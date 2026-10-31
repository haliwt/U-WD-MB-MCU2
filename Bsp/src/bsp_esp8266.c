#include "bsp.h"


// wait_timeout = tx_time_get() + SECONDS_TO_TICKS(20);

 
 uint8_t link_wifi_the_first_f;
 /**
 *
 *@brief 
 *@param  
 *
 **/

static void smartphone_timer_power_on_handler(void);




/**********************************************************************
	*
	*Functin Name: void wifi_auto_detected_link_state(void)
	*Function :
	*Input Ref:  NO
	*Return Ref: NO
	*
**********************************************************************/
void wifi_auto_detected_link_state(void)
{

   if(ptc_high_temperature_f == true || fan_warning_f ==true || is_doing_connet_wifi_f == true) return ;
   

	if(is_doing_connet_wifi_f==0  && wifi_connected_success_f==0){
		  auto_connect_wifi_handler();
	
	}

    if(wifi_connected_success_f==1 && link_wifi_the_first_f==0){
              
           link_wifi_the_first_f++ ;
		
           wifi_linking_tencent_f =0;//wifi_t.linking_tencent_cloud_doing = 0;
           time_link_net_counter =0;
        
          if(gpro_t.g_power_flag== true){
		  	 MqttData_Publish_SetOpen(0);
			 tx_thread_sleep(20);//wait_timeout = tx_time_get()+30;
		     //MqttData_Publish_Update_Data();//MqttData_Publish_PowerOn_Ref();
             //tx_thread_sleep(20);//wait_timeout = tx_time_get()+20;//tx_thread_sleep(20);// delay_ms(200);//HAL_Delay(200);
             

          }
		  else if(gpro_t.g_power_flag== false){
		  	  MqttData_Publish_SetOpen(0);
			  tx_thread_sleep(20);//wait_timeout = tx_time_get()+30;
            
		  }
          
          Subscriber_Data_FromCloud_Handler();
          tx_thread_sleep(20);//wait_timeout = tx_time_get()+20;//tx_thread_sleep(20); //delay_ms(200);//HAL_Delay(200);
         

          if(disp_second_f== 1){
		  	  SendWifiData_To_Cmd(0x1F,0x01); //link wifi order 1 --link wifi net is success.
              tx_thread_sleep(2);//wait_timeout = tx_time_get()+10;//tx_thread_sleep(10);//delay_ms(100);
          }
		  time_link_net_counter =0;
   }
   else if(wifi_connected_success_f==1 && link_wifi_the_first_f==1){
		link_wifi_the_first_f++ ;

		if(gpro_t.g_power_flag== true){
		
		   MqttData_Publish_Update_Data();//MqttData_Publish_PowerOn_Ref();
		    tx_thread_sleep(20);//wait_timeout = tx_time_get()+20;//tx_thread_sleep(20);// delay_ms(200);//HAL_Delay(200);


		}
		else if(gpro_t.g_power_flag== false){
		   MqttData_Publish_PowerOff_Ref(); //
		    tx_thread_sleep(20);//wait_timeout = tx_time_get()+20;

		}

		Subscriber_Data_FromCloud_Handler();
		tx_thread_sleep(20);//wait_timeout = tx_time_get()+20;//tx_thread_sleep(20); //delay_ms(200);//HAL_Delay(200);


		if(disp_second_f== 1){
			SendWifiData_To_Cmd(0x1F,0x01); //link wifi order 1 --link wifi net is success.
			tx_thread_sleep(2);//wait_timeout = tx_time_get()+10;//tx_thread_sleep(10);//delay_ms(100);
		}
		time_link_net_counter =0;

     }
     else if(wifi_connected_success_f==1 && link_wifi_the_first_f==2 && gpro_t.beijing_time_flag==false && gpro_t.g_power_flag == true){
		
        if(gpro_t.beijing_time_flag==false){
		     get_beijing_thime_handler();
			  link_wifi_the_first_f++ ;
		}
		else{
		 
	       link_wifi_the_first_f++ ;

       }

     }
   
    if(gpro_t.get_rx_beijing_time_enable ==2){
	   parse_wifi_time();

	}
	else
       check_wifi_connect_net_state();

	if(gpro_t.gTimer_get_beijing_counter > 5 && (gpro_t.get_rx_beijing_time_enable ==1 || gpro_t.get_rx_beijing_time_enable ==2)){

	    gpro_t.get_rx_beijing_time_enable =0;

	} 
}



   

