/*
  ******************************************************************************
  * Copyright (c) 2024 Yspring.
  * All rights reserved..
  * @file    uart.C
  * @author  Yspring Firmware Team  
  * @brief   uart Source Code.
  ******************************************************************************      
*/

#include "uart.h"   
#include "ys32t031.h"


volatile uint8_t UART1_RX_BUF[60];
volatile uint8_t uart1_rx_cnt;

volatile uint8_t UART2_RX_BUF[60];
volatile uint8_t uart2_rx_cnt;



void UART1_Configuration(uint32_t BaudRate1);
void UART2_Configuration(uint32_t BaudRate2);
void UART1_SendByte(uint8_t Data);
void UART1_Send_Str(uint8_t *String,uint8_t s1);
void UART2_SendByte(uint8_t Data);
void UART2_Send_Str(uint8_t *String,uint8_t s2);



// UART1 初始化配置
// Be used to display board conntector .
void UART1_Configuration(uint32_t BaudRate1)
{
    UART_InitTypeDef UART_InitStructure;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_UART1, ENABLE);
    UART_DeInit(UART1);
    UART_StructInit(&UART_InitStructure);

    UART_InitStructure.UART_BaudRate = BaudRate1;             //波特率设置
    UART_InitStructure.UART_WordLength = UART_WordLength_8b;  //8位数据格式   
    UART_InitStructure.UART_StopBits = UART_StopBits_1;       //1个停止位
    UART_InitStructure.UART_Parity = UART_Parity_No;          //无基偶校验位
    UART_InitStructure.UART_HardwareFlowControl = UART_HardwareFlowControl_None;   //无硬件数据流控制
    UART_InitStructure.UART_Mode = UART_Mode_Rx | UART_Mode_Tx;   //收发模式
    UART_Init(UART1, &UART_InitStructure);

	  UART_ITConfig(UART1, UART_IT_RXNE, ENABLE);                   //使能UART1接收中断
	
    UART_Cmd(UART1, ENABLE);
}



// UART2 初始化配置
void UART2_Configuration(uint32_t BaudRate2)
{
    UART_InitTypeDef UART_InitStructure;

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_UART2, ENABLE);
    UART_DeInit(UART2);
    UART_StructInit(&UART_InitStructure);

    UART_InitStructure.UART_BaudRate = BaudRate2;                //波特率设置
    UART_InitStructure.UART_WordLength = UART_WordLength_8b;     //8位数据格式   
    UART_InitStructure.UART_StopBits = UART_StopBits_1;          //1个停止位
    UART_InitStructure.UART_Parity = UART_Parity_No;             //无基偶校验位
    UART_InitStructure.UART_HardwareFlowControl = UART_HardwareFlowControl_None;    //无硬件数据流控制
    UART_InitStructure.UART_Mode = UART_Mode_Rx | UART_Mode_Tx;  //收发模式
    UART_Init(UART2, &UART_InitStructure);
	
	UART_ITConfig(UART2, UART_IT_RXNE, ENABLE);                   //使能UART2接收中断

    UART_Cmd(UART2, ENABLE);
}



/**
 * @brief  UART1_SendByte
 * @param  Data: 数据
 * @retval None
 */
void UART1_SendByte(uint8_t Data)
{
    while(UART_GetFlagStatus(UART1, UART_FLAG_TXE) == RESET);
    UART_SendData(UART1, Data);
}



/**
* @brief  UART1发送字符串
 * @param  String: 字符串
 * @retval None
 */
void UART1_Send_Str(uint8_t *String,uint8_t s1)
{
	  uint8_t i;
	
    for(i=0;i<s1;i++)
    {
        UART1_SendByte(*String);
        String++;
    }
}



/**
 * @brief  UART2_SendByte
 * @param  Data: 数据
 * @retval None
 */
void UART2_SendByte(uint8_t Data)
{
    while(UART_GetFlagStatus(UART2, UART_FLAG_TXE) == RESET);
    UART_SendData(UART2, Data);
}



/**
* @brief  UART2发送字符串
 * @param  String: 字符串
 * @retval None
 */
void UART2_Send_Str(uint8_t *String,uint8_t s2)
{
	  uint8_t i;
	
    for(i=0;i<s2;i++)
    {
        UART2_SendByte(*String);
        String++;
    }
}



//打印输出
int fputc(int ch, FILE *f)
{
    UART1_SendByte(ch);
    return ch;
}













