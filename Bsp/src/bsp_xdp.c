#include "bsp.h"


// 为协议中的魔术字节定义常量，提高可读性
#define FRAME_HEADER        0xA5        //receive display board header  
#define FRAME_NUM           0x02          //main deviece number is 0x10 
#define FRAME_OLD_NUM       0x01          //older version device NUM
#define FRAME_ACK_NUM       0x80          //new version from main answer singnal 0x80 new version . 
#define FRAME_END_BYTE              0xFE
#define DATA_FRAME_TYPE_INDICATOR   0x0F
#define FRAME_COPY_NUM              0xFF   //this is older version .

#define ACK_SUCCESS 0x00U
#define ACK_FAILURE 0x01U




volatile uint8_t uart1_rx_buf[UART1_RX_BUF_SIZE];
volatile uint16_t uart1_rx_head ;
volatile uint16_t uart1_rx_tail ;

bool fan_rx_stop_flag;



typedef void (*Usart1RxCallback)(uint8_t data);

static Usart1RxCallback usart1_rx_cb = NULL;  //定义一个全局静态函数指针

//static void usart1_invoke_callback(uint8_t data);


//static void usart1_isr_callback_handler(uint8_t data);
static void parse_recieve_copy_data(uint8_t *pddata);


uint8_t rx_inputBuf[12];
uint8_t check_bcc_code;
uint8_t rx1_data;

uint8_t ptc_onoff_default ;


//提供注册接口
void usart1_register_rx_callback(Usart1RxCallback cb)
{
   usart1_rx_cb = cb;

}

void usart1_invoke_callback(uint8_t data)
{
   if(usart1_rx_cb !=NULL){

       usart1_rx_cb(data);
   }


}


void callback_register_usart1_rx(void)
{

   usart1_register_rx_callback(usart1_isr_callback_handler);

}




volatile uint8_t rx_state;



typedef enum{

  open =1,
  close =2,
  no_change =0  

}atcion_state_e;



typedef enum {
    UART_STATE_WAIT_HEADER = 0,
    UART_STATE_NUM=1,
    UART_STATE_CMD_NOTICE=2,
    UART_STATE_EXEC_CMD_OR_LEN=3,
    UART_STATE_FRAME_END=4,
    UART_STATE_BCC_CHECK,
    UART_STATE_OLDER_BCC_CHECK,
    UART_STATE_DATA_LEN,
    UART_STATE_DATA,
    UART_STATE_DATA_END,
    UART_STATE_DATA_BCC
} uart_parse_state_t;

typedef enum{

    power_on_off=1,
    ptc_on_off=2,
    plasma_on_off=3,
    ultrasonic_on_off=4,
    wifi_link=5,
    buzzer_sound_s=6,
    ai_mode=7,
    temp_high_warning=8,
    fan_warning_s=9,
    fan_on_off = 0x0B,

     //notice no sound 
    ack_power_on_off = 0x10,
    ack_ptc_on_off = 0x12,
    ack_plasma_on_ff= 0x13,
    ack_ultrasonic_on_off = 0x14,
}signal_parase_t;


typedef struct Msg
{
    
	uint8_t   cmd_notice;
	uint8_t   execuite_cmd_notice;
	uint8_t   copy_cmd_flag;
	uint8_t   rx_data_flag;	
    uint8_t   bcc_check_code;
	uint8_t   check_code_hex;
    uint8_t   receive_data_length;
    uint8_t   data_length;
	uint8_t   rc_data_length;
	uint8_t   total_data_length;
    uint8_t   rx_end_code;
	uint8_t   rx_total_numbers;
	uint8_t   rx_data[4];
	uint8_t   usData[12];
	uint8_t   desData[12];

}MSG_T;

MSG_T   gl_tMsg; 

uint8_t inputBuf[1];



static void usart1_protocol_state_machine(uint8_t *pdata);

volatile uint8_t rx_usart1_data_counter=0;

