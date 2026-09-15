#include "bsp.h"

#define KEY_TICKS_SHORT    4    // 40ms 消抖
#define KEY_TICKS_LONG_P   150//250  // 2.5s 电源键长按
#define KEY_TICKS_LONG_M   100//200  // 2s 模式/下键长按



uint8_t key_worked_f;
uint8_t key_long_f;
uint16_t key_data;
uint16_t key_time;



void Process_Short_Key(uint16_t key) ;
void Process_Short_Key(uint16_t key);
void Process_Long_Key(uint16_t key);


void Handle_Value_Adjustment(uint8_t is_up);

#if 0

void Key_Scan(void)
{
    uint16_t key_i = 0;
    
    // 物理层扫描
    if      (KEY10_PIN) key_i = _POWER_KEY_DOWN;
    else if (KEY9_PIN)  key_i = _MODE_KEY_DOWN;
    else if (KEY8_PIN)  key_i = _UP_KEY_DOWN;
    else if (KEY7_PIN)  key_i = _DOWN_KEY_DOWN;

    // 状态机处理
    if (key_i == 0) { // 松手或无按键
        if (!key_long_f && key_time >= KEY_TICKS_SHORT) {
            // --- 执行短按逻辑 ---
            Process_Short_Key(key_data);
        }
        key_time = 0;
        key_data = 0;
        key_long_f = 0;
    } 
    else if (key_i != key_data) { // 切换按键
        key_data = key_i;
        key_time = 0;
        key_long_f = 0;
    } 
    else { // 持续按下
        if (key_time < 0xFFF) key_time++;
        
        // --- 执行长按逻辑 ---
        Process_Long_Key(key_data);
    }
}


// 长按处理子函数
void Process_Long_Key(uint16_t key) {
   // if (key_long_f) return; // 已处理过长按则退出

    switch (key) {
        case _POWER_KEY_DOWN:
            if (key_time >= KEY_TICKS_LONG_P) {
                //key_long_f = 1;
                if (gpro_t.g_power_flag && !key_net_config_f) {
                    key_net_config_f = 1;
					link_net_step=0;
				    wifi_connected_success_f =0;
					wifi_first_connectoed_cloud_f =0;
                    key_net_config_time = 0;
					BEEP_ON() ;//Beep(BEEP_ONCE);
                }
            }
            break;

        case _MODE_KEY_DOWN://LONG KEY MODE ID 
            if (key_time >= KEY_TICKS_LONG_M) {
                //key_long_f = 1;
                if (gpro_t.g_power_flag && !fan_warning_f) {
                    Is_time_setting_f = 1;
                   
                    time_set_hours_counter =0;
                    BEEP_ON() ; //Beep(BEEP_ONCE);
                }
            }
            break;

        case _DOWN_KEY_DOWN:
            if (key_time >= KEY_TICKS_LONG_M) {
                //key_long_f = 1;
                if (gpro_t.g_power_flag) {
					if(led_strip_open_f==1){
						led_strip_open_f=0;
						LED_TAPE_OFF();
					}
                    else{
						led_strip_open_f = 1;// 翻转灯带状态
                         LED_TAPE_ON();
                    }
                    
                  BEEP_ON() ;  //Beep(BEEP_ONCE);
                }
            }
            break;
    }
}

// 短按处理子函数
void Process_Short_Key(uint16_t key) 
{
    if (key == _POWER_KEY_DOWN  && !KEY10_PIN) {
        if (gpro_t.g_power_flag) System_Status_PowerOff();
        else System_Status_PowerOn();
        return;
    }

    // 仅在开机且无负载故障时允许操作
    if (!gpro_t.g_power_flag || fan_warning_f) return;

    switch (key) {
        case _MODE_KEY_DOWN:
			if(Is_time_setting_f == 1){

		    }
			else{
		      
	            Is_time_setting_f = 0;
	            disp_set_hours_time_f = 1;
	            LED_AI_OFF();
				
				time_set_hours_counter =0;
			}
             BEEP_ON() ;//Beep(BEEP_ONCE);
            break;

        case _UP_KEY_DOWN:
		
            Handle_Value_Adjustment(1);
            BEEP_ON(); //Beep(BEEP_ONCE);
            break;

        case _DOWN_KEY_DOWN:
            Handle_Value_Adjustment(0);
            BEEP_ON();//Beep(BEEP_ONCE);
            break;
    }
}

