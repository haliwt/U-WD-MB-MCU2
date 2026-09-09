/*
  ******************************************************************************
  * Copyright (c) 2024 Yspring.
  * All rights reserved..
  * @file    system_init.C
  * @author  Yspring Firmware Team  
  * @brief   system_init Source Code.
  ******************************************************************************      
*/

#include "system_init.h"
//#include "bsp.h"
#include "delay.h"
#include "ys32t031.h"
#include "ys32t031_it.h"   
#include <stdint.h>



void RCC_Configuration(void);
void GPIO_Configuration(void);
void NVIC_Configuration(void);


// RCC initialization configuration
#if 0
void RCC_Configuration(void)
{
    FLASH_SetLatency(FLASH_Latency_3);
	
    // Enable LSI
    RCC_LSICmd(ENABLE);

    RCC_HSI_CLK(RCC_HSI_48M, RCC_HSI_CLK_Div1);
    RCC_HSICmd(ENABLE);
    while( RCC_GetFlagStatus(RCC_FLAG_HSIRDY) == RESET);

    // HCLK = 48 MHz
    RCC_HCLKConfig(RCC_SYSCLK_Div1);

    RCC_SYSCLKConfig(RCC_SOURCE_HSI);
    while (RCC_GetSYSCLKSource() != RCC_SOURCE_HSI);

    FLASH_SetLatency(FLASH_Latency_2);

    // PCLK = 48 MHz
    RCC_PCLKConfig(RCC_HCLK_Div1);

    // SYSCLK = 48 MHz
    SystemCoreClockUpdate();
}
#else
void RCC_Configuration(void)
{
    FLASH_SetLatency(FLASH_Latency_3);   // 64MHz ÈúÄË¶Å 3 ‰∏™Á≠âÂæÖÂë®Êúü

    // 1. ÂêØÂä®ÂÜÖÈÉ®Êô∂ÊåØ HSI = 16MHz
    RCC_HSI_CLK(RCC_HSI_16M, RCC_HSI_CLK_Div1);
    RCC_HSICmd(ENABLE);
    while (RCC_GetFlagStatus(RCC_FLAG_HSIRDY) == RESET);

    // 2. ÈÖçÁΩÆ PLLÔºö16MHz √ó 4 = 64MHz
    RCC_PLLConfig(RCC_PLLSource_HSI, RCC_PLLMul_4);
    RCC_PLLCmd(ENABLE);
    while (RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET);

    // 3. ÂàáÊç¢Á≥ªÁªüÊó∂ÈíüÂà∞ PLL ËæìÂá∫
    RCC_SYSCLKConfig(RCC_SOURCE_PLL);
    while (RCC_GetSYSCLKSource() != RCC_SOURCE_PLL);

    // 4. HCLK = SYSCLK = 64MHz
    RCC_HCLKConfig(RCC_SYSCLK_Div1);

    // 5. PCLK = HCLK = 64MHz
    RCC_PCLKConfig(RCC_HCLK_Div1);

    SystemCoreClockUpdate();
}


#endif 






//NVIC÷–∂œ≈‰÷√
void NVIC_Configuration(void)
{
    NVIC_InitTypeDef NVIC_InitStructure;
	
	  NVIC_InitStructure.NVIC_IRQChannel = TIM6_LPTIM_IRQn ;   //…Ë÷√÷–∂œ¿¥‘¥
    NVIC_InitStructure.NVIC_IRQChannelPriority = 0;          //…Ë÷√÷˜”≈œ»º∂Œ™ 0
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
	
	  NVIC_InitStructure.NVIC_IRQChannel = UART1_IRQn;         //IRQÕ®µ¿:¥Æø⁄1
    NVIC_InitStructure.NVIC_IRQChannelPriority = 1;          //”≈œ»º∂ :1º∂
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;          // πƒ‹IRQÕ®µ¿
    NVIC_Init(&NVIC_InitStructure);
	
	  NVIC_InitStructure.NVIC_IRQChannel = UART2_IRQn;         //IRQÕ®µ¿:¥Æø⁄1
    NVIC_InitStructure.NVIC_IRQChannelPriority = 1;          //”≈œ»º∂ :1º∂
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;          // πƒ‹IRQÕ®µ¿
    NVIC_Init(&NVIC_InitStructure);
}










