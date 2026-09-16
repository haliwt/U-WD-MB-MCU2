/*
  ******************************************************************************
  * Copyright (c) 2024 Yspring.
  * All rights reserved..
  * @file    user.C
  * @author  Yspring Firmware Team  
  * @brief   user Source Code.
  ******************************************************************************      
*/

#include "bsp.h"

power_state gon_t;



volatile uint8_t Times5msCnt;
uint8_t Times10msCnt;
//uint8_t Times100msCnt;
uint8_t Times1minute;
uint16_t Times1minCnt;
uint8_t Cacl_time_sec;

volatile uint8_t time_5ms_f;

uint8_t time_wifi_10ms_f;

uint16_t fan_adc_value[1];
uint16_t ad_ptc_value[1];
uint16_t fan_current;
uint16_t ptc_current;



uint16_t current_temperature;
uint16_t setting_temperature;
uint16_t disp_temperature;
uint16_t disp_timing_time;
uint16_t disp_humidity;

uint8_t AI_led_open_f;
bool ptc_heat_open_f;
uint8_t first_temp_compare_f;

bool ptc_prohibit_off_f;

bool    ultra_sound_open_f;
bool    plasma_open_f;

uint16_t timing_is_reach_disptime;

uint8_t read_ntc_temperature_value;




uint8_t Is_time_setting_f;

uint8_t Is_countdown_timer_f;
uint8_t set_temperature_value_f;
uint8_t time_1s_counter;

//display second board
uint8_t disp_second_f;
uint8_t heat_open_close_f;
uint8_t  key_pressed_set_temp_f;





uint8_t key_net_config_f;
uint16_t key_net_config_time;


uint8_t flash_f;


uint16_t device_rest_time;

//countdown timer 
int8_t timing_min_cnt;
int8_t setting_timing_second;
uint8_t real_hours_counter;
int8_t temporary_timer_hours;
int8_t setting_timing_hour;

//end
//timer 
uint8_t  time_set_hours_counter;

//wroks time two hours

bool  works_interval_f;



bool fan_open_f;
uint8_t fan_speed_level;


volatile uint8_t beep_times;				//����
volatile uint8_t beep_lenght;			  //��ĳ��� *100ms
volatile uint8_t non_beep_length;		//���ʱ��
uint16_t beep_interval_time;

//temp ref
uint8_t temperature;
uint8_t humidity;

uint8_t  soft_version ;



//peripheral ref


uint16_t fan_current_det_time;
bool fan_warning_f;

uint8_t disp_switch_temp_humi;
//
uint8_t soft_version;

//wifi 

uint8_t  link_net_step;
uint8_t  time_link_net_counter;
//wifi references
uint8_t  wifi_linking_tencent_f;
bool     wifi_connected_success_f;
volatile uint8_t  wifi_rx_numbers;
uint8_t  wifi_cofig_success_f;
uint8_t  wifi_app_timer_power_on_f;
uint8_t  wifi_run_step ;
uint8_t  wifi_off_step;

uint8_t  wifi_first_connectoed_cloud_f;
uint8_t  wifi_read_net_data_f;
uint8_t  wifi_check_net_f;
volatile uint8_t  rx_wifi_data_success;
volatile uint8_t   rx_wifi_data_counter;



//wifi ref end 

uint8_t  time_autolink_counter;

uint8_t dc_connect_net_step	;


uint8_t  mqtt_status;


//fan
uint8_t  fan_one_minute_cuonter;
uint8_t  time_10ms_f;
uint16_t ptc_adc_numbers;





uint8_t key_be_pressed_inc_or_dec_f;
uint8_t disp_set_hours_time_f;
uint8_t key_input_temp_f;

bool ptc_high_temperature_f ;




//uint8_t com_data_temp[8];
//uint8_t com_data_buf[16];





uint8_t counter;
uint8_t power_Led_switch;	

volatile uint16_t i;
volatile uint16_t bw_i=0;
volatile uint16_t sw_i=0;
volatile uint16_t gw_i=0;
volatile uint16_t disp_timing_time_temp;
volatile uint16_t timing_diff_value_hour;
volatile uint16_t timing_diff_value_min;


volatile uint8_t static beep_sound_f =0;



