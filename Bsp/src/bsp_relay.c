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
   
	if(ptc_prohibit_off_f == true) return ;
	
		 if((ptc_heat_open_f==true)  && works_interval_f == false){
                   
			  RELAY_ON();
					
			}
			else if(ptc_heat_open_f==false){
				
			  RELAY_OFF();
					
			}
}



void relay_ctrl_on(void)
{
	if((ptc_heat_open_f==true)	&& works_interval_f == false){
					  
				 RELAY_ON();
					   
	}


}
		


