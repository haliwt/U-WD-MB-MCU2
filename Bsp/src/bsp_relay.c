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
		    if((ptc_heat_open_f==true) && ptc_prohibit_off_f == false && works_interval_f == false)
				{
                   // LED_PTC_ON();
					RELAY_ON();
					
				}
				else{
					//LED_PTC_OFF();
					RELAY_OFF();
					
				}
		}

	
		
}

