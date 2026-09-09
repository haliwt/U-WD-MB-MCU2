#ifndef __BSP_FAN_H
#define __BSP_FAN_H
#include "main.h"
#include "ys32t031.h"




void Fan_Current_Det(void);

void Fan_Ctrl_Process(void);



void fan_full_fun(void);
void fan_stop(void);

void fan_start_power_on(void);


void wifiFan_Ctrl_Process(void);








#endif 

