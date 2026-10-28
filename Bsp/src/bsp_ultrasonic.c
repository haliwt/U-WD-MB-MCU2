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
	if(works_interval_f == false)
	{
		if(ultra_sound_open_f==true)
		{
			ultra_sound_on(20); //
			//LED_MOUSE_ON();
		}
		else {
			ultra_sound_off();
			//LED_MOUSE_OFF();
		}
	}
   
}

