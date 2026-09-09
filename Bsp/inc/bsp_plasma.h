#ifndef __BSP_PLASMA_H
#define __BSP_PLASMA_H
#include "main.h"
#include "ys32t031.h"




#define PLASMA_ON()         LL_GPIO_SetOutputPin(PLASMA_GPIO_Port, LL_PLASMA_Pin)//{GPIO_ResetBits(LED_PLASMA_GPIO_PORT, LED_PLASMA_PIN);}
#define PLASMA_OFF()        LL_GPIO_ResetOutputPin(PLASMA_GPIO_Port, LL_PLASMA_Pin) //{GPIO_SetBits(LED_PLASMA_GPIO_PORT, LED_PLASMA_PIN);}



void Plasma_Ctrl(void);





#endif 