/**********************************************************************
	**
	*Function Name
	*Function: 
	*Input Ref: 
	*Return Ref:NO
	*
************************************************************************/
void auto_connect_wifi_handler(void)
{
  //static uint8_t link_wifi_f=0;
  static uint32_t wait_timeout = 0 ;

  // 安全的时间差比较（防止 Tick 溢出）
   if ((int32_t)(tx_time_get() - wait_timeout) < 0) {
        return;
   }
  
  switch(dc_connect_net_step){

	case 0:

	    
	    wifi_rx_numbers = 0;
        wifi_linking_tencent_f =1;//linking_tencent_cloud_doing = 1;
	    wifi_cofig_success_f=0;
		
	   send_usart2_data((const uint8_t *)"AT+RST\r\n", strlen("AT+RST\r\n"));
	   //HAL_Delay(1000);
	   
	   
	    wait_timeout = tx_time_get()+ 2000;//tx_thread_sleep(200);//10ms *100 =1s.
      
	    time_autolink_counter=0; 
		dc_connect_net_step =1;

	break;

	case 1:
	 if(time_autolink_counter > 10 ){
	   time_autolink_counter=0; 
		wifi_linking_tencent_f = 1;//net_t.linking_tencent_cloud_doing  = 1;
	     wifi_rx_numbers = 0; 

		 dc_connect_net_step = 3;
     }

	break;

	case 3:
  
      
      
	 // HAL_UART_Transmit(&huart2, "AT+TCMQTTCONN=1,5000,240,0,1\r\n", strlen("AT+TCMQTTCONN=1,5000,240,0,1\r\n"), 0xffff);//??
	       send_usart2_data((const uint8_t *)"AT+TCMQTTCONN=1,5000,240,0,1\r\n", strlen("AT+TCMQTTCONN=1,5000,240,0,1\r\n"));
		    
	        wait_timeout = tx_time_get()+ 2000;//tx_thread_sleep(200);//10*100ms = 
		   	dc_connect_net_step=4;
	        //wifi_off_step = 0;
	        time_autolink_counter=0;
	  
	  
     break;


	 case 4:

	     if(time_autolink_counter > 10){
		 	
		        dc_connect_net_step=5;
				wifi_off_step = 0;
				time_autolink_counter=0;
			  


	 	}


	 break;

	 case 5:
       
		   
		    if(wifi_cofig_success_f ==0){
				wifi_linking_tencent_f=0;
				time_autolink_counter=0;
			     SendWifiData_To_Cmd(0x1F,0); //link wifi order 1 --link wifi net is success.
			    tx_thread_sleep(2);//wait_timeout = tx_time_get()+10;//tx_thread_sleep(10);//delay_ms(100);
				dc_connect_net_step =6;
				
		    }
			else{
				dc_connect_net_step =8;//wifi connect net is success .
				wifi_linking_tencent_f =0;
                SendWifiData_To_Cmd(0x1F,0x01); //link wifi order 1 --link wifi net is success.
			    tx_thread_sleep(2);//wait_timeout = tx_time_get()+10;//tx_thread_sleep(10);//delay_ms(100);

			}
        
   
	break;

	case 6:

	   if(time_autolink_counter > 30){

	       time_autolink_counter=0;
	       dc_connect_net_step =0;


	   }
		


	break;


	default:

	break;

	}
}

/**********************************************************************
	**
	*Function Name : void wifi_power_on_handler(void)
	*Function: 
	*Input Ref: 
	*Return Ref:NO
	*
************************************************************************/
 uint8_t sub_counter,counter_1;