/**
  * @brief  fan run is error
  * @note  
  * @param: 
  *
**/
void Clear_Ram(void)
{
    time_5ms_f = 0;
	

	  gpro_t.time_400ms_f =0;
	  gpro_t.time_500ms_f =0;
	  gpro_t.time_1s_f = 0;
	  gpro_t.time_1m_f=0;
	

	  Times10msCnt = 0;

	  Times1minute = 0;
	  Times1minCnt = 0;
	  Cacl_time_sec = 0;
	
	
	
	  key_worked_f = 0;
	 
	  key_data = 0;
	  key_time = 0;
	
	  gpro_t.g_power_flag = 0;
		
		
		device_rest_time = 0;
		
		fan_speed_level = 100;
		fan_open_f = 0;
	
		
		AI_led_open_f = 0;
		ptc_heat_open_f= 0;
		first_temp_compare_f=0;
		ultra_sound_open_f = 0;
		plasma_open_f = 0;
	
		
		timing_is_reach_disptime = 0;
		
		Is_time_setting_f = 0;
	
		Is_countdown_timer_f = 0;
		
	
		flash_f = 0;
	
		
		timing_min_cnt = 0;
		
		fan_warning_f = 0;
		fan_current_det_time = 0;
		
		disp_switch_temp_humi = 0;
		beep_interval_time = 0;
		//wifi 
		wifi_linking_tencent_f=0;
		
}


// 根据 ThreadX 配置定义：1秒 = 100个tick，即 1 tick = 10ms
#define TICKS_PER_SEC       100
#define MS_TO_TICKS(ms)     ((ms) / (1000 / TICKS_PER_SEC))

#define TASK_NUM (sizeof(g_tasks) / sizeof(TimeSharingTask_t))


typedef struct{

	uint32_t last_tick;
	uint32_t  period;
	void (*task_handler)(void);

}TimeSharingTask_t;


static void handler_wifi_state(void);
static void handler_wifi_update_data(void);
static void handler_works_hours(void);
static void handler_fan_adc(void);
static void handler_wifi_update_temp_humidity(void);
static void handler_read_dht11(void);
static void handler_fan_speed_state(void);
static void handler_hardware_update(void);
static void handler_read_dht11_to_outside_diplay(void);

static void handler_link_wifi(void);
static void handler_repeat_link_net(void);

static void handler_wifi_report(void);

volatile uint8_t time_slot ;


// --- 4. 初始化分时任务表 ---
TimeSharingTask_t g_tasks[] = {
    {0, 370,       handler_wifi_state},                 //370* 10ms = 3,7s
    {0, 140,       handler_wifi_update_data},         //140*10ms = 1.4s
    {0, 430,       handler_works_hours},            //
    {0, 570,       handler_fan_adc},
    {0, 710,       handler_wifi_update_temp_humidity},
    {0, 280,       handler_read_dht11},
    {0, 220,       handler_fan_speed_state},
    {0, 200,        handler_hardware_update},          //200*10ms = 2000ms =2s   
    {0, 3,         handler_link_wifi},                  //3*10ms =30ms
    {0, 230,       handler_repeat_link_net},
    {0, 270,       handler_wifi_report},
    {0, 300,       handler_read_dht11_to_outside_diplay}
   
    
	
};

static void power_on_cycle_handler(void);
static void module_wifi_report_handler(void);
static void power_on_handler(void);
static void power_off_handler(void);
static void power_on_initial(void);





/************************************************************************
 * Function Name: LED_Power_Breathing(void)
 * 功能:
 * 参数:无
 * 返回值:无
 ************************************************************************/
static void power_on_initial(void)
{

   
   switch(gon_t.on_step){

   case 0:
   	  gon_t.off_step = 0;
      wifi_off_step =0; //WT.EDT 2026.05.15
      
      System_Status_PowerOn() ;
	  dht11_read_temp_humidity_value();
	  //display_digital_3_numbers();
	  sendData_Real_TimeHum(humidity,temperature);
	  tx_thread_sleep(2);
      gon_t.on_step =1;
	

   break;

   case 1:
   // dht11_read_temp_humidity_value();
	sendData_Real_TimeHum(humidity,temperature);
   // display_digital_3_numbers();
    tx_thread_sleep(2);
    gon_t.on_step =2;


   break;

   case 2:
   	 
       //dht11_read_temp_humidity_value();
	   //display_digital_3_numbers();
	   gon_t.on_step =0xfe;

   break;

   	}
}
/************************************************************************
*
* Function Name: LED_Power_Breathing(void)
* 功能:
* 参数:无
* 返回值:无
*
************************************************************************/
uint16_t disp_counter;

