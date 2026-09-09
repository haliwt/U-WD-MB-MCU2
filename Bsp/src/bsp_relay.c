#include "bsp.h"

/**
*
*@brief 
*@notice
*@param
*
**/
void Relay_Ctrl(void)
{
   
	if(gpro_t.g_power_flag){
		    if((ptc_heat_open_f==1)&& ptc_prohibit_off_f == 0 && works_interval_f ==0)
				{
                   // LED_PTC_ON();
					RELAY_ON();
					
				}
				else if(ptc_heat_open_f==0)
				{
					//LED_PTC_OFF();
					RELAY_OFF();
					
				}
		}

	
		
}

