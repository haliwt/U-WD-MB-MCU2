#include "bsp.h"


/*================= ???????? =================*/

static void DHT11_GPIO_Output(void);
static void DHT11_GPIO_Input(void);
static void DHT11_WritePin(uint8_t val);
static uint8_t DHT11_ReadPin(void);

static void TIM17_Init_1MHz(void);
//static void Delay_US_dht11(uint16_t us);


static uint8_t DHT11_ReadByte(void);

/*================= ?????? =================*/

void delay_ms_dht11(uint16_t ms)
{
    ms = 1000*ms;
	Delay_US_dht11(ms);

}

void DHT11_Init(void)
{
    /* GPIO ?????????? */
    RCC_AHB2PeriphClockCmd(DHT11_GPIO_CLK, ENABLE);

    DHT11_GPIO_Output();
    DHT11_WritePin(1);

    /* ??? TIM14 ? 1MHz ?? */
    TIM17_Init_1MHz();
}

/**
 * @brief  ?? DHT11 ???
 * @param  humi: ??????
 * @param  temp: ??????
 * @retval 0: ??,??: ??
 */
 #if 1
uint8_t DHT11_ReadData(uint8_t *humi, uint8_t *temp)
{
    uint8_t data[5] = {0};
    uint32_t timeout;


    /* 2. ???? 18ms */
    DHT11_GPIO_Output();
    DHT11_WritePin(0);
    Delay_US_dht11(18000);

    /* 3. ?? 20~40us */
    DHT11_WritePin(1);
    Delay_US_dht11(30);

    /* 4. ????,?? DHT11 ?? */
    DHT11_GPIO_Input();
    Delay_US_dht11(5);

    /* ?? DHT11 ??(80us) */
    timeout = 0;
    while (DHT11_ReadPin())
    {
        if (++timeout > 1000) return 3; // ????????
        Delay_US_dht11(1);
    }

    /* ?? DHT11 ??(80us) */
    timeout = 0;
    while (!DHT11_ReadPin())
    {
        if (++timeout > 1000) return 3; // ????????
        Delay_US_dht11(1);
    }

    /* ?? DHT11 ????,?????? */
    timeout = 0;
    while (DHT11_ReadPin())
    {
        if (++timeout > 1000) return 3; // ????????
        Delay_US_dht11(1);
    }

    /* 5. ?? 5 ??(40bit) */
    for (uint8_t i = 0; i < 5; i++)
    {
        data[i] = DHT11_ReadByte();
        if (data[i] == 0xFF) return 3;
    }

    /* 7. ?? */
    if ((uint8_t)(data[0] + data[1] + data[2] + data[3]) != data[4])
        return 2;

    *humi = data[0];
    *temp = data[2];

    return 0;
}
#else 

uint8_t DHT11_ReadData(uint8_t *humi, uint8_t *temp)
{
    uint8_t data[5] = {0};
    uint32_t timeout;

    /* 1. 主机发送 18ms 低电平起始信号 */
    DHT11_GPIO_Output();
    DHT11_WritePin(0);
    Delay_US_dht11(18000);

    /* 2. 主机拉高 30us */
    DHT11_WritePin(1);
    Delay_US_dht11(30);

    /* 3. 切换为输入，准备接收 DHT11 响应 */
    DHT11_GPIO_Input();
    Delay_US_dht11(5);

    /* --- 握手阶段 1 --- 等待 DHT11 拉低 (80us响应低电平) */
    timeout = 0;
    while (DHT11_ReadPin())
    {
        if (++timeout > 1000) return 1; // 错误码 1：等不到 DHT11 的响应低电平（传感器没连好或未响应）
        Delay_US_dht11(1);
    }

    /* --- 握手阶段 2 --- 等待 DHT11 释放并拉高 (80us响应高电平) */
    timeout = 0;
    while (!DHT11_ReadPin())
    {
        if (++timeout > 1000) return 2; // 错误码 2：等不到响应高电平结束
        Delay_US_dht11(1);
    }

    /* --- 握手阶段 3 --- 等待高电平结束，准备进入数据接收 */
    timeout = 0;
    while (DHT11_ReadPin())
    {
        if (++timeout > 1000) return 3; // 错误码 3：等待数据传输前的引脚拉低超时
        Delay_US_dht11(1);
    }

    /* 4. 读取 5 个字节(40bit) */
    for (uint8_t i = 0; i < 5; i++)
    {
        data[i] = DHT11_ReadByte();
        if (data[i] == 0xFF) return 4;   // 错误码 4：读字节过程中超时
    }

    /* 5. 校验和检查 */
    if ((uint8_t)(data[0] + data[1] + data[2] + data[3]) != data[4])
        return 5;                       // 错误码 5：校验和错误

    *humi = data[0];
    *temp = data[2];

    return 0; // 成功
}