void power_on_handler(void)
{

  volatile  static uint8_t time_slot = 0,ptc_counter=0,fan_counter=0,fan_error=0;
  volatile static uint8_t per_counter=0,switch_done =0,disp_counter=0;
  volatile static uint8_t high_tmep_counter = 0,warning_counter=0,has_warning_counter=0;

  volatile static uint16_t wifi_check_counter=0;

	
        if(gon_t.on_step  < 8){
		  power_on_initial();
        }
	 // ✨【新增：紧急事件拦截响应】✨
        // 如果按键任务设置完温度，将 g_pro.g_immediate_heat_f 置为 1
       
         if(time_10ms_f ==1 &&  ptc_high_temperature_f == 0 && fan_warning_f ==0 && (gpro_t.external_display_flag == false || gpro_t.key_inc_or_dec_f == true)){
		    time_10ms_f=0;
            gpro_t.key_inc_or_dec_f = false;
		    disp_key_input_handler();

			if(heat_open_close_f == 1 && ptc_high_temperature_f == 0 && fan_warning_f ==0)
	        {
	           heat_open_close_f = 0; // 立即清除触发标志，防止重复执行
	            
	            // 强制、立刻执行一次加热控制函数
	            // 确保底层硬件（如继电器、PWM、PTC）在 20ms 内得到响应
	           compare_set_temp_value(); //set_temperature_value_handler(); 
	        }
			    

         }
		 else{
			power_on_cycle_handler();


		 }

}
/************************************************************************************
*
*Function Name: static void power_on_cycle_handler(void)
*Fucntion :
*Input Ref:NO
*Return Ref:NO
*
************************************************************************************/
static void power_on_cycle_handler(void)
{

      // 获取当前系统的绝对时间戳
      uint32_t current_tick = tx_time_get();
	
        // 通过时间片轮询核心算法，分时调用各个功能模块
    for (uint8_t i = 0; i < TASK_NUM; i++) 
    {
        if ((current_tick - g_tasks[i].last_tick) >= g_tasks[i].period) 
        {
            // 【工业级进化：防轰炸饱和截断】
            // 如果卡顿/被高优先级抢占的时间超过了 2 个周期，直接对齐当前时间，放弃追赶
            if ((current_tick - g_tasks[i].last_tick) > (g_tasks[i].period * 2)) 
            {
                g_tasks[i].last_tick = current_tick;
            }
            else 
            {
                // 如果只是正常范围内的轻微抖动，滚动累加周期，死锁锁相，消除长期长跑漂移
                g_tasks[i].last_tick += g_tasks[i].period;
            }
            
            // 触发对应周期的执行函数（确保不为 NULL，防止空指针崩溃）
            if (g_tasks[i].task_handler != NULL)
            {
                g_tasks[i].task_handler(); 
            }
        }
    }
	  

}
/************************************************************************************
*
*Function Name: static void power_on_cycle_handler(void)
*Fucntion :
*Input Ref:NO
*Return Ref:NO
*
************************************************************************************/
static void handler_wifi_state(void)
{
    // 如果这些变量之前是全局的，保持原样；如果是局部的，必须加 static 保持状态
   
    static uint8_t sw_flag = 0;
	
   if( soft_version  == 0){ //WT.EDIT 2026.02.27
		
		sw_flag = sw_flag ^ 0x01;
	    // 关键优化：用三元运算符直接提取状态值，消灭大面积重复的 if-else 块
        uint8_t wifi_status = (wifi_connected_success_f == true) ? true : false;
		if(sw_flag == 1){
			SendWifiData_olderCmd(0x1F,wifi_status);//SendWifiData_To_Cmd(0x1F,0x01); //link wifi order 1 --link wifi net is success.
			tx_thread_sleep(2);
		}
		else{
			SendWifiData_To_Data(0x1F,wifi_status);
			tx_thread_sleep(2);
		}

	}
}
/**
*
*@brief 
*@notice
*@param
*@retval
*
**/
static void handler_wifi_update_data(void)
{
   if(wifi_connected_success_f==1 && ptc_high_temperature_f == false && fan_warning_f ==false){
   	
		   wifi_power_on_handler();
      }
    
}
 /**
 *
 *@brief 
 *@notice
 *@param
 *@retval
 *
 **/