void wifi_power_on_handler(void)
{
    static uint8_t sw_flag=0;
	//static uint8_t counter_1=0,
	static uint8_t counter=0,send_times=0;
	static uint32_t wait_timeout = 0; // 新增：用于非阻塞等待的时间戳
    
    
    // 如果当前正处于“等待响应”的时间段内，直接跳出，让 UI 任务跑别的 Slot
    if ((int32_t)(tx_time_get() - wait_timeout) < 0) {
       return;
     }

	if(is_doing_connet_wifi_f == 1 || gpro_t.g_power_flag == 0 || wifi_connected_success_f==0) return ;
		
     switch(wifi_run_step){

	 case 0:
        send_times =0;
	   if(wifi_app_timer_power_on_f ==1){

	        smartphone_timer_power_on_handler();
	        wifi_run_step =1;


	   }
	   else if(wifi_connected_success_f ==1 && wifi_app_timer_power_on_f ==0){
    
		   if(gpro_t.g_power_flag){
		         MqttData_Publish_SetOpen(1);  
				 wait_timeout=tx_time_get()+20;// tx_thread_sleep(20);
				
				 wifi_run_step =1;
		  }
		
	  }
	  else{
        wifi_run_step =1;
	  }
	 break;

	 case 1:
	 	if(wifi_app_timer_power_on_f ==1){

	       //setting_temperature=40;
           
          // MqttData_Publis_SetTemp(setting_temperature);
	       wifi_run_step =2;


	   }
	   else if(wifi_connected_success_f ==1 && wifi_app_timer_power_on_f ==0){
		    MqttData_Publish_Update_Data();  
		    wait_timeout=tx_time_get()+20;//tx_thread_sleep(20);//delay_ms(100);
	        wifi_run_step =2;
		}
		
       send_times=0;
	   wifi_run_step =2;
			
		
	 break;
	 
	 case 2:

	    get_beijing_thime_handler();
		if(wifi_app_timer_power_on_f ==1 && gpro_t.g_power_flag == 1){
		     	//smartphone_timer_power_on_handler();
				// wait_timeout=tx_time_get()+20;//tx_thread_sleep(20);//Publish_Data_fan_Warning(2);//fan warning 
			
			 	 wifi_run_step = 3;
		 }
		 else{
		    wifi_run_step = 3;
		 }

		
	 break;

	 case 3:
	 	if(wifi_app_timer_power_on_f == 1 && gpro_t.g_power_flag ==1 ){

           	fan_speed_level = 100;//gctl_t.set_wind_speed_value=100;
            MqttData_Publis_SetFan(fan_speed_level);//WT.EDIT 2025.12.19
            wait_timeout=tx_time_get()+20;//tx_thread_sleep(20);//delay_ms(100);
			wifi_run_step = 4;

	 		}
		    else{
			wifi_run_step = 4;

			}

	 break;

	 case 4:
	 	
		 if(wifi_app_timer_power_on_f == 1 && gpro_t.g_power_flag ==1 ){   
            setting_temperature=40;
           
            MqttData_Publis_SetTemp(setting_temperature);
			wait_timeout=tx_time_get()+20;//tx_thread_sleep(20);//delay_ms(100);
			    
		    wifi_app_timer_power_on_f++;
		
           #if 0
              printf("wifi_app_f = %d \r\n",wifi_app_timer_power_on_f);
		   #endif 
			
	      }
		
		   wifi_run_step = 5;
		  

	    break;


     case 5:
		
         if(wifi_connected_success_f ==1 &&  wifi_app_timer_power_on_f ==0 && wifi_first_connectoed_cloud_f==0){
          
	      if(gpro_t.g_power_flag){
		        fan_warning_f = 0;
			 	Publish_Data_fan_Warning(0); //fan warning .
			    //wait_timeout=tx_time_get()+20;//tx_thread_sleep(20);//delay_ms(100);
			 }
			 wifi_first_connectoed_cloud_f++;
			  
         }
		
		 get_beijing_thime_handler();
		 wifi_run_step = 6;
	break;


	case 6: 

	  
	case 7:
	  	
	      counter++;
		  
	  	  if(wifi_connected_success_f ==1 &&  send_times < 3){
		  	    
			    send_times ++;
				Update_Dht11_Totencent_Value();
              //   wait_timeout=tx_time_get()+10;//tx_thread_sleep(20);// delay_ms(200);
              if(disp_second_f== 1){
			  SendWifiData_To_Cmd(0x1F,0x01); //link wifi order 1 --link wifi net is success.
			   tx_thread_sleep(2);//wait_timeout = tx_time_get()+10;//tx_thread_sleep(10);//delay_ms(100);
		   	}
          }
		  else if(wifi_connected_success_f ==1 && counter > 5){
				counter = 0;

                if(disp_second_f== 1){
			    SendWifiData_To_Cmd(0x1F,0x01); //link wifi order 1 --link wifi net is success.
			     tx_thread_sleep(2);//wait_timeout = tx_time_get()+10;//tx_thread_sleep(10);//delay_ms(100);
		   	 }

		  }
		  else if(wifi_connected_success_f ==0 && counter > 5) {
               counter = 0;
		      if(disp_second_f== 1){
					 SendWifiData_To_Cmd(0x1F,0); //link wifi order 1 --link wifi net is success.
					  tx_thread_sleep(2);//wait_timeout = tx_time_get()+10;//tx_thread_sleep(10);//delay_ms(100);
			}


		  }

	    wifi_run_step =6;

	 break;


     	}

}

