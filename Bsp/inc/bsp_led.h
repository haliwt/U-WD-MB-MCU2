#ifndef __BSP_LED_H
#define __BSP_LED_H
#include "main.h"



#define LED_KEY_POWER_ON()             LL_GPIO_ResetOutputPin(LED_POWER_GPIO_Port, LL_LED_POWER_Pin)
#define LED_KEY_POWER_OFF()            LL_GPIO_SetOutputPin(LED_POWER_GPIO_Port, LL_LED_POWER_Pin)  


#define LED_TIME_ON()                 LL_GPIO_SetOutputPin(LED_TIM_GPIO_Port,LL_LED_TIM_Pin)
#define LED_TIME_OFF()                LL_GPIO_ResetOutputPin(LED_TIM_GPIO_Port,LL_LED_TIM_Pin)


#define LED_BACKLIGHT_ON()           LL_GPIO_SetOutputPin(LED_BACK_LIGHT_GPIO_Port, LL_LED_BACK_LIGHT_Pin)
#define LED_BACKLIGHT_OFF()          LL_GPIO_ResetOutputPin(LED_BACK_LIGHT_GPIO_Port, LL_LED_BACK_LIGHT_Pin)

//#define LED_WIFI_ON()           LL_GPIO_ResetOutputPin(LED_WIFI_GPIO_PORT, LED_WIFI_PIN)  //{GPIO_ResetBits(LED_WIFI_GPIO_PORT, LED_WIFI_PIN);}
//#define LED_WIFI_OFF()          LL_GPIO_SetOutputPin(LED_WIFI_GPIO_PORT, LED_WIFI_PIN)      // {GPIO_SetBits(LED_WIFI_GPIO_PORT, LED_WIFI_PIN);}
//#define LED_WIFI_TOGGLE()       LL_GPIO_TogglePin(LED_WIFI_GPIO_PORT, LED_WIFI_PIN)//GPIO_T




void all_led_off(void);

void wifi_fast_led_state(void);


void wifi_led_state_handler(void);
void power_on_led_open_handler(void);






#endif 