uint8_t parse_exit_flag,parse_decoder_flag;
/********************************************************************************
	**
	*Function Name:void usart1_isr_callback_handler(void)
	*Function :  this is receive data from mainboard.
	*Input Ref:NO
	*Return Ref:NO
	*
*******************************************************************************/
void usart1_isr_callback_handler(uint8_t data)
{
   
	switch(rx_state){

	 case 0:
		if(data == FRAME_HEADER){
			rx_usart1_data_counter=0;
			gl_tMsg.usData[rx_usart1_data_counter]=data;
			
			rx_state =1;

		}
		else{
		   rx_state =0;

		}
	 break;

	 case 1:
			rx_usart1_data_counter++;
			gl_tMsg.usData[rx_usart1_data_counter]=data;

	        if(gl_tMsg.usData[rx_usart1_data_counter]==0x01 || gl_tMsg.usData[rx_usart1_data_counter]==0x02){
			 
				 rx_state = 2;
			 }
			 else{
				rx_state = 0;
				
             }

	 break;

	 case 2:
	 
		   rx_usart1_data_counter++;
           gl_tMsg.usData[rx_usart1_data_counter]=data;
		   
		  if(gl_tMsg.usData[rx_usart1_data_counter]==0xFE && rx_usart1_data_counter> 4){
		      rx_state = 3;
		  }
		 
     break;
			 
	 case 3:
		       rx_usart1_data_counter++;
	           gl_tMsg.usData[rx_usart1_data_counter]=data;
			 
	           rx_state = 0;
               gl_tMsg.rx_total_numbers = rx_usart1_data_counter;

			   gl_tMsg.rx_end_code = 0;
			   
		       //gpro_t.decoder_success_flag=1;

			   gl_tMsg.bcc_check_code = data;

               wifi_semaphore_xtask();//display_board_xtask_notice();

	 break;

	 default:
	   rx_state =0;

	 break;

	 }

}