#endif 

/*================= ?????? =================*/

static void DHT11_GPIO_Output(void)
{
    GPIO_InitTypeDef gpio;
    GPIO_StructInit(&gpio);

    gpio.GPIO_Pin   = DHT11_GPIO_PIN;
    gpio.GPIO_Mode  = GPIO_Mode_OUT;
    gpio.GPIO_OType = GPIO_OType_PP;
    gpio.GPIO_Speed = GPIO_Speed_High;
    gpio.GPIO_PuPd  = GPIO_PuPd_NOPULL;

    GPIO_Init(DHT11_GPIO_PORT, &gpio);
}

static void DHT11_GPIO_Input(void)
{
    GPIO_InitTypeDef gpio;
    GPIO_StructInit(&gpio);

    gpio.GPIO_Pin  = DHT11_GPIO_PIN;
    gpio.GPIO_Mode = GPIO_Mode_IN;
    gpio.GPIO_PuPd = GPIO_PuPd_NOPULL;

    GPIO_Init(DHT11_GPIO_PORT, &gpio);
}

static void DHT11_WritePin(uint8_t val)
{
    if (val)
        LL_GPIO_SetOutputPin(DHT11_GPIO_PORT, DHT11_GPIO_PIN);//GPIO_SetBits(DHT11_GPIO_PORT, DHT11_GPIO_PIN);
    else
        LL_GPIO_ResetOutputPin(DHT11_GPIO_PORT, DHT11_GPIO_PIN);//GPIO_ResetBits(DHT11_GPIO_PORT, DHT11_GPIO_PIN);
}

static uint8_t DHT11_ReadPin(void)
{
    return  (DHT11_GPIO_PORT->IDR & DHT11_GPIO_PIN) ? 1 : 0;
}

/*---------------- TIM14 1MHz ?? ----------------*/

static void TIM17_Init_1MHz(void)
{
   #if 0

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM17, ENABLE);

    TIM_TimeBaseInitTypeDef tim;
    TIM_TimeBaseStructInit(&tim);

    tim.TIM_Prescaler     = 64-1 ; //48 - 1;   /* 48MHz / 48 = 1MHz */
    tim.TIM_Period        = 0xFFFF;
    tim.TIM_CounterMode   = TIM_CounterMode_Up;
    tim.TIM_ClockDivision = TIM_CKD_DIV1;

    TIM_TimeBaseInit(TIM17, &tim);
    TIM_Cmd(TIM17, ENABLE);
  #else 
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM17, ENABLE);

    TIM_TimeBaseInitTypeDef tim;
    TIM_TimeBaseStructInit(&tim);

    uint32_t sysclk = SystemCoreClock;   // 自动获取系统时钟

    tim.TIM_Prescaler = sysclk / 1000000 - 1;   // 动态计算
    tim.TIM_Period    = 0xFFFF;
    tim.TIM_CounterMode   = TIM_CounterMode_Up;
    tim.TIM_ClockDivision = TIM_CKD_DIV1;

    TIM_TimeBaseInit(TIM17, &tim);
    TIM_Cmd(TIM17, ENABLE);


  #endif 
}

void Delay_US_dht11(uint16_t us)
{
   #if 1

	uint16_t start = TIM17->CNT;

    while ((uint16_t)(TIM17->CNT - start) < us)
    {
        /* busy wait */
    }
	#else 
	  while (us--)
    {
        // 48MHz ?,1us ?? 48 ???
        // ?? while ?????????????(? 6~9 ???)
        // ??? 40 ?????? NOP ??
        __NOP(); __NOP(); __NOP(); __NOP(); __NOP(); __NOP();
        __NOP(); __NOP(); __NOP(); __NOP(); __NOP(); __NOP();
        __NOP(); __NOP(); __NOP(); __NOP(); __NOP(); __NOP();
        __NOP(); __NOP(); __NOP(); __NOP(); __NOP(); __NOP();
    }


	#endif 
}