static void handler_works_hours(void)
{

	if( ptc_high_temperature_f == 0 && fan_warning_f ==0){
	  works_run_two_hours_state();
	}

	
}
/**
*
*@brief 
*@notice
*@param
*@retval
*
**/

static void handler_hardware_update(void)
{

	if(ptc_high_temperature_f == 0 && fan_warning_f ==0){ //10ms * 100
	
	     peripheral_hardware_handler();
	}
}

/**
*
*@brief dispatch module_hardware_control task 
*@notice
*@param
*@retval
*
**/
uint8_t flag_id;

static void handler_read_dht11_to_outside_diplay(void)
{

	if(gpro_t.external_display_flag ==1){
     flag_id = DHT11_ReadData(&humidity,&temperature);
     sendData_Real_TimeHum(humidity,temperature);
     tx_thread_sleep(2);
	}
  

}
/**
*
*@brief dispatch module_hardware_control task 
*@notice
*@param
*@retval
*
**/
static void handler_wifi_report(void)
{

  	module_wifi_report_handler();

}
/**
*
*@brief 
*@notice
*@param
*@retval
*
**/
static void handler_fan_adc(void)
{

   static uint8_t fan_counter = 0,fan_error;
   
	  if( ptc_high_temperature_f == 0 && fan_warning_f ==0 && works_interval_f==0){
            fan_counter =1;
		    adc_fan_channel_get_value();
		    AD_Filter();
	  }

	   if(fan_counter ==1){
		   	  fan_counter ++; 
			  #if 0
				  printf("fan_current  = %d \n\r",fan_current );
				  printf("temperature = %d \n\r",read_ntc_temperature_value);
			  #endif 
           if(fan_current < 20  &&  fan_warning_f == 0 && works_interval_f==0){
		  	    
                 fan_error ++ ;
				 #if 0
				 
				  printf("fan_error= %d \n\r",fan_error);
			    #endif 
			     if(fan_error > 6){
				  fan_warning_f = 1;
				    //   LED_PTC_OFF();
					    RELAY_OFF(); 
						SMG_Display_Err(02);
						if(wifi_connected_success_f ==1){
                            Publish_Data_fan_Warning(0x01);//fan warning
						}
						beep_high_temperature_sound();
						
	            }
				 
			}
		    else if(fan_current  >19   &&  fan_warning_f == 0 && works_interval_f==0){

			   fan_error  =0;


			}

		 	}
    
	   
}


  /**
*
*@brief 
*@notice
*@param
*@retval
*
**/
static void handler_wifi_update_temp_humidity(void)
{
    
    if(wifi_connected_success_f ==true){
			
		Update_Dht11_Totencent_Value();
     }
	 
 }
 /**
*
*@brief 
*@notice
*@param
*@retval
*
**/
static void handler_read_dht11(void)
{

     if( ptc_high_temperature_f == 0 && fan_warning_f ==0 ){
			disp_counter=0;	
		display_temperature_humidigy_handler();

	 }

}

/**
	*
	*@brief 
	*@notice
	*@param
	*@retval
	*
**/
static void handler_fan_speed_state(void)
{
     if(ptc_high_temperature_f == false && fan_warning_f ==false){
		 	
		    Fan_Ctrl_Process();	  // 风扇控制

     }
   	   
}
/**
	*
	*@brief 
	*@notice
	*@param
	*@retval
	*
**/
static void handler_repeat_link_net(void)
{

	if(ptc_high_temperature_f == 0 && fan_warning_f ==0){
		if(key_net_config_f==0 &&	wifi_linking_tencent_f ==0){
		
#if DEBUG_ENABLE
		printf("reconnection wifi ! \n\r");
#endif 
		automatic_network_reconnection();

	}
	}



}
/**
	*
	*@brief 
	*@notice
	*@param
	*@retval
	*
**/
static void handler_link_wifi(void)
{
	
 if(ptc_high_temperature_f == 0 && fan_warning_f ==0){
				if(key_net_config_f)
				 {
					
					if(key_net_config_time>=130)
					{
						key_net_config_time = 0;

						key_net_config_f = 0;
						
					}
					else{ //conneting to wifi net 
				        
						link_wifi_net_handler();
					}
				 } 
		  }

}