/**
*@breif : power off connector to tencent cloud .
*@note:
*@param:
*@return:
*
*/
void wifi_power_off_handler(void)
{
   
  static uint8_t wait_timeout  = 0;

  if(tx_time_get() < wait_timeout){

  	  return ;

  }
	  static uint8_t  counter=0,sw_flag=0;
	
	   switch(wifi_off_step){
	
		case 0:
		  if(wifi_connected_success_f ==1 ){
	   
		
			MqttData_Publish_SetOpen(0);  
			wait_timeout = tx_time_get()+ 20;//20 *10ms =200ms //tx_thread_sleep(200);
			   wifi_off_step = 1;
           }
		   
	    break;
	
		case 1:
			if(wifi_connected_success_f ==1){
			  
				 MqttData_Publish_PowerOff_Ref(); 
				 wait_timeout = tx_time_get()+ 20;   //tx_thread_sleep(200);///delay_ms(100);
				   
				   wifi_off_step = 2;
				   gpro_t.time_7s_f=0;
	
			   }
			 
		break;
	
	
		case 2: 
	
		
	
		   if(wifi_connected_success_f ==1 && gpro_t.time_7s_f > 1){
		 
		       gpro_t.time_7s_f=0;
			  Subscriber_Data_FromCloud_Handler();
			  wait_timeout = tx_time_get()+ 20; //tx_thread_sleep(200);//delay_ms(100);
		       gpro_t.time_7s_f=0;
			   wifi_off_step = 3;
		   }
	   
		 
		break; 
	
		case 3:
		
			if(wifi_connected_success_f ==1 && gpro_t.time_7s_f > 1){
			 
			    gpro_t.time_7s_f=0;
				fan_warning_f = 0;
				 Publish_Data_fan_Warning(0); //fan warning .
			    wait_timeout = tx_time_get()+ 20;//tx_thread_sleep(200);
				gpro_t.time_7s_f=0;
				wifi_off_step = 4;
	        }
		

		 case 4:
				
			
			if(wifi_connected_success_f ==1	&& soft_version == 0){ //WT.EDIT 2026.02.27
	
			   sw_flag = sw_flag ^ 0x01;
			   if(sw_flag == 1){
				   if(disp_second_f == 1){
				   	SendWifiData_olderCmd(0x1F,0x01);//SendWifiData_To_Cmd(0x1F,0x01); //link wifi order 1 --link wifi net is success.
				       tx_thread_sleep(2);//wait_timeout = tx_time_get()+ 10;//delay_ms(100);
				   	}
			   }
			   else{
				   if(disp_second_f == 1){
				   	SendWifiData_To_Data(0x1F,0x01);
				      tx_thread_sleep(2);//wait_timeout = tx_time_get()+ 10;//delay_ms(100);
				   	}
			   }
	
		   }
		   else if(wifi_connected_success_f ==0 && counter > 1 && soft_version ==0){ //WT.EDIT 2026.02.27
			  
			   sw_flag = sw_flag ^ 0x01;
			   if(sw_flag == 1){
				   if(disp_second_f == 1){
				   	SendWifiData_olderCmd(0x1F,0x0);//SendWifiData_To_Cmd(0x1F,0x01); //link wifi order 1 --link wifi net is success.
				      tx_thread_sleep(2);//wait_timeout = tx_time_get()+ 10;//delay_ms(100);
				   }
			   }
			   else{
				   if(disp_second_f == 1){
				   	SendWifiData_To_Data(0x1F,0x0);
				      tx_thread_sleep(2);//wait_timeout = tx_time_get()+ 10;//delay_ms(100);
				   	}
			   }
		   }
	    gpro_t.time_7s_f=0;
		wifi_off_step = 5;
	
		break;
	
	     case 5:
			
			 if(wifi_connected_success_f ==1 &&   gpro_t.time_7s_f> 1){
				   gpro_t.time_7s_f=0;
			   
				   Update_Dht11_Totencent_Value();
				     tx_thread_sleep(20);//wait_timeout = tx_time_get()+ 20;//tx_thread_sleep(200); // delay_ms(200);

				   gpro_t.time_7s_f=0;
				    wifi_off_step =6 ;
		   }
	
		 
	
		break;


		case 6:

		   wifi_off_step =2 ;

		break;


	

		default:

		break;
	
	
		   }


}

