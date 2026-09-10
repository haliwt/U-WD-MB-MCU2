#include "bsp.h"


/**
  * @brief  fan run is error
  * @note  
  * @param: 
  *
**/

//ADC  FAN BE Detected 
void adc_fan_channel_get_value(void)
{
    #if 0
	volatile uint16_t ad_temp;
    ad_temp = ADC_GetValue(_FCUR_CH,VREFBUF_ADC_VCC);
	
    fan_adc_value[_AD_FCUR] = ad_temp;
	#else
    uint16_t time_out ;
   ADC_Channel_Init(2);
   ADC_SoftwareStartConvCmd(ADC);

    time_out =0  ;
     while(!ADC_GetFlagStatus(ADC,ADC_FLAG_EOC)){  //等待转换完成

	    time_out ++;
		if(time_out > 10000){
            return ;

		}

    }
  
    fan_adc_value[0] = ADC_GetConversionValue(ADC);
       // printf("VSense = %d\n",ptc_adc);
       // printf_ptc_adc_numbers();
     
       // ptc_current = (ptc_adc_numbers * 33000 )/4095;
		//tx_thread_sleep(10);
        ADC_ClearFlag(ADC, ADC_FLAG_EOC);
      //  ADC_SoftwareStartConvCmd(ADC);
      //  tx_thread_sleep(5);//DelayMS(50);

	#endif 
}

//AD����һ�׻����˲�
void AD_Filter(void)
{
    //FAN_CURRENT
	fan_current=(fan_adc_value[0] *3300)/4095;
	//printf("fan_v = %d \n\r",fan_current);
}




//ADC  PTC 
void Adc_PTC_Channel_Sample(void)
{
    uint16_t time_out ;
	#if 0
	volatile uint16_t ad_ptc_temp;
	
    ad_ptc_temp = ADC_GetValue(_PTCCUR_CH,VREFBUF_ADC_VCC);
	
    ad_ptc_value[_AD_PTCCUR] = ad_ptc_temp;
   #else
     time_out =0  ;
     while(!ADC_GetFlagStatus(ADC,ADC_FLAG_EOC)){  //等待转换完成

	    time_out ++;
		if(time_out > 5000){
            return ;

		}

    }
	  
      ad_ptc_value[0] = ADC_GetConversionValue(ADC);

   #endif 
   
	
}


/**
  * @brief  fan run is error
  * @note  
  * @param: 
  *
**/



void AD_PTC_Filter(void)
{
   // uint16_t tem_ptc;
	//ptc_adc=(ad_ptc_value[_AD_PTCCUR]*2+ptc_current*18)/20;

	//ptc_current = (ptc_adc * 3300 )/4095;

	ptc_current = (ad_ptc_value[0] * 3300 )/4095;

}
/****************************************************/
void printf_ptc_adc_numbers(void)
{
  printf("ptc_adc_numbers = %d \n\r",ptc_adc_numbers);

}

void ptc_adc_detected_voltage(void)
{
   uint16_t time_out ;
   ADC_Channel_Init(3);
   ADC_SoftwareStartConvCmd(ADC);

    time_out =0  ;
     while(!ADC_GetFlagStatus(ADC,ADC_FLAG_EOC)){  //等待转换完成

	    time_out ++;
		if(time_out > 10000){
            return ;

		}

    }
  
    ad_ptc_value[0] = ADC_GetConversionValue(ADC);
       // printf("VSense = %d\n",ptc_adc);
       // printf_ptc_adc_numbers();
       ptc_adc_numbers =  ad_ptc_value[0];
       // ptc_current = (ptc_adc_numbers * 33000 )/4095;
		//tx_thread_sleep(10);
        ADC_ClearFlag(ADC, ADC_FLAG_EOC);
      //  ADC_SoftwareStartConvCmd(ADC);
      //  tx_thread_sleep(5);//DelayMS(50);

}

void ptc_switch_temperature(void)
{
   ptc_current = (ad_ptc_value[0] * 3300 )/4095;
   // ADC_ClearFlag(ADC, ADC_FLAG_EOC);
  //  ADC_SoftwareStartConvCmd(ADC);

}
/**
  * @brief  fan run is ok
  * @note  
  *
  *
**/

