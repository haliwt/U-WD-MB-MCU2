#include "bsp.h"


/**
*
*@brief environment temperature value compare set temperater value
*@notice
*@param
*@retrval 
*
**/
void Ultra_Sound_Ctrl(void)
{
    if(discharge_f)
    {
		    if(Ultra_Sound_open_f)
				{
				    ultra_sound_on(20); //
					LED_MOUSE_ON();
				}
				else
				{
				    ultra_sound_off();
					LED_MOUSE_OFF();
				}
		}
   
}

