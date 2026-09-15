#ifndef __BSP_FAN_H
#define __BSP_FAN_H
#include "main.h"
#include "ys32t031.h"


#define FAN_DRIVER_ON()   		do{FAN_RUN_GPIO_Port ->BSRR = LL_FAN_RUN_Pin;}while(0)
#define FAN_DRIVER_OFF()    	do{FAN_RUN_GPIO_Port ->BSRR = (uint32_t) LL_FAN_RUN_Pin<<16;}while(0)




void Fan_Current_Det(void);

void Fan_Ctrl_Process(void);




void fan_wind_speed_full(void);

void fan_stop(void);




void wifiFan_Ctrl_Process(void);








#endif 

