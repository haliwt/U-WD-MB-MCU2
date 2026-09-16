#include "bsp.h"


static void fan_set_pwm_value(uint16_t ipwm);


void fan_wind_speed_low(void)
{
	fan_set_pwm_value(1280);
	FAN_DRIVER_ON();
}
		 
		 
void fan_wind_speed_middle(void)
{
	fan_set_pwm_value(2048);
	FAN_DRIVER_ON();

}
		  
		
void fan_wind_speed_full(void)
{
	fan_set_pwm_value(2048);
	FAN_DRIVER_ON();

}


/**
*
*@brief environment temperature value compare set temperater value
*@notice
*@param
*@retrval 
*
**/
void Fan_Current_Det(void)
{
	if((gpro_t.g_power_flag)&&(fan_open_f) && works_interval_f == 0)
	{
		if(fan_current<_NO_FAN_LOAD_CURRENT){
			fan_current_det_time++;
			if(fan_current_det_time>=2){
				fan_current_det_time = 0;

				if(!fan_warning_f)
				{
					//Beep(BEEP_THREE);
					beep_interval_time = 0;

					fan_open_f = 0;
				}

				fan_warning_f = 1;
			}
		}
		else{
		   fan_current_det_time = 0;
		}
	}
	else
	{
		fan_current_det_time = 0;
	}		   
}

//·çÉÈ¿ØÖÆ
/**
*@brief : in 100ms processing .

**/
uint8_t  fan_stop_interval_f;

void Fan_Ctrl_Process(void)
{
   
	if(gpro_t.g_power_flag){
	   if(works_interval_f == 0){
	      	
			fan_stop_interval_f = 0;
			fan_one_minute_cuonter=0;
	     
		if((fan_open_f)){
			if(fan_speed_level < 34)
			{
			 
			  fan_wind_speed_low();
			}
			else if(fan_speed_level > 33 && fan_speed_level < 67)
			{
			
			  fan_wind_speed_middle();
			}
			else if(fan_speed_level==100 || fan_speed_level > 66)
			{
			
			  fan_wind_speed_full();
			}

		
		}
    }
	else if(works_interval_f == 1){
       
		if(fan_one_minute_cuonter < 61  && fan_stop_interval_f ==0){
		    fan_wind_speed_full();
	     
		}
		else{
		  fan_stop_interval_f =2;
		  fan_stop();
		#if DEBUG_ENABLE 

		printf("fan_stop !!! \n\r");

		#endif 
		  

		}

	}

    }
 }

void wifiFan_Ctrl_Process(void)
{
   
	if(gpro_t.g_power_flag){
	   if(works_interval_f == 0 ){
	      	
	     
		if(fan_open_f==true){
			if(fan_speed_level < 34)
			{
		        fan_wind_speed_low();
			}
			else if(fan_speed_level > 33 && fan_speed_level < 67)
			{
			  fan_wind_speed_middle();
				
			}
			else if(fan_speed_level==100 || fan_speed_level > 66)
			{
			  fan_wind_speed_full();	
			}

		}
    }
	}
}



/**
  * @brief  // æŒ‰é”®æŒ‰ä¸‹æ—¶è°ƒç”¨
  * @note  
  * @param: 
  *
**/
void fan_stop(void)
{

    fan_set_pwm_value(0);
	FAN_DRIVER_OFF();
}


/**
*
*@brief 
*@notice
*@param
*@retrval 
*
**/
static void fan_set_pwm_value(uint16_t fan_duty)
{
 
	TIM_SetCompare1(TIM16,fan_duty);
	
	TIM_Cmd(TIM16, ENABLE);
    TIM_CtrlPWMOutputs(TIM16, ENABLE);
	
	
}