#endif 
/**
  * @brief  数值调节处理函数
  * @param  is_up: 1 为增加(UP), 0 为减少(DOWN)
  */
void Handle_Value_Adjustment(uint8_t is_up) 
{


    // 情况 A: 正在设置时间 (定时小时)
    if (Is_time_setting_f)  //设置 :定时时间值
    {
        if (is_up) {
            if (setting_timing_hour < 24) setting_timing_hour++;
        } else {
            setting_timing_hour--;
			if(setting_timing_hour < 0 )  setting_timing_hour=0;
        }
        
        // 逻辑关联：如果定时不为0，开启定时标志
        // AI_led_open_f = (setting_timing_hour > 0) ? 1 : 0;
        
        // 只要动了时间，秒和分计数值都要清零重新开始
        timing_min_cnt = 0;
      
        Cacl_time_sec = 0;
		key_be_pressed_f =1;
		
		time_set_hours_counter =0;
    } 
    else{  // 情况 B: 正在设置温度
		
        if (is_up) {
           if (setting_temperature < 40) setting_temperature++;
        } else {
            if (setting_temperature > 20) setting_temperature--;
        }
		disp_set_hours_time_f = 0;
		set_temperature_value_f = 1;
		first_temp_compare_f = 0; 
		time_1s_counter =0;
	    time_set_hours_counter =0;
		key_be_pressed_f =0;
		key_input_temp_f= 1;
		heat_open_close_f= 1;//WT.EDIT 2026.05-15
		key_pressed_set_temp_f =1;
		if(AI_led_open_f == 0){//if(g_pro.set_timing_or_timer_time_flag ==TIMER_TIME){
			         
		     //LED_AI_OFF(); 
		 }
		  else{
		     //LED_AI_ON(); 

		}
       TM1639_Display_Temperature(setting_temperature);
	   direct_compare_set_temp_value();
    }
}




/**
* @brief  : 
* @note    
* @param   None
* @retval  None
*/
void key_power_short_handler(void)
{

	if (gpro_t.g_power_flag) System_Status_PowerOff();
    else System_Status_PowerOn();

}
/**
* @brief  : 
* @note    
* @param   None
* @retval  None
*/
void key_power_long_handler(void)
{
	//key_long_f = 1;
    if (!key_net_config_f) {
        key_net_config_f = 1;
		link_net_step=0;
	    wifi_connected_success_f =0;
		wifi_first_connectoed_cloud_f =0;
        key_net_config_time = 0;
       
		BEEP_ON() ;//Beep(BEEP_ONCE);
    }
}
/**
* @brief  : 
* @note    
* @param   None
* @retval  None
*/
void key_mode_short_handler(void)
{
	if(Is_time_setting_f == 1){

	}
	else{
		      
	    Is_time_setting_f = 0;
	    disp_set_hours_time_f = 1;
	    //LED_AI_OFF();
		
		time_set_hours_counter =0;
	}
    BEEP_ON() ;//Beep(BEEP_ONCE);

}

/**
* @brief  : 
* @note    
* @param   None
* @retval  None
*/
void key_mode_long_handler(void)
{
	//key_long_f = 1;
    if (gpro_t.g_power_flag && !fan_warning_f) {
        Is_time_setting_f = 1;
       
        time_set_hours_counter =0;
        BEEP_ON() ; //Beep(BEEP_ONCE);
    }

}

/**
* @brief  : 
* @note    
* @param   None
* @retval  None
*/
void key_up_short_handler(void)
{
     BEEP_ON(); 
	 Handle_Value_Adjustment(1);
    //Beep(BEEP_ONCE);  

}

/**
* @brief  : 
* @note    
* @param   None
* @retval  None
*/
void key_down_short_handler(void)
{
  BEEP_ON(); //Beep(BEEP_ONCE);
  Handle_Value_Adjustment(0);
  

}

/**
* @brief  : 
* @note    
* @param   None
* @retval  None
*/



