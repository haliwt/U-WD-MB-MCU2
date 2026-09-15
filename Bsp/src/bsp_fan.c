#include "bsp.h"





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

//∑Á…»øÿ÷∆
/**
*@brief : in 100ms processing .

**/
void Fan_Ctrl_Process(void)
{
   static uint8_t  fan_stop_f;
	if(gpro_t.g_power_flag){
	   if(works_interval_f == 0 && fan_rx_stop_flag ==0){
	      	
			fan_stop_f = 0;
			fan_one_minute_cuonter=0;;
	     
		if((fan_open_f)){
			if(fan_speed_level < 34)
			{
			fan_on(1280);
			}
			else if(fan_speed_level > 33 && fan_speed_level < 67)
			{
			fan_on(2048);
			}
			else if(fan_speed_level==100 || fan_speed_level > 66)
			{
			fan_on(2560);
			}

		
		}
    }
	else if(works_interval_f == 1){
       
		if(fan_one_minute_cuonter < 61  && fan_stop_f ==0){
		   fan_on(2560);  // FAN_RUN_ON(); 
	     
		}
		else{
		  fan_stop_f =2;
		  //FAN_RUN_OFF(); 
		  //fan_on(40);
		  fan_on(0); //fan_off();
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
	   if(works_interval_f == 0 && fan_rx_stop_flag ==0){
	      	
	     
		if((fan_open_f)){
			if(fan_speed_level < 34)
			{
			fan_on(1280);
			}
			else if(fan_speed_level > 33 && fan_speed_level < 67)
			{
			fan_on(2048);
			}
			else if(fan_speed_level==100 || fan_speed_level > 66)
			{
			fan_on(2560);
			}

			///__NOP();__NOP();__NOP();__NOP();__NOP();

			//FAN_RUN_ON();
		}
    }
	}
}


void fan_full_fun(void)
{

	
	//FAN_RUN_ON();
	fan_on(2560);

}

void fan_start_power_on(void)
{
	

	
	fan_on(2560);
	
}




void fan_stop(void)
{
    //FAN_RUN_OFF();
	//fan_on(40);//
    fan_on(0);//fan_off();
}