/************************************************************************
 *
 * Function Name: LED_Power_Breathing(void)
 * 功能:
 * 参数:无
 * 返回值:无
 *
 ************************************************************************/
static void power_off_handler(void)
{
   static uint8_t dc_on=0,fan_one_f=0;

   static uint32_t wait_timeout = 0;
  

	switch(gon_t.off_step){
	
		 case 0:
			gon_t.on_step =0;
	       
		    fan_one_f =1;
			time_1s_counter=0;
			fan_one_minute_cuonter =0;
			wifi_run_step = 0;
			wifi_off_step =0;
			power_off_peripheral_handler();
			all_led_off();
	        TM1639_Display_ON_OFF(0);
			
			
			gon_t.off_step = 1;
	
		 break;
	
		 case 1:
             power_off_peripheral_handler();
		  
             if(dc_on ==0){
			    BEEP_ON();
			 	dc_on++;
				fan_one_f =0;
			
				fan_stop();
				
			  }

			if(wifi_connected_success_f ==1 ){
	
               MqttData_Publish_PowerOff_Ref(); 
			}

			gon_t.off_step = 2;
			 
        break;


		case 2:
        if(wifi_connected_success_f ==1){
			     gon_t.off_step = 3;
			
				fan_warning_f = 0;
			    ptc_high_temperature_f =0;
			    Publish_Data_fan_Warning(0); //fan warning .

				Publish_Data_Ptc_Temp_Warning(0);
				//wait_timeout=tx_time_get()+20;//tx_thread_sleep(20);///delay_ms(200);
		    }
            else{

                gon_t.off_step = 3;
			}

		break;

		case 3:

		  
			
			   if(fan_one_f == 1  && fan_one_minute_cuonter>59){
				     fan_one_f ++;
	                 fan_stop();
				 }

				 if(wifi_connected_success_f ==1 && gpro_t.time_2s_f > 5){
                     gpro_t.time_2s_f=0;
				     MqttData_Publish_SetOpen(0);  
				   	
					
		
		    	   wait_timeout = tx_time_get()+20;//tx_thread_sleep(20);//delay_ms(100);
	    
			      }
			
		
	       gon_t.off_step = 4;
            	
		break;

		 case 4 :

		    
		   if(time_1s_counter > 1){
				 	time_1s_counter =0;
				    dht11_read_temp_humidity_value();
				    //#if DEBUG_ENABLE
                     /// printf(" gon_t.off_step = %d \n\r", gon_t.off_step );
				    ///#endif 
			}

        
		    gon_t.off_step = 5;

		  break;

		  case 5:

		     if(time_1s_counter > 2){
				 	time_1s_counter =0;
				    dht11_read_temp_humidity_value();
				   // #if DEBUG_ENABLE
                     /// printf(" gon_t.off_step = %d \n\r", gon_t.off_step );
				    //#endif 
			}
		
		    gon_t.off_step =6;

		  break;

		  case 6:

		 

			 if(wifi_connected_success_f ==1 &&  gpro_t.time_3s_f> 5 ){//10ms*800 =8000ms =8s
      
			       gpro_t.time_3s_f =0;
				   Subscriber_Data_FromCloud_Handler();
		    	   wait_timeout = tx_time_get() + 20 ;//tx_thread_sleep(20);//delay_ms(100);
	    
			     }
		
		  gon_t.off_step = 7;
		break;

		case 7:
			

		    if(wifi_connected_success_f ==1 &&   gpro_t.time_4s_f> 8){
				gpro_t.time_4s_f=0;
				fan_warning_f = 0;
			    ptc_high_temperature_f =0;
			    Publish_Data_fan_Warning(0); //fan warning .

				Publish_Data_Ptc_Temp_Warning(0);
				//wait_timeout=tx_time_get()+20;//tx_thread_sleep(20);///delay_ms(200);
		    }
		    gon_t.off_step = 8;

		break;

		case 8:
			if(setting_timing_second > 6 && wifi_connected_success_f ==1 ){
				setting_timing_second =0;
               MqttData_Publish_PowerOff_Ref(); 
			   wait_timeout = tx_time_get()+ 20;   
			}
		
          gon_t.off_step = 3;
		break;

   }
}