/**
*@breif :
*@note:
*@param:
*@return:
*
*/
void Update_Dht11_Totencent_Value(void)
{

    MqttData_Publis_ReadTempHum(temperature,humidity);
  
}



/************************************************************************************
*
*Function Name:
*
*
*
************************************************************************************/
static void smartphone_timer_power_on_handler(void)
{

	//Parse_Json_Statement();
#if 0
	static uint32_t wait_timeout = 0; // 新增：用于非阻塞等待的时间戳
    
    // 如果当前正处于“等待响应”的时间段内，直接跳出，让 UI 任务跑别的 Slot
    if (tx_time_get() < wait_timeout) {
        return; 
    }
   #endif 
   
	if(plasma_open_f==1){ //Anion


	if(disp_second_f == 1){
		SendWifiData_To_Cmd(0x03,0x01);
	    tx_thread_sleep(2);//wait_timeout = tx_time_get() + 10; //tx_thread_sleep(10);//delay_ms(100);
		}

	}
	else{
	plasma_open_f =0;
	if(disp_second_f == 1){
		SendWifiData_To_Cmd(0x03,0x0);
	    tx_thread_sleep(2);//wait_timeout = tx_time_get() + 10;//tx_thread_sleep(10);//delay_ms(100);
		}
	}


	if(ultra_sound_open_f== true){

	if(disp_second_f == 1){
		SendWifiData_To_Cmd(0x04,0x01);
	    tx_thread_sleep(2);//wait_timeout = tx_time_get() + 10;//tx_thread_sleep(10);//delay_ms(100);
		}
	}
	else if(ultra_sound_open_f== false){
	ultra_sound_open_f=0;
	if(disp_second_f == 1){
		SendWifiData_To_Cmd(0x04,0x0);
	    tx_thread_sleep(2);//wait_timeout = tx_time_get() + 10; //tx_thread_sleep(10);//delay_ms(100);
		}
	}



	if(ptc_heat_open_f== true){
	   ptc_prohibit_off_f =false;

	if(disp_second_f == 1){
		SendWifiData_To_Cmd(0x02,0x01);
	    tx_thread_sleep(2);//wait_timeout = tx_time_get() + 10;//tx_thread_sleep(10);//delay_ms(100);
		}
	}
	else if(ptc_heat_open_f == false){
		ptc_prohibit_off_f =1;
		RELAY_OFF();
		if(disp_second_f == 1){
			SendWifiData_To_Cmd(0x02,0x0);

		    tx_thread_sleep(2);//wait_timeout = tx_time_get() + 10;
		}

	}

	MqttData_Publish_Update_Data();

}
			







