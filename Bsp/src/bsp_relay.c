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
		 if((ptc_heat_open_f==true) && ptc_prohibit_off_f == false && works_interval_f == false){
                   
			  RELAY_ON();
					
			}
			else if(ptc_heat_open_f==false){
				
			  RELAY_OFF();
					
			}
		}

	
		
}

