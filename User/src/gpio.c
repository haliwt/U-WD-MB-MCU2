#include "gpio.h"


void gpio_init(void)
{
  LL_GPIO_InitTypeDef GPIO_InitStruct = {0};
  LL_AHB2_GRP1_EnableClock(LL_AHB2_GRP1_PERIPH_GPIOA);
  LL_AHB2_GRP1_EnableClock(LL_AHB2_GRP1_PERIPH_GPIOB);
  LL_AHB2_GRP1_EnableClock(LL_AHB2_GRP1_PERIPH_GPIOF);

  // GPIO_Output
  LL_GPIO_ResetOutputPin(PLASMA_GPIO_Port, LL_PLASMA_Pin);
  LL_GPIO_ResetOutputPin(ANALOG_TX_GPIO_Port, LL_ANALOG_TX_Pin);
  LL_GPIO_ResetOutputPin(ANALOG_RX_GPIO_Port, LL_ANALOG_RX_Pin);
  LL_GPIO_StructInit(&GPIO_InitStruct);
  GPIO_InitStruct.Pin = LL_PLASMA_Pin | LL_ANALOG_TX_Pin | LL_ANALOG_RX_Pin;
  GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
  GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
  GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_HIGH;
  GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
  LL_GPIO_Init(PLASMA_GPIO_Port, &GPIO_InitStruct);

  // GPIO_Input
  LL_GPIO_StructInit(&GPIO_InitStruct);
  GPIO_InitStruct.Pin = LL_KEY_MODE_Pin;
  GPIO_InitStruct.Mode = LL_GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = LL_GPIO_PULL_UP;
  LL_GPIO_Init(KEY_MODE_GPIO_Port, &GPIO_InitStruct);

  // ADC_IN2
  LL_GPIO_StructInit(&GPIO_InitStruct);
  GPIO_InitStruct.Pin = LL_ADC_FAN_Pin;
  GPIO_InitStruct.Mode = LL_GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
  LL_GPIO_Init(ADC_FAN_GPIO_Port, &GPIO_InitStruct);

  // ADC_IN3
  LL_GPIO_StructInit(&GPIO_InitStruct);
  GPIO_InitStruct.Pin = LL_ADC_PTC_Pin;
  GPIO_InitStruct.Mode = LL_GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
  LL_GPIO_Init(ADC_PTC_GPIO_Port, &GPIO_InitStruct);

  // TIM1_CH1
  LL_GPIO_StructInit(&GPIO_InitStruct);
  GPIO_InitStruct.Alternate = LL_GPIO_AF_2;
  GPIO_InitStruct.Pin = LL_ULTR_PWM_Pin;
  GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
  GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
  GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
  LL_GPIO_Init(ULTR_PWM_GPIO_Port, &GPIO_InitStruct);


  // TIM14_CH1 --GPIOB LL_PIN_1
  #if 1
  LL_GPIO_StructInit(&GPIO_InitStruct);
  GPIO_InitStruct.Alternate = LL_GPIO_AF_0;
  GPIO_InitStruct.Pin = LL_GPIO_PIN_1;
  GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
  GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
  GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
  LL_GPIO_Init(GPIOB, &GPIO_InitStruct);
  #else

   // TIM14_CH1
    GPIO_PinAFConfig(GPIOB, GPIO_PinSource1, GPIO_AF_0);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_VeryHigh;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

  #endif 

  // TIM16_CH1
  LL_GPIO_StructInit(&GPIO_InitStruct);
  GPIO_InitStruct.Alternate = LL_GPIO_AF_5;
  GPIO_InitStruct.Pin = LL_FAN_PWM_Pin;
  GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
  GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
  GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
  LL_GPIO_Init(FAN_PWM_GPIO_Port, &GPIO_InitStruct);


  // UART1_TX
  LL_GPIO_StructInit(&GPIO_InitStruct);
  GPIO_InitStruct.Alternate = LL_GPIO_AF_1;
  GPIO_InitStruct.Pin = LL_DSP1_TX_Pin;
  GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
  GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
  GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Pull = LL_GPIO_PULL_UP;
  LL_GPIO_Init(DSP1_TX_GPIO_Port, &GPIO_InitStruct);

  // UART1_RX
  LL_GPIO_StructInit(&GPIO_InitStruct);
  GPIO_InitStruct.Alternate = LL_GPIO_AF_1;
  GPIO_InitStruct.Pin = LL_DSP1_RX_Pin;
  GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
  GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
  GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Pull = LL_GPIO_PULL_UP;
  LL_GPIO_Init(DSP1_RX_GPIO_Port, &GPIO_InitStruct);

  // UART2_TX
  LL_GPIO_StructInit(&GPIO_InitStruct);
  GPIO_InitStruct.Alternate = LL_GPIO_AF_1;
  GPIO_InitStruct.Pin = LL_WIFI2_TX_Pin;
  GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
  GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
  GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Pull = LL_GPIO_PULL_UP;
  LL_GPIO_Init(WIFI2_TX_GPIO_Port, &GPIO_InitStruct);

  // UART2_RX
  LL_GPIO_StructInit(&GPIO_InitStruct);
  GPIO_InitStruct.Alternate = LL_GPIO_AF_4;
  GPIO_InitStruct.Pin = LL_WIFI2_RX_Pin;
  GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
  GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
  GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Pull = LL_GPIO_PULL_UP;
  LL_GPIO_Init(WIFI2_RX_GPIO_Port, &GPIO_InitStruct);

  // GPIO_Output
  LL_GPIO_ResetOutputPin(RELAY_GPIO_Port, LL_RELAY_Pin);
  LL_GPIO_ResetOutputPin(LED_POWER_GPIO_Port, LL_LED_POWER_Pin);
  LL_GPIO_ResetOutputPin(LED_TIM_GPIO_Port, LL_LED_TIM_Pin);
  LL_GPIO_ResetOutputPin(LED_BACK_LIGHT_GPIO_Port, LL_LED_BACK_LIGHT_Pin);
  LL_GPIO_ResetOutputPin(MCU_DIO_GPIO_Port, LL_MCU_DIO_Pin);
  LL_GPIO_ResetOutputPin(MCU_CLK_GPIO_Port, LL_MCU_CLK_Pin);
  LL_GPIO_ResetOutputPin(MCU_STB_GPIO_Port, LL_MCU_STB_Pin);
  LL_GPIO_ResetOutputPin(TEMP_GPIO_Port, LL_TEMP_Pin);
  LL_GPIO_ResetOutputPin(MUTE_GPIO_Port, LL_MUTE_Pin);
  LL_GPIO_StructInit(&GPIO_InitStruct);
  GPIO_InitStruct.Pin = LL_RELAY_Pin | LL_LED_POWER_Pin | LL_LED_TIM_Pin | LL_LED_BACK_LIGHT_Pin | LL_MCU_DIO_Pin | LL_MCU_CLK_Pin | LL_MCU_STB_Pin | LL_TEMP_Pin | LL_MUTE_Pin;
  GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
  GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
  GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_HIGH;
  GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
  LL_GPIO_Init(RELAY_GPIO_Port, &GPIO_InitStruct);

  // GPIO_Input
  LL_GPIO_StructInit(&GPIO_InitStruct);
  GPIO_InitStruct.Pin = LL_KEY_DEC_Pin;
  GPIO_InitStruct.Mode = LL_GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
  LL_GPIO_Init(KEY_DEC_GPIO_Port, &GPIO_InitStruct);


  // GPIO_Output
  LL_GPIO_ResetOutputPin(FAN_RUN_GPIO_Port, LL_FAN_RUN_Pin);
  LL_GPIO_StructInit(&GPIO_InitStruct);
  GPIO_InitStruct.Pin = LL_FAN_RUN_Pin;
  GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
  GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
  GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_HIGH;
  GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
  LL_GPIO_Init(FAN_RUN_GPIO_Port, &GPIO_InitStruct);

  // GPIO_Input
  LL_GPIO_StructInit(&GPIO_InitStruct);
  GPIO_InitStruct.Pin = LL_KEY_INC_Pin | LL_KEY_POWER_Pin;
  GPIO_InitStruct.Mode = LL_GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
  LL_GPIO_Init(KEY_INC_GPIO_Port, &GPIO_InitStruct);
 
 }


