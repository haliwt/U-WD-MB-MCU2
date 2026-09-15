/*
  ******************************************************************************
  * Copyright (c) 2023 Yspring.
  * All rights reserved..
  * @file    GPIO_LED.H
  * @version V1.0.0
  * @date    2023
  * @author  Yspring Firmware Team  
  * @brief   GPIO OUTPUT Header Code.
  ******************************************************************************      
*/
#ifndef __GPIO_H
#define __GPIO_H


#include "main.h"
#include "ys32t031.h"

#include "stdint.h"



//CTL GPIO 
#define PLASMA_GPIO_Port 						GPIOA
#define LL_PLASMA_Pin 							LL_GPIO_PIN_7



#define ANALOG_TX_GPIO_Port 					GPIOA
#define LL_ANALOG_TX_Pin 						LL_GPIO_PIN_11

#define ANALOG_RX_GPIO_Port 					GPIOA
#define LL_ANALOG_RX_Pin 						LL_GPIO_PIN_12

#define KEY_MODE_GPIO_Port 						GPIOA
#define LL_KEY_MODE_Pin 						LL_GPIO_PIN_15

#define RELAY_GPIO_Port 						GPIOB
#define LL_RELAY_Pin 							LL_GPIO_PIN_0

#define LED_POWER_GPIO_Port 					GPIOB
#define LL_LED_POWER_Pin 						LL_GPIO_PIN_4

#define LED_TIM_GPIO_Port 						GPIOB
#define LL_LED_TIM_Pin 							LL_GPIO_PIN_5

#define LED_BACK_LIGHT_GPIO_Port 				GPIOB
#define LL_LED_BACK_LIGHT_Pin 					LL_GPIO_PIN_6
//TM1639 DRIVER
#define MCU_DIO_GPIO_Port 						GPIOB
#define LL_MCU_DIO_Pin 							LL_GPIO_PIN_7

#define MCU_CLK_GPIO_Port 						GPIOB
#define LL_MCU_CLK_Pin 							LL_GPIO_PIN_8

#define MCU_STB_GPIO_Port 						GPIOB
#define LL_MCU_STB_Pin 							LL_GPIO_PIN_9
/***************************************/

#define TEMP_GPIO_Port 							GPIOB
#define LL_TEMP_Pin 							LL_GPIO_PIN_13

#define MUTE_GPIO_Port 							GPIOB
#define LL_MUTE_Pin 							LL_GPIO_PIN_15



#define KEY_INC_GPIO_Port 						GPIOF
#define LL_KEY_INC_Pin 							LL_GPIO_PIN_6

#define KEY_POWER_GPIO_Port	 					GPIOF
#define LL_KEY_POWER_Pin 						LL_GPIO_PIN_7

#define KEY_DEC_GPIO_Port 						GPIOB
#define LL_KEY_DEC_Pin 							LL_GPIO_PIN_3

#define ADC_FAN_GPIO_Port 						GPIOA
#define LL_ADC_FAN_Pin 							LL_GPIO_PIN_0

#define ADC_PTC_GPIO_Port 						GPIOA
#define LL_ADC_PTC_Pin 							LL_GPIO_PIN_1

#define ULTR_PWM_GPIO_Port GPIOA
#define LL_ULTR_PWM_Pin LL_GPIO_PIN_8

#define BEEP_PWM_GPIO_Port 							GPIOB
#define LL_BEEP_PWM_Pin 							LL_GPIO_PIN_1
// FAN DRIVER GPIO
#define FAN_PWM_GPIO_Port 							GPIOA
#define LL_FAN_PWM_Pin 								LL_GPIO_PIN_6

#define FAN_RUN_GPIO_Port 						GPIOF
#define LL_FAN_RUN_Pin 							LL_GPIO_PIN_4

//

#define DSP1_TX_GPIO_Port GPIOA
#define LL_DSP1_TX_Pin LL_GPIO_PIN_9

#define DSP1_RX_GPIO_Port GPIOA
#define LL_DSP1_RX_Pin LL_GPIO_PIN_10

#define WIFI2_TX_GPIO_Port GPIOA
#define LL_WIFI2_TX_Pin LL_GPIO_PIN_2

#define WIFI2_RX_GPIO_Port GPIOA
#define LL_WIFI2_RX_Pin LL_GPIO_PIN_3




void gpio_init(void);

//void GPIO_Configuration(void);



#endif
