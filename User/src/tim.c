/*
  ******************************************************************************
  * Copyright (c) 2024 Yspring.
  * All rights reserved..
  * @file    TIM.C
  * @author  Yspring Firmware Team  
  * @brief   TIM Source Code.
  ******************************************************************************      
*/

#include "ys32t031.h"
#include "tim.h"
#include "bsp.h"



void TIM1_Configuration(void);
void TIM3_Configuration(void);
void TIM6_Configuration(void);
void TIM14_Configuration(void);
//void BEEP_ON(void);
//void BEEP_OFF(void);
void fan_on(uint16_t fan_duty);
void fan_off(void);
void ultra_sound_on(uint16_t us_duty);
void ultra_sound_off(void);



/**
*
*@brief TIM1 CH1 as ULTRASONIC PWM IS 25KHZ
*@param  sysClock 64MHZ
*@retrval 
*
**/

void TIM1_Configuration(void)
{
    TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
    TIM_OCInitTypeDef TIM_OCInitStructure;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);

   // ÂÆöÊó∂Âë®Êúü = ((Ëá™Âä®ÈáçË£ÖËΩΩÂÄº426 + 1) * (È¢ÑÂàÜÈ¢ëÁ≥ªÊï∞ 5 + 1)) / 64000000 = 40 us, È¢ëÁéá= 25 kH
    TIM_TimeBaseStructInit(&TIM_TimeBaseStructure);
    TIM_TimeBaseStructure.TIM_Prescaler =  5;
    TIM_TimeBaseStructure.TIM_Period = 426;
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseStructure.TIM_ClockDivision = 0;
    TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;
    TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure);

    TIM_OCStructInit(&TIM_OCInitStructure);
    TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
    TIM_OCInitStructure.TIM_Pulse = 0;
    TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
    TIM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;
    TIM_OC3Init(TIM1, &TIM_OCInitStructure); //ÈÄöÈÅì 3

	TIM_OC1Init(TIM1, &TIM_OCInitStructure);//ÈÄöÈÅì 1 

    TIM_Cmd(TIM1, ENABLE);
    TIM_CtrlPWMOutputs(TIM1, ENABLE);
}



// TIM3 FAN IS SET 25KHZ FREQUENCY 
//sysClock 64MHZ
void TIM3_Configuration(void)
{
    TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
    TIM_OCInitTypeDef TIM_OCInitStructure;

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);

	// ÂÆöÊó∂Âë®Êúü = ((Ëá™Âä®ÈáçË£ÖËΩΩÂÄº426 + 1) * (È¢ÑÂàÜÈ¢ëÁ≥ªÊï∞ 5 + 1)) / 64000000 = 40 us, È¢ëÁéá= 25 kH

    TIM_TimeBaseStructInit(&TIM_TimeBaseStructure);
    TIM_TimeBaseStructure.TIM_Prescaler = 5;//47;//5; SYSCLOCK IS 48MHZ .
    TIM_TimeBaseStructure.TIM_Period = 426;//319;//39;//319; //F =1/(39+1)= 0.025MHZ 
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseStructure.TIM_ClockDivision = 0;
    TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);

    TIM_OCStructInit(&TIM_OCInitStructure);
    TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
    TIM_OCInitStructure.TIM_Pulse = 0;
    TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
    TIM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;
    TIM_OC1Init(TIM3, &TIM_OCInitStructure);

    TIM_Cmd(TIM3, ENABLE);
    TIM_CtrlPWMOutputs(TIM3, ENABLE);  
}



/**
*
*@brief TIM6 as timer is 5ms 
*@param  sysClock 64MHZ
*@retrval 
*
**/
void TIM6_Configuration(void)
{
    TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6, ENABLE);

    // “Á≥ˆ ±º‰ = ((63 + 1) * (4999 + 1)) / 64000000 = 5 ms,  = 200 Hz
    TIM_TimeBaseStructInit(&TIM_TimeBaseStructure);
    TIM_TimeBaseStructure.TIM_Prescaler = 63;//95;
    TIM_TimeBaseStructure.TIM_Period = 4999;//2499;
    TIM_TimeBaseInit(TIM6, &TIM_TimeBaseStructure);

	TIM_ClearFlag(TIM6, TIM_FLAG_Update);                   // «Â≥˝º∆ ˝∆˜÷–∂œ±Í÷æŒª  
    TIM_ITConfig(TIM6,TIM_IT_Update,ENABLE);
	
    TIM_Cmd(TIM6, ENABLE);
}


/**
*
*@brief TIM14 FOR BUZZER IS 4 KHZ -TIM14-CH1
*@notice  sysClock is 64MHZ
*@param
*@retrval 
*
**/
void TIM14_Configuration(void)
{
    TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
    TIM_OCInitTypeDef TIM_OCInitStructure;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM14, ENABLE);

    // “Á≥ˆ ±º‰ = (preio d999 + 1) * (Prescaler 15 + 1)) 648000000 = 250 ¶Ãs, ∆µ¬ = 4 kHz
    TIM_TimeBaseStructInit(&TIM_TimeBaseStructure);
    TIM_TimeBaseStructure.TIM_Prescaler = 15;
    TIM_TimeBaseStructure.TIM_Period = 999;//749;
    TIM_TimeBaseStructure.TIM_ClockDivision = 0;
    TIM_TimeBaseInit(TIM14, &TIM_TimeBaseStructure);

    TIM_OCStructInit(&TIM_OCInitStructure);
    TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
    TIM_OCInitStructure.TIM_Pulse = 0;
    TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
    TIM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;
    TIM_OC1Init(TIM14, &TIM_OCInitStructure);

    TIM_Cmd(TIM14, ENABLE);
    TIM_CtrlPWMOutputs(TIM14, ENABLE);
}






/**
*
*@brief 
*@notice
*@param
*@retrval 
*
**/
void fan_on(uint16_t fan_duty)
{
    #if 1
	TIM_SetCompare1(TIM3,fan_duty);
	
	TIM_Cmd(TIM3, ENABLE);
    TIM_CtrlPWMOutputs(TIM3, ENABLE);
	#else 

	TIM_SetCompare1(TIM1,fan_duty);
	
	TIM_Cmd(TIM1, ENABLE);
    TIM_CtrlPWMOutputs(TIM1, ENABLE);
	
	#endif 
}


//∑Á…»πÿ
void fan_off(void)
{
//    TIM_SetCompare1(TIM3,0);
	
//	TIM_Cmd(TIM3, DISABLE);
//    TIM_CtrlPWMOutputs(TIM3, DISABLE);
	fan_on(0);

}



//≥¨…˘≤®ø™
void ultra_sound_on(uint16_t us_duty)
{
    
	TIM_SetCompare3(TIM1,us_duty);
	
	  TIM_Cmd(TIM1, ENABLE);
    TIM_CtrlPWMOutputs(TIM1, ENABLE);
	
}


//≥¨…˘≤®πÿ
void ultra_sound_off(void)
{
    TIM_SetCompare3(TIM1,0);
	
	  TIM_Cmd(TIM1, ENABLE);
    TIM_CtrlPWMOutputs(TIM1, ENABLE);
}










