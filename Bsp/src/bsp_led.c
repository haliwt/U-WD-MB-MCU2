#include "bsp.h"


void all_led_off(void)
{
   


}

void power_on_led_open_handler(void)
{
	if(wifi_app_timer_power_on_f==0){

	     
		ptc_heat_open_f= 1;        // 默认开启加热
	    ultra_sound_open_f = 1;     // 默认开启超声波
	    plasma_open_f = 1;          // 默认开启等离子
	  


	  }
	  else{
		
	    


	  }

}
//300ms
void wifi_fast_led_state(void)
{
   static uint8_t slowly_led_counter = 0;//100ms
   if((gpro_t.g_power_flag ==1) && (key_net_config_f ==1) && (wifi_connected_success_f == 0)){
	   // LED_WIFI_TOGGLE();
		
   }
   else if((gpro_t.g_power_flag ==1) && (key_net_config_f ==0) && (wifi_connected_success_f == 0)){

      
		if(++slowly_led_counter > 9){//100ms *10 =1000ms =1s 

		    slowly_led_counter =0;
		    // LED_WIFI_TOGGLE();
		}
   }
   else if(gpro_t.g_power_flag ==0){
	     
	   if(++slowly_led_counter > 9){//100ms *10 =1000ms =1s
	     slowly_led_counter=0;
        //LED_POWER_TOGGLE();

      }
   }
   else if(wifi_connected_success_f==1 && gpro_t.g_power_flag ==1){
			
	      // LED_WIFI_ON();

   	}
}


void wifi_led_state_handler(void)
{
	
     if(key_net_config_f==1) return ;
	 if(wifi_connected_success_f==1)
		{
			//LED_WIFI_ON();
//			  #if DEBUG_ENABLE

//			   printf("wifi_flag = %d\n\r",wifi_connected_success_f);

//			  #endif 
		}

	}




