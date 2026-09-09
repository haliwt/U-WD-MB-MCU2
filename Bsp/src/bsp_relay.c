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
   
	if(discharge_f){
		    if((PTC_heat_open_f==1)&& ptc_prohibit_off_f == 0 && works_interval_f ==0)
				{
                   // LED_PTC_ON();
					RELAY_ON();
					
				}
				else if(PTC_heat_open_f ==0)
				{
					//LED_PTC_OFF();
					RELAY_OFF();
					
				}
		}

	
		
}

