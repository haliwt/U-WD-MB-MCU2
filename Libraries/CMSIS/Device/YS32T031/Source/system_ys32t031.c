/**
  ******************************************************************************
  * @file    system_ys32t031.c
  * @author  YSPRING Application Team
  * @brief   CMSIS Cortex-M0 Device Peripheral Access Layer System Source File.
  *
  * 1. This file provides two functions and one global variable to be called from
  *    user application:
  *      - SystemInit(): This function is called at startup just after reset and 
  *                      before branch to main program. This call is made inside
  *                      the "startup_ys32t031.s" file.
  *
  *      - SystemCoreClock variable: Contains the core clock (HCLK), it can be used
  *                                  by the user application to setup the SysTick
  *                                  timer or configure other parameters.
  *
  *      - SystemCoreClockUpdate(): Updates the variable SystemCoreClock and must
  *                                 be called whenever the core clock is changed
  *                                 during program execution.
  *
  *
  ******************************************************************************
 */

/******************************************************************************/
/* Include files                                                              */
/******************************************************************************/
#include "ys32t031.h"
#include "system_ys32t031.h"

/**
 ******************************************************************************
 ** System Clock Frequency (Core Clock) Variable according CMSIS
 ******************************************************************************/
uint32_t SystemCoreClock = 16000000;

const uint8_t AHBPrescTable[16] = {0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 6, 7, 8, 9};
const uint8_t APBPrescTable[8] = {0, 0, 0, 0, 1, 2, 3, 4};
const uint32_t HSIFreqTable[4] = {48000000U, 36000000U, 24000000U, 16000000U};



/**
 ******************************************************************************
 ** \brief  Setup the microcontroller system. Initialize the System and update
 ** the SystemCoreClock variable.
 **
 ** \param  none
 ** \return none
 ******************************************************************************/
void SystemInit(void)
{
  /* NOTE :SystemInit(): This function is called at startup just after reset and 
                         before branch to main program. This call is made inside
                         the "startup_ys32f0xx.s" file.
                         User can setups the default system clock (System clock source, PLL Multiplier
                         and Divider factors, AHB/APBx prescalers and Flash settings).
   */
  uint32_t reg;

  reg = RCC->ICSCR;
  reg &= ~(RCC_ICSCR_HSI_FS | RCC_ICSCR_HSI_TRIM);
  reg |= RCC_HSI_16M;                  //16M
  RCC->ICSCR = reg;
  
  reg = RCC->CR;
  reg &= ~(RCC_CR_HSIDIV);
  reg |= RCC_CR_HSIDIV_1;              //DIV1
  RCC->CR = reg;

}

void SystemCoreClockUpdate(void)       // Update SystemCoreClock variable
{
  RCC_ClocksTypeDef RCC_CLK;
  
  RCC_GetClocksFreq(&RCC_CLK);
  SystemCoreClock = RCC_CLK.HCLK_Frequency;
}

#if defined(__CC_ARM)

#endif

