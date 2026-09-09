#ifndef __BSP_PERIPHERAL_H
#define __BSP_PERIPHERAL_H
#include "main.h"



#define FAN_PWM_PIN             GPIO_Pin_6            
#define FAN_PWM_GPIO_PORT       GPIOA

#define FAN_PWM_GPIO_ON()            do{FAN_PWM_GPIO_PORT->BSRR = FAN_PWM_PIN;}while(0)//{GPIO_SetBits(FAN_RUN_GPIO_PORT, FAN_RUN_PIN);}
#define FAN_PWM_GPIO_OFF()           do{FAN_PWM_GPIO_PORT->BSRR =(uint32_t)FAN_PWM_PIN << 16;}while(0)//{GPIO_ResetBits(FAN_RUN_GPIO_PORT, FAN_RUN_PIN);}



void LED_Strip_Ctrl(void);



//void Beep(Beep_TypeDef music);








void peripheral_fun_handler(void);
void workd_interval_time_peripheral_handle(void);
void workd_interval_turn_off_handle(void);


void power_off_peripheral_handler(void);

void power_on_peripheral_handler(void);



void compare_set_temp_value(void);

void direct_compare_set_temp_value(void);





#endif 
