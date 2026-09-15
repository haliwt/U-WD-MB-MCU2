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

    // Overflow time = ((Auto-reload 2559 + 1) * (Prescaler 0 + 1)) / 64000000 = 40 Œºs, frequency= 25 kHz
    TIM_TimeBaseStructInit(&TIM_TimeBaseStructure);
    TIM_TimeBaseStructure.TIM_Prescaler = 0;// 5;
    TIM_TimeBaseStructure.TIM_Period = 2559;//319;
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
   // TIM_OC3Init(TIM1, &TIM_OCInitStructure); //ÈÄöÈÅì 3

	TIM_OC1Init(TIM1, &TIM_OCInitStructure);//ÈÄöÈÅì 1 

    TIM_Cmd(TIM1, ENABLE);
    TIM_CtrlPWMOutputs(TIM1, ENABLE);
}


#if 0
// TIM3 FAN IS SET 25KHZ FREQUENCY 
//sysClock  FAN PWM
void TIM3_Configuration(void)
{
    TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
    TIM_OCInitTypeDef TIM_OCInitStructure;

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);

	// ÂÆöÊó∂Âë®Êúü = ((Ëá™Âä®ÈáçË£ÖËΩΩÂÄº426 + 1) * (È¢ÑÂàÜÈ¢ëÁ≥ªÊï∞ 5 + 1)) / 64000000 = 40 us, È¢ëÁéá= 25 kH

    TIM_TimeBaseStructInit(&TIM_TimeBaseStructure);
    TIM_TimeBaseStructure.TIM_Prescaler = 0;//47;//5; SYSCLOCK IS 48MHZ .
    TIM_TimeBaseStructure.TIM_Period = 2559;//319;//39;//319; //F =1/(39+1)= 0.025MHZ 
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


#endif 
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
    TIM_TimeBaseStructure.TIM_Period = 9999;//
    TIM_TimeBaseInit(TIM6, &TIM_TimeBaseStructure);

	TIM_ClearFlag(TIM6, TIM_FLAG_Update);                   // «Â≥˝º∆ ˝∆˜÷–∂œ±Í÷æŒª  
    TIM_ITConfig(TIM6,TIM_IT_Update,ENABLE);
	
    TIM_Cmd(TIM6, ENABLE);
}


/**
*
*@brief TIM14 FOR BUZZER IS 4 KHZ -TIM14-CH1
*@notice  sysClock is 64MHZ GPIOB ,
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
    TIM_TimeBaseStructure.TIM_Prescaler = 0; //15;
    TIM_TimeBaseStructure.TIM_Period = 15999;
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



// TIM16 ÂàùÂßãÂåñÈÖçÁΩÆ
//FAN PWM 
void TIM16_Configuration(void)
{
  TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
  TIM_OCInitTypeDef TIM_OCInitStructure;

  RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM16, ENABLE);

  // Overflow time = ((Auto-reload 2559 + 1) * (Prescaler 0 + 1)) / 64000000 = 40 Œºs, frequency= 25 kHz
  TIM_TimeBaseStructInit(&TIM_TimeBaseStructure);
  TIM_TimeBaseStructure.TIM_Prescaler = 0;
  TIM_TimeBaseStructure.TIM_Period = 2559;
  TIM_TimeBaseStructure.TIM_ClockDivision = 0;
  TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;
  TIM_TimeBaseInit(TIM16, &TIM_TimeBaseStructure);

  TIM_OCStructInit(&TIM_OCInitStructure);
  TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OCInitStructure.TIM_Pulse = 0;
  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
  TIM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;
  TIM_OC1Init(TIM16, &TIM_OCInitStructure);

  TIM_Cmd(TIM16, ENABLE);

  TIM_CtrlPWMOutputs(TIM16, ENABLE);
}








//≥¨…˘≤®ø™
void ultra_sound_on(uint16_t us_duty)
{
    
	TIM_SetCompare1(TIM1,1280);
	
	TIM_Cmd(TIM1, ENABLE);
    TIM_CtrlPWMOutputs(TIM1, ENABLE);
	
}


//≥¨…˘≤®πÿ
void ultra_sound_off(void)
{
    TIM_SetCompare1(TIM1,0);
	
	//TIM_Cmd(TIM1, DISABLE);
   // TIM_CtrlPWMOutputs(TIM1, ENABLE);
}