/********************************************************************************
	**
	*Function Name:void usart1_protocol_state_machine(void)
	*Function :  in process bsp_freertos.c xTaskMsgPro
	*Input Ref:NO
	*Return Ref:NO
	*
*******************************************************************************/
static void usart1_protocol_state_machine(uint8_t *pdata)
{

   static uint8_t ptc_set_wifi = 0xff;
   switch(pdata[2]){

   case 0:

   break;

   case power_on_off: 

         
        if(pdata[3] == 0x01){ //open
                
		        gon_t.on_step=0;
				
		        BEEP_ON();//buzzer_sound_fun();
		        gpro_t.external_display_flag = true;
	            SendWifiData_Answer_Cmd(0x01,0x01);
	            tx_thread_sleep(2);//10ms *2 
				 gpro_t.g_power_flag  = true;//gpro_t.gpower_on = power_on;
				  fan_wind_speed_full();//fan_full_run();//WT.EDIT 2026.01.26
				   PLASMA_ON();//PLASMA_ON();;
                   ultra_sound_on(20);//(159); //ultra_sound_on(uint16_t us_duty);   //ultra_sound_on(40);   //ultrasnoic ON 
                   RELAY_ON();//RELAY_ON();


	    }
        else if(pdata[3] == 0x0){ //close 


			 BEEP_ON();
		     gon_t.off_step=0;
             gpro_t.g_power_flag  = false ;//gpro_t.gpower_on = power_off;
             gpro_t.external_display_flag = true;
			 RELAY_OFF();
			 PLASMA_OFF();
			 ultra_sound_off();
             
              SendWifiData_Answer_Cmd(0x01,0x0); //power off .
              tx_thread_sleep(2); 
			  SendWifiData_Answer_Cmd(0x01,0x02); //compatible older version 
	           tx_thread_sleep(2);
           
		}
      
       

     break;

	 case 0x10 : //power on or power off don't buzzer sound .

	 	if(pdata[3]== 0x01){

		   if(gpro_t.g_power_flag == true){


		   }
		   else{
				
				gon_t.on_step=0;
				gpro_t.external_display_flag = true;
				SendWifiData_Answer_Cmd(0x01,0x01);
				tx_thread_sleep(2);//10ms *2 
				gpro_t.g_power_flag  = true;//gpro_t.gpower_on = power_on;
				fan_wind_speed_full();//fan_full_run();//WT.EDIT 2026.01.26
				PLASMA_ON();//PLASMA_ON();;
				ultra_sound_on(20);//(159); //ultra_sound_on(uint16_t us_duty);   //ultra_sound_on(40);   //ultrasnoic ON 
				RELAY_ON();//RELAY_ON();
           }

        }
		else{
             if(gpro_t.g_power_flag == false){


             }
			 else{
				 gon_t.off_step=0;
	             gpro_t.g_power_flag  = false ;//gpro_t.gpower_on = power_off;
	             gpro_t.external_display_flag = true;
				 RELAY_OFF();
				 PLASMA_OFF();
				 ultra_sound_off();
	             
	              SendWifiData_Answer_Cmd(0x01,0x0); //power off .
	              tx_thread_sleep(2); 
				  SendWifiData_Answer_Cmd(0x01,0x02); //compatible older version 
		           tx_thread_sleep(2);
            }
	
         }
       break;

	 

	  case ptc_on_off: //PTC key of command .

       if(pdata[3] == 0x01 ){//phone_cmd_power

			BEEP_ON();
			ptc_heat_open_f= true;
			ptc_prohibit_off_f =0; // 

			if(works_interval_f==0){//two hours have a rest ten minutes .
					if(fan_warning_f  ==0 && ptc_high_temperature_f ==0){ //PTC warning flag

					RELAY_ON();
				}

				SendWifiData_Answer_Cmd(0x02,0x01); //
				tx_thread_sleep(2); 

			}
	   }
       else if(pdata[3]== 0x0){
	   
			BEEP_ON();
		    ptc_heat_open_f= false;
			ptc_prohibit_off_f = 1;//disable  ptc head .
			RELAY_OFF();
            SendWifiData_Answer_Cmd(0x02,0x0); //
			tx_thread_sleep(2); 

       }
      break;

	  
     case plasma_on_off: //PLASMA ACTIVE OPEN OR CLOSE
   
		  if(pdata[3]== 0x01){
			 
			BEEP_ON();
			
			 plasma_open_f = true;
			 if(works_interval_f==0){
				 PLASMA_ON(); ;
   
			}
            SendWifiData_Answer_Cmd(0x03,0x01); //
			tx_thread_sleep(2); 
			 
		  }
		  else if(pdata[3]  == 0x0){
			 BEEP_ON();
			
			 
			 plasma_open_f = false;
			  PLASMA_OFF();

			SendWifiData_Answer_Cmd(0x03,0x0); //
			tx_thread_sleep(10); 
			  
		  
		  }
   
   
	break;

	   
   	case 0x04: //ultrasonic	ACTIVE OPEN OR CLOSE
          
		  if(pdata[3]  == 0x01){  //open 
			 BEEP_ON();
			ultra_sound_open_f =1;
   
			if(works_interval_f==0){
				 ultra_sound_on(20);//(159);
   
			}
			
			SendWifiData_Answer_Cmd(0x04,0x01); //
			tx_thread_sleep(2); 
   
		  }
		  else if(pdata[3] == 0x0){ //close 
              BEEP_ON();
			ultra_sound_open_f = 0;
   
			ultra_sound_off();
			
			SendWifiData_Answer_Cmd(0x04,0x0); //
			tx_thread_sleep(2); 
   
		  }
   
   
    break;

	
     case  wifi_link: // link wifi command

       if(pdata[3] == 0x01){  // link wifi 
        
          BEEP_ON();
          link_net_step =0;
	      wifi_connected_success_f=0;
          key_net_config_f =1;
		  key_net_config_time =0;
         
		  SendWifiData_Answer_Cmd(0x05,0x01); //WT.EDIT 2024.12.28
          tx_thread_sleep(2);
         
      
        }


     break;

	  case buzzer_sound_s: //buzzer sound command 
          if(pdata[3] == 0x01)BEEP_ON();
		 
     break;



      case 0x11:
		    gpro_t.external_display_flag  = pdata[3];
	  break; 

	  
	  case 0x16 : //buzzer sound command with answer .

  
		BEEP_ON();
        
        SendWifiData_Answer_Cmd(0x16,0x01); //WT.EDIT 2025.07.28
	    tx_thread_sleep(2);
      break;
	  
      case 0x27: //AI command without buzzer sound
	  case 0x17: //AI notice
	  case 0x07:
	  
	  if(pdata[3] == 0x02 || pdata[3]==0){
	 
		
            AI_led_open_f =0;
           if(wifi_connected_success_f ==1){
	          MqttData_Publish_AitState(2);
			   tx_thread_sleep(20);//tx_thread_sleep(200);//HAL_Delay(350);
	       }
        
          
       }
       else if(pdata[3] == 0x01){ //AI mode 
       
	      AI_led_open_f=1;

         if(wifi_connected_success_f ==1){
	         MqttData_Publish_AitState(1);
			 tx_thread_sleep(20);//tx_thread_sleep(200);//HAL_Delay(350);
	      }
		 
       }


	 break;

	 case 0x18: 
       
	 break;

	  case 0x19: //works 2 hours ,then have a rest 10 minutes ->notice 

	    if(pdata[3]==1){ // recach 2 hours 

            works_interval_f=1;//works 2 hours .
	         RELAY_OFF(); //ptc off;
			 PLASMA_OFF() ; //plasma turn off.
             ultra_sound_off();
			
		}
		else if(pdata[3]==0){
			  works_interval_f=0;//WT.EDIT 2026.01.26
			  fan_rx_stop_flag =0 ;
		      if( ptc_prohibit_off_f==false && ultra_sound_open_f == true){
			  	RELAY_ON();
				
              }
			  if(plasma_open_f== true)PLASMA_ON();
			  if(ultra_sound_open_f==true) ultra_sound_on(20);
			  if(wifi_connected_success_f == true){
			    	wifiFan_Ctrl_Process();
			  }
			  else{
				fan_wind_speed_full();
         
			  }
		
			  
		}
	   

	  break;

	  case 0x1A: //read dht11 temperatuare and humidity value 

	  break;

  
	  case 0x1B: //
	  
      break;
     
 
	  
    case 0x1C: // is time data: hours,minutes,sencodes.
		   
	break;


	case 0x22: //PTC ON OR OFF by compare temperature value .don't buzzer sound.

	    if(ptc_prohibit_off_f  == 1)return ;
		
        if(pdata[3]== 0x01){ //ptc open 
		   
		   if(works_interval_f ==0 && ptc_prohibit_off_f==false){
			     ptc_heat_open_f = true;
			     ptc_onoff_default++;
                 RELAY_ON();

			     SendWifiData_Answer_Cmd(0x22,0x01); //WT.EDIT 2025.07.28
			     tx_thread_sleep(2);
				 gpro_t.app_open_ptc_flag = true;
//					 if(wifi_connected_success_f==1){ 
//						  MqttData_Publish_SetPtc(0x01);
//						tx_thread_sleep(20);
						
//					  }
				 
		   	}   	
	   }
       else if(pdata[3]== 0x0){
	   
		   ptc_prohibit_off_f =0 ;//gctl_t.gDry =0;
            ptc_onoff_default++;
	    
	          RELAY_OFF();
			   gpro_t.app_open_ptc_flag = false;
           
		      SendWifiData_Answer_Cmd(0x22,0x0); //WT.EDIT 2025.07.28
			  tx_thread_sleep(2);

  //		  if(wifi_connected_success_f==1){ 
//			MqttData_Publish_SetPtc(0x0);
//			tx_thread_sleep(20);
//		  }
		  
         
	  }
	
   
     break;

	 case 0x23: // key adjust temperature open ptc and off. don't buzzer sound .

	     if(pdata[3]==1){

	        ptc_heat_open_f = true;
			ptc_prohibit_off_f = false;
		    RELAY_ON();

	     }
		 else if(pdata[3]==0){

           ptc_heat_open_f = false ;
		   ptc_prohibit_off_f = false;
		   RELAY_OFF();

		 }


	 break;


	 
	 case 0x2A: // is data //phone or display  board set temperature .receive.
	 
		   if(pdata[4]==0x01 && gpro_t.g_power_flag == true){//pdata[4] :表示数据的长度。
			  
			   if(pdata[5] >19 && pdata[5] < 41){
			   	ptc_prohibit_off_f  = 0;
			    setting_temperature = pdata[5] ;
			  
			   if(setting_temperature > temperature && works_interval_f ==false){
			
			         ptc_onoff_default++;
                      ptc_heat_open_f = true;
				      RELAY_ON();
					  gpro_t.app_open_ptc_flag = true;
			   }
			   else{
			   	   ptc_onoff_default++;
				   ptc_heat_open_f = false;
				   ptc_prohibit_off_f =0 ;//gctl_t.gDry =0;
				   gpro_t.app_open_ptc_flag = false;

			       RELAY_OFF();
		       }

		
//				   if(wifi_connected_success_f==1){
//					   MqttData_Publis_SetTemp(setting_temperature);
//					   tx_thread_sleep(20);//tx_thread_sleep(200);//HAL_Delay(350);
//					}
			   	
			  }
		   
			}
		
		
	 break;

	 case 0x2B: //display or phone set timer time value 
	      if(pdata[4]==0x01 && gpro_t.g_power_flag == true){//pdata[4] :表示数据的长度。

               


	      }

	 break;

	 

	 case 0x6C: //Synchronize local time ->two display board 

	   if(pdata[4]==0x03){ 

		     if(pdata[5] < 24 && pdata[6] < 61 && pdata[7] < 61){
         
		     
			
		     }
		 }

	 break;

	 case 0xF0: //software version difference older and new sotfware 
      
            soft_version = pdata[3];
	 
		   #if DEBUG_ENABLE


               printf("soft_version = %d \r\n",soft_version);
		   

		   #endif 

    break;


	case 0xFF: //copy comand or notice or data.

	       parse_recieve_copy_data(pdata) ;

	break;

	}

}
/**********************************************************************
	*
	*Function Name:static void parse_recieve_copy_data_handler(void)
	*Function: display board send to mainboard answer signal
	*Input Ref:NO
	*Return Ref:NO
	*
**********************************************************************/
static void parse_recieve_copy_data(uint8_t *pddata)
{

    switch(pddata[3]){
    
       case 0:
    
    
       break;

	   case 0x01:

	     if(pddata[4] == 0x01){ //open

		    //gon_t.on_step=0;
	        //gpro_t.g_power_flag = true;
	        gpro_t.g_answer_power_flag = true; //表示显示板，接收到开机信息。

		 }
        else if(pddata[4] == 0x0){ //close 

		   //gon_t.off_step=0;
          //gpro_t.g_power_flag = false;
            gpro_t.g_answer_power_flag = false; //表示显示板，接收到关键信息
			 
		}
	   

	   break;

	   
    }
      
 }



/**
  * @brief This function handles USART1 global interrupt 
  * @param
  * @retrval 
**/
void decoder_handler(void)
{
   // gpro_t.decoder_success_flag=0;
	check_bcc_code = bcc_check(gl_tMsg.usData,gl_tMsg.rx_total_numbers);
	if(check_bcc_code == gl_tMsg.bcc_check_code){
		usart1_protocol_state_machine(gl_tMsg.usData);
    }
}







