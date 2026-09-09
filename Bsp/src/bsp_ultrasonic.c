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
    if(gpro_t.g_power_flag)
    {
		    if(ultra_sound_open_f)
				{
				    ultra_sound_on(20); //
					//LED_MOUSE_ON();
				}
				else
				{
				    ultra_sound_off();
					//LED_MOUSE_OFF();
				}
		}
   
}

