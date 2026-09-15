/*
  ******************************************************************************
  * Copyright (c) 2024 Yspring.
  * All rights reserved..
  * @file    user.H
  * @version V1.0.0
  * @date    2024
  * @author  Yspring Firmware Team  
  * @brief   user Header Code.
  ******************************************************************************      
*/
#ifndef __BSP_POWER_H
#define __BSP_POWER_H

#ifdef __cplusplus
extern "C" {
#endif
   
#include "ys32t031.h"
#include "system_ys32t031.h"  
#include <stdint.h> 

#define _AD_FCUR      0

#define _AD_PTCCUR    0

#define _FCUR_CH      2

#define _PTCCUR_CH    3   //WT.EDIT 2025-05-29


#define _DEVICE_WORK_TIME         120

#define _POWER_KEY_DOWN          (1<<0)     
#define _UP_KEY_DOWN             (1<<1)
#define _DOWN_KEY_DOWN           (1<<2)
#define _MODE_KEY_DOWN           (1<<3)

#define _FAN_SPEED_LEVEL_1          0
#define _FAN_SPEED_LEVEL_2          1
#define _FAN_SPEED_LEVEL_3          2

#define _DEVICE_REST_TIME            10

#define BEEP_LENGTH_DEFAULT 49		//4*100ms
#define NON_BEEP_LENGTH_DEFAULT 49	//4*100ms 

typedef enum {BEEP_ONCE,BEEP_TWO,BEEP_THREE,BEEP_1SECONDS,BEEP_TIME_OVER}Beep_TypeDef;






extern uint8_t Times10msCnt;

extern uint8_t Times1minute;
extern uint16_t Times1minCnt;
extern uint8_t Cacl_time_sec;

extern volatile uint8_t time_5ms_f;

extern uint8_t disp_second_f ;
extern bool ptc_high_temperature_f;

extern uint16_t ptc_adc_numbers;

//WIFI TIMER
extern uint8_t time_wifi_10ms_f;

extern uint16_t fan_adc_value[1];
extern uint16_t ad_ptc_value[1];

extern uint16_t fan_current;
extern uint16_t ptc_current;

extern uint16_t current_temperature;
extern uint16_t setting_temperature;
extern uint16_t disp_temperature;
extern uint16_t disp_timing_time;
extern uint16_t disp_humidity;

extern uint8_t AI_led_open_f;
extern bool ptc_heat_open_f;
extern uint8_t first_temp_compare_f;

extern bool ptc_prohibit_off_f;

extern bool ultra_sound_open_f;
extern bool plasma_open_f;

extern uint16_t timing_is_reach_disptime;
/*countdown timer  */
extern int8_t setting_timing_hour;
extern int8_t setting_timing_second;
extern int8_t timing_min_cnt;
extern uint8_t real_hours_counter;
extern int8_t temporary_timer_hours;



//

extern uint8_t Is_time_setting_f;

extern uint8_t Is_countdown_timer_f;
extern uint8_t set_temperature_value_f;
extern uint8_t time_1s_counter;
extern uint8_t read_ntc_temperature_value;






extern uint8_t key_net_config_f;
extern uint16_t key_net_config_time;


extern uint8_t flash_f;


extern uint16_t device_rest_time;





extern bool fan_open_f;
extern uint8_t fan_speed_level;





extern volatile uint8_t beep_times;				  //次数
extern volatile uint8_t beep_lenght;			  //响的长度 *100ms
extern volatile uint8_t non_beep_length;		//间隔时间
extern uint16_t beep_interval_time;

//
extern uint8_t soft_version;


extern uint8_t temperature;
extern uint8_t humidity;




extern bool fan_warning_f;
extern uint16_t fan_current_det_time;
#define _NO_FAN_LOAD_CURRENT       50      //0.06A*0.67*4096/3.3   

extern uint8_t disp_switch_temp_humi;
//peripheral 
extern uint8_t key_be_pressed_f;
extern uint8_t disp_set_hours_time_f;
extern uint8_t  key_input_temp_f;
extern uint8_t  time_10ms_f;

extern uint8_t heat_open_close_f;



//wifi ref
volatile extern  uint8_t  wifi_rx_numbers;
extern  uint8_t  link_net_step;
extern  uint8_t  wifi_cofig_success_f;

extern  uint8_t  time_link_net_counter ;
extern  uint8_t  wifi_linking_tencent_f;
extern  bool  wifi_connected_success_f;
extern  uint8_t  wifi_app_timer_power_on_f;
extern  uint8_t  wifi_run_step ;
extern  uint8_t  wifi_off_step;

extern  uint8_t  wifi_first_connectoed_cloud_f;
extern  uint8_t  wifi_read_net_data_f;
extern  uint8_t  wifi_check_net_f;
extern  uint8_t dc_connect_net_step	;
volatile extern  uint8_t  rx_wifi_data_success;
volatile extern  uint8_t   rx_wifi_data_counter;
extern  uint8_t  mqtt_status;
extern  uint8_t  time_autolink_counter;
extern  uint8_t  key_pressed_set_temp_f; //WT.EDIT 2026-05-16


/*end*/

//fan
extern uint8_t  fan_one_minute_cuonter;

//time couter 
extern uint8_t  time_set_hours_counter;

extern bool  works_interval_f;

extern uint8_t  soft_version ;


//wifi end 

//extern uint8_t com_data_temp[8];
//extern uint8_t com_data_buf[16];


typedef struct  _power_state{

    uint8_t on_step;
	uint8_t  off_step;


}power_state;

extern power_state gon_t;


void Clear_Ram(void);







void Countdown_timer_Handler(void);




void Task_Beep_Simple_10ms(void);

void works_run_two_hours_state(void);



void power_on_off_handler(void);

	
//void BEEP_ON(void);

void printf_ptc_adc_numbers(void);

void ptc_adc_detected_voltage(void);
void ptc_switch_temperature(void);

void Heat_Process(void);

void System_Status_PowerOff(void) ;
	
void System_Status_PowerOn(void) ;





#ifdef __cplusplus
}
#endif

#endif /* __USER_H */
