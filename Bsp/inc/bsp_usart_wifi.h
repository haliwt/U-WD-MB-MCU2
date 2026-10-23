#ifndef __BSP_USART_WIFI_H
#define __BSP_USART_WIFI_H
#include "main.h"

// 定义时间结构体
typedef struct {
    
    
    uint8_t month;
	uint8_t hour;
	uint16_t year;
    uint16_t day;
    uint16_t minute;
    uint16_t second;
} DateTime_t;

extern DateTime_t time_t;

void usart2_rx_callback_invoke(uint8_t data);

void Subscribe_Rx_Interrupt_Handler(void);

void Wifi_Rx_InputInfo_Handler(void);

void send_usart2_data(const uint8_t* pdata,uint8_t lenght);

void wifi_parse_tencennt_hadler(void);

//void Parse_Json_Statement(void);
void automatic_network_reconnection(void);


void Parse_Tencent_Data(void) ;


void check_wifi_connect_net_state(void);

int8_t parse_wifi_time(void);

#endif 


