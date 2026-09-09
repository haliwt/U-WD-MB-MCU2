#include "gpio.h"


void gpio_init(void)
{
		LL_GPIO_InitTypeDef GPIO_InitStruct = {0};
    printf("This is LED Blinking TEST \r\n");
    
    GPIO_InitStruct.Pin 				= LL_GPIO_PIN_7;
    GPIO_InitStruct.Mode 				= LL_GPIO_MODE_OUTPUT;
    GPIO_InitStruct.Speed 			    = LL_GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStruct.OutputType 	        = LL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.Pull 				= LL_GPIO_PULL_NO;
    LL_GPIO_Init(GPIOA, &GPIO_InitStruct); 
 
 
 }

 
 
 