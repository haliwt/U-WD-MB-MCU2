#ifndef __BSP_ADC_H
#define __BSP_ADC_H
#include "main.h"
#include "ys32t031.h"

void adc_fan_channel_get_value(void);

void Adc_PTC_Channel_Sample(void);

void AD_Filter(void);

void AD_PTC_Filter(void);






#endif 