static uint8_t DHT11_ReadByte(void)
{

   #if 0
	uint8_t i, dat = 0;
    volatile uint32_t timeout; // 使用 volatile 防止被编译器优化

    for (i = 0; i < 8; i++) 
    {
        // ------------------ 预防卡死点 1 ------------------
        // 等待引脚变为高电平（跳过起始的低电平阶段）
        timeout = 0;
        //while (GPIO_ReadInputDataBit(DHT11_DATA_GPIO_PORT, DHT11_DATA_PIN) == 0)
        while ((DHT11_DATA_GPIO_PORT->IDR & DHT11_DATA_PIN) == 0)
        {
            timeout++;
            if (timeout > 10000) // 门槛值，防止硬件损坏时死循环
            {
                return 0xFF; // 返回错误标志
            }
			Delay_US_dht11(1); // 关键：加入 1us 延时，防止 64MHz 下计数瞬间超限
        }
        
        // 延时 40微秒 区分信号是 0 还是 1
        Delay_US_dht11(40);
        
        // 如果 40us 后依然是高电平，说明这一位是数据 "1"
        //if (GPIO_ReadInputDataBit(DHT11_DATA_GPIO_PORT, DHT11_DATA_PIN) == 1)
        if ((DHT11_DATA_GPIO_PORT->IDR & DHT11_DATA_PIN) != 0)
        {
            // ------------------ 预防卡死点 2 ------------------
            // 数据是 1，需要等待引脚变回低电平，才能开始下一位的接收
            timeout = 0;
            while(DHT11_DATA_GPIO_PORT->IDR & DHT11_DATA_PIN != 0)//while (GPIO_ReadInputDataBit(DHT11_DATA_GPIO_PORT, DHT11_DATA_PIN) == 1)
            {
                timeout++;
                if (timeout > 10000) 
                {
                    return 0xFF; // 返回错误标志
                }
            }
            
            dat |= (uint8_t)(0x01 << (7 - i)); // 写入 1
        }
        else
        {
            // 40us 后变回了低电平，说明这一位是数据 "0"
            //（此时引脚已经是低电平了，无需等待，直接清零对应位即可）
            dat &= (uint8_t)~(0x01 << (7 - i)); // 写入 0
        }
    }
    
    return dat;
	#else

	uint8_t i, dat = 0;
    volatile uint16_t timeout;

    for (i = 0; i < 8; i++)
    {
        /* 1. 每个位开始前，DHT11 会拉低总线 50us，等待其变高 */
        timeout = 0;
        while (!DHT11_ReadPin())
        {
            if (++timeout > 1000) return 0xFF; // 超时错误
            Delay_US_dht11(1);
        }

        /* 2. 总线变高后，延时 30~40us 之后判断引脚电平 */
        Delay_US_dht11(40); 

        /* 3. 如果此时还是高电平，说明这一位是 '1'（高电平持续 70us）*/
        /*    如果变为了低电平，说明这一位是 '0'（高电平仅持续 26~28us）*/
        dat <<= 1;
        if (DHT11_ReadPin())
        {
            dat |= 1;
        }

        /* 4. 等待当前位的高电平结束（等待变回低电平，准备下一位） */
        timeout = 0;
        while (DHT11_ReadPin())
        {
            if (++timeout > 1000) return 0xFF; // 超时错误
            Delay_US_dht11(1);
        }
    }
    return dat;
	#endif 


	
}



uint8_t dht11_read_temp_humidity_value(void)
{
    uint8_t dht11_read_flag;
	
	dht11_read_flag = DHT11_ReadData(&humidity,&temperature);
    if(dht11_read_flag==0) 
		return dht11_read_flag;
    else 
        return 0xff;
	
}
  #if 0
	if(dht11_read_flag==0){
      
	 // humidity = dht11_data_buf[0];
	 // temperature = dht11_data_buf[2];
	    printf("humidity = %d \r\n",humidity);
	    printf("temperature = %d \r\n",temperature);
	   LED_PLASMA_ON();
       return 0;
	}
	else{

       LED_PLASMA_OFF();
	   tx_thread_sleep(20);
	   LED_PLASMA_ON();
	   tx_thread_sleep(20);
	   LED_PLASMA_OFF();


	   printf("read fail, code = %d\r\n", dht11_read_flag);
	   return 1;
		
	}

  #endif 


