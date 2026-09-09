#ifndef __BSP_RELAY_H
#define __BSP_RELAY_H
#include "main.h"


#define RELAY_ON()     LL_GPIO_SetOutputPin(RELAY_GPIO_Port,LL_RELAY_Pin)
#define RELAY_OFF()    LL_GPIO_ResetOutputPin(RELAY_GPIO_Port,LL_RELAY_Pin)


void Relay_Ctrl(void);





#endif 

