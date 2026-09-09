#include "bsp.h"

/**
*
*@brief 
*@notice
*@param
*
**/

//void BEEP_ERROR_ON(void)
//{
//        TIM_SetCompare1(TIM14, 374);
//        TIM_Cmd(TIM14, ENABLE);
//        TIM_CtrlPWMOutputs(TIM14, ENABLE);
//		tx_thread_sleep(50);//open_beep_sound();
//        TIM_SetCompare1(TIM14,0);

//        TIM_Cmd(TIM14, DISABLE);
//}

void BEEP_ON(void)
{
	      TIM_SetCompare1(TIM14, 374);
		  TIM_Cmd(TIM14, ENABLE);
		  TIM_CtrlPWMOutputs(TIM14, ENABLE);
		  tx_thread_sleep(2);//open_beep_sound();
		  TIM_SetCompare1(TIM14,0);
	
		  TIM_Cmd(TIM14, DISABLE);


}

void fan_err_beep_on(void)
{
    
        TIM_SetCompare1(TIM14, 374);
        TIM_Cmd(TIM14, ENABLE);
        TIM_CtrlPWMOutputs(TIM14, ENABLE);
		tx_thread_sleep(4);//open_beep_sound();
        TIM_SetCompare1(TIM14,0);

        TIM_Cmd(TIM14, DISABLE);
   }





//·äÃùÆ÷¹Ø
void BEEP_OFF(void)
{
    TIM_SetCompare1(TIM14,0);
	
	TIM_Cmd(TIM14, DISABLE);
    //TIM_CtrlPWMOutputs(TIM14, ENABLE);
}

void beep_high_temperature_sound(void)
{
	fan_err_beep_on();
	tx_thread_sleep(20);
	fan_err_beep_on();
	tx_thread_sleep(20);
	fan_err_beep_on();
	tx_thread_sleep(20);
	fan_err_beep_on();
	tx_thread_sleep(20);
	fan_err_beep_on();
	tx_thread_sleep(20);
	fan_err_beep_on();
	tx_thread_sleep(20);

}

void beep_fan_default_sound(void)
{
	fan_err_beep_on();
	tx_thread_sleep(30);
	fan_err_beep_on();
	tx_thread_sleep(30);
	fan_err_beep_on();
	tx_thread_sleep(30);
	fan_err_beep_on();
	tx_thread_sleep(30);
	fan_err_beep_on();
	tx_thread_sleep(30);
	fan_err_beep_on();
	tx_thread_sleep(30);

}


