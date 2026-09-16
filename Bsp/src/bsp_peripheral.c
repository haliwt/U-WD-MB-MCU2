#include "bsp.h"






#if 0
        else
			{
			if(fan_delay_time_off!=0){
				fan_delay_time_off--;

				if(fan_speed_level==1)
				{
				fan_set_pwm_value(287);
				}   
				else if(fan_speed_level==2)
				{
				fan_set_pwm_value(303);
				}
				else if(fan_speed_level==3)
				{
				fan_set_pwm_value(319);
				}

				__NOP();__NOP();__NOP();__NOP();__NOP();

				FAN_RUN_ON();
			}
			else
			{
			FAN_RUN_OFF();

			__NOP();__NOP();__NOP();__NOP();__NOP();

			fan_off();
			}
			}					
		}
		else
		{
        	if(fan_delay_time_off!=0)
				{
				    fan_delay_time_off--;
							
						if(fan_speed_level==1)
						{
						    fan_set_pwm_value(287);
						}   
						else if(fan_speed_level==2)
						{
						    fan_set_pwm_value(303);
						}
						else if(fan_speed_level==3)
						{
						    fan_set_pwm_value(319);
						}
						
						__NOP();__NOP();__NOP();__NOP();__NOP();
						
						FAN_RUN_ON();
				}
				else
				{
				    FAN_RUN_OFF();
			
			      __NOP();__NOP();__NOP();__NOP();__NOP();
			
		        fan_off();
				}
		}
}

#endif 
/**
  * @brief  
  * @note  
  * @param: 
  *
**/

#if 0
//�������������
void Beep(Beep_TypeDef music)
{
    switch (music)
	  {
		    case BEEP_ONCE:
			     beep_times=1;
			     beep_lenght=2; 
			     non_beep_length=0;
			     break;
		
		    case BEEP_TWO:
			     beep_times=4;
			     beep_lenght=BEEP_LENGTH_DEFAULT; 
			     non_beep_length=NON_BEEP_LENGTH_DEFAULT;
			     break;			
		
				case BEEP_THREE:
			     beep_times=6;
			     beep_lenght=2; 
			     non_beep_length=NON_BEEP_LENGTH_DEFAULT;
			     break;
				
		    case BEEP_1SECONDS:
			     beep_times=1;
			     beep_lenght=100; 			//10ms*100=1seconds
			     non_beep_length=0;
			     break;	
		
		    case BEEP_TIME_OVER:
			     beep_times=15;
			     beep_lenght=200; 			//10ms*200=2seconds
			     non_beep_length=0;
			     break;			
		
		    default:
			     beep_times=0;
			     beep_lenght=0; 
			     non_beep_length=0;	
           break;		
    }
} 

#endif 

/**
*
*@brief 
*@notice
*@param
*
**/










	

/**
*
*@brief environment temperature value compare set temperater value
*@notice
*@param
*@retrval 
*
**/
void workd_interval_time_peripheral_handle(void)
{
	if(gpro_t.g_power_flag){

		if((ptc_heat_open_f==1)&& ptc_prohibit_off_f == 0)
		{
			//LED_PTC_ON();
        }
		else if(ptc_heat_open_f==0)
		{
			//LED_PTC_OFF();


		}
		
		if(ultra_sound_open_f)
		{

			//LED_MOUSE_ON();
		}
		else
		{

			//LED_MOUSE_OFF();
		}
		
		if(plasma_open_f)
		{

		//LED_PLASMA_ON();
		}
			else
		{

		//LED_PLASMA_OFF();
		}
	}
 
}



void workd_interval_turn_off_handle(void)
{
	RELAY_OFF();
	ultra_sound_off();
	PLASMA_OFF();
		
}


/************************************************************************
*
* Function Name: LED_Power_Breathing(void)
* ĺč˝:
* ĺć°:ć 
* čżĺĺź:ć 
*
************************************************************************/
void compare_set_temp_value(void)
{

	if(wifi_connected_success_f == 1){
		MqttData_Publis_SetTemp(setting_temperature);
		//wait_timeout = tx_time_get()+20;
	}

	if(ptc_heat_open_f== 1 && wifi_connected_success_f==1){
     	MqttData_Publish_SetPtc(1);

	}
	else if(wifi_connected_success_f==1){

	  MqttData_Publish_SetPtc(0);

	}

}

void direct_compare_set_temp_value(void)
{

    
    // 如果当前正处于“等待响应”的时间段内，直接跳出，让 UI 任务跑别的 Slot
   
	if(temperature >= setting_temperature){
	     ptc_prohibit_off_f = 0;
	     ptc_heat_open_f= 0;   // 立即关闭
	     RELAY_OFF();
		 //LED_PTC_OFF();
		

    }
	else{
	    ptc_prohibit_off_f = 0;
		ptc_heat_open_f= 1;   // 立即open
		//LED_PTC_ON();
		if(works_interval_f == 0)RELAY_ON();
		 
	}

}



/**
*
*@brief 
*@notice
*@param
*
**/
void peripheral_hardware_handler(void)
{
   if(gpro_t.g_power_flag==true){

    switch(works_interval_f){

	case 0:
     
      Plasma_Ctrl();
      Ultra_Sound_Ctrl();
	  Relay_Ctrl();

	 if(disp_set_hours_time_f == 1 || Is_time_setting_f ==1) return ;
	  
      if(AI_led_open_f==1){
	  	//LED_AI_ON();
	  }
	  else{
	    // LED_AI_OFF();

	  }
    break;

	case 1: //have a rest 10 minutes 
	
       workd_interval_time_peripheral_handle();
	   workd_interval_turn_off_handle();
	   
	   if(disp_set_hours_time_f == 1 || Is_time_setting_f ==1) return ;
	   if(AI_led_open_f==1){
	  	//LED_AI_ON();
	   }
	   else{
	    // LED_AI_OFF();
       }

	break;
	  
    }

	}

}

/**
*
*@brief 
*@notice
*@param
*
**/

void power_off_peripheral_handler(void)
{

	RELAY_OFF();
	ultra_sound_off();
	PLASMA_OFF();


}

/**
*
*@brief 
*@notice
*@param
*
**/

void power_on_peripheral_handler(void)
{

	RELAY_ON();
	ultra_sound_on(20);//(159); 
	PLASMA_ON();


}