/**
  * @brief  
  * @note  
  * @param: 
  *
**/
void Countdown_timer_Handler(void)
{
   static int8_t dsip_timer_value ;
 
   if(setting_timing_second >=60) //60s
    {
	   setting_timing_second=0;

	   #if DEBUG_ENABLE

		timing_min_cnt = timing_min_cnt - 40;
	   #else 
		 timing_min_cnt --;

	   #endif 

        if(timing_min_cnt <  0)
        {
           timing_min_cnt =59;
		   real_hours_counter++;
		   if((setting_timing_hour > 1) && setting_timing_hour !=1){
		   	
		          dsip_timer_value = temporary_timer_hours - real_hours_counter +1;
				  setting_timing_hour = dsip_timer_value;


		   }

		   if(setting_timing_hour ==1 || setting_timing_hour==0){
               
				   setting_timing_hour--;
				   
            }

        }

        if (setting_timing_hour < 0)
        {
             gpro_t.g_power_flag = 0;
			 System_Status_PowerOff() ;

        }
    }
}
/**
  * @brief  outside connect display board control two hours times
  * @note  
  * @param: 
  *
**/
void works_run_two_hours_state(void)
{
     static uint8_t interval_10m_f = 0 ,interval_state=0;

	 if(gpro_t.external_display_flag == false){
	 
		#if  0 //DEBUG_ENABLE 
			if(gpro_t.time_1m_f >11 && works_interval_f==0){
		#else 
			if(gpro_t.time_1m_f > 119 && works_interval_f==0){

		#endif 

			gpro_t.time_1m_f = 0;
		    gpro_t.time_base_1s_counter=0;
			works_interval_f=1;
			fan_one_minute_cuonter =0;
			
		#if DEBUG_ENABLE 
			printf("works_interval_f = %d \n\r",works_interval_f);
		#endif 
		}

		#if 0
		  else if(works_interval_f==1 && gpro_t.time_1m_f >9){
		#else 
		  else if(works_interval_f==1 && gpro_t.time_1m_f >10){

		#endif 
				gpro_t.time_1m_f = 0;  
				works_interval_f =0;
		        gpro_t.time_base_1s_counter=0;
				interval_10m_f = 1;
				
		#if DEBUG_ENABLE 
			printf("works_interval_f = %d \n\r",works_interval_f);
		#endif 
		}


		if(interval_10m_f == 1 && works_interval_f==0){
             interval_10m_f ++;
		     fan_wind_speed_full();
		  if(ptc_prohibit_off_f == 0 &&  ptc_heat_open_f== 1){
		
		      RELAY_ON();
		  
		  	}
		 
		}
		if(Is_countdown_timer_f ==1 && ptc_high_temperature_f == 0 && fan_warning_f ==0){
            Countdown_timer_Handler();
	   	 }

	}
	else{

         if(works_interval_f== true && interval_state==0){
              
			gpro_t.time_1m_f = 0;
		    gpro_t.time_base_1s_counter=0;
			fan_one_minute_cuonter =0;
			interval_state++;
		
         }
		 else if(works_interval_f == false){
		   interval_state=0;

          }


	}
		
 }
  
/**
	*
	*@brief environment temperature value compare set temperater value
	*@notice
	*@param
	*
**/
void Heat_Process(void)
{
     static uint8_t default_init = 0xff;   // 第一次比较标志
     
     if(gpro_t.g_power_flag == 1 && gpro_t.external_display_flag == false){
	   if(ptc_prohibit_off_f == 1 || set_temperature_value_f ==1 ) return ;

	  uint8_t target_temp;

	  target_temp = setting_temperature;

	  if(temperature > 39){

        ptc_heat_open_f= 0;   // 立即关闭
	    first_temp_compare_f = 1; 
	    if(default_init != ptc_heat_open_f|| key_input_temp_f ==1 || key_input_temp_f==2 ){
					default_init= ptc_heat_open_f;
					key_input_temp_f++;
				if(disp_second_f == 1){
					SendWifiData_To_Cmd(0x02,0);
		        //delay_ms(100);//HAL_Delay(5);
					}
		        if(wifi_connected_success_f == 1){
					MqttData_Publish_SetPtc(0);
		        }

				}
	  
	     return ;

	  }

      // -----------------------------
    // 2. 第一次比较：必须立即决定 PTC 开关
    // -----------------------------
	  if(first_temp_compare_f == 0){

		if(temperature >= target_temp){
            ptc_heat_open_f= 0;   // 立即关闭

		       if(default_init != ptc_heat_open_f || key_input_temp_f ==1 || key_input_temp_f==2 ){
					default_init = ptc_heat_open_f;
					key_input_temp_f ++;
				if(disp_second_f == 1)SendWifiData_To_Cmd(0x02,0);
		        //delay_ms(100);//HAL_Delay(5);
		        if(wifi_connected_success_f == 1)MqttData_Publish_SetPtc(0);

				}
		}
        else{
            ptc_heat_open_f= 1;   // 立即打开
            first_temp_compare_f = 1;         // 以后进入滞后控制
            if(default_init!= ptc_heat_open_f|| key_input_temp_f ==1 || key_input_temp_f==2 ){
					default_init = ptc_heat_open_f;
					key_input_temp_f++;
				if(disp_second_f == 1)SendWifiData_To_Cmd(0x02,0x01);
		        //delay_ms(100);//HAL_Delay(5);
		        if(wifi_connected_success_f == 1)MqttData_Publish_SetPtc(0x01);

			}
        }
        return;


	  }

		// -----------------------------
		// 3. 第二次及以后：使用 -2°C 滞后控制
		// -----------------------------
		if(first_temp_compare_f == 1)
		{
			// 当前是开启状态 → 高于设定温度则关闭
			if(temperature >= target_temp){
					ptc_heat_open_f= 0;
				if(default_init != ptc_heat_open_f || key_input_temp_f ==1 || key_input_temp_f==2 ){
					default_init = ptc_heat_open_f;
					key_input_temp_f++;
				if(disp_second_f == 1)SendWifiData_To_Cmd(0x02,0);
		       // delay_ms(100);//HAL_Delay(5);
		        if(wifi_connected_success_f == 1)MqttData_Publish_SetPtc(0);

				}
			}
			else
			{
				// 当前是关闭状态 → 低于设定温度 - 2 才重新打开
				if(temperature <  (target_temp - 2))
				ptc_heat_open_f= 1;
				
				if(default_init!= ptc_heat_open_f|| key_input_temp_f ==1 || key_input_temp_f==2 ){
					default_init = ptc_heat_open_f;
					key_input_temp_f++;
				if(disp_second_f == 1)SendWifiData_To_Cmd(0x02,0x01);
		       // delay_ms(100);//HAL_Delay(5);
		        if(wifi_connected_success_f == 1)MqttData_Publish_SetPtc(0x01);

				}
			}
		}

       }

}
/**
  * @brief  
  * @note  
  * @param: 
  *
**/
void power_on_off_handler(void)
{

 
	 switch(gpro_t.g_power_flag){

      case 1:
           power_on_handler();
	 
	  break;

	  case 0:
	  	   power_off_handler();
		 

	  break;
      }

   if(wifi_linking_tencent_f==1 &&  wifi_read_net_data_f==1){
	   wifi_read_net_data_f++;

	   Wifi_Rx_InputInfo_Handler();
	}

	wifi_parse_tencennt_hadler();//
    
	if(key_net_config_f==0 ){
      wifi_auto_detected_link_state();

   	}

	
}



/**
 * @brief 2. WiFi 本地串口与 MQTT 云端数据上报函数
 * @note  挂在 3s 一次的时间戳慢周期中执行
 */
static void module_wifi_report_handler(void)
{
    // 如果系统已经报警，清空业务标志，不进行正常上报（或者在此处增加上报报警错误码的逻辑）
    if (ptc_high_temperature_f == true || fan_warning_f == true) {
       
        return;
    }

    // 状态保持变量移到这里，它们只为“数据上报”服务
    static uint8_t ptc_default = 0xff;
    static uint8_t plasma_default = 0xff;
    static uint8_t ultrasonic_default = 0xff;

    // ==========================================
    // 业务 2：云端状态同步——MQTT 属性上报
    // ==========================================
    if ( wifi_connected_success_f == true) {
        
        // PTC 状态有变动则上报
        if (ptc_default != ptc_heat_open_f) {
            ptc_default = ptc_heat_open_f;
            MqttData_Publish_SetPtc(ptc_heat_open_f ?  true : false);
            //tx_thread_sleep(20); 
        }

        // 等离子状态有变动则上报
        if (plasma_default != plasma_open_f) {
            plasma_default = plasma_open_f;
            MqttData_Publish_SetPlasma(plasma_open_f ?  true : false);
            //tx_thread_sleep(20);
        }

        // 超声波状态有变动则上报
        if (ultrasonic_default != ultra_sound_open_f) {
            ultrasonic_default = ultra_sound_open_f;
            MqttData_Publish_SetUltrasonic(ultra_sound_open_f ?  true : false);
           // tx_thread_sleep(20);
        }

//        // 温度定时上报
//        if (gpro_t.tx_wifi_temperature_f == 1) {
//            gpro_t.tx_wifi_temperature_f++;
//            MqttData_Publis_SetTemp(gctl_t.set_temperature_value);
//           // tx_thread_sleep(20);
//        }
    }
}


/**
* @brief	系统状态初始化（开机）
* @note	设定系统启动时的默认工作参数
*/
void System_Status_PowerOn(void) 
{
	// 1. 开启核心工作标志位
	gpro_t.g_power_flag = 1; 
	fan_wind_speed_full();


	if(wifi_app_timer_power_on_f==0){ //手机定时开机
		gpro_t.g_power_flag = 1;			// 总输出使能
		ptc_heat_open_f= true;		  // 默认开启加热
		ultra_sound_open_f = 1; 	// 默认开启超声波
		plasma_open_f = 1;			// 默认开启等离子
		power_on_peripheral_handler();
    }

	fan_open_f = 1; 			// 默认开启风扇

	AI_led_open_f = 1;		 // 默认AI 开启
	fan_speed_level =100;		// 默认风扇最大风速 
	set_temperature_value_f =0; 
	ptc_high_temperature_f =0;	//高温报警标志位,清零
	read_ntc_temperature_value =0;
	heat_open_close_f=0; //WT.EIDT 2026-07-13
	//wifi
	wifi_run_step=0;
	wifi_off_step=0;

	// 2. 设定启动默认参数
	setting_temperature = 40;	// 默认设定温度 40°C
	setting_timing_hour = 0;	// 默认不设置定时（常开模式）
	gpro_t.time_base_1s_counter=0;	// 重置工作时间累计
	gpro_t.time_1m_f = 0;			// 重置工作时间累计
	// 3. 状态显示切换
	Is_time_setting_f = 0;
	Is_countdown_timer_f = 0;
	disp_set_hours_time_f = 0;

	// 4. 重置计数器（确保从 0 开始计时）
	timing_min_cnt = 0;

	Cacl_time_sec = 0;

	works_interval_f = 0 ; // device_rest_f = 0;		  // 退出休息模式
	device_rest_time = 0;
	key_net_config_f =0;

	// 5. 清除异常标志
	fan_warning_f = 0;			// 清除负载异常


	// 6. 执行开机提示音

}
/**
* @brief	系统状态复位（关机/重置）
* @note	将所有业务逻辑标志位恢复至初始关闭状态
*/
void System_Status_PowerOff(void) 
{
	// 1. 关闭所有输出负载标志

	gpro_t.g_power_flag = 0;
	wifi_app_timer_power_on_f =0; //smart app power on by timer timing clear .

	first_temp_compare_f=0;
	ultra_sound_open_f = 0;

	plasma_open_f = 0;
	fan_open_f = 0;
	key_net_config_f =0;


	ptc_heat_open_f= 0;		// 默认--from smart phone define.
	ultra_sound_open_f = 0;	 // 默
	plasma_open_f = 0; 		 // 默
	set_temperature_value_f =0; 
	// 2. 重置所有功能模式标志
	AI_led_open_f = 0;
	Is_time_setting_f = 0;

	Is_countdown_timer_f = 0;
	works_interval_f =0;
	gpro_t.time_base_1s_counter=0;// 重置工作时间累计
	gpro_t.time_1m_f = 0;// 重置工作时间累计

	//wifi
	wifi_run_step=0;
	wifi_off_step =0;
	ptc_high_temperature_f =0;


	// 3. 重置所有时间/计数器
	timing_min_cnt = 0;

	Cacl_time_sec = 0;

	device_rest_time = 0;


	// 4. 特殊逻辑处理
	fan_warning_f = 0;
	power_off_peripheral_handler();


	// 5. 提示音
	all_led_off();
	TM1639_Display_ON_OFF(0);
}




