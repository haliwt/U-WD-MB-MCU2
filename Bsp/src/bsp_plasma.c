#include "bsp.h"

/**
  * @brief  
  * @note  
  * @param: 
  *
**/
void Plasma_Ctrl(void)
{
	  if(gpro_t.g_power_flag){
        if(plasma_open_f==true)
		    {
		        PLASMA_ON();
				//LED_PLASMA_ON();
		    }
		    else 
		    {
		        PLASMA_OFF();
				//LED_PLASMA_OFF();
		    }
        }
		
}