#if 0
// GPIO ≥ı ºªØ≈‰÷√
void GPIO_Configuration(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_StructInit(&GPIO_InitStructure);

    GPIO_DeInit(GPIOA);
    GPIO_DeInit(GPIOB);
    GPIO_DeInit(GPIOC);
    GPIO_DeInit(GPIOF);

    RCC_AHB2PeriphClockCmd(RCC_AHB2Periph_GPIOA, ENABLE);
    RCC_AHB2PeriphClockCmd(RCC_AHB2Periph_GPIOB, ENABLE);
    RCC_AHB2PeriphClockCmd(RCC_AHB2Periph_GPIOC, ENABLE);
    RCC_AHB2PeriphClockCmd(RCC_AHB2Periph_GPIOF, ENABLE);
	
	  GPIO_WriteBit(GPIOA, GPIO_Pin_11, Bit_SET);
    GPIO_WriteBit(GPIOA, GPIO_Pin_12, Bit_SET);
    GPIO_WriteBit(GPIOA, GPIO_Pin_15, Bit_SET);
	
	GPIO_WriteBit(GPIOB, GPIO_Pin_7, Bit_SET);
    GPIO_WriteBit(GPIOB, GPIO_Pin_8, Bit_SET);
    GPIO_WriteBit(GPIOB, GPIO_Pin_9, Bit_SET);
	
	GPIO_WriteBit(GPIOF, GPIO_Pin_6, Bit_SET);
    GPIO_WriteBit(GPIOF, GPIO_Pin_7, Bit_SET);

    // GPIO_Output
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_Low;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	  GPIO_WriteBit(GPIOA, GPIO_Pin_4, Bit_SET);

    // GPIO_Output
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7 | GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_15;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_High;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
	

	GPIO_WriteBit(GPIOA, GPIO_Pin_7, Bit_RESET);
    GPIO_WriteBit(GPIOA, GPIO_Pin_11, Bit_SET);
    GPIO_WriteBit(GPIOA, GPIO_Pin_12, Bit_SET);
    GPIO_WriteBit(GPIOA, GPIO_Pin_15, Bit_SET);

    // ADC_IN2
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    // ADC_IN3
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    // TIM1_CH3
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource8, GPIO_AF_4);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_VeryHigh;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

	 // TIM1_CH1
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource5, GPIO_AF_2);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_VeryHigh;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    #if 0
    // TIM3_CH1
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource6, GPIO_AF_1);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_VeryHigh;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;//NOPULL; WT.EDIT 2026-05-16
    GPIO_Init(GPIOA, &GPIO_InitStructure);
	#endif 

    // UART1_TX
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource9, GPIO_AF_1);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_VeryHigh;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    // UART1_RX
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource10, GPIO_AF_1);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_VeryHigh;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    // UART2_TX
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource2, GPIO_AF_1);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_VeryHigh;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    // UART2_RX
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource3, GPIO_AF_4);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_VeryHigh;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    // GPIO_Output
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_2 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_High;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	GPIO_WriteBit(GPIOB, GPIO_Pin_0, Bit_RESET);
    GPIO_WriteBit(GPIOB, GPIO_Pin_2, Bit_RESET);
	GPIO_WriteBit(GPIOB, GPIO_Pin_7, Bit_SET);
    GPIO_WriteBit(GPIOB, GPIO_Pin_8, Bit_SET);
    GPIO_WriteBit(GPIOB, GPIO_Pin_9, Bit_SET);
    GPIO_WriteBit(GPIOB, GPIO_Pin_10, Bit_RESET);
    GPIO_WriteBit(GPIOB, GPIO_Pin_11, Bit_RESET);
    GPIO_WriteBit(GPIOB, GPIO_Pin_12, Bit_RESET);
    GPIO_WriteBit(GPIOB, GPIO_Pin_13, Bit_RESET);
    GPIO_WriteBit(GPIOB, GPIO_Pin_14, Bit_RESET);
    GPIO_WriteBit(GPIOB, GPIO_Pin_15, Bit_RESET);
		//GPIO_WriteBit(GPIOA, GPIO_Pin_5, Bit_RESET);

    #if 0
    // TSC_IO7
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

    // TSC_IO8
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

    // TSC_IO9
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

    // TSC_IO10
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

	#else 
    //GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5|GPIO_Pin_6; 
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_Init(GPIOB, &GPIO_InitStructure);



    #endif 


    // TIM14_CH1
    GPIO_PinAFConfig(GPIOB, GPIO_PinSource1, GPIO_AF_0);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_VeryHigh;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

		// GPIO_Output
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13|GPIO_Pin_14 | GPIO_Pin_15;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_Low;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOC, &GPIO_InitStructure);
	
	  GPIO_WriteBit(GPIOC, GPIO_Pin_13, Bit_SET);
    GPIO_WriteBit(GPIOC, GPIO_Pin_14, Bit_SET);
    GPIO_WriteBit(GPIOC, GPIO_Pin_15, Bit_SET);
		
    // GPIO_Output
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_9;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_High;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOF, &GPIO_InitStructure);
		
	GPIO_WriteBit(GPIOF, GPIO_Pin_0, Bit_RESET);
    GPIO_WriteBit(GPIOF, GPIO_Pin_1, Bit_RESET);
    GPIO_WriteBit(GPIOF, GPIO_Pin_3, Bit_RESET);
    GPIO_WriteBit(GPIOF, GPIO_Pin_4, Bit_RESET);
    GPIO_WriteBit(GPIOF, GPIO_Pin_6, Bit_SET);
    GPIO_WriteBit(GPIOF, GPIO_Pin_7, Bit_SET);
	GPIO_WriteBit(GPIOF, GPIO_Pin_9, Bit_RESET);

    // GPIO_Input
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_8;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOF, &GPIO_InitStructure);
}
	

#endif 
 

