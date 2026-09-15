/*
 * YSPRING YS32T031 License
 *
 * @file     ys32t031.h
 * @brief    CMSIS HeaderFile
 * @version  0.0.26
 * @date     Fri May 30 13:58:08 2025
 */


/** @addtogroup YSPRING Ltd.
  * @{
  */


/** @addtogroup ys32t031
  * @{
  */


#ifndef YS32T031_H
#define YS32T031_H

#ifdef __cplusplus
extern "C" {
#endif


/** @addtogroup Configuration_of_CMSIS
  * @{
  */



/* =========================================================================================================================== */
/* ================                                Interrupt Number Definition                                ================ */
/* =========================================================================================================================== */

typedef enum {
/* =======================================  ARM Cortex-M0 Specific Interrupt Numbers  ======================================== */
  Reset_IRQn                = -15,              /*!< -15  Reset Vector, invoked on Power up and warm reset                     */
  NonMaskableInt_IRQn       = -14,              /*!< -14  Non maskable Interrupt, cannot be stopped or preempted               */
  HardFault_IRQn            = -13,              /*!< -13  Hard Fault, all classes of Fault                                     */
  SVCall_IRQn               =  -5,              /*!< -5 System Service Call via SVC instruction                                */
  PendSV_IRQn               =  -2,              /*!< -2 Pendable request for system service                                    */
  SysTick_IRQn              =  -1,              /*!< -1 System Tick Timer                                                      */
/* ==========================================  ys32t031 Specific Interrupt Numbers  ========================================== */
  WWDG_IRQn                 =   0,              /*!< 0  Window WatchDog Interrupt                                              */
  PVD_IRQn                  =   1,              /*!< 1  PVD Interrupt through EXTI Lines 16                                    */
  RTC_IRQn                  =   2,              /*!< 2  RTC Interrupt through EXTI Lines 19                                    */
  FLASH_IRQn                =   3,              /*!< 3  Flash global interrupt                                                 */
  RCC_IRQn                  =   4,              /*!< 4  RCC global Interrupt                                                   */
  EXTI0_1_IRQn              =   5,              /*!< 5  EXTI Line 0 and 1 Interrupt                                            */
  EXTI2_3_IRQn              =   6,              /*!< 6  EXTI Line 2 and 3 Interrupt                                            */
  EXTI4_15_IRQn             =   7,              /*!< 7  EXTI Line 4 to 15 Interrupt                                            */
  TSC_IRQn                  =   8,              /*!< 8  Touch sensing interrupt                                                */
  DMA_CHANNEL1_IRQn         =   9,              /*!< 9  DMA Channel 1 Interrupt                                                */
  DMA_CHANNEL2_3_IRQn       =  10,              /*!< 10 DMA Channel 2 and Channel 3 Interrupt                                  */
  DMA_CHANNEL4_5_IRQn       =  11,              /*!< 11 DMA Channel 4 and Channel 5 Interrupt                                  */
  ADC_COMP_IRQn             =  12,              /*!< 12 ADC and COMP Interrupt through EXTI Lines 17 and 18                    */
  TIM1_BRK_UP_TRG_COM_IRQn  =  13,              /*!< 13 TIM1 Break, Update, Trigger and Commutation Interrupt                  */
  TIM1_CC_IRQn              =  14,              /*!< 14 TIM1 Capture Compare Interrupt                                         */
  TIM3_IRQn                 =  16,              /*!< 16 TIM3 global Interrupt                                                  */
  TIM6_LPTIM_IRQn           =  17,              /*!< 17 TIM6/LPTIM Interrupt                                                   */
  TIM14_IRQn                =  19,              /*!< 19 TIM14 global Interrupt                                                 */
  TIM15_IRQn                =  20,              /*!< 20 TIM15 global Interrupt                                                 */
  TIM16_IRQn                =  21,              /*!< 21 TIM16 global Interrupt                                                 */
  TIM17_IRQn                =  22,              /*!< 22 TIM17 global Interrupt                                                 */
  I2C1_IRQn                 =  23,              /*!< 23 I2C1 global Interrupt                                                  */
  I2C2_IRQn                 =  24,              /*!< 24 I2C2 global Interrupt                                                  */
  SPI1_IRQn                 =  25,              /*!< 25 SPI1 global Interrupt                                                  */
  SPI2_IRQn                 =  26,              /*!< 26 SPI2 global Interrupt                                                  */
  UART1_IRQn                =  27,              /*!< 27 UART1 global Interrupt                                                 */
  UART2_IRQn                =  28,              /*!< 28 UART2 global Interrupt                                                 */
  LED_IRQn                  =  30               /*!< 30 LED global Interrupt                                                   */
} IRQn_Type;



/* =========================================================================================================================== */
/* ================                           Processor and Core Peripheral Section                           ================ */
/* =========================================================================================================================== */

/* ===========================  Configuration of the ARM Cortex-M0 Processor and Core Peripherals  =========================== */
#define __CM0_REV                 0x0000U       /*!< CM0 Core Revision                                                         */
#define __NVIC_PRIO_BITS               2        /*!< Number of Bits used for Priority Levels                                   */
#define __Vendor_SysTickConfig         0        /*!< Set to 1 if different SysTick Config is used                              */
#define __MPU_PRESENT                  1        /*!< MPU present                                                               */
#define __FPU_PRESENT                  0        /*!< FPU present                                                               */


/** @} */ /* End of group Configuration_of_CMSIS */

#include "core_cm0.h"                           /*!< ARM Cortex-M0 processor and core peripherals                              */
#include "system_ys32t031.h"                    /*!< ys32t031 System                                                           */

#ifndef __IM                                    /*!< Fallback for older CMSIS versions                                         */
  #define __IM   __I
#endif
#ifndef __OM                                    /*!< Fallback for older CMSIS versions                                         */
  #define __OM   __O
#endif
#ifndef __IOM                                   /*!< Fallback for older CMSIS versions                                         */
  #define __IOM  __IO
#endif


/* ========================================  Start of section using anonymous unions  ======================================== */
#if defined (__CC_ARM)
  #pragma push
  #pragma anon_unions
#elif defined (__ICCARM__)
  #pragma language=extended
#elif defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
  #pragma clang diagnostic push
  #pragma clang diagnostic ignored "-Wc11-extensions"
  #pragma clang diagnostic ignored "-Wreserved-id-macro"
  #pragma clang diagnostic ignored "-Wgnu-anonymous-struct"
  #pragma clang diagnostic ignored "-Wnested-anon-types"
#elif defined (__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined (__TMS470__)
  /* anonymous unions are enabled by default */
#elif defined (__TASKING__)
  #pragma warning 586
#elif defined (__CSMC__)
  /* anonymous unions are enabled by default */
#else
  #warning Not supported compiler type
#endif


/* =========================================================================================================================== */
/* ================                            Device Specific Peripheral Section                             ================ */
/* =========================================================================================================================== */


/** @addtogroup Device_Peripheral_peripherals
  * @{
  */



/* =========================================================================================================================== */
/* ================                                           FLASH                                           ================ */
/* =========================================================================================================================== */


/**
  * @brief FLASH (FLASH)
  */

typedef struct {                                /*!< FLASH Structure                                                           */
  __IOM uint32_t  ACR;                          /*!< Access Control register                                                   */
  __IM  uint32_t  RESERVED;
  __OM  uint32_t  KEYR;                         /*!< FLASH key register                                                        */
  __OM  uint32_t  OPTKEYR;                      /*!< FLASH Optional key register                                               */
  __IOM uint32_t  SR;                           /*!< FLASH State register                                                      */
  __IOM uint32_t  CR;                           /*!< FLASH Control register                                                    */
  __IM  uint32_t  RESERVED1[2];
  __IOM uint32_t  OPTR;                         /*!< FLASH option register                                                     */
  __IOM uint32_t  PCROPR;                       /*!< FLASH PCROPR address register                                             */
  __IM  uint32_t  RESERVED2;
  __IOM uint32_t  WRPR;                         /*!< FLASH_WRPR register                                                       */
  __IM  uint32_t  RESERVED3[52];
  __IOM uint32_t  SEQ0;                         /*!< FLASH SEQ0 register                                                       */
  __IOM uint32_t  SEQ1;                         /*!< FLASH SEQ1 register                                                       */
  __IOM uint32_t  SEQ2P1;                       /*!< FLASH SEQ2P1 register                                                     */
  __IOM uint32_t  SEQ2P3;                       /*!< FLASH SEQ2P3 register                                                     */
  __IOM uint32_t  SEQ3;                         /*!< FLASH SEQ3 register                                                       */
  __IOM uint32_t  PREPG_SEQ2P2;                 /*!< FLASH PRE-PROGRAM SEQ2P2 register                                         */
  __IOM uint32_t  PE_SEQ2P2;                    /*!< FLASH PAGE ERASE SEQ2P2 register                                          */
  __IOM uint32_t  SME_SEQ2P2;                   /*!< FLASH SECTOR MASS ERASE SEQ2P2 register                                   */
  __IOM uint32_t  PP_SEQ2P2;                    /*!< FLASH PAGE PROGRAM SEQ2P2 register                                        */
  __IOM uint32_t  SMP_SEQ2P2;                   /*!< FLASH SECTOR MASS PROGRAM SEQ2P2 register                                 */
} FLASH_TypeDef;                                   /*!< Size = 296 (0x128)                                                        */



/* =========================================================================================================================== */
/* ================                                            PWR                                            ================ */
/* =========================================================================================================================== */


/**
  * @brief The peripheral's registers can be accessed via half-word or word (PWR)
  */

typedef struct {                                /*!< PWR Structure                                                             */
  __IOM uint32_t  CR1;                          /*!< Power control registers                                                   */
  __IOM uint32_t  CR2;                          /*!< Power control registers                                                   */
  __IM  uint32_t  RESERVED[3];
  __IM  uint32_t  SR;                           /*!< Power State registers                                                     */
} PWR_TypeDef;                                     /*!< Size = 24 (0x18)                                                          */



/* =========================================================================================================================== */
/* ================                                            RCC                                            ================ */
/* =========================================================================================================================== */


/**
  * @brief Reset and clock control (RCC)
  */

typedef struct {                                /*!< RCC Structure                                                             */
  __IOM uint32_t  CR;                           /*!< Clock control register                                                    */
  __IOM uint32_t  ICSCR;                        /*!< Internal clock sources calibration register                               */
  __IOM uint32_t  CFGR;                         /*!< Clock configuration register                                              */
  __IOM uint32_t  PLLCFGR;                      /*!< PLL configuration register                                                */
  __IOM uint32_t  ECSCR;                        /*!< External clock source control register                                    */
  __IM  uint32_t  RESERVED;
  __IOM uint32_t  CIER;                         /*!< Clock interrupt enable register                                           */
  __IM  uint32_t  CIFR;                         /*!< Clock interrupt flag register                                             */
  __OM  uint32_t  CICR;                         /*!< Clock interrupt clear register                                            */
  __IOM uint32_t  IOPRSTR;                      /*!< GPIO reset register                                                       */
  __IOM uint32_t  AHBRSTR;                      /*!< AHB peripheral reset register                                             */
  __IOM uint32_t  APBRSTR1;                     /*!< APB peripheral reset register 1                                           */
  __IOM uint32_t  APBRSTR2;                     /*!< APB peripheral reset register 2                                           */
  __IOM uint32_t  IOPENR;                       /*!< GPIO clock enable register                                                */
  __IOM uint32_t  AHBENR;                       /*!< AHB peripheral clock enable register                                      */
  __IOM uint32_t  APBENR1;                      /*!< APB peripheral clock enable register 1                                    */
  __IOM uint32_t  APBENR2;                      /*!< APB peripheral clock enable register 2                                    */
  __IM  uint32_t  RESERVED1[4];
  __IOM uint32_t  CCIPR;                        /*!< Peripherals independent clock configuration register                      */
  __IM  uint32_t  RESERVED2;
  __IOM uint32_t  BDCR;                         /*!< RTC domain control register                                               */
  __IOM uint32_t  CSR;                          /*!< Control/status register                                                   */
  __IM  uint32_t  RESERVED3[3];
  __IOM uint32_t  MRTRIM_CR;                    /*!< Voltage regulation control register                                       */
} RCC_TypeDef;                                     /*!< Size = 116 (0x74)                                                         */



/* =========================================================================================================================== */
/* ================                                           GPIOA                                           ================ */
/* =========================================================================================================================== */


/**
  * @brief General-purpose I/Os (GPIOA)
  */

typedef struct {                                /*!< GPIOA Structure                                                           */
  __IOM uint32_t  MODER;                        /*!< GPIO port mode register                                                   */
  __IOM uint32_t  OTYPER;                       /*!< GPIO port output type register                                            */
  __IOM uint32_t  OSPEEDR;                      /*!< GPIO port output speed register                                           */
  __IOM uint32_t  PUPDR;                        /*!< GPIO port pull-up/pull-down register                                      */
  __IM  uint32_t  IDR;                          /*!< GPIO port input data register                                             */
  __IOM uint32_t  ODR;                          /*!< GPIO port output data register                                            */
  __OM  uint32_t  BSRR;                         /*!< GPIO port bit set/reset register                                          */
  __IOM uint32_t  LCKR;                         /*!< GPIO port configuration lock register                                     */
  __IOM uint32_t  AFRL;                         /*!< GPIO alternate function low register                                      */
  __IOM uint32_t  AFRH;                         /*!< GPIO alternate function high register                                     */
  __OM  uint32_t  BRR;                          /*!< port bit reset register                                                   */
} GPIO_TypeDef;                                   /*!< Size = 44 (0x2c)                                                          */



/* =========================================================================================================================== */
/* ================                                          SYSCFG                                           ================ */
/* =========================================================================================================================== */


/**
  * @brief System configuration controller (SYSCFG)
  */

typedef struct {                                /*!< SYSCFG Structure                                                          */
  __IOM uint32_t  CFGR1;                        /*!< SYSCFG configuration register 1                                           */
  __IM  uint32_t  RESERVED[5];
  __IOM uint32_t  CFGR2;                        /*!< SYSCFG configuration register 2                                           */
  __IOM uint32_t  CFGR3;                        /*!< SYSCFG configuration register 3                                           */
  __IOM uint32_t  CFGR4;                        /*!< SYSCFG configuration register 4                                           */
  __IM  uint32_t  RESERVED1[81];
  __IOM uint32_t  SRAM_TEST_CFGR;               /*!< SRAM TEST CONFIGURATION register                                          */
} SYSCFG_TypeDef;                                  /*!< Size = 364 (0x16c)                                                        */



/* =========================================================================================================================== */
/* ================                                            DMA                                            ================ */
/* =========================================================================================================================== */


/**
  * @brief Direct memory access (DMA)
  */

typedef struct {                                /*!< DMA Structure                                                             */
  __IM  uint32_t  ISR;                          /*!< DMA interrupt status register (DMA_ISR)                                   */
  __OM  uint32_t  IFCR;                         /*!< DMA interrupt flag clear register (DMA_IFCR)                              */
} DMA_TypeDef;                                     /*!< Size = 8 (0x8)                                                            */



/* =========================================================================================================================== */
/* ================                                       DMA_CHANNEL1                                        ================ */
/* =========================================================================================================================== */


/**
  * @brief Direct Channel 1 (DMA_CHANNEL1)
  */

typedef struct {                                /*!< DMA_CHANNEL1 Structure                                                    */
  __IOM uint32_t  CCR;                          /*!< DMA channel configuration register (DMA_CCR)                              */
  __IOM uint32_t  CNDTR;                        /*!< DMA channel number of data register                                       */
  __IOM uint32_t  CPAR;                         /*!< DMA channel peripheral address register                                   */
  __IOM uint32_t  CMAR;                         /*!< DMA channel memory address register                                       */
} DMA_CHANNEL_TypeDef;                            /*!< Size = 16 (0x10)                                                          */



/* =========================================================================================================================== */
/* ================                                           EXTI                                            ================ */
/* =========================================================================================================================== */


/**
  * @brief External interrupt/event
   controller (EXTI)
  */

typedef struct {                                /*!< EXTI Structure                                                            */
  __IOM uint32_t  RTSR;                         /*!< EXTI rising trigger selection register                                    */
  __IOM uint32_t  FTSR;                         /*!< EXTI falling trigger selection register                                   */
  __IOM uint32_t  SWIER;                        /*!< EXTI software interrupt event register                                    */
  __IOM uint32_t  PR;                           /*!< EXTI pending register                                                     */
  __IM  uint32_t  RESERVED[20];
  __IOM uint32_t  EXTICR1;                      /*!< EXTI external interrupt selection register                                */
  __IOM uint32_t  EXTICR2;                      /*!< EXTI external interrupt selection register                                */
  __IOM uint32_t  EXTICR3;                      /*!< EXTI external interrupt selection register                                */
  __IOM uint32_t  EXTICR4;                      /*!< EXTI external interrupt selection register                                */
  __IM  uint32_t  RESERVED1[4];
  __IOM uint32_t  IMR;                          /*!< EXTI CPU wakeup with interrupt mask register                              */
  __IOM uint32_t  EMR;                          /*!< EXTI CPU wakeup with event mask register                                  */
} EXTI_TypeDef;                                    /*!< Size = 136 (0x88)                                                         */



/* =========================================================================================================================== */
/* ================                                            ADC                                            ================ */
/* =========================================================================================================================== */


/**
  * @brief Analog to Digital Converter (ADC)
  */

typedef struct {                                /*!< ADC Structure                                                             */
  __IOM uint32_t  SR;                           /*!< ADC status register                                                       */
  __IOM uint32_t  CR1;                          /*!< ADC control register                                                      */
  __IOM uint32_t  CR2;                          /*!< ADC control register                                                      */
  __IOM uint32_t  SMPR;                         /*!< ADC sampling time register 1                                              */
  __IOM uint32_t  JOFR1;                        /*!< ADC injection channel data offset registe 1                               */
  __IOM uint32_t  JOFR2;                        /*!< ADC injection channel data offset registe 2                               */
  __IOM uint32_t  JOFR3;                        /*!< ADC injection channel data offset registe 3                               */
  __IOM uint32_t  JOFR4;                        /*!< ADC injection channel data offset registe 4                               */
  __IOM uint32_t  JOFR5;                        /*!< ADC injection channel data offset registe 5                               */
  __IOM uint32_t  HTR;                          /*!< ADC Watchdog high threshold register                                      */
  __IOM uint32_t  LTR;                          /*!< ADC Watchdog low threshold register                                       */
  __IOM uint32_t  SQR1;                         /*!< ADC regular sequence register 1                                           */
  __IOM uint32_t  SQR2;                         /*!< ADC regular sequence register 2                                           */
  __IOM uint32_t  SQR3;                         /*!< ADC regular sequence register 3                                           */
  __IOM uint32_t  SQR4;                         /*!< ADC regular sequence register 4                                           */
  __IOM uint32_t  JSQR;                         /*!< ADC injected sequence register                                            */
  __IM  uint32_t  JDR1;                         /*!< ADC injected data register 1                                              */
  __IM  uint32_t  JDR2;                         /*!< ADC injected data register 2                                              */
  __IM  uint32_t  JDR3;                         /*!< ADC injected data register 3                                              */
  __IM  uint32_t  JDR4;                         /*!< ADC injected data register 4                                              */
  __IM  uint32_t  JDR5;                         /*!< ADC injected data register 5                                              */
  __IM  uint32_t  DR;                           /*!< ADC regular data register                                                 */
} ADC_TypeDef;                                     /*!< Size = 88 (0x58)                                                          */



/* =========================================================================================================================== */
/* ================                                           COMP1                                           ================ */
/* =========================================================================================================================== */


/**
  * @brief Comparator (COMP1)
  */

typedef struct {                                /*!< COMP1 Structure                                                           */
  __IOM uint32_t  CSR;                          /*!< COMP control and status register                                          */
  __IOM uint32_t  FR;                           /*!< Comparator Filter register                                                */
} COMP_TypeDef;                                   /*!< Size = 8 (0x8)                                                            */



/* =========================================================================================================================== */
/* ================                                           COMP2                                           ================ */
/* =========================================================================================================================== */


/**
  * @brief Comparator (COMP2)
  */

typedef struct {                                /*!< COMP2 Structure                                                           */
  __IOM uint32_t  CSR;                          /*!< COMP control and status register                                          */
  __IOM uint32_t  FR;                           /*!< Comparator Filter register                                                */
} COMP2_TypeDef;                                   /*!< Size = 8 (0x8)                                                            */



/* =========================================================================================================================== */
/* ================                                           COMP3                                           ================ */
/* =========================================================================================================================== */


/**
  * @brief Comparator (COMP3)
  */

typedef struct {                                /*!< COMP3 Structure                                                           */
  __IOM uint32_t  CSR;                          /*!< COMP control and status register                                          */
  __IOM uint32_t  FR;                           /*!< Comparator Filter register                                                */
} COMP3_TypeDef;                                   /*!< Size = 8 (0x8)                                                            */



/* =========================================================================================================================== */
/* ================                                           COMP4                                           ================ */
/* =========================================================================================================================== */


/**
  * @brief Comparator (COMP4)
  */

typedef struct {                                /*!< COMP4 Structure                                                           */
  __IOM uint32_t  CSR;                          /*!< COMP control and status register                                          */
  __IOM uint32_t  FR;                           /*!< Comparator Filter register                                                */
} COMP4_TypeDef;                                   /*!< Size = 8 (0x8)                                                            */



/* =========================================================================================================================== */
/* ================                                            LED                                            ================ */
/* =========================================================================================================================== */


/**
  * @brief LED CONTROLLER (LED)
  */

typedef struct {                                /*!< LED Structure                                                             */
  __IOM uint32_t  ICDR;                         /*!< Control register                                                          */
  __IOM uint32_t  OTCR;                         /*!< LED turn-on time configuration register                                   */
  __IOM uint32_t  GCR;                          /*!< LED general configuration register                                        */
  __IOM uint32_t  SCR1;                         /*!< LED status configuration register 1                                       */
  __IOM uint32_t  SCR2;                         /*!< LED status configuration register 2                                       */
  __IOM uint32_t  OPSR1;                        /*!< LED light period selection register 1                                     */
  __IOM uint32_t  OPSR2;                        /*!< LED light period selection register 2                                     */
  __IOM uint32_t  COMENR;                       /*!< IO high current enable register                                           */
} LED_TypeDef;                                     /*!< Size = 32 (0x20)                                                          */



/* =========================================================================================================================== */
/* ================                                          VREFBUF                                          ================ */
/* =========================================================================================================================== */


/**
  * @brief Voltage reference buffer (VREFBUF)
  */

typedef struct {                                /*!< VREFBUF Structure                                                         */
  __IOM uint32_t  CSR;                          /*!< VREFBUF control and status register                                       */
  __IOM uint32_t  CCR;                          /*!< VREFBUF calibration control register                                      */
} VREFBUF_TypeDef;                                 /*!< Size = 8 (0x8)                                                            */



/* =========================================================================================================================== */
/* ================                                            CRC                                            ================ */
/* =========================================================================================================================== */


/**
  * @brief CRC calculation unit (CRC)
  */

typedef struct {                                /*!< CRC Structure                                                             */
  __IM  uint32_t  SR;                           /*!< status register                                                           */
  __IOM uint32_t  RESULT;                       /*!< Result register                                                           */
  __OM  uint32_t  DATA;                         /*!< CRC DATA register                                                         */
} CRC_TypeDef;                                     /*!< Size = 12 (0xc)                                                           */



/* =========================================================================================================================== */
/* ================                                           I2C1                                            ================ */
/* =========================================================================================================================== */


/**
  * @brief Inter integrated circuit (I2C1)
  */

typedef struct {                                /*!< I2C1 Structure                                                            */
  __IOM uint32_t  CR1;                          /*!< Control register 1                                                        */
  __IOM uint32_t  CR2;                          /*!< Control register 2                                                        */
  __IOM uint32_t  OAR1;                         /*!< Own address register 1                                                    */
  __IOM uint32_t  OAR2;                         /*!< Own address register 2                                                    */
  __IOM uint32_t  TIMINGR;                      /*!< Timing register                                                           */
  __IM  uint32_t  RESERVED;
  __IOM uint32_t  ISR;                          /*!< Interrupt and Status register                                             */
  __OM  uint32_t  ICR;                          /*!< Interrupt clear register                                                  */
  __IM  uint32_t  RESERVED1;
  __IM  uint32_t  RXDR;                         /*!< Receiving data register                                                   */
  __IOM uint32_t  TXDR;                         /*!< Transfer data register                                                    */
} I2C_TypeDef;                                    /*!< Size = 44 (0x2c)                                                          */



/* =========================================================================================================================== */
/* ================                                           UART1                                           ================ */
/* =========================================================================================================================== */


/**
  * @brief Universal asynchronous receiver
   transmitter (UART1)
  */

typedef struct {                                /*!< UART1 Structure                                                           */
  __IOM uint32_t  CR1;                          /*!< Control register 1                                                        */
  __IOM uint32_t  CR2;                          /*!< Control register 2                                                        */
  __IOM uint32_t  CR3;                          /*!< Control register 3                                                        */
  __IOM uint32_t  BRR;                          /*!< Baud rate register                                                        */
  __IM  uint32_t  RESERVED;
  __IOM uint32_t  RTOR;                         /*!< receiver timeout register                                                 */
  __OM  uint32_t  RQR;                          /*!< requeset register                                                         */
  __IOM uint32_t  ISR;                          /*!< Interrupt Status register                                                 */
  __OM  uint32_t  ICR;                          /*!< Interrupt clear register                                                  */
  __IM  uint32_t  RDR;                          /*!< Receive data register                                                     */
  __IOM uint32_t  TDR;                          /*!< Transfer data register                                                    */
} UART_TypeDef;                                   /*!< Size = 44 (0x2c)                                                          */



/* =========================================================================================================================== */
/* ================                                           WWDG                                            ================ */
/* =========================================================================================================================== */


/**
  * @brief Window watchdog (WWDG)
  */

typedef struct {                                /*!< WWDG Structure                                                            */
  __IOM uint32_t  CR;                           /*!< Control register (WWDG_CR)                                                */
  __IOM uint32_t  CFR;                          /*!< Configuration register (WWDG_CFR)                                         */
  __IOM uint32_t  SR;                           /*!< Status register (WWDG_SR)                                                 */
} WWDG_TypeDef;                                    /*!< Size = 12 (0xc)                                                           */



/* =========================================================================================================================== */
/* ================                                           IWDG                                            ================ */
/* =========================================================================================================================== */


/**
  * @brief Independent watchdog (IWDG)
  */

typedef struct {                                /*!< IWDG Structure                                                            */
  __OM  uint32_t  KR;                           /*!< Key register (IWDG_KR)                                                    */
  __IOM uint32_t  PR;                           /*!< Prescaler register (IWDG_PR)                                              */
  __IOM uint32_t  RLR;                          /*!< Reload register (IWDG_RLR)                                                */
  __IM  uint32_t  SR;                           /*!< Status register (IWDG_SR)                                                 */
  __IOM uint32_t  WINR;                         /*!< Window register (IWDG_WINR)                                               */
} IWDG_TypeDef;                                    /*!< Size = 20 (0x14)                                                          */



/* =========================================================================================================================== */
/* ================                                            RTC                                            ================ */
/* =========================================================================================================================== */


/**
  * @brief Real time clock (RTC)
  */

typedef struct {                                /*!< RTC Structure                                                             */
  __IM  uint32_t  RESERVED[3];
  __IM  uint32_t  ICSR;                         /*!< RTC initialization and status register                                    */
  __IOM uint32_t  PRER;                         /*!< RTC prescaler register                                                    */
  __IM  uint32_t  RESERVED1;
  __IOM uint32_t  CR;                           /*!< RTC control register                                                      */
  __IM  uint32_t  RESERVED2[2];
  __OM  uint32_t  WPR;                          /*!< RTC write protect register                                                */
  __IOM uint32_t  CALR;                         /*!< RTC calibration register                                                  */
  __IM  uint32_t  RESERVED3[9];
  __IOM uint32_t  SR;                           /*!< RTC status register                                                       */
  __IM  uint32_t  RESERVED4[2];
  __IOM uint32_t  SCR;                          /*!< RTC status clear register                                                 */
} RTC_TypeDef;                                     /*!< Size = 96 (0x60)                                                          */



/* =========================================================================================================================== */
/* ================                                           LPTIM                                           ================ */
/* =========================================================================================================================== */


/**
  * @brief Low power timer (LPTIM)
  */

typedef struct {                                /*!< LPTIM Structure                                                           */
  __IM  uint32_t  CNT;                          /*!< Counter Register                                                          */
  __IOM uint32_t  ARR;                          /*!< Autoreload Register                                                       */
  __IOM uint32_t  CR;                           /*!< Control Register                                                          */
  __IM  uint32_t  OVFR;                         /*!< Overflows flag Register                                                   */
  __IOM uint32_t  OCLR;                         /*!< Overflows clear register                                                  */
} LPTIM_TypeDef;                                   /*!< Size = 20 (0x14)                                                          */



/* =========================================================================================================================== */
/* ================                                           TIM                                            ================ */
/* =========================================================================================================================== */


/**
  * @brief Advanced timer (TIM1)
  */

typedef struct {                                /*!< TIM Structure                                                            */
  __IOM uint32_t  CR1;                          /*!< control register 1                                                        */
  __IOM uint32_t  CR2;                          /*!< control register 2                                                        */
  __IOM uint32_t  SMCR;                         /*!< slave mode control register                                               */
  __IOM uint32_t  DIER;                         /*!< DMA/Interrupt enable register                                             */
  __IOM uint32_t  SR;                           /*!< status register                                                           */
  __OM  uint32_t  EGR;                          /*!< event generation register                                                 */
  __IOM uint32_t CCMR1;                         /*!< capture/compare mode register 1                                           */
  __IOM uint32_t CCMR2;                         /*!< capture/compare mode register 2                                           */
  __IOM uint32_t  CCER;                         /*!< capture/compare enable register                                           */
  __IOM uint32_t  CNT;                          /*!< counter                                                                   */
  __IOM uint32_t  PSC;                          /*!< prescaler                                                                 */
  __IOM uint32_t  ARR;                          /*!< auto-reload register                                                      */
  __IOM uint32_t  RCR;                          /*!< repetition counter register                                               */
  __IOM uint32_t  CCR1;                         /*!< capture/compare register 1                                                */
  __IOM uint32_t  CCR2;                         /*!< capture/compare register 2                                                */
  __IOM uint32_t  CCR3;                         /*!< capture/compare register 3                                                */
  __IOM uint32_t  CCR4;                         /*!< capture/compare register 4                                                */
  __IOM uint32_t  BDTR;                         /*!< break and dead-time register                                              */
  __IOM uint32_t  DCR;                          /*!< DMA control register                                                      */
  __IOM uint32_t  DMAR;                         /*!< DMA address for full transfer                                             */
  __IOM uint32_t  OR;                           /*!< TIM configuration register                                               */
  __IM  uint32_t  RESERVED[5];
  __IOM uint32_t  TISEL;                        /*!< TIM Input selection                                                      */
} TIM_TypeDef;                                  /*!< Size = 108 (0x6c)                                                         */



/* =========================================================================================================================== */
/* ================                                          DBGMCU                                           ================ */
/* =========================================================================================================================== */


/**
  * @brief Debug support (DBGMCU)
  */

typedef struct {                                /*!< DBGMCU Structure                                                          */
  __IM  uint32_t  DBG_IDCODE;                   /*!< DBG Device ID Code Register                                               */
  __IOM uint32_t  CR;                           /*!< Debug MCU Configuration Register                                          */
  __IOM uint32_t  DBG_APB_FZ1;                  /*!< APB Freeze freeze Register1                                               */
  __IOM uint32_t  DBG_APB_FZ2;                  /*!< DBG APB Freeze Register2                                                  */
} DBGMCU_TypeDef;                                  /*!< Size = 16 (0x10)                                                          */



/* =========================================================================================================================== */
/* ================                                           SPI1                                            ================ */
/* =========================================================================================================================== */


/**
  * @brief Serial peripheral interface (SPI1)
  */

typedef struct {                                /*!< SPI1 Structure                                                            */
  __IOM uint32_t  CR1;                          /*!< control register 1                                                        */
  __IOM uint32_t  CR2;                          /*!< control register 2                                                        */
  __IOM uint32_t  SR;                           /*!< status register                                                           */
  __IOM uint32_t  DR;                           /*!< data register                                                             */
} SPI_TypeDef;                                    /*!< Size = 16 (0x10)                                                          */



/* =========================================================================================================================== */
/* ================                                            TSC                                            ================ */
/* =========================================================================================================================== */


/**
  * @brief Touch sensing controller (TSC)
  */

typedef struct {                                /*!< TSC Structure                                                             */
  __IOM uint32_t  TKCR1;                        /*!< Touch key control register 1                                              */
  __IOM uint32_t  TKCR2;                        /*!< Touch key control register 2                                              */
  __IM  uint32_t  TKCNTR;                       /*!< Touch key counter register                                                */
  __IOM uint32_t  TKTSCRR;                      /*!< Touch key Time slot counter pre-loaded register                           */
  __IOM uint32_t  TKIER;                        /*!< Touch key interrupt enable register                                       */
  __IOM uint32_t  TKSR1;                        /*!< Touch key status register 1                                               */
  __IOM uint32_t  TKSR2;                        /*!< Touch key status register 2                                               */
  __IOM uint32_t  TKENCFGR;                     /*!< Touch key configuration register                                          */
  __IOM uint32_t  TKTHSCFGR;                    /*!< Touch key threshold configuration register                                */
  __IOM uint32_t  TKROCPR;                      /*!< Touch key reference oscillator capacitance register                       */
  __IOM uint32_t  TKK0CPR;                      /*!< Touch key Key0 Capacitance register                                       */
  __IOM uint32_t  TKK1CPR;                      /*!< Touch key Key1 Capacitance register                                       */
  __IOM uint32_t  TKK2CPR;                      /*!< Touch key Key2 Capacitance register                                       */
  __IOM uint32_t  TKK3CPR;                      /*!< Touch key Key3 Capacitance register                                       */
  __IOM uint32_t  TKK4CPR;                      /*!< Touch key Key4 Capacitance register                                       */
  __IOM uint32_t  TKK5CPR;                      /*!< Touch key Key5 Capacitance register                                       */
  __IOM uint32_t  TKK6CPR;                      /*!< Touch key Key6 Capacitance register                                       */
  __IOM uint32_t  TKK7CPR;                      /*!< Touch key Key7 Capacitance register                                       */
  __IOM uint32_t  TKK8CPR;                      /*!< Touch key Key8 Capacitance register                                       */
  __IOM uint32_t  TKK9CPR;                      /*!< Touch key Key9 Capacitance register                                       */
  __IOM uint32_t  TKKACPR;                      /*!< Touch key KeyA Capacitance register                                       */
  __IOM uint32_t  TKKBCPR;                      /*!< Touch key KeyB Capacitance register                                       */
  __IOM uint32_t  TKKCCPR;                      /*!< Touch key KeyC Capacitance register                                       */
  __IOM uint32_t  TKKDCPR;                      /*!< Touch key KeyD Capacitance register                                       */
  __IOM uint32_t  TKKECPR;                      /*!< Touch key KeyE Capacitance register                                       */
  __IOM uint32_t  TKKFCPR;                      /*!< Touch key KeyF Capacitance register                                       */
  __IM  uint32_t  TKCFCNTR;                     /*!< Touch key C/F counter register                                            */
  __IM  uint32_t  TKK0CNTR;                     /*!< Touch key counter register                                                */
  __IM  uint32_t  TKK1CNTR;                     /*!< Touch key counter register                                                */
  __IM  uint32_t  TKK2CNTR;                     /*!< Touch key counter register                                                */
  __IM  uint32_t  TKK3CNTR;                     /*!< Touch key counter register                                                */
  __IM  uint32_t  TKK4CNTR;                     /*!< Touch key counter register                                                */
  __IM  uint32_t  TKK5CNTR;                     /*!< Touch key counter register                                                */
  __IM  uint32_t  TKK6CNTR;                     /*!< Touch key counter register                                                */
  __IM  uint32_t  TKK7CNTR;                     /*!< Touch key counter register                                                */
  __IM  uint32_t  TKK8CNTR;                     /*!< Touch key counter register                                                */
  __IM  uint32_t  TKK9CNTR;                     /*!< Touch key counter register                                                */
  __IM  uint32_t  TKKACNTR;                     /*!< Touch key counter register                                                */
  __IM  uint32_t  TKKBCNTR;                     /*!< Touch key counter register                                                */
  __IM  uint32_t  TKKCCNTR;                     /*!< Touch key counter register                                                */
  __IM  uint32_t  TKKDCNTR;                     /*!< Touch key counter register                                                */
  __IM  uint32_t  TKKECNTR;                     /*!< Touch key counter register                                                */
  __IM  uint32_t  TKKFCNTR;                     /*!< Touch key counter register                                                */
  __IOM uint32_t  TKK0THR;                      /*!< Touch key threshold register                                              */
  __IOM uint32_t  TKK1THR;                      /*!< Touch key threshold register                                              */
  __IOM uint32_t  TKK2THR;                      /*!< Touch key threshold register                                              */
  __IOM uint32_t  TKK3THR;                      /*!< Touch key threshold register                                              */
  __IOM uint32_t  TKK4THR;                      /*!< Touch key threshold register                                              */
  __IOM uint32_t  TKK5THR;                      /*!< Touch key threshold register                                              */
  __IOM uint32_t  TKK6THR;                      /*!< Touch key threshold register                                              */
  __IOM uint32_t  TKK7THR;                      /*!< Touch key threshold register                                              */
  __IOM uint32_t  TKK8THR;                      /*!< Touch key threshold register                                              */
  __IOM uint32_t  TKK9THR;                      /*!< Touch key threshold register                                              */
  __IOM uint32_t  TKKATHR;                      /*!< Touch key threshold register                                              */
  __IOM uint32_t  TKKBTHR;                      /*!< Touch key threshold register                                              */
  __IOM uint32_t  TKKCTHR;                      /*!< Touch key threshold register                                              */
  __IOM uint32_t  TKKDTHR;                      /*!< Touch key threshold register                                              */
  __IOM uint32_t  TKKETHR;                      /*!< Touch key threshold register                                              */
  __IOM uint32_t  TKKFTHR;                      /*!< Touch key threshold register                                              */
} TSC_TypeDef;                                     /*!< Size = 236 (0xec)                                                         */



/* =========================================================================================================================== */
/* ================                                           TEST                                            ================ */
/* =========================================================================================================================== */


/**
  * @brief TEST support (TEST)
  */

typedef struct {                                /*!< TEST Structure                                                            */
  __IOM uint32_t  TEST_MODER;                   /*!< TEST Mode Register                                                        */
  __IOM uint32_t  TEST_TRIMR1;                  /*!< TEST Trim Register1                                                       */
  __IOM uint32_t  TEST_TRIMR2;                  /*!< TEST Trim Register2                                                       */
} TEST_TypeDef;                                    /*!< Size = 12 (0xc)                                                           */


/** @} */ /* End of group Device_Peripheral_peripherals */


/* =========================================================================================================================== */
/* ================                          Device Specific Peripheral Address Map                           ================ */
/* =========================================================================================================================== */


/** @addtogroup Device_Peripheral_peripheralAddr
  * @{
  */

#define FLASH_BASE                  0x40022000UL
#define PWR_BASE                    0x40007000UL
#define RCC_BASE                    0x40021000UL
#define GPIOA_BASE                  0x48000000UL
#define GPIOB_BASE                  0x48000400UL
#define GPIOC_BASE                  0x48000800UL
#define GPIOF_BASE                  0x48001400UL
#define SYSCFG_BASE                 0x40010000UL
#define DMA_BASE                    0x40020000UL
#define DMA_CHANNEL1_BASE           0x40020008UL
#define DMA_CHANNEL2_BASE           0x4002001CUL
#define DMA_CHANNEL3_BASE           0x40020030UL
#define DMA_CHANNEL4_BASE           0x40020044UL
#define DMA_CHANNEL5_BASE           0x40020058UL
#define EXTI_BASE                   0x40010400UL
#define ADC_BASE                    0x40012400UL
#define COMP1_BASE                  0x40010200UL
#define COMP2_BASE                  0x40010210UL
#define COMP3_BASE                  0x40010220UL
#define COMP4_BASE                  0x40010230UL
#define LED_BASE                    0x40002400UL
#define VREFBUF_BASE                0x40010030UL
#define CRC_BASE                    0x40023000UL
#define I2C1_BASE                   0x40005400UL
#define I2C2_BASE                   0x40005800UL
#define UART1_BASE                  0x40013800UL
#define UART2_BASE                  0x40004400UL
#define WWDG_BASE                   0x40002C00UL
#define IWDG_BASE                   0x40003000UL
#define RTC_BASE                    0x40002800UL
#define LPTIM_BASE                  0x40007C00UL
#define TIM1_BASE                   0x40012C00UL
#define TIM3_BASE                   0x40000400UL
#define TIM6_BASE                   0x40001000UL
#define TIM14_BASE                  0x40002000UL
#define TIM15_BASE                  0x40014000UL
#define TIM16_BASE                  0x40014400UL
#define TIM17_BASE                  0x40014800UL
#define DBGMCU_BASE                 0x40015800UL
#define SPI1_BASE                   0x40013000UL
#define SPI2_BASE                   0x40003800UL
#define TSC_BASE                    0x40024000UL
#define TEST_BASE                   0x40011400UL

/** @} */ /* End of group Device_Peripheral_peripheralAddr */


/* =========================================================================================================================== */
/* ================                                  Peripheral declaration                                   ================ */
/* =========================================================================================================================== */


/** @addtogroup Device_Peripheral_declaration
  * @{
  */

#define FLASH                       ((FLASH_TypeDef*)             FLASH_BASE)
#define PWR                         ((PWR_TypeDef*)               PWR_BASE)
#define RCC                         ((RCC_TypeDef*)               RCC_BASE)
#define GPIOA                       ((GPIO_TypeDef*)             GPIOA_BASE)
#define GPIOB                       ((GPIO_TypeDef*)             GPIOB_BASE)
#define GPIOC                       ((GPIO_TypeDef*)             GPIOC_BASE)
#define GPIOF                       ((GPIO_TypeDef*)             GPIOF_BASE)
#define SYSCFG                      ((SYSCFG_TypeDef*)            SYSCFG_BASE)
#define DMA                         ((DMA_TypeDef*)               DMA_BASE)
#define DMA_CHANNEL1                ((DMA_CHANNEL_TypeDef*)      DMA_CHANNEL1_BASE)
#define DMA_CHANNEL2                ((DMA_CHANNEL_TypeDef*)      DMA_CHANNEL2_BASE)
#define DMA_CHANNEL3                ((DMA_CHANNEL_TypeDef*)      DMA_CHANNEL3_BASE)
#define DMA_CHANNEL4                ((DMA_CHANNEL_TypeDef*)      DMA_CHANNEL4_BASE)
#define DMA_CHANNEL5                ((DMA_CHANNEL_TypeDef*)      DMA_CHANNEL5_BASE)
#define EXTI                        ((EXTI_TypeDef*)              EXTI_BASE)
#define ADC                         ((ADC_TypeDef*)               ADC_BASE)
#define COMP1                       ((COMP_TypeDef*)             COMP1_BASE)
#define COMP2                       ((COMP_TypeDef*)             COMP2_BASE)
#define COMP3                       ((COMP_TypeDef*)             COMP3_BASE)
#define COMP4                       ((COMP_TypeDef*)             COMP4_BASE)
#define LED                         ((LED_TypeDef*)               LED_BASE)
#define VREFBUF                     ((VREFBUF_TypeDef*)           VREFBUF_BASE)
#define CRC                         ((CRC_TypeDef*)               CRC_BASE)
#define I2C1                        ((I2C_TypeDef*)              I2C1_BASE)
#define I2C2                        ((I2C_TypeDef*)              I2C2_BASE)
#define UART1                       ((UART_TypeDef*)             UART1_BASE)
#define UART2                       ((UART_TypeDef*)             UART2_BASE)
#define WWDG                        ((WWDG_TypeDef*)              WWDG_BASE)
#define IWDG                        ((IWDG_TypeDef*)              IWDG_BASE)
#define RTC                         ((RTC_TypeDef*)               RTC_BASE)
#define LPTIM                       ((LPTIM_TypeDef*)             LPTIM_BASE)
#define TIM1                        ((TIM_TypeDef*)              TIM1_BASE)
#define TIM3                        ((TIM_TypeDef*)              TIM3_BASE)
#define TIM6                        ((TIM_TypeDef*)              TIM6_BASE)
#define TIM14                       ((TIM_TypeDef*)             TIM14_BASE)
#define TIM15                       ((TIM_TypeDef*)             TIM15_BASE)
#define TIM16                       ((TIM_TypeDef*)             TIM16_BASE)
#define TIM17                       ((TIM_TypeDef*)             TIM17_BASE)
#define DBGMCU                      ((DBGMCU_TypeDef*)            DBGMCU_BASE)
#define SPI1                        ((SPI_TypeDef*)              SPI1_BASE)
#define SPI2                        ((SPI_TypeDef*)              SPI2_BASE)
#define TSC                         ((TSC_TypeDef*)               TSC_BASE)
#define TEST                        ((TEST_TypeDef*)              TEST_BASE)

/** @} */ /* End of group Device_Peripheral_declaration */


/* =========================================  End of section using anonymous unions  ========================================= */
#if defined (__CC_ARM)
  #pragma pop
#elif defined (__ICCARM__)
  /* leave anonymous unions enabled */
#elif defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
  #pragma clang diagnostic pop
#elif defined (__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined (__TMS470__)
  /* anonymous unions are enabled by default */
#elif defined (__TASKING__)
  #pragma warning restore
#elif defined (__CSMC__)
  /* anonymous unions are enabled by default */
#endif


/* =========================================================================================================================== */
/* ================                                Pos/Mask Peripheral Section                                ================ */
/* =========================================================================================================================== */


/** @addtogroup PosMask_peripherals
  * @{
  */



/* =========================================================================================================================== */
/* ================                                           FLASH                                           ================ */
/* =========================================================================================================================== */

/* ==========================================================  ACR  ========================================================== */
#define FLASH_ACR_LATENCY_Pos             (0UL)                     /*!< LATENCY (Bit 0)                                       */
#define FLASH_ACR_LATENCY_Msk             (0x3UL)                   /*!< LATENCY (Bitfield-Mask: 0x03)                         */
#define FLASH_ACR_LATENCY                 (0x3UL)                   /*!< LATENCY (Bitfield-Mask: 0x03)                         */
/* =========================================================  KEYR  ========================================================== */
#define FLASH_KEYR_KEY_Pos                (0UL)                     /*!< KEY (Bit 0)                                           */
#define FLASH_KEYR_KEY_Msk                (0xffffffffUL)            /*!< KEY (Bitfield-Mask: 0xffffffff)                       */
#define FLASH_KEYR_KEY                    (0xffffffffUL)            /*!< KEY (Bitfield-Mask: 0xffffffff)                       */
/* ========================================================  OPTKEYR  ======================================================== */
#define FLASH_OPTKEYR_OPTKEY_Pos          (0UL)                     /*!< OPTKEY (Bit 0)                                        */
#define FLASH_OPTKEYR_OPTKEY_Msk          (0xffffffffUL)            /*!< OPTKEY (Bitfield-Mask: 0xffffffff)                    */
#define FLASH_OPTKEYR_OPTKEY              (0xffffffffUL)            /*!< OPTKEY (Bitfield-Mask: 0xffffffff)                    */
/* ==========================================================  SR  =========================================================== */
#define FLASH_SR_BSY_Pos                  (16UL)                    /*!< BSY (Bit 16)                                          */
#define FLASH_SR_BSY_Msk                  (0x10000UL)               /*!< BSY (Bitfield-Mask: 0x01)                             */
#define FLASH_SR_BSY                      (0x10000UL)               /*!< BSY (Bitfield-Mask: 0x01)                             */
#define FLASH_SR_OPTVERR_Pos              (15UL)                    /*!< OPTVERR (Bit 15)                                      */
#define FLASH_SR_OPTVERR_Msk              (0x8000UL)                /*!< OPTVERR (Bitfield-Mask: 0x01)                         */
#define FLASH_SR_OPTVERR                  (0x8000UL)                /*!< OPTVERR (Bitfield-Mask: 0x01)                         */
#define FLASH_SR_WRPERR_Pos               (4UL)                     /*!< WRPERR (Bit 4)                                        */
#define FLASH_SR_WRPERR_Msk               (0x10UL)                  /*!< WRPERR (Bitfield-Mask: 0x01)                          */
#define FLASH_SR_WRPERR                   (0x10UL)                  /*!< WRPERR (Bitfield-Mask: 0x01)                          */
#define FLASH_SR_EOP_Pos                  (0UL)                     /*!< EOP (Bit 0)                                           */
#define FLASH_SR_EOP_Msk                  (0x1UL)                   /*!< EOP (Bitfield-Mask: 0x01)                             */
#define FLASH_SR_EOP                      (0x1UL)                   /*!< EOP (Bitfield-Mask: 0x01)                             */
/* ==========================================================  CR  =========================================================== */
#define FLASH_CR_LOCK_Pos                 (31UL)                    /*!< LOCK (Bit 31)                                         */
#define FLASH_CR_LOCK_Msk                 (0x80000000UL)            /*!< LOCK (Bitfield-Mask: 0x01)                            */
#define FLASH_CR_LOCK                     (0x80000000UL)            /*!< LOCK (Bitfield-Mask: 0x01)                            */
#define FLASH_CR_OPTLOCK_Pos              (30UL)                    /*!< OPTLOCK (Bit 30)                                      */
#define FLASH_CR_OPTLOCK_Msk              (0x40000000UL)            /*!< OPTLOCK (Bitfield-Mask: 0x01)                         */
#define FLASH_CR_OPTLOCK                  (0x40000000UL)            /*!< OPTLOCK (Bitfield-Mask: 0x01)                         */
#define FLASH_CR_OBL_LAUNCH_Pos           (27UL)                    /*!< OBL_LAUNCH (Bit 27)                                   */
#define FLASH_CR_OBL_LAUNCH_Msk           (0x8000000UL)             /*!< OBL_LAUNCH (Bitfield-Mask: 0x01)                      */
#define FLASH_CR_OBL_LAUNCH               (0x8000000UL)             /*!< OBL_LAUNCH (Bitfield-Mask: 0x01)                      */
#define FLASH_CR_ERRIE_Pos                (25UL)                    /*!< ERRIE (Bit 25)                                        */
#define FLASH_CR_ERRIE_Msk                (0x2000000UL)             /*!< ERRIE (Bitfield-Mask: 0x01)                           */
#define FLASH_CR_ERRIE                    (0x2000000UL)             /*!< ERRIE (Bitfield-Mask: 0x01)                           */
#define FLASH_CR_EOPIE_Pos                (24UL)                    /*!< EOPIE (Bit 24)                                        */
#define FLASH_CR_EOPIE_Msk                (0x1000000UL)             /*!< EOPIE (Bitfield-Mask: 0x01)                           */
#define FLASH_CR_EOPIE                    (0x1000000UL)             /*!< EOPIE (Bitfield-Mask: 0x01)                           */
#define FLASH_CR_PGSTRT_Pos               (19UL)                    /*!< PGSTRT (Bit 19)                                       */
#define FLASH_CR_PGSTRT_Msk               (0x80000UL)               /*!< PGSTRT (Bitfield-Mask: 0x01)                          */
#define FLASH_CR_PGSTRT                   (0x80000UL)               /*!< PGSTRT (Bitfield-Mask: 0x01)                          */
#define FLASH_CR_OPTSTRT_Pos              (17UL)                    /*!< OPTSTRT (Bit 17)                                      */
#define FLASH_CR_OPTSTRT_Msk              (0x20000UL)               /*!< OPTSTRT (Bitfield-Mask: 0x01)                         */
#define FLASH_CR_OPTSTRT                  (0x20000UL)               /*!< OPTSTRT (Bitfield-Mask: 0x01)                         */
#define FLASH_CR_SER_Pos                  (11UL)                    /*!< SER (Bit 11)                                          */
#define FLASH_CR_SER_Msk                  (0x800UL)                 /*!< SER (Bitfield-Mask: 0x01)                             */
#define FLASH_CR_SER                      (0x800UL)                 /*!< SER (Bitfield-Mask: 0x01)                             */
#define FLASH_CR_MER_Pos                  (2UL)                     /*!< MER (Bit 2)                                           */
#define FLASH_CR_MER_Msk                  (0x4UL)                   /*!< MER (Bitfield-Mask: 0x01)                             */
#define FLASH_CR_MER                      (0x4UL)                   /*!< MER (Bitfield-Mask: 0x01)                             */
#define FLASH_CR_PER_Pos                  (1UL)                     /*!< PER (Bit 1)                                           */
#define FLASH_CR_PER_Msk                  (0x2UL)                   /*!< PER (Bitfield-Mask: 0x01)                             */
#define FLASH_CR_PER                      (0x2UL)                   /*!< PER (Bitfield-Mask: 0x01)                             */
#define FLASH_CR_PG_Pos                   (0UL)                     /*!< PG (Bit 0)                                            */
#define FLASH_CR_PG_Msk                   (0x1UL)                   /*!< PG (Bitfield-Mask: 0x01)                              */
#define FLASH_CR_PG                       (0x1UL)                   /*!< PG (Bitfield-Mask: 0x01)                              */
/* =========================================================  OPTR  ========================================================== */
#define FLASH_OPTR_nBOOT1_Pos             (15UL)                    /*!< nBOOT1 (Bit 15)                                       */
#define FLASH_OPTR_nBOOT1_Msk             (0x8000UL)                /*!< nBOOT1 (Bitfield-Mask: 0x01)                          */
#define FLASH_OPTR_nBOOT1                 (0x8000UL)                /*!< nBOOT1 (Bitfield-Mask: 0x01)                          */
#define FLASH_OPTR_NRST_MODE_Pos          (14UL)                    /*!< NRST_MODE (Bit 14)                                    */
#define FLASH_OPTR_NRST_MODE_Msk          (0x4000UL)                /*!< NRST_MODE (Bitfield-Mask: 0x01)                       */
#define FLASH_OPTR_NRST_MODE              (0x4000UL)                /*!< NRST_MODE (Bitfield-Mask: 0x01)                       */
#define FLASH_OPTR_WWDG_SW_Pos            (13UL)                    /*!< WWDG_SW (Bit 13)                                      */
#define FLASH_OPTR_WWDG_SW_Msk            (0x2000UL)                /*!< WWDG_SW (Bitfield-Mask: 0x01)                         */
#define FLASH_OPTR_WWDG_SW                (0x2000UL)                /*!< WWDG_SW (Bitfield-Mask: 0x01)                         */
#define FLASH_OPTR_BOR_LEV_Pos            (9UL)                     /*!< BOR_LEV (Bit 9)                                       */
#define FLASH_OPTR_BOR_LEV_Msk            (0xe00UL)                 /*!< BOR_LEV (Bitfield-Mask: 0x07)                         */
#define FLASH_OPTR_BOR_LEV                (0xe00UL)                 /*!< BOR_LEV (Bitfield-Mask: 0x07)                         */
#define FLASH_OPTR_IWDG_SW_Pos            (12UL)                    /*!< IWDG_SW (Bit 12)                                      */
#define FLASH_OPTR_IWDG_SW_Msk            (0x1000UL)                /*!< IWDG_SW (Bitfield-Mask: 0x01)                         */
#define FLASH_OPTR_IWDG_SW                (0x1000UL)                /*!< IWDG_SW (Bitfield-Mask: 0x01)                         */
#define FLASH_OPTR_BOR_EN_Pos             (8UL)                     /*!< BOR_EN (Bit 8)                                        */
#define FLASH_OPTR_BOR_EN_Msk             (0x100UL)                 /*!< BOR_EN (Bitfield-Mask: 0x01)                          */
#define FLASH_OPTR_BOR_EN                 (0x100UL)                 /*!< BOR_EN (Bitfield-Mask: 0x01)                          */
#define FLASH_OPTR_RDP_Pos                (0UL)                     /*!< RDP (Bit 0)                                           */
#define FLASH_OPTR_RDP_Msk                (0xffUL)                  /*!< RDP (Bitfield-Mask: 0xff)                             */
#define FLASH_OPTR_RDP                    (0xffUL)                  /*!< RDP (Bitfield-Mask: 0xff)                             */
/* ========================================================  PCROPR  ========================================================= */
#define FLASH_PCROPR_PCROP_END_Pos        (8UL)                     /*!< PCROP_END (Bit 8)                                     */
#define FLASH_PCROPR_PCROP_END_Msk        (0x1f00UL)                /*!< PCROP_END (Bitfield-Mask: 0x1f)                       */
#define FLASH_PCROPR_PCROP_END            (0x1f00UL)                /*!< PCROP_END (Bitfield-Mask: 0x1f)                       */
#define FLASH_PCROPR_PCROP_STRT_Pos       (0UL)                     /*!< PCROP_STRT (Bit 0)                                    */
#define FLASH_PCROPR_PCROP_STRT_Msk       (0x1fUL)                  /*!< PCROP_STRT (Bitfield-Mask: 0x1f)                      */
#define FLASH_PCROPR_PCROP_STRT           (0x1fUL)                  /*!< PCROP_STRT (Bitfield-Mask: 0x1f)                      */
/* =========================================================  WRPR  ========================================================== */
#define FLASH_WRPR_WRP_Pos                (0UL)                     /*!< WRP (Bit 0)                                           */
#define FLASH_WRPR_WRP_Msk                (0x7fffUL)                /*!< WRP (Bitfield-Mask: 0x7fff)                           */
#define FLASH_WRPR_WRP                    (0x7fffUL)                /*!< WRP (Bitfield-Mask: 0x7fff)                           */
/* =========================================================  SEQ0  ========================================================== */
#define FLASH_SEQ0_SEQ0_Pos               (0UL)                     /*!< SEQ0 (Bit 0)                                          */
#define FLASH_SEQ0_SEQ0_Msk               (0x1ffUL)                 /*!< SEQ0 (Bitfield-Mask: 0x1ff)                           */
#define FLASH_SEQ0_SEQ0                   (0x1ffUL)                 /*!< SEQ0 (Bitfield-Mask: 0x1ff)                           */
/* =========================================================  SEQ1  ========================================================== */
#define FLASH_SEQ1_SEQ1_Pos               (0UL)                     /*!< SEQ1 (Bit 0)                                          */
#define FLASH_SEQ1_SEQ1_Msk               (0x3ffUL)                 /*!< SEQ1 (Bitfield-Mask: 0x3ff)                           */
#define FLASH_SEQ1_SEQ1                   (0x3ffUL)                 /*!< SEQ1 (Bitfield-Mask: 0x3ff)                           */
/* ========================================================  SEQ2P1  ========================================================= */
#define FLASH_SEQ2P1_SEQ2P1_Pos           (0UL)                     /*!< SEQ2P1 (Bit 0)                                        */
#define FLASH_SEQ2P1_SEQ2P1_Msk           (0xffUL)                  /*!< SEQ2P1 (Bitfield-Mask: 0xff)                          */
#define FLASH_SEQ2P1_SEQ2P1               (0xffUL)                  /*!< SEQ2P1 (Bitfield-Mask: 0xff)                          */
/* ========================================================  SEQ2P3  ========================================================= */
#define FLASH_SEQ2P3_SEQ2P3_Pos           (0UL)                     /*!< SEQ2P3 (Bit 0)                                        */
#define FLASH_SEQ2P3_SEQ2P3_Msk           (0xfffUL)                 /*!< SEQ2P3 (Bitfield-Mask: 0xfff)                         */
#define FLASH_SEQ2P3_SEQ2P3               (0xfffUL)                 /*!< SEQ2P3 (Bitfield-Mask: 0xfff)                         */
/* =========================================================  SEQ3  ========================================================== */
#define FLASH_SEQ3_SEQ3_Pos               (0UL)                     /*!< SEQ3 (Bit 0)                                          */
#define FLASH_SEQ3_SEQ3_Msk               (0xffUL)                  /*!< SEQ3 (Bitfield-Mask: 0xff)                            */
#define FLASH_SEQ3_SEQ3                   (0xffUL)                  /*!< SEQ3 (Bitfield-Mask: 0xff)                            */
/* =====================================================  PREPG_SEQ2P2  ====================================================== */
#define FLASH_PREPG_SEQ2P2_PREPG_SEQ2P2_Pos (0UL)                   /*!< PREPG_SEQ2P2 (Bit 0)                                  */
#define FLASH_PREPG_SEQ2P2_PREPG_SEQ2P2_Msk (0xffffUL)              /*!< PREPG_SEQ2P2 (Bitfield-Mask: 0xffff)                  */
#define FLASH_PREPG_SEQ2P2_PREPG_SEQ2P2     (0xffffUL)              /*!< PREPG_SEQ2P2 (Bitfield-Mask: 0xffff)                  */
/* =======================================================  PE_SEQ2P2  ======================================================= */
#define FLASH_PE_SEQ2P2_PE_SEQ2P2_Pos     (0UL)                     /*!< PE_SEQ2P2 (Bit 0)                                     */
#define FLASH_PE_SEQ2P2_PE_SEQ2P2_Msk     (0x1ffffUL)               /*!< PE_SEQ2P2 (Bitfield-Mask: 0x1ffff)                    */
#define FLASH_PE_SEQ2P2_PE_SEQ2P2         (0x1ffffUL)               /*!< PE_SEQ2P2 (Bitfield-Mask: 0x1ffff)                    */
/* ======================================================  SME_SEQ2P2  ======================================================= */
#define FLASH_SME_SEQ2P2_SME_SEQ2P2_Pos   (0UL)                     /*!< SME_SEQ2P2 (Bit 0)                                    */
#define FLASH_SME_SEQ2P2_SME_SEQ2P2_Msk   (0x1ffffUL)               /*!< SME_SEQ2P2 (Bitfield-Mask: 0x1ffff)                   */
#define FLASH_SME_SEQ2P2_SME_SEQ2P2       (0x1ffffUL)               /*!< SME_SEQ2P2 (Bitfield-Mask: 0x1ffff)                   */
/* =======================================================  PP_SEQ2P2  ======================================================= */
#define FLASH_PP_SEQ2P2_PP_SEQ2P2_Pos     (0UL)                     /*!< PP_SEQ2P2 (Bit 0)                                     */
#define FLASH_PP_SEQ2P2_PP_SEQ2P2_Msk     (0x1ffffUL)               /*!< PP_SEQ2P2 (Bitfield-Mask: 0x1ffff)                    */
#define FLASH_PP_SEQ2P2_PP_SEQ2P2         (0x1ffffUL)               /*!< PP_SEQ2P2 (Bitfield-Mask: 0x1ffff)                    */
/* ======================================================  SMP_SEQ2P2  ======================================================= */
#define FLASH_SMP_SEQ2P2_SME_SEQ2P2_Pos   (0UL)                     /*!< SME_SEQ2P2 (Bit 0)                                    */
#define FLASH_SMP_SEQ2P2_SME_SEQ2P2_Msk   (0x1ffffUL)               /*!< SME_SEQ2P2 (Bitfield-Mask: 0x1ffff)                   */
#define FLASH_SMP_SEQ2P2_SME_SEQ2P2       (0x1ffffUL)               /*!< SME_SEQ2P2 (Bitfield-Mask: 0x1ffff)                   */


/* =========================================================================================================================== */
/* ================                                            PWR                                            ================ */
/* =========================================================================================================================== */

/* ==========================================================  CR1  ========================================================== */
#define PWR_CR1_CPU_HALT_Pos              (20UL)                    /*!< CPU_HALT (Bit 20)                                     */
#define PWR_CR1_CPU_HALT_Msk              (0x100000UL)              /*!< CPU_HALT (Bitfield-Mask: 0x01)                        */
#define PWR_CR1_CPU_HALT                  (0x100000UL)              /*!< CPU_HALT (Bitfield-Mask: 0x01)                        */
#define PWR_CR1_HSION_CFG_Pos             (19UL)                    /*!< HSION_CFG (Bit 19)                                    */
#define PWR_CR1_HSION_CFG_Msk             (0x80000UL)               /*!< HSION_CFG (Bitfield-Mask: 0x01)                       */
#define PWR_CR1_HSION_CFG                 (0x80000UL)               /*!< HSION_CFG (Bitfield-Mask: 0x01)                       */
#define PWR_CR1_LPR_Pos                   (14UL)                    /*!< LPR (Bit 14)                                          */
#define PWR_CR1_LPR_Msk                   (0x4000UL)                /*!< LPR (Bitfield-Mask: 0x01)                             */
#define PWR_CR1_LPR                       (0x4000UL)                /*!< LPR (Bitfield-Mask: 0x01)                             */
#define PWR_CR1_FLS_TURBO_Pos             (12UL)                    /*!< FLS_TURBO (Bit 12)                                    */
#define PWR_CR1_FLS_TURBO_Msk             (0x1000UL)                /*!< FLS_TURBO (Bitfield-Mask: 0x01)                       */
#define PWR_CR1_FLS_TURBO                 (0x1000UL)                /*!< FLS_TURBO (Bitfield-Mask: 0x01)                       */
#define PWR_CR1_VOS_Pos                   (9UL)                     /*!< VOS (Bit 9)                                           */
#define PWR_CR1_VOS_Msk                   (0x200UL)                 /*!< VOS (Bitfield-Mask: 0x01)                             */
#define PWR_CR1_VOS                       (0x200UL)                 /*!< VOS (Bitfield-Mask: 0x01)                             */
#define PWR_CR1_DBP_Pos                   (8UL)                     /*!< DBP (Bit 8)                                           */
#define PWR_CR1_DBP_Msk                   (0x100UL)                 /*!< DBP (Bitfield-Mask: 0x01)                             */
#define PWR_CR1_DBP                       (0x100UL)                 /*!< DBP (Bitfield-Mask: 0x01)                             */
#define PWR_CR1_BIAS_CR_SEL_Pos           (4UL)                     /*!< BIAS_CR_SEL (Bit 4)                                   */
#define PWR_CR1_BIAS_CR_SEL_Msk           (0x10UL)                  /*!< BIAS_CR_SEL (Bitfield-Mask: 0x01)                     */
#define PWR_CR1_BIAS_CR_SEL               (0x10UL)                  /*!< BIAS_CR_SEL (Bitfield-Mask: 0x01)                     */
#define PWR_CR1_BIAS_CR_Pos               (0UL)                     /*!< BIAS_CR (Bit 0)                                       */
#define PWR_CR1_BIAS_CR_Msk               (0xfUL)                   /*!< BIAS_CR (Bitfield-Mask: 0x0f)                         */
#define PWR_CR1_BIAS_CR                   (0xfUL)                   /*!< BIAS_CR (Bitfield-Mask: 0x0f)                         */
/* ==========================================================  CR2  ========================================================== */
#define PWR_CR2_FLT_TIME_Pos              (9UL)                     /*!< FLT_TIME (Bit 9)                                      */
#define PWR_CR2_FLT_TIME_Msk              (0xe00UL)                 /*!< FLT_TIME (Bitfield-Mask: 0x07)                        */
#define PWR_CR2_FLT_TIME                  (0xe00UL)                 /*!< FLT_TIME (Bitfield-Mask: 0x07)                        */
#define PWR_CR2_FLTEN_Pos                 (8UL)                     /*!< FLTEN (Bit 8)                                         */
#define PWR_CR2_FLTEN_Msk                 (0x100UL)                 /*!< FLTEN (Bitfield-Mask: 0x01)                           */
#define PWR_CR2_FLTEN                     (0x100UL)                 /*!< FLTEN (Bitfield-Mask: 0x01)                           */
#define PWR_CR2_PVDT_Pos                  (4UL)                     /*!< PVDT (Bit 4)                                          */
#define PWR_CR2_PVDT_Msk                  (0x70UL)                  /*!< PVDT (Bitfield-Mask: 0x07)                            */
#define PWR_CR2_PVDT                      (0x70UL)                  /*!< PVDT (Bitfield-Mask: 0x07)                            */
#define PWR_CR2_SRCSEL_Pos                (2UL)                     /*!< SRCSEL (Bit 2)                                        */
#define PWR_CR2_SRCSEL_Msk                (0x4UL)                   /*!< SRCSEL (Bitfield-Mask: 0x01)                          */
#define PWR_CR2_SRCSEL                    (0x4UL)                   /*!< SRCSEL (Bitfield-Mask: 0x01)                          */
#define PWR_CR2_PVDE_Pos                  (0UL)                     /*!< PVDE (Bit 0)                                          */
#define PWR_CR2_PVDE_Msk                  (0x1UL)                   /*!< PVDE (Bitfield-Mask: 0x01)                            */
#define PWR_CR2_PVDE                      (0x1UL)                   /*!< PVDE (Bitfield-Mask: 0x01)                            */
/* ==========================================================  SR  =========================================================== */
#define PWR_SR_PVDO_Pos                   (11UL)                    /*!< PVDO (Bit 11)                                         */
#define PWR_SR_PVDO_Msk                   (0x800UL)                 /*!< PVDO (Bitfield-Mask: 0x01)                            */
#define PWR_SR_PVDO                       (0x800UL)                 /*!< PVDO (Bitfield-Mask: 0x01)                            */


/* =========================================================================================================================== */
/* ================                                            RCC                                            ================ */
/* =========================================================================================================================== */

/* ==========================================================  CR  =========================================================== */
#define RCC_CR_PLLRDY_Pos                 (25UL)                    /*!< PLLRDY (Bit 25)                                       */
#define RCC_CR_PLLRDY_Msk                 (0x2000000UL)             /*!< PLLRDY (Bitfield-Mask: 0x01)                          */
#define RCC_CR_PLLRDY                     (0x2000000UL)             /*!< PLLRDY (Bitfield-Mask: 0x01)                          */
#define RCC_CR_PLLON_Pos                  (24UL)                    /*!< PLLON (Bit 24)                                        */
#define RCC_CR_PLLON_Msk                  (0x1000000UL)             /*!< PLLON (Bitfield-Mask: 0x01)                           */
#define RCC_CR_PLLON                      (0x1000000UL)             /*!< PLLON (Bitfield-Mask: 0x01)                           */
#define RCC_CR_CSSON_Pos                  (19UL)                    /*!< CSSON (Bit 19)                                        */
#define RCC_CR_CSSON_Msk                  (0x80000UL)               /*!< CSSON (Bitfield-Mask: 0x01)                           */
#define RCC_CR_CSSON                      (0x80000UL)               /*!< CSSON (Bitfield-Mask: 0x01)                           */
#define RCC_CR_HSEBYP_Pos                 (18UL)                    /*!< HSEBYP (Bit 18)                                       */
#define RCC_CR_HSEBYP_Msk                 (0x40000UL)               /*!< HSEBYP (Bitfield-Mask: 0x01)                          */
#define RCC_CR_HSEBYP                     (0x40000UL)               /*!< HSEBYP (Bitfield-Mask: 0x01)                          */
#define RCC_CR_HSERDY_Pos                 (17UL)                    /*!< HSERDY (Bit 17)                                       */
#define RCC_CR_HSERDY_Msk                 (0x20000UL)               /*!< HSERDY (Bitfield-Mask: 0x01)                          */
#define RCC_CR_HSERDY                     (0x20000UL)               /*!< HSERDY (Bitfield-Mask: 0x01)                          */
#define RCC_CR_HSEON_Pos                  (16UL)                    /*!< HSEON (Bit 16)                                        */
#define RCC_CR_HSEON_Msk                  (0x10000UL)               /*!< HSEON (Bitfield-Mask: 0x01)                           */
#define RCC_CR_HSEON                      (0x10000UL)               /*!< HSEON (Bitfield-Mask: 0x01)                           */
#define RCC_CR_HSIDIV_Pos                 (11UL)                    /*!< HSIDIV (Bit 11)                                       */
#define RCC_CR_HSIDIV_Msk                 (0x3800UL)                /*!< HSIDIV (Bitfield-Mask: 0x07)                          */
#define RCC_CR_HSIDIV                     (0x3800UL)                /*!< HSIDIV (Bitfield-Mask: 0x07)                          */
#define RCC_CR_HSIRDY_Pos                 (10UL)                    /*!< HSIRDY (Bit 10)                                       */
#define RCC_CR_HSIRDY_Msk                 (0x400UL)                 /*!< HSIRDY (Bitfield-Mask: 0x01)                          */
#define RCC_CR_HSIRDY                     (0x400UL)                 /*!< HSIRDY (Bitfield-Mask: 0x01)                          */
#define RCC_CR_HSION_Pos                  (8UL)                     /*!< HSION (Bit 8)                                         */
#define RCC_CR_HSION_Msk                  (0x100UL)                 /*!< HSION (Bitfield-Mask: 0x01)                           */
#define RCC_CR_HSION                      (0x100UL)                 /*!< HSION (Bitfield-Mask: 0x01)                           */
/* =========================================================  ICSCR  ========================================================= */
#define RCC_ICSCR_LSI_TRIM_Pos            (16UL)                    /*!< LSI_TRIM (Bit 16)                                     */
#define RCC_ICSCR_LSI_TRIM_Msk            (0x7f0000UL)              /*!< LSI_TRIM (Bitfield-Mask: 0x7f)                        */
#define RCC_ICSCR_LSI_TRIM                (0x7f0000UL)              /*!< LSI_TRIM (Bitfield-Mask: 0x7f)                        */
#define RCC_ICSCR_HSI_FS_Pos              (13UL)                    /*!< HSI_FS (Bit 13)                                       */
#define RCC_ICSCR_HSI_FS_Msk              (0x6000UL)                /*!< HSI_FS (Bitfield-Mask: 0x03)                          */
#define RCC_ICSCR_HSI_FS                  (0x6000UL)                /*!< HSI_FS (Bitfield-Mask: 0x03)                          */
#define RCC_ICSCR_HSI_TRIM_Pos            (0UL)                     /*!< HSI_TRIM (Bit 0)                                      */
#define RCC_ICSCR_HSI_TRIM_Msk            (0x7ffUL)                 /*!< HSI_TRIM (Bitfield-Mask: 0x7ff)                       */
#define RCC_ICSCR_HSI_TRIM                (0x7ffUL)                 /*!< HSI_TRIM (Bitfield-Mask: 0x7ff)                       */
/* =========================================================  CFGR  ========================================================== */
#define RCC_CFGR_MCOPRE_Pos               (28UL)                    /*!< MCOPRE (Bit 28)                                       */
#define RCC_CFGR_MCOPRE_Msk               (0x70000000UL)            /*!< MCOPRE (Bitfield-Mask: 0x07)                          */
#define RCC_CFGR_MCOPRE                   (0x70000000UL)            /*!< MCOPRE (Bitfield-Mask: 0x07)                          */
#define RCC_CFGR_MCOSEL_Pos               (24UL)                    /*!< MCOSEL (Bit 24)                                       */
#define RCC_CFGR_MCOSEL_Msk               (0x7000000UL)             /*!< MCOSEL (Bitfield-Mask: 0x07)                          */
#define RCC_CFGR_MCOSEL                   (0x7000000UL)             /*!< MCOSEL (Bitfield-Mask: 0x07)                          */
#define RCC_CFGR_PLLMUL_Pos               (18UL)                    /*!< PLLMUL (Bit 18)                                       */
#define RCC_CFGR_PLLMUL_Msk               (0x40000UL)               /*!< PLLMUL (Bitfield-Mask: 0x01)                          */
#define RCC_CFGR_PLLMUL                   (0x40000UL)               /*!< PLLMUL (Bitfield-Mask: 0x01)                          */
#define RCC_CFGR_PPRE_Pos                 (12UL)                    /*!< PPRE (Bit 12)                                         */
#define RCC_CFGR_PPRE_Msk                 (0x7000UL)                /*!< PPRE (Bitfield-Mask: 0x07)                            */
#define RCC_CFGR_PPRE                     (0x7000UL)                /*!< PPRE (Bitfield-Mask: 0x07)                            */
#define RCC_CFGR_HPRE_Pos                 (8UL)                     /*!< HPRE (Bit 8)                                          */
#define RCC_CFGR_HPRE_Msk                 (0xf00UL)                 /*!< HPRE (Bitfield-Mask: 0x0f)                            */
#define RCC_CFGR_HPRE                     (0xf00UL)                 /*!< HPRE (Bitfield-Mask: 0x0f)                            */
#define RCC_CFGR_SWS_Pos                  (3UL)                     /*!< SWS (Bit 3)                                           */
#define RCC_CFGR_SWS_Msk                  (0x38UL)                  /*!< SWS (Bitfield-Mask: 0x07)                             */
#define RCC_CFGR_SWS                      (0x38UL)                  /*!< SWS (Bitfield-Mask: 0x07)                             */
#define RCC_CFGR_SW_Pos                   (0UL)                     /*!< SW (Bit 0)                                            */
#define RCC_CFGR_SW_Msk                   (0x7UL)                   /*!< SW (Bitfield-Mask: 0x07)                              */
#define RCC_CFGR_SW                       (0x7UL)                   /*!< SW (Bitfield-Mask: 0x07)                              */
/* ========================================================  PLLCFGR  ======================================================== */
#define RCC_PLLCFGR_PLLSRC_Pos            (0UL)                     /*!< PLLSRC (Bit 0)                                        */
#define RCC_PLLCFGR_PLLSRC_Msk            (0x1UL)                   /*!< PLLSRC (Bitfield-Mask: 0x01)                          */
#define RCC_PLLCFGR_PLLSRC                (0x1UL)                   /*!< PLLSRC (Bitfield-Mask: 0x01)                          */
/* =========================================================  ECSCR  ========================================================= */
#define RCC_ECSCR_LSE_DRIVER_Pos          (16UL)                    /*!< LSE_DRIVER (Bit 16)                                   */
#define RCC_ECSCR_LSE_DRIVER_Msk          (0x30000UL)               /*!< LSE_DRIVER (Bitfield-Mask: 0x03)                      */
#define RCC_ECSCR_LSE_DRIVER              (0x30000UL)               /*!< LSE_DRIVER (Bitfield-Mask: 0x03)                      */
#define RCC_ECSCR_HSE_FREQ_Pos            (2UL)                     /*!< HSE_FREQ (Bit 2)                                      */
#define RCC_ECSCR_HSE_FREQ_Msk            (0xcUL)                   /*!< HSE_FREQ (Bitfield-Mask: 0x03)                        */
#define RCC_ECSCR_HSE_FREQ                (0xcUL)                   /*!< HSE_FREQ (Bitfield-Mask: 0x03)                        */
/* =========================================================  CIER  ========================================================== */
#define RCC_CIER_PLLRDYIE_Pos             (5UL)                     /*!< PLLRDYIE (Bit 5)                                      */
#define RCC_CIER_PLLRDYIE_Msk             (0x20UL)                  /*!< PLLRDYIE (Bitfield-Mask: 0x01)                        */
#define RCC_CIER_PLLRDYIE                 (0x20UL)                  /*!< PLLRDYIE (Bitfield-Mask: 0x01)                        */
#define RCC_CIER_HSERDYIE_Pos             (4UL)                     /*!< HSERDYIE (Bit 4)                                      */
#define RCC_CIER_HSERDYIE_Msk             (0x10UL)                  /*!< HSERDYIE (Bitfield-Mask: 0x01)                        */
#define RCC_CIER_HSERDYIE                 (0x10UL)                  /*!< HSERDYIE (Bitfield-Mask: 0x01)                        */
#define RCC_CIER_HSIRDYIE_Pos             (3UL)                     /*!< HSIRDYIE (Bit 3)                                      */
#define RCC_CIER_HSIRDYIE_Msk             (0x8UL)                   /*!< HSIRDYIE (Bitfield-Mask: 0x01)                        */
#define RCC_CIER_HSIRDYIE                 (0x8UL)                   /*!< HSIRDYIE (Bitfield-Mask: 0x01)                        */
#define RCC_CIER_LSERDYIE_Pos             (1UL)                     /*!< LSERDYIE (Bit 1)                                      */
#define RCC_CIER_LSERDYIE_Msk             (0x2UL)                   /*!< LSERDYIE (Bitfield-Mask: 0x01)                        */
#define RCC_CIER_LSERDYIE                 (0x2UL)                   /*!< LSERDYIE (Bitfield-Mask: 0x01)                        */
/* =========================================================  CIFR  ========================================================== */
#define RCC_CIFR_LSECSSF_Pos              (9UL)                     /*!< LSECSSF (Bit 9)                                       */
#define RCC_CIFR_LSECSSF_Msk              (0x200UL)                 /*!< LSECSSF (Bitfield-Mask: 0x01)                         */
#define RCC_CIFR_LSECSSF                  (0x200UL)                 /*!< LSECSSF (Bitfield-Mask: 0x01)                         */
#define RCC_CIFR_CSSF_Pos                 (8UL)                     /*!< CSSF (Bit 8)                                          */
#define RCC_CIFR_CSSF_Msk                 (0x100UL)                 /*!< CSSF (Bitfield-Mask: 0x01)                            */
#define RCC_CIFR_CSSF                     (0x100UL)                 /*!< CSSF (Bitfield-Mask: 0x01)                            */
#define RCC_CIFR_PLLRDYF_Pos              (5UL)                     /*!< PLLRDYF (Bit 5)                                       */
#define RCC_CIFR_PLLRDYF_Msk              (0x20UL)                  /*!< PLLRDYF (Bitfield-Mask: 0x01)                         */
#define RCC_CIFR_PLLRDYF                  (0x20UL)                  /*!< PLLRDYF (Bitfield-Mask: 0x01)                         */
#define RCC_CIFR_HSERDYF_Pos              (4UL)                     /*!< HSERDYF (Bit 4)                                       */
#define RCC_CIFR_HSERDYF_Msk              (0x10UL)                  /*!< HSERDYF (Bitfield-Mask: 0x01)                         */
#define RCC_CIFR_HSERDYF                  (0x10UL)                  /*!< HSERDYF (Bitfield-Mask: 0x01)                         */
#define RCC_CIFR_HSIRDYF_Pos              (3UL)                     /*!< HSIRDYF (Bit 3)                                       */
#define RCC_CIFR_HSIRDYF_Msk              (0x8UL)                   /*!< HSIRDYF (Bitfield-Mask: 0x01)                         */
#define RCC_CIFR_HSIRDYF                  (0x8UL)                   /*!< HSIRDYF (Bitfield-Mask: 0x01)                         */
#define RCC_CIFR_LSERDYF_Pos              (1UL)                     /*!< LSERDYF (Bit 1)                                       */
#define RCC_CIFR_LSERDYF_Msk              (0x2UL)                   /*!< LSERDYF (Bitfield-Mask: 0x01)                         */
#define RCC_CIFR_LSERDYF                  (0x2UL)                   /*!< LSERDYF (Bitfield-Mask: 0x01)                         */
/* =========================================================  CICR  ========================================================== */
#define RCC_CICR_LSECSSC_Pos              (9UL)                     /*!< LSECSSC (Bit 9)                                       */
#define RCC_CICR_LSECSSC_Msk              (0x200UL)                 /*!< LSECSSC (Bitfield-Mask: 0x01)                         */
#define RCC_CICR_LSECSSC                  (0x200UL)                 /*!< LSECSSC (Bitfield-Mask: 0x01)                         */
#define RCC_CICR_CSSC_Pos                 (8UL)                     /*!< CSSC (Bit 8)                                          */
#define RCC_CICR_CSSC_Msk                 (0x100UL)                 /*!< CSSC (Bitfield-Mask: 0x01)                            */
#define RCC_CICR_CSSC                     (0x100UL)                 /*!< CSSC (Bitfield-Mask: 0x01)                            */
#define RCC_CICR_PLLRDYC_Pos              (5UL)                     /*!< PLLRDYC (Bit 5)                                       */
#define RCC_CICR_PLLRDYC_Msk              (0x20UL)                  /*!< PLLRDYC (Bitfield-Mask: 0x01)                         */
#define RCC_CICR_PLLRDYC                  (0x20UL)                  /*!< PLLRDYC (Bitfield-Mask: 0x01)                         */
#define RCC_CICR_HSERDYC_Pos              (4UL)                     /*!< HSERDYC (Bit 4)                                       */
#define RCC_CICR_HSERDYC_Msk              (0x10UL)                  /*!< HSERDYC (Bitfield-Mask: 0x01)                         */
#define RCC_CICR_HSERDYC                  (0x10UL)                  /*!< HSERDYC (Bitfield-Mask: 0x01)                         */
#define RCC_CICR_HSIRDYC_Pos              (3UL)                     /*!< HSIRDYC (Bit 3)                                       */
#define RCC_CICR_HSIRDYC_Msk              (0x8UL)                   /*!< HSIRDYC (Bitfield-Mask: 0x01)                         */
#define RCC_CICR_HSIRDYC                  (0x8UL)                   /*!< HSIRDYC (Bitfield-Mask: 0x01)                         */
#define RCC_CICR_LSERDYC_Pos              (1UL)                     /*!< LSERDYC (Bit 1)                                       */
#define RCC_CICR_LSERDYC_Msk              (0x2UL)                   /*!< LSERDYC (Bitfield-Mask: 0x01)                         */
#define RCC_CICR_LSERDYC                  (0x2UL)                   /*!< LSERDYC (Bitfield-Mask: 0x01)                         */
/* ========================================================  IOPRSTR  ======================================================== */
#define RCC_IOPRSTR_GPIOFRST_Pos          (5UL)                     /*!< GPIOFRST (Bit 5)                                      */
#define RCC_IOPRSTR_GPIOFRST_Msk          (0x20UL)                  /*!< GPIOFRST (Bitfield-Mask: 0x01)                        */
#define RCC_IOPRSTR_GPIOFRST              (0x20UL)                  /*!< GPIOFRST (Bitfield-Mask: 0x01)                        */
#define RCC_IOPRSTR_GPIOCRST_Pos          (2UL)                     /*!< GPIOCRST (Bit 2)                                      */
#define RCC_IOPRSTR_GPIOCRST_Msk          (0x4UL)                   /*!< GPIOCRST (Bitfield-Mask: 0x01)                        */
#define RCC_IOPRSTR_GPIOCRST              (0x4UL)                   /*!< GPIOCRST (Bitfield-Mask: 0x01)                        */
#define RCC_IOPRSTR_GPIOBRST_Pos          (1UL)                     /*!< GPIOBRST (Bit 1)                                      */
#define RCC_IOPRSTR_GPIOBRST_Msk          (0x2UL)                   /*!< GPIOBRST (Bitfield-Mask: 0x01)                        */
#define RCC_IOPRSTR_GPIOBRST              (0x2UL)                   /*!< GPIOBRST (Bitfield-Mask: 0x01)                        */
#define RCC_IOPRSTR_GPIOARST_Pos          (0UL)                     /*!< GPIOARST (Bit 0)                                      */
#define RCC_IOPRSTR_GPIOARST_Msk          (0x1UL)                   /*!< GPIOARST (Bitfield-Mask: 0x01)                        */
#define RCC_IOPRSTR_GPIOARST              (0x1UL)                   /*!< GPIOARST (Bitfield-Mask: 0x01)                        */
/* ========================================================  AHBRSTR  ======================================================== */
#define RCC_AHBRSTR_TSCRST_Pos            (24UL)                    /*!< TSCRST (Bit 24)                                       */
#define RCC_AHBRSTR_TSCRST_Msk            (0x1000000UL)             /*!< TSCRST (Bitfield-Mask: 0x01)                          */
#define RCC_AHBRSTR_TSCRST                (0x1000000UL)             /*!< TSCRST (Bitfield-Mask: 0x01)                          */
#define RCC_AHBRSTR_CRCRST_Pos            (12UL)                    /*!< CRCRST (Bit 12)                                       */
#define RCC_AHBRSTR_CRCRST_Msk            (0x1000UL)                /*!< CRCRST (Bitfield-Mask: 0x01)                          */
#define RCC_AHBRSTR_CRCRST                (0x1000UL)                /*!< CRCRST (Bitfield-Mask: 0x01)                          */
#define RCC_AHBRSTR_DMARST_Pos            (0UL)                     /*!< DMARST (Bit 0)                                        */
#define RCC_AHBRSTR_DMARST_Msk            (0x1UL)                   /*!< DMARST (Bitfield-Mask: 0x01)                          */
#define RCC_AHBRSTR_DMARST                (0x1UL)                   /*!< DMARST (Bitfield-Mask: 0x01)                          */
/* =======================================================  APBRSTR1  ======================================================== */
#define RCC_APBRSTR1_LPTIMRST_Pos         (31UL)                    /*!< LPTIMRST (Bit 31)                                     */
#define RCC_APBRSTR1_LPTIMRST_Msk         (0x80000000UL)            /*!< LPTIMRST (Bitfield-Mask: 0x01)                        */
#define RCC_APBRSTR1_LPTIMRST             (0x80000000UL)            /*!< LPTIMRST (Bitfield-Mask: 0x01)                        */
#define RCC_APBRSTR1_PWRRST_Pos           (28UL)                    /*!< PWRRST (Bit 28)                                       */
#define RCC_APBRSTR1_PWRRST_Msk           (0x10000000UL)            /*!< PWRRST (Bitfield-Mask: 0x01)                          */
#define RCC_APBRSTR1_PWRRST               (0x10000000UL)            /*!< PWRRST (Bitfield-Mask: 0x01)                          */
#define RCC_APBRSTR1_DBGRST_Pos           (27UL)                    /*!< DBGRST (Bit 27)                                       */
#define RCC_APBRSTR1_DBGRST_Msk           (0x8000000UL)             /*!< DBGRST (Bitfield-Mask: 0x01)                          */
#define RCC_APBRSTR1_DBGRST               (0x8000000UL)             /*!< DBGRST (Bitfield-Mask: 0x01)                          */
#define RCC_APBRSTR1_I2C2RST_Pos          (22UL)                    /*!< I2C2RST (Bit 22)                                      */
#define RCC_APBRSTR1_I2C2RST_Msk          (0x400000UL)              /*!< I2C2RST (Bitfield-Mask: 0x01)                         */
#define RCC_APBRSTR1_I2C2RST              (0x400000UL)              /*!< I2C2RST (Bitfield-Mask: 0x01)                         */
#define RCC_APBRSTR1_I2C1RST_Pos          (21UL)                    /*!< I2C1RST (Bit 21)                                      */
#define RCC_APBRSTR1_I2C1RST_Msk          (0x200000UL)              /*!< I2C1RST (Bitfield-Mask: 0x01)                         */
#define RCC_APBRSTR1_I2C1RST              (0x200000UL)              /*!< I2C1RST (Bitfield-Mask: 0x01)                         */
#define RCC_APBRSTR1_UART2RST_Pos         (17UL)                    /*!< UART2RST (Bit 17)                                     */
#define RCC_APBRSTR1_UART2RST_Msk         (0x20000UL)               /*!< UART2RST (Bitfield-Mask: 0x01)                        */
#define RCC_APBRSTR1_UART2RST             (0x20000UL)               /*!< UART2RST (Bitfield-Mask: 0x01)                        */
#define RCC_APBRSTR1_SPI2RST_Pos          (14UL)                    /*!< SPI2RST (Bit 14)                                      */
#define RCC_APBRSTR1_SPI2RST_Msk          (0x4000UL)                /*!< SPI2RST (Bitfield-Mask: 0x01)                         */
#define RCC_APBRSTR1_SPI2RST              (0x4000UL)                /*!< SPI2RST (Bitfield-Mask: 0x01)                         */
#define RCC_APBRSTR1_TIM6RST_Pos          (4UL)                     /*!< TIM6RST (Bit 4)                                       */
#define RCC_APBRSTR1_TIM6RST_Msk          (0x10UL)                  /*!< TIM6RST (Bitfield-Mask: 0x01)                         */
#define RCC_APBRSTR1_TIM6RST              (0x10UL)                  /*!< TIM6RST (Bitfield-Mask: 0x01)                         */
#define RCC_APBRSTR1_TIM3RST_Pos          (1UL)                     /*!< TIM3RST (Bit 1)                                       */
#define RCC_APBRSTR1_TIM3RST_Msk          (0x2UL)                   /*!< TIM3RST (Bitfield-Mask: 0x01)                         */
#define RCC_APBRSTR1_TIM3RST              (0x2UL)                   /*!< TIM3RST (Bitfield-Mask: 0x01)                         */
/* =======================================================  APBRSTR2  ======================================================== */
#define RCC_APBRSTR2_LEDRST_Pos           (23UL)                    /*!< LEDRST (Bit 23)                                       */
#define RCC_APBRSTR2_LEDRST_Msk           (0x800000UL)              /*!< LEDRST (Bitfield-Mask: 0x01)                          */
#define RCC_APBRSTR2_LEDRST               (0x800000UL)              /*!< LEDRST (Bitfield-Mask: 0x01)                          */
#define RCC_APBRSTR2_ADCRST_Pos           (20UL)                    /*!< ADCRST (Bit 20)                                       */
#define RCC_APBRSTR2_ADCRST_Msk           (0x100000UL)              /*!< ADCRST (Bitfield-Mask: 0x01)                          */
#define RCC_APBRSTR2_ADCRST               (0x100000UL)              /*!< ADCRST (Bitfield-Mask: 0x01)                          */
#define RCC_APBRSTR2_TIM17RST_Pos         (18UL)                    /*!< TIM17RST (Bit 18)                                     */
#define RCC_APBRSTR2_TIM17RST_Msk         (0x40000UL)               /*!< TIM17RST (Bitfield-Mask: 0x01)                        */
#define RCC_APBRSTR2_TIM17RST             (0x40000UL)               /*!< TIM17RST (Bitfield-Mask: 0x01)                        */
#define RCC_APBRSTR2_TIM16RST_Pos         (17UL)                    /*!< TIM16RST (Bit 17)                                     */
#define RCC_APBRSTR2_TIM16RST_Msk         (0x20000UL)               /*!< TIM16RST (Bitfield-Mask: 0x01)                        */
#define RCC_APBRSTR2_TIM16RST             (0x20000UL)               /*!< TIM16RST (Bitfield-Mask: 0x01)                        */
#define RCC_APBRSTR2_TIM15RST_Pos         (16UL)                    /*!< TIM15RST (Bit 16)                                     */
#define RCC_APBRSTR2_TIM15RST_Msk         (0x10000UL)               /*!< TIM15RST (Bitfield-Mask: 0x01)                        */
#define RCC_APBRSTR2_TIM15RST             (0x10000UL)               /*!< TIM15RST (Bitfield-Mask: 0x01)                        */
#define RCC_APBRSTR2_TIM14RST_Pos         (15UL)                    /*!< TIM14RST (Bit 15)                                     */
#define RCC_APBRSTR2_TIM14RST_Msk         (0x8000UL)                /*!< TIM14RST (Bitfield-Mask: 0x01)                        */
#define RCC_APBRSTR2_TIM14RST             (0x8000UL)                /*!< TIM14RST (Bitfield-Mask: 0x01)                        */
#define RCC_APBRSTR2_UART1RST_Pos         (14UL)                    /*!< UART1RST (Bit 14)                                     */
#define RCC_APBRSTR2_UART1RST_Msk         (0x4000UL)                /*!< UART1RST (Bitfield-Mask: 0x01)                        */
#define RCC_APBRSTR2_UART1RST             (0x4000UL)                /*!< UART1RST (Bitfield-Mask: 0x01)                        */
#define RCC_APBRSTR2_SPI1RST_Pos          (12UL)                    /*!< SPI1RST (Bit 12)                                      */
#define RCC_APBRSTR2_SPI1RST_Msk          (0x1000UL)                /*!< SPI1RST (Bitfield-Mask: 0x01)                         */
#define RCC_APBRSTR2_SPI1RST              (0x1000UL)                /*!< SPI1RST (Bitfield-Mask: 0x01)                         */
#define RCC_APBRSTR2_TIM1RST_Pos          (11UL)                    /*!< TIM1RST (Bit 11)                                      */
#define RCC_APBRSTR2_TIM1RST_Msk          (0x800UL)                 /*!< TIM1RST (Bitfield-Mask: 0x01)                         */
#define RCC_APBRSTR2_TIM1RST              (0x800UL)                 /*!< TIM1RST (Bitfield-Mask: 0x01)                         */
#define RCC_APBRSTR2_SYSCFGRST_Pos        (0UL)                     /*!< SYSCFGRST (Bit 0)                                     */
#define RCC_APBRSTR2_SYSCFGRST_Msk        (0x1UL)                   /*!< SYSCFGRST (Bitfield-Mask: 0x01)                       */
#define RCC_APBRSTR2_SYSCFGRST            (0x1UL)                   /*!< SYSCFGRST (Bitfield-Mask: 0x01)                       */
/* ========================================================  IOPENR  ========================================================= */
#define RCC_IOPENR_GPIOFEN_Pos            (5UL)                     /*!< GPIOFEN (Bit 5)                                       */
#define RCC_IOPENR_GPIOFEN_Msk            (0x20UL)                  /*!< GPIOFEN (Bitfield-Mask: 0x01)                         */
#define RCC_IOPENR_GPIOFEN                (0x20UL)                  /*!< GPIOFEN (Bitfield-Mask: 0x01)                         */
#define RCC_IOPENR_GPIOCEN_Pos            (2UL)                     /*!< GPIOCEN (Bit 2)                                       */
#define RCC_IOPENR_GPIOCEN_Msk            (0x4UL)                   /*!< GPIOCEN (Bitfield-Mask: 0x01)                         */
#define RCC_IOPENR_GPIOCEN                (0x4UL)                   /*!< GPIOCEN (Bitfield-Mask: 0x01)                         */
#define RCC_IOPENR_GPIOBEN_Pos            (1UL)                     /*!< GPIOBEN (Bit 1)                                       */
#define RCC_IOPENR_GPIOBEN_Msk            (0x2UL)                   /*!< GPIOBEN (Bitfield-Mask: 0x01)                         */
#define RCC_IOPENR_GPIOBEN                (0x2UL)                   /*!< GPIOBEN (Bitfield-Mask: 0x01)                         */
#define RCC_IOPENR_GPIOAEN_Pos            (0UL)                     /*!< GPIOAEN (Bit 0)                                       */
#define RCC_IOPENR_GPIOAEN_Msk            (0x1UL)                   /*!< GPIOAEN (Bitfield-Mask: 0x01)                         */
#define RCC_IOPENR_GPIOAEN                (0x1UL)                   /*!< GPIOAEN (Bitfield-Mask: 0x01)                         */
/* ========================================================  AHBENR  ========================================================= */
#define RCC_AHBENR_TSCEN_Pos              (24UL)                    /*!< TSCEN (Bit 24)                                        */
#define RCC_AHBENR_TSCEN_Msk              (0x1000000UL)             /*!< TSCEN (Bitfield-Mask: 0x01)                           */
#define RCC_AHBENR_TSCEN                  (0x1000000UL)             /*!< TSCEN (Bitfield-Mask: 0x01)                           */
#define RCC_AHBENR_CRCEN_Pos              (12UL)                    /*!< CRCEN (Bit 12)                                        */
#define RCC_AHBENR_CRCEN_Msk              (0x1000UL)                /*!< CRCEN (Bitfield-Mask: 0x01)                           */
#define RCC_AHBENR_CRCEN                  (0x1000UL)                /*!< CRCEN (Bitfield-Mask: 0x01)                           */
#define RCC_AHBENR_DMAEN_Pos              (0UL)                     /*!< DMAEN (Bit 0)                                         */
#define RCC_AHBENR_DMAEN_Msk              (0x1UL)                   /*!< DMAEN (Bitfield-Mask: 0x01)                           */
#define RCC_AHBENR_DMAEN                  (0x1UL)                   /*!< DMAEN (Bitfield-Mask: 0x01)                           */
/* ========================================================  APBENR1  ======================================================== */
#define RCC_APBENR1_LPTIMEN_Pos           (31UL)                    /*!< LPTIMEN (Bit 31)                                      */
#define RCC_APBENR1_LPTIMEN_Msk           (0x80000000UL)            /*!< LPTIMEN (Bitfield-Mask: 0x01)                         */
#define RCC_APBENR1_LPTIMEN               (0x80000000UL)            /*!< LPTIMEN (Bitfield-Mask: 0x01)                         */
#define RCC_APBENR1_PWREN_Pos             (28UL)                    /*!< PWREN (Bit 28)                                        */
#define RCC_APBENR1_PWREN_Msk             (0x10000000UL)            /*!< PWREN (Bitfield-Mask: 0x01)                           */
#define RCC_APBENR1_PWREN                 (0x10000000UL)            /*!< PWREN (Bitfield-Mask: 0x01)                           */
#define RCC_APBENR1_DBGEN_Pos             (27UL)                    /*!< DBGEN (Bit 27)                                        */
#define RCC_APBENR1_DBGEN_Msk             (0x8000000UL)             /*!< DBGEN (Bitfield-Mask: 0x01)                           */
#define RCC_APBENR1_DBGEN                 (0x8000000UL)             /*!< DBGEN (Bitfield-Mask: 0x01)                           */
#define RCC_APBENR1_I2C2EN_Pos            (22UL)                    /*!< I2C2EN (Bit 22)                                       */
#define RCC_APBENR1_I2C2EN_Msk            (0x400000UL)              /*!< I2C2EN (Bitfield-Mask: 0x01)                          */
#define RCC_APBENR1_I2C2EN                (0x400000UL)              /*!< I2C2EN (Bitfield-Mask: 0x01)                          */
#define RCC_APBENR1_I2C1EN_Pos            (21UL)                    /*!< I2C1EN (Bit 21)                                       */
#define RCC_APBENR1_I2C1EN_Msk            (0x200000UL)              /*!< I2C1EN (Bitfield-Mask: 0x01)                          */
#define RCC_APBENR1_I2C1EN                (0x200000UL)              /*!< I2C1EN (Bitfield-Mask: 0x01)                          */
#define RCC_APBENR1_UART2EN_Pos           (17UL)                    /*!< UART2EN (Bit 17)                                      */
#define RCC_APBENR1_UART2EN_Msk           (0x20000UL)               /*!< UART2EN (Bitfield-Mask: 0x01)                         */
#define RCC_APBENR1_UART2EN               (0x20000UL)               /*!< UART2EN (Bitfield-Mask: 0x01)                         */
#define RCC_APBENR1_SPI2EN_Pos            (14UL)                    /*!< SPI2EN (Bit 14)                                       */
#define RCC_APBENR1_SPI2EN_Msk            (0x4000UL)                /*!< SPI2EN (Bitfield-Mask: 0x01)                          */
#define RCC_APBENR1_SPI2EN                (0x4000UL)                /*!< SPI2EN (Bitfield-Mask: 0x01)                          */
#define RCC_APBENR1_IWDGEN_Pos            (12UL)                    /*!< IWDGEN (Bit 12)                                       */
#define RCC_APBENR1_IWDGEN_Msk            (0x1000UL)                /*!< IWDGEN (Bitfield-Mask: 0x01)                          */
#define RCC_APBENR1_IWDGEN                (0x1000UL)                /*!< IWDGEN (Bitfield-Mask: 0x01)                          */
#define RCC_APBENR1_WWDGEN_Pos            (11UL)                    /*!< WWDGEN (Bit 11)                                       */
#define RCC_APBENR1_WWDGEN_Msk            (0x800UL)                 /*!< WWDGEN (Bitfield-Mask: 0x01)                          */
#define RCC_APBENR1_WWDGEN                (0x800UL)                 /*!< WWDGEN (Bitfield-Mask: 0x01)                          */
#define RCC_APBENR1_RTCAPBEN_Pos          (10UL)                    /*!< RTCAPBEN (Bit 10)                                     */
#define RCC_APBENR1_RTCAPBEN_Msk          (0x400UL)                 /*!< RTCAPBEN (Bitfield-Mask: 0x01)                        */
#define RCC_APBENR1_RTCAPBEN              (0x400UL)                 /*!< RTCAPBEN (Bitfield-Mask: 0x01)                        */
#define RCC_APBENR1_TIM6EN_Pos            (4UL)                     /*!< TIM6EN (Bit 4)                                        */
#define RCC_APBENR1_TIM6EN_Msk            (0x10UL)                  /*!< TIM6EN (Bitfield-Mask: 0x01)                          */
#define RCC_APBENR1_TIM6EN                (0x10UL)                  /*!< TIM6EN (Bitfield-Mask: 0x01)                          */
#define RCC_APBENR1_TIM3EN_Pos            (1UL)                     /*!< TIM3EN (Bit 1)                                        */
#define RCC_APBENR1_TIM3EN_Msk            (0x2UL)                   /*!< TIM3EN (Bitfield-Mask: 0x01)                          */
#define RCC_APBENR1_TIM3EN                (0x2UL)                   /*!< TIM3EN (Bitfield-Mask: 0x01)                          */
/* ========================================================  APBENR2  ======================================================== */
#define RCC_APBENR2_COMP4EN_Pos           (25UL)                    /*!< COMP4EN (Bit 25)                                      */
#define RCC_APBENR2_COMP4EN_Msk           (0x2000000UL)             /*!< COMP4EN (Bitfield-Mask: 0x01)                         */
#define RCC_APBENR2_COMP4EN               (0x2000000UL)             /*!< COMP4EN (Bitfield-Mask: 0x01)                         */
#define RCC_APBENR2_COMP3EN_Pos           (24UL)                    /*!< COMP3EN (Bit 24)                                      */
#define RCC_APBENR2_COMP3EN_Msk           (0x1000000UL)             /*!< COMP3EN (Bitfield-Mask: 0x01)                         */
#define RCC_APBENR2_COMP3EN               (0x1000000UL)             /*!< COMP3EN (Bitfield-Mask: 0x01)                         */
#define RCC_APBENR2_LEDEN_Pos             (23UL)                    /*!< LEDEN (Bit 23)                                        */
#define RCC_APBENR2_LEDEN_Msk             (0x800000UL)              /*!< LEDEN (Bitfield-Mask: 0x01)                           */
#define RCC_APBENR2_LEDEN                 (0x800000UL)              /*!< LEDEN (Bitfield-Mask: 0x01)                           */
#define RCC_APBENR2_COMP2EN_Pos           (22UL)                    /*!< COMP2EN (Bit 22)                                      */
#define RCC_APBENR2_COMP2EN_Msk           (0x400000UL)              /*!< COMP2EN (Bitfield-Mask: 0x01)                         */
#define RCC_APBENR2_COMP2EN               (0x400000UL)              /*!< COMP2EN (Bitfield-Mask: 0x01)                         */
#define RCC_APBENR2_COMP1EN_Pos           (21UL)                    /*!< COMP1EN (Bit 21)                                      */
#define RCC_APBENR2_COMP1EN_Msk           (0x200000UL)              /*!< COMP1EN (Bitfield-Mask: 0x01)                         */
#define RCC_APBENR2_COMP1EN               (0x200000UL)              /*!< COMP1EN (Bitfield-Mask: 0x01)                         */
#define RCC_APBENR2_ADCEN_Pos             (20UL)                    /*!< ADCEN (Bit 20)                                        */
#define RCC_APBENR2_ADCEN_Msk             (0x100000UL)              /*!< ADCEN (Bitfield-Mask: 0x01)                           */
#define RCC_APBENR2_ADCEN                 (0x100000UL)              /*!< ADCEN (Bitfield-Mask: 0x01)                           */
#define RCC_APBENR2_TIM17EN_Pos           (18UL)                    /*!< TIM17EN (Bit 18)                                      */
#define RCC_APBENR2_TIM17EN_Msk           (0x40000UL)               /*!< TIM17EN (Bitfield-Mask: 0x01)                         */
#define RCC_APBENR2_TIM17EN               (0x40000UL)               /*!< TIM17EN (Bitfield-Mask: 0x01)                         */
#define RCC_APBENR2_TIM16EN_Pos           (17UL)                    /*!< TIM16EN (Bit 17)                                      */
#define RCC_APBENR2_TIM16EN_Msk           (0x20000UL)               /*!< TIM16EN (Bitfield-Mask: 0x01)                         */
#define RCC_APBENR2_TIM16EN               (0x20000UL)               /*!< TIM16EN (Bitfield-Mask: 0x01)                         */
#define RCC_APBENR2_TIM15EN_Pos           (16UL)                    /*!< TIM15EN (Bit 16)                                      */
#define RCC_APBENR2_TIM15EN_Msk           (0x10000UL)               /*!< TIM15EN (Bitfield-Mask: 0x01)                         */
#define RCC_APBENR2_TIM15EN               (0x10000UL)               /*!< TIM15EN (Bitfield-Mask: 0x01)                         */
#define RCC_APBENR2_TIM14EN_Pos           (15UL)                    /*!< TIM14EN (Bit 15)                                      */
#define RCC_APBENR2_TIM14EN_Msk           (0x8000UL)                /*!< TIM14EN (Bitfield-Mask: 0x01)                         */
#define RCC_APBENR2_TIM14EN               (0x8000UL)                /*!< TIM14EN (Bitfield-Mask: 0x01)                         */
#define RCC_APBENR2_UART1EN_Pos           (14UL)                    /*!< UART1EN (Bit 14)                                      */
#define RCC_APBENR2_UART1EN_Msk           (0x4000UL)                /*!< UART1EN (Bitfield-Mask: 0x01)                         */
#define RCC_APBENR2_UART1EN               (0x4000UL)                /*!< UART1EN (Bitfield-Mask: 0x01)                         */
#define RCC_APBENR2_SPI1EN_Pos            (12UL)                    /*!< SPI1EN (Bit 12)                                       */
#define RCC_APBENR2_SPI1EN_Msk            (0x1000UL)                /*!< SPI1EN (Bitfield-Mask: 0x01)                          */
#define RCC_APBENR2_SPI1EN                (0x1000UL)                /*!< SPI1EN (Bitfield-Mask: 0x01)                          */
#define RCC_APBENR2_TIM1EN_Pos            (11UL)                    /*!< TIM1EN (Bit 11)                                       */
#define RCC_APBENR2_TIM1EN_Msk            (0x800UL)                 /*!< TIM1EN (Bitfield-Mask: 0x01)                          */
#define RCC_APBENR2_TIM1EN                (0x800UL)                 /*!< TIM1EN (Bitfield-Mask: 0x01)                          */
#define RCC_APBENR2_SYSCFGEN_Pos          (0UL)                     /*!< SYSCFGEN (Bit 0)                                      */
#define RCC_APBENR2_SYSCFGEN_Msk          (0x1UL)                   /*!< SYSCFGEN (Bitfield-Mask: 0x01)                        */
#define RCC_APBENR2_SYSCFGEN              (0x1UL)                   /*!< SYSCFGEN (Bitfield-Mask: 0x01)                        */
/* =========================================================  CCIPR  ========================================================= */
#define RCC_CCIPR_LPTIMSEL_Pos            (18UL)                    /*!< LPTIMSEL (Bit 18)                                     */
#define RCC_CCIPR_LPTIMSEL_Msk            (0xc0000UL)               /*!< LPTIMSEL (Bitfield-Mask: 0x03)                        */
#define RCC_CCIPR_LPTIMSEL                (0xc0000UL)               /*!< LPTIMSEL (Bitfield-Mask: 0x03)                        */
#define RCC_CCIPR_COMP4SEL_Pos            (17UL)                    /*!< COMP4SEL (Bit 17)                                     */
#define RCC_CCIPR_COMP4SEL_Msk            (0x20000UL)               /*!< COMP4SEL (Bitfield-Mask: 0x01)                        */
#define RCC_CCIPR_COMP4SEL                (0x20000UL)               /*!< COMP4SEL (Bitfield-Mask: 0x01)                        */
#define RCC_CCIPR_COMP3SEL_Pos            (16UL)                    /*!< COMP3SEL (Bit 16)                                     */
#define RCC_CCIPR_COMP3SEL_Msk            (0x10000UL)               /*!< COMP3SEL (Bitfield-Mask: 0x01)                        */
#define RCC_CCIPR_COMP3SEL                (0x10000UL)               /*!< COMP3SEL (Bitfield-Mask: 0x01)                        */
#define RCC_CCIPR_COMP2SEL_Pos            (9UL)                     /*!< COMP2SEL (Bit 9)                                      */
#define RCC_CCIPR_COMP2SEL_Msk            (0x200UL)                 /*!< COMP2SEL (Bitfield-Mask: 0x01)                        */
#define RCC_CCIPR_COMP2SEL                (0x200UL)                 /*!< COMP2SEL (Bitfield-Mask: 0x01)                        */
#define RCC_CCIPR_COMP1SEL_Pos            (8UL)                     /*!< COMP1SEL (Bit 8)                                      */
#define RCC_CCIPR_COMP1SEL_Msk            (0x100UL)                 /*!< COMP1SEL (Bitfield-Mask: 0x01)                        */
#define RCC_CCIPR_COMP1SEL                (0x100UL)                 /*!< COMP1SEL (Bitfield-Mask: 0x01)                        */
#define RCC_CCIPR_PVDSEL_Pos              (7UL)                     /*!< PVDSEL (Bit 7)                                        */
#define RCC_CCIPR_PVDSEL_Msk              (0x80UL)                  /*!< PVDSEL (Bitfield-Mask: 0x01)                          */
#define RCC_CCIPR_PVDSEL                  (0x80UL)                  /*!< PVDSEL (Bitfield-Mask: 0x01)                          */
/* =========================================================  BDCR  ========================================================== */
#define RCC_BDCR_LSCOSEL_Pos              (25UL)                    /*!< LSCOSEL (Bit 25)                                      */
#define RCC_BDCR_LSCOSEL_Msk              (0x2000000UL)             /*!< LSCOSEL (Bitfield-Mask: 0x01)                         */
#define RCC_BDCR_LSCOSEL                  (0x2000000UL)             /*!< LSCOSEL (Bitfield-Mask: 0x01)                         */
#define RCC_BDCR_LSCOEN_Pos               (24UL)                    /*!< LSCOEN (Bit 24)                                       */
#define RCC_BDCR_LSCOEN_Msk               (0x1000000UL)             /*!< LSCOEN (Bitfield-Mask: 0x01)                          */
#define RCC_BDCR_LSCOEN                   (0x1000000UL)             /*!< LSCOEN (Bitfield-Mask: 0x01)                          */
#define RCC_BDCR_BDRST_Pos                (16UL)                    /*!< BDRST (Bit 16)                                        */
#define RCC_BDCR_BDRST_Msk                (0x10000UL)               /*!< BDRST (Bitfield-Mask: 0x01)                           */
#define RCC_BDCR_BDRST                    (0x10000UL)               /*!< BDRST (Bitfield-Mask: 0x01)                           */
#define RCC_BDCR_RTCEN_Pos                (15UL)                    /*!< RTCEN (Bit 15)                                        */
#define RCC_BDCR_RTCEN_Msk                (0x8000UL)                /*!< RTCEN (Bitfield-Mask: 0x01)                           */
#define RCC_BDCR_RTCEN                    (0x8000UL)                /*!< RTCEN (Bitfield-Mask: 0x01)                           */
#define RCC_BDCR_RTCSEL_Pos               (8UL)                     /*!< RTCSEL (Bit 8)                                        */
#define RCC_BDCR_RTCSEL_Msk               (0x300UL)                 /*!< RTCSEL (Bitfield-Mask: 0x03)                          */
#define RCC_BDCR_RTCSEL                   (0x300UL)                 /*!< RTCSEL (Bitfield-Mask: 0x03)                          */
#define RCC_BDCR_LSECSSD_Pos              (6UL)                     /*!< LSECSSD (Bit 6)                                       */
#define RCC_BDCR_LSECSSD_Msk              (0x40UL)                  /*!< LSECSSD (Bitfield-Mask: 0x01)                         */
#define RCC_BDCR_LSECSSD                  (0x40UL)                  /*!< LSECSSD (Bitfield-Mask: 0x01)                         */
#define RCC_BDCR_LSECSSON_Pos             (5UL)                     /*!< LSECSSON (Bit 5)                                      */
#define RCC_BDCR_LSECSSON_Msk             (0x20UL)                  /*!< LSECSSON (Bitfield-Mask: 0x01)                        */
#define RCC_BDCR_LSECSSON                 (0x20UL)                  /*!< LSECSSON (Bitfield-Mask: 0x01)                        */
#define RCC_BDCR_LSEBYP_Pos               (2UL)                     /*!< LSEBYP (Bit 2)                                        */
#define RCC_BDCR_LSEBYP_Msk               (0x4UL)                   /*!< LSEBYP (Bitfield-Mask: 0x01)                          */
#define RCC_BDCR_LSEBYP                   (0x4UL)                   /*!< LSEBYP (Bitfield-Mask: 0x01)                          */
#define RCC_BDCR_LSERDY_Pos               (1UL)                     /*!< LSERDY (Bit 1)                                        */
#define RCC_BDCR_LSERDY_Msk               (0x2UL)                   /*!< LSERDY (Bitfield-Mask: 0x01)                          */
#define RCC_BDCR_LSERDY                   (0x2UL)                   /*!< LSERDY (Bitfield-Mask: 0x01)                          */
#define RCC_BDCR_LSEON_Pos                (0UL)                     /*!< LSEON (Bit 0)                                         */
#define RCC_BDCR_LSEON_Msk                (0x1UL)                   /*!< LSEON (Bitfield-Mask: 0x01)                           */
#define RCC_BDCR_LSEON                    (0x1UL)                   /*!< LSEON (Bitfield-Mask: 0x01)                           */
/* ==========================================================  CSR  ========================================================== */
#define RCC_CSR_WWDGRSTF_Pos              (30UL)                    /*!< WWDGRSTF (Bit 30)                                     */
#define RCC_CSR_WWDGRSTF_Msk              (0x40000000UL)            /*!< WWDGRSTF (Bitfield-Mask: 0x01)                        */
#define RCC_CSR_WWDGRSTF                  (0x40000000UL)            /*!< WWDGRSTF (Bitfield-Mask: 0x01)                        */
#define RCC_CSR_IWDGRSTF_Pos              (29UL)                    /*!< IWDGRSTF (Bit 29)                                     */
#define RCC_CSR_IWDGRSTF_Msk              (0x20000000UL)            /*!< IWDGRSTF (Bitfield-Mask: 0x01)                        */
#define RCC_CSR_IWDGRSTF                  (0x20000000UL)            /*!< IWDGRSTF (Bitfield-Mask: 0x01)                        */
#define RCC_CSR_SFTRSTF_Pos               (28UL)                    /*!< SFTRSTF (Bit 28)                                      */
#define RCC_CSR_SFTRSTF_Msk               (0x10000000UL)            /*!< SFTRSTF (Bitfield-Mask: 0x01)                         */
#define RCC_CSR_SFTRSTF                   (0x10000000UL)            /*!< SFTRSTF (Bitfield-Mask: 0x01)                         */
#define RCC_CSR_PWRRSTF_Pos               (27UL)                    /*!< PWRRSTF (Bit 27)                                      */
#define RCC_CSR_PWRRSTF_Msk               (0x8000000UL)             /*!< PWRRSTF (Bitfield-Mask: 0x01)                         */
#define RCC_CSR_PWRRSTF                   (0x8000000UL)             /*!< PWRRSTF (Bitfield-Mask: 0x01)                         */
#define RCC_CSR_PINRSTF_Pos               (26UL)                    /*!< PINRSTF (Bit 26)                                      */
#define RCC_CSR_PINRSTF_Msk               (0x4000000UL)             /*!< PINRSTF (Bitfield-Mask: 0x01)                         */
#define RCC_CSR_PINRSTF                   (0x4000000UL)             /*!< PINRSTF (Bitfield-Mask: 0x01)                         */
#define RCC_CSR_OBLRSTF_Pos               (25UL)                    /*!< OBLRSTF (Bit 25)                                      */
#define RCC_CSR_OBLRSTF_Msk               (0x2000000UL)             /*!< OBLRSTF (Bitfield-Mask: 0x01)                         */
#define RCC_CSR_OBLRSTF                   (0x2000000UL)             /*!< OBLRSTF (Bitfield-Mask: 0x01)                         */
#define RCC_CSR_RMVF_Pos                  (23UL)                    /*!< RMVF (Bit 23)                                         */
#define RCC_CSR_RMVF_Msk                  (0x800000UL)              /*!< RMVF (Bitfield-Mask: 0x01)                            */
#define RCC_CSR_RMVF                      (0x800000UL)              /*!< RMVF (Bitfield-Mask: 0x01)                            */
#define RCC_CSR_NRST_FLTDIS_Pos           (8UL)                     /*!< NRST_FLTDIS (Bit 8)                                   */
#define RCC_CSR_NRST_FLTDIS_Msk           (0x100UL)                 /*!< NRST_FLTDIS (Bitfield-Mask: 0x01)                     */
#define RCC_CSR_NRST_FLTDIS               (0x100UL)                 /*!< NRST_FLTDIS (Bitfield-Mask: 0x01)                     */
#define RCC_CSR_CLKRDY_Pos                (2UL)                     /*!< CLKRDY (Bit 2)                                        */
#define RCC_CSR_CLKRDY_Msk                (0x4UL)                   /*!< CLKRDY (Bitfield-Mask: 0x01)                          */
#define RCC_CSR_CLKRDY                    (0x4UL)                   /*!< CLKRDY (Bitfield-Mask: 0x01)                          */
#define RCC_CSR_LSION_Pos                 (0UL)                     /*!< LSION (Bit 0)                                         */
#define RCC_CSR_LSION_Msk                 (0x1UL)                   /*!< LSION (Bitfield-Mask: 0x01)                           */
#define RCC_CSR_LSION                     (0x1UL)                   /*!< LSION (Bitfield-Mask: 0x01)                           */
/* =======================================================  MRTRIM_CR  ======================================================= */
#define RCC_MRTRIM_CR_TVS_Pos             (15UL)                    /*!< TVS (Bit 15)                                          */
#define RCC_MRTRIM_CR_TVS_Msk             (0x8000UL)                /*!< TVS (Bitfield-Mask: 0x01)                             */
#define RCC_MRTRIM_CR_TVS                 (0x8000UL)                /*!< TVS (Bitfield-Mask: 0x01)                             */
#define RCC_MRTRIM_CR_TRIM_MR_ADDV_Pos    (4UL)                     /*!< TRIM_MR_ADDV (Bit 4)                                  */
#define RCC_MRTRIM_CR_TRIM_MR_ADDV_Msk    (0xf0UL)                  /*!< TRIM_MR_ADDV (Bitfield-Mask: 0x0f)                    */
#define RCC_MRTRIM_CR_TRIM_MR_ADDV        (0xf0UL)                  /*!< TRIM_MR_ADDV (Bitfield-Mask: 0x0f)                    */
#define RCC_MRTRIM_CR_TVSEN_Pos           (0UL)                     /*!< TVSEN (Bit 0)                                         */
#define RCC_MRTRIM_CR_TVSEN_Msk           (0x1UL)                   /*!< TVSEN (Bitfield-Mask: 0x01)                           */
#define RCC_MRTRIM_CR_TVSEN               (0x1UL)                   /*!< TVSEN (Bitfield-Mask: 0x01)                           */


/* =========================================================================================================================== */
/* ================                                           GPIOA                                           ================ */
/* =========================================================================================================================== */

/* =========================================================  MODER  ========================================================= */
#define GPIO_MODER_MODE15_Pos            (30UL)                    /*!< MODE15 (Bit 30)                                       */
#define GPIO_MODER_MODE15_Msk            (0xc0000000UL)            /*!< MODE15 (Bitfield-Mask: 0x03)                          */
#define GPIO_MODER_MODE15                (0xc0000000UL)            /*!< MODE15 (Bitfield-Mask: 0x03)                          */
#define GPIO_MODER_MODE14_Pos            (28UL)                    /*!< MODE14 (Bit 28)                                       */
#define GPIO_MODER_MODE14_Msk            (0x30000000UL)            /*!< MODE14 (Bitfield-Mask: 0x03)                          */
#define GPIO_MODER_MODE14                (0x30000000UL)            /*!< MODE14 (Bitfield-Mask: 0x03)                          */
#define GPIO_MODER_MODE13_Pos            (26UL)                    /*!< MODE13 (Bit 26)                                       */
#define GPIO_MODER_MODE13_Msk            (0xc000000UL)             /*!< MODE13 (Bitfield-Mask: 0x03)                          */
#define GPIO_MODER_MODE13                (0xc000000UL)             /*!< MODE13 (Bitfield-Mask: 0x03)                          */
#define GPIO_MODER_MODE12_Pos            (24UL)                    /*!< MODE12 (Bit 24)                                       */
#define GPIO_MODER_MODE12_Msk            (0x3000000UL)             /*!< MODE12 (Bitfield-Mask: 0x03)                          */
#define GPIO_MODER_MODE12                (0x3000000UL)             /*!< MODE12 (Bitfield-Mask: 0x03)                          */
#define GPIO_MODER_MODE11_Pos            (22UL)                    /*!< MODE11 (Bit 22)                                       */
#define GPIO_MODER_MODE11_Msk            (0xc00000UL)              /*!< MODE11 (Bitfield-Mask: 0x03)                          */
#define GPIO_MODER_MODE11                (0xc00000UL)              /*!< MODE11 (Bitfield-Mask: 0x03)                          */
#define GPIO_MODER_MODE10_Pos            (20UL)                    /*!< MODE10 (Bit 20)                                       */
#define GPIO_MODER_MODE10_Msk            (0x300000UL)              /*!< MODE10 (Bitfield-Mask: 0x03)                          */
#define GPIO_MODER_MODE10                (0x300000UL)              /*!< MODE10 (Bitfield-Mask: 0x03)                          */
#define GPIO_MODER_MODE9_Pos             (18UL)                    /*!< MODE9 (Bit 18)                                        */
#define GPIO_MODER_MODE9_Msk             (0xc0000UL)               /*!< MODE9 (Bitfield-Mask: 0x03)                           */
#define GPIO_MODER_MODE9                 (0xc0000UL)               /*!< MODE9 (Bitfield-Mask: 0x03)                           */
#define GPIO_MODER_MODE8_Pos             (16UL)                    /*!< MODE8 (Bit 16)                                        */
#define GPIO_MODER_MODE8_Msk             (0x30000UL)               /*!< MODE8 (Bitfield-Mask: 0x03)                           */
#define GPIO_MODER_MODE8                 (0x30000UL)               /*!< MODE8 (Bitfield-Mask: 0x03)                           */
#define GPIO_MODER_MODE7_Pos             (14UL)                    /*!< MODE7 (Bit 14)                                        */
#define GPIO_MODER_MODE7_Msk             (0xc000UL)                /*!< MODE7 (Bitfield-Mask: 0x03)                           */
#define GPIO_MODER_MODE7                 (0xc000UL)                /*!< MODE7 (Bitfield-Mask: 0x03)                           */
#define GPIO_MODER_MODE6_Pos             (12UL)                    /*!< MODE6 (Bit 12)                                        */
#define GPIO_MODER_MODE6_Msk             (0x3000UL)                /*!< MODE6 (Bitfield-Mask: 0x03)                           */
#define GPIO_MODER_MODE6                 (0x3000UL)                /*!< MODE6 (Bitfield-Mask: 0x03)                           */
#define GPIO_MODER_MODE5_Pos             (10UL)                    /*!< MODE5 (Bit 10)                                        */
#define GPIO_MODER_MODE5_Msk             (0xc00UL)                 /*!< MODE5 (Bitfield-Mask: 0x03)                           */
#define GPIO_MODER_MODE5                 (0xc00UL)                 /*!< MODE5 (Bitfield-Mask: 0x03)                           */
#define GPIO_MODER_MODE4_Pos             (8UL)                     /*!< MODE4 (Bit 8)                                         */
#define GPIO_MODER_MODE4_Msk             (0x300UL)                 /*!< MODE4 (Bitfield-Mask: 0x03)                           */
#define GPIO_MODER_MODE4                 (0x300UL)                 /*!< MODE4 (Bitfield-Mask: 0x03)                           */
#define GPIO_MODER_MODE3_Pos             (6UL)                     /*!< MODE3 (Bit 6)                                         */
#define GPIO_MODER_MODE3_Msk             (0xc0UL)                  /*!< MODE3 (Bitfield-Mask: 0x03)                           */
#define GPIO_MODER_MODE3                 (0xc0UL)                  /*!< MODE3 (Bitfield-Mask: 0x03)                           */
#define GPIO_MODER_MODE2_Pos             (4UL)                     /*!< MODE2 (Bit 4)                                         */
#define GPIO_MODER_MODE2_Msk             (0x30UL)                  /*!< MODE2 (Bitfield-Mask: 0x03)                           */
#define GPIO_MODER_MODE2                 (0x30UL)                  /*!< MODE2 (Bitfield-Mask: 0x03)                           */
#define GPIO_MODER_MODE1_Pos             (2UL)                     /*!< MODE1 (Bit 2)                                         */
#define GPIO_MODER_MODE1_Msk             (0xcUL)                   /*!< MODE1 (Bitfield-Mask: 0x03)                           */
#define GPIO_MODER_MODE1                 (0xcUL)                   /*!< MODE1 (Bitfield-Mask: 0x03)                           */
#define GPIO_MODER_MODE0_Pos             (0UL)                     /*!< MODE0 (Bit 0)                                         */
#define GPIO_MODER_MODE0_Msk             (0x3UL)                   /*!< MODE0 (Bitfield-Mask: 0x03)                           */
#define GPIO_MODER_MODE0                 (0x3UL)                   /*!< MODE0 (Bitfield-Mask: 0x03)                           */
/* ========================================================  OTYPER  ========================================================= */
#define GPIO_OTYPER_OT15_Pos             (15UL)                    /*!< OT15 (Bit 15)                                         */
#define GPIO_OTYPER_OT15_Msk             (0x8000UL)                /*!< OT15 (Bitfield-Mask: 0x01)                            */
#define GPIO_OTYPER_OT15                 (0x8000UL)                /*!< OT15 (Bitfield-Mask: 0x01)                            */
#define GPIO_OTYPER_OT14_Pos             (14UL)                    /*!< OT14 (Bit 14)                                         */
#define GPIO_OTYPER_OT14_Msk             (0x4000UL)                /*!< OT14 (Bitfield-Mask: 0x01)                            */
#define GPIO_OTYPER_OT14                 (0x4000UL)                /*!< OT14 (Bitfield-Mask: 0x01)                            */
#define GPIO_OTYPER_OT13_Pos             (13UL)                    /*!< OT13 (Bit 13)                                         */
#define GPIO_OTYPER_OT13_Msk             (0x2000UL)                /*!< OT13 (Bitfield-Mask: 0x01)                            */
#define GPIO_OTYPER_OT13                 (0x2000UL)                /*!< OT13 (Bitfield-Mask: 0x01)                            */
#define GPIO_OTYPER_OT12_Pos             (12UL)                    /*!< OT12 (Bit 12)                                         */
#define GPIO_OTYPER_OT12_Msk             (0x1000UL)                /*!< OT12 (Bitfield-Mask: 0x01)                            */
#define GPIO_OTYPER_OT12                 (0x1000UL)                /*!< OT12 (Bitfield-Mask: 0x01)                            */
#define GPIO_OTYPER_OT11_Pos             (11UL)                    /*!< OT11 (Bit 11)                                         */
#define GPIO_OTYPER_OT11_Msk             (0x800UL)                 /*!< OT11 (Bitfield-Mask: 0x01)                            */
#define GPIO_OTYPER_OT11                 (0x800UL)                 /*!< OT11 (Bitfield-Mask: 0x01)                            */
#define GPIO_OTYPER_OT10_Pos             (10UL)                    /*!< OT10 (Bit 10)                                         */
#define GPIO_OTYPER_OT10_Msk             (0x400UL)                 /*!< OT10 (Bitfield-Mask: 0x01)                            */
#define GPIO_OTYPER_OT10                 (0x400UL)                 /*!< OT10 (Bitfield-Mask: 0x01)                            */
#define GPIO_OTYPER_OT9_Pos              (9UL)                     /*!< OT9 (Bit 9)                                           */
#define GPIO_OTYPER_OT9_Msk              (0x200UL)                 /*!< OT9 (Bitfield-Mask: 0x01)                             */
#define GPIO_OTYPER_OT9                  (0x200UL)                 /*!< OT9 (Bitfield-Mask: 0x01)                             */
#define GPIO_OTYPER_OT8_Pos              (8UL)                     /*!< OT8 (Bit 8)                                           */
#define GPIO_OTYPER_OT8_Msk              (0x100UL)                 /*!< OT8 (Bitfield-Mask: 0x01)                             */
#define GPIO_OTYPER_OT8                  (0x100UL)                 /*!< OT8 (Bitfield-Mask: 0x01)                             */
#define GPIO_OTYPER_OT7_Pos              (7UL)                     /*!< OT7 (Bit 7)                                           */
#define GPIO_OTYPER_OT7_Msk              (0x80UL)                  /*!< OT7 (Bitfield-Mask: 0x01)                             */
#define GPIO_OTYPER_OT7                  (0x80UL)                  /*!< OT7 (Bitfield-Mask: 0x01)                             */
#define GPIO_OTYPER_OT6_Pos              (6UL)                     /*!< OT6 (Bit 6)                                           */
#define GPIO_OTYPER_OT6_Msk              (0x40UL)                  /*!< OT6 (Bitfield-Mask: 0x01)                             */
#define GPIO_OTYPER_OT6                  (0x40UL)                  /*!< OT6 (Bitfield-Mask: 0x01)                             */
#define GPIO_OTYPER_OT5_Pos              (5UL)                     /*!< OT5 (Bit 5)                                           */
#define GPIO_OTYPER_OT5_Msk              (0x20UL)                  /*!< OT5 (Bitfield-Mask: 0x01)                             */
#define GPIO_OTYPER_OT5                  (0x20UL)                  /*!< OT5 (Bitfield-Mask: 0x01)                             */
#define GPIO_OTYPER_OT4_Pos              (4UL)                     /*!< OT4 (Bit 4)                                           */
#define GPIO_OTYPER_OT4_Msk              (0x10UL)                  /*!< OT4 (Bitfield-Mask: 0x01)                             */
#define GPIO_OTYPER_OT4                  (0x10UL)                  /*!< OT4 (Bitfield-Mask: 0x01)                             */
#define GPIO_OTYPER_OT3_Pos              (3UL)                     /*!< OT3 (Bit 3)                                           */
#define GPIO_OTYPER_OT3_Msk              (0x8UL)                   /*!< OT3 (Bitfield-Mask: 0x01)                             */
#define GPIO_OTYPER_OT3                  (0x8UL)                   /*!< OT3 (Bitfield-Mask: 0x01)                             */
#define GPIO_OTYPER_OT2_Pos              (2UL)                     /*!< OT2 (Bit 2)                                           */
#define GPIO_OTYPER_OT2_Msk              (0x4UL)                   /*!< OT2 (Bitfield-Mask: 0x01)                             */
#define GPIO_OTYPER_OT2                  (0x4UL)                   /*!< OT2 (Bitfield-Mask: 0x01)                             */
#define GPIO_OTYPER_OT1_Pos              (1UL)                     /*!< OT1 (Bit 1)                                           */
#define GPIO_OTYPER_OT1_Msk              (0x2UL)                   /*!< OT1 (Bitfield-Mask: 0x01)                             */
#define GPIO_OTYPER_OT1                  (0x2UL)                   /*!< OT1 (Bitfield-Mask: 0x01)                             */
#define GPIO_OTYPER_OT0_Pos              (0UL)                     /*!< OT0 (Bit 0)                                           */
#define GPIO_OTYPER_OT0_Msk              (0x1UL)                   /*!< OT0 (Bitfield-Mask: 0x01)                             */
#define GPIO_OTYPER_OT0                  (0x1UL)                   /*!< OT0 (Bitfield-Mask: 0x01)                             */
/* ========================================================  OSPEEDR  ======================================================== */
#define GPIO_OSPEEDR_OSPEED15_Pos        (30UL)                    /*!< OSPEED15 (Bit 30)                                     */
#define GPIO_OSPEEDR_OSPEED15_Msk        (0xc0000000UL)            /*!< OSPEED15 (Bitfield-Mask: 0x03)                        */
#define GPIO_OSPEEDR_OSPEED15            (0xc0000000UL)            /*!< OSPEED15 (Bitfield-Mask: 0x03)                        */
#define GPIO_OSPEEDR_OSPEED14_Pos        (28UL)                    /*!< OSPEED14 (Bit 28)                                     */
#define GPIO_OSPEEDR_OSPEED14_Msk        (0x30000000UL)            /*!< OSPEED14 (Bitfield-Mask: 0x03)                        */
#define GPIO_OSPEEDR_OSPEED14            (0x30000000UL)            /*!< OSPEED14 (Bitfield-Mask: 0x03)                        */
#define GPIO_OSPEEDR_OSPEED13_Pos        (26UL)                    /*!< OSPEED13 (Bit 26)                                     */
#define GPIO_OSPEEDR_OSPEED13_Msk        (0xc000000UL)             /*!< OSPEED13 (Bitfield-Mask: 0x03)                        */
#define GPIO_OSPEEDR_OSPEED13            (0xc000000UL)             /*!< OSPEED13 (Bitfield-Mask: 0x03)                        */
#define GPIO_OSPEEDR_OSPEED12_Pos        (24UL)                    /*!< OSPEED12 (Bit 24)                                     */
#define GPIO_OSPEEDR_OSPEED12_Msk        (0x3000000UL)             /*!< OSPEED12 (Bitfield-Mask: 0x03)                        */
#define GPIO_OSPEEDR_OSPEED12            (0x3000000UL)             /*!< OSPEED12 (Bitfield-Mask: 0x03)                        */
#define GPIO_OSPEEDR_OSPEED11_Pos        (22UL)                    /*!< OSPEED11 (Bit 22)                                     */
#define GPIO_OSPEEDR_OSPEED11_Msk        (0xc00000UL)              /*!< OSPEED11 (Bitfield-Mask: 0x03)                        */
#define GPIO_OSPEEDR_OSPEED11            (0xc00000UL)              /*!< OSPEED11 (Bitfield-Mask: 0x03)                        */
#define GPIO_OSPEEDR_OSPEED10_Pos        (20UL)                    /*!< OSPEED10 (Bit 20)                                     */
#define GPIO_OSPEEDR_OSPEED10_Msk        (0x300000UL)              /*!< OSPEED10 (Bitfield-Mask: 0x03)                        */
#define GPIO_OSPEEDR_OSPEED10            (0x300000UL)              /*!< OSPEED10 (Bitfield-Mask: 0x03)                        */
#define GPIO_OSPEEDR_OSPEED9_Pos         (18UL)                    /*!< OSPEED9 (Bit 18)                                      */
#define GPIO_OSPEEDR_OSPEED9_Msk         (0xc0000UL)               /*!< OSPEED9 (Bitfield-Mask: 0x03)                         */
#define GPIO_OSPEEDR_OSPEED9             (0xc0000UL)               /*!< OSPEED9 (Bitfield-Mask: 0x03)                         */
#define GPIO_OSPEEDR_OSPEED8_Pos         (16UL)                    /*!< OSPEED8 (Bit 16)                                      */
#define GPIO_OSPEEDR_OSPEED8_Msk         (0x30000UL)               /*!< OSPEED8 (Bitfield-Mask: 0x03)                         */
#define GPIO_OSPEEDR_OSPEED8             (0x30000UL)               /*!< OSPEED8 (Bitfield-Mask: 0x03)                         */
#define GPIO_OSPEEDR_OSPEED7_Pos         (14UL)                    /*!< OSPEED7 (Bit 14)                                      */
#define GPIO_OSPEEDR_OSPEED7_Msk         (0xc000UL)                /*!< OSPEED7 (Bitfield-Mask: 0x03)                         */
#define GPIO_OSPEEDR_OSPEED7             (0xc000UL)                /*!< OSPEED7 (Bitfield-Mask: 0x03)                         */
#define GPIO_OSPEEDR_OSPEED6_Pos         (12UL)                    /*!< OSPEED6 (Bit 12)                                      */
#define GPIO_OSPEEDR_OSPEED6_Msk         (0x3000UL)                /*!< OSPEED6 (Bitfield-Mask: 0x03)                         */
#define GPIO_OSPEEDR_OSPEED6             (0x3000UL)                /*!< OSPEED6 (Bitfield-Mask: 0x03)                         */
#define GPIO_OSPEEDR_OSPEED5_Pos         (10UL)                    /*!< OSPEED5 (Bit 10)                                      */
#define GPIO_OSPEEDR_OSPEED5_Msk         (0xc00UL)                 /*!< OSPEED5 (Bitfield-Mask: 0x03)                         */
#define GPIO_OSPEEDR_OSPEED5             (0xc00UL)                 /*!< OSPEED5 (Bitfield-Mask: 0x03)                         */
#define GPIO_OSPEEDR_OSPEED4_Pos         (8UL)                     /*!< OSPEED4 (Bit 8)                                       */
#define GPIO_OSPEEDR_OSPEED4_Msk         (0x300UL)                 /*!< OSPEED4 (Bitfield-Mask: 0x03)                         */
#define GPIO_OSPEEDR_OSPEED4             (0x300UL)                 /*!< OSPEED4 (Bitfield-Mask: 0x03)                         */
#define GPIO_OSPEEDR_OSPEED3_Pos         (6UL)                     /*!< OSPEED3 (Bit 6)                                       */
#define GPIO_OSPEEDR_OSPEED3_Msk         (0xc0UL)                  /*!< OSPEED3 (Bitfield-Mask: 0x03)                         */
#define GPIO_OSPEEDR_OSPEED3             (0xc0UL)                  /*!< OSPEED3 (Bitfield-Mask: 0x03)                         */
#define GPIO_OSPEEDR_OSPEED2_Pos         (4UL)                     /*!< OSPEED2 (Bit 4)                                       */
#define GPIO_OSPEEDR_OSPEED2_Msk         (0x30UL)                  /*!< OSPEED2 (Bitfield-Mask: 0x03)                         */
#define GPIO_OSPEEDR_OSPEED2             (0x30UL)                  /*!< OSPEED2 (Bitfield-Mask: 0x03)                         */
#define GPIO_OSPEEDR_OSPEED1_Pos         (2UL)                     /*!< OSPEED1 (Bit 2)                                       */
#define GPIO_OSPEEDR_OSPEED1_Msk         (0xcUL)                   /*!< OSPEED1 (Bitfield-Mask: 0x03)                         */
#define GPIO_OSPEEDR_OSPEED1             (0xcUL)                   /*!< OSPEED1 (Bitfield-Mask: 0x03)                         */
#define GPIO_OSPEEDR_OSPEED0_Pos         (0UL)                     /*!< OSPEED0 (Bit 0)                                       */
#define GPIO_OSPEEDR_OSPEED0_Msk         (0x3UL)                   /*!< OSPEED0 (Bitfield-Mask: 0x03)                         */
#define GPIO_OSPEEDR_OSPEED0             (0x3UL)                   /*!< OSPEED0 (Bitfield-Mask: 0x03)                         */
/* =========================================================  PUPDR  ========================================================= */
#define GPIO_PUPDR_PUPD15_Pos            (30UL)                    /*!< PUPD15 (Bit 30)                                       */
#define GPIO_PUPDR_PUPD15_Msk            (0xc0000000UL)            /*!< PUPD15 (Bitfield-Mask: 0x03)                          */
#define GPIO_PUPDR_PUPD15                (0xc0000000UL)            /*!< PUPD15 (Bitfield-Mask: 0x03)                          */
#define GPIO_PUPDR_PUPD14_Pos            (28UL)                    /*!< PUPD14 (Bit 28)                                       */
#define GPIO_PUPDR_PUPD14_Msk            (0x30000000UL)            /*!< PUPD14 (Bitfield-Mask: 0x03)                          */
#define GPIO_PUPDR_PUPD14                (0x30000000UL)            /*!< PUPD14 (Bitfield-Mask: 0x03)                          */
#define GPIO_PUPDR_PUPD13_Pos            (26UL)                    /*!< PUPD13 (Bit 26)                                       */
#define GPIO_PUPDR_PUPD13_Msk            (0xc000000UL)             /*!< PUPD13 (Bitfield-Mask: 0x03)                          */
#define GPIO_PUPDR_PUPD13                (0xc000000UL)             /*!< PUPD13 (Bitfield-Mask: 0x03)                          */
#define GPIO_PUPDR_PUPD12_Pos            (24UL)                    /*!< PUPD12 (Bit 24)                                       */
#define GPIO_PUPDR_PUPD12_Msk            (0x3000000UL)             /*!< PUPD12 (Bitfield-Mask: 0x03)                          */
#define GPIO_PUPDR_PUPD12                (0x3000000UL)             /*!< PUPD12 (Bitfield-Mask: 0x03)                          */
#define GPIO_PUPDR_PUPD11_Pos            (22UL)                    /*!< PUPD11 (Bit 22)                                       */
#define GPIO_PUPDR_PUPD11_Msk            (0xc00000UL)              /*!< PUPD11 (Bitfield-Mask: 0x03)                          */
#define GPIO_PUPDR_PUPD11                (0xc00000UL)              /*!< PUPD11 (Bitfield-Mask: 0x03)                          */
#define GPIO_PUPDR_PUPD10_Pos            (20UL)                    /*!< PUPD10 (Bit 20)                                       */
#define GPIO_PUPDR_PUPD10_Msk            (0x300000UL)              /*!< PUPD10 (Bitfield-Mask: 0x03)                          */
#define GPIO_PUPDR_PUPD10                (0x300000UL)              /*!< PUPD10 (Bitfield-Mask: 0x03)                          */
#define GPIO_PUPDR_PUPD9_Pos             (18UL)                    /*!< PUPD9 (Bit 18)                                        */
#define GPIO_PUPDR_PUPD9_Msk             (0xc0000UL)               /*!< PUPD9 (Bitfield-Mask: 0x03)                           */
#define GPIO_PUPDR_PUPD9                 (0xc0000UL)               /*!< PUPD9 (Bitfield-Mask: 0x03)                           */
#define GPIO_PUPDR_PUPD8_Pos             (16UL)                    /*!< PUPD8 (Bit 16)                                        */
#define GPIO_PUPDR_PUPD8_Msk             (0x30000UL)               /*!< PUPD8 (Bitfield-Mask: 0x03)                           */
#define GPIO_PUPDR_PUPD8                 (0x30000UL)               /*!< PUPD8 (Bitfield-Mask: 0x03)                           */
#define GPIO_PUPDR_PUPD7_Pos             (14UL)                    /*!< PUPD7 (Bit 14)                                        */
#define GPIO_PUPDR_PUPD7_Msk             (0xc000UL)                /*!< PUPD7 (Bitfield-Mask: 0x03)                           */
#define GPIO_PUPDR_PUPD7                 (0xc000UL)                /*!< PUPD7 (Bitfield-Mask: 0x03)                           */
#define GPIO_PUPDR_PUPD6_Pos             (12UL)                    /*!< PUPD6 (Bit 12)                                        */
#define GPIO_PUPDR_PUPD6_Msk             (0x3000UL)                /*!< PUPD6 (Bitfield-Mask: 0x03)                           */
#define GPIO_PUPDR_PUPD6                 (0x3000UL)                /*!< PUPD6 (Bitfield-Mask: 0x03)                           */
#define GPIO_PUPDR_PUPD5_Pos             (10UL)                    /*!< PUPD5 (Bit 10)                                        */
#define GPIO_PUPDR_PUPD5_Msk             (0xc00UL)                 /*!< PUPD5 (Bitfield-Mask: 0x03)                           */
#define GPIO_PUPDR_PUPD5                 (0xc00UL)                 /*!< PUPD5 (Bitfield-Mask: 0x03)                           */
#define GPIO_PUPDR_PUPD4_Pos             (8UL)                     /*!< PUPD4 (Bit 8)                                         */
#define GPIO_PUPDR_PUPD4_Msk             (0x300UL)                 /*!< PUPD4 (Bitfield-Mask: 0x03)                           */
#define GPIO_PUPDR_PUPD4                 (0x300UL)                 /*!< PUPD4 (Bitfield-Mask: 0x03)                           */
#define GPIO_PUPDR_PUPD3_Pos             (6UL)                     /*!< PUPD3 (Bit 6)                                         */
#define GPIO_PUPDR_PUPD3_Msk             (0xc0UL)                  /*!< PUPD3 (Bitfield-Mask: 0x03)                           */
#define GPIO_PUPDR_PUPD3                 (0xc0UL)                  /*!< PUPD3 (Bitfield-Mask: 0x03)                           */
#define GPIO_PUPDR_PUPD2_Pos             (4UL)                     /*!< PUPD2 (Bit 4)                                         */
#define GPIO_PUPDR_PUPD2_Msk             (0x30UL)                  /*!< PUPD2 (Bitfield-Mask: 0x03)                           */
#define GPIO_PUPDR_PUPD2                 (0x30UL)                  /*!< PUPD2 (Bitfield-Mask: 0x03)                           */
#define GPIO_PUPDR_PUPD1_Pos             (2UL)                     /*!< PUPD1 (Bit 2)                                         */
#define GPIO_PUPDR_PUPD1_Msk             (0xcUL)                   /*!< PUPD1 (Bitfield-Mask: 0x03)                           */
#define GPIO_PUPDR_PUPD1                 (0xcUL)                   /*!< PUPD1 (Bitfield-Mask: 0x03)                           */
#define GPIO_PUPDR_PUPD0_Pos             (0UL)                     /*!< PUPD0 (Bit 0)                                         */
#define GPIO_PUPDR_PUPD0_Msk             (0x3UL)                   /*!< PUPD0 (Bitfield-Mask: 0x03)                           */
#define GPIO_PUPDR_PUPD0                 (0x3UL)                   /*!< PUPD0 (Bitfield-Mask: 0x03)                           */
/* ==========================================================  IDR  ========================================================== */
#define GPIO_IDR_ID15_Pos                (15UL)                    /*!< ID15 (Bit 15)                                         */
#define GPIO_IDR_ID15_Msk                (0x8000UL)                /*!< ID15 (Bitfield-Mask: 0x01)                            */
#define GPIO_IDR_ID15                    (0x8000UL)                /*!< ID15 (Bitfield-Mask: 0x01)                            */
#define GPIO_IDR_ID14_Pos                (14UL)                    /*!< ID14 (Bit 14)                                         */
#define GPIO_IDR_ID14_Msk                (0x4000UL)                /*!< ID14 (Bitfield-Mask: 0x01)                            */
#define GPIO_IDR_ID14                    (0x4000UL)                /*!< ID14 (Bitfield-Mask: 0x01)                            */
#define GPIO_IDR_ID13_Pos                (13UL)                    /*!< ID13 (Bit 13)                                         */
#define GPIO_IDR_ID13_Msk                (0x2000UL)                /*!< ID13 (Bitfield-Mask: 0x01)                            */
#define GPIO_IDR_ID13                    (0x2000UL)                /*!< ID13 (Bitfield-Mask: 0x01)                            */
#define GPIO_IDR_ID12_Pos                (12UL)                    /*!< ID12 (Bit 12)                                         */
#define GPIO_IDR_ID12_Msk                (0x1000UL)                /*!< ID12 (Bitfield-Mask: 0x01)                            */
#define GPIO_IDR_ID12                    (0x1000UL)                /*!< ID12 (Bitfield-Mask: 0x01)                            */
#define GPIO_IDR_ID11_Pos                (11UL)                    /*!< ID11 (Bit 11)                                         */
#define GPIO_IDR_ID11_Msk                (0x800UL)                 /*!< ID11 (Bitfield-Mask: 0x01)                            */
#define GPIO_IDR_ID11                    (0x800UL)                 /*!< ID11 (Bitfield-Mask: 0x01)                            */
#define GPIO_IDR_ID10_Pos                (10UL)                    /*!< ID10 (Bit 10)                                         */
#define GPIO_IDR_ID10_Msk                (0x400UL)                 /*!< ID10 (Bitfield-Mask: 0x01)                            */
#define GPIO_IDR_ID10                    (0x400UL)                 /*!< ID10 (Bitfield-Mask: 0x01)                            */
#define GPIO_IDR_ID9_Pos                 (9UL)                     /*!< ID9 (Bit 9)                                           */
#define GPIO_IDR_ID9_Msk                 (0x200UL)                 /*!< ID9 (Bitfield-Mask: 0x01)                             */
#define GPIO_IDR_ID9                     (0x200UL)                 /*!< ID9 (Bitfield-Mask: 0x01)                             */
#define GPIO_IDR_ID8_Pos                 (8UL)                     /*!< ID8 (Bit 8)                                           */
#define GPIO_IDR_ID8_Msk                 (0x100UL)                 /*!< ID8 (Bitfield-Mask: 0x01)                             */
#define GPIO_IDR_ID8                     (0x100UL)                 /*!< ID8 (Bitfield-Mask: 0x01)                             */
#define GPIO_IDR_ID7_Pos                 (7UL)                     /*!< ID7 (Bit 7)                                           */
#define GPIO_IDR_ID7_Msk                 (0x80UL)                  /*!< ID7 (Bitfield-Mask: 0x01)                             */
#define GPIO_IDR_ID7                     (0x80UL)                  /*!< ID7 (Bitfield-Mask: 0x01)                             */
#define GPIO_IDR_ID6_Pos                 (6UL)                     /*!< ID6 (Bit 6)                                           */
#define GPIO_IDR_ID6_Msk                 (0x40UL)                  /*!< ID6 (Bitfield-Mask: 0x01)                             */
#define GPIO_IDR_ID6                     (0x40UL)                  /*!< ID6 (Bitfield-Mask: 0x01)                             */
#define GPIO_IDR_ID5_Pos                 (5UL)                     /*!< ID5 (Bit 5)                                           */
#define GPIO_IDR_ID5_Msk                 (0x20UL)                  /*!< ID5 (Bitfield-Mask: 0x01)                             */
#define GPIO_IDR_ID5                     (0x20UL)                  /*!< ID5 (Bitfield-Mask: 0x01)                             */
#define GPIO_IDR_ID4_Pos                 (4UL)                     /*!< ID4 (Bit 4)                                           */
#define GPIO_IDR_ID4_Msk                 (0x10UL)                  /*!< ID4 (Bitfield-Mask: 0x01)                             */
#define GPIO_IDR_ID4                     (0x10UL)                  /*!< ID4 (Bitfield-Mask: 0x01)                             */
#define GPIO_IDR_ID3_Pos                 (3UL)                     /*!< ID3 (Bit 3)                                           */
#define GPIO_IDR_ID3_Msk                 (0x8UL)                   /*!< ID3 (Bitfield-Mask: 0x01)                             */
#define GPIO_IDR_ID3                     (0x8UL)                   /*!< ID3 (Bitfield-Mask: 0x01)                             */
#define GPIO_IDR_ID2_Pos                 (2UL)                     /*!< ID2 (Bit 2)                                           */
#define GPIO_IDR_ID2_Msk                 (0x4UL)                   /*!< ID2 (Bitfield-Mask: 0x01)                             */
#define GPIO_IDR_ID2                     (0x4UL)                   /*!< ID2 (Bitfield-Mask: 0x01)                             */
#define GPIO_IDR_ID1_Pos                 (1UL)                     /*!< ID1 (Bit 1)                                           */
#define GPIO_IDR_ID1_Msk                 (0x2UL)                   /*!< ID1 (Bitfield-Mask: 0x01)                             */
#define GPIO_IDR_ID1                     (0x2UL)                   /*!< ID1 (Bitfield-Mask: 0x01)                             */
#define GPIO_IDR_ID0_Pos                 (0UL)                     /*!< ID0 (Bit 0)                                           */
#define GPIO_IDR_ID0_Msk                 (0x1UL)                   /*!< ID0 (Bitfield-Mask: 0x01)                             */
#define GPIO_IDR_ID0                     (0x1UL)                   /*!< ID0 (Bitfield-Mask: 0x01)                             */
/* ==========================================================  ODR  ========================================================== */
#define GPIO_ODR_OD15_Pos                (15UL)                    /*!< OD15 (Bit 15)                                         */
#define GPIO_ODR_OD15_Msk                (0x8000UL)                /*!< OD15 (Bitfield-Mask: 0x01)                            */
#define GPIO_ODR_OD15                    (0x8000UL)                /*!< OD15 (Bitfield-Mask: 0x01)                            */
#define GPIO_ODR_OD14_Pos                (14UL)                    /*!< OD14 (Bit 14)                                         */
#define GPIO_ODR_OD14_Msk                (0x4000UL)                /*!< OD14 (Bitfield-Mask: 0x01)                            */
#define GPIO_ODR_OD14                    (0x4000UL)                /*!< OD14 (Bitfield-Mask: 0x01)                            */
#define GPIO_ODR_OD13_Pos                (13UL)                    /*!< OD13 (Bit 13)                                         */
#define GPIO_ODR_OD13_Msk                (0x2000UL)                /*!< OD13 (Bitfield-Mask: 0x01)                            */
#define GPIO_ODR_OD13                    (0x2000UL)                /*!< OD13 (Bitfield-Mask: 0x01)                            */
#define GPIO_ODR_OD12_Pos                (12UL)                    /*!< OD12 (Bit 12)                                         */
#define GPIO_ODR_OD12_Msk                (0x1000UL)                /*!< OD12 (Bitfield-Mask: 0x01)                            */
#define GPIO_ODR_OD12                    (0x1000UL)                /*!< OD12 (Bitfield-Mask: 0x01)                            */
#define GPIO_ODR_OD11_Pos                (11UL)                    /*!< OD11 (Bit 11)                                         */
#define GPIO_ODR_OD11_Msk                (0x800UL)                 /*!< OD11 (Bitfield-Mask: 0x01)                            */
#define GPIO_ODR_OD11                    (0x800UL)                 /*!< OD11 (Bitfield-Mask: 0x01)                            */
#define GPIO_ODR_OD10_Pos                (10UL)                    /*!< OD10 (Bit 10)                                         */
#define GPIO_ODR_OD10_Msk                (0x400UL)                 /*!< OD10 (Bitfield-Mask: 0x01)                            */
#define GPIO_ODR_OD10                    (0x400UL)                 /*!< OD10 (Bitfield-Mask: 0x01)                            */
#define GPIO_ODR_OD9_Pos                 (9UL)                     /*!< OD9 (Bit 9)                                           */
#define GPIO_ODR_OD9_Msk                 (0x200UL)                 /*!< OD9 (Bitfield-Mask: 0x01)                             */
#define GPIO_ODR_OD9                     (0x200UL)                 /*!< OD9 (Bitfield-Mask: 0x01)                             */
#define GPIO_ODR_OD8_Pos                 (8UL)                     /*!< OD8 (Bit 8)                                           */
#define GPIO_ODR_OD8_Msk                 (0x100UL)                 /*!< OD8 (Bitfield-Mask: 0x01)                             */
#define GPIO_ODR_OD8                     (0x100UL)                 /*!< OD8 (Bitfield-Mask: 0x01)                             */
#define GPIO_ODR_OD7_Pos                 (7UL)                     /*!< OD7 (Bit 7)                                           */
#define GPIO_ODR_OD7_Msk                 (0x80UL)                  /*!< OD7 (Bitfield-Mask: 0x01)                             */
#define GPIO_ODR_OD7                     (0x80UL)                  /*!< OD7 (Bitfield-Mask: 0x01)                             */
#define GPIO_ODR_OD6_Pos                 (6UL)                     /*!< OD6 (Bit 6)                                           */
#define GPIO_ODR_OD6_Msk                 (0x40UL)                  /*!< OD6 (Bitfield-Mask: 0x01)                             */
#define GPIO_ODR_OD6                     (0x40UL)                  /*!< OD6 (Bitfield-Mask: 0x01)                             */
#define GPIO_ODR_OD5_Pos                 (5UL)                     /*!< OD5 (Bit 5)                                           */
#define GPIO_ODR_OD5_Msk                 (0x20UL)                  /*!< OD5 (Bitfield-Mask: 0x01)                             */
#define GPIO_ODR_OD5                     (0x20UL)                  /*!< OD5 (Bitfield-Mask: 0x01)                             */
#define GPIO_ODR_OD4_Pos                 (4UL)                     /*!< OD4 (Bit 4)                                           */
#define GPIO_ODR_OD4_Msk                 (0x10UL)                  /*!< OD4 (Bitfield-Mask: 0x01)                             */
#define GPIO_ODR_OD4                     (0x10UL)                  /*!< OD4 (Bitfield-Mask: 0x01)                             */
#define GPIO_ODR_OD3_Pos                 (3UL)                     /*!< OD3 (Bit 3)                                           */
#define GPIO_ODR_OD3_Msk                 (0x8UL)                   /*!< OD3 (Bitfield-Mask: 0x01)                             */
#define GPIO_ODR_OD3                     (0x8UL)                   /*!< OD3 (Bitfield-Mask: 0x01)                             */
#define GPIO_ODR_OD2_Pos                 (2UL)                     /*!< OD2 (Bit 2)                                           */
#define GPIO_ODR_OD2_Msk                 (0x4UL)                   /*!< OD2 (Bitfield-Mask: 0x01)                             */
#define GPIO_ODR_OD2                     (0x4UL)                   /*!< OD2 (Bitfield-Mask: 0x01)                             */
#define GPIO_ODR_OD1_Pos                 (1UL)                     /*!< OD1 (Bit 1)                                           */
#define GPIO_ODR_OD1_Msk                 (0x2UL)                   /*!< OD1 (Bitfield-Mask: 0x01)                             */
#define GPIO_ODR_OD1                     (0x2UL)                   /*!< OD1 (Bitfield-Mask: 0x01)                             */
#define GPIO_ODR_OD0_Pos                 (0UL)                     /*!< OD0 (Bit 0)                                           */
#define GPIO_ODR_OD0_Msk                 (0x1UL)                   /*!< OD0 (Bitfield-Mask: 0x01)                             */
#define GPIO_ODR_OD0                     (0x1UL)                   /*!< OD0 (Bitfield-Mask: 0x01)                             */
/* =========================================================  BSRR  ========================================================== */
#define GPIO_BSRR_BR15_Pos               (31UL)                    /*!< BR15 (Bit 31)                                         */
#define GPIO_BSRR_BR15_Msk               (0x80000000UL)            /*!< BR15 (Bitfield-Mask: 0x01)                            */
#define GPIO_BSRR_BR15                   (0x80000000UL)            /*!< BR15 (Bitfield-Mask: 0x01)                            */
#define GPIO_BSRR_BR14_Pos               (30UL)                    /*!< BR14 (Bit 30)                                         */
#define GPIO_BSRR_BR14_Msk               (0x40000000UL)            /*!< BR14 (Bitfield-Mask: 0x01)                            */
#define GPIO_BSRR_BR14                   (0x40000000UL)            /*!< BR14 (Bitfield-Mask: 0x01)                            */
#define GPIO_BSRR_BR13_Pos               (29UL)                    /*!< BR13 (Bit 29)                                         */
#define GPIO_BSRR_BR13_Msk               (0x20000000UL)            /*!< BR13 (Bitfield-Mask: 0x01)                            */
#define GPIO_BSRR_BR13                   (0x20000000UL)            /*!< BR13 (Bitfield-Mask: 0x01)                            */
#define GPIO_BSRR_BR12_Pos               (28UL)                    /*!< BR12 (Bit 28)                                         */
#define GPIO_BSRR_BR12_Msk               (0x10000000UL)            /*!< BR12 (Bitfield-Mask: 0x01)                            */
#define GPIO_BSRR_BR12                   (0x10000000UL)            /*!< BR12 (Bitfield-Mask: 0x01)                            */
#define GPIO_BSRR_BR11_Pos               (27UL)                    /*!< BR11 (Bit 27)                                         */
#define GPIO_BSRR_BR11_Msk               (0x8000000UL)             /*!< BR11 (Bitfield-Mask: 0x01)                            */
#define GPIO_BSRR_BR11                   (0x8000000UL)             /*!< BR11 (Bitfield-Mask: 0x01)                            */
#define GPIO_BSRR_BR10_Pos               (26UL)                    /*!< BR10 (Bit 26)                                         */
#define GPIO_BSRR_BR10_Msk               (0x4000000UL)             /*!< BR10 (Bitfield-Mask: 0x01)                            */
#define GPIO_BSRR_BR10                   (0x4000000UL)             /*!< BR10 (Bitfield-Mask: 0x01)                            */
#define GPIO_BSRR_BR9_Pos                (25UL)                    /*!< BR9 (Bit 25)                                          */
#define GPIO_BSRR_BR9_Msk                (0x2000000UL)             /*!< BR9 (Bitfield-Mask: 0x01)                             */
#define GPIO_BSRR_BR9                    (0x2000000UL)             /*!< BR9 (Bitfield-Mask: 0x01)                             */
#define GPIO_BSRR_BR8_Pos                (24UL)                    /*!< BR8 (Bit 24)                                          */
#define GPIO_BSRR_BR8_Msk                (0x1000000UL)             /*!< BR8 (Bitfield-Mask: 0x01)                             */
#define GPIO_BSRR_BR8                    (0x1000000UL)             /*!< BR8 (Bitfield-Mask: 0x01)                             */
#define GPIO_BSRR_BR7_Pos                (23UL)                    /*!< BR7 (Bit 23)                                          */
#define GPIO_BSRR_BR7_Msk                (0x800000UL)              /*!< BR7 (Bitfield-Mask: 0x01)                             */
#define GPIO_BSRR_BR7                    (0x800000UL)              /*!< BR7 (Bitfield-Mask: 0x01)                             */
#define GPIO_BSRR_BR6_Pos                (22UL)                    /*!< BR6 (Bit 22)                                          */
#define GPIO_BSRR_BR6_Msk                (0x400000UL)              /*!< BR6 (Bitfield-Mask: 0x01)                             */
#define GPIO_BSRR_BR6                    (0x400000UL)              /*!< BR6 (Bitfield-Mask: 0x01)                             */
#define GPIO_BSRR_BR5_Pos                (21UL)                    /*!< BR5 (Bit 21)                                          */
#define GPIO_BSRR_BR5_Msk                (0x200000UL)              /*!< BR5 (Bitfield-Mask: 0x01)                             */
#define GPIO_BSRR_BR5                    (0x200000UL)              /*!< BR5 (Bitfield-Mask: 0x01)                             */
#define GPIO_BSRR_BR4_Pos                (20UL)                    /*!< BR4 (Bit 20)                                          */
#define GPIO_BSRR_BR4_Msk                (0x100000UL)              /*!< BR4 (Bitfield-Mask: 0x01)                             */
#define GPIO_BSRR_BR4                    (0x100000UL)              /*!< BR4 (Bitfield-Mask: 0x01)                             */
#define GPIO_BSRR_BR3_Pos                (19UL)                    /*!< BR3 (Bit 19)                                          */
#define GPIO_BSRR_BR3_Msk                (0x80000UL)               /*!< BR3 (Bitfield-Mask: 0x01)                             */
#define GPIO_BSRR_BR3                    (0x80000UL)               /*!< BR3 (Bitfield-Mask: 0x01)                             */
#define GPIO_BSRR_BR2_Pos                (18UL)                    /*!< BR2 (Bit 18)                                          */
#define GPIO_BSRR_BR2_Msk                (0x40000UL)               /*!< BR2 (Bitfield-Mask: 0x01)                             */
#define GPIO_BSRR_BR2                    (0x40000UL)               /*!< BR2 (Bitfield-Mask: 0x01)                             */
#define GPIO_BSRR_BR1_Pos                (17UL)                    /*!< BR1 (Bit 17)                                          */
#define GPIO_BSRR_BR1_Msk                (0x20000UL)               /*!< BR1 (Bitfield-Mask: 0x01)                             */
#define GPIO_BSRR_BR1                    (0x20000UL)               /*!< BR1 (Bitfield-Mask: 0x01)                             */
#define GPIO_BSRR_BR0_Pos                (16UL)                    /*!< BR0 (Bit 16)                                          */
#define GPIO_BSRR_BR0_Msk                (0x10000UL)               /*!< BR0 (Bitfield-Mask: 0x01)                             */
#define GPIO_BSRR_BR0                    (0x10000UL)               /*!< BR0 (Bitfield-Mask: 0x01)                             */
#define GPIO_BSRR_BS15_Pos               (15UL)                    /*!< BS15 (Bit 15)                                         */
#define GPIO_BSRR_BS15_Msk               (0x8000UL)                /*!< BS15 (Bitfield-Mask: 0x01)                            */
#define GPIO_BSRR_BS15                   (0x8000UL)                /*!< BS15 (Bitfield-Mask: 0x01)                            */
#define GPIO_BSRR_BS14_Pos               (14UL)                    /*!< BS14 (Bit 14)                                         */
#define GPIO_BSRR_BS14_Msk               (0x4000UL)                /*!< BS14 (Bitfield-Mask: 0x01)                            */
#define GPIO_BSRR_BS14                   (0x4000UL)                /*!< BS14 (Bitfield-Mask: 0x01)                            */
#define GPIO_BSRR_BS13_Pos               (13UL)                    /*!< BS13 (Bit 13)                                         */
#define GPIO_BSRR_BS13_Msk               (0x2000UL)                /*!< BS13 (Bitfield-Mask: 0x01)                            */
#define GPIO_BSRR_BS13                   (0x2000UL)                /*!< BS13 (Bitfield-Mask: 0x01)                            */
#define GPIO_BSRR_BS12_Pos               (12UL)                    /*!< BS12 (Bit 12)                                         */
#define GPIO_BSRR_BS12_Msk               (0x1000UL)                /*!< BS12 (Bitfield-Mask: 0x01)                            */
#define GPIO_BSRR_BS12                   (0x1000UL)                /*!< BS12 (Bitfield-Mask: 0x01)                            */
#define GPIO_BSRR_BS11_Pos               (11UL)                    /*!< BS11 (Bit 11)                                         */
#define GPIO_BSRR_BS11_Msk               (0x800UL)                 /*!< BS11 (Bitfield-Mask: 0x01)                            */
#define GPIO_BSRR_BS11                   (0x800UL)                 /*!< BS11 (Bitfield-Mask: 0x01)                            */
#define GPIO_BSRR_BS10_Pos               (10UL)                    /*!< BS10 (Bit 10)                                         */
#define GPIO_BSRR_BS10_Msk               (0x400UL)                 /*!< BS10 (Bitfield-Mask: 0x01)                            */
#define GPIO_BSRR_BS10                   (0x400UL)                 /*!< BS10 (Bitfield-Mask: 0x01)                            */
#define GPIO_BSRR_BS9_Pos                (9UL)                     /*!< BS9 (Bit 9)                                           */
#define GPIO_BSRR_BS9_Msk                (0x200UL)                 /*!< BS9 (Bitfield-Mask: 0x01)                             */
#define GPIO_BSRR_BS9                    (0x200UL)                 /*!< BS9 (Bitfield-Mask: 0x01)                             */
#define GPIO_BSRR_BS8_Pos                (8UL)                     /*!< BS8 (Bit 8)                                           */
#define GPIO_BSRR_BS8_Msk                (0x100UL)                 /*!< BS8 (Bitfield-Mask: 0x01)                             */
#define GPIO_BSRR_BS8                    (0x100UL)                 /*!< BS8 (Bitfield-Mask: 0x01)                             */
#define GPIO_BSRR_BS7_Pos                (7UL)                     /*!< BS7 (Bit 7)                                           */
#define GPIO_BSRR_BS7_Msk                (0x80UL)                  /*!< BS7 (Bitfield-Mask: 0x01)                             */
#define GPIO_BSRR_BS7                    (0x80UL)                  /*!< BS7 (Bitfield-Mask: 0x01)                             */
#define GPIO_BSRR_BS6_Pos                (6UL)                     /*!< BS6 (Bit 6)                                           */
#define GPIO_BSRR_BS6_Msk                (0x40UL)                  /*!< BS6 (Bitfield-Mask: 0x01)                             */
#define GPIO_BSRR_BS6                    (0x40UL)                  /*!< BS6 (Bitfield-Mask: 0x01)                             */
#define GPIO_BSRR_BS5_Pos                (5UL)                     /*!< BS5 (Bit 5)                                           */
#define GPIO_BSRR_BS5_Msk                (0x20UL)                  /*!< BS5 (Bitfield-Mask: 0x01)                             */
#define GPIO_BSRR_BS5                    (0x20UL)                  /*!< BS5 (Bitfield-Mask: 0x01)                             */
#define GPIO_BSRR_BS4_Pos                (4UL)                     /*!< BS4 (Bit 4)                                           */
#define GPIO_BSRR_BS4_Msk                (0x10UL)                  /*!< BS4 (Bitfield-Mask: 0x01)                             */
#define GPIO_BSRR_BS4                    (0x10UL)                  /*!< BS4 (Bitfield-Mask: 0x01)                             */
#define GPIO_BSRR_BS3_Pos                (3UL)                     /*!< BS3 (Bit 3)                                           */
#define GPIO_BSRR_BS3_Msk                (0x8UL)                   /*!< BS3 (Bitfield-Mask: 0x01)                             */
#define GPIO_BSRR_BS3                    (0x8UL)                   /*!< BS3 (Bitfield-Mask: 0x01)                             */
#define GPIO_BSRR_BS2_Pos                (2UL)                     /*!< BS2 (Bit 2)                                           */
#define GPIO_BSRR_BS2_Msk                (0x4UL)                   /*!< BS2 (Bitfield-Mask: 0x01)                             */
#define GPIO_BSRR_BS2                    (0x4UL)                   /*!< BS2 (Bitfield-Mask: 0x01)                             */
#define GPIO_BSRR_BS1_Pos                (1UL)                     /*!< BS1 (Bit 1)                                           */
#define GPIO_BSRR_BS1_Msk                (0x2UL)                   /*!< BS1 (Bitfield-Mask: 0x01)                             */
#define GPIO_BSRR_BS1                    (0x2UL)                   /*!< BS1 (Bitfield-Mask: 0x01)                             */
#define GPIO_BSRR_BS0_Pos                (0UL)                     /*!< BS0 (Bit 0)                                           */
#define GPIO_BSRR_BS0_Msk                (0x1UL)                   /*!< BS0 (Bitfield-Mask: 0x01)                             */
#define GPIO_BSRR_BS0                    (0x1UL)                   /*!< BS0 (Bitfield-Mask: 0x01)                             */
/* =========================================================  LCKR  ========================================================== */
#define GPIO_LCKR_LCKK_Pos               (16UL)                    /*!< LCKK (Bit 16)                                         */
#define GPIO_LCKR_LCKK_Msk               (0x10000UL)               /*!< LCKK (Bitfield-Mask: 0x01)                            */
#define GPIO_LCKR_LCKK                   (0x10000UL)               /*!< LCKK (Bitfield-Mask: 0x01)                            */
#define GPIO_LCKR_LCK15_Pos              (15UL)                    /*!< LCK15 (Bit 15)                                        */
#define GPIO_LCKR_LCK15_Msk              (0x8000UL)                /*!< LCK15 (Bitfield-Mask: 0x01)                           */
#define GPIO_LCKR_LCK15                  (0x8000UL)                /*!< LCK15 (Bitfield-Mask: 0x01)                           */
#define GPIO_LCKR_LCK14_Pos              (14UL)                    /*!< LCK14 (Bit 14)                                        */
#define GPIO_LCKR_LCK14_Msk              (0x4000UL)                /*!< LCK14 (Bitfield-Mask: 0x01)                           */
#define GPIO_LCKR_LCK14                  (0x4000UL)                /*!< LCK14 (Bitfield-Mask: 0x01)                           */
#define GPIO_LCKR_LCK13_Pos              (13UL)                    /*!< LCK13 (Bit 13)                                        */
#define GPIO_LCKR_LCK13_Msk              (0x2000UL)                /*!< LCK13 (Bitfield-Mask: 0x01)                           */
#define GPIO_LCKR_LCK13                  (0x2000UL)                /*!< LCK13 (Bitfield-Mask: 0x01)                           */
#define GPIO_LCKR_LCK12_Pos              (12UL)                    /*!< LCK12 (Bit 12)                                        */
#define GPIO_LCKR_LCK12_Msk              (0x1000UL)                /*!< LCK12 (Bitfield-Mask: 0x01)                           */
#define GPIO_LCKR_LCK12                  (0x1000UL)                /*!< LCK12 (Bitfield-Mask: 0x01)                           */
#define GPIO_LCKR_LCK11_Pos              (11UL)                    /*!< LCK11 (Bit 11)                                        */
#define GPIO_LCKR_LCK11_Msk              (0x800UL)                 /*!< LCK11 (Bitfield-Mask: 0x01)                           */
#define GPIO_LCKR_LCK11                  (0x800UL)                 /*!< LCK11 (Bitfield-Mask: 0x01)                           */
#define GPIO_LCKR_LCK10_Pos              (10UL)                    /*!< LCK10 (Bit 10)                                        */
#define GPIO_LCKR_LCK10_Msk              (0x400UL)                 /*!< LCK10 (Bitfield-Mask: 0x01)                           */
#define GPIO_LCKR_LCK10                  (0x400UL)                 /*!< LCK10 (Bitfield-Mask: 0x01)                           */
#define GPIO_LCKR_LCK9_Pos               (9UL)                     /*!< LCK9 (Bit 9)                                          */
#define GPIO_LCKR_LCK9_Msk               (0x200UL)                 /*!< LCK9 (Bitfield-Mask: 0x01)                            */
#define GPIO_LCKR_LCK9                   (0x200UL)                 /*!< LCK9 (Bitfield-Mask: 0x01)                            */
#define GPIO_LCKR_LCK8_Pos               (8UL)                     /*!< LCK8 (Bit 8)                                          */
#define GPIO_LCKR_LCK8_Msk               (0x100UL)                 /*!< LCK8 (Bitfield-Mask: 0x01)                            */
#define GPIO_LCKR_LCK8                   (0x100UL)                 /*!< LCK8 (Bitfield-Mask: 0x01)                            */
#define GPIO_LCKR_LCK7_Pos               (7UL)                     /*!< LCK7 (Bit 7)                                          */
#define GPIO_LCKR_LCK7_Msk               (0x80UL)                  /*!< LCK7 (Bitfield-Mask: 0x01)                            */
#define GPIO_LCKR_LCK7                   (0x80UL)                  /*!< LCK7 (Bitfield-Mask: 0x01)                            */
#define GPIO_LCKR_LCK6_Pos               (6UL)                     /*!< LCK6 (Bit 6)                                          */
#define GPIO_LCKR_LCK6_Msk               (0x40UL)                  /*!< LCK6 (Bitfield-Mask: 0x01)                            */
#define GPIO_LCKR_LCK6                   (0x40UL)                  /*!< LCK6 (Bitfield-Mask: 0x01)                            */
#define GPIO_LCKR_LCK5_Pos               (5UL)                     /*!< LCK5 (Bit 5)                                          */
#define GPIO_LCKR_LCK5_Msk               (0x20UL)                  /*!< LCK5 (Bitfield-Mask: 0x01)                            */
#define GPIO_LCKR_LCK5                   (0x20UL)                  /*!< LCK5 (Bitfield-Mask: 0x01)                            */
#define GPIO_LCKR_LCK4_Pos               (4UL)                     /*!< LCK4 (Bit 4)                                          */
#define GPIO_LCKR_LCK4_Msk               (0x10UL)                  /*!< LCK4 (Bitfield-Mask: 0x01)                            */
#define GPIO_LCKR_LCK4                   (0x10UL)                  /*!< LCK4 (Bitfield-Mask: 0x01)                            */
#define GPIO_LCKR_LCK3_Pos               (3UL)                     /*!< LCK3 (Bit 3)                                          */
#define GPIO_LCKR_LCK3_Msk               (0x8UL)                   /*!< LCK3 (Bitfield-Mask: 0x01)                            */
#define GPIO_LCKR_LCK3                   (0x8UL)                   /*!< LCK3 (Bitfield-Mask: 0x01)                            */
#define GPIO_LCKR_LCK2_Pos               (2UL)                     /*!< LCK2 (Bit 2)                                          */
#define GPIO_LCKR_LCK2_Msk               (0x4UL)                   /*!< LCK2 (Bitfield-Mask: 0x01)                            */
#define GPIO_LCKR_LCK2                   (0x4UL)                   /*!< LCK2 (Bitfield-Mask: 0x01)                            */
#define GPIO_LCKR_LCK1_Pos               (1UL)                     /*!< LCK1 (Bit 1)                                          */
#define GPIO_LCKR_LCK1_Msk               (0x2UL)                   /*!< LCK1 (Bitfield-Mask: 0x01)                            */
#define GPIO_LCKR_LCK1                   (0x2UL)                   /*!< LCK1 (Bitfield-Mask: 0x01)                            */
#define GPIO_LCKR_LCK0_Pos               (0UL)                     /*!< LCK0 (Bit 0)                                          */
#define GPIO_LCKR_LCK0_Msk               (0x1UL)                   /*!< LCK0 (Bitfield-Mask: 0x01)                            */
#define GPIO_LCKR_LCK0                   (0x1UL)                   /*!< LCK0 (Bitfield-Mask: 0x01)                            */
/* =========================================================  AFRL  ========================================================== */
#define GPIO_AFRL_AFSEL7_Pos             (28UL)                    /*!< AFSEL7 (Bit 28)                                       */
#define GPIO_AFRL_AFSEL7_Msk             (0xf0000000UL)            /*!< AFSEL7 (Bitfield-Mask: 0x0f)                          */
#define GPIO_AFRL_AFSEL7                 (0xf0000000UL)            /*!< AFSEL7 (Bitfield-Mask: 0x0f)                          */
#define GPIO_AFRL_AFSEL6_Pos             (24UL)                    /*!< AFSEL6 (Bit 24)                                       */
#define GPIO_AFRL_AFSEL6_Msk             (0xf000000UL)             /*!< AFSEL6 (Bitfield-Mask: 0x0f)                          */
#define GPIO_AFRL_AFSEL6                 (0xf000000UL)             /*!< AFSEL6 (Bitfield-Mask: 0x0f)                          */
#define GPIO_AFRL_AFSEL5_Pos             (20UL)                    /*!< AFSEL5 (Bit 20)                                       */
#define GPIO_AFRL_AFSEL5_Msk             (0xf00000UL)              /*!< AFSEL5 (Bitfield-Mask: 0x0f)                          */
#define GPIO_AFRL_AFSEL5                 (0xf00000UL)              /*!< AFSEL5 (Bitfield-Mask: 0x0f)                          */
#define GPIO_AFRL_AFSEL4_Pos             (16UL)                    /*!< AFSEL4 (Bit 16)                                       */
#define GPIO_AFRL_AFSEL4_Msk             (0xf0000UL)               /*!< AFSEL4 (Bitfield-Mask: 0x0f)                          */
#define GPIO_AFRL_AFSEL4                 (0xf0000UL)               /*!< AFSEL4 (Bitfield-Mask: 0x0f)                          */
#define GPIO_AFRL_AFSEL3_Pos             (12UL)                    /*!< AFSEL3 (Bit 12)                                       */
#define GPIO_AFRL_AFSEL3_Msk             (0xf000UL)                /*!< AFSEL3 (Bitfield-Mask: 0x0f)                          */
#define GPIO_AFRL_AFSEL3                 (0xf000UL)                /*!< AFSEL3 (Bitfield-Mask: 0x0f)                          */
#define GPIO_AFRL_AFSEL2_Pos             (8UL)                     /*!< AFSEL2 (Bit 8)                                        */
#define GPIO_AFRL_AFSEL2_Msk             (0xf00UL)                 /*!< AFSEL2 (Bitfield-Mask: 0x0f)                          */
#define GPIO_AFRL_AFSEL2                 (0xf00UL)                 /*!< AFSEL2 (Bitfield-Mask: 0x0f)                          */
#define GPIO_AFRL_AFSEL1_Pos             (4UL)                     /*!< AFSEL1 (Bit 4)                                        */
#define GPIO_AFRL_AFSEL1_Msk             (0xf0UL)                  /*!< AFSEL1 (Bitfield-Mask: 0x0f)                          */
#define GPIO_AFRL_AFSEL1                 (0xf0UL)                  /*!< AFSEL1 (Bitfield-Mask: 0x0f)                          */
#define GPIO_AFRL_AFSEL0_Pos             (0UL)                     /*!< AFSEL0 (Bit 0)                                        */
#define GPIO_AFRL_AFSEL0_Msk             (0xfUL)                   /*!< AFSEL0 (Bitfield-Mask: 0x0f)                          */
#define GPIO_AFRL_AFSEL0                 (0xfUL)                   /*!< AFSEL0 (Bitfield-Mask: 0x0f)                          */
/* =========================================================  AFRH  ========================================================== */
#define GPIO_AFRH_AFSEL15_Pos            (28UL)                    /*!< AFSEL15 (Bit 28)                                      */
#define GPIO_AFRH_AFSEL15_Msk            (0xf0000000UL)            /*!< AFSEL15 (Bitfield-Mask: 0x0f)                         */
#define GPIO_AFRH_AFSEL15                (0xf0000000UL)            /*!< AFSEL15 (Bitfield-Mask: 0x0f)                         */
#define GPIO_AFRH_AFSEL14_Pos            (24UL)                    /*!< AFSEL14 (Bit 24)                                      */
#define GPIO_AFRH_AFSEL14_Msk            (0xf000000UL)             /*!< AFSEL14 (Bitfield-Mask: 0x0f)                         */
#define GPIO_AFRH_AFSEL14                (0xf000000UL)             /*!< AFSEL14 (Bitfield-Mask: 0x0f)                         */
#define GPIO_AFRH_AFSEL13_Pos            (20UL)                    /*!< AFSEL13 (Bit 20)                                      */
#define GPIO_AFRH_AFSEL13_Msk            (0xf00000UL)              /*!< AFSEL13 (Bitfield-Mask: 0x0f)                         */
#define GPIO_AFRH_AFSEL13                (0xf00000UL)              /*!< AFSEL13 (Bitfield-Mask: 0x0f)                         */
#define GPIO_AFRH_AFSEL12_Pos            (16UL)                    /*!< AFSEL12 (Bit 16)                                      */
#define GPIO_AFRH_AFSEL12_Msk            (0xf0000UL)               /*!< AFSEL12 (Bitfield-Mask: 0x0f)                         */
#define GPIO_AFRH_AFSEL12                (0xf0000UL)               /*!< AFSEL12 (Bitfield-Mask: 0x0f)                         */
#define GPIO_AFRH_AFSEL11_Pos            (12UL)                    /*!< AFSEL11 (Bit 12)                                      */
#define GPIO_AFRH_AFSEL11_Msk            (0xf000UL)                /*!< AFSEL11 (Bitfield-Mask: 0x0f)                         */
#define GPIO_AFRH_AFSEL11                (0xf000UL)                /*!< AFSEL11 (Bitfield-Mask: 0x0f)                         */
#define GPIO_AFRH_AFSEL10_Pos            (8UL)                     /*!< AFSEL10 (Bit 8)                                       */
#define GPIO_AFRH_AFSEL10_Msk            (0xf00UL)                 /*!< AFSEL10 (Bitfield-Mask: 0x0f)                         */
#define GPIO_AFRH_AFSEL10                (0xf00UL)                 /*!< AFSEL10 (Bitfield-Mask: 0x0f)                         */
#define GPIO_AFRH_AFSEL9_Pos             (4UL)                     /*!< AFSEL9 (Bit 4)                                        */
#define GPIO_AFRH_AFSEL9_Msk             (0xf0UL)                  /*!< AFSEL9 (Bitfield-Mask: 0x0f)                          */
#define GPIO_AFRH_AFSEL9                 (0xf0UL)                  /*!< AFSEL9 (Bitfield-Mask: 0x0f)                          */
#define GPIO_AFRH_AFSEL8_Pos             (0UL)                     /*!< AFSEL8 (Bit 0)                                        */
#define GPIO_AFRH_AFSEL8_Msk             (0xfUL)                   /*!< AFSEL8 (Bitfield-Mask: 0x0f)                          */
#define GPIO_AFRH_AFSEL8                 (0xfUL)                   /*!< AFSEL8 (Bitfield-Mask: 0x0f)                          */
/* ==========================================================  BRR  ========================================================== */
#define GPIO_BRR_BR15_Pos                (15UL)                    /*!< BR15 (Bit 15)                                         */
#define GPIO_BRR_BR15_Msk                (0x8000UL)                /*!< BR15 (Bitfield-Mask: 0x01)                            */
#define GPIO_BRR_BR15                    (0x8000UL)                /*!< BR15 (Bitfield-Mask: 0x01)                            */
#define GPIO_BRR_BR14_Pos                (14UL)                    /*!< BR14 (Bit 14)                                         */
#define GPIO_BRR_BR14_Msk                (0x4000UL)                /*!< BR14 (Bitfield-Mask: 0x01)                            */
#define GPIO_BRR_BR14                    (0x4000UL)                /*!< BR14 (Bitfield-Mask: 0x01)                            */
#define GPIO_BRR_BR13_Pos                (13UL)                    /*!< BR13 (Bit 13)                                         */
#define GPIO_BRR_BR13_Msk                (0x2000UL)                /*!< BR13 (Bitfield-Mask: 0x01)                            */
#define GPIO_BRR_BR13                    (0x2000UL)                /*!< BR13 (Bitfield-Mask: 0x01)                            */
#define GPIO_BRR_BR12_Pos                (12UL)                    /*!< BR12 (Bit 12)                                         */
#define GPIO_BRR_BR12_Msk                (0x1000UL)                /*!< BR12 (Bitfield-Mask: 0x01)                            */
#define GPIO_BRR_BR12                    (0x1000UL)                /*!< BR12 (Bitfield-Mask: 0x01)                            */
#define GPIO_BRR_BR11_Pos                (11UL)                    /*!< BR11 (Bit 11)                                         */
#define GPIO_BRR_BR11_Msk                (0x800UL)                 /*!< BR11 (Bitfield-Mask: 0x01)                            */
#define GPIO_BRR_BR11                    (0x800UL)                 /*!< BR11 (Bitfield-Mask: 0x01)                            */
#define GPIO_BRR_BR10_Pos                (10UL)                    /*!< BR10 (Bit 10)                                         */
#define GPIO_BRR_BR10_Msk                (0x400UL)                 /*!< BR10 (Bitfield-Mask: 0x01)                            */
#define GPIO_BRR_BR10                    (0x400UL)                 /*!< BR10 (Bitfield-Mask: 0x01)                            */
#define GPIO_BRR_BR9_Pos                 (9UL)                     /*!< BR9 (Bit 9)                                           */
#define GPIO_BRR_BR9_Msk                 (0x200UL)                 /*!< BR9 (Bitfield-Mask: 0x01)                             */
#define GPIO_BRR_BR9                     (0x200UL)                 /*!< BR9 (Bitfield-Mask: 0x01)                             */
#define GPIO_BRR_BR8_Pos                 (8UL)                     /*!< BR8 (Bit 8)                                           */
#define GPIO_BRR_BR8_Msk                 (0x100UL)                 /*!< BR8 (Bitfield-Mask: 0x01)                             */
#define GPIO_BRR_BR8                     (0x100UL)                 /*!< BR8 (Bitfield-Mask: 0x01)                             */
#define GPIO_BRR_BR7_Pos                 (7UL)                     /*!< BR7 (Bit 7)                                           */
#define GPIO_BRR_BR7_Msk                 (0x80UL)                  /*!< BR7 (Bitfield-Mask: 0x01)                             */
#define GPIO_BRR_BR7                     (0x80UL)                  /*!< BR7 (Bitfield-Mask: 0x01)                             */
#define GPIO_BRR_BR6_Pos                 (6UL)                     /*!< BR6 (Bit 6)                                           */
#define GPIO_BRR_BR6_Msk                 (0x40UL)                  /*!< BR6 (Bitfield-Mask: 0x01)                             */
#define GPIO_BRR_BR6                     (0x40UL)                  /*!< BR6 (Bitfield-Mask: 0x01)                             */
#define GPIO_BRR_BR5_Pos                 (5UL)                     /*!< BR5 (Bit 5)                                           */
#define GPIO_BRR_BR5_Msk                 (0x20UL)                  /*!< BR5 (Bitfield-Mask: 0x01)                             */
#define GPIO_BRR_BR5                     (0x20UL)                  /*!< BR5 (Bitfield-Mask: 0x01)                             */
#define GPIO_BRR_BR4_Pos                 (4UL)                     /*!< BR4 (Bit 4)                                           */
#define GPIO_BRR_BR4_Msk                 (0x10UL)                  /*!< BR4 (Bitfield-Mask: 0x01)                             */
#define GPIO_BRR_BR4                     (0x10UL)                  /*!< BR4 (Bitfield-Mask: 0x01)                             */
#define GPIO_BRR_BR3_Pos                 (3UL)                     /*!< BR3 (Bit 3)                                           */
#define GPIO_BRR_BR3_Msk                 (0x8UL)                   /*!< BR3 (Bitfield-Mask: 0x01)                             */
#define GPIO_BRR_BR3                     (0x8UL)                   /*!< BR3 (Bitfield-Mask: 0x01)                             */
#define GPIO_BRR_BR2_Pos                 (2UL)                     /*!< BR2 (Bit 2)                                           */
#define GPIO_BRR_BR2_Msk                 (0x4UL)                   /*!< BR2 (Bitfield-Mask: 0x01)                             */
#define GPIO_BRR_BR2                     (0x4UL)                   /*!< BR2 (Bitfield-Mask: 0x01)                             */
#define GPIO_BRR_BR1_Pos                 (1UL)                     /*!< BR1 (Bit 1)                                           */
#define GPIO_BRR_BR1_Msk                 (0x2UL)                   /*!< BR1 (Bitfield-Mask: 0x01)                             */
#define GPIO_BRR_BR1                     (0x2UL)                   /*!< BR1 (Bitfield-Mask: 0x01)                             */
#define GPIO_BRR_BR0_Pos                 (0UL)                     /*!< BR0 (Bit 0)                                           */
#define GPIO_BRR_BR0_Msk                 (0x1UL)                   /*!< BR0 (Bitfield-Mask: 0x01)                             */
#define GPIO_BRR_BR0                     (0x1UL)                   /*!< BR0 (Bitfield-Mask: 0x01)                             */


/* =========================================================================================================================== */
/* ================                                          SYSCFG                                           ================ */
/* =========================================================================================================================== */

/* =========================================================  CFGR1  ========================================================= */
#define SYSCFG_CFGR1_MEM_MODE_Pos         (0UL)                     /*!< MEM_MODE (Bit 0)                                      */
#define SYSCFG_CFGR1_MEM_MODE_Msk         (0x3UL)                   /*!< MEM_MODE (Bitfield-Mask: 0x03)                        */
#define SYSCFG_CFGR1_MEM_MODE             (0x3UL)                   /*!< MEM_MODE (Bitfield-Mask: 0x03)                        */
/* =========================================================  CFGR2  ========================================================= */
#define SYSCFG_CFGR2_ETR_SRC_TIM1_Pos     (19UL)                    /*!< ETR_SRC_TIM1 (Bit 19)                                 */
#define SYSCFG_CFGR2_ETR_SRC_TIM1_Msk     (0x380000UL)              /*!< ETR_SRC_TIM1 (Bitfield-Mask: 0x07)                    */
#define SYSCFG_CFGR2_ETR_SRC_TIM1         (0x380000UL)              /*!< ETR_SRC_TIM1 (Bitfield-Mask: 0x07)                    */
#define SYSCFG_CFGR2_COMP4_BRK_TIM17_Pos  (18UL)                    /*!< COMP4_BRK_TIM17 (Bit 18)                              */
#define SYSCFG_CFGR2_COMP4_BRK_TIM17_Msk  (0x40000UL)               /*!< COMP4_BRK_TIM17 (Bitfield-Mask: 0x01)                 */
#define SYSCFG_CFGR2_COMP4_BRK_TIM17      (0x40000UL)               /*!< COMP4_BRK_TIM17 (Bitfield-Mask: 0x01)                 */
#define SYSCFG_CFGR2_COMP3_BRK_TIM17_Pos  (17UL)                    /*!< COMP3_BRK_TIM17 (Bit 17)                              */
#define SYSCFG_CFGR2_COMP3_BRK_TIM17_Msk  (0x20000UL)               /*!< COMP3_BRK_TIM17 (Bitfield-Mask: 0x01)                 */
#define SYSCFG_CFGR2_COMP3_BRK_TIM17      (0x20000UL)               /*!< COMP3_BRK_TIM17 (Bitfield-Mask: 0x01)                 */
#define SYSCFG_CFGR2_COMP2_BRK_TIM17_Pos  (16UL)                    /*!< COMP2_BRK_TIM17 (Bit 16)                              */
#define SYSCFG_CFGR2_COMP2_BRK_TIM17_Msk  (0x10000UL)               /*!< COMP2_BRK_TIM17 (Bitfield-Mask: 0x01)                 */
#define SYSCFG_CFGR2_COMP2_BRK_TIM17      (0x10000UL)               /*!< COMP2_BRK_TIM17 (Bitfield-Mask: 0x01)                 */
#define SYSCFG_CFGR2_COMP1_BRK_TIM17_Pos  (15UL)                    /*!< COMP1_BRK_TIM17 (Bit 15)                              */
#define SYSCFG_CFGR2_COMP1_BRK_TIM17_Msk  (0x8000UL)                /*!< COMP1_BRK_TIM17 (Bitfield-Mask: 0x01)                 */
#define SYSCFG_CFGR2_COMP1_BRK_TIM17      (0x8000UL)                /*!< COMP1_BRK_TIM17 (Bitfield-Mask: 0x01)                 */
#define SYSCFG_CFGR2_COMP4_BRK_TIM16_Pos  (14UL)                    /*!< COMP4_BRK_TIM16 (Bit 14)                              */
#define SYSCFG_CFGR2_COMP4_BRK_TIM16_Msk  (0x4000UL)                /*!< COMP4_BRK_TIM16 (Bitfield-Mask: 0x01)                 */
#define SYSCFG_CFGR2_COMP4_BRK_TIM16      (0x4000UL)                /*!< COMP4_BRK_TIM16 (Bitfield-Mask: 0x01)                 */
#define SYSCFG_CFGR2_COMP3_BRK_TIM16_Pos  (13UL)                    /*!< COMP3_BRK_TIM16 (Bit 13)                              */
#define SYSCFG_CFGR2_COMP3_BRK_TIM16_Msk  (0x2000UL)                /*!< COMP3_BRK_TIM16 (Bitfield-Mask: 0x01)                 */
#define SYSCFG_CFGR2_COMP3_BRK_TIM16      (0x2000UL)                /*!< COMP3_BRK_TIM16 (Bitfield-Mask: 0x01)                 */
#define SYSCFG_CFGR2_COMP2_BRK_TIM16_Pos  (12UL)                    /*!< COMP2_BRK_TIM16 (Bit 12)                              */
#define SYSCFG_CFGR2_COMP2_BRK_TIM16_Msk  (0x1000UL)                /*!< COMP2_BRK_TIM16 (Bitfield-Mask: 0x01)                 */
#define SYSCFG_CFGR2_COMP2_BRK_TIM16      (0x1000UL)                /*!< COMP2_BRK_TIM16 (Bitfield-Mask: 0x01)                 */
#define SYSCFG_CFGR2_COMP1_BRK_TIM16_Pos  (11UL)                    /*!< COMP1_BRK_TIM16 (Bit 11)                              */
#define SYSCFG_CFGR2_COMP1_BRK_TIM16_Msk  (0x800UL)                 /*!< COMP1_BRK_TIM16 (Bitfield-Mask: 0x01)                 */
#define SYSCFG_CFGR2_COMP1_BRK_TIM16      (0x800UL)                 /*!< COMP1_BRK_TIM16 (Bitfield-Mask: 0x01)                 */
#define SYSCFG_CFGR2_COMP4_BRK_TIM15_Pos  (10UL)                    /*!< COMP4_BRK_TIM15 (Bit 10)                              */
#define SYSCFG_CFGR2_COMP4_BRK_TIM15_Msk  (0x400UL)                 /*!< COMP4_BRK_TIM15 (Bitfield-Mask: 0x01)                 */
#define SYSCFG_CFGR2_COMP4_BRK_TIM15      (0x400UL)                 /*!< COMP4_BRK_TIM15 (Bitfield-Mask: 0x01)                 */
#define SYSCFG_CFGR2_COMP3_BRK_TIM15_Pos  (9UL)                     /*!< COMP3_BRK_TIM15 (Bit 9)                               */
#define SYSCFG_CFGR2_COMP3_BRK_TIM15_Msk  (0x200UL)                 /*!< COMP3_BRK_TIM15 (Bitfield-Mask: 0x01)                 */
#define SYSCFG_CFGR2_COMP3_BRK_TIM15      (0x200UL)                 /*!< COMP3_BRK_TIM15 (Bitfield-Mask: 0x01)                 */
#define SYSCFG_CFGR2_COMP2_BRK_TIM15_Pos  (8UL)                     /*!< COMP2_BRK_TIM15 (Bit 8)                               */
#define SYSCFG_CFGR2_COMP2_BRK_TIM15_Msk  (0x100UL)                 /*!< COMP2_BRK_TIM15 (Bitfield-Mask: 0x01)                 */
#define SYSCFG_CFGR2_COMP2_BRK_TIM15      (0x100UL)                 /*!< COMP2_BRK_TIM15 (Bitfield-Mask: 0x01)                 */
#define SYSCFG_CFGR2_COMP1_BRK_TIM15_Pos  (7UL)                     /*!< COMP1_BRK_TIM15 (Bit 7)                               */
#define SYSCFG_CFGR2_COMP1_BRK_TIM15_Msk  (0x80UL)                  /*!< COMP1_BRK_TIM15 (Bitfield-Mask: 0x01)                 */
#define SYSCFG_CFGR2_COMP1_BRK_TIM15      (0x80UL)                  /*!< COMP1_BRK_TIM15 (Bitfield-Mask: 0x01)                 */
#define SYSCFG_CFGR2_COMP4_BRK_TIM1_Pos   (6UL)                     /*!< COMP4_BRK_TIM1 (Bit 6)                                */
#define SYSCFG_CFGR2_COMP4_BRK_TIM1_Msk   (0x40UL)                  /*!< COMP4_BRK_TIM1 (Bitfield-Mask: 0x01)                  */
#define SYSCFG_CFGR2_COMP4_BRK_TIM1       (0x40UL)                  /*!< COMP4_BRK_TIM1 (Bitfield-Mask: 0x01)                  */
#define SYSCFG_CFGR2_COMP3_BRK_TIM1_Pos   (5UL)                     /*!< COMP3_BRK_TIM1 (Bit 5)                                */
#define SYSCFG_CFGR2_COMP3_BRK_TIM1_Msk   (0x20UL)                  /*!< COMP3_BRK_TIM1 (Bitfield-Mask: 0x01)                  */
#define SYSCFG_CFGR2_COMP3_BRK_TIM1       (0x20UL)                  /*!< COMP3_BRK_TIM1 (Bitfield-Mask: 0x01)                  */
#define SYSCFG_CFGR2_COMP2_BRK_TIM1_Pos   (4UL)                     /*!< COMP2_BRK_TIM1 (Bit 4)                                */
#define SYSCFG_CFGR2_COMP2_BRK_TIM1_Msk   (0x10UL)                  /*!< COMP2_BRK_TIM1 (Bitfield-Mask: 0x01)                  */
#define SYSCFG_CFGR2_COMP2_BRK_TIM1       (0x10UL)                  /*!< COMP2_BRK_TIM1 (Bitfield-Mask: 0x01)                  */
#define SYSCFG_CFGR2_COMP1_BRK_TIM1_Pos   (3UL)                     /*!< COMP1_BRK_TIM1 (Bit 3)                                */
#define SYSCFG_CFGR2_COMP1_BRK_TIM1_Msk   (0x8UL)                   /*!< COMP1_BRK_TIM1 (Bitfield-Mask: 0x01)                  */
#define SYSCFG_CFGR2_COMP1_BRK_TIM1       (0x8UL)                   /*!< COMP1_BRK_TIM1 (Bitfield-Mask: 0x01)                  */
#define SYSCFG_CFGR2_PVD_LOCK_Pos         (2UL)                     /*!< PVD_LOCK (Bit 2)                                      */
#define SYSCFG_CFGR2_PVD_LOCK_Msk         (0x4UL)                   /*!< PVD_LOCK (Bitfield-Mask: 0x01)                        */
#define SYSCFG_CFGR2_PVD_LOCK             (0x4UL)                   /*!< PVD_LOCK (Bitfield-Mask: 0x01)                        */
#define SYSCFG_CFGR2_LOCKUP_LOCK_Pos      (0UL)                     /*!< LOCKUP_LOCK (Bit 0)                                   */
#define SYSCFG_CFGR2_LOCKUP_LOCK_Msk      (0x1UL)                   /*!< LOCKUP_LOCK (Bitfield-Mask: 0x01)                     */
#define SYSCFG_CFGR2_LOCKUP_LOCK          (0x1UL)                   /*!< LOCKUP_LOCK (Bitfield-Mask: 0x01)                     */
/* =========================================================  CFGR3  ========================================================= */
#define SYSCFG_CFGR3_DMA3_MAP_Pos         (16UL)                    /*!< DMA3_MAP (Bit 16)                                     */
#define SYSCFG_CFGR3_DMA3_MAP_Msk         (0x3f0000UL)              /*!< DMA3_MAP (Bitfield-Mask: 0x3f)                        */
#define SYSCFG_CFGR3_DMA3_MAP             (0x3f0000UL)              /*!< DMA3_MAP (Bitfield-Mask: 0x3f)                        */
#define SYSCFG_CFGR3_DMA2_MAP_Pos         (8UL)                     /*!< DMA2_MAP (Bit 8)                                      */
#define SYSCFG_CFGR3_DMA2_MAP_Msk         (0x3f00UL)                /*!< DMA2_MAP (Bitfield-Mask: 0x3f)                        */
#define SYSCFG_CFGR3_DMA2_MAP             (0x3f00UL)                /*!< DMA2_MAP (Bitfield-Mask: 0x3f)                        */
#define SYSCFG_CFGR3_DMA1_MAP_Pos         (0UL)                     /*!< DMA1_MAP (Bit 0)                                      */
#define SYSCFG_CFGR3_DMA1_MAP_Msk         (0x3fUL)                  /*!< DMA1_MAP (Bitfield-Mask: 0x3f)                        */
#define SYSCFG_CFGR3_DMA1_MAP             (0x3fUL)                  /*!< DMA1_MAP (Bitfield-Mask: 0x3f)                        */
/* =========================================================  CFGR4  ========================================================= */
#define SYSCFG_CFGR4_DMA5_MAP_Pos         (8UL)                     /*!< DMA5_MAP (Bit 8)                                      */
#define SYSCFG_CFGR4_DMA5_MAP_Msk         (0x3f00UL)                /*!< DMA5_MAP (Bitfield-Mask: 0x3f)                        */
#define SYSCFG_CFGR4_DMA5_MAP             (0x3f00UL)                /*!< DMA5_MAP (Bitfield-Mask: 0x3f)                        */
#define SYSCFG_CFGR4_DMA4_MAP_Pos         (0UL)                     /*!< DMA4_MAP (Bit 0)                                      */
#define SYSCFG_CFGR4_DMA4_MAP_Msk         (0x3fUL)                  /*!< DMA4_MAP (Bitfield-Mask: 0x3f)                        */
#define SYSCFG_CFGR4_DMA4_MAP             (0x3fUL)                  /*!< DMA4_MAP (Bitfield-Mask: 0x3f)                        */
/* ====================================================  SRAM_TEST_CFGR  ===================================================== */
#define SYSCFG_SRAM_TEST_CFGR_RME_Pos     (5UL)                     /*!< RME (Bit 5)                                           */
#define SYSCFG_SRAM_TEST_CFGR_RME_Msk     (0x20UL)                  /*!< RME (Bitfield-Mask: 0x01)                             */
#define SYSCFG_SRAM_TEST_CFGR_RME         (0x20UL)                  /*!< RME (Bitfield-Mask: 0x01)                             */
#define SYSCFG_SRAM_TEST_CFGR_RM_Pos      (1UL)                     /*!< RM (Bit 1)                                            */
#define SYSCFG_SRAM_TEST_CFGR_RM_Msk      (0x1eUL)                  /*!< RM (Bitfield-Mask: 0x0f)                              */
#define SYSCFG_SRAM_TEST_CFGR_RM          (0x1eUL)                  /*!< RM (Bitfield-Mask: 0x0f)                              */
#define SYSCFG_SRAM_TEST_CFGR_SRAM_TESTEN_Pos (0UL)                 /*!< SRAM_TESTEN (Bit 0)                                   */
#define SYSCFG_SRAM_TEST_CFGR_SRAM_TESTEN_Msk (0x1UL)               /*!< SRAM_TESTEN (Bitfield-Mask: 0x01)                     */
#define SYSCFG_SRAM_TEST_CFGR_SRAM_TESTEN     (0x1UL)               /*!< SRAM_TESTEN (Bitfield-Mask: 0x01)                     */


/* =========================================================================================================================== */
/* ================                                            DMA                                            ================ */
/* =========================================================================================================================== */

/* ==========================================================  ISR  ========================================================== */
#define DMA_ISR_TEIF5_Pos                 (19UL)                    /*!< TEIF5 (Bit 19)                                        */
#define DMA_ISR_TEIF5_Msk                 (0x80000UL)               /*!< TEIF5 (Bitfield-Mask: 0x01)                           */
#define DMA_ISR_TEIF5                     (0x80000UL)               /*!< TEIF5 (Bitfield-Mask: 0x01)                           */
#define DMA_ISR_HTIF5_Pos                 (18UL)                    /*!< HTIF5 (Bit 18)                                        */
#define DMA_ISR_HTIF5_Msk                 (0x40000UL)               /*!< HTIF5 (Bitfield-Mask: 0x01)                           */
#define DMA_ISR_HTIF5                     (0x40000UL)               /*!< HTIF5 (Bitfield-Mask: 0x01)                           */
#define DMA_ISR_TCIF5_Pos                 (17UL)                    /*!< TCIF5 (Bit 17)                                        */
#define DMA_ISR_TCIF5_Msk                 (0x20000UL)               /*!< TCIF5 (Bitfield-Mask: 0x01)                           */
#define DMA_ISR_TCIF5                     (0x20000UL)               /*!< TCIF5 (Bitfield-Mask: 0x01)                           */
#define DMA_ISR_GIF5_Pos                  (16UL)                    /*!< GIF5 (Bit 16)                                         */
#define DMA_ISR_GIF5_Msk                  (0x10000UL)               /*!< GIF5 (Bitfield-Mask: 0x01)                            */
#define DMA_ISR_GIF5                      (0x10000UL)               /*!< GIF5 (Bitfield-Mask: 0x01)                            */
#define DMA_ISR_TEIF4_Pos                 (15UL)                    /*!< TEIF4 (Bit 15)                                        */
#define DMA_ISR_TEIF4_Msk                 (0x8000UL)                /*!< TEIF4 (Bitfield-Mask: 0x01)                           */
#define DMA_ISR_TEIF4                     (0x8000UL)                /*!< TEIF4 (Bitfield-Mask: 0x01)                           */
#define DMA_ISR_HTIF4_Pos                 (14UL)                    /*!< HTIF4 (Bit 14)                                        */
#define DMA_ISR_HTIF4_Msk                 (0x4000UL)                /*!< HTIF4 (Bitfield-Mask: 0x01)                           */
#define DMA_ISR_HTIF4                     (0x4000UL)                /*!< HTIF4 (Bitfield-Mask: 0x01)                           */
#define DMA_ISR_TCIF4_Pos                 (13UL)                    /*!< TCIF4 (Bit 13)                                        */
#define DMA_ISR_TCIF4_Msk                 (0x2000UL)                /*!< TCIF4 (Bitfield-Mask: 0x01)                           */
#define DMA_ISR_TCIF4                     (0x2000UL)                /*!< TCIF4 (Bitfield-Mask: 0x01)                           */
#define DMA_ISR_GIF4_Pos                  (12UL)                    /*!< GIF4 (Bit 12)                                         */
#define DMA_ISR_GIF4_Msk                  (0x1000UL)                /*!< GIF4 (Bitfield-Mask: 0x01)                            */
#define DMA_ISR_GIF4                      (0x1000UL)                /*!< GIF4 (Bitfield-Mask: 0x01)                            */
#define DMA_ISR_TEIF3_Pos                 (11UL)                    /*!< TEIF3 (Bit 11)                                        */
#define DMA_ISR_TEIF3_Msk                 (0x800UL)                 /*!< TEIF3 (Bitfield-Mask: 0x01)                           */
#define DMA_ISR_TEIF3                     (0x800UL)                 /*!< TEIF3 (Bitfield-Mask: 0x01)                           */
#define DMA_ISR_HTIF3_Pos                 (10UL)                    /*!< HTIF3 (Bit 10)                                        */
#define DMA_ISR_HTIF3_Msk                 (0x400UL)                 /*!< HTIF3 (Bitfield-Mask: 0x01)                           */
#define DMA_ISR_HTIF3                     (0x400UL)                 /*!< HTIF3 (Bitfield-Mask: 0x01)                           */
#define DMA_ISR_TCIF3_Pos                 (9UL)                     /*!< TCIF3 (Bit 9)                                         */
#define DMA_ISR_TCIF3_Msk                 (0x200UL)                 /*!< TCIF3 (Bitfield-Mask: 0x01)                           */
#define DMA_ISR_TCIF3                     (0x200UL)                 /*!< TCIF3 (Bitfield-Mask: 0x01)                           */
#define DMA_ISR_GIF3_Pos                  (8UL)                     /*!< GIF3 (Bit 8)                                          */
#define DMA_ISR_GIF3_Msk                  (0x100UL)                 /*!< GIF3 (Bitfield-Mask: 0x01)                            */
#define DMA_ISR_GIF3                      (0x100UL)                 /*!< GIF3 (Bitfield-Mask: 0x01)                            */
#define DMA_ISR_TEIF2_Pos                 (7UL)                     /*!< TEIF2 (Bit 7)                                         */
#define DMA_ISR_TEIF2_Msk                 (0x80UL)                  /*!< TEIF2 (Bitfield-Mask: 0x01)                           */
#define DMA_ISR_TEIF2                     (0x80UL)                  /*!< TEIF2 (Bitfield-Mask: 0x01)                           */
#define DMA_ISR_HTIF2_Pos                 (6UL)                     /*!< HTIF2 (Bit 6)                                         */
#define DMA_ISR_HTIF2_Msk                 (0x40UL)                  /*!< HTIF2 (Bitfield-Mask: 0x01)                           */
#define DMA_ISR_HTIF2                     (0x40UL)                  /*!< HTIF2 (Bitfield-Mask: 0x01)                           */
#define DMA_ISR_TCIF2_Pos                 (5UL)                     /*!< TCIF2 (Bit 5)                                         */
#define DMA_ISR_TCIF2_Msk                 (0x20UL)                  /*!< TCIF2 (Bitfield-Mask: 0x01)                           */
#define DMA_ISR_TCIF2                     (0x20UL)                  /*!< TCIF2 (Bitfield-Mask: 0x01)                           */
#define DMA_ISR_GIF2_Pos                  (4UL)                     /*!< GIF2 (Bit 4)                                          */
#define DMA_ISR_GIF2_Msk                  (0x10UL)                  /*!< GIF2 (Bitfield-Mask: 0x01)                            */
#define DMA_ISR_GIF2                      (0x10UL)                  /*!< GIF2 (Bitfield-Mask: 0x01)                            */
#define DMA_ISR_TEIF1_Pos                 (3UL)                     /*!< TEIF1 (Bit 3)                                         */
#define DMA_ISR_TEIF1_Msk                 (0x8UL)                   /*!< TEIF1 (Bitfield-Mask: 0x01)                           */
#define DMA_ISR_TEIF1                     (0x8UL)                   /*!< TEIF1 (Bitfield-Mask: 0x01)                           */
#define DMA_ISR_HTIF1_Pos                 (2UL)                     /*!< HTIF1 (Bit 2)                                         */
#define DMA_ISR_HTIF1_Msk                 (0x4UL)                   /*!< HTIF1 (Bitfield-Mask: 0x01)                           */
#define DMA_ISR_HTIF1                     (0x4UL)                   /*!< HTIF1 (Bitfield-Mask: 0x01)                           */
#define DMA_ISR_TCIF1_Pos                 (1UL)                     /*!< TCIF1 (Bit 1)                                         */
#define DMA_ISR_TCIF1_Msk                 (0x2UL)                   /*!< TCIF1 (Bitfield-Mask: 0x01)                           */
#define DMA_ISR_TCIF1                     (0x2UL)                   /*!< TCIF1 (Bitfield-Mask: 0x01)                           */
#define DMA_ISR_GIF1_Pos                  (0UL)                     /*!< GIF1 (Bit 0)                                          */
#define DMA_ISR_GIF1_Msk                  (0x1UL)                   /*!< GIF1 (Bitfield-Mask: 0x01)                            */
#define DMA_ISR_GIF1                      (0x1UL)                   /*!< GIF1 (Bitfield-Mask: 0x01)                            */
/* =========================================================  IFCR  ========================================================== */
#define DMA_IFCR_CTEIF5_Pos               (19UL)                    /*!< CTEIF5 (Bit 19)                                       */
#define DMA_IFCR_CTEIF5_Msk               (0x80000UL)               /*!< CTEIF5 (Bitfield-Mask: 0x01)                          */
#define DMA_IFCR_CTEIF5                   (0x80000UL)               /*!< CTEIF5 (Bitfield-Mask: 0x01)                          */
#define DMA_IFCR_CHTIF5_Pos               (18UL)                    /*!< CHTIF5 (Bit 18)                                       */
#define DMA_IFCR_CHTIF5_Msk               (0x40000UL)               /*!< CHTIF5 (Bitfield-Mask: 0x01)                          */
#define DMA_IFCR_CHTIF5                   (0x40000UL)               /*!< CHTIF5 (Bitfield-Mask: 0x01)                          */
#define DMA_IFCR_CTCIF5_Pos               (17UL)                    /*!< CTCIF5 (Bit 17)                                       */
#define DMA_IFCR_CTCIF5_Msk               (0x20000UL)               /*!< CTCIF5 (Bitfield-Mask: 0x01)                          */
#define DMA_IFCR_CTCIF5                   (0x20000UL)               /*!< CTCIF5 (Bitfield-Mask: 0x01)                          */
#define DMA_IFCR_CGIF5_Pos                (16UL)                    /*!< CGIF5 (Bit 16)                                        */
#define DMA_IFCR_CGIF5_Msk                (0x10000UL)               /*!< CGIF5 (Bitfield-Mask: 0x01)                           */
#define DMA_IFCR_CGIF5                    (0x10000UL)               /*!< CGIF5 (Bitfield-Mask: 0x01)                           */
#define DMA_IFCR_CTEIF4_Pos               (15UL)                    /*!< CTEIF4 (Bit 15)                                       */
#define DMA_IFCR_CTEIF4_Msk               (0x8000UL)                /*!< CTEIF4 (Bitfield-Mask: 0x01)                          */
#define DMA_IFCR_CTEIF4                   (0x8000UL)                /*!< CTEIF4 (Bitfield-Mask: 0x01)                          */
#define DMA_IFCR_CHTIF4_Pos               (14UL)                    /*!< CHTIF4 (Bit 14)                                       */
#define DMA_IFCR_CHTIF4_Msk               (0x4000UL)                /*!< CHTIF4 (Bitfield-Mask: 0x01)                          */
#define DMA_IFCR_CHTIF4                   (0x4000UL)                /*!< CHTIF4 (Bitfield-Mask: 0x01)                          */
#define DMA_IFCR_CTCIF4_Pos               (13UL)                    /*!< CTCIF4 (Bit 13)                                       */
#define DMA_IFCR_CTCIF4_Msk               (0x2000UL)                /*!< CTCIF4 (Bitfield-Mask: 0x01)                          */
#define DMA_IFCR_CTCIF4                   (0x2000UL)                /*!< CTCIF4 (Bitfield-Mask: 0x01)                          */
#define DMA_IFCR_CGIF4_Pos                (12UL)                    /*!< CGIF4 (Bit 12)                                        */
#define DMA_IFCR_CGIF4_Msk                (0x1000UL)                /*!< CGIF4 (Bitfield-Mask: 0x01)                           */
#define DMA_IFCR_CGIF4                    (0x1000UL)                /*!< CGIF4 (Bitfield-Mask: 0x01)                           */
#define DMA_IFCR_CTEIF3_Pos               (11UL)                    /*!< CTEIF3 (Bit 11)                                       */
#define DMA_IFCR_CTEIF3_Msk               (0x800UL)                 /*!< CTEIF3 (Bitfield-Mask: 0x01)                          */
#define DMA_IFCR_CTEIF3                   (0x800UL)                 /*!< CTEIF3 (Bitfield-Mask: 0x01)                          */
#define DMA_IFCR_CHTIF3_Pos               (10UL)                    /*!< CHTIF3 (Bit 10)                                       */
#define DMA_IFCR_CHTIF3_Msk               (0x400UL)                 /*!< CHTIF3 (Bitfield-Mask: 0x01)                          */
#define DMA_IFCR_CHTIF3                   (0x400UL)                 /*!< CHTIF3 (Bitfield-Mask: 0x01)                          */
#define DMA_IFCR_CTCIF3_Pos               (9UL)                     /*!< CTCIF3 (Bit 9)                                        */
#define DMA_IFCR_CTCIF3_Msk               (0x200UL)                 /*!< CTCIF3 (Bitfield-Mask: 0x01)                          */
#define DMA_IFCR_CTCIF3                   (0x200UL)                 /*!< CTCIF3 (Bitfield-Mask: 0x01)                          */
#define DMA_IFCR_CGIF3_Pos                (8UL)                     /*!< CGIF3 (Bit 8)                                         */
#define DMA_IFCR_CGIF3_Msk                (0x100UL)                 /*!< CGIF3 (Bitfield-Mask: 0x01)                           */
#define DMA_IFCR_CGIF3                    (0x100UL)                 /*!< CGIF3 (Bitfield-Mask: 0x01)                           */
#define DMA_IFCR_CTEIF2_Pos               (7UL)                     /*!< CTEIF2 (Bit 7)                                        */
#define DMA_IFCR_CTEIF2_Msk               (0x80UL)                  /*!< CTEIF2 (Bitfield-Mask: 0x01)                          */
#define DMA_IFCR_CTEIF2                   (0x80UL)                  /*!< CTEIF2 (Bitfield-Mask: 0x01)                          */
#define DMA_IFCR_CHTIF2_Pos               (6UL)                     /*!< CHTIF2 (Bit 6)                                        */
#define DMA_IFCR_CHTIF2_Msk               (0x40UL)                  /*!< CHTIF2 (Bitfield-Mask: 0x01)                          */
#define DMA_IFCR_CHTIF2                   (0x40UL)                  /*!< CHTIF2 (Bitfield-Mask: 0x01)                          */
#define DMA_IFCR_CTCIF2_Pos               (5UL)                     /*!< CTCIF2 (Bit 5)                                        */
#define DMA_IFCR_CTCIF2_Msk               (0x20UL)                  /*!< CTCIF2 (Bitfield-Mask: 0x01)                          */
#define DMA_IFCR_CTCIF2                   (0x20UL)                  /*!< CTCIF2 (Bitfield-Mask: 0x01)                          */
#define DMA_IFCR_CGIF2_Pos                (4UL)                     /*!< CGIF2 (Bit 4)                                         */
#define DMA_IFCR_CGIF2_Msk                (0x10UL)                  /*!< CGIF2 (Bitfield-Mask: 0x01)                           */
#define DMA_IFCR_CGIF2                    (0x10UL)                  /*!< CGIF2 (Bitfield-Mask: 0x01)                           */
#define DMA_IFCR_CTEIF1_Pos               (3UL)                     /*!< CTEIF1 (Bit 3)                                        */
#define DMA_IFCR_CTEIF1_Msk               (0x8UL)                   /*!< CTEIF1 (Bitfield-Mask: 0x01)                          */
#define DMA_IFCR_CTEIF1                   (0x8UL)                   /*!< CTEIF1 (Bitfield-Mask: 0x01)                          */
#define DMA_IFCR_CHTIF1_Pos               (2UL)                     /*!< CHTIF1 (Bit 2)                                        */
#define DMA_IFCR_CHTIF1_Msk               (0x4UL)                   /*!< CHTIF1 (Bitfield-Mask: 0x01)                          */
#define DMA_IFCR_CHTIF1                   (0x4UL)                   /*!< CHTIF1 (Bitfield-Mask: 0x01)                          */
#define DMA_IFCR_CTCIF1_Pos               (1UL)                     /*!< CTCIF1 (Bit 1)                                        */
#define DMA_IFCR_CTCIF1_Msk               (0x2UL)                   /*!< CTCIF1 (Bitfield-Mask: 0x01)                          */
#define DMA_IFCR_CTCIF1                   (0x2UL)                   /*!< CTCIF1 (Bitfield-Mask: 0x01)                          */
#define DMA_IFCR_CGIF1_Pos                (0UL)                     /*!< CGIF1 (Bit 0)                                         */
#define DMA_IFCR_CGIF1_Msk                (0x1UL)                   /*!< CGIF1 (Bitfield-Mask: 0x01)                           */
#define DMA_IFCR_CGIF1                    (0x1UL)                   /*!< CGIF1 (Bitfield-Mask: 0x01)                           */


/* =========================================================================================================================== */
/* ================                                       DMA_CHANNEL1                                        ================ */
/* =========================================================================================================================== */

/* ==========================================================  CCR  ========================================================== */
#define DMA_CHANNEL_CCR_TRANS_MODE_Pos   (15UL)                    /*!< TRANS_MODE (Bit 15)                                   */
#define DMA_CHANNEL_CCR_TRANS_MODE_Msk   (0x8000UL)                /*!< TRANS_MODE (Bitfield-Mask: 0x01)                      */
#define DMA_CHANNEL_CCR_TRANS_MODE       (0x8000UL)                /*!< TRANS_MODE (Bitfield-Mask: 0x01)                      */
#define DMA_CHANNEL_CCR_MEM2MEM_Pos      (14UL)                    /*!< MEM2MEM (Bit 14)                                      */
#define DMA_CHANNEL_CCR_MEM2MEM_Msk      (0x4000UL)                /*!< MEM2MEM (Bitfield-Mask: 0x01)                         */
#define DMA_CHANNEL_CCR_MEM2MEM          (0x4000UL)                /*!< MEM2MEM (Bitfield-Mask: 0x01)                         */
#define DMA_CHANNEL_CCR_PL_Pos           (12UL)                    /*!< PL (Bit 12)                                           */
#define DMA_CHANNEL_CCR_PL_Msk           (0x3000UL)                /*!< PL (Bitfield-Mask: 0x03)                              */
#define DMA_CHANNEL_CCR_PL               (0x3000UL)                /*!< PL (Bitfield-Mask: 0x03)                              */
#define DMA_CHANNEL_CCR_MSIZE_Pos        (10UL)                    /*!< MSIZE (Bit 10)                                        */
#define DMA_CHANNEL_CCR_MSIZE_Msk        (0xc00UL)                 /*!< MSIZE (Bitfield-Mask: 0x03)                           */
#define DMA_CHANNEL_CCR_MSIZE            (0xc00UL)                 /*!< MSIZE (Bitfield-Mask: 0x03)                           */
#define DMA_CHANNEL_CCR_PSIZE_Pos        (8UL)                     /*!< PSIZE (Bit 8)                                         */
#define DMA_CHANNEL_CCR_PSIZE_Msk        (0x300UL)                 /*!< PSIZE (Bitfield-Mask: 0x03)                           */
#define DMA_CHANNEL_CCR_PSIZE            (0x300UL)                 /*!< PSIZE (Bitfield-Mask: 0x03)                           */
#define DMA_CHANNEL_CCR_MINC_Pos         (7UL)                     /*!< MINC (Bit 7)                                          */
#define DMA_CHANNEL_CCR_MINC_Msk         (0x80UL)                  /*!< MINC (Bitfield-Mask: 0x01)                            */
#define DMA_CHANNEL_CCR_MINC             (0x80UL)                  /*!< MINC (Bitfield-Mask: 0x01)                            */
#define DMA_CHANNEL_CCR_PINC_Pos         (6UL)                     /*!< PINC (Bit 6)                                          */
#define DMA_CHANNEL_CCR_PINC_Msk         (0x40UL)                  /*!< PINC (Bitfield-Mask: 0x01)                            */
#define DMA_CHANNEL_CCR_PINC             (0x40UL)                  /*!< PINC (Bitfield-Mask: 0x01)                            */
#define DMA_CHANNEL_CCR_CIRC_Pos         (5UL)                     /*!< CIRC (Bit 5)                                          */
#define DMA_CHANNEL_CCR_CIRC_Msk         (0x20UL)                  /*!< CIRC (Bitfield-Mask: 0x01)                            */
#define DMA_CHANNEL_CCR_CIRC             (0x20UL)                  /*!< CIRC (Bitfield-Mask: 0x01)                            */
#define DMA_CHANNEL_CCR_DIR_Pos          (4UL)                     /*!< DIR (Bit 4)                                           */
#define DMA_CHANNEL_CCR_DIR_Msk          (0x10UL)                  /*!< DIR (Bitfield-Mask: 0x01)                             */
#define DMA_CHANNEL_CCR_DIR              (0x10UL)                  /*!< DIR (Bitfield-Mask: 0x01)                             */
#define DMA_CHANNEL_CCR_TEIE_Pos         (3UL)                     /*!< TEIE (Bit 3)                                          */
#define DMA_CHANNEL_CCR_TEIE_Msk         (0x8UL)                   /*!< TEIE (Bitfield-Mask: 0x01)                            */
#define DMA_CHANNEL_CCR_TEIE             (0x8UL)                   /*!< TEIE (Bitfield-Mask: 0x01)                            */
#define DMA_CHANNEL_CCR_HTIE_Pos         (2UL)                     /*!< HTIE (Bit 2)                                          */
#define DMA_CHANNEL_CCR_HTIE_Msk         (0x4UL)                   /*!< HTIE (Bitfield-Mask: 0x01)                            */
#define DMA_CHANNEL_CCR_HTIE             (0x4UL)                   /*!< HTIE (Bitfield-Mask: 0x01)                            */
#define DMA_CHANNEL_CCR_TCIE_Pos         (1UL)                     /*!< TCIE (Bit 1)                                          */
#define DMA_CHANNEL_CCR_TCIE_Msk         (0x2UL)                   /*!< TCIE (Bitfield-Mask: 0x01)                            */
#define DMA_CHANNEL_CCR_TCIE             (0x2UL)                   /*!< TCIE (Bitfield-Mask: 0x01)                            */
#define DMA_CHANNEL_CCR_EN_Pos           (0UL)                     /*!< EN (Bit 0)                                            */
#define DMA_CHANNEL_CCR_EN_Msk           (0x1UL)                   /*!< EN (Bitfield-Mask: 0x01)                              */
#define DMA_CHANNEL_CCR_EN               (0x1UL)                   /*!< EN (Bitfield-Mask: 0x01)                              */
/* =========================================================  CNDTR  ========================================================= */
#define DMA_CHANNEL_CNDTR_NDT_Pos        (0UL)                     /*!< NDT (Bit 0)                                           */
#define DMA_CHANNEL_CNDTR_NDT_Msk        (0xffffUL)                /*!< NDT (Bitfield-Mask: 0xffff)                           */
#define DMA_CHANNEL_CNDTR_NDT            (0xffffUL)                /*!< NDT (Bitfield-Mask: 0xffff)                           */
/* =========================================================  CPAR  ========================================================== */
#define DMA_CHANNEL_CPAR_PA_Pos          (0UL)                     /*!< PA (Bit 0)                                            */
#define DMA_CHANNEL_CPAR_PA_Msk          (0xffffffffUL)            /*!< PA (Bitfield-Mask: 0xffffffff)                        */
#define DMA_CHANNEL_CPAR_PA              (0xffffffffUL)            /*!< PA (Bitfield-Mask: 0xffffffff)                        */
/* =========================================================  CMAR  ========================================================== */
#define DMA_CHANNEL_CMAR_MA_Pos          (0UL)                     /*!< MA (Bit 0)                                            */
#define DMA_CHANNEL_CMAR_MA_Msk          (0xffffffffUL)            /*!< MA (Bitfield-Mask: 0xffffffff)                        */
#define DMA_CHANNEL_CMAR_MA              (0xffffffffUL)            /*!< MA (Bitfield-Mask: 0xffffffff)                        */


/* =========================================================================================================================== */
/* ================                                           EXTI                                            ================ */
/* =========================================================================================================================== */

/* =========================================================  RTSR  ========================================================== */
#define EXTI_RTSR_RT24_Pos                (24UL)                    /*!< RT24 (Bit 24)                                         */
#define EXTI_RTSR_RT24_Msk                (0x1000000UL)             /*!< RT24 (Bitfield-Mask: 0x01)                            */
#define EXTI_RTSR_RT24                    (0x1000000UL)             /*!< RT24 (Bitfield-Mask: 0x01)                            */
#define EXTI_RTSR_RT22_Pos                (22UL)                    /*!< RT22 (Bit 22)                                         */
#define EXTI_RTSR_RT22_Msk                (0x400000UL)              /*!< RT22 (Bitfield-Mask: 0x01)                            */
#define EXTI_RTSR_RT22                    (0x400000UL)              /*!< RT22 (Bitfield-Mask: 0x01)                            */
#define EXTI_RTSR_RT18_Pos                (18UL)                    /*!< RT18 (Bit 18)                                         */
#define EXTI_RTSR_RT18_Msk                (0x40000UL)               /*!< RT18 (Bitfield-Mask: 0x01)                            */
#define EXTI_RTSR_RT18                    (0x40000UL)               /*!< RT18 (Bitfield-Mask: 0x01)                            */
#define EXTI_RTSR_RT17_Pos                (17UL)                    /*!< RT17 (Bit 17)                                         */
#define EXTI_RTSR_RT17_Msk                (0x20000UL)               /*!< RT17 (Bitfield-Mask: 0x01)                            */
#define EXTI_RTSR_RT17                    (0x20000UL)               /*!< RT17 (Bitfield-Mask: 0x01)                            */
#define EXTI_RTSR_RT16_Pos                (16UL)                    /*!< RT16 (Bit 16)                                         */
#define EXTI_RTSR_RT16_Msk                (0x10000UL)               /*!< RT16 (Bitfield-Mask: 0x01)                            */
#define EXTI_RTSR_RT16                    (0x10000UL)               /*!< RT16 (Bitfield-Mask: 0x01)                            */
#define EXTI_RTSR_RT15_Pos                (15UL)                    /*!< RT15 (Bit 15)                                         */
#define EXTI_RTSR_RT15_Msk                (0x8000UL)                /*!< RT15 (Bitfield-Mask: 0x01)                            */
#define EXTI_RTSR_RT15                    (0x8000UL)                /*!< RT15 (Bitfield-Mask: 0x01)                            */
#define EXTI_RTSR_RT14_Pos                (14UL)                    /*!< RT14 (Bit 14)                                         */
#define EXTI_RTSR_RT14_Msk                (0x4000UL)                /*!< RT14 (Bitfield-Mask: 0x01)                            */
#define EXTI_RTSR_RT14                    (0x4000UL)                /*!< RT14 (Bitfield-Mask: 0x01)                            */
#define EXTI_RTSR_RT13_Pos                (13UL)                    /*!< RT13 (Bit 13)                                         */
#define EXTI_RTSR_RT13_Msk                (0x2000UL)                /*!< RT13 (Bitfield-Mask: 0x01)                            */
#define EXTI_RTSR_RT13                    (0x2000UL)                /*!< RT13 (Bitfield-Mask: 0x01)                            */
#define EXTI_RTSR_RT12_Pos                (12UL)                    /*!< RT12 (Bit 12)                                         */
#define EXTI_RTSR_RT12_Msk                (0x1000UL)                /*!< RT12 (Bitfield-Mask: 0x01)                            */
#define EXTI_RTSR_RT12                    (0x1000UL)                /*!< RT12 (Bitfield-Mask: 0x01)                            */
#define EXTI_RTSR_RT11_Pos                (11UL)                    /*!< RT11 (Bit 11)                                         */
#define EXTI_RTSR_RT11_Msk                (0x800UL)                 /*!< RT11 (Bitfield-Mask: 0x01)                            */
#define EXTI_RTSR_RT11                    (0x800UL)                 /*!< RT11 (Bitfield-Mask: 0x01)                            */
#define EXTI_RTSR_RT10_Pos                (10UL)                    /*!< RT10 (Bit 10)                                         */
#define EXTI_RTSR_RT10_Msk                (0x400UL)                 /*!< RT10 (Bitfield-Mask: 0x01)                            */
#define EXTI_RTSR_RT10                    (0x400UL)                 /*!< RT10 (Bitfield-Mask: 0x01)                            */
#define EXTI_RTSR_RT9_Pos                 (9UL)                     /*!< RT9 (Bit 9)                                           */
#define EXTI_RTSR_RT9_Msk                 (0x200UL)                 /*!< RT9 (Bitfield-Mask: 0x01)                             */
#define EXTI_RTSR_RT9                     (0x200UL)                 /*!< RT9 (Bitfield-Mask: 0x01)                             */
#define EXTI_RTSR_RT8_Pos                 (8UL)                     /*!< RT8 (Bit 8)                                           */
#define EXTI_RTSR_RT8_Msk                 (0x100UL)                 /*!< RT8 (Bitfield-Mask: 0x01)                             */
#define EXTI_RTSR_RT8                     (0x100UL)                 /*!< RT8 (Bitfield-Mask: 0x01)                             */
#define EXTI_RTSR_RT7_Pos                 (7UL)                     /*!< RT7 (Bit 7)                                           */
#define EXTI_RTSR_RT7_Msk                 (0x80UL)                  /*!< RT7 (Bitfield-Mask: 0x01)                             */
#define EXTI_RTSR_RT7                     (0x80UL)                  /*!< RT7 (Bitfield-Mask: 0x01)                             */
#define EXTI_RTSR_RT6_Pos                 (6UL)                     /*!< RT6 (Bit 6)                                           */
#define EXTI_RTSR_RT6_Msk                 (0x40UL)                  /*!< RT6 (Bitfield-Mask: 0x01)                             */
#define EXTI_RTSR_RT6                     (0x40UL)                  /*!< RT6 (Bitfield-Mask: 0x01)                             */
#define EXTI_RTSR_RT5_Pos                 (5UL)                     /*!< RT5 (Bit 5)                                           */
#define EXTI_RTSR_RT5_Msk                 (0x20UL)                  /*!< RT5 (Bitfield-Mask: 0x01)                             */
#define EXTI_RTSR_RT5                     (0x20UL)                  /*!< RT5 (Bitfield-Mask: 0x01)                             */
#define EXTI_RTSR_RT4_Pos                 (4UL)                     /*!< RT4 (Bit 4)                                           */
#define EXTI_RTSR_RT4_Msk                 (0x10UL)                  /*!< RT4 (Bitfield-Mask: 0x01)                             */
#define EXTI_RTSR_RT4                     (0x10UL)                  /*!< RT4 (Bitfield-Mask: 0x01)                             */
#define EXTI_RTSR_RT3_Pos                 (3UL)                     /*!< RT3 (Bit 3)                                           */
#define EXTI_RTSR_RT3_Msk                 (0x8UL)                   /*!< RT3 (Bitfield-Mask: 0x01)                             */
#define EXTI_RTSR_RT3                     (0x8UL)                   /*!< RT3 (Bitfield-Mask: 0x01)                             */
#define EXTI_RTSR_RT2_Pos                 (2UL)                     /*!< RT2 (Bit 2)                                           */
#define EXTI_RTSR_RT2_Msk                 (0x4UL)                   /*!< RT2 (Bitfield-Mask: 0x01)                             */
#define EXTI_RTSR_RT2                     (0x4UL)                   /*!< RT2 (Bitfield-Mask: 0x01)                             */
#define EXTI_RTSR_RT1_Pos                 (1UL)                     /*!< RT1 (Bit 1)                                           */
#define EXTI_RTSR_RT1_Msk                 (0x2UL)                   /*!< RT1 (Bitfield-Mask: 0x01)                             */
#define EXTI_RTSR_RT1                     (0x2UL)                   /*!< RT1 (Bitfield-Mask: 0x01)                             */
#define EXTI_RTSR_RT0_Pos                 (0UL)                     /*!< RT0 (Bit 0)                                           */
#define EXTI_RTSR_RT0_Msk                 (0x1UL)                   /*!< RT0 (Bitfield-Mask: 0x01)                             */
#define EXTI_RTSR_RT0                     (0x1UL)                   /*!< RT0 (Bitfield-Mask: 0x01)                             */
/* =========================================================  FTSR  ========================================================== */
#define EXTI_FTSR_FT24_Pos                (24UL)                    /*!< FT24 (Bit 24)                                         */
#define EXTI_FTSR_FT24_Msk                (0x1000000UL)             /*!< FT24 (Bitfield-Mask: 0x01)                            */
#define EXTI_FTSR_FT24                    (0x1000000UL)             /*!< FT24 (Bitfield-Mask: 0x01)                            */
#define EXTI_FTSR_FT22_Pos                (22UL)                    /*!< FT22 (Bit 22)                                         */
#define EXTI_FTSR_FT22_Msk                (0x400000UL)              /*!< FT22 (Bitfield-Mask: 0x01)                            */
#define EXTI_FTSR_FT22                    (0x400000UL)              /*!< FT22 (Bitfield-Mask: 0x01)                            */
#define EXTI_FTSR_FT18_Pos                (18UL)                    /*!< FT18 (Bit 18)                                         */
#define EXTI_FTSR_FT18_Msk                (0x40000UL)               /*!< FT18 (Bitfield-Mask: 0x01)                            */
#define EXTI_FTSR_FT18                    (0x40000UL)               /*!< FT18 (Bitfield-Mask: 0x01)                            */
#define EXTI_FTSR_FT17_Pos                (17UL)                    /*!< FT17 (Bit 17)                                         */
#define EXTI_FTSR_FT17_Msk                (0x20000UL)               /*!< FT17 (Bitfield-Mask: 0x01)                            */
#define EXTI_FTSR_FT17                    (0x20000UL)               /*!< FT17 (Bitfield-Mask: 0x01)                            */
#define EXTI_FTSR_FT16_Pos                (16UL)                    /*!< FT16 (Bit 16)                                         */
#define EXTI_FTSR_FT16_Msk                (0x10000UL)               /*!< FT16 (Bitfield-Mask: 0x01)                            */
#define EXTI_FTSR_FT16                    (0x10000UL)               /*!< FT16 (Bitfield-Mask: 0x01)                            */
#define EXTI_FTSR_FT15_Pos                (15UL)                    /*!< FT15 (Bit 15)                                         */
#define EXTI_FTSR_FT15_Msk                (0x8000UL)                /*!< FT15 (Bitfield-Mask: 0x01)                            */
#define EXTI_FTSR_FT15                    (0x8000UL)                /*!< FT15 (Bitfield-Mask: 0x01)                            */
#define EXTI_FTSR_FT14_Pos                (14UL)                    /*!< FT14 (Bit 14)                                         */
#define EXTI_FTSR_FT14_Msk                (0x4000UL)                /*!< FT14 (Bitfield-Mask: 0x01)                            */
#define EXTI_FTSR_FT14                    (0x4000UL)                /*!< FT14 (Bitfield-Mask: 0x01)                            */
#define EXTI_FTSR_FT13_Pos                (13UL)                    /*!< FT13 (Bit 13)                                         */
#define EXTI_FTSR_FT13_Msk                (0x2000UL)                /*!< FT13 (Bitfield-Mask: 0x01)                            */
#define EXTI_FTSR_FT13                    (0x2000UL)                /*!< FT13 (Bitfield-Mask: 0x01)                            */
#define EXTI_FTSR_FT12_Pos                (12UL)                    /*!< FT12 (Bit 12)                                         */
#define EXTI_FTSR_FT12_Msk                (0x1000UL)                /*!< FT12 (Bitfield-Mask: 0x01)                            */
#define EXTI_FTSR_FT12                    (0x1000UL)                /*!< FT12 (Bitfield-Mask: 0x01)                            */
#define EXTI_FTSR_FT11_Pos                (11UL)                    /*!< FT11 (Bit 11)                                         */
#define EXTI_FTSR_FT11_Msk                (0x800UL)                 /*!< FT11 (Bitfield-Mask: 0x01)                            */
#define EXTI_FTSR_FT11                    (0x800UL)                 /*!< FT11 (Bitfield-Mask: 0x01)                            */
#define EXTI_FTSR_FT10_Pos                (10UL)                    /*!< FT10 (Bit 10)                                         */
#define EXTI_FTSR_FT10_Msk                (0x400UL)                 /*!< FT10 (Bitfield-Mask: 0x01)                            */
#define EXTI_FTSR_FT10                    (0x400UL)                 /*!< FT10 (Bitfield-Mask: 0x01)                            */
#define EXTI_FTSR_FT9_Pos                 (9UL)                     /*!< FT9 (Bit 9)                                           */
#define EXTI_FTSR_FT9_Msk                 (0x200UL)                 /*!< FT9 (Bitfield-Mask: 0x01)                             */
#define EXTI_FTSR_FT9                     (0x200UL)                 /*!< FT9 (Bitfield-Mask: 0x01)                             */
#define EXTI_FTSR_FT8_Pos                 (8UL)                     /*!< FT8 (Bit 8)                                           */
#define EXTI_FTSR_FT8_Msk                 (0x100UL)                 /*!< FT8 (Bitfield-Mask: 0x01)                             */
#define EXTI_FTSR_FT8                     (0x100UL)                 /*!< FT8 (Bitfield-Mask: 0x01)                             */
#define EXTI_FTSR_FT7_Pos                 (7UL)                     /*!< FT7 (Bit 7)                                           */
#define EXTI_FTSR_FT7_Msk                 (0x80UL)                  /*!< FT7 (Bitfield-Mask: 0x01)                             */
#define EXTI_FTSR_FT7                     (0x80UL)                  /*!< FT7 (Bitfield-Mask: 0x01)                             */
#define EXTI_FTSR_FT6_Pos                 (6UL)                     /*!< FT6 (Bit 6)                                           */
#define EXTI_FTSR_FT6_Msk                 (0x40UL)                  /*!< FT6 (Bitfield-Mask: 0x01)                             */
#define EXTI_FTSR_FT6                     (0x40UL)                  /*!< FT6 (Bitfield-Mask: 0x01)                             */
#define EXTI_FTSR_FT5_Pos                 (5UL)                     /*!< FT5 (Bit 5)                                           */
#define EXTI_FTSR_FT5_Msk                 (0x20UL)                  /*!< FT5 (Bitfield-Mask: 0x01)                             */
#define EXTI_FTSR_FT5                     (0x20UL)                  /*!< FT5 (Bitfield-Mask: 0x01)                             */
#define EXTI_FTSR_FT4_Pos                 (4UL)                     /*!< FT4 (Bit 4)                                           */
#define EXTI_FTSR_FT4_Msk                 (0x10UL)                  /*!< FT4 (Bitfield-Mask: 0x01)                             */
#define EXTI_FTSR_FT4                     (0x10UL)                  /*!< FT4 (Bitfield-Mask: 0x01)                             */
#define EXTI_FTSR_FT3_Pos                 (3UL)                     /*!< FT3 (Bit 3)                                           */
#define EXTI_FTSR_FT3_Msk                 (0x8UL)                   /*!< FT3 (Bitfield-Mask: 0x01)                             */
#define EXTI_FTSR_FT3                     (0x8UL)                   /*!< FT3 (Bitfield-Mask: 0x01)                             */
#define EXTI_FTSR_FT2_Pos                 (2UL)                     /*!< FT2 (Bit 2)                                           */
#define EXTI_FTSR_FT2_Msk                 (0x4UL)                   /*!< FT2 (Bitfield-Mask: 0x01)                             */
#define EXTI_FTSR_FT2                     (0x4UL)                   /*!< FT2 (Bitfield-Mask: 0x01)                             */
#define EXTI_FTSR_FT1_Pos                 (1UL)                     /*!< FT1 (Bit 1)                                           */
#define EXTI_FTSR_FT1_Msk                 (0x2UL)                   /*!< FT1 (Bitfield-Mask: 0x01)                             */
#define EXTI_FTSR_FT1                     (0x2UL)                   /*!< FT1 (Bitfield-Mask: 0x01)                             */
#define EXTI_FTSR_FT0_Pos                 (0UL)                     /*!< FT0 (Bit 0)                                           */
#define EXTI_FTSR_FT0_Msk                 (0x1UL)                   /*!< FT0 (Bitfield-Mask: 0x01)                             */
#define EXTI_FTSR_FT0                     (0x1UL)                   /*!< FT0 (Bitfield-Mask: 0x01)                             */
/* =========================================================  SWIER  ========================================================= */
#define EXTI_SWIER_SWI24_Pos              (24UL)                    /*!< SWI24 (Bit 24)                                        */
#define EXTI_SWIER_SWI24_Msk              (0x1000000UL)             /*!< SWI24 (Bitfield-Mask: 0x01)                           */
#define EXTI_SWIER_SWI24                  (0x1000000UL)             /*!< SWI24 (Bitfield-Mask: 0x01)                           */
#define EXTI_SWIER_SWI22_Pos              (22UL)                    /*!< SWI22 (Bit 22)                                        */
#define EXTI_SWIER_SWI22_Msk              (0x400000UL)              /*!< SWI22 (Bitfield-Mask: 0x01)                           */
#define EXTI_SWIER_SWI22                  (0x400000UL)              /*!< SWI22 (Bitfield-Mask: 0x01)                           */
#define EXTI_SWIER_SWI18_Pos              (18UL)                    /*!< SWI18 (Bit 18)                                        */
#define EXTI_SWIER_SWI18_Msk              (0x40000UL)               /*!< SWI18 (Bitfield-Mask: 0x01)                           */
#define EXTI_SWIER_SWI18                  (0x40000UL)               /*!< SWI18 (Bitfield-Mask: 0x01)                           */
#define EXTI_SWIER_SWI17_Pos              (17UL)                    /*!< SWI17 (Bit 17)                                        */
#define EXTI_SWIER_SWI17_Msk              (0x20000UL)               /*!< SWI17 (Bitfield-Mask: 0x01)                           */
#define EXTI_SWIER_SWI17                  (0x20000UL)               /*!< SWI17 (Bitfield-Mask: 0x01)                           */
#define EXTI_SWIER_SWI16_Pos              (16UL)                    /*!< SWI16 (Bit 16)                                        */
#define EXTI_SWIER_SWI16_Msk              (0x10000UL)               /*!< SWI16 (Bitfield-Mask: 0x01)                           */
#define EXTI_SWIER_SWI16                  (0x10000UL)               /*!< SWI16 (Bitfield-Mask: 0x01)                           */
#define EXTI_SWIER_SWI15_Pos              (15UL)                    /*!< SWI15 (Bit 15)                                        */
#define EXTI_SWIER_SWI15_Msk              (0x8000UL)                /*!< SWI15 (Bitfield-Mask: 0x01)                           */
#define EXTI_SWIER_SWI15                  (0x8000UL)                /*!< SWI15 (Bitfield-Mask: 0x01)                           */
#define EXTI_SWIER_SWI14_Pos              (14UL)                    /*!< SWI14 (Bit 14)                                        */
#define EXTI_SWIER_SWI14_Msk              (0x4000UL)                /*!< SWI14 (Bitfield-Mask: 0x01)                           */
#define EXTI_SWIER_SWI14                  (0x4000UL)                /*!< SWI14 (Bitfield-Mask: 0x01)                           */
#define EXTI_SWIER_SWI13_Pos              (13UL)                    /*!< SWI13 (Bit 13)                                        */
#define EXTI_SWIER_SWI13_Msk              (0x2000UL)                /*!< SWI13 (Bitfield-Mask: 0x01)                           */
#define EXTI_SWIER_SWI13                  (0x2000UL)                /*!< SWI13 (Bitfield-Mask: 0x01)                           */
#define EXTI_SWIER_SWI12_Pos              (12UL)                    /*!< SWI12 (Bit 12)                                        */
#define EXTI_SWIER_SWI12_Msk              (0x1000UL)                /*!< SWI12 (Bitfield-Mask: 0x01)                           */
#define EXTI_SWIER_SWI12                  (0x1000UL)                /*!< SWI12 (Bitfield-Mask: 0x01)                           */
#define EXTI_SWIER_SWI11_Pos              (11UL)                    /*!< SWI11 (Bit 11)                                        */
#define EXTI_SWIER_SWI11_Msk              (0x800UL)                 /*!< SWI11 (Bitfield-Mask: 0x01)                           */
#define EXTI_SWIER_SWI11                  (0x800UL)                 /*!< SWI11 (Bitfield-Mask: 0x01)                           */
#define EXTI_SWIER_SWI10_Pos              (10UL)                    /*!< SWI10 (Bit 10)                                        */
#define EXTI_SWIER_SWI10_Msk              (0x400UL)                 /*!< SWI10 (Bitfield-Mask: 0x01)                           */
#define EXTI_SWIER_SWI10                  (0x400UL)                 /*!< SWI10 (Bitfield-Mask: 0x01)                           */
#define EXTI_SWIER_SWI9_Pos               (9UL)                     /*!< SWI9 (Bit 9)                                          */
#define EXTI_SWIER_SWI9_Msk               (0x200UL)                 /*!< SWI9 (Bitfield-Mask: 0x01)                            */
#define EXTI_SWIER_SWI9                   (0x200UL)                 /*!< SWI9 (Bitfield-Mask: 0x01)                            */
#define EXTI_SWIER_SWI8_Pos               (8UL)                     /*!< SWI8 (Bit 8)                                          */
#define EXTI_SWIER_SWI8_Msk               (0x100UL)                 /*!< SWI8 (Bitfield-Mask: 0x01)                            */
#define EXTI_SWIER_SWI8                   (0x100UL)                 /*!< SWI8 (Bitfield-Mask: 0x01)                            */
#define EXTI_SWIER_SWI7_Pos               (7UL)                     /*!< SWI7 (Bit 7)                                          */
#define EXTI_SWIER_SWI7_Msk               (0x80UL)                  /*!< SWI7 (Bitfield-Mask: 0x01)                            */
#define EXTI_SWIER_SWI7                   (0x80UL)                  /*!< SWI7 (Bitfield-Mask: 0x01)                            */
#define EXTI_SWIER_SWI6_Pos               (6UL)                     /*!< SWI6 (Bit 6)                                          */
#define EXTI_SWIER_SWI6_Msk               (0x40UL)                  /*!< SWI6 (Bitfield-Mask: 0x01)                            */
#define EXTI_SWIER_SWI6                   (0x40UL)                  /*!< SWI6 (Bitfield-Mask: 0x01)                            */
#define EXTI_SWIER_SWI5_Pos               (5UL)                     /*!< SWI5 (Bit 5)                                          */
#define EXTI_SWIER_SWI5_Msk               (0x20UL)                  /*!< SWI5 (Bitfield-Mask: 0x01)                            */
#define EXTI_SWIER_SWI5                   (0x20UL)                  /*!< SWI5 (Bitfield-Mask: 0x01)                            */
#define EXTI_SWIER_SWI4_Pos               (4UL)                     /*!< SWI4 (Bit 4)                                          */
#define EXTI_SWIER_SWI4_Msk               (0x10UL)                  /*!< SWI4 (Bitfield-Mask: 0x01)                            */
#define EXTI_SWIER_SWI4                   (0x10UL)                  /*!< SWI4 (Bitfield-Mask: 0x01)                            */
#define EXTI_SWIER_SWI3_Pos               (3UL)                     /*!< SWI3 (Bit 3)                                          */
#define EXTI_SWIER_SWI3_Msk               (0x8UL)                   /*!< SWI3 (Bitfield-Mask: 0x01)                            */
#define EXTI_SWIER_SWI3                   (0x8UL)                   /*!< SWI3 (Bitfield-Mask: 0x01)                            */
#define EXTI_SWIER_SWI2_Pos               (2UL)                     /*!< SWI2 (Bit 2)                                          */
#define EXTI_SWIER_SWI2_Msk               (0x4UL)                   /*!< SWI2 (Bitfield-Mask: 0x01)                            */
#define EXTI_SWIER_SWI2                   (0x4UL)                   /*!< SWI2 (Bitfield-Mask: 0x01)                            */
#define EXTI_SWIER_SWI1_Pos               (1UL)                     /*!< SWI1 (Bit 1)                                          */
#define EXTI_SWIER_SWI1_Msk               (0x2UL)                   /*!< SWI1 (Bitfield-Mask: 0x01)                            */
#define EXTI_SWIER_SWI1                   (0x2UL)                   /*!< SWI1 (Bitfield-Mask: 0x01)                            */
#define EXTI_SWIER_SWI0_Pos               (0UL)                     /*!< SWI0 (Bit 0)                                          */
#define EXTI_SWIER_SWI0_Msk               (0x1UL)                   /*!< SWI0 (Bitfield-Mask: 0x01)                            */
#define EXTI_SWIER_SWI0                   (0x1UL)                   /*!< SWI0 (Bitfield-Mask: 0x01)                            */
/* ==========================================================  PR  =========================================================== */
#define EXTI_PR_PR24_Pos                  (24UL)                    /*!< PR24 (Bit 24)                                         */
#define EXTI_PR_PR24_Msk                  (0x1000000UL)             /*!< PR24 (Bitfield-Mask: 0x01)                            */
#define EXTI_PR_PR24                      (0x1000000UL)             /*!< PR24 (Bitfield-Mask: 0x01)                            */
#define EXTI_PR_PR22_Pos                  (22UL)                    /*!< PR22 (Bit 22)                                         */
#define EXTI_PR_PR22_Msk                  (0x400000UL)              /*!< PR22 (Bitfield-Mask: 0x01)                            */
#define EXTI_PR_PR22                      (0x400000UL)              /*!< PR22 (Bitfield-Mask: 0x01)                            */
#define EXTI_PR_PR18_Pos                  (18UL)                    /*!< PR18 (Bit 18)                                         */
#define EXTI_PR_PR18_Msk                  (0x40000UL)               /*!< PR18 (Bitfield-Mask: 0x01)                            */
#define EXTI_PR_PR18                      (0x40000UL)               /*!< PR18 (Bitfield-Mask: 0x01)                            */
#define EXTI_PR_PR17_Pos                  (17UL)                    /*!< PR17 (Bit 17)                                         */
#define EXTI_PR_PR17_Msk                  (0x20000UL)               /*!< PR17 (Bitfield-Mask: 0x01)                            */
#define EXTI_PR_PR17                      (0x20000UL)               /*!< PR17 (Bitfield-Mask: 0x01)                            */
#define EXTI_PR_PR16_Pos                  (16UL)                    /*!< PR16 (Bit 16)                                         */
#define EXTI_PR_PR16_Msk                  (0x10000UL)               /*!< PR16 (Bitfield-Mask: 0x01)                            */
#define EXTI_PR_PR16                      (0x10000UL)               /*!< PR16 (Bitfield-Mask: 0x01)                            */
#define EXTI_PR_PR15_Pos                  (15UL)                    /*!< PR15 (Bit 15)                                         */
#define EXTI_PR_PR15_Msk                  (0x8000UL)                /*!< PR15 (Bitfield-Mask: 0x01)                            */
#define EXTI_PR_PR15                      (0x8000UL)                /*!< PR15 (Bitfield-Mask: 0x01)                            */
#define EXTI_PR_PR14_Pos                  (14UL)                    /*!< PR14 (Bit 14)                                         */
#define EXTI_PR_PR14_Msk                  (0x4000UL)                /*!< PR14 (Bitfield-Mask: 0x01)                            */
#define EXTI_PR_PR14                      (0x4000UL)                /*!< PR14 (Bitfield-Mask: 0x01)                            */
#define EXTI_PR_PR13_Pos                  (13UL)                    /*!< PR13 (Bit 13)                                         */
#define EXTI_PR_PR13_Msk                  (0x2000UL)                /*!< PR13 (Bitfield-Mask: 0x01)                            */
#define EXTI_PR_PR13                      (0x2000UL)                /*!< PR13 (Bitfield-Mask: 0x01)                            */
#define EXTI_PR_PR12_Pos                  (12UL)                    /*!< PR12 (Bit 12)                                         */
#define EXTI_PR_PR12_Msk                  (0x1000UL)                /*!< PR12 (Bitfield-Mask: 0x01)                            */
#define EXTI_PR_PR12                      (0x1000UL)                /*!< PR12 (Bitfield-Mask: 0x01)                            */
#define EXTI_PR_PR11_Pos                  (11UL)                    /*!< PR11 (Bit 11)                                         */
#define EXTI_PR_PR11_Msk                  (0x800UL)                 /*!< PR11 (Bitfield-Mask: 0x01)                            */
#define EXTI_PR_PR11                      (0x800UL)                 /*!< PR11 (Bitfield-Mask: 0x01)                            */
#define EXTI_PR_PR10_Pos                  (10UL)                    /*!< PR10 (Bit 10)                                         */
#define EXTI_PR_PR10_Msk                  (0x400UL)                 /*!< PR10 (Bitfield-Mask: 0x01)                            */
#define EXTI_PR_PR10                      (0x400UL)                 /*!< PR10 (Bitfield-Mask: 0x01)                            */
#define EXTI_PR_PR9_Pos                   (9UL)                     /*!< PR9 (Bit 9)                                           */
#define EXTI_PR_PR9_Msk                   (0x200UL)                 /*!< PR9 (Bitfield-Mask: 0x01)                             */
#define EXTI_PR_PR9                       (0x200UL)                 /*!< PR9 (Bitfield-Mask: 0x01)                             */
#define EXTI_PR_PR8_Pos                   (8UL)                     /*!< PR8 (Bit 8)                                           */
#define EXTI_PR_PR8_Msk                   (0x100UL)                 /*!< PR8 (Bitfield-Mask: 0x01)                             */
#define EXTI_PR_PR8                       (0x100UL)                 /*!< PR8 (Bitfield-Mask: 0x01)                             */
#define EXTI_PR_PR7_Pos                   (7UL)                     /*!< PR7 (Bit 7)                                           */
#define EXTI_PR_PR7_Msk                   (0x80UL)                  /*!< PR7 (Bitfield-Mask: 0x01)                             */
#define EXTI_PR_PR7                       (0x80UL)                  /*!< PR7 (Bitfield-Mask: 0x01)                             */
#define EXTI_PR_PR6_Pos                   (6UL)                     /*!< PR6 (Bit 6)                                           */
#define EXTI_PR_PR6_Msk                   (0x40UL)                  /*!< PR6 (Bitfield-Mask: 0x01)                             */
#define EXTI_PR_PR6                       (0x40UL)                  /*!< PR6 (Bitfield-Mask: 0x01)                             */
#define EXTI_PR_PR5_Pos                   (5UL)                     /*!< PR5 (Bit 5)                                           */
#define EXTI_PR_PR5_Msk                   (0x20UL)                  /*!< PR5 (Bitfield-Mask: 0x01)                             */
#define EXTI_PR_PR5                       (0x20UL)                  /*!< PR5 (Bitfield-Mask: 0x01)                             */
#define EXTI_PR_PR4_Pos                   (4UL)                     /*!< PR4 (Bit 4)                                           */
#define EXTI_PR_PR4_Msk                   (0x10UL)                  /*!< PR4 (Bitfield-Mask: 0x01)                             */
#define EXTI_PR_PR4                       (0x10UL)                  /*!< PR4 (Bitfield-Mask: 0x01)                             */
#define EXTI_PR_PR3_Pos                   (3UL)                     /*!< PR3 (Bit 3)                                           */
#define EXTI_PR_PR3_Msk                   (0x8UL)                   /*!< PR3 (Bitfield-Mask: 0x01)                             */
#define EXTI_PR_PR3                       (0x8UL)                   /*!< PR3 (Bitfield-Mask: 0x01)                             */
#define EXTI_PR_PR2_Pos                   (2UL)                     /*!< PR2 (Bit 2)                                           */
#define EXTI_PR_PR2_Msk                   (0x4UL)                   /*!< PR2 (Bitfield-Mask: 0x01)                             */
#define EXTI_PR_PR2                       (0x4UL)                   /*!< PR2 (Bitfield-Mask: 0x01)                             */
#define EXTI_PR_PR1_Pos                   (1UL)                     /*!< PR1 (Bit 1)                                           */
#define EXTI_PR_PR1_Msk                   (0x2UL)                   /*!< PR1 (Bitfield-Mask: 0x01)                             */
#define EXTI_PR_PR1                       (0x2UL)                   /*!< PR1 (Bitfield-Mask: 0x01)                             */
#define EXTI_PR_PR0_Pos                   (0UL)                     /*!< PR0 (Bit 0)                                           */
#define EXTI_PR_PR0_Msk                   (0x1UL)                   /*!< PR0 (Bitfield-Mask: 0x01)                             */
#define EXTI_PR_PR0                       (0x1UL)                   /*!< PR0 (Bitfield-Mask: 0x01)                             */
/* ========================================================  EXTICR1  ======================================================== */
#define EXTI_EXTICR1_EXTI3_Pos            (24UL)                    /*!< EXTI3 (Bit 24)                                        */
#define EXTI_EXTICR1_EXTI3_Msk            (0x3000000UL)             /*!< EXTI3 (Bitfield-Mask: 0x03)                           */
#define EXTI_EXTICR1_EXTI3                (0x3000000UL)             /*!< EXTI3 (Bitfield-Mask: 0x03)                           */
#define EXTI_EXTICR1_EXTI2_Pos            (16UL)                    /*!< EXTI2 (Bit 16)                                        */
#define EXTI_EXTICR1_EXTI2_Msk            (0x30000UL)               /*!< EXTI2 (Bitfield-Mask: 0x03)                           */
#define EXTI_EXTICR1_EXTI2                (0x30000UL)               /*!< EXTI2 (Bitfield-Mask: 0x03)                           */
#define EXTI_EXTICR1_EXTI1_Pos            (8UL)                     /*!< EXTI1 (Bit 8)                                         */
#define EXTI_EXTICR1_EXTI1_Msk            (0x300UL)                 /*!< EXTI1 (Bitfield-Mask: 0x03)                           */
#define EXTI_EXTICR1_EXTI1                (0x300UL)                 /*!< EXTI1 (Bitfield-Mask: 0x03)                           */
#define EXTI_EXTICR1_EXTI0_Pos            (0UL)                     /*!< EXTI0 (Bit 0)                                         */
#define EXTI_EXTICR1_EXTI0_Msk            (0x3UL)                   /*!< EXTI0 (Bitfield-Mask: 0x03)                           */
#define EXTI_EXTICR1_EXTI0                (0x3UL)                   /*!< EXTI0 (Bitfield-Mask: 0x03)                           */
/* ========================================================  EXTICR2  ======================================================== */
#define EXTI_EXTICR2_EXTI7_Pos            (24UL)                    /*!< EXTI7 (Bit 24)                                        */
#define EXTI_EXTICR2_EXTI7_Msk            (0x3000000UL)             /*!< EXTI7 (Bitfield-Mask: 0x03)                           */
#define EXTI_EXTICR2_EXTI7                (0x3000000UL)             /*!< EXTI7 (Bitfield-Mask: 0x03)                           */
#define EXTI_EXTICR2_EXTI6_Pos            (16UL)                    /*!< EXTI6 (Bit 16)                                        */
#define EXTI_EXTICR2_EXTI6_Msk            (0x30000UL)               /*!< EXTI6 (Bitfield-Mask: 0x03)                           */
#define EXTI_EXTICR2_EXTI6                (0x30000UL)               /*!< EXTI6 (Bitfield-Mask: 0x03)                           */
#define EXTI_EXTICR2_EXTI5_Pos            (8UL)                     /*!< EXTI5 (Bit 8)                                         */
#define EXTI_EXTICR2_EXTI5_Msk            (0x100UL)                 /*!< EXTI5 (Bitfield-Mask: 0x01)                           */
#define EXTI_EXTICR2_EXTI5                (0x100UL)                 /*!< EXTI5 (Bitfield-Mask: 0x01)                           */
#define EXTI_EXTICR2_EXTI4_Pos            (0UL)                     /*!< EXTI4 (Bit 0)                                         */
#define EXTI_EXTICR2_EXTI4_Msk            (0x3UL)                   /*!< EXTI4 (Bitfield-Mask: 0x03)                           */
#define EXTI_EXTICR2_EXTI4                (0x3UL)                   /*!< EXTI4 (Bitfield-Mask: 0x03)                           */
/* ========================================================  EXTICR3  ======================================================== */
#define EXTI_EXTICR3_EXTI11_Pos           (24UL)                    /*!< EXTI11 (Bit 24)                                       */
#define EXTI_EXTICR3_EXTI11_Msk           (0x3000000UL)             /*!< EXTI11 (Bitfield-Mask: 0x03)                          */
#define EXTI_EXTICR3_EXTI11               (0x3000000UL)             /*!< EXTI11 (Bitfield-Mask: 0x03)                          */
#define EXTI_EXTICR3_EXTI10_Pos           (16UL)                    /*!< EXTI10 (Bit 16)                                       */
#define EXTI_EXTICR3_EXTI10_Msk           (0x30000UL)               /*!< EXTI10 (Bitfield-Mask: 0x03)                          */
#define EXTI_EXTICR3_EXTI10               (0x30000UL)               /*!< EXTI10 (Bitfield-Mask: 0x03)                          */
#define EXTI_EXTICR3_EXTI9_Pos            (8UL)                     /*!< EXTI9 (Bit 8)                                         */
#define EXTI_EXTICR3_EXTI9_Msk            (0x300UL)                 /*!< EXTI9 (Bitfield-Mask: 0x03)                           */
#define EXTI_EXTICR3_EXTI9                (0x300UL)                 /*!< EXTI9 (Bitfield-Mask: 0x03)                           */
#define EXTI_EXTICR3_EXTI8_Pos            (0UL)                     /*!< EXTI8 (Bit 0)                                         */
#define EXTI_EXTICR3_EXTI8_Msk            (0x3UL)                   /*!< EXTI8 (Bitfield-Mask: 0x03)                           */
#define EXTI_EXTICR3_EXTI8                (0x3UL)                   /*!< EXTI8 (Bitfield-Mask: 0x03)                           */
/* ========================================================  EXTICR4  ======================================================== */
#define EXTI_EXTICR4_EXTI15_Pos           (24UL)                    /*!< EXTI15 (Bit 24)                                       */
#define EXTI_EXTICR4_EXTI15_Msk           (0x3000000UL)             /*!< EXTI15 (Bitfield-Mask: 0x03)                          */
#define EXTI_EXTICR4_EXTI15               (0x3000000UL)             /*!< EXTI15 (Bitfield-Mask: 0x03)                          */
#define EXTI_EXTICR4_EXTI14_Pos           (16UL)                    /*!< EXTI14 (Bit 16)                                       */
#define EXTI_EXTICR4_EXTI14_Msk           (0x30000UL)               /*!< EXTI14 (Bitfield-Mask: 0x03)                          */
#define EXTI_EXTICR4_EXTI14               (0x30000UL)               /*!< EXTI14 (Bitfield-Mask: 0x03)                          */
#define EXTI_EXTICR4_EXTI13_Pos           (8UL)                     /*!< EXTI13 (Bit 8)                                        */
#define EXTI_EXTICR4_EXTI13_Msk           (0x300UL)                 /*!< EXTI13 (Bitfield-Mask: 0x03)                          */
#define EXTI_EXTICR4_EXTI13               (0x300UL)                 /*!< EXTI13 (Bitfield-Mask: 0x03)                          */
#define EXTI_EXTICR4_EXTI12_Pos           (0UL)                     /*!< EXTI12 (Bit 0)                                        */
#define EXTI_EXTICR4_EXTI12_Msk           (0x1UL)                   /*!< EXTI12 (Bitfield-Mask: 0x01)                          */
#define EXTI_EXTICR4_EXTI12               (0x1UL)                   /*!< EXTI12 (Bitfield-Mask: 0x01)                          */
/* ==========================================================  IMR  ========================================================== */
#define EXTI_IMR_IM29_Pos                 (29UL)                    /*!< IM29 (Bit 29)                                         */
#define EXTI_IMR_IM29_Msk                 (0x20000000UL)            /*!< IM29 (Bitfield-Mask: 0x01)                            */
#define EXTI_IMR_IM29                     (0x20000000UL)            /*!< IM29 (Bitfield-Mask: 0x01)                            */
#define EXTI_IMR_IM24_Pos                 (24UL)                    /*!< IM24 (Bit 24)                                         */
#define EXTI_IMR_IM24_Msk                 (0x1000000UL)             /*!< IM24 (Bitfield-Mask: 0x01)                            */
#define EXTI_IMR_IM24                     (0x1000000UL)             /*!< IM24 (Bitfield-Mask: 0x01)                            */
#define EXTI_IMR_IM22_Pos                 (22UL)                    /*!< IM22 (Bit 22)                                         */
#define EXTI_IMR_IM22_Msk                 (0x400000UL)              /*!< IM22 (Bitfield-Mask: 0x01)                            */
#define EXTI_IMR_IM22                     (0x400000UL)              /*!< IM22 (Bitfield-Mask: 0x01)                            */
#define EXTI_IMR_IM20_Pos                 (20UL)                    /*!< IM20 (Bit 20)                                         */
#define EXTI_IMR_IM20_Msk                 (0x100000UL)              /*!< IM20 (Bitfield-Mask: 0x01)                            */
#define EXTI_IMR_IM20                     (0x100000UL)              /*!< IM20 (Bitfield-Mask: 0x01)                            */
#define EXTI_IMR_IM19_Pos                 (19UL)                    /*!< IM19 (Bit 19)                                         */
#define EXTI_IMR_IM19_Msk                 (0x80000UL)               /*!< IM19 (Bitfield-Mask: 0x01)                            */
#define EXTI_IMR_IM19                     (0x80000UL)               /*!< IM19 (Bitfield-Mask: 0x01)                            */
#define EXTI_IMR_IM18_Pos                 (18UL)                    /*!< IM18 (Bit 18)                                         */
#define EXTI_IMR_IM18_Msk                 (0x40000UL)               /*!< IM18 (Bitfield-Mask: 0x01)                            */
#define EXTI_IMR_IM18                     (0x40000UL)               /*!< IM18 (Bitfield-Mask: 0x01)                            */
#define EXTI_IMR_IM17_Pos                 (17UL)                    /*!< IM17 (Bit 17)                                         */
#define EXTI_IMR_IM17_Msk                 (0x20000UL)               /*!< IM17 (Bitfield-Mask: 0x01)                            */
#define EXTI_IMR_IM17                     (0x20000UL)               /*!< IM17 (Bitfield-Mask: 0x01)                            */
#define EXTI_IMR_IM16_Pos                 (16UL)                    /*!< IM16 (Bit 16)                                         */
#define EXTI_IMR_IM16_Msk                 (0x10000UL)               /*!< IM16 (Bitfield-Mask: 0x01)                            */
#define EXTI_IMR_IM16                     (0x10000UL)               /*!< IM16 (Bitfield-Mask: 0x01)                            */
#define EXTI_IMR_IM15_Pos                 (15UL)                    /*!< IM15 (Bit 15)                                         */
#define EXTI_IMR_IM15_Msk                 (0x8000UL)                /*!< IM15 (Bitfield-Mask: 0x01)                            */
#define EXTI_IMR_IM15                     (0x8000UL)                /*!< IM15 (Bitfield-Mask: 0x01)                            */
#define EXTI_IMR_IM14_Pos                 (14UL)                    /*!< IM14 (Bit 14)                                         */
#define EXTI_IMR_IM14_Msk                 (0x4000UL)                /*!< IM14 (Bitfield-Mask: 0x01)                            */
#define EXTI_IMR_IM14                     (0x4000UL)                /*!< IM14 (Bitfield-Mask: 0x01)                            */
#define EXTI_IMR_IM13_Pos                 (13UL)                    /*!< IM13 (Bit 13)                                         */
#define EXTI_IMR_IM13_Msk                 (0x2000UL)                /*!< IM13 (Bitfield-Mask: 0x01)                            */
#define EXTI_IMR_IM13                     (0x2000UL)                /*!< IM13 (Bitfield-Mask: 0x01)                            */
#define EXTI_IMR_IM12_Pos                 (12UL)                    /*!< IM12 (Bit 12)                                         */
#define EXTI_IMR_IM12_Msk                 (0x1000UL)                /*!< IM12 (Bitfield-Mask: 0x01)                            */
#define EXTI_IMR_IM12                     (0x1000UL)                /*!< IM12 (Bitfield-Mask: 0x01)                            */
#define EXTI_IMR_IM11_Pos                 (11UL)                    /*!< IM11 (Bit 11)                                         */
#define EXTI_IMR_IM11_Msk                 (0x800UL)                 /*!< IM11 (Bitfield-Mask: 0x01)                            */
#define EXTI_IMR_IM11                     (0x800UL)                 /*!< IM11 (Bitfield-Mask: 0x01)                            */
#define EXTI_IMR_IM10_Pos                 (10UL)                    /*!< IM10 (Bit 10)                                         */
#define EXTI_IMR_IM10_Msk                 (0x400UL)                 /*!< IM10 (Bitfield-Mask: 0x01)                            */
#define EXTI_IMR_IM10                     (0x400UL)                 /*!< IM10 (Bitfield-Mask: 0x01)                            */
#define EXTI_IMR_IM9_Pos                  (9UL)                     /*!< IM9 (Bit 9)                                           */
#define EXTI_IMR_IM9_Msk                  (0x200UL)                 /*!< IM9 (Bitfield-Mask: 0x01)                             */
#define EXTI_IMR_IM9                      (0x200UL)                 /*!< IM9 (Bitfield-Mask: 0x01)                             */
#define EXTI_IMR_IM8_Pos                  (8UL)                     /*!< IM8 (Bit 8)                                           */
#define EXTI_IMR_IM8_Msk                  (0x100UL)                 /*!< IM8 (Bitfield-Mask: 0x01)                             */
#define EXTI_IMR_IM8                      (0x100UL)                 /*!< IM8 (Bitfield-Mask: 0x01)                             */
#define EXTI_IMR_IM7_Pos                  (7UL)                     /*!< IM7 (Bit 7)                                           */
#define EXTI_IMR_IM7_Msk                  (0x80UL)                  /*!< IM7 (Bitfield-Mask: 0x01)                             */
#define EXTI_IMR_IM7                      (0x80UL)                  /*!< IM7 (Bitfield-Mask: 0x01)                             */
#define EXTI_IMR_IM6_Pos                  (6UL)                     /*!< IM6 (Bit 6)                                           */
#define EXTI_IMR_IM6_Msk                  (0x40UL)                  /*!< IM6 (Bitfield-Mask: 0x01)                             */
#define EXTI_IMR_IM6                      (0x40UL)                  /*!< IM6 (Bitfield-Mask: 0x01)                             */
#define EXTI_IMR_IM5_Pos                  (5UL)                     /*!< IM5 (Bit 5)                                           */
#define EXTI_IMR_IM5_Msk                  (0x20UL)                  /*!< IM5 (Bitfield-Mask: 0x01)                             */
#define EXTI_IMR_IM5                      (0x20UL)                  /*!< IM5 (Bitfield-Mask: 0x01)                             */
#define EXTI_IMR_IM4_Pos                  (4UL)                     /*!< IM4 (Bit 4)                                           */
#define EXTI_IMR_IM4_Msk                  (0x10UL)                  /*!< IM4 (Bitfield-Mask: 0x01)                             */
#define EXTI_IMR_IM4                      (0x10UL)                  /*!< IM4 (Bitfield-Mask: 0x01)                             */
#define EXTI_IMR_IM3_Pos                  (3UL)                     /*!< IM3 (Bit 3)                                           */
#define EXTI_IMR_IM3_Msk                  (0x8UL)                   /*!< IM3 (Bitfield-Mask: 0x01)                             */
#define EXTI_IMR_IM3                      (0x8UL)                   /*!< IM3 (Bitfield-Mask: 0x01)                             */
#define EXTI_IMR_IM2_Pos                  (2UL)                     /*!< IM2 (Bit 2)                                           */
#define EXTI_IMR_IM2_Msk                  (0x4UL)                   /*!< IM2 (Bitfield-Mask: 0x01)                             */
#define EXTI_IMR_IM2                      (0x4UL)                   /*!< IM2 (Bitfield-Mask: 0x01)                             */
#define EXTI_IMR_IM1_Pos                  (1UL)                     /*!< IM1 (Bit 1)                                           */
#define EXTI_IMR_IM1_Msk                  (0x2UL)                   /*!< IM1 (Bitfield-Mask: 0x01)                             */
#define EXTI_IMR_IM1                      (0x2UL)                   /*!< IM1 (Bitfield-Mask: 0x01)                             */
#define EXTI_IMR_IM0_Pos                  (0UL)                     /*!< IM0 (Bit 0)                                           */
#define EXTI_IMR_IM0_Msk                  (0x1UL)                   /*!< IM0 (Bitfield-Mask: 0x01)                             */
#define EXTI_IMR_IM0                      (0x1UL)                   /*!< IM0 (Bitfield-Mask: 0x01)                             */
/* ==========================================================  EMR  ========================================================== */
#define EXTI_EMR_EM29_Pos                 (29UL)                    /*!< EM29 (Bit 29)                                         */
#define EXTI_EMR_EM29_Msk                 (0x20000000UL)            /*!< EM29 (Bitfield-Mask: 0x01)                            */
#define EXTI_EMR_EM29                     (0x20000000UL)            /*!< EM29 (Bitfield-Mask: 0x01)                            */
#define EXTI_EMR_EM24_Pos                 (24UL)                    /*!< EM24 (Bit 24)                                         */
#define EXTI_EMR_EM24_Msk                 (0x1000000UL)             /*!< EM24 (Bitfield-Mask: 0x01)                            */
#define EXTI_EMR_EM24                     (0x1000000UL)             /*!< EM24 (Bitfield-Mask: 0x01)                            */
#define EXTI_EMR_EM22_Pos                 (22UL)                    /*!< EM22 (Bit 22)                                         */
#define EXTI_EMR_EM22_Msk                 (0x400000UL)              /*!< EM22 (Bitfield-Mask: 0x01)                            */
#define EXTI_EMR_EM22                     (0x400000UL)              /*!< EM22 (Bitfield-Mask: 0x01)                            */
#define EXTI_EMR_EM20_Pos                 (20UL)                    /*!< EM20 (Bit 20)                                         */
#define EXTI_EMR_EM20_Msk                 (0x100000UL)              /*!< EM20 (Bitfield-Mask: 0x01)                            */
#define EXTI_EMR_EM20                     (0x100000UL)              /*!< EM20 (Bitfield-Mask: 0x01)                            */
#define EXTI_EMR_EM19_Pos                 (19UL)                    /*!< EM19 (Bit 19)                                         */
#define EXTI_EMR_EM19_Msk                 (0x80000UL)               /*!< EM19 (Bitfield-Mask: 0x01)                            */
#define EXTI_EMR_EM19                     (0x80000UL)               /*!< EM19 (Bitfield-Mask: 0x01)                            */
#define EXTI_EMR_EM18_Pos                 (18UL)                    /*!< EM18 (Bit 18)                                         */
#define EXTI_EMR_EM18_Msk                 (0x40000UL)               /*!< EM18 (Bitfield-Mask: 0x01)                            */
#define EXTI_EMR_EM18                     (0x40000UL)               /*!< EM18 (Bitfield-Mask: 0x01)                            */
#define EXTI_EMR_EM17_Pos                 (17UL)                    /*!< EM17 (Bit 17)                                         */
#define EXTI_EMR_EM17_Msk                 (0x20000UL)               /*!< EM17 (Bitfield-Mask: 0x01)                            */
#define EXTI_EMR_EM17                     (0x20000UL)               /*!< EM17 (Bitfield-Mask: 0x01)                            */
#define EXTI_EMR_EM16_Pos                 (16UL)                    /*!< EM16 (Bit 16)                                         */
#define EXTI_EMR_EM16_Msk                 (0x10000UL)               /*!< EM16 (Bitfield-Mask: 0x01)                            */
#define EXTI_EMR_EM16                     (0x10000UL)               /*!< EM16 (Bitfield-Mask: 0x01)                            */
#define EXTI_EMR_EM15_Pos                 (15UL)                    /*!< EM15 (Bit 15)                                         */
#define EXTI_EMR_EM15_Msk                 (0x8000UL)                /*!< EM15 (Bitfield-Mask: 0x01)                            */
#define EXTI_EMR_EM15                     (0x8000UL)                /*!< EM15 (Bitfield-Mask: 0x01)                            */
#define EXTI_EMR_EM14_Pos                 (14UL)                    /*!< EM14 (Bit 14)                                         */
#define EXTI_EMR_EM14_Msk                 (0x4000UL)                /*!< EM14 (Bitfield-Mask: 0x01)                            */
#define EXTI_EMR_EM14                     (0x4000UL)                /*!< EM14 (Bitfield-Mask: 0x01)                            */
#define EXTI_EMR_EM13_Pos                 (13UL)                    /*!< EM13 (Bit 13)                                         */
#define EXTI_EMR_EM13_Msk                 (0x2000UL)                /*!< EM13 (Bitfield-Mask: 0x01)                            */
#define EXTI_EMR_EM13                     (0x2000UL)                /*!< EM13 (Bitfield-Mask: 0x01)                            */
#define EXTI_EMR_EM12_Pos                 (12UL)                    /*!< EM12 (Bit 12)                                         */
#define EXTI_EMR_EM12_Msk                 (0x1000UL)                /*!< EM12 (Bitfield-Mask: 0x01)                            */
#define EXTI_EMR_EM12                     (0x1000UL)                /*!< EM12 (Bitfield-Mask: 0x01)                            */
#define EXTI_EMR_EM11_Pos                 (11UL)                    /*!< EM11 (Bit 11)                                         */
#define EXTI_EMR_EM11_Msk                 (0x800UL)                 /*!< EM11 (Bitfield-Mask: 0x01)                            */
#define EXTI_EMR_EM11                     (0x800UL)                 /*!< EM11 (Bitfield-Mask: 0x01)                            */
#define EXTI_EMR_EM10_Pos                 (10UL)                    /*!< EM10 (Bit 10)                                         */
#define EXTI_EMR_EM10_Msk                 (0x400UL)                 /*!< EM10 (Bitfield-Mask: 0x01)                            */
#define EXTI_EMR_EM10                     (0x400UL)                 /*!< EM10 (Bitfield-Mask: 0x01)                            */
#define EXTI_EMR_EM9_Pos                  (9UL)                     /*!< EM9 (Bit 9)                                           */
#define EXTI_EMR_EM9_Msk                  (0x200UL)                 /*!< EM9 (Bitfield-Mask: 0x01)                             */
#define EXTI_EMR_EM9                      (0x200UL)                 /*!< EM9 (Bitfield-Mask: 0x01)                             */
#define EXTI_EMR_EM8_Pos                  (8UL)                     /*!< EM8 (Bit 8)                                           */
#define EXTI_EMR_EM8_Msk                  (0x100UL)                 /*!< EM8 (Bitfield-Mask: 0x01)                             */
#define EXTI_EMR_EM8                      (0x100UL)                 /*!< EM8 (Bitfield-Mask: 0x01)                             */
#define EXTI_EMR_EM7_Pos                  (7UL)                     /*!< EM7 (Bit 7)                                           */
#define EXTI_EMR_EM7_Msk                  (0x80UL)                  /*!< EM7 (Bitfield-Mask: 0x01)                             */
#define EXTI_EMR_EM7                      (0x80UL)                  /*!< EM7 (Bitfield-Mask: 0x01)                             */
#define EXTI_EMR_EM6_Pos                  (6UL)                     /*!< EM6 (Bit 6)                                           */
#define EXTI_EMR_EM6_Msk                  (0x40UL)                  /*!< EM6 (Bitfield-Mask: 0x01)                             */
#define EXTI_EMR_EM6                      (0x40UL)                  /*!< EM6 (Bitfield-Mask: 0x01)                             */
#define EXTI_EMR_EM5_Pos                  (5UL)                     /*!< EM5 (Bit 5)                                           */
#define EXTI_EMR_EM5_Msk                  (0x20UL)                  /*!< EM5 (Bitfield-Mask: 0x01)                             */
#define EXTI_EMR_EM5                      (0x20UL)                  /*!< EM5 (Bitfield-Mask: 0x01)                             */
#define EXTI_EMR_EM4_Pos                  (4UL)                     /*!< EM4 (Bit 4)                                           */
#define EXTI_EMR_EM4_Msk                  (0x10UL)                  /*!< EM4 (Bitfield-Mask: 0x01)                             */
#define EXTI_EMR_EM4                      (0x10UL)                  /*!< EM4 (Bitfield-Mask: 0x01)                             */
#define EXTI_EMR_EM3_Pos                  (3UL)                     /*!< EM3 (Bit 3)                                           */
#define EXTI_EMR_EM3_Msk                  (0x8UL)                   /*!< EM3 (Bitfield-Mask: 0x01)                             */
#define EXTI_EMR_EM3                      (0x8UL)                   /*!< EM3 (Bitfield-Mask: 0x01)                             */
#define EXTI_EMR_EM2_Pos                  (2UL)                     /*!< EM2 (Bit 2)                                           */
#define EXTI_EMR_EM2_Msk                  (0x4UL)                   /*!< EM2 (Bitfield-Mask: 0x01)                             */
#define EXTI_EMR_EM2                      (0x4UL)                   /*!< EM2 (Bitfield-Mask: 0x01)                             */
#define EXTI_EMR_EM1_Pos                  (1UL)                     /*!< EM1 (Bit 1)                                           */
#define EXTI_EMR_EM1_Msk                  (0x2UL)                   /*!< EM1 (Bitfield-Mask: 0x01)                             */
#define EXTI_EMR_EM1                      (0x2UL)                   /*!< EM1 (Bitfield-Mask: 0x01)                             */
#define EXTI_EMR_EM0_Pos                  (0UL)                     /*!< EM0 (Bit 0)                                           */
#define EXTI_EMR_EM0_Msk                  (0x1UL)                   /*!< EM0 (Bitfield-Mask: 0x01)                             */
#define EXTI_EMR_EM0                      (0x1UL)                   /*!< EM0 (Bitfield-Mask: 0x01)                             */


/* =========================================================================================================================== */
/* ================                                            ADC                                            ================ */
/* =========================================================================================================================== */

/* ==========================================================  SR  =========================================================== */
#define ADC_SR_STRT_Pos                   (10UL)                    /*!< STRT (Bit 10)                                         */
#define ADC_SR_STRT_Msk                   (0x400UL)                 /*!< STRT (Bitfield-Mask: 0x01)                            */
#define ADC_SR_STRT                       (0x400UL)                 /*!< STRT (Bitfield-Mask: 0x01)                            */
#define ADC_SR_JSTRT_Pos                  (9UL)                     /*!< JSTRT (Bit 9)                                         */
#define ADC_SR_JSTRT_Msk                  (0x200UL)                 /*!< JSTRT (Bitfield-Mask: 0x01)                           */
#define ADC_SR_JSTRT                      (0x200UL)                 /*!< JSTRT (Bitfield-Mask: 0x01)                           */
#define ADC_SR_OVR_Pos                    (8UL)                     /*!< OVR (Bit 8)                                           */
#define ADC_SR_OVR_Msk                    (0x100UL)                 /*!< OVR (Bitfield-Mask: 0x01)                             */
#define ADC_SR_OVR                        (0x100UL)                 /*!< OVR (Bitfield-Mask: 0x01)                             */
#define ADC_SR_EOS_Pos                    (7UL)                     /*!< EOS (Bit 7)                                           */
#define ADC_SR_EOS_Msk                    (0x80UL)                  /*!< EOS (Bitfield-Mask: 0x01)                             */
#define ADC_SR_EOS                        (0x80UL)                  /*!< EOS (Bitfield-Mask: 0x01)                             */
#define ADC_SR_JEOSEQ_Pos                 (6UL)                     /*!< JEOSEQ (Bit 6)                                        */
#define ADC_SR_JEOSEQ_Msk                 (0x40UL)                  /*!< JEOSEQ (Bitfield-Mask: 0x01)                          */
#define ADC_SR_JEOSEQ                     (0x40UL)                  /*!< JEOSEQ (Bitfield-Mask: 0x01)                          */
#define ADC_SR_EOSEQ_Pos                  (5UL)                     /*!< EOSEQ (Bit 5)                                         */
#define ADC_SR_EOSEQ_Msk                  (0x20UL)                  /*!< EOSEQ (Bitfield-Mask: 0x01)                           */
#define ADC_SR_EOSEQ                      (0x20UL)                  /*!< EOSEQ (Bitfield-Mask: 0x01)                           */
#define ADC_SR_JEOC_Pos                   (4UL)                     /*!< JEOC (Bit 4)                                          */
#define ADC_SR_JEOC_Msk                   (0x10UL)                  /*!< JEOC (Bitfield-Mask: 0x01)                            */
#define ADC_SR_JEOC                       (0x10UL)                  /*!< JEOC (Bitfield-Mask: 0x01)                            */
#define ADC_SR_EOC_Pos                    (3UL)                     /*!< EOC (Bit 3)                                           */
#define ADC_SR_EOC_Msk                    (0x8UL)                   /*!< EOC (Bitfield-Mask: 0x01)                             */
#define ADC_SR_EOC                        (0x8UL)                   /*!< EOC (Bitfield-Mask: 0x01)                             */
#define ADC_SR_EOSMP_Pos                  (2UL)                     /*!< EOSMP (Bit 2)                                         */
#define ADC_SR_EOSMP_Msk                  (0x4UL)                   /*!< EOSMP (Bitfield-Mask: 0x01)                           */
#define ADC_SR_EOSMP                      (0x4UL)                   /*!< EOSMP (Bitfield-Mask: 0x01)                           */
#define ADC_SR_ADRDY_Pos                  (1UL)                     /*!< ADRDY (Bit 1)                                         */
#define ADC_SR_ADRDY_Msk                  (0x2UL)                   /*!< ADRDY (Bitfield-Mask: 0x01)                           */
#define ADC_SR_ADRDY                      (0x2UL)                   /*!< ADRDY (Bitfield-Mask: 0x01)                           */
#define ADC_SR_AWD_Pos                    (0UL)                     /*!< AWD (Bit 0)                                           */
#define ADC_SR_AWD_Msk                    (0x1UL)                   /*!< AWD (Bitfield-Mask: 0x01)                             */
#define ADC_SR_AWD                        (0x1UL)                   /*!< AWD (Bitfield-Mask: 0x01)                             */
/* ==========================================================  CR1  ========================================================== */
#define ADC_CR1_OVRMODE_Pos               (26UL)                    /*!< OVRMODE (Bit 26)                                      */
#define ADC_CR1_OVRMODE_Msk               (0x4000000UL)             /*!< OVRMODE (Bitfield-Mask: 0x01)                         */
#define ADC_CR1_OVRMODE                   (0x4000000UL)             /*!< OVRMODE (Bitfield-Mask: 0x01)                         */
#define ADC_CR1_WAIT_Pos                  (25UL)                    /*!< WAIT (Bit 25)                                         */
#define ADC_CR1_WAIT_Msk                  (0x2000000UL)             /*!< WAIT (Bitfield-Mask: 0x01)                            */
#define ADC_CR1_WAIT                      (0x2000000UL)             /*!< WAIT (Bitfield-Mask: 0x01)                            */
#define ADC_CR1_AWDEN_Pos                 (23UL)                    /*!< AWDEN (Bit 23)                                        */
#define ADC_CR1_AWDEN_Msk                 (0x800000UL)              /*!< AWDEN (Bitfield-Mask: 0x01)                           */
#define ADC_CR1_AWDEN                     (0x800000UL)              /*!< AWDEN (Bitfield-Mask: 0x01)                           */
#define ADC_CR1_JAWDEN_Pos                (22UL)                    /*!< JAWDEN (Bit 22)                                       */
#define ADC_CR1_JAWDEN_Msk                (0x400000UL)              /*!< JAWDEN (Bitfield-Mask: 0x01)                          */
#define ADC_CR1_JAWDEN                    (0x400000UL)              /*!< JAWDEN (Bitfield-Mask: 0x01)                          */
#define ADC_CR1_DISCNUM_Pos               (16UL)                    /*!< DISCNUM (Bit 16)                                      */
#define ADC_CR1_DISCNUM_Msk               (0xf0000UL)               /*!< DISCNUM (Bitfield-Mask: 0x0f)                         */
#define ADC_CR1_DISCNUM                   (0xf0000UL)               /*!< DISCNUM (Bitfield-Mask: 0x0f)                         */
#define ADC_CR1_JDISCEN_Pos               (15UL)                    /*!< JDISCEN (Bit 15)                                      */
#define ADC_CR1_JDISCEN_Msk               (0x8000UL)                /*!< JDISCEN (Bitfield-Mask: 0x01)                         */
#define ADC_CR1_JDISCEN                   (0x8000UL)                /*!< JDISCEN (Bitfield-Mask: 0x01)                         */
#define ADC_CR1_DISCEN_Pos                (14UL)                    /*!< DISCEN (Bit 14)                                       */
#define ADC_CR1_DISCEN_Msk                (0x4000UL)                /*!< DISCEN (Bitfield-Mask: 0x01)                          */
#define ADC_CR1_DISCEN                    (0x4000UL)                /*!< DISCEN (Bitfield-Mask: 0x01)                          */
#define ADC_CR1_JAUTO_Pos                 (13UL)                    /*!< JAUTO (Bit 13)                                        */
#define ADC_CR1_JAUTO_Msk                 (0x2000UL)                /*!< JAUTO (Bitfield-Mask: 0x01)                           */
#define ADC_CR1_JAUTO                     (0x2000UL)                /*!< JAUTO (Bitfield-Mask: 0x01)                           */
#define ADC_CR1_AWDSGL_Pos                (12UL)                    /*!< AWDSGL (Bit 12)                                       */
#define ADC_CR1_AWDSGL_Msk                (0x1000UL)                /*!< AWDSGL (Bitfield-Mask: 0x01)                          */
#define ADC_CR1_AWDSGL                    (0x1000UL)                /*!< AWDSGL (Bitfield-Mask: 0x01)                          */
#define ADC_CR1_SCAN_Pos                  (11UL)                    /*!< SCAN (Bit 11)                                         */
#define ADC_CR1_SCAN_Msk                  (0x800UL)                 /*!< SCAN (Bitfield-Mask: 0x01)                            */
#define ADC_CR1_SCAN                      (0x800UL)                 /*!< SCAN (Bitfield-Mask: 0x01)                            */
#define ADC_CR1_EOSIE_Pos                 (10UL)                    /*!< EOSIE (Bit 10)                                        */
#define ADC_CR1_EOSIE_Msk                 (0x400UL)                 /*!< EOSIE (Bitfield-Mask: 0x01)                           */
#define ADC_CR1_EOSIE                     (0x400UL)                 /*!< EOSIE (Bitfield-Mask: 0x01)                           */
#define ADC_CR1_JEOSEQIE_Pos              (9UL)                     /*!< JEOSEQIE (Bit 9)                                      */
#define ADC_CR1_JEOSEQIE_Msk              (0x200UL)                 /*!< JEOSEQIE (Bitfield-Mask: 0x01)                        */
#define ADC_CR1_JEOSEQIE                  (0x200UL)                 /*!< JEOSEQIE (Bitfield-Mask: 0x01)                        */
#define ADC_CR1_EOSEQIE_Pos               (8UL)                     /*!< EOSEQIE (Bit 8)                                       */
#define ADC_CR1_EOSEQIE_Msk               (0x100UL)                 /*!< EOSEQIE (Bitfield-Mask: 0x01)                         */
#define ADC_CR1_EOSEQIE                   (0x100UL)                 /*!< EOSEQIE (Bitfield-Mask: 0x01)                         */
#define ADC_CR1_JEOCIE_Pos                (7UL)                     /*!< JEOCIE (Bit 7)                                        */
#define ADC_CR1_JEOCIE_Msk                (0x80UL)                  /*!< JEOCIE (Bitfield-Mask: 0x01)                          */
#define ADC_CR1_JEOCIE                    (0x80UL)                  /*!< JEOCIE (Bitfield-Mask: 0x01)                          */
#define ADC_CR1_AWDIE_Pos                 (6UL)                     /*!< AWDIE (Bit 6)                                         */
#define ADC_CR1_AWDIE_Msk                 (0x40UL)                  /*!< AWDIE (Bitfield-Mask: 0x01)                           */
#define ADC_CR1_AWDIE                     (0x40UL)                  /*!< AWDIE (Bitfield-Mask: 0x01)                           */
#define ADC_CR1_EOCIE_Pos                 (5UL)                     /*!< EOCIE (Bit 5)                                         */
#define ADC_CR1_EOCIE_Msk                 (0x20UL)                  /*!< EOCIE (Bitfield-Mask: 0x01)                           */
#define ADC_CR1_EOCIE                     (0x20UL)                  /*!< EOCIE (Bitfield-Mask: 0x01)                           */
#define ADC_CR1_AWDCH_Pos                 (0UL)                     /*!< AWDCH (Bit 0)                                         */
#define ADC_CR1_AWDCH_Msk                 (0x1fUL)                  /*!< AWDCH (Bitfield-Mask: 0x1f)                           */
#define ADC_CR1_AWDCH                     (0x1fUL)                  /*!< AWDCH (Bitfield-Mask: 0x1f)                           */
/* ==========================================================  CR2  ========================================================== */
#define ADC_CR2_CKMODE_Pos                (28UL)                    /*!< CKMODE (Bit 28)                                       */
#define ADC_CR2_CKMODE_Msk                (0xf0000000UL)            /*!< CKMODE (Bitfield-Mask: 0x0f)                          */
#define ADC_CR2_CKMODE                    (0xf0000000UL)            /*!< CKMODE (Bitfield-Mask: 0x0f)                          */
#define ADC_CR2_TSEN_Pos                  (23UL)                    /*!< TSEN (Bit 23)                                         */
#define ADC_CR2_TSEN_Msk                  (0x800000UL)              /*!< TSEN (Bitfield-Mask: 0x01)                            */
#define ADC_CR2_TSEN                      (0x800000UL)              /*!< TSEN (Bitfield-Mask: 0x01)                            */
#define ADC_CR2_SWSTART_Pos               (22UL)                    /*!< SWSTART (Bit 22)                                      */
#define ADC_CR2_SWSTART_Msk               (0x400000UL)              /*!< SWSTART (Bitfield-Mask: 0x01)                         */
#define ADC_CR2_SWSTART                   (0x400000UL)              /*!< SWSTART (Bitfield-Mask: 0x01)                         */
#define ADC_CR2_JSWSTART_Pos              (21UL)                    /*!< JSWSTART (Bit 21)                                     */
#define ADC_CR2_JSWSTART_Msk              (0x200000UL)              /*!< JSWSTART (Bitfield-Mask: 0x01)                        */
#define ADC_CR2_JSWSTART                  (0x200000UL)              /*!< JSWSTART (Bitfield-Mask: 0x01)                        */
#define ADC_CR2_EXTTRIG_Pos               (20UL)                    /*!< EXTTRIG (Bit 20)                                      */
#define ADC_CR2_EXTTRIG_Msk               (0x100000UL)              /*!< EXTTRIG (Bitfield-Mask: 0x01)                         */
#define ADC_CR2_EXTTRIG                   (0x100000UL)              /*!< EXTTRIG (Bitfield-Mask: 0x01)                         */
#define ADC_CR2_EXTSEL_Pos                (17UL)                    /*!< EXTSEL (Bit 17)                                       */
#define ADC_CR2_EXTSEL_Msk                (0xe0000UL)               /*!< EXTSEL (Bitfield-Mask: 0x07)                          */
#define ADC_CR2_EXTSEL                    (0xe0000UL)               /*!< EXTSEL (Bitfield-Mask: 0x07)                          */
#define ADC_CR2_JEXTTRIG_Pos              (15UL)                    /*!< JEXTTRIG (Bit 15)                                     */
#define ADC_CR2_JEXTTRIG_Msk              (0x8000UL)                /*!< JEXTTRIG (Bitfield-Mask: 0x01)                        */
#define ADC_CR2_JEXTTRIG                  (0x8000UL)                /*!< JEXTTRIG (Bitfield-Mask: 0x01)                        */
#define ADC_CR2_JEXTSEL_Pos               (12UL)                    /*!< JEXTSEL (Bit 12)                                      */
#define ADC_CR2_JEXTSEL_Msk               (0x7000UL)                /*!< JEXTSEL (Bitfield-Mask: 0x07)                         */
#define ADC_CR2_JEXTSEL                   (0x7000UL)                /*!< JEXTSEL (Bitfield-Mask: 0x07)                         */
#define ADC_CR2_ALIGN_Pos                 (11UL)                    /*!< ALIGN (Bit 11)                                        */
#define ADC_CR2_ALIGN_Msk                 (0x800UL)                 /*!< ALIGN (Bitfield-Mask: 0x01)                           */
#define ADC_CR2_ALIGN                     (0x800UL)                 /*!< ALIGN (Bitfield-Mask: 0x01)                           */
#define ADC_CR2_DMA_Pos                   (8UL)                     /*!< DMA (Bit 8)                                           */
#define ADC_CR2_DMA_Msk                   (0x100UL)                 /*!< DMA (Bitfield-Mask: 0x01)                             */
#define ADC_CR2_DMA                       (0x100UL)                 /*!< DMA (Bitfield-Mask: 0x01)                             */
#define ADC_CR2_CUR_Pos                   (4UL)                     /*!< CUR (Bit 4)                                           */
#define ADC_CR2_CUR_Msk                   (0x30UL)                  /*!< CUR (Bitfield-Mask: 0x03)                             */
#define ADC_CR2_CUR                       (0x30UL)                  /*!< CUR (Bitfield-Mask: 0x03)                             */
#define ADC_CR2_CONT_Pos                  (1UL)                     /*!< CONT (Bit 1)                                          */
#define ADC_CR2_CONT_Msk                  (0x2UL)                   /*!< CONT (Bitfield-Mask: 0x01)                            */
#define ADC_CR2_CONT                      (0x2UL)                   /*!< CONT (Bitfield-Mask: 0x01)                            */
#define ADC_CR2_ADON_Pos                  (0UL)                     /*!< ADON (Bit 0)                                          */
#define ADC_CR2_ADON_Msk                  (0x1UL)                   /*!< ADON (Bitfield-Mask: 0x01)                            */
#define ADC_CR2_ADON                      (0x1UL)                   /*!< ADON (Bitfield-Mask: 0x01)                            */
/* =========================================================  SMPR  ========================================================== */
#define ADC_SMPR_SMP_Pos                  (0UL)                     /*!< SMP (Bit 0)                                           */
#define ADC_SMPR_SMP_Msk                  (0xfUL)                   /*!< SMP (Bitfield-Mask: 0x0f)                             */
#define ADC_SMPR_SMP                      (0xfUL)                   /*!< SMP (Bitfield-Mask: 0x0f)                             */
/* =========================================================  JOFR1  ========================================================= */
#define ADC_JOFR1_JOFFSET1_Pos            (0UL)                     /*!< JOFFSET1 (Bit 0)                                      */
#define ADC_JOFR1_JOFFSET1_Msk            (0xfffUL)                 /*!< JOFFSET1 (Bitfield-Mask: 0xfff)                       */
#define ADC_JOFR1_JOFFSET1                (0xfffUL)                 /*!< JOFFSET1 (Bitfield-Mask: 0xfff)                       */
/* =========================================================  JOFR2  ========================================================= */
#define ADC_JOFR2_JOFFSET2_Pos            (0UL)                     /*!< JOFFSET2 (Bit 0)                                      */
#define ADC_JOFR2_JOFFSET2_Msk            (0xfffUL)                 /*!< JOFFSET2 (Bitfield-Mask: 0xfff)                       */
#define ADC_JOFR2_JOFFSET2                (0xfffUL)                 /*!< JOFFSET2 (Bitfield-Mask: 0xfff)                       */
/* =========================================================  JOFR3  ========================================================= */
#define ADC_JOFR3_JOFFSET3_Pos            (0UL)                     /*!< JOFFSET3 (Bit 0)                                      */
#define ADC_JOFR3_JOFFSET3_Msk            (0xfffUL)                 /*!< JOFFSET3 (Bitfield-Mask: 0xfff)                       */
#define ADC_JOFR3_JOFFSET3                (0xfffUL)                 /*!< JOFFSET3 (Bitfield-Mask: 0xfff)                       */
/* =========================================================  JOFR4  ========================================================= */
#define ADC_JOFR4_JOFFSET4_Pos            (0UL)                     /*!< JOFFSET4 (Bit 0)                                      */
#define ADC_JOFR4_JOFFSET4_Msk            (0xfffUL)                 /*!< JOFFSET4 (Bitfield-Mask: 0xfff)                       */
#define ADC_JOFR4_JOFFSET4                (0xfffUL)                 /*!< JOFFSET4 (Bitfield-Mask: 0xfff)                       */
/* =========================================================  JOFR5  ========================================================= */
#define ADC_JOFR5_JOFFSET5_Pos            (0UL)                     /*!< JOFFSET5 (Bit 0)                                      */
#define ADC_JOFR5_JOFFSET5_Msk            (0xfffUL)                 /*!< JOFFSET5 (Bitfield-Mask: 0xfff)                       */
#define ADC_JOFR5_JOFFSET5                (0xfffUL)                 /*!< JOFFSET5 (Bitfield-Mask: 0xfff)                       */
/* ==========================================================  HTR  ========================================================== */
#define ADC_HTR_HT_Pos                    (0UL)                     /*!< HT (Bit 0)                                            */
#define ADC_HTR_HT_Msk                    (0xfffUL)                 /*!< HT (Bitfield-Mask: 0xfff)                             */
#define ADC_HTR_HT                        (0xfffUL)                 /*!< HT (Bitfield-Mask: 0xfff)                             */
/* ==========================================================  LTR  ========================================================== */
#define ADC_LTR_LT_Pos                    (0UL)                     /*!< LT (Bit 0)                                            */
#define ADC_LTR_LT_Msk                    (0xfffUL)                 /*!< LT (Bitfield-Mask: 0xfff)                             */
#define ADC_LTR_LT                        (0xfffUL)                 /*!< LT (Bitfield-Mask: 0xfff)                             */
/* =========================================================  SQR1  ========================================================== */
#define ADC_SQR1_L_Pos                    (10UL)                    /*!< L (Bit 10)                                            */
#define ADC_SQR1_L_Msk                    (0x7c00UL)                /*!< L (Bitfield-Mask: 0x1f)                               */
#define ADC_SQR1_L                        (0x7c00UL)                /*!< L (Bitfield-Mask: 0x1f)                               */
#define ADC_SQR1_SQ20_Pos                 (5UL)                     /*!< SQ20 (Bit 5)                                          */
#define ADC_SQR1_SQ20_Msk                 (0x3e0UL)                 /*!< SQ20 (Bitfield-Mask: 0x1f)                            */
#define ADC_SQR1_SQ20                     (0x3e0UL)                 /*!< SQ20 (Bitfield-Mask: 0x1f)                            */
#define ADC_SQR1_SQ19_Pos                 (0UL)                     /*!< SQ19 (Bit 0)                                          */
#define ADC_SQR1_SQ19_Msk                 (0x1fUL)                  /*!< SQ19 (Bitfield-Mask: 0x1f)                            */
#define ADC_SQR1_SQ19                     (0x1fUL)                  /*!< SQ19 (Bitfield-Mask: 0x1f)                            */
/* =========================================================  SQR2  ========================================================== */
#define ADC_SQR2_SQ18_Pos                 (25UL)                    /*!< SQ18 (Bit 25)                                         */
#define ADC_SQR2_SQ18_Msk                 (0x3e000000UL)            /*!< SQ18 (Bitfield-Mask: 0x1f)                            */
#define ADC_SQR2_SQ18                     (0x3e000000UL)            /*!< SQ18 (Bitfield-Mask: 0x1f)                            */
#define ADC_SQR2_SQ17_Pos                 (20UL)                    /*!< SQ17 (Bit 20)                                         */
#define ADC_SQR2_SQ17_Msk                 (0x1f00000UL)             /*!< SQ17 (Bitfield-Mask: 0x1f)                            */
#define ADC_SQR2_SQ17                     (0x1f00000UL)             /*!< SQ17 (Bitfield-Mask: 0x1f)                            */
#define ADC_SQR2_SQ16_Pos                 (15UL)                    /*!< SQ16 (Bit 15)                                         */
#define ADC_SQR2_SQ16_Msk                 (0xf8000UL)               /*!< SQ16 (Bitfield-Mask: 0x1f)                            */
#define ADC_SQR2_SQ16                     (0xf8000UL)               /*!< SQ16 (Bitfield-Mask: 0x1f)                            */
#define ADC_SQR2_SQ15_Pos                 (10UL)                    /*!< SQ15 (Bit 10)                                         */
#define ADC_SQR2_SQ15_Msk                 (0x7c00UL)                /*!< SQ15 (Bitfield-Mask: 0x1f)                            */
#define ADC_SQR2_SQ15                     (0x7c00UL)                /*!< SQ15 (Bitfield-Mask: 0x1f)                            */
#define ADC_SQR2_SQ14_Pos                 (5UL)                     /*!< SQ14 (Bit 5)                                          */
#define ADC_SQR2_SQ14_Msk                 (0x3e0UL)                 /*!< SQ14 (Bitfield-Mask: 0x1f)                            */
#define ADC_SQR2_SQ14                     (0x3e0UL)                 /*!< SQ14 (Bitfield-Mask: 0x1f)                            */
#define ADC_SQR2_SQ13_Pos                 (0UL)                     /*!< SQ13 (Bit 0)                                          */
#define ADC_SQR2_SQ13_Msk                 (0x1fUL)                  /*!< SQ13 (Bitfield-Mask: 0x1f)                            */
#define ADC_SQR2_SQ13                     (0x1fUL)                  /*!< SQ13 (Bitfield-Mask: 0x1f)                            */
/* =========================================================  SQR3  ========================================================== */
#define ADC_SQR3_SQ12_Pos                 (25UL)                    /*!< SQ12 (Bit 25)                                         */
#define ADC_SQR3_SQ12_Msk                 (0x3e000000UL)            /*!< SQ12 (Bitfield-Mask: 0x1f)                            */
#define ADC_SQR3_SQ12                     (0x3e000000UL)            /*!< SQ12 (Bitfield-Mask: 0x1f)                            */
#define ADC_SQR3_SQ11_Pos                 (20UL)                    /*!< SQ11 (Bit 20)                                         */
#define ADC_SQR3_SQ11_Msk                 (0x1f00000UL)             /*!< SQ11 (Bitfield-Mask: 0x1f)                            */
#define ADC_SQR3_SQ11                     (0x1f00000UL)             /*!< SQ11 (Bitfield-Mask: 0x1f)                            */
#define ADC_SQR3_SQ10_Pos                 (15UL)                    /*!< SQ10 (Bit 15)                                         */
#define ADC_SQR3_SQ10_Msk                 (0xf8000UL)               /*!< SQ10 (Bitfield-Mask: 0x1f)                            */
#define ADC_SQR3_SQ10                     (0xf8000UL)               /*!< SQ10 (Bitfield-Mask: 0x1f)                            */
#define ADC_SQR3_SQ9_Pos                  (10UL)                    /*!< SQ9 (Bit 10)                                          */
#define ADC_SQR3_SQ9_Msk                  (0x7c00UL)                /*!< SQ9 (Bitfield-Mask: 0x1f)                             */
#define ADC_SQR3_SQ9                      (0x7c00UL)                /*!< SQ9 (Bitfield-Mask: 0x1f)                             */
#define ADC_SQR3_SQ8_Pos                  (5UL)                     /*!< SQ8 (Bit 5)                                           */
#define ADC_SQR3_SQ8_Msk                  (0x3e0UL)                 /*!< SQ8 (Bitfield-Mask: 0x1f)                             */
#define ADC_SQR3_SQ8                      (0x3e0UL)                 /*!< SQ8 (Bitfield-Mask: 0x1f)                             */
#define ADC_SQR3_SQ7_Pos                  (0UL)                     /*!< SQ7 (Bit 0)                                           */
#define ADC_SQR3_SQ7_Msk                  (0x1fUL)                  /*!< SQ7 (Bitfield-Mask: 0x1f)                             */
#define ADC_SQR3_SQ7                      (0x1fUL)                  /*!< SQ7 (Bitfield-Mask: 0x1f)                             */
/* =========================================================  SQR4  ========================================================== */
#define ADC_SQR4_SQ6_Pos                  (25UL)                    /*!< SQ6 (Bit 25)                                          */
#define ADC_SQR4_SQ6_Msk                  (0x3e000000UL)            /*!< SQ6 (Bitfield-Mask: 0x1f)                             */
#define ADC_SQR4_SQ6                      (0x3e000000UL)            /*!< SQ6 (Bitfield-Mask: 0x1f)                             */
#define ADC_SQR4_SQ5_Pos                  (20UL)                    /*!< SQ5 (Bit 20)                                          */
#define ADC_SQR4_SQ5_Msk                  (0x1f00000UL)             /*!< SQ5 (Bitfield-Mask: 0x1f)                             */
#define ADC_SQR4_SQ5                      (0x1f00000UL)             /*!< SQ5 (Bitfield-Mask: 0x1f)                             */
#define ADC_SQR4_SQ4_Pos                  (15UL)                    /*!< SQ4 (Bit 15)                                          */
#define ADC_SQR4_SQ4_Msk                  (0xf8000UL)               /*!< SQ4 (Bitfield-Mask: 0x1f)                             */
#define ADC_SQR4_SQ4                      (0xf8000UL)               /*!< SQ4 (Bitfield-Mask: 0x1f)                             */
#define ADC_SQR4_SQ3_Pos                  (10UL)                    /*!< SQ3 (Bit 10)                                          */
#define ADC_SQR4_SQ3_Msk                  (0x7c00UL)                /*!< SQ3 (Bitfield-Mask: 0x1f)                             */
#define ADC_SQR4_SQ3                      (0x7c00UL)                /*!< SQ3 (Bitfield-Mask: 0x1f)                             */
#define ADC_SQR4_SQ2_Pos                  (5UL)                     /*!< SQ2 (Bit 5)                                           */
#define ADC_SQR4_SQ2_Msk                  (0x3e0UL)                 /*!< SQ2 (Bitfield-Mask: 0x1f)                             */
#define ADC_SQR4_SQ2                      (0x3e0UL)                 /*!< SQ2 (Bitfield-Mask: 0x1f)                             */
#define ADC_SQR4_SQ1_Pos                  (0UL)                     /*!< SQ1 (Bit 0)                                           */
#define ADC_SQR4_SQ1_Msk                  (0x1fUL)                  /*!< SQ1 (Bitfield-Mask: 0x1f)                             */
#define ADC_SQR4_SQ1                      (0x1fUL)                  /*!< SQ1 (Bitfield-Mask: 0x1f)                             */
/* =========================================================  JSQR  ========================================================== */
#define ADC_JSQR_JL_Pos                   (25UL)                    /*!< JL (Bit 25)                                           */
#define ADC_JSQR_JL_Msk                   (0xe000000UL)             /*!< JL (Bitfield-Mask: 0x07)                              */
#define ADC_JSQR_JL                       (0xe000000UL)             /*!< JL (Bitfield-Mask: 0x07)                              */
#define ADC_JSQR_JSQ5_Pos                 (20UL)                    /*!< JSQ5 (Bit 20)                                         */
#define ADC_JSQR_JSQ5_Msk                 (0x1f00000UL)             /*!< JSQ5 (Bitfield-Mask: 0x1f)                            */
#define ADC_JSQR_JSQ5                     (0x1f00000UL)             /*!< JSQ5 (Bitfield-Mask: 0x1f)                            */
#define ADC_JSQR_JSQ4_Pos                 (15UL)                    /*!< JSQ4 (Bit 15)                                         */
#define ADC_JSQR_JSQ4_Msk                 (0xf8000UL)               /*!< JSQ4 (Bitfield-Mask: 0x1f)                            */
#define ADC_JSQR_JSQ4                     (0xf8000UL)               /*!< JSQ4 (Bitfield-Mask: 0x1f)                            */
#define ADC_JSQR_JSQ3_Pos                 (10UL)                    /*!< JSQ3 (Bit 10)                                         */
#define ADC_JSQR_JSQ3_Msk                 (0x7c00UL)                /*!< JSQ3 (Bitfield-Mask: 0x1f)                            */
#define ADC_JSQR_JSQ3                     (0x7c00UL)                /*!< JSQ3 (Bitfield-Mask: 0x1f)                            */
#define ADC_JSQR_JSQ2_Pos                 (5UL)                     /*!< JSQ2 (Bit 5)                                          */
#define ADC_JSQR_JSQ2_Msk                 (0x3e0UL)                 /*!< JSQ2 (Bitfield-Mask: 0x1f)                            */
#define ADC_JSQR_JSQ2                     (0x3e0UL)                 /*!< JSQ2 (Bitfield-Mask: 0x1f)                            */
#define ADC_JSQR_JSQ1_Pos                 (0UL)                     /*!< JSQ1 (Bit 0)                                          */
#define ADC_JSQR_JSQ1_Msk                 (0x1fUL)                  /*!< JSQ1 (Bitfield-Mask: 0x1f)                            */
#define ADC_JSQR_JSQ1                     (0x1fUL)                  /*!< JSQ1 (Bitfield-Mask: 0x1f)                            */
/* =========================================================  JDR1  ========================================================== */
#define ADC_JDR1_JDATA_Pos                (0UL)                     /*!< JDATA (Bit 0)                                         */
#define ADC_JDR1_JDATA_Msk                (0xffffUL)                /*!< JDATA (Bitfield-Mask: 0xffff)                         */
#define ADC_JDR1_JDATA                    (0xffffUL)                /*!< JDATA (Bitfield-Mask: 0xffff)                         */
/* =========================================================  JDR2  ========================================================== */
#define ADC_JDR2_JDATA_Pos                (0UL)                     /*!< JDATA (Bit 0)                                         */
#define ADC_JDR2_JDATA_Msk                (0xffffUL)                /*!< JDATA (Bitfield-Mask: 0xffff)                         */
#define ADC_JDR2_JDATA                    (0xffffUL)                /*!< JDATA (Bitfield-Mask: 0xffff)                         */
/* =========================================================  JDR3  ========================================================== */
#define ADC_JDR3_JDATA_Pos                (0UL)                     /*!< JDATA (Bit 0)                                         */
#define ADC_JDR3_JDATA_Msk                (0xffffUL)                /*!< JDATA (Bitfield-Mask: 0xffff)                         */
#define ADC_JDR3_JDATA                    (0xffffUL)                /*!< JDATA (Bitfield-Mask: 0xffff)                         */
/* =========================================================  JDR4  ========================================================== */
#define ADC_JDR4_JDATA_Pos                (0UL)                     /*!< JDATA (Bit 0)                                         */
#define ADC_JDR4_JDATA_Msk                (0xffffUL)                /*!< JDATA (Bitfield-Mask: 0xffff)                         */
#define ADC_JDR4_JDATA                    (0xffffUL)                /*!< JDATA (Bitfield-Mask: 0xffff)                         */
/* =========================================================  JDR5  ========================================================== */
#define ADC_JDR5_JDATA_Pos                (0UL)                     /*!< JDATA (Bit 0)                                         */
#define ADC_JDR5_JDATA_Msk                (0xffffUL)                /*!< JDATA (Bitfield-Mask: 0xffff)                         */
#define ADC_JDR5_JDATA                    (0xffffUL)                /*!< JDATA (Bitfield-Mask: 0xffff)                         */
/* ==========================================================  DR  =========================================================== */
#define ADC_DR_DATA_Pos                   (0UL)                     /*!< DATA (Bit 0)                                          */
#define ADC_DR_DATA_Msk                   (0xffffUL)                /*!< DATA (Bitfield-Mask: 0xffff)                          */
#define ADC_DR_DATA                       (0xffffUL)                /*!< DATA (Bitfield-Mask: 0xffff)                          */


/* =========================================================================================================================== */
/* ================                                           COMP1                                           ================ */
/* =========================================================================================================================== */

/* ==========================================================  CSR  ========================================================== */
#define COMP_CSR_LOCK_Pos                (31UL)                    /*!< LOCK (Bit 31)                                         */
#define COMP_CSR_LOCK_Msk                (0x80000000UL)            /*!< LOCK (Bitfield-Mask: 0x01)                            */
#define COMP_CSR_LOCK                    (0x80000000UL)            /*!< LOCK (Bitfield-Mask: 0x01)                            */
#define COMP_CSR_COMP_OUT_Pos            (30UL)                    /*!< COMP_OUT (Bit 30)                                     */
#define COMP_CSR_COMP_OUT_Msk            (0x40000000UL)            /*!< COMP_OUT (Bitfield-Mask: 0x01)                        */
#define COMP_CSR_COMP_OUT                (0x40000000UL)            /*!< COMP_OUT (Bitfield-Mask: 0x01)                        */
#define COMP_CSR_PWRMODE_Pos             (18UL)                    /*!< PWRMODE (Bit 18)                                      */
#define COMP_CSR_PWRMODE_Msk             (0xc0000UL)               /*!< PWRMODE (Bitfield-Mask: 0x03)                         */
#define COMP_CSR_PWRMODE                 (0xc0000UL)               /*!< PWRMODE (Bitfield-Mask: 0x03)                         */
#define COMP_CSR_HYST_Pos                (16UL)                    /*!< HYST (Bit 16)                                         */
#define COMP_CSR_HYST_Msk                (0x10000UL)               /*!< HYST (Bitfield-Mask: 0x01)                            */
#define COMP_CSR_HYST                    (0x10000UL)               /*!< HYST (Bitfield-Mask: 0x01)                            */
#define COMP_CSR_POLARITY_Pos            (15UL)                    /*!< POLARITY (Bit 15)                                     */
#define COMP_CSR_POLARITY_Msk            (0x8000UL)                /*!< POLARITY (Bitfield-Mask: 0x01)                        */
#define COMP_CSR_POLARITY                (0x8000UL)                /*!< POLARITY (Bitfield-Mask: 0x01)                        */
#define COMP_CSR_WINMODE_Pos             (11UL)                    /*!< WINMODE (Bit 11)                                      */
#define COMP_CSR_WINMODE_Msk             (0x800UL)                 /*!< WINMODE (Bitfield-Mask: 0x01)                         */
#define COMP_CSR_WINMODE                 (0x800UL)                 /*!< WINMODE (Bitfield-Mask: 0x01)                         */
#define COMP_CSR_INPSEL_Pos              (8UL)                     /*!< INPSEL (Bit 8)                                        */
#define COMP_CSR_INPSEL_Msk              (0x700UL)                 /*!< INPSEL (Bitfield-Mask: 0x07)                          */
#define COMP_CSR_INPSEL                  (0x700UL)                 /*!< INPSEL (Bitfield-Mask: 0x07)                          */
#define COMP_CSR_INMSEL_Pos              (4UL)                     /*!< INMSEL (Bit 4)                                        */
#define COMP_CSR_INMSEL_Msk              (0xf0UL)                  /*!< INMSEL (Bitfield-Mask: 0x0f)                          */
#define COMP_CSR_INMSEL                  (0xf0UL)                  /*!< INMSEL (Bitfield-Mask: 0x0f)                          */
#define COMP_CSR_SCALER_EN_Pos           (1UL)                     /*!< SCALER_EN (Bit 1)                                     */
#define COMP_CSR_SCALER_EN_Msk           (0x2UL)                   /*!< SCALER_EN (Bitfield-Mask: 0x01)                       */
#define COMP_CSR_SCALER_EN               (0x2UL)                   /*!< SCALER_EN (Bitfield-Mask: 0x01)                       */
#define COMP_CSR_EN_Pos                  (0UL)                     /*!< EN (Bit 0)                                            */
#define COMP_CSR_EN_Msk                  (0x1UL)                   /*!< EN (Bitfield-Mask: 0x01)                              */
#define COMP_CSR_EN                      (0x1UL)                   /*!< EN (Bitfield-Mask: 0x01)                              */
/* ==========================================================  FR  =========================================================== */
#define COMP_FR_FLTCNT_Pos              (16UL)                    /*!< FLTCNT (Bit 16)                                      */
#define COMP_FR_FLTCNT_Msk              (0xffff0000UL)            /*!< FLTCNT (Bitfield-Mask: 0xffff)                       */
#define COMP_FR_FLTCNT                  (0xffff0000UL)            /*!< FLTCNT (Bitfield-Mask: 0xffff)                       */
#define COMP_FR_FLTEN_Pos               (0UL)                     /*!< FLTEN (Bit 0)                                        */
#define COMP_FR_FLTEN_Msk               (0x1UL)                   /*!< FLTEN (Bitfield-Mask: 0x01)                          */
#define COMP_FR_FLTEN                   (0x1UL)                   /*!< FLTEN (Bitfield-Mask: 0x01)                          */


/* =========================================================================================================================== */
/* ================                                           COMP2                                           ================ */
/* =========================================================================================================================== */

/* ==========================================================  CSR  ========================================================== */
#define COMP2_CSR_LOCK_Pos                (31UL)                    /*!< LOCK (Bit 31)                                         */
#define COMP2_CSR_LOCK_Msk                (0x80000000UL)            /*!< LOCK (Bitfield-Mask: 0x01)                            */
#define COMP2_CSR_LOCK                    (0x80000000UL)            /*!< LOCK (Bitfield-Mask: 0x01)                            */
#define COMP2_CSR_COMP_OUT_Pos            (30UL)                    /*!< COMP_OUT (Bit 30)                                     */
#define COMP2_CSR_COMP_OUT_Msk            (0x40000000UL)            /*!< COMP_OUT (Bitfield-Mask: 0x01)                        */
#define COMP2_CSR_COMP_OUT                (0x40000000UL)            /*!< COMP_OUT (Bitfield-Mask: 0x01)                        */
#define COMP2_CSR_PWRMODE_Pos             (18UL)                    /*!< PWRMODE (Bit 18)                                      */
#define COMP2_CSR_PWRMODE_Msk             (0xc0000UL)               /*!< PWRMODE (Bitfield-Mask: 0x03)                         */
#define COMP2_CSR_PWRMODE                 (0xc0000UL)               /*!< PWRMODE (Bitfield-Mask: 0x03)                         */
#define COMP2_CSR_HYST_Pos                (16UL)                    /*!< HYST (Bit 16)                                         */
#define COMP2_CSR_HYST_Msk                (0x10000UL)               /*!< HYST (Bitfield-Mask: 0x01)                            */
#define COMP2_CSR_HYST                    (0x10000UL)               /*!< HYST (Bitfield-Mask: 0x01)                            */
#define COMP2_CSR_POLARITY_Pos            (15UL)                    /*!< POLARITY (Bit 15)                                     */
#define COMP2_CSR_POLARITY_Msk            (0x8000UL)                /*!< POLARITY (Bitfield-Mask: 0x01)                        */
#define COMP2_CSR_POLARITY                (0x8000UL)                /*!< POLARITY (Bitfield-Mask: 0x01)                        */
#define COMP2_CSR_WINMODE_Pos             (11UL)                    /*!< WINMODE (Bit 11)                                      */
#define COMP2_CSR_WINMODE_Msk             (0x800UL)                 /*!< WINMODE (Bitfield-Mask: 0x01)                         */
#define COMP2_CSR_WINMODE                 (0x800UL)                 /*!< WINMODE (Bitfield-Mask: 0x01)                         */
#define COMP2_CSR_INPSEL_Pos              (8UL)                     /*!< INPSEL (Bit 8)                                        */
#define COMP2_CSR_INPSEL_Msk              (0x700UL)                 /*!< INPSEL (Bitfield-Mask: 0x07)                          */
#define COMP2_CSR_INPSEL                  (0x700UL)                 /*!< INPSEL (Bitfield-Mask: 0x07)                          */
#define COMP2_CSR_INMSEL_Pos              (4UL)                     /*!< INMSEL (Bit 4)                                        */
#define COMP2_CSR_INMSEL_Msk              (0xf0UL)                  /*!< INMSEL (Bitfield-Mask: 0x0f)                          */
#define COMP2_CSR_INMSEL                  (0xf0UL)                  /*!< INMSEL (Bitfield-Mask: 0x0f)                          */
#define COMP2_CSR_EN_Pos                  (0UL)                     /*!< EN (Bit 0)                                            */
#define COMP2_CSR_EN_Msk                  (0x1UL)                   /*!< EN (Bitfield-Mask: 0x01)                              */
#define COMP2_CSR_EN                      (0x1UL)                   /*!< EN (Bitfield-Mask: 0x01)                              */
/* ==========================================================  FR  =========================================================== */
#define COMP2_FR_FLTCNT_Pos              (16UL)                    /*!< FLTCNT (Bit 16)                                      */
#define COMP2_FR_FLTCNT_Msk              (0xffff0000UL)            /*!< FLTCNT (Bitfield-Mask: 0xffff)                       */
#define COMP2_FR_FLTCNT                  (0xffff0000UL)            /*!< FLTCNT (Bitfield-Mask: 0xffff)                       */
#define COMP2_FR_FLTEN_Pos               (0UL)                     /*!< FLTEN (Bit 0)                                        */
#define COMP2_FR_FLTEN_Msk               (0x1UL)                   /*!< FLTEN (Bitfield-Mask: 0x01)                          */
#define COMP2_FR_FLTEN                   (0x1UL)                   /*!< FLTEN (Bitfield-Mask: 0x01)                          */


/* =========================================================================================================================== */
/* ================                                           COMP3                                           ================ */
/* =========================================================================================================================== */

/* ==========================================================  CSR  ========================================================== */
#define COMP3_CSR_LOCK_Pos                (31UL)                    /*!< LOCK (Bit 31)                                         */
#define COMP3_CSR_LOCK_Msk                (0x80000000UL)            /*!< LOCK (Bitfield-Mask: 0x01)                            */
#define COMP3_CSR_LOCK                    (0x80000000UL)            /*!< LOCK (Bitfield-Mask: 0x01)                            */
#define COMP3_CSR_COMP_OUT_Pos            (30UL)                    /*!< COMP_OUT (Bit 30)                                     */
#define COMP3_CSR_COMP_OUT_Msk            (0x40000000UL)            /*!< COMP_OUT (Bitfield-Mask: 0x01)                        */
#define COMP3_CSR_COMP_OUT                (0x40000000UL)            /*!< COMP_OUT (Bitfield-Mask: 0x01)                        */
#define COMP3_CSR_PWRMODE_Pos             (18UL)                    /*!< PWRMODE (Bit 18)                                      */
#define COMP3_CSR_PWRMODE_Msk             (0xc0000UL)               /*!< PWRMODE (Bitfield-Mask: 0x03)                         */
#define COMP3_CSR_PWRMODE                 (0xc0000UL)               /*!< PWRMODE (Bitfield-Mask: 0x03)                         */
#define COMP3_CSR_HYST_Pos                (16UL)                    /*!< HYST (Bit 16)                                         */
#define COMP3_CSR_HYST_Msk                (0x10000UL)               /*!< HYST (Bitfield-Mask: 0x01)                            */
#define COMP3_CSR_HYST                    (0x10000UL)               /*!< HYST (Bitfield-Mask: 0x01)                            */
#define COMP3_CSR_POLARITY_Pos            (15UL)                    /*!< POLARITY (Bit 15)                                     */
#define COMP3_CSR_POLARITY_Msk            (0x8000UL)                /*!< POLARITY (Bitfield-Mask: 0x01)                        */
#define COMP3_CSR_POLARITY                (0x8000UL)                /*!< POLARITY (Bitfield-Mask: 0x01)                        */
#define COMP3_CSR_WINMODE_Pos             (11UL)                    /*!< WINMODE (Bit 11)                                      */
#define COMP3_CSR_WINMODE_Msk             (0x800UL)                 /*!< WINMODE (Bitfield-Mask: 0x01)                         */
#define COMP3_CSR_WINMODE                 (0x800UL)                 /*!< WINMODE (Bitfield-Mask: 0x01)                         */
#define COMP3_CSR_INPSEL_Pos              (8UL)                     /*!< INPSEL (Bit 8)                                        */
#define COMP3_CSR_INPSEL_Msk              (0x700UL)                 /*!< INPSEL (Bitfield-Mask: 0x07)                          */
#define COMP3_CSR_INPSEL                  (0x700UL)                 /*!< INPSEL (Bitfield-Mask: 0x07)                          */
#define COMP3_CSR_INMSEL_Pos              (4UL)                     /*!< INMSEL (Bit 4)                                        */
#define COMP3_CSR_INMSEL_Msk              (0xf0UL)                  /*!< INMSEL (Bitfield-Mask: 0x0f)                          */
#define COMP3_CSR_INMSEL                  (0xf0UL)                  /*!< INMSEL (Bitfield-Mask: 0x0f)                          */
#define COMP3_CSR_SCALER_EN_Pos           (1UL)                     /*!< SCALER_EN (Bit 1)                                     */
#define COMP3_CSR_SCALER_EN_Msk           (0x2UL)                   /*!< SCALER_EN (Bitfield-Mask: 0x01)                       */
#define COMP3_CSR_SCALER_EN               (0x2UL)                   /*!< SCALER_EN (Bitfield-Mask: 0x01)                       */
#define COMP3_CSR_EN_Pos                  (0UL)                     /*!< EN (Bit 0)                                            */
#define COMP3_CSR_EN_Msk                  (0x1UL)                   /*!< EN (Bitfield-Mask: 0x01)                              */
#define COMP3_CSR_EN                      (0x1UL)                   /*!< EN (Bitfield-Mask: 0x01)                              */
/* ==========================================================  FR  =========================================================== */
#define COMP3_FR_FLTCNT_Pos              (16UL)                    /*!< FLTCNT (Bit 16)                                      */
#define COMP3_FR_FLTCNT_Msk              (0xffff0000UL)            /*!< FLTCNT (Bitfield-Mask: 0xffff)                       */
#define COMP3_FR_FLTCNT                  (0xffff0000UL)            /*!< FLTCNT (Bitfield-Mask: 0xffff)                       */
#define COMP3_FR_FLTEN_Pos               (0UL)                     /*!< FLTEN (Bit 0)                                        */
#define COMP3_FR_FLTEN_Msk               (0x1UL)                   /*!< FLTEN (Bitfield-Mask: 0x01)                          */
#define COMP3_FR_FLTEN                   (0x1UL)                   /*!< FLTEN (Bitfield-Mask: 0x01)                          */


/* =========================================================================================================================== */
/* ================                                           COMP4                                           ================ */
/* =========================================================================================================================== */

/* ==========================================================  CSR  ========================================================== */
#define COMP4_CSR_LOCK_Pos                (31UL)                    /*!< LOCK (Bit 31)                                         */
#define COMP4_CSR_LOCK_Msk                (0x80000000UL)            /*!< LOCK (Bitfield-Mask: 0x01)                            */
#define COMP4_CSR_LOCK                    (0x80000000UL)            /*!< LOCK (Bitfield-Mask: 0x01)                            */
#define COMP4_CSR_COMP_OUT_Pos            (30UL)                    /*!< COMP_OUT (Bit 30)                                     */
#define COMP4_CSR_COMP_OUT_Msk            (0x40000000UL)            /*!< COMP_OUT (Bitfield-Mask: 0x01)                        */
#define COMP4_CSR_COMP_OUT                (0x40000000UL)            /*!< COMP_OUT (Bitfield-Mask: 0x01)                        */
#define COMP4_CSR_PWRMODE_Pos             (18UL)                    /*!< PWRMODE (Bit 18)                                      */
#define COMP4_CSR_PWRMODE_Msk             (0xc0000UL)               /*!< PWRMODE (Bitfield-Mask: 0x03)                         */
#define COMP4_CSR_PWRMODE                 (0xc0000UL)               /*!< PWRMODE (Bitfield-Mask: 0x03)                         */
#define COMP4_CSR_HYST_Pos                (16UL)                    /*!< HYST (Bit 16)                                         */
#define COMP4_CSR_HYST_Msk                (0x10000UL)               /*!< HYST (Bitfield-Mask: 0x01)                            */
#define COMP4_CSR_HYST                    (0x10000UL)               /*!< HYST (Bitfield-Mask: 0x01)                            */
#define COMP4_CSR_POLARITY_Pos            (15UL)                    /*!< POLARITY (Bit 15)                                     */
#define COMP4_CSR_POLARITY_Msk            (0x8000UL)                /*!< POLARITY (Bitfield-Mask: 0x01)                        */
#define COMP4_CSR_POLARITY                (0x8000UL)                /*!< POLARITY (Bitfield-Mask: 0x01)                        */
#define COMP4_CSR_WINMODE_Pos             (11UL)                    /*!< WINMODE (Bit 11)                                      */
#define COMP4_CSR_WINMODE_Msk             (0x800UL)                 /*!< WINMODE (Bitfield-Mask: 0x01)                         */
#define COMP4_CSR_WINMODE                 (0x800UL)                 /*!< WINMODE (Bitfield-Mask: 0x01)                         */
#define COMP4_CSR_INPSEL_Pos              (8UL)                     /*!< INPSEL (Bit 8)                                        */
#define COMP4_CSR_INPSEL_Msk              (0x700UL)                 /*!< INPSEL (Bitfield-Mask: 0x07)                          */
#define COMP4_CSR_INPSEL                  (0x700UL)                 /*!< INPSEL (Bitfield-Mask: 0x07)                          */
#define COMP4_CSR_INMSEL_Pos              (4UL)                     /*!< INMSEL (Bit 4)                                        */
#define COMP4_CSR_INMSEL_Msk              (0xf0UL)                  /*!< INMSEL (Bitfield-Mask: 0x0f)                          */
#define COMP4_CSR_INMSEL                  (0xf0UL)                  /*!< INMSEL (Bitfield-Mask: 0x0f)                          */
#define COMP4_CSR_EN_Pos                  (0UL)                     /*!< EN (Bit 0)                                            */
#define COMP4_CSR_EN_Msk                  (0x1UL)                   /*!< EN (Bitfield-Mask: 0x01)                              */
#define COMP4_CSR_EN                      (0x1UL)                   /*!< EN (Bitfield-Mask: 0x01)                              */
/* ==========================================================  FR  =========================================================== */
#define COMP4_FR_FLTCNT_Pos              (16UL)                    /*!< FLTCNT (Bit 16)                                      */
#define COMP4_FR_FLTCNT_Msk              (0xffff0000UL)            /*!< FLTCNT (Bitfield-Mask: 0xffff)                       */
#define COMP4_FR_FLTCNT                  (0xffff0000UL)            /*!< FLTCNT (Bitfield-Mask: 0xffff)                       */
#define COMP4_FR_FLTEN_Pos               (0UL)                     /*!< FLTEN (Bit 0)                                        */
#define COMP4_FR_FLTEN_Msk               (0x1UL)                   /*!< FLTEN (Bitfield-Mask: 0x01)                          */
#define COMP4_FR_FLTEN                   (0x1UL)                   /*!< FLTEN (Bitfield-Mask: 0x01)                          */


/* =========================================================================================================================== */
/* ================                                            LED                                            ================ */
/* =========================================================================================================================== */

/* =========================================================  ICDR  ========================================================== */
#define LED_ICDR_INT_Pos                  (8UL)                     /*!< INT (Bit 8)                                           */
#define LED_ICDR_INT_Msk                  (0x100UL)                 /*!< INT (Bitfield-Mask: 0x01)                             */
#define LED_ICDR_INT                      (0x100UL)                 /*!< INT (Bitfield-Mask: 0x01)                             */
#define LED_ICDR_DIV_Pos                  (0UL)                     /*!< DIV (Bit 0)                                           */
#define LED_ICDR_DIV_Msk                  (0xfUL)                   /*!< DIV (Bitfield-Mask: 0x0f)                             */
#define LED_ICDR_DIV                      (0xfUL)                   /*!< DIV (Bitfield-Mask: 0x0f)                             */
/* =========================================================  OTCR  ========================================================== */
#define LED_OTCR_T1_Pos                   (8UL)                     /*!< T1 (Bit 8)                                            */
#define LED_OTCR_T1_Msk                   (0xff00UL)                /*!< T1 (Bitfield-Mask: 0xff)                              */
#define LED_OTCR_T1                       (0xff00UL)                /*!< T1 (Bitfield-Mask: 0xff)                              */
#define LED_OTCR_T0_Pos                   (0UL)                     /*!< T0 (Bit 0)                                            */
#define LED_OTCR_T0_Msk                   (0xffUL)                  /*!< T0 (Bitfield-Mask: 0xff)                              */
#define LED_OTCR_T0                       (0xffUL)                  /*!< T0 (Bitfield-Mask: 0xff)                              */
/* ==========================================================  GCR  ========================================================== */
#define LED_GCR_SCAN_FIRST_Pos            (12UL)                    /*!< SCAN_FIRST (Bit 12)                                   */
#define LED_GCR_SCAN_FIRST_Msk            (0xf000UL)                /*!< SCAN_FIRST (Bitfield-Mask: 0x0f)                      */
#define LED_GCR_SCAN_FIRST                (0xf000UL)                /*!< SCAN_FIRST (Bitfield-Mask: 0x0f)                      */
#define LED_GCR_ARRAY_MODE_Pos            (9UL)                     /*!< ARRAY_MODE (Bit 9)                                    */
#define LED_GCR_ARRAY_MODE_Msk            (0xe00UL)                 /*!< ARRAY_MODE (Bitfield-Mask: 0x07)                      */
#define LED_GCR_ARRAY_MODE                (0xe00UL)                 /*!< ARRAY_MODE (Bitfield-Mask: 0x07)                      */
#define LED_GCR_SCAN_MODE_Pos             (8UL)                     /*!< SCAN_MODE (Bit 8)                                     */
#define LED_GCR_SCAN_MODE_Msk             (0x100UL)                 /*!< SCAN_MODE (Bitfield-Mask: 0x01)                       */
#define LED_GCR_SCAN_MODE                 (0x100UL)                 /*!< SCAN_MODE (Bitfield-Mask: 0x01)                       */
#define LED_GCR_STAR_Pos                  (0UL)                     /*!< STAR (Bit 0)                                          */
#define LED_GCR_STAR_Msk                  (0x1UL)                   /*!< STAR (Bitfield-Mask: 0x01)                            */
#define LED_GCR_STAR                      (0x1UL)                   /*!< STAR (Bitfield-Mask: 0x01)                            */
/* =========================================================  SCR1  ========================================================== */
#define LED_SCR1_D31_Pos                  (31UL)                    /*!< D31 (Bit 31)                                          */
#define LED_SCR1_D31_Msk                  (0x80000000UL)            /*!< D31 (Bitfield-Mask: 0x01)                             */
#define LED_SCR1_D31                      (0x80000000UL)            /*!< D31 (Bitfield-Mask: 0x01)                             */
#define LED_SCR1_D30_Pos                  (30UL)                    /*!< D30 (Bit 30)                                          */
#define LED_SCR1_D30_Msk                  (0x40000000UL)            /*!< D30 (Bitfield-Mask: 0x01)                             */
#define LED_SCR1_D30                      (0x40000000UL)            /*!< D30 (Bitfield-Mask: 0x01)                             */
#define LED_SCR1_D29_Pos                  (29UL)                    /*!< D29 (Bit 29)                                          */
#define LED_SCR1_D29_Msk                  (0x20000000UL)            /*!< D29 (Bitfield-Mask: 0x01)                             */
#define LED_SCR1_D29                      (0x20000000UL)            /*!< D29 (Bitfield-Mask: 0x01)                             */
#define LED_SCR1_D28_Pos                  (28UL)                    /*!< D28 (Bit 28)                                          */
#define LED_SCR1_D28_Msk                  (0x10000000UL)            /*!< D28 (Bitfield-Mask: 0x01)                             */
#define LED_SCR1_D28                      (0x10000000UL)            /*!< D28 (Bitfield-Mask: 0x01)                             */
#define LED_SCR1_D27_Pos                  (27UL)                    /*!< D27 (Bit 27)                                          */
#define LED_SCR1_D27_Msk                  (0x8000000UL)             /*!< D27 (Bitfield-Mask: 0x01)                             */
#define LED_SCR1_D27                      (0x8000000UL)             /*!< D27 (Bitfield-Mask: 0x01)                             */
#define LED_SCR1_D26_Pos                  (26UL)                    /*!< D26 (Bit 26)                                          */
#define LED_SCR1_D26_Msk                  (0x4000000UL)             /*!< D26 (Bitfield-Mask: 0x01)                             */
#define LED_SCR1_D26                      (0x4000000UL)             /*!< D26 (Bitfield-Mask: 0x01)                             */
#define LED_SCR1_D25_Pos                  (25UL)                    /*!< D25 (Bit 25)                                          */
#define LED_SCR1_D25_Msk                  (0x2000000UL)             /*!< D25 (Bitfield-Mask: 0x01)                             */
#define LED_SCR1_D25                      (0x2000000UL)             /*!< D25 (Bitfield-Mask: 0x01)                             */
#define LED_SCR1_D24_Pos                  (24UL)                    /*!< D24 (Bit 24)                                          */
#define LED_SCR1_D24_Msk                  (0x1000000UL)             /*!< D24 (Bitfield-Mask: 0x01)                             */
#define LED_SCR1_D24                      (0x1000000UL)             /*!< D24 (Bitfield-Mask: 0x01)                             */
#define LED_SCR1_D23_Pos                  (23UL)                    /*!< D23 (Bit 23)                                          */
#define LED_SCR1_D23_Msk                  (0x800000UL)              /*!< D23 (Bitfield-Mask: 0x01)                             */
#define LED_SCR1_D23                      (0x800000UL)              /*!< D23 (Bitfield-Mask: 0x01)                             */
#define LED_SCR1_D22_Pos                  (22UL)                    /*!< D22 (Bit 22)                                          */
#define LED_SCR1_D22_Msk                  (0x400000UL)              /*!< D22 (Bitfield-Mask: 0x01)                             */
#define LED_SCR1_D22                      (0x400000UL)              /*!< D22 (Bitfield-Mask: 0x01)                             */
#define LED_SCR1_D21_Pos                  (21UL)                    /*!< D21 (Bit 21)                                          */
#define LED_SCR1_D21_Msk                  (0x200000UL)              /*!< D21 (Bitfield-Mask: 0x01)                             */
#define LED_SCR1_D21                      (0x200000UL)              /*!< D21 (Bitfield-Mask: 0x01)                             */
#define LED_SCR1_D20_Pos                  (20UL)                    /*!< D20 (Bit 20)                                          */
#define LED_SCR1_D20_Msk                  (0x100000UL)              /*!< D20 (Bitfield-Mask: 0x01)                             */
#define LED_SCR1_D20                      (0x100000UL)              /*!< D20 (Bitfield-Mask: 0x01)                             */
#define LED_SCR1_D19_Pos                  (19UL)                    /*!< D19 (Bit 19)                                          */
#define LED_SCR1_D19_Msk                  (0x80000UL)               /*!< D19 (Bitfield-Mask: 0x01)                             */
#define LED_SCR1_D19                      (0x80000UL)               /*!< D19 (Bitfield-Mask: 0x01)                             */
#define LED_SCR1_D18_Pos                  (18UL)                    /*!< D18 (Bit 18)                                          */
#define LED_SCR1_D18_Msk                  (0x40000UL)               /*!< D18 (Bitfield-Mask: 0x01)                             */
#define LED_SCR1_D18                      (0x40000UL)               /*!< D18 (Bitfield-Mask: 0x01)                             */
#define LED_SCR1_D17_Pos                  (17UL)                    /*!< D17 (Bit 17)                                          */
#define LED_SCR1_D17_Msk                  (0x20000UL)               /*!< D17 (Bitfield-Mask: 0x01)                             */
#define LED_SCR1_D17                      (0x20000UL)               /*!< D17 (Bitfield-Mask: 0x01)                             */
#define LED_SCR1_D16_Pos                  (16UL)                    /*!< D16 (Bit 16)                                          */
#define LED_SCR1_D16_Msk                  (0x10000UL)               /*!< D16 (Bitfield-Mask: 0x01)                             */
#define LED_SCR1_D16                      (0x10000UL)               /*!< D16 (Bitfield-Mask: 0x01)                             */
#define LED_SCR1_D15_Pos                  (15UL)                    /*!< D15 (Bit 15)                                          */
#define LED_SCR1_D15_Msk                  (0x8000UL)                /*!< D15 (Bitfield-Mask: 0x01)                             */
#define LED_SCR1_D15                      (0x8000UL)                /*!< D15 (Bitfield-Mask: 0x01)                             */
#define LED_SCR1_D14_Pos                  (14UL)                    /*!< D14 (Bit 14)                                          */
#define LED_SCR1_D14_Msk                  (0x4000UL)                /*!< D14 (Bitfield-Mask: 0x01)                             */
#define LED_SCR1_D14                      (0x4000UL)                /*!< D14 (Bitfield-Mask: 0x01)                             */
#define LED_SCR1_D13_Pos                  (13UL)                    /*!< D13 (Bit 13)                                          */
#define LED_SCR1_D13_Msk                  (0x2000UL)                /*!< D13 (Bitfield-Mask: 0x01)                             */
#define LED_SCR1_D13                      (0x2000UL)                /*!< D13 (Bitfield-Mask: 0x01)                             */
#define LED_SCR1_D12_Pos                  (12UL)                    /*!< D12 (Bit 12)                                          */
#define LED_SCR1_D12_Msk                  (0x1000UL)                /*!< D12 (Bitfield-Mask: 0x01)                             */
#define LED_SCR1_D12                      (0x1000UL)                /*!< D12 (Bitfield-Mask: 0x01)                             */
#define LED_SCR1_D11_Pos                  (11UL)                    /*!< D11 (Bit 11)                                          */
#define LED_SCR1_D11_Msk                  (0x800UL)                 /*!< D11 (Bitfield-Mask: 0x01)                             */
#define LED_SCR1_D11                      (0x800UL)                 /*!< D11 (Bitfield-Mask: 0x01)                             */
#define LED_SCR1_D10_Pos                  (10UL)                    /*!< D10 (Bit 10)                                          */
#define LED_SCR1_D10_Msk                  (0x400UL)                 /*!< D10 (Bitfield-Mask: 0x01)                             */
#define LED_SCR1_D10                      (0x400UL)                 /*!< D10 (Bitfield-Mask: 0x01)                             */
#define LED_SCR1_D9_Pos                   (9UL)                     /*!< D9 (Bit 9)                                            */
#define LED_SCR1_D9_Msk                   (0x200UL)                 /*!< D9 (Bitfield-Mask: 0x01)                              */
#define LED_SCR1_D9                       (0x200UL)                 /*!< D9 (Bitfield-Mask: 0x01)                              */
#define LED_SCR1_D8_Pos                   (8UL)                     /*!< D8 (Bit 8)                                            */
#define LED_SCR1_D8_Msk                   (0x100UL)                 /*!< D8 (Bitfield-Mask: 0x01)                              */
#define LED_SCR1_D8                       (0x100UL)                 /*!< D8 (Bitfield-Mask: 0x01)                              */
#define LED_SCR1_D7_Pos                   (7UL)                     /*!< D7 (Bit 7)                                            */
#define LED_SCR1_D7_Msk                   (0x80UL)                  /*!< D7 (Bitfield-Mask: 0x01)                              */
#define LED_SCR1_D7                       (0x80UL)                  /*!< D7 (Bitfield-Mask: 0x01)                              */
#define LED_SCR1_D6_Pos                   (6UL)                     /*!< D6 (Bit 6)                                            */
#define LED_SCR1_D6_Msk                   (0x40UL)                  /*!< D6 (Bitfield-Mask: 0x01)                              */
#define LED_SCR1_D6                       (0x40UL)                  /*!< D6 (Bitfield-Mask: 0x01)                              */
#define LED_SCR1_D5_Pos                   (5UL)                     /*!< D5 (Bit 5)                                            */
#define LED_SCR1_D5_Msk                   (0x20UL)                  /*!< D5 (Bitfield-Mask: 0x01)                              */
#define LED_SCR1_D5                       (0x20UL)                  /*!< D5 (Bitfield-Mask: 0x01)                              */
#define LED_SCR1_D4_Pos                   (4UL)                     /*!< D4 (Bit 4)                                            */
#define LED_SCR1_D4_Msk                   (0x10UL)                  /*!< D4 (Bitfield-Mask: 0x01)                              */
#define LED_SCR1_D4                       (0x10UL)                  /*!< D4 (Bitfield-Mask: 0x01)                              */
#define LED_SCR1_D3_Pos                   (3UL)                     /*!< D3 (Bit 3)                                            */
#define LED_SCR1_D3_Msk                   (0x8UL)                   /*!< D3 (Bitfield-Mask: 0x01)                              */
#define LED_SCR1_D3                       (0x8UL)                   /*!< D3 (Bitfield-Mask: 0x01)                              */
#define LED_SCR1_D2_Pos                   (2UL)                     /*!< D2 (Bit 2)                                            */
#define LED_SCR1_D2_Msk                   (0x4UL)                   /*!< D2 (Bitfield-Mask: 0x01)                              */
#define LED_SCR1_D2                       (0x4UL)                   /*!< D2 (Bitfield-Mask: 0x01)                              */
#define LED_SCR1_D1_Pos                   (1UL)                     /*!< D1 (Bit 1)                                            */
#define LED_SCR1_D1_Msk                   (0x2UL)                   /*!< D1 (Bitfield-Mask: 0x01)                              */
#define LED_SCR1_D1                       (0x2UL)                   /*!< D1 (Bitfield-Mask: 0x01)                              */
#define LED_SCR1_D0_Pos                   (0UL)                     /*!< D0 (Bit 0)                                            */
#define LED_SCR1_D0_Msk                   (0x1UL)                   /*!< D0 (Bitfield-Mask: 0x01)                              */
#define LED_SCR1_D0                       (0x1UL)                   /*!< D0 (Bitfield-Mask: 0x01)                              */
/* =========================================================  SCR2  ========================================================== */
#define LED_SCR2_D63_Pos                  (31UL)                    /*!< D63 (Bit 31)                                          */
#define LED_SCR2_D63_Msk                  (0x80000000UL)            /*!< D63 (Bitfield-Mask: 0x01)                             */
#define LED_SCR2_D63                      (0x80000000UL)            /*!< D63 (Bitfield-Mask: 0x01)                             */
#define LED_SCR2_D62_Pos                  (30UL)                    /*!< D62 (Bit 30)                                          */
#define LED_SCR2_D62_Msk                  (0x40000000UL)            /*!< D62 (Bitfield-Mask: 0x01)                             */
#define LED_SCR2_D62                      (0x40000000UL)            /*!< D62 (Bitfield-Mask: 0x01)                             */
#define LED_SCR2_D61_Pos                  (29UL)                    /*!< D61 (Bit 29)                                          */
#define LED_SCR2_D61_Msk                  (0x20000000UL)            /*!< D61 (Bitfield-Mask: 0x01)                             */
#define LED_SCR2_D61                      (0x20000000UL)            /*!< D61 (Bitfield-Mask: 0x01)                             */
#define LED_SCR2_D60_Pos                  (28UL)                    /*!< D60 (Bit 28)                                          */
#define LED_SCR2_D60_Msk                  (0x10000000UL)            /*!< D60 (Bitfield-Mask: 0x01)                             */
#define LED_SCR2_D60                      (0x10000000UL)            /*!< D60 (Bitfield-Mask: 0x01)                             */
#define LED_SCR2_D59_Pos                  (27UL)                    /*!< D59 (Bit 27)                                          */
#define LED_SCR2_D59_Msk                  (0x8000000UL)             /*!< D59 (Bitfield-Mask: 0x01)                             */
#define LED_SCR2_D59                      (0x8000000UL)             /*!< D59 (Bitfield-Mask: 0x01)                             */
#define LED_SCR2_D58_Pos                  (26UL)                    /*!< D58 (Bit 26)                                          */
#define LED_SCR2_D58_Msk                  (0x4000000UL)             /*!< D58 (Bitfield-Mask: 0x01)                             */
#define LED_SCR2_D58                      (0x4000000UL)             /*!< D58 (Bitfield-Mask: 0x01)                             */
#define LED_SCR2_D57_Pos                  (25UL)                    /*!< D57 (Bit 25)                                          */
#define LED_SCR2_D57_Msk                  (0x2000000UL)             /*!< D57 (Bitfield-Mask: 0x01)                             */
#define LED_SCR2_D57                      (0x2000000UL)             /*!< D57 (Bitfield-Mask: 0x01)                             */
#define LED_SCR2_D56_Pos                  (24UL)                    /*!< D56 (Bit 24)                                          */
#define LED_SCR2_D56_Msk                  (0x1000000UL)             /*!< D56 (Bitfield-Mask: 0x01)                             */
#define LED_SCR2_D56                      (0x1000000UL)             /*!< D56 (Bitfield-Mask: 0x01)                             */
#define LED_SCR2_D55_Pos                  (23UL)                    /*!< D55 (Bit 23)                                          */
#define LED_SCR2_D55_Msk                  (0x800000UL)              /*!< D55 (Bitfield-Mask: 0x01)                             */
#define LED_SCR2_D55                      (0x800000UL)              /*!< D55 (Bitfield-Mask: 0x01)                             */
#define LED_SCR2_D54_Pos                  (22UL)                    /*!< D54 (Bit 22)                                          */
#define LED_SCR2_D54_Msk                  (0x400000UL)              /*!< D54 (Bitfield-Mask: 0x01)                             */
#define LED_SCR2_D54                      (0x400000UL)              /*!< D54 (Bitfield-Mask: 0x01)                             */
#define LED_SCR2_D53_Pos                  (21UL)                    /*!< D53 (Bit 21)                                          */
#define LED_SCR2_D53_Msk                  (0x200000UL)              /*!< D53 (Bitfield-Mask: 0x01)                             */
#define LED_SCR2_D53                      (0x200000UL)              /*!< D53 (Bitfield-Mask: 0x01)                             */
#define LED_SCR2_D52_Pos                  (20UL)                    /*!< D52 (Bit 20)                                          */
#define LED_SCR2_D52_Msk                  (0x100000UL)              /*!< D52 (Bitfield-Mask: 0x01)                             */
#define LED_SCR2_D52                      (0x100000UL)              /*!< D52 (Bitfield-Mask: 0x01)                             */
#define LED_SCR2_D51_Pos                  (19UL)                    /*!< D51 (Bit 19)                                          */
#define LED_SCR2_D51_Msk                  (0x80000UL)               /*!< D51 (Bitfield-Mask: 0x01)                             */
#define LED_SCR2_D51                      (0x80000UL)               /*!< D51 (Bitfield-Mask: 0x01)                             */
#define LED_SCR2_D50_Pos                  (18UL)                    /*!< D50 (Bit 18)                                          */
#define LED_SCR2_D50_Msk                  (0x40000UL)               /*!< D50 (Bitfield-Mask: 0x01)                             */
#define LED_SCR2_D50                      (0x40000UL)               /*!< D50 (Bitfield-Mask: 0x01)                             */
#define LED_SCR2_D49_Pos                  (17UL)                    /*!< D49 (Bit 17)                                          */
#define LED_SCR2_D49_Msk                  (0x20000UL)               /*!< D49 (Bitfield-Mask: 0x01)                             */
#define LED_SCR2_D49                      (0x20000UL)               /*!< D49 (Bitfield-Mask: 0x01)                             */
#define LED_SCR2_D48_Pos                  (16UL)                    /*!< D48 (Bit 16)                                          */
#define LED_SCR2_D48_Msk                  (0x10000UL)               /*!< D48 (Bitfield-Mask: 0x01)                             */
#define LED_SCR2_D48                      (0x10000UL)               /*!< D48 (Bitfield-Mask: 0x01)                             */
#define LED_SCR2_D47_Pos                  (15UL)                    /*!< D47 (Bit 15)                                          */
#define LED_SCR2_D47_Msk                  (0x8000UL)                /*!< D47 (Bitfield-Mask: 0x01)                             */
#define LED_SCR2_D47                      (0x8000UL)                /*!< D47 (Bitfield-Mask: 0x01)                             */
#define LED_SCR2_D46_Pos                  (14UL)                    /*!< D46 (Bit 14)                                          */
#define LED_SCR2_D46_Msk                  (0x4000UL)                /*!< D46 (Bitfield-Mask: 0x01)                             */
#define LED_SCR2_D46                      (0x4000UL)                /*!< D46 (Bitfield-Mask: 0x01)                             */
#define LED_SCR2_D45_Pos                  (13UL)                    /*!< D45 (Bit 13)                                          */
#define LED_SCR2_D45_Msk                  (0x2000UL)                /*!< D45 (Bitfield-Mask: 0x01)                             */
#define LED_SCR2_D45                      (0x2000UL)                /*!< D45 (Bitfield-Mask: 0x01)                             */
#define LED_SCR2_D44_Pos                  (12UL)                    /*!< D44 (Bit 12)                                          */
#define LED_SCR2_D44_Msk                  (0x1000UL)                /*!< D44 (Bitfield-Mask: 0x01)                             */
#define LED_SCR2_D44                      (0x1000UL)                /*!< D44 (Bitfield-Mask: 0x01)                             */
#define LED_SCR2_D43_Pos                  (11UL)                    /*!< D43 (Bit 11)                                          */
#define LED_SCR2_D43_Msk                  (0x800UL)                 /*!< D43 (Bitfield-Mask: 0x01)                             */
#define LED_SCR2_D43                      (0x800UL)                 /*!< D43 (Bitfield-Mask: 0x01)                             */
#define LED_SCR2_D42_Pos                  (10UL)                    /*!< D42 (Bit 10)                                          */
#define LED_SCR2_D42_Msk                  (0x400UL)                 /*!< D42 (Bitfield-Mask: 0x01)                             */
#define LED_SCR2_D42                      (0x400UL)                 /*!< D42 (Bitfield-Mask: 0x01)                             */
#define LED_SCR2_D41_Pos                  (9UL)                     /*!< D41 (Bit 9)                                           */
#define LED_SCR2_D41_Msk                  (0x200UL)                 /*!< D41 (Bitfield-Mask: 0x01)                             */
#define LED_SCR2_D41                      (0x200UL)                 /*!< D41 (Bitfield-Mask: 0x01)                             */
#define LED_SCR2_D40_Pos                  (8UL)                     /*!< D40 (Bit 8)                                           */
#define LED_SCR2_D40_Msk                  (0x100UL)                 /*!< D40 (Bitfield-Mask: 0x01)                             */
#define LED_SCR2_D40                      (0x100UL)                 /*!< D40 (Bitfield-Mask: 0x01)                             */
#define LED_SCR2_D39_Pos                  (7UL)                     /*!< D39 (Bit 7)                                           */
#define LED_SCR2_D39_Msk                  (0x80UL)                  /*!< D39 (Bitfield-Mask: 0x01)                             */
#define LED_SCR2_D39                      (0x80UL)                  /*!< D39 (Bitfield-Mask: 0x01)                             */
#define LED_SCR2_D38_Pos                  (6UL)                     /*!< D38 (Bit 6)                                           */
#define LED_SCR2_D38_Msk                  (0x40UL)                  /*!< D38 (Bitfield-Mask: 0x01)                             */
#define LED_SCR2_D38                      (0x40UL)                  /*!< D38 (Bitfield-Mask: 0x01)                             */
#define LED_SCR2_D37_Pos                  (5UL)                     /*!< D37 (Bit 5)                                           */
#define LED_SCR2_D37_Msk                  (0x20UL)                  /*!< D37 (Bitfield-Mask: 0x01)                             */
#define LED_SCR2_D37                      (0x20UL)                  /*!< D37 (Bitfield-Mask: 0x01)                             */
#define LED_SCR2_D36_Pos                  (4UL)                     /*!< D36 (Bit 4)                                           */
#define LED_SCR2_D36_Msk                  (0x10UL)                  /*!< D36 (Bitfield-Mask: 0x01)                             */
#define LED_SCR2_D36                      (0x10UL)                  /*!< D36 (Bitfield-Mask: 0x01)                             */
#define LED_SCR2_D35_Pos                  (3UL)                     /*!< D35 (Bit 3)                                           */
#define LED_SCR2_D35_Msk                  (0x8UL)                   /*!< D35 (Bitfield-Mask: 0x01)                             */
#define LED_SCR2_D35                      (0x8UL)                   /*!< D35 (Bitfield-Mask: 0x01)                             */
#define LED_SCR2_D34_Pos                  (2UL)                     /*!< D34 (Bit 2)                                           */
#define LED_SCR2_D34_Msk                  (0x4UL)                   /*!< D34 (Bitfield-Mask: 0x01)                             */
#define LED_SCR2_D34                      (0x4UL)                   /*!< D34 (Bitfield-Mask: 0x01)                             */
#define LED_SCR2_D33_Pos                  (1UL)                     /*!< D33 (Bit 1)                                           */
#define LED_SCR2_D33_Msk                  (0x2UL)                   /*!< D33 (Bitfield-Mask: 0x01)                             */
#define LED_SCR2_D33                      (0x2UL)                   /*!< D33 (Bitfield-Mask: 0x01)                             */
#define LED_SCR2_D32_Pos                  (0UL)                     /*!< D32 (Bit 0)                                           */
#define LED_SCR2_D32_Msk                  (0x1UL)                   /*!< D32 (Bitfield-Mask: 0x01)                             */
#define LED_SCR2_D32                      (0x1UL)                   /*!< D32 (Bitfield-Mask: 0x01)                             */
/* =========================================================  OPSR1  ========================================================= */
#define LED_OPSR1_S31_Pos                 (31UL)                    /*!< S31 (Bit 31)                                          */
#define LED_OPSR1_S31_Msk                 (0x80000000UL)            /*!< S31 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR1_S31                     (0x80000000UL)            /*!< S31 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR1_S30_Pos                 (30UL)                    /*!< S30 (Bit 30)                                          */
#define LED_OPSR1_S30_Msk                 (0x40000000UL)            /*!< S30 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR1_S30                     (0x40000000UL)            /*!< S30 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR1_S29_Pos                 (29UL)                    /*!< S29 (Bit 29)                                          */
#define LED_OPSR1_S29_Msk                 (0x20000000UL)            /*!< S29 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR1_S29                     (0x20000000UL)            /*!< S29 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR1_S28_Pos                 (28UL)                    /*!< S28 (Bit 28)                                          */
#define LED_OPSR1_S28_Msk                 (0x10000000UL)            /*!< S28 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR1_S28                     (0x10000000UL)            /*!< S28 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR1_S27_Pos                 (27UL)                    /*!< S27 (Bit 27)                                          */
#define LED_OPSR1_S27_Msk                 (0x8000000UL)             /*!< S27 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR1_S27                     (0x8000000UL)             /*!< S27 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR1_S26_Pos                 (26UL)                    /*!< S26 (Bit 26)                                          */
#define LED_OPSR1_S26_Msk                 (0x4000000UL)             /*!< S26 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR1_S26                     (0x4000000UL)             /*!< S26 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR1_S25_Pos                 (25UL)                    /*!< S25 (Bit 25)                                          */
#define LED_OPSR1_S25_Msk                 (0x2000000UL)             /*!< S25 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR1_S25                     (0x2000000UL)             /*!< S25 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR1_S24_Pos                 (24UL)                    /*!< S24 (Bit 24)                                          */
#define LED_OPSR1_S24_Msk                 (0x1000000UL)             /*!< S24 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR1_S24                     (0x1000000UL)             /*!< S24 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR1_S23_Pos                 (23UL)                    /*!< S23 (Bit 23)                                          */
#define LED_OPSR1_S23_Msk                 (0x800000UL)              /*!< S23 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR1_S23                     (0x800000UL)              /*!< S23 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR1_S22_Pos                 (22UL)                    /*!< S22 (Bit 22)                                          */
#define LED_OPSR1_S22_Msk                 (0x400000UL)              /*!< S22 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR1_S22                     (0x400000UL)              /*!< S22 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR1_S21_Pos                 (21UL)                    /*!< S21 (Bit 21)                                          */
#define LED_OPSR1_S21_Msk                 (0x200000UL)              /*!< S21 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR1_S21                     (0x200000UL)              /*!< S21 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR1_S20_Pos                 (20UL)                    /*!< S20 (Bit 20)                                          */
#define LED_OPSR1_S20_Msk                 (0x100000UL)              /*!< S20 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR1_S20                     (0x100000UL)              /*!< S20 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR1_S19_Pos                 (19UL)                    /*!< S19 (Bit 19)                                          */
#define LED_OPSR1_S19_Msk                 (0x80000UL)               /*!< S19 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR1_S19                     (0x80000UL)               /*!< S19 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR1_S18_Pos                 (18UL)                    /*!< S18 (Bit 18)                                          */
#define LED_OPSR1_S18_Msk                 (0x40000UL)               /*!< S18 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR1_S18                     (0x40000UL)               /*!< S18 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR1_S17_Pos                 (17UL)                    /*!< S17 (Bit 17)                                          */
#define LED_OPSR1_S17_Msk                 (0x20000UL)               /*!< S17 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR1_S17                     (0x20000UL)               /*!< S17 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR1_S16_Pos                 (16UL)                    /*!< S16 (Bit 16)                                          */
#define LED_OPSR1_S16_Msk                 (0x10000UL)               /*!< S16 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR1_S16                     (0x10000UL)               /*!< S16 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR1_S15_Pos                 (15UL)                    /*!< S15 (Bit 15)                                          */
#define LED_OPSR1_S15_Msk                 (0x8000UL)                /*!< S15 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR1_S15                     (0x8000UL)                /*!< S15 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR1_S14_Pos                 (14UL)                    /*!< S14 (Bit 14)                                          */
#define LED_OPSR1_S14_Msk                 (0x4000UL)                /*!< S14 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR1_S14                     (0x4000UL)                /*!< S14 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR1_S13_Pos                 (13UL)                    /*!< S13 (Bit 13)                                          */
#define LED_OPSR1_S13_Msk                 (0x2000UL)                /*!< S13 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR1_S13                     (0x2000UL)                /*!< S13 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR1_S12_Pos                 (12UL)                    /*!< S12 (Bit 12)                                          */
#define LED_OPSR1_S12_Msk                 (0x1000UL)                /*!< S12 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR1_S12                     (0x1000UL)                /*!< S12 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR1_S11_Pos                 (11UL)                    /*!< S11 (Bit 11)                                          */
#define LED_OPSR1_S11_Msk                 (0x800UL)                 /*!< S11 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR1_S11                     (0x800UL)                 /*!< S11 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR1_S10_Pos                 (10UL)                    /*!< S10 (Bit 10)                                          */
#define LED_OPSR1_S10_Msk                 (0x400UL)                 /*!< S10 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR1_S10                     (0x400UL)                 /*!< S10 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR1_S9_Pos                  (9UL)                     /*!< S9 (Bit 9)                                            */
#define LED_OPSR1_S9_Msk                  (0x200UL)                 /*!< S9 (Bitfield-Mask: 0x01)                              */
#define LED_OPSR1_S9                      (0x200UL)                 /*!< S9 (Bitfield-Mask: 0x01)                              */
#define LED_OPSR1_S8_Pos                  (8UL)                     /*!< S8 (Bit 8)                                            */
#define LED_OPSR1_S8_Msk                  (0x100UL)                 /*!< S8 (Bitfield-Mask: 0x01)                              */
#define LED_OPSR1_S8                      (0x100UL)                 /*!< S8 (Bitfield-Mask: 0x01)                              */
#define LED_OPSR1_S7_Pos                  (7UL)                     /*!< S7 (Bit 7)                                            */
#define LED_OPSR1_S7_Msk                  (0x80UL)                  /*!< S7 (Bitfield-Mask: 0x01)                              */
#define LED_OPSR1_S7                      (0x80UL)                  /*!< S7 (Bitfield-Mask: 0x01)                              */
#define LED_OPSR1_S6_Pos                  (6UL)                     /*!< S6 (Bit 6)                                            */
#define LED_OPSR1_S6_Msk                  (0x40UL)                  /*!< S6 (Bitfield-Mask: 0x01)                              */
#define LED_OPSR1_S6                      (0x40UL)                  /*!< S6 (Bitfield-Mask: 0x01)                              */
#define LED_OPSR1_S5_Pos                  (5UL)                     /*!< S5 (Bit 5)                                            */
#define LED_OPSR1_S5_Msk                  (0x20UL)                  /*!< S5 (Bitfield-Mask: 0x01)                              */
#define LED_OPSR1_S5                      (0x20UL)                  /*!< S5 (Bitfield-Mask: 0x01)                              */
#define LED_OPSR1_S4_Pos                  (4UL)                     /*!< S4 (Bit 4)                                            */
#define LED_OPSR1_S4_Msk                  (0x10UL)                  /*!< S4 (Bitfield-Mask: 0x01)                              */
#define LED_OPSR1_S4                      (0x10UL)                  /*!< S4 (Bitfield-Mask: 0x01)                              */
#define LED_OPSR1_S3_Pos                  (3UL)                     /*!< S3 (Bit 3)                                            */
#define LED_OPSR1_S3_Msk                  (0x8UL)                   /*!< S3 (Bitfield-Mask: 0x01)                              */
#define LED_OPSR1_S3                      (0x8UL)                   /*!< S3 (Bitfield-Mask: 0x01)                              */
#define LED_OPSR1_S2_Pos                  (2UL)                     /*!< S2 (Bit 2)                                            */
#define LED_OPSR1_S2_Msk                  (0x4UL)                   /*!< S2 (Bitfield-Mask: 0x01)                              */
#define LED_OPSR1_S2                      (0x4UL)                   /*!< S2 (Bitfield-Mask: 0x01)                              */
#define LED_OPSR1_S1_Pos                  (1UL)                     /*!< S1 (Bit 1)                                            */
#define LED_OPSR1_S1_Msk                  (0x2UL)                   /*!< S1 (Bitfield-Mask: 0x01)                              */
#define LED_OPSR1_S1                      (0x2UL)                   /*!< S1 (Bitfield-Mask: 0x01)                              */
#define LED_OPSR1_S0_Pos                  (0UL)                     /*!< S0 (Bit 0)                                            */
#define LED_OPSR1_S0_Msk                  (0x1UL)                   /*!< S0 (Bitfield-Mask: 0x01)                              */
#define LED_OPSR1_S0                      (0x1UL)                   /*!< S0 (Bitfield-Mask: 0x01)                              */
/* =========================================================  OPSR2  ========================================================= */
#define LED_OPSR2_S63_Pos                 (31UL)                    /*!< S63 (Bit 31)                                          */
#define LED_OPSR2_S63_Msk                 (0x80000000UL)            /*!< S63 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR2_S63                     (0x80000000UL)            /*!< S63 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR2_S62_Pos                 (30UL)                    /*!< S62 (Bit 30)                                          */
#define LED_OPSR2_S62_Msk                 (0x40000000UL)            /*!< S62 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR2_S62                     (0x40000000UL)            /*!< S62 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR2_S61_Pos                 (29UL)                    /*!< S61 (Bit 29)                                          */
#define LED_OPSR2_S61_Msk                 (0x20000000UL)            /*!< S61 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR2_S61                     (0x20000000UL)            /*!< S61 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR2_S60_Pos                 (28UL)                    /*!< S60 (Bit 28)                                          */
#define LED_OPSR2_S60_Msk                 (0x10000000UL)            /*!< S60 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR2_S60                     (0x10000000UL)            /*!< S60 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR2_S59_Pos                 (27UL)                    /*!< S59 (Bit 27)                                          */
#define LED_OPSR2_S59_Msk                 (0x8000000UL)             /*!< S59 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR2_S59                     (0x8000000UL)             /*!< S59 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR2_S58_Pos                 (26UL)                    /*!< S58 (Bit 26)                                          */
#define LED_OPSR2_S58_Msk                 (0x4000000UL)             /*!< S58 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR2_S58                     (0x4000000UL)             /*!< S58 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR2_S57_Pos                 (25UL)                    /*!< S57 (Bit 25)                                          */
#define LED_OPSR2_S57_Msk                 (0x2000000UL)             /*!< S57 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR2_S57                     (0x2000000UL)             /*!< S57 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR2_S56_Pos                 (24UL)                    /*!< S56 (Bit 24)                                          */
#define LED_OPSR2_S56_Msk                 (0x1000000UL)             /*!< S56 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR2_S56                     (0x1000000UL)             /*!< S56 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR2_S55_Pos                 (23UL)                    /*!< S55 (Bit 23)                                          */
#define LED_OPSR2_S55_Msk                 (0x800000UL)              /*!< S55 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR2_S55                     (0x800000UL)              /*!< S55 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR2_S54_Pos                 (22UL)                    /*!< S54 (Bit 22)                                          */
#define LED_OPSR2_S54_Msk                 (0x400000UL)              /*!< S54 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR2_S54                     (0x400000UL)              /*!< S54 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR2_S53_Pos                 (21UL)                    /*!< S53 (Bit 21)                                          */
#define LED_OPSR2_S53_Msk                 (0x200000UL)              /*!< S53 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR2_S53                     (0x200000UL)              /*!< S53 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR2_S52_Pos                 (20UL)                    /*!< S52 (Bit 20)                                          */
#define LED_OPSR2_S52_Msk                 (0x100000UL)              /*!< S52 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR2_S52                     (0x100000UL)              /*!< S52 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR2_S51_Pos                 (19UL)                    /*!< S51 (Bit 19)                                          */
#define LED_OPSR2_S51_Msk                 (0x80000UL)               /*!< S51 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR2_S51                     (0x80000UL)               /*!< S51 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR2_S50_Pos                 (18UL)                    /*!< S50 (Bit 18)                                          */
#define LED_OPSR2_S50_Msk                 (0x40000UL)               /*!< S50 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR2_S50                     (0x40000UL)               /*!< S50 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR2_S49_Pos                 (17UL)                    /*!< S49 (Bit 17)                                          */
#define LED_OPSR2_S49_Msk                 (0x20000UL)               /*!< S49 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR2_S49                     (0x20000UL)               /*!< S49 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR2_S48_Pos                 (16UL)                    /*!< S48 (Bit 16)                                          */
#define LED_OPSR2_S48_Msk                 (0x10000UL)               /*!< S48 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR2_S48                     (0x10000UL)               /*!< S48 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR2_S47_Pos                 (15UL)                    /*!< S47 (Bit 15)                                          */
#define LED_OPSR2_S47_Msk                 (0x8000UL)                /*!< S47 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR2_S47                     (0x8000UL)                /*!< S47 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR2_S46_Pos                 (14UL)                    /*!< S46 (Bit 14)                                          */
#define LED_OPSR2_S46_Msk                 (0x4000UL)                /*!< S46 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR2_S46                     (0x4000UL)                /*!< S46 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR2_S45_Pos                 (13UL)                    /*!< S45 (Bit 13)                                          */
#define LED_OPSR2_S45_Msk                 (0x2000UL)                /*!< S45 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR2_S45                     (0x2000UL)                /*!< S45 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR2_S44_Pos                 (12UL)                    /*!< S44 (Bit 12)                                          */
#define LED_OPSR2_S44_Msk                 (0x1000UL)                /*!< S44 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR2_S44                     (0x1000UL)                /*!< S44 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR2_S43_Pos                 (11UL)                    /*!< S43 (Bit 11)                                          */
#define LED_OPSR2_S43_Msk                 (0x800UL)                 /*!< S43 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR2_S43                     (0x800UL)                 /*!< S43 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR2_S42_Pos                 (10UL)                    /*!< S42 (Bit 10)                                          */
#define LED_OPSR2_S42_Msk                 (0x400UL)                 /*!< S42 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR2_S42                     (0x400UL)                 /*!< S42 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR2_S41_Pos                 (9UL)                     /*!< S41 (Bit 9)                                           */
#define LED_OPSR2_S41_Msk                 (0x200UL)                 /*!< S41 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR2_S41                     (0x200UL)                 /*!< S41 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR2_S40_Pos                 (8UL)                     /*!< S40 (Bit 8)                                           */
#define LED_OPSR2_S40_Msk                 (0x100UL)                 /*!< S40 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR2_S40                     (0x100UL)                 /*!< S40 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR2_S39_Pos                 (7UL)                     /*!< S39 (Bit 7)                                           */
#define LED_OPSR2_S39_Msk                 (0x80UL)                  /*!< S39 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR2_S39                     (0x80UL)                  /*!< S39 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR2_S38_Pos                 (6UL)                     /*!< S38 (Bit 6)                                           */
#define LED_OPSR2_S38_Msk                 (0x40UL)                  /*!< S38 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR2_S38                     (0x40UL)                  /*!< S38 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR2_S37_Pos                 (5UL)                     /*!< S37 (Bit 5)                                           */
#define LED_OPSR2_S37_Msk                 (0x20UL)                  /*!< S37 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR2_S37                     (0x20UL)                  /*!< S37 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR2_S36_Pos                 (4UL)                     /*!< S36 (Bit 4)                                           */
#define LED_OPSR2_S36_Msk                 (0x10UL)                  /*!< S36 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR2_S36                     (0x10UL)                  /*!< S36 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR2_S35_Pos                 (3UL)                     /*!< S35 (Bit 3)                                           */
#define LED_OPSR2_S35_Msk                 (0x8UL)                   /*!< S35 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR2_S35                     (0x8UL)                   /*!< S35 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR2_S34_Pos                 (2UL)                     /*!< S34 (Bit 2)                                           */
#define LED_OPSR2_S34_Msk                 (0x4UL)                   /*!< S34 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR2_S34                     (0x4UL)                   /*!< S34 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR2_S33_Pos                 (1UL)                     /*!< S33 (Bit 1)                                           */
#define LED_OPSR2_S33_Msk                 (0x2UL)                   /*!< S33 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR2_S33                     (0x2UL)                   /*!< S33 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR2_S32_Pos                 (0UL)                     /*!< S32 (Bit 0)                                           */
#define LED_OPSR2_S32_Msk                 (0x1UL)                   /*!< S32 (Bitfield-Mask: 0x01)                             */
#define LED_OPSR2_S32                     (0x1UL)                   /*!< S32 (Bitfield-Mask: 0x01)                             */
/* ========================================================  COMENR  ========================================================= */
#define LED_COMENR_COMEN8_Pos             (8UL)                     /*!< COMEN8 (Bit 8)                                        */
#define LED_COMENR_COMEN8_Msk             (0x100UL)                 /*!< COMEN8 (Bitfield-Mask: 0x01)                          */
#define LED_COMENR_COMEN8                 (0x100UL)                 /*!< COMEN8 (Bitfield-Mask: 0x01)                          */
#define LED_COMENR_COMEN7_Pos             (7UL)                     /*!< COMEN7 (Bit 7)                                        */
#define LED_COMENR_COMEN7_Msk             (0x80UL)                  /*!< COMEN7 (Bitfield-Mask: 0x01)                          */
#define LED_COMENR_COMEN7                 (0x80UL)                  /*!< COMEN7 (Bitfield-Mask: 0x01)                          */
#define LED_COMENR_COMEN6_Pos             (6UL)                     /*!< COMEN6 (Bit 6)                                        */
#define LED_COMENR_COMEN6_Msk             (0x40UL)                  /*!< COMEN6 (Bitfield-Mask: 0x01)                          */
#define LED_COMENR_COMEN6                 (0x40UL)                  /*!< COMEN6 (Bitfield-Mask: 0x01)                          */
#define LED_COMENR_COMEN5_Pos             (5UL)                     /*!< COMEN5 (Bit 5)                                        */
#define LED_COMENR_COMEN5_Msk             (0x20UL)                  /*!< COMEN5 (Bitfield-Mask: 0x01)                          */
#define LED_COMENR_COMEN5                 (0x20UL)                  /*!< COMEN5 (Bitfield-Mask: 0x01)                          */
#define LED_COMENR_COMEN4_Pos             (4UL)                     /*!< COMEN4 (Bit 4)                                        */
#define LED_COMENR_COMEN4_Msk             (0x10UL)                  /*!< COMEN4 (Bitfield-Mask: 0x01)                          */
#define LED_COMENR_COMEN4                 (0x10UL)                  /*!< COMEN4 (Bitfield-Mask: 0x01)                          */
#define LED_COMENR_COMEN3_Pos             (3UL)                     /*!< COMEN3 (Bit 3)                                        */
#define LED_COMENR_COMEN3_Msk             (0x8UL)                   /*!< COMEN3 (Bitfield-Mask: 0x01)                          */
#define LED_COMENR_COMEN3                 (0x8UL)                   /*!< COMEN3 (Bitfield-Mask: 0x01)                          */
#define LED_COMENR_COMEN2_Pos             (2UL)                     /*!< COMEN2 (Bit 2)                                        */
#define LED_COMENR_COMEN2_Msk             (0x4UL)                   /*!< COMEN2 (Bitfield-Mask: 0x01)                          */
#define LED_COMENR_COMEN2                 (0x4UL)                   /*!< COMEN2 (Bitfield-Mask: 0x01)                          */
#define LED_COMENR_COMEN1_Pos             (1UL)                     /*!< COMEN1 (Bit 1)                                        */
#define LED_COMENR_COMEN1_Msk             (0x2UL)                   /*!< COMEN1 (Bitfield-Mask: 0x01)                          */
#define LED_COMENR_COMEN1                 (0x2UL)                   /*!< COMEN1 (Bitfield-Mask: 0x01)                          */
#define LED_COMENR_COMEN0_Pos             (0UL)                     /*!< COMEN0 (Bit 0)                                        */
#define LED_COMENR_COMEN0_Msk             (0x1UL)                   /*!< COMEN0 (Bitfield-Mask: 0x01)                          */
#define LED_COMENR_COMEN0                 (0x1UL)                   /*!< COMEN0 (Bitfield-Mask: 0x01)                          */


/* =========================================================================================================================== */
/* ================                                          VREFBUF                                          ================ */
/* =========================================================================================================================== */

/* ==========================================================  CSR  ========================================================== */
#define VREFBUF_CSR_VREF_SEL_Pos          (1UL)                     /*!< VREF_SEL (Bit 1)                                      */
#define VREFBUF_CSR_VREF_SEL_Msk          (0x6UL)                   /*!< VREF_SEL (Bitfield-Mask: 0x03)                        */
#define VREFBUF_CSR_VREF_SEL              (0x6UL)                   /*!< VREF_SEL (Bitfield-Mask: 0x03)                        */
#define VREFBUF_CSR_ENVR_Pos              (0UL)                     /*!< ENVR (Bit 0)                                          */
#define VREFBUF_CSR_ENVR_Msk              (0x1UL)                   /*!< ENVR (Bitfield-Mask: 0x01)                            */
#define VREFBUF_CSR_ENVR                  (0x1UL)                   /*!< ENVR (Bitfield-Mask: 0x01)                            */
/* ==========================================================  CCR  ========================================================== */
#define VREFBUF_CCR_TRIM_VREF_Pos         (0UL)                     /*!< TRIM_VREF (Bit 0)                                     */
#define VREFBUF_CCR_TRIM_VREF_Msk         (0x7UL)                   /*!< TRIM_VREF (Bitfield-Mask: 0x07)                       */
#define VREFBUF_CCR_TRIM_VREF             (0x7UL)                   /*!< TRIM_VREF (Bitfield-Mask: 0x07)                       */


/* =========================================================================================================================== */
/* ================                                            CRC                                            ================ */
/* =========================================================================================================================== */

/* ==========================================================  SR  =========================================================== */
#define CRC_SR_FLAG_Pos                   (1UL)                     /*!< FLAG (Bit 1)                                          */
#define CRC_SR_FLAG_Msk                   (0x2UL)                   /*!< FLAG (Bitfield-Mask: 0x01)                            */
#define CRC_SR_FLAG                       (0x2UL)                   /*!< FLAG (Bitfield-Mask: 0x01)                            */
/* ========================================================  RESULT  ========================================================= */
#define CRC_RESULT_RESULT_Pos             (0UL)                     /*!< RESULT (Bit 0)                                        */
#define CRC_RESULT_RESULT_Msk             (0xffffffffUL)            /*!< RESULT (Bitfield-Mask: 0xffffffff)                    */
#define CRC_RESULT_RESULT                 (0xffffffffUL)            /*!< RESULT (Bitfield-Mask: 0xffffffff)                    */
/* =========================================================  DATA  ========================================================== */
#define CRC_DATA_DATA_Pos                 (0UL)                     /*!< DATA (Bit 0)                                          */
#define CRC_DATA_DATA_Msk                 (0xffffffffUL)            /*!< DATA (Bitfield-Mask: 0xffffffff)                      */
#define CRC_DATA_DATA                     (0xffffffffUL)            /*!< DATA (Bitfield-Mask: 0xffffffff)                      */


/* =========================================================================================================================== */
/* ================                                           I2C1                                            ================ */
/* =========================================================================================================================== */

/* ==========================================================  CR1  ========================================================== */
#define I2C_CR1_GCEN_Pos                 (19UL)                    /*!< GCEN (Bit 19)                                         */
#define I2C_CR1_GCEN_Msk                 (0x80000UL)               /*!< GCEN (Bitfield-Mask: 0x01)                            */
#define I2C_CR1_GCEN                     (0x80000UL)               /*!< GCEN (Bitfield-Mask: 0x01)                            */
#define I2C_CR1_NOSTRETCH_Pos            (17UL)                    /*!< NOSTRETCH (Bit 17)                                    */
#define I2C_CR1_NOSTRETCH_Msk            (0x20000UL)               /*!< NOSTRETCH (Bitfield-Mask: 0x01)                       */
#define I2C_CR1_NOSTRETCH                (0x20000UL)               /*!< NOSTRETCH (Bitfield-Mask: 0x01)                       */
#define I2C_CR1_SBC_Pos                  (16UL)                    /*!< SBC (Bit 16)                                          */
#define I2C_CR1_SBC_Msk                  (0x10000UL)               /*!< SBC (Bitfield-Mask: 0x01)                             */
#define I2C_CR1_SBC                      (0x10000UL)               /*!< SBC (Bitfield-Mask: 0x01)                             */
#define I2C_CR1_RXDMAEN_Pos              (15UL)                    /*!< RXDMAEN (Bit 15)                                      */
#define I2C_CR1_RXDMAEN_Msk              (0x8000UL)                /*!< RXDMAEN (Bitfield-Mask: 0x01)                         */
#define I2C_CR1_RXDMAEN                  (0x8000UL)                /*!< RXDMAEN (Bitfield-Mask: 0x01)                         */
#define I2C_CR1_TXDMAEN_Pos              (14UL)                    /*!< TXDMAEN (Bit 14)                                      */
#define I2C_CR1_TXDMAEN_Msk              (0x4000UL)                /*!< TXDMAEN (Bitfield-Mask: 0x01)                         */
#define I2C_CR1_TXDMAEN                  (0x4000UL)                /*!< TXDMAEN (Bitfield-Mask: 0x01)                         */
#define I2C_CR1_DNF_Pos                  (8UL)                     /*!< DNF (Bit 8)                                           */
#define I2C_CR1_DNF_Msk                  (0xf00UL)                 /*!< DNF (Bitfield-Mask: 0x0f)                             */
#define I2C_CR1_DNF                      (0xf00UL)                 /*!< DNF (Bitfield-Mask: 0x0f)                             */
#define I2C_CR1_ERRIE_Pos                (7UL)                     /*!< ERRIE (Bit 7)                                         */
#define I2C_CR1_ERRIE_Msk                (0x80UL)                  /*!< ERRIE (Bitfield-Mask: 0x01)                           */
#define I2C_CR1_ERRIE                    (0x80UL)                  /*!< ERRIE (Bitfield-Mask: 0x01)                           */
#define I2C_CR1_TCIE_Pos                 (6UL)                     /*!< TCIE (Bit 6)                                          */
#define I2C_CR1_TCIE_Msk                 (0x40UL)                  /*!< TCIE (Bitfield-Mask: 0x01)                            */
#define I2C_CR1_TCIE                     (0x40UL)                  /*!< TCIE (Bitfield-Mask: 0x01)                            */
#define I2C_CR1_STOPIE_Pos               (5UL)                     /*!< STOPIE (Bit 5)                                        */
#define I2C_CR1_STOPIE_Msk               (0x20UL)                  /*!< STOPIE (Bitfield-Mask: 0x01)                          */
#define I2C_CR1_STOPIE                   (0x20UL)                  /*!< STOPIE (Bitfield-Mask: 0x01)                          */
#define I2C_CR1_NACKIE_Pos               (4UL)                     /*!< NACKIE (Bit 4)                                        */
#define I2C_CR1_NACKIE_Msk               (0x10UL)                  /*!< NACKIE (Bitfield-Mask: 0x01)                          */
#define I2C_CR1_NACKIE                   (0x10UL)                  /*!< NACKIE (Bitfield-Mask: 0x01)                          */
#define I2C_CR1_ADDRIE_Pos               (3UL)                     /*!< ADDRIE (Bit 3)                                        */
#define I2C_CR1_ADDRIE_Msk               (0x8UL)                   /*!< ADDRIE (Bitfield-Mask: 0x01)                          */
#define I2C_CR1_ADDRIE                   (0x8UL)                   /*!< ADDRIE (Bitfield-Mask: 0x01)                          */
#define I2C_CR1_RXIE_Pos                 (2UL)                     /*!< RXIE (Bit 2)                                          */
#define I2C_CR1_RXIE_Msk                 (0x4UL)                   /*!< RXIE (Bitfield-Mask: 0x01)                            */
#define I2C_CR1_RXIE                     (0x4UL)                   /*!< RXIE (Bitfield-Mask: 0x01)                            */
#define I2C_CR1_TXIE_Pos                 (1UL)                     /*!< TXIE (Bit 1)                                          */
#define I2C_CR1_TXIE_Msk                 (0x2UL)                   /*!< TXIE (Bitfield-Mask: 0x01)                            */
#define I2C_CR1_TXIE                     (0x2UL)                   /*!< TXIE (Bitfield-Mask: 0x01)                            */
#define I2C_CR1_PE_Pos                   (0UL)                     /*!< PE (Bit 0)                                            */
#define I2C_CR1_PE_Msk                   (0x1UL)                   /*!< PE (Bitfield-Mask: 0x01)                              */
#define I2C_CR1_PE                       (0x1UL)                   /*!< PE (Bitfield-Mask: 0x01)                              */
/* ==========================================================  CR2  ========================================================== */
#define I2C_CR2_AUTOEND_Pos              (25UL)                    /*!< AUTOEND (Bit 25)                                      */
#define I2C_CR2_AUTOEND_Msk              (0x2000000UL)             /*!< AUTOEND (Bitfield-Mask: 0x01)                         */
#define I2C_CR2_AUTOEND                  (0x2000000UL)             /*!< AUTOEND (Bitfield-Mask: 0x01)                         */
#define I2C_CR2_RELOAD_Pos               (24UL)                    /*!< RELOAD (Bit 24)                                       */
#define I2C_CR2_RELOAD_Msk               (0x1000000UL)             /*!< RELOAD (Bitfield-Mask: 0x01)                          */
#define I2C_CR2_RELOAD                   (0x1000000UL)             /*!< RELOAD (Bitfield-Mask: 0x01)                          */
#define I2C_CR2_NBYTES_Pos               (16UL)                    /*!< NBYTES (Bit 16)                                       */
#define I2C_CR2_NBYTES_Msk               (0xff0000UL)              /*!< NBYTES (Bitfield-Mask: 0xff)                          */
#define I2C_CR2_NBYTES                   (0xff0000UL)              /*!< NBYTES (Bitfield-Mask: 0xff)                          */
#define I2C_CR2_NACK_Pos                 (15UL)                    /*!< NACK (Bit 15)                                         */
#define I2C_CR2_NACK_Msk                 (0x8000UL)                /*!< NACK (Bitfield-Mask: 0x01)                            */
#define I2C_CR2_NACK                     (0x8000UL)                /*!< NACK (Bitfield-Mask: 0x01)                            */
#define I2C_CR2_STOP_Pos                 (14UL)                    /*!< STOP (Bit 14)                                         */
#define I2C_CR2_STOP_Msk                 (0x4000UL)                /*!< STOP (Bitfield-Mask: 0x01)                            */
#define I2C_CR2_STOP                     (0x4000UL)                /*!< STOP (Bitfield-Mask: 0x01)                            */
#define I2C_CR2_START_Pos                (13UL)                    /*!< START (Bit 13)                                        */
#define I2C_CR2_START_Msk                (0x2000UL)                /*!< START (Bitfield-Mask: 0x01)                           */
#define I2C_CR2_START                    (0x2000UL)                /*!< START (Bitfield-Mask: 0x01)                           */
#define I2C_CR2_HEAD10R_Pos              (12UL)                    /*!< HEAD10R (Bit 12)                                      */
#define I2C_CR2_HEAD10R_Msk              (0x1000UL)                /*!< HEAD10R (Bitfield-Mask: 0x01)                         */
#define I2C_CR2_HEAD10R                  (0x1000UL)                /*!< HEAD10R (Bitfield-Mask: 0x01)                         */
#define I2C_CR2_ADD10_Pos                (11UL)                    /*!< ADD10 (Bit 11)                                        */
#define I2C_CR2_ADD10_Msk                (0x800UL)                 /*!< ADD10 (Bitfield-Mask: 0x01)                           */
#define I2C_CR2_ADD10                    (0x800UL)                 /*!< ADD10 (Bitfield-Mask: 0x01)                           */
#define I2C_CR2_RD_WRN_Pos               (10UL)                    /*!< RD_WRN (Bit 10)                                       */
#define I2C_CR2_RD_WRN_Msk               (0x400UL)                 /*!< RD_WRN (Bitfield-Mask: 0x01)                          */
#define I2C_CR2_RD_WRN                   (0x400UL)                 /*!< RD_WRN (Bitfield-Mask: 0x01)                          */
#define I2C_CR2_SADD_Pos                 (0UL)                     /*!< SADD (Bit 0)                                          */
#define I2C_CR2_SADD_Msk                 (0x3ffUL)                 /*!< SADD (Bitfield-Mask: 0x3ff)                           */
#define I2C_CR2_SADD                     (0x3ffUL)                 /*!< SADD (Bitfield-Mask: 0x3ff)                           */
/* =========================================================  OAR1  ========================================================== */
#define I2C_OAR1_OA1EN_Pos               (15UL)                    /*!< OA1EN (Bit 15)                                        */
#define I2C_OAR1_OA1EN_Msk               (0x8000UL)                /*!< OA1EN (Bitfield-Mask: 0x01)                           */
#define I2C_OAR1_OA1EN                   (0x8000UL)                /*!< OA1EN (Bitfield-Mask: 0x01)                           */
#define I2C_OAR1_OA1MODE_Pos             (10UL)                    /*!< OA1MODE (Bit 10)                                      */
#define I2C_OAR1_OA1MODE_Msk             (0x400UL)                 /*!< OA1MODE (Bitfield-Mask: 0x01)                         */
#define I2C_OAR1_OA1MODE                 (0x400UL)                 /*!< OA1MODE (Bitfield-Mask: 0x01)                         */
#define I2C_OAR1_OA1_Pos                 (0UL)                     /*!< OA1 (Bit 0)                                           */
#define I2C_OAR1_OA1_Msk                 (0x3ffUL)                 /*!< OA1 (Bitfield-Mask: 0x3ff)                            */
#define I2C_OAR1_OA1                     (0x3ffUL)                 /*!< OA1 (Bitfield-Mask: 0x3ff)                            */
/* =========================================================  OAR2  ========================================================== */
#define I2C_OAR2_OA2EN_Pos               (15UL)                    /*!< OA2EN (Bit 15)                                        */
#define I2C_OAR2_OA2EN_Msk               (0x8000UL)                /*!< OA2EN (Bitfield-Mask: 0x01)                           */
#define I2C_OAR2_OA2EN                   (0x8000UL)                /*!< OA2EN (Bitfield-Mask: 0x01)                           */
#define I2C_OAR2_OA2MSK_Pos              (8UL)                     /*!< OA2MSK (Bit 8)                                        */
#define I2C_OAR2_OA2MSK_Msk              (0x700UL)                 /*!< OA2MSK (Bitfield-Mask: 0x07)                          */
#define I2C_OAR2_OA2MSK                  (0x700UL)                 /*!< OA2MSK (Bitfield-Mask: 0x07)                          */
#define I2C_OAR2_OA2_Pos                 (1UL)                     /*!< OA2 (Bit 1)                                           */
#define I2C_OAR2_OA2_Msk                 (0xfeUL)                  /*!< OA2 (Bitfield-Mask: 0x7f)                             */
#define I2C_OAR2_OA2                     (0xfeUL)                  /*!< OA2 (Bitfield-Mask: 0x7f)                             */
/* ========================================================  TIMINGR  ======================================================== */
#define I2C_TIMINGR_PRESC_Pos            (28UL)                    /*!< PRESC (Bit 28)                                        */
#define I2C_TIMINGR_PRESC_Msk            (0xf0000000UL)            /*!< PRESC (Bitfield-Mask: 0x0f)                           */
#define I2C_TIMINGR_PRESC                (0xf0000000UL)            /*!< PRESC (Bitfield-Mask: 0x0f)                           */
#define I2C_TIMINGR_SCLDEL_Pos           (20UL)                    /*!< SCLDEL (Bit 20)                                       */
#define I2C_TIMINGR_SCLDEL_Msk           (0xf00000UL)              /*!< SCLDEL (Bitfield-Mask: 0x0f)                          */
#define I2C_TIMINGR_SCLDEL               (0xf00000UL)              /*!< SCLDEL (Bitfield-Mask: 0x0f)                          */
#define I2C_TIMINGR_SDADEL_Pos           (16UL)                    /*!< SDADEL (Bit 16)                                       */
#define I2C_TIMINGR_SDADEL_Msk           (0xf0000UL)               /*!< SDADEL (Bitfield-Mask: 0x0f)                          */
#define I2C_TIMINGR_SDADEL               (0xf0000UL)               /*!< SDADEL (Bitfield-Mask: 0x0f)                          */
#define I2C_TIMINGR_SCLH_Pos             (8UL)                     /*!< SCLH (Bit 8)                                          */
#define I2C_TIMINGR_SCLH_Msk             (0xff00UL)                /*!< SCLH (Bitfield-Mask: 0xff)                            */
#define I2C_TIMINGR_SCLH                 (0xff00UL)                /*!< SCLH (Bitfield-Mask: 0xff)                            */
#define I2C_TIMINGR_SCLL_Pos             (0UL)                     /*!< SCLL (Bit 0)                                          */
#define I2C_TIMINGR_SCLL_Msk             (0xffUL)                  /*!< SCLL (Bitfield-Mask: 0xff)                            */
#define I2C_TIMINGR_SCLL                 (0xffUL)                  /*!< SCLL (Bitfield-Mask: 0xff)                            */
/* ==========================================================  ISR  ========================================================== */
#define I2C_ISR_ADDCODE_Pos              (17UL)                    /*!< ADDCODE (Bit 17)                                      */
#define I2C_ISR_ADDCODE_Msk              (0xfe0000UL)              /*!< ADDCODE (Bitfield-Mask: 0x7f)                         */
#define I2C_ISR_ADDCODE                  (0xfe0000UL)              /*!< ADDCODE (Bitfield-Mask: 0x7f)                         */
#define I2C_ISR_DIR_Pos                  (16UL)                    /*!< DIR (Bit 16)                                          */
#define I2C_ISR_DIR_Msk                  (0x10000UL)               /*!< DIR (Bitfield-Mask: 0x01)                             */
#define I2C_ISR_DIR                      (0x10000UL)               /*!< DIR (Bitfield-Mask: 0x01)                             */
#define I2C_ISR_BUSY_Pos                 (15UL)                    /*!< BUSY (Bit 15)                                         */
#define I2C_ISR_BUSY_Msk                 (0x8000UL)                /*!< BUSY (Bitfield-Mask: 0x01)                            */
#define I2C_ISR_BUSY                     (0x8000UL)                /*!< BUSY (Bitfield-Mask: 0x01)                            */
#define I2C_ISR_OVR_Pos                  (10UL)                    /*!< OVR (Bit 10)                                          */
#define I2C_ISR_OVR_Msk                  (0x400UL)                 /*!< OVR (Bitfield-Mask: 0x01)                             */
#define I2C_ISR_OVR                      (0x400UL)                 /*!< OVR (Bitfield-Mask: 0x01)                             */
#define I2C_ISR_ARLO_Pos                 (9UL)                     /*!< ARLO (Bit 9)                                          */
#define I2C_ISR_ARLO_Msk                 (0x200UL)                 /*!< ARLO (Bitfield-Mask: 0x01)                            */
#define I2C_ISR_ARLO                     (0x200UL)                 /*!< ARLO (Bitfield-Mask: 0x01)                            */
#define I2C_ISR_BERR_Pos                 (8UL)                     /*!< BERR (Bit 8)                                          */
#define I2C_ISR_BERR_Msk                 (0x100UL)                 /*!< BERR (Bitfield-Mask: 0x01)                            */
#define I2C_ISR_BERR                     (0x100UL)                 /*!< BERR (Bitfield-Mask: 0x01)                            */
#define I2C_ISR_TCR_Pos                  (7UL)                     /*!< TCR (Bit 7)                                           */
#define I2C_ISR_TCR_Msk                  (0x80UL)                  /*!< TCR (Bitfield-Mask: 0x01)                             */
#define I2C_ISR_TCR                      (0x80UL)                  /*!< TCR (Bitfield-Mask: 0x01)                             */
#define I2C_ISR_TC_Pos                   (6UL)                     /*!< TC (Bit 6)                                            */
#define I2C_ISR_TC_Msk                   (0x40UL)                  /*!< TC (Bitfield-Mask: 0x01)                              */
#define I2C_ISR_TC                       (0x40UL)                  /*!< TC (Bitfield-Mask: 0x01)                              */
#define I2C_ISR_STOPF_Pos                (5UL)                     /*!< STOPF (Bit 5)                                         */
#define I2C_ISR_STOPF_Msk                (0x20UL)                  /*!< STOPF (Bitfield-Mask: 0x01)                           */
#define I2C_ISR_STOPF                    (0x20UL)                  /*!< STOPF (Bitfield-Mask: 0x01)                           */
#define I2C_ISR_NACKF_Pos                (4UL)                     /*!< NACKF (Bit 4)                                         */
#define I2C_ISR_NACKF_Msk                (0x10UL)                  /*!< NACKF (Bitfield-Mask: 0x01)                           */
#define I2C_ISR_NACKF                    (0x10UL)                  /*!< NACKF (Bitfield-Mask: 0x01)                           */
#define I2C_ISR_ADDR_Pos                 (3UL)                     /*!< ADDR (Bit 3)                                          */
#define I2C_ISR_ADDR_Msk                 (0x8UL)                   /*!< ADDR (Bitfield-Mask: 0x01)                            */
#define I2C_ISR_ADDR                     (0x8UL)                   /*!< ADDR (Bitfield-Mask: 0x01)                            */
#define I2C_ISR_RXNE_Pos                 (2UL)                     /*!< RXNE (Bit 2)                                          */
#define I2C_ISR_RXNE_Msk                 (0x4UL)                   /*!< RXNE (Bitfield-Mask: 0x01)                            */
#define I2C_ISR_RXNE                     (0x4UL)                   /*!< RXNE (Bitfield-Mask: 0x01)                            */
#define I2C_ISR_TXIS_Pos                 (1UL)                     /*!< TXIS (Bit 1)                                          */
#define I2C_ISR_TXIS_Msk                 (0x2UL)                   /*!< TXIS (Bitfield-Mask: 0x01)                            */
#define I2C_ISR_TXIS                     (0x2UL)                   /*!< TXIS (Bitfield-Mask: 0x01)                            */
#define I2C_ISR_TXE_Pos                  (0UL)                     /*!< TXE (Bit 0)                                           */
#define I2C_ISR_TXE_Msk                  (0x1UL)                   /*!< TXE (Bitfield-Mask: 0x01)                             */
#define I2C_ISR_TXE                      (0x1UL)                   /*!< TXE (Bitfield-Mask: 0x01)                             */
/* ==========================================================  ICR  ========================================================== */
#define I2C_ICR_OVRCF_Pos                (10UL)                    /*!< OVRCF (Bit 10)                                        */
#define I2C_ICR_OVRCF_Msk                (0x400UL)                 /*!< OVRCF (Bitfield-Mask: 0x01)                           */
#define I2C_ICR_OVRCF                    (0x400UL)                 /*!< OVRCF (Bitfield-Mask: 0x01)                           */
#define I2C_ICR_ARLOCF_Pos               (9UL)                     /*!< ARLOCF (Bit 9)                                        */
#define I2C_ICR_ARLOCF_Msk               (0x200UL)                 /*!< ARLOCF (Bitfield-Mask: 0x01)                          */
#define I2C_ICR_ARLOCF                   (0x200UL)                 /*!< ARLOCF (Bitfield-Mask: 0x01)                          */
#define I2C_ICR_BERRCF_Pos               (8UL)                     /*!< BERRCF (Bit 8)                                        */
#define I2C_ICR_BERRCF_Msk               (0x100UL)                 /*!< BERRCF (Bitfield-Mask: 0x01)                          */
#define I2C_ICR_BERRCF                   (0x100UL)                 /*!< BERRCF (Bitfield-Mask: 0x01)                          */
#define I2C_ICR_STOPCF_Pos               (5UL)                     /*!< STOPCF (Bit 5)                                        */
#define I2C_ICR_STOPCF_Msk               (0x20UL)                  /*!< STOPCF (Bitfield-Mask: 0x01)                          */
#define I2C_ICR_STOPCF                   (0x20UL)                  /*!< STOPCF (Bitfield-Mask: 0x01)                          */
#define I2C_ICR_NACKCF_Pos               (4UL)                     /*!< NACKCF (Bit 4)                                        */
#define I2C_ICR_NACKCF_Msk               (0x10UL)                  /*!< NACKCF (Bitfield-Mask: 0x01)                          */
#define I2C_ICR_NACKCF                   (0x10UL)                  /*!< NACKCF (Bitfield-Mask: 0x01)                          */
#define I2C_ICR_ADDRCF_Pos               (3UL)                     /*!< ADDRCF (Bit 3)                                        */
#define I2C_ICR_ADDRCF_Msk               (0x8UL)                   /*!< ADDRCF (Bitfield-Mask: 0x01)                          */
#define I2C_ICR_ADDRCF                   (0x8UL)                   /*!< ADDRCF (Bitfield-Mask: 0x01)                          */
/* =========================================================  RXDR  ========================================================== */
#define I2C_RXDR_RXDATA_Pos              (0UL)                     /*!< RXDATA (Bit 0)                                        */
#define I2C_RXDR_RXDATA_Msk              (0xffUL)                  /*!< RXDATA (Bitfield-Mask: 0xff)                          */
#define I2C_RXDR_RXDATA                  (0xffUL)                  /*!< RXDATA (Bitfield-Mask: 0xff)                          */
/* =========================================================  TXDR  ========================================================== */
#define I2C_TXDR_TXDATA_Pos              (0UL)                     /*!< TXDATA (Bit 0)                                        */
#define I2C_TXDR_TXDATA_Msk              (0xffUL)                  /*!< TXDATA (Bitfield-Mask: 0xff)                          */
#define I2C_TXDR_TXDATA                  (0xffUL)                  /*!< TXDATA (Bitfield-Mask: 0xff)                          */


/* =========================================================================================================================== */
/* ================                                           UART1                                           ================ */
/* =========================================================================================================================== */

/* ==========================================================  CR1  ========================================================== */
#define UART_CR1_M1_Pos                  (28UL)                    /*!< M1 (Bit 28)                                           */
#define UART_CR1_M1_Msk                  (0x10000000UL)            /*!< M1 (Bitfield-Mask: 0x01)                              */
#define UART_CR1_M1                      (0x10000000UL)            /*!< M1 (Bitfield-Mask: 0x01)                              */
#define UART_CR1_RTOIE_Pos               (26UL)                    /*!< RTOIE (Bit 26)                                        */
#define UART_CR1_RTOIE_Msk               (0x4000000UL)             /*!< RTOIE (Bitfield-Mask: 0x01)                           */
#define UART_CR1_RTOIE                   (0x4000000UL)             /*!< RTOIE (Bitfield-Mask: 0x01)                           */
#define UART_CR1_CMIE_Pos                (14UL)                    /*!< CMIE (Bit 14)                                         */
#define UART_CR1_CMIE_Msk                (0x4000UL)                /*!< CMIE (Bitfield-Mask: 0x01)                            */
#define UART_CR1_CMIE                    (0x4000UL)                /*!< CMIE (Bitfield-Mask: 0x01)                            */
#define UART_CR1_MME_Pos                 (13UL)                    /*!< MME (Bit 13)                                          */
#define UART_CR1_MME_Msk                 (0x2000UL)                /*!< MME (Bitfield-Mask: 0x01)                             */
#define UART_CR1_MME                     (0x2000UL)                /*!< MME (Bitfield-Mask: 0x01)                             */
#define UART_CR1_M0_Pos                  (12UL)                    /*!< M0 (Bit 12)                                           */
#define UART_CR1_M0_Msk                  (0x1000UL)                /*!< M0 (Bitfield-Mask: 0x01)                              */
#define UART_CR1_M0                      (0x1000UL)                /*!< M0 (Bitfield-Mask: 0x01)                              */
#define UART_CR1_WAKE_Pos                (11UL)                    /*!< WAKE (Bit 11)                                         */
#define UART_CR1_WAKE_Msk                (0x800UL)                 /*!< WAKE (Bitfield-Mask: 0x01)                            */
#define UART_CR1_WAKE                    (0x800UL)                 /*!< WAKE (Bitfield-Mask: 0x01)                            */
#define UART_CR1_PCE_Pos                 (10UL)                    /*!< PCE (Bit 10)                                          */
#define UART_CR1_PCE_Msk                 (0x400UL)                 /*!< PCE (Bitfield-Mask: 0x01)                             */
#define UART_CR1_PCE                     (0x400UL)                 /*!< PCE (Bitfield-Mask: 0x01)                             */
#define UART_CR1_PS_Pos                  (9UL)                     /*!< PS (Bit 9)                                            */
#define UART_CR1_PS_Msk                  (0x200UL)                 /*!< PS (Bitfield-Mask: 0x01)                              */
#define UART_CR1_PS                      (0x200UL)                 /*!< PS (Bitfield-Mask: 0x01)                              */
#define UART_CR1_PEIE_Pos                (8UL)                     /*!< PEIE (Bit 8)                                          */
#define UART_CR1_PEIE_Msk                (0x100UL)                 /*!< PEIE (Bitfield-Mask: 0x01)                            */
#define UART_CR1_PEIE                    (0x100UL)                 /*!< PEIE (Bitfield-Mask: 0x01)                            */
#define UART_CR1_TXEIE_Pos               (7UL)                     /*!< TXEIE (Bit 7)                                         */
#define UART_CR1_TXEIE_Msk               (0x80UL)                  /*!< TXEIE (Bitfield-Mask: 0x01)                           */
#define UART_CR1_TXEIE                   (0x80UL)                  /*!< TXEIE (Bitfield-Mask: 0x01)                           */
#define UART_CR1_TCIE_Pos                (6UL)                     /*!< TCIE (Bit 6)                                          */
#define UART_CR1_TCIE_Msk                (0x40UL)                  /*!< TCIE (Bitfield-Mask: 0x01)                            */
#define UART_CR1_TCIE                    (0x40UL)                  /*!< TCIE (Bitfield-Mask: 0x01)                            */
#define UART_CR1_RXNEIE_Pos              (5UL)                     /*!< RXNEIE (Bit 5)                                        */
#define UART_CR1_RXNEIE_Msk              (0x20UL)                  /*!< RXNEIE (Bitfield-Mask: 0x01)                          */
#define UART_CR1_RXNEIE                  (0x20UL)                  /*!< RXNEIE (Bitfield-Mask: 0x01)                          */
#define UART_CR1_IDLEIE_Pos              (4UL)                     /*!< IDLEIE (Bit 4)                                        */
#define UART_CR1_IDLEIE_Msk              (0x10UL)                  /*!< IDLEIE (Bitfield-Mask: 0x01)                          */
#define UART_CR1_IDLEIE                  (0x10UL)                  /*!< IDLEIE (Bitfield-Mask: 0x01)                          */
#define UART_CR1_TE_Pos                  (3UL)                     /*!< TE (Bit 3)                                            */
#define UART_CR1_TE_Msk                  (0x8UL)                   /*!< TE (Bitfield-Mask: 0x01)                              */
#define UART_CR1_TE                      (0x8UL)                   /*!< TE (Bitfield-Mask: 0x01)                              */
#define UART_CR1_RE_Pos                  (2UL)                     /*!< RE (Bit 2)                                            */
#define UART_CR1_RE_Msk                  (0x4UL)                   /*!< RE (Bitfield-Mask: 0x01)                              */
#define UART_CR1_RE                      (0x4UL)                   /*!< RE (Bitfield-Mask: 0x01)                              */
#define UART_CR1_UE_Pos                  (0UL)                     /*!< UE (Bit 0)                                            */
#define UART_CR1_UE_Msk                  (0x1UL)                   /*!< UE (Bitfield-Mask: 0x01)                              */
#define UART_CR1_UE                      (0x1UL)                   /*!< UE (Bitfield-Mask: 0x01)                              */
/* ==========================================================  CR2  ========================================================== */
#define UART_CR2_ADD_Pos                 (24UL)                    /*!< ADD (Bit 24)                                          */
#define UART_CR2_ADD_Msk                 (0xff000000UL)            /*!< ADD (Bitfield-Mask: 0xff)                             */
#define UART_CR2_ADD                     (0xff000000UL)            /*!< ADD (Bitfield-Mask: 0xff)                             */
#define UART_CR2_RTOEN_Pos               (23UL)                    /*!< RTOEN (Bit 23)                                        */
#define UART_CR2_RTOEN_Msk               (0x800000UL)              /*!< RTOEN (Bitfield-Mask: 0x01)                           */
#define UART_CR2_RTOEN                   (0x800000UL)              /*!< RTOEN (Bitfield-Mask: 0x01)                           */
#define UART_CR2_ABRMOD_Pos              (21UL)                    /*!< ABRMOD (Bit 21)                                       */
#define UART_CR2_ABRMOD_Msk              (0x600000UL)              /*!< ABRMOD (Bitfield-Mask: 0x03)                          */
#define UART_CR2_ABRMOD                  (0x600000UL)              /*!< ABRMOD (Bitfield-Mask: 0x03)                          */
#define UART_CR2_ABREN_Pos               (20UL)                    /*!< ABREN (Bit 20)                                        */
#define UART_CR2_ABREN_Msk               (0x100000UL)              /*!< ABREN (Bitfield-Mask: 0x01)                           */
#define UART_CR2_ABREN                   (0x100000UL)              /*!< ABREN (Bitfield-Mask: 0x01)                           */
#define UART_CR2_MSBFIRST_Pos            (19UL)                    /*!< MSBFIRST (Bit 19)                                     */
#define UART_CR2_MSBFIRST_Msk            (0x80000UL)               /*!< MSBFIRST (Bitfield-Mask: 0x01)                        */
#define UART_CR2_MSBFIRST                (0x80000UL)               /*!< MSBFIRST (Bitfield-Mask: 0x01)                        */
#define UART_CR2_DATAINV_Pos             (18UL)                    /*!< DATAINV (Bit 18)                                      */
#define UART_CR2_DATAINV_Msk             (0x40000UL)               /*!< DATAINV (Bitfield-Mask: 0x01)                         */
#define UART_CR2_DATAINV                 (0x40000UL)               /*!< DATAINV (Bitfield-Mask: 0x01)                         */
#define UART_CR2_TXINV_Pos               (17UL)                    /*!< TXINV (Bit 17)                                        */
#define UART_CR2_TXINV_Msk               (0x20000UL)               /*!< TXINV (Bitfield-Mask: 0x01)                           */
#define UART_CR2_TXINV                   (0x20000UL)               /*!< TXINV (Bitfield-Mask: 0x01)                           */
#define UART_CR2_RXINV_Pos               (16UL)                    /*!< RXINV (Bit 16)                                        */
#define UART_CR2_RXINV_Msk               (0x10000UL)               /*!< RXINV (Bitfield-Mask: 0x01)                           */
#define UART_CR2_RXINV                   (0x10000UL)               /*!< RXINV (Bitfield-Mask: 0x01)                           */
#define UART_CR2_STOP_Pos                (12UL)                    /*!< STOP (Bit 12)                                         */
#define UART_CR2_STOP_Msk                (0x3000UL)                /*!< STOP (Bitfield-Mask: 0x03)                            */
#define UART_CR2_STOP                    (0x3000UL)                /*!< STOP (Bitfield-Mask: 0x03)                            */
#define UART_CR2_ADDM7_Pos               (4UL)                     /*!< ADDM7 (Bit 4)                                         */
#define UART_CR2_ADDM7_Msk               (0x10UL)                  /*!< ADDM7 (Bitfield-Mask: 0x01)                           */
#define UART_CR2_ADDM7                   (0x10UL)                  /*!< ADDM7 (Bitfield-Mask: 0x01)                           */
/* ==========================================================  CR3  ========================================================== */
#define UART_CR3_OVRDIS_Pos              (12UL)                    /*!< OVRDIS (Bit 12)                                       */
#define UART_CR3_OVRDIS_Msk              (0x1000UL)                /*!< OVRDIS (Bitfield-Mask: 0x01)                          */
#define UART_CR3_OVRDIS                  (0x1000UL)                /*!< OVRDIS (Bitfield-Mask: 0x01)                          */
#define UART_CR3_ONEBIT_Pos              (11UL)                    /*!< ONEBIT (Bit 11)                                       */
#define UART_CR3_ONEBIT_Msk              (0x800UL)                 /*!< ONEBIT (Bitfield-Mask: 0x01)                          */
#define UART_CR3_ONEBIT                  (0x800UL)                 /*!< ONEBIT (Bitfield-Mask: 0x01)                          */
#define UART_CR3_DMAT_Pos                (7UL)                     /*!< DMAT (Bit 7)                                          */
#define UART_CR3_DMAT_Msk                (0x80UL)                  /*!< DMAT (Bitfield-Mask: 0x01)                            */
#define UART_CR3_DMAT                    (0x80UL)                  /*!< DMAT (Bitfield-Mask: 0x01)                            */
#define UART_CR3_DMAR_Pos                (6UL)                     /*!< DMAR (Bit 6)                                          */
#define UART_CR3_DMAR_Msk                (0x40UL)                  /*!< DMAR (Bitfield-Mask: 0x01)                            */
#define UART_CR3_DMAR                    (0x40UL)                  /*!< DMAR (Bitfield-Mask: 0x01)                            */
#define UART_CR3_EIE_Pos                 (0UL)                     /*!< EIE (Bit 0)                                           */
#define UART_CR3_EIE_Msk                 (0x1UL)                   /*!< EIE (Bitfield-Mask: 0x01)                             */
#define UART_CR3_EIE                     (0x1UL)                   /*!< EIE (Bitfield-Mask: 0x01)                             */
/* ==========================================================  BRR  ========================================================== */
#define UART_BRR_BRR_Pos                 (0UL)                     /*!< BRR (Bit 0)                                           */
#define UART_BRR_BRR_Msk                 (0xffffUL)                /*!< BRR (Bitfield-Mask: 0xffff)                           */
#define UART_BRR_BRR                     (0xffffUL)                /*!< BRR (Bitfield-Mask: 0xffff)                           */
/* =========================================================  RTOR  ========================================================== */
#define UART_RTOR_RTO_Pos                (0UL)                     /*!< RTO (Bit 0)                                           */
#define UART_RTOR_RTO_Msk                (0xffffffUL)              /*!< RTO (Bitfield-Mask: 0xffffff)                         */
#define UART_RTOR_RTO                    (0xffffffUL)              /*!< RTO (Bitfield-Mask: 0xffffff)                         */
/* ==========================================================  RQR  ========================================================== */
#define UART_RQR_RXFRQ_Pos               (3UL)                     /*!< RXFRQ (Bit 3)                                         */
#define UART_RQR_RXFRQ_Msk               (0x8UL)                   /*!< RXFRQ (Bitfield-Mask: 0x01)                           */
#define UART_RQR_RXFRQ                   (0x8UL)                   /*!< RXFRQ (Bitfield-Mask: 0x01)                           */
#define UART_RQR_MMRQ_Pos                (2UL)                     /*!< MMRQ (Bit 2)                                          */
#define UART_RQR_MMRQ_Msk                (0x4UL)                   /*!< MMRQ (Bitfield-Mask: 0x01)                            */
#define UART_RQR_MMRQ                    (0x4UL)                   /*!< MMRQ (Bitfield-Mask: 0x01)                            */
#define UART_RQR_SBKRQ_Pos               (1UL)                     /*!< SBKRQ (Bit 1)                                         */
#define UART_RQR_SBKRQ_Msk               (0x2UL)                   /*!< SBKRQ (Bitfield-Mask: 0x01)                           */
#define UART_RQR_SBKRQ                   (0x2UL)                   /*!< SBKRQ (Bitfield-Mask: 0x01)                           */
#define UART_RQR_ABRRQ_Pos               (0UL)                     /*!< ABRRQ (Bit 0)                                         */
#define UART_RQR_ABRRQ_Msk               (0x1UL)                   /*!< ABRRQ (Bitfield-Mask: 0x01)                           */
#define UART_RQR_ABRRQ                   (0x1UL)                   /*!< ABRRQ (Bitfield-Mask: 0x01)                           */
/* ==========================================================  ISR  ========================================================== */
#define UART_ISR_RWU_Pos                 (19UL)                    /*!< RWU (Bit 19)                                          */
#define UART_ISR_RWU_Msk                 (0x80000UL)               /*!< RWU (Bitfield-Mask: 0x01)                             */
#define UART_ISR_RWU                     (0x80000UL)               /*!< RWU (Bitfield-Mask: 0x01)                             */
#define UART_ISR_SBKF_Pos                (18UL)                    /*!< SBKF (Bit 18)                                         */
#define UART_ISR_SBKF_Msk                (0x40000UL)               /*!< SBKF (Bitfield-Mask: 0x01)                            */
#define UART_ISR_SBKF                    (0x40000UL)               /*!< SBKF (Bitfield-Mask: 0x01)                            */
#define UART_ISR_CMF_Pos                 (17UL)                    /*!< CMF (Bit 17)                                          */
#define UART_ISR_CMF_Msk                 (0x20000UL)               /*!< CMF (Bitfield-Mask: 0x01)                             */
#define UART_ISR_CMF                     (0x20000UL)               /*!< CMF (Bitfield-Mask: 0x01)                             */
#define UART_ISR_BUSY_Pos                (16UL)                    /*!< BUSY (Bit 16)                                         */
#define UART_ISR_BUSY_Msk                (0x10000UL)               /*!< BUSY (Bitfield-Mask: 0x01)                            */
#define UART_ISR_BUSY                    (0x10000UL)               /*!< BUSY (Bitfield-Mask: 0x01)                            */
#define UART_ISR_ABRF_Pos                (15UL)                    /*!< ABRF (Bit 15)                                         */
#define UART_ISR_ABRF_Msk                (0x8000UL)                /*!< ABRF (Bitfield-Mask: 0x01)                            */
#define UART_ISR_ABRF                    (0x8000UL)                /*!< ABRF (Bitfield-Mask: 0x01)                            */
#define UART_ISR_ABRE_Pos                (14UL)                    /*!< ABRE (Bit 14)                                         */
#define UART_ISR_ABRE_Msk                (0x4000UL)                /*!< ABRE (Bitfield-Mask: 0x01)                            */
#define UART_ISR_ABRE                    (0x4000UL)                /*!< ABRE (Bitfield-Mask: 0x01)                            */
#define UART_ISR_RTOF_Pos                (11UL)                    /*!< RTOF (Bit 11)                                         */
#define UART_ISR_RTOF_Msk                (0x800UL)                 /*!< RTOF (Bitfield-Mask: 0x01)                            */
#define UART_ISR_RTOF                    (0x800UL)                 /*!< RTOF (Bitfield-Mask: 0x01)                            */
#define UART_ISR_TXE_Pos                 (7UL)                     /*!< TXE (Bit 7)                                           */
#define UART_ISR_TXE_Msk                 (0x80UL)                  /*!< TXE (Bitfield-Mask: 0x01)                             */
#define UART_ISR_TXE                     (0x80UL)                  /*!< TXE (Bitfield-Mask: 0x01)                             */
#define UART_ISR_TC_Pos                  (6UL)                     /*!< TC (Bit 6)                                            */
#define UART_ISR_TC_Msk                  (0x40UL)                  /*!< TC (Bitfield-Mask: 0x01)                              */
#define UART_ISR_TC                      (0x40UL)                  /*!< TC (Bitfield-Mask: 0x01)                              */
#define UART_ISR_RXNE_Pos                (5UL)                     /*!< RXNE (Bit 5)                                          */
#define UART_ISR_RXNE_Msk                (0x20UL)                  /*!< RXNE (Bitfield-Mask: 0x01)                            */
#define UART_ISR_RXNE                    (0x20UL)                  /*!< RXNE (Bitfield-Mask: 0x01)                            */
#define UART_ISR_IDLE_Pos                (4UL)                     /*!< IDLE (Bit 4)                                          */
#define UART_ISR_IDLE_Msk                (0x10UL)                  /*!< IDLE (Bitfield-Mask: 0x01)                            */
#define UART_ISR_IDLE                    (0x10UL)                  /*!< IDLE (Bitfield-Mask: 0x01)                            */
#define UART_ISR_ORE_Pos                 (3UL)                     /*!< ORE (Bit 3)                                           */
#define UART_ISR_ORE_Msk                 (0x8UL)                   /*!< ORE (Bitfield-Mask: 0x01)                             */
#define UART_ISR_ORE                     (0x8UL)                   /*!< ORE (Bitfield-Mask: 0x01)                             */
#define UART_ISR_NF_Pos                  (2UL)                     /*!< NF (Bit 2)                                            */
#define UART_ISR_NF_Msk                  (0x4UL)                   /*!< NF (Bitfield-Mask: 0x01)                              */
#define UART_ISR_NF                      (0x4UL)                   /*!< NF (Bitfield-Mask: 0x01)                              */
#define UART_ISR_FE_Pos                  (1UL)                     /*!< FE (Bit 1)                                            */
#define UART_ISR_FE_Msk                  (0x2UL)                   /*!< FE (Bitfield-Mask: 0x01)                              */
#define UART_ISR_FE                      (0x2UL)                   /*!< FE (Bitfield-Mask: 0x01)                              */
#define UART_ISR_PE_Pos                  (0UL)                     /*!< PE (Bit 0)                                            */
#define UART_ISR_PE_Msk                  (0x1UL)                   /*!< PE (Bitfield-Mask: 0x01)                              */
#define UART_ISR_PE                      (0x1UL)                   /*!< PE (Bitfield-Mask: 0x01)                              */
/* ==========================================================  ICR  ========================================================== */
#define UART_ICR_CMCF_Pos                (17UL)                    /*!< CMCF (Bit 17)                                         */
#define UART_ICR_CMCF_Msk                (0x20000UL)               /*!< CMCF (Bitfield-Mask: 0x01)                            */
#define UART_ICR_CMCF                    (0x20000UL)               /*!< CMCF (Bitfield-Mask: 0x01)                            */
#define UART_ICR_RTOCF_Pos               (11UL)                    /*!< RTOCF (Bit 11)                                        */
#define UART_ICR_RTOCF_Msk               (0x800UL)                 /*!< RTOCF (Bitfield-Mask: 0x01)                           */
#define UART_ICR_RTOCF                   (0x800UL)                 /*!< RTOCF (Bitfield-Mask: 0x01)                           */
#define UART_ICR_TCCF_Pos                (6UL)                     /*!< TCCF (Bit 6)                                          */
#define UART_ICR_TCCF_Msk                (0x40UL)                  /*!< TCCF (Bitfield-Mask: 0x01)                            */
#define UART_ICR_TCCF                    (0x40UL)                  /*!< TCCF (Bitfield-Mask: 0x01)                            */
#define UART_ICR_IDLECF_Pos              (4UL)                     /*!< IDLECF (Bit 4)                                        */
#define UART_ICR_IDLECF_Msk              (0x10UL)                  /*!< IDLECF (Bitfield-Mask: 0x01)                          */
#define UART_ICR_IDLECF                  (0x10UL)                  /*!< IDLECF (Bitfield-Mask: 0x01)                          */
#define UART_ICR_ORECF_Pos               (3UL)                     /*!< ORECF (Bit 3)                                         */
#define UART_ICR_ORECF_Msk               (0x8UL)                   /*!< ORECF (Bitfield-Mask: 0x01)                           */
#define UART_ICR_ORECF                   (0x8UL)                   /*!< ORECF (Bitfield-Mask: 0x01)                           */
#define UART_ICR_NCF_Pos                 (2UL)                     /*!< NCF (Bit 2)                                           */
#define UART_ICR_NCF_Msk                 (0x4UL)                   /*!< NCF (Bitfield-Mask: 0x01)                             */
#define UART_ICR_NCF                     (0x4UL)                   /*!< NCF (Bitfield-Mask: 0x01)                             */
#define UART_ICR_FECF_Pos                (1UL)                     /*!< FECF (Bit 1)                                          */
#define UART_ICR_FECF_Msk                (0x2UL)                   /*!< FECF (Bitfield-Mask: 0x01)                            */
#define UART_ICR_FECF                    (0x2UL)                   /*!< FECF (Bitfield-Mask: 0x01)                            */
#define UART_ICR_PECF_Pos                (0UL)                     /*!< PECF (Bit 0)                                          */
#define UART_ICR_PECF_Msk                (0x1UL)                   /*!< PECF (Bitfield-Mask: 0x01)                            */
#define UART_ICR_PECF                    (0x1UL)                   /*!< PECF (Bitfield-Mask: 0x01)                            */
/* ==========================================================  RDR  ========================================================== */
#define UART_RDR_RDR_Pos                 (0UL)                     /*!< RDR (Bit 0)                                           */
#define UART_RDR_RDR_Msk                 (0x1ffUL)                 /*!< RDR (Bitfield-Mask: 0x1ff)                            */
#define UART_RDR_RDR                     (0x1ffUL)                 /*!< RDR (Bitfield-Mask: 0x1ff)                            */
/* ==========================================================  TDR  ========================================================== */
#define UART_TDR_TDR_Pos                 (0UL)                     /*!< TDR (Bit 0)                                           */
#define UART_TDR_TDR_Msk                 (0x1ffUL)                 /*!< TDR (Bitfield-Mask: 0x1ff)                            */
#define UART_TDR_TDR                     (0x1ffUL)                 /*!< TDR (Bitfield-Mask: 0x1ff)                            */


/* =========================================================================================================================== */
/* ================                                           WWDG                                            ================ */
/* =========================================================================================================================== */

/* ==========================================================  CR  =========================================================== */
#define WWDG_CR_WDGA_Pos                  (7UL)                     /*!< WDGA (Bit 7)                                          */
#define WWDG_CR_WDGA_Msk                  (0x80UL)                  /*!< WDGA (Bitfield-Mask: 0x01)                            */
#define WWDG_CR_WDGA                      (0x80UL)                  /*!< WDGA (Bitfield-Mask: 0x01)                            */
#define WWDG_CR_T_Pos                     (0UL)                     /*!< T (Bit 0)                                             */
#define WWDG_CR_T_Msk                     (0x7fUL)                  /*!< T (Bitfield-Mask: 0x7f)                               */
#define WWDG_CR_T                         (0x7fUL)                  /*!< T (Bitfield-Mask: 0x7f)                               */
/* ==========================================================  CFR  ========================================================== */
#define WWDG_CFR_EWI_Pos                  (9UL)                     /*!< EWI (Bit 9)                                           */
#define WWDG_CFR_EWI_Msk                  (0x200UL)                 /*!< EWI (Bitfield-Mask: 0x01)                             */
#define WWDG_CFR_EWI                      (0x200UL)                 /*!< EWI (Bitfield-Mask: 0x01)                             */
#define WWDG_CFR_WDGTB_Pos                (7UL)                     /*!< WDGTB (Bit 7)                                         */
#define WWDG_CFR_WDGTB_Msk                (0x180UL)                 /*!< WDGTB (Bitfield-Mask: 0x03)                           */
#define WWDG_CFR_WDGTB                    (0x180UL)                 /*!< WDGTB (Bitfield-Mask: 0x03)                           */
#define WWDG_CFR_T_Pos                    (0UL)                     /*!< T (Bit 0)                                             */
#define WWDG_CFR_T_Msk                    (0x7fUL)                  /*!< T (Bitfield-Mask: 0x7f)                               */
#define WWDG_CFR_T                        (0x7fUL)                  /*!< T (Bitfield-Mask: 0x7f)                               */
/* ==========================================================  SR  =========================================================== */
#define WWDG_SR_EWIF_Pos                  (0UL)                     /*!< EWIF (Bit 0)                                          */
#define WWDG_SR_EWIF_Msk                  (0x1UL)                   /*!< EWIF (Bitfield-Mask: 0x01)                            */
#define WWDG_SR_EWIF                      (0x1UL)                   /*!< EWIF (Bitfield-Mask: 0x01)                            */


/* =========================================================================================================================== */
/* ================                                           IWDG                                            ================ */
/* =========================================================================================================================== */

/* ==========================================================  KR  =========================================================== */
#define IWDG_KR_KEY_Pos                   (0UL)                     /*!< KEY (Bit 0)                                           */
#define IWDG_KR_KEY_Msk                   (0xffffUL)                /*!< KEY (Bitfield-Mask: 0xffff)                           */
#define IWDG_KR_KEY                       (0xffffUL)                /*!< KEY (Bitfield-Mask: 0xffff)                           */
/* ==========================================================  PR  =========================================================== */
#define IWDG_PR_PR_Pos                    (0UL)                     /*!< PR (Bit 0)                                            */
#define IWDG_PR_PR_Msk                    (0x7UL)                   /*!< PR (Bitfield-Mask: 0x07)                              */
#define IWDG_PR_PR                        (0x7UL)                   /*!< PR (Bitfield-Mask: 0x07)                              */
/* ==========================================================  RLR  ========================================================== */
#define IWDG_RLR_RL_Pos                   (0UL)                     /*!< RL (Bit 0)                                            */
#define IWDG_RLR_RL_Msk                   (0xfffUL)                 /*!< RL (Bitfield-Mask: 0xfff)                             */
#define IWDG_RLR_RL                       (0xfffUL)                 /*!< RL (Bitfield-Mask: 0xfff)                             */
/* ==========================================================  SR  =========================================================== */
#define IWDG_SR_WVU_Pos                   (2UL)                     /*!< WVU (Bit 2)                                           */
#define IWDG_SR_WVU_Msk                   (0x4UL)                   /*!< WVU (Bitfield-Mask: 0x01)                             */
#define IWDG_SR_WVU                       (0x4UL)                   /*!< WVU (Bitfield-Mask: 0x01)                             */
#define IWDG_SR_RVU_Pos                   (1UL)                     /*!< RVU (Bit 1)                                           */
#define IWDG_SR_RVU_Msk                   (0x2UL)                   /*!< RVU (Bitfield-Mask: 0x01)                             */
#define IWDG_SR_RVU                       (0x2UL)                   /*!< RVU (Bitfield-Mask: 0x01)                             */
#define IWDG_SR_PVU_Pos                   (0UL)                     /*!< PVU (Bit 0)                                           */
#define IWDG_SR_PVU_Msk                   (0x1UL)                   /*!< PVU (Bitfield-Mask: 0x01)                             */
#define IWDG_SR_PVU                       (0x1UL)                   /*!< PVU (Bitfield-Mask: 0x01)                             */
/* =========================================================  WINR  ========================================================== */
#define IWDG_WINR_WIN_Pos                 (0UL)                     /*!< WIN (Bit 0)                                           */
#define IWDG_WINR_WIN_Msk                 (0xfffUL)                 /*!< WIN (Bitfield-Mask: 0xfff)                            */
#define IWDG_WINR_WIN                     (0xfffUL)                 /*!< WIN (Bitfield-Mask: 0xfff)                            */


/* =========================================================================================================================== */
/* ================                                            RTC                                            ================ */
/* =========================================================================================================================== */

/* =========================================================  ICSR  ========================================================== */
#define RTC_ICSR_RECALPF_Pos              (16UL)                    /*!< RECALPF (Bit 16)                                      */
#define RTC_ICSR_RECALPF_Msk              (0x10000UL)               /*!< RECALPF (Bitfield-Mask: 0x01)                         */
#define RTC_ICSR_RECALPF                  (0x10000UL)               /*!< RECALPF (Bitfield-Mask: 0x01)                         */
/* =========================================================  PRER  ========================================================== */
#define RTC_PRER_PREDIV_A_Pos             (16UL)                    /*!< PREDIV_A (Bit 16)                                     */
#define RTC_PRER_PREDIV_A_Msk             (0x7f0000UL)              /*!< PREDIV_A (Bitfield-Mask: 0x7f)                        */
#define RTC_PRER_PREDIV_A                 (0x7f0000UL)              /*!< PREDIV_A (Bitfield-Mask: 0x7f)                        */
#define RTC_PRER_PREDIV_S_Pos             (0UL)                     /*!< PREDIV_S (Bit 0)                                      */
#define RTC_PRER_PREDIV_S_Msk             (0x7fffUL)                /*!< PREDIV_S (Bitfield-Mask: 0x7fff)                      */
#define RTC_PRER_PREDIV_S                 (0x7fffUL)                /*!< PREDIV_S (Bitfield-Mask: 0x7fff)                      */
/* ==========================================================  CR  =========================================================== */
#define RTC_CR_COE_Pos                    (23UL)                    /*!< COE (Bit 23)                                          */
#define RTC_CR_COE_Msk                    (0x800000UL)              /*!< COE (Bitfield-Mask: 0x01)                             */
#define RTC_CR_COE                        (0x800000UL)              /*!< COE (Bitfield-Mask: 0x01)                             */
#define RTC_CR_COSEL_Pos                  (19UL)                    /*!< COSEL (Bit 19)                                        */
#define RTC_CR_COSEL_Msk                  (0x80000UL)               /*!< COSEL (Bitfield-Mask: 0x01)                           */
#define RTC_CR_COSEL                      (0x80000UL)               /*!< COSEL (Bitfield-Mask: 0x01)                           */
#define RTC_CR_SIE_Pos                    (14UL)                    /*!< SIE (Bit 14)                                          */
#define RTC_CR_SIE_Msk                    (0x4000UL)                /*!< SIE (Bitfield-Mask: 0x01)                             */
#define RTC_CR_SIE                        (0x4000UL)                /*!< SIE (Bitfield-Mask: 0x01)                             */
/* ==========================================================  WPR  ========================================================== */
#define RTC_WPR_KEY_Pos                   (0UL)                     /*!< KEY (Bit 0)                                           */
#define RTC_WPR_KEY_Msk                   (0xffUL)                  /*!< KEY (Bitfield-Mask: 0xff)                             */
#define RTC_WPR_KEY                       (0xffUL)                  /*!< KEY (Bitfield-Mask: 0xff)                             */
/* =========================================================  CALR  ========================================================== */
#define RTC_CALR_CALP_Pos                 (15UL)                    /*!< CALP (Bit 15)                                         */
#define RTC_CALR_CALP_Msk                 (0x8000UL)                /*!< CALP (Bitfield-Mask: 0x01)                            */
#define RTC_CALR_CALP                     (0x8000UL)                /*!< CALP (Bitfield-Mask: 0x01)                            */
#define RTC_CALR_CALW8_Pos                (14UL)                    /*!< CALW8 (Bit 14)                                        */
#define RTC_CALR_CALW8_Msk                (0x4000UL)                /*!< CALW8 (Bitfield-Mask: 0x01)                           */
#define RTC_CALR_CALW8                    (0x4000UL)                /*!< CALW8 (Bitfield-Mask: 0x01)                           */
#define RTC_CALR_CALW16_Pos               (13UL)                    /*!< CALW16 (Bit 13)                                       */
#define RTC_CALR_CALW16_Msk               (0x2000UL)                /*!< CALW16 (Bitfield-Mask: 0x01)                          */
#define RTC_CALR_CALW16                   (0x2000UL)                /*!< CALW16 (Bitfield-Mask: 0x01)                          */
#define RTC_CALR_CALM_Pos                 (0UL)                     /*!< CALM (Bit 0)                                          */
#define RTC_CALR_CALM_Msk                 (0x1ffUL)                 /*!< CALM (Bitfield-Mask: 0x1ff)                           */
#define RTC_CALR_CALM                     (0x1ffUL)                 /*!< CALM (Bitfield-Mask: 0x1ff)                           */
/* ==========================================================  SR  =========================================================== */
#define RTC_SR_SF_Pos                     (2UL)                     /*!< SF (Bit 2)                                            */
#define RTC_SR_SF_Msk                     (0x4UL)                   /*!< SF (Bitfield-Mask: 0x01)                              */
#define RTC_SR_SF                         (0x4UL)                   /*!< SF (Bitfield-Mask: 0x01)                              */
/* ==========================================================  SCR  ========================================================== */
#define RTC_SCR_SMF_Pos                   (2UL)                     /*!< SMF (Bit 2)                                           */
#define RTC_SCR_SMF_Msk                   (0x4UL)                   /*!< SMF (Bitfield-Mask: 0x01)                             */
#define RTC_SCR_SMF                       (0x4UL)                   /*!< SMF (Bitfield-Mask: 0x01)                             */


/* =========================================================================================================================== */
/* ================                                           LPTIM                                           ================ */
/* =========================================================================================================================== */

/* ==========================================================  CNT  ========================================================== */
#define LPTIM_CNT_CNT_Pos                 (0UL)                     /*!< CNT (Bit 0)                                           */
#define LPTIM_CNT_CNT_Msk                 (0xffffUL)                /*!< CNT (Bitfield-Mask: 0xffff)                           */
#define LPTIM_CNT_CNT                     (0xffffUL)                /*!< CNT (Bitfield-Mask: 0xffff)                           */
/* ==========================================================  ARR  ========================================================== */
#define LPTIM_ARR_ARR_Pos                 (0UL)                     /*!< ARR (Bit 0)                                           */
#define LPTIM_ARR_ARR_Msk                 (0xffffUL)                /*!< ARR (Bitfield-Mask: 0xffff)                           */
#define LPTIM_ARR_ARR                     (0xffffUL)                /*!< ARR (Bitfield-Mask: 0xffff)                           */
/* ==========================================================  CR  =========================================================== */
#define LPTIM_CR_IE_Pos                   (7UL)                     /*!< IE (Bit 7)                                            */
#define LPTIM_CR_IE_Msk                   (0x80UL)                  /*!< IE (Bitfield-Mask: 0x01)                              */
#define LPTIM_CR_IE                       (0x80UL)                  /*!< IE (Bitfield-Mask: 0x01)                              */
#define LPTIM_CR_WT_FLAG_Pos              (4UL)                     /*!< WT_FLAG (Bit 4)                                       */
#define LPTIM_CR_WT_FLAG_Msk              (0x10UL)                  /*!< WT_FLAG (Bitfield-Mask: 0x01)                         */
#define LPTIM_CR_WT_FLAG                  (0x10UL)                  /*!< WT_FLAG (Bitfield-Mask: 0x01)                         */
#define LPTIM_CR_TR_Pos                   (0UL)                     /*!< TR (Bit 0)                                            */
#define LPTIM_CR_TR_Msk                   (0x1UL)                   /*!< TR (Bitfield-Mask: 0x01)                              */
#define LPTIM_CR_TR                       (0x1UL)                   /*!< TR (Bitfield-Mask: 0x01)                              */
/* =========================================================  OVFR  ========================================================== */
#define LPTIM_OVFR_TF_Pos                 (0UL)                     /*!< TF (Bit 0)                                            */
#define LPTIM_OVFR_TF_Msk                 (0x1UL)                   /*!< TF (Bitfield-Mask: 0x01)                              */
#define LPTIM_OVFR_TF                     (0x1UL)                   /*!< TF (Bitfield-Mask: 0x01)                              */
/* =========================================================  OCLR  ========================================================== */
#define LPTIM_OCLR_TF_Pos                 (0UL)                     /*!< TF (Bit 0)                                            */
#define LPTIM_OCLR_TF_Msk                 (0x1UL)                   /*!< TF (Bitfield-Mask: 0x01)                              */
#define LPTIM_OCLR_TF                     (0x1UL)                   /*!< TF (Bitfield-Mask: 0x01)                              */


/* =========================================================================================================================== */
/* ================                                           TIM                                            ================ */
/* =========================================================================================================================== */

/* ==========================================================  CR1  ========================================================== */
#define TIM_CR1_CKD_Pos                  (8UL)                     /*!< CKD (Bit 8)                                           */
#define TIM_CR1_CKD_Msk                  (0x300UL)                 /*!< CKD (Bitfield-Mask: 0x03)                             */
#define TIM_CR1_CKD                      (0x300UL)                 /*!< CKD (Bitfield-Mask: 0x03)                             */
#define TIM_CR1_ARPE_Pos                 (7UL)                     /*!< ARPE (Bit 7)                                          */
#define TIM_CR1_ARPE_Msk                 (0x80UL)                  /*!< ARPE (Bitfield-Mask: 0x01)                            */
#define TIM_CR1_ARPE                     (0x80UL)                  /*!< ARPE (Bitfield-Mask: 0x01)                            */
#define TIM_CR1_CMS_Pos                  (5UL)                     /*!< CMS (Bit 5)                                           */
#define TIM_CR1_CMS_Msk                  (0x60UL)                  /*!< CMS (Bitfield-Mask: 0x03)                             */
#define TIM_CR1_CMS                      (0x60UL)                  /*!< CMS (Bitfield-Mask: 0x03)                             */
#define TIM_CR1_DIR_Pos                  (4UL)                     /*!< DIR (Bit 4)                                           */
#define TIM_CR1_DIR_Msk                  (0x10UL)                  /*!< DIR (Bitfield-Mask: 0x01)                             */
#define TIM_CR1_DIR                      (0x10UL)                  /*!< DIR (Bitfield-Mask: 0x01)                             */
#define TIM_CR1_OPM_Pos                  (3UL)                     /*!< OPM (Bit 3)                                           */
#define TIM_CR1_OPM_Msk                  (0x8UL)                   /*!< OPM (Bitfield-Mask: 0x01)                             */
#define TIM_CR1_OPM                      (0x8UL)                   /*!< OPM (Bitfield-Mask: 0x01)                             */
#define TIM_CR1_URS_Pos                  (2UL)                     /*!< URS (Bit 2)                                           */
#define TIM_CR1_URS_Msk                  (0x4UL)                   /*!< URS (Bitfield-Mask: 0x01)                             */
#define TIM_CR1_URS                      (0x4UL)                   /*!< URS (Bitfield-Mask: 0x01)                             */
#define TIM_CR1_UDIS_Pos                 (1UL)                     /*!< UDIS (Bit 1)                                          */
#define TIM_CR1_UDIS_Msk                 (0x2UL)                   /*!< UDIS (Bitfield-Mask: 0x01)                            */
#define TIM_CR1_UDIS                     (0x2UL)                   /*!< UDIS (Bitfield-Mask: 0x01)                            */
#define TIM_CR1_CEN_Pos                  (0UL)                     /*!< CEN (Bit 0)                                           */
#define TIM_CR1_CEN_Msk                  (0x1UL)                   /*!< CEN (Bitfield-Mask: 0x01)                             */
#define TIM_CR1_CEN                      (0x1UL)                   /*!< CEN (Bitfield-Mask: 0x01)                             */
/* ==========================================================  CR2  ========================================================== */
#define TIM_CR2_OIS4_Pos                 (14UL)                    /*!< OIS4 (Bit 14)                                         */
#define TIM_CR2_OIS4_Msk                 (0x4000UL)                /*!< OIS4 (Bitfield-Mask: 0x01)                            */
#define TIM_CR2_OIS4                     (0x4000UL)                /*!< OIS4 (Bitfield-Mask: 0x01)                            */
#define TIM_CR2_OIS3N_Pos                (13UL)                    /*!< OIS3N (Bit 13)                                        */
#define TIM_CR2_OIS3N_Msk                (0x2000UL)                /*!< OIS3N (Bitfield-Mask: 0x01)                           */
#define TIM_CR2_OIS3N                    (0x2000UL)                /*!< OIS3N (Bitfield-Mask: 0x01)                           */
#define TIM_CR2_OIS3_Pos                 (12UL)                    /*!< OIS3 (Bit 12)                                         */
#define TIM_CR2_OIS3_Msk                 (0x1000UL)                /*!< OIS3 (Bitfield-Mask: 0x01)                            */
#define TIM_CR2_OIS3                     (0x1000UL)                /*!< OIS3 (Bitfield-Mask: 0x01)                            */
#define TIM_CR2_OIS2N_Pos                (11UL)                    /*!< OIS2N (Bit 11)                                        */
#define TIM_CR2_OIS2N_Msk                (0x800UL)                 /*!< OIS2N (Bitfield-Mask: 0x01)                           */
#define TIM_CR2_OIS2N                    (0x800UL)                 /*!< OIS2N (Bitfield-Mask: 0x01)                           */
#define TIM_CR2_OIS2_Pos                 (10UL)                    /*!< OIS2 (Bit 10)                                         */
#define TIM_CR2_OIS2_Msk                 (0x400UL)                 /*!< OIS2 (Bitfield-Mask: 0x01)                            */
#define TIM_CR2_OIS2                     (0x400UL)                 /*!< OIS2 (Bitfield-Mask: 0x01)                            */
#define TIM_CR2_OIS1N_Pos                (9UL)                     /*!< OIS1N (Bit 9)                                         */
#define TIM_CR2_OIS1N_Msk                (0x200UL)                 /*!< OIS1N (Bitfield-Mask: 0x01)                           */
#define TIM_CR2_OIS1N                    (0x200UL)                 /*!< OIS1N (Bitfield-Mask: 0x01)                           */
#define TIM_CR2_OIS1_Pos                 (8UL)                     /*!< OIS1 (Bit 8)                                          */
#define TIM_CR2_OIS1_Msk                 (0x100UL)                 /*!< OIS1 (Bitfield-Mask: 0x01)                            */
#define TIM_CR2_OIS1                     (0x100UL)                 /*!< OIS1 (Bitfield-Mask: 0x01)                            */
#define TIM_CR2_TI1S_Pos                 (7UL)                     /*!< TI1S (Bit 7)                                          */
#define TIM_CR2_TI1S_Msk                 (0x80UL)                  /*!< TI1S (Bitfield-Mask: 0x01)                            */
#define TIM_CR2_TI1S                     (0x80UL)                  /*!< TI1S (Bitfield-Mask: 0x01)                            */
#define TIM_CR2_MMS_Pos                  (4UL)                     /*!< MMS (Bit 4)                                           */
#define TIM_CR2_MMS_Msk                  (0x70UL)                  /*!< MMS (Bitfield-Mask: 0x07)                             */
#define TIM_CR2_MMS                      (0x70UL)                  /*!< MMS (Bitfield-Mask: 0x07)                             */
#define TIM_CR2_CCDS_Pos                 (3UL)                     /*!< CCDS (Bit 3)                                          */
#define TIM_CR2_CCDS_Msk                 (0x8UL)                   /*!< CCDS (Bitfield-Mask: 0x01)                            */
#define TIM_CR2_CCDS                     (0x8UL)                   /*!< CCDS (Bitfield-Mask: 0x01)                            */
#define TIM_CR2_CCUS_Pos                 (2UL)                     /*!< CCUS (Bit 2)                                          */
#define TIM_CR2_CCUS_Msk                 (0x4UL)                   /*!< CCUS (Bitfield-Mask: 0x01)                            */
#define TIM_CR2_CCUS                     (0x4UL)                   /*!< CCUS (Bitfield-Mask: 0x01)                            */
#define TIM_CR2_CCPC_Pos                 (0UL)                     /*!< CCPC (Bit 0)                                          */
#define TIM_CR2_CCPC_Msk                 (0x1UL)                   /*!< CCPC (Bitfield-Mask: 0x01)                            */
#define TIM_CR2_CCPC                     (0x1UL)                   /*!< CCPC (Bitfield-Mask: 0x01)                            */
/* =========================================================  SMCR  ========================================================== */
#define TIM_SMCR_ETP_Pos                 (15UL)                    /*!< ETP (Bit 15)                                          */
#define TIM_SMCR_ETP_Msk                 (0x8000UL)                /*!< ETP (Bitfield-Mask: 0x01)                             */
#define TIM_SMCR_ETP                     (0x8000UL)                /*!< ETP (Bitfield-Mask: 0x01)                             */
#define TIM_SMCR_ECE_Pos                 (14UL)                    /*!< ECE (Bit 14)                                          */
#define TIM_SMCR_ECE_Msk                 (0x4000UL)                /*!< ECE (Bitfield-Mask: 0x01)                             */
#define TIM_SMCR_ECE                     (0x4000UL)                /*!< ECE (Bitfield-Mask: 0x01)                             */
#define TIM_SMCR_ETPS_Pos                (12UL)                    /*!< ETPS (Bit 12)                                         */
#define TIM_SMCR_ETPS_Msk                (0x3000UL)                /*!< ETPS (Bitfield-Mask: 0x03)                            */
#define TIM_SMCR_ETPS                    (0x3000UL)                /*!< ETPS (Bitfield-Mask: 0x03)                            */
#define TIM_SMCR_ETF_Pos                 (8UL)                     /*!< ETF (Bit 8)                                           */
#define TIM_SMCR_ETF_Msk                 (0xf00UL)                 /*!< ETF (Bitfield-Mask: 0x0f)                             */
#define TIM_SMCR_ETF                     (0xf00UL)                 /*!< ETF (Bitfield-Mask: 0x0f)                             */
#define TIM_SMCR_MSM_Pos                 (7UL)                     /*!< MSM (Bit 7)                                           */
#define TIM_SMCR_MSM_Msk                 (0x80UL)                  /*!< MSM (Bitfield-Mask: 0x01)                             */
#define TIM_SMCR_MSM                     (0x80UL)                  /*!< MSM (Bitfield-Mask: 0x01)                             */
#define TIM_SMCR_TS_Pos                  (4UL)                     /*!< TS (Bit 4)                                            */
#define TIM_SMCR_TS_Msk                  (0x70UL)                  /*!< TS (Bitfield-Mask: 0x07)                              */
#define TIM_SMCR_TS                      (0x70UL)                  /*!< TS (Bitfield-Mask: 0x07)                              */
#define TIM_SMCR_OCCS_Pos                (3UL)                     /*!< OCCS (Bit 3)                                          */
#define TIM_SMCR_OCCS_Msk                (0x8UL)                   /*!< OCCS (Bitfield-Mask: 0x01)                            */
#define TIM_SMCR_OCCS                    (0x8UL)                   /*!< OCCS (Bitfield-Mask: 0x01)                            */
#define TIM_SMCR_SMS_Pos                 (0UL)                     /*!< SMS (Bit 0)                                           */
#define TIM_SMCR_SMS_Msk                 (0x7UL)                   /*!< SMS (Bitfield-Mask: 0x07)                             */
#define TIM_SMCR_SMS                     (0x7UL)                   /*!< SMS (Bitfield-Mask: 0x07)                             */
/* =========================================================  DIER  ========================================================== */
#define TIM_DIER_TDE_Pos                 (14UL)                    /*!< TDE (Bit 14)                                          */
#define TIM_DIER_TDE_Msk                 (0x4000UL)                /*!< TDE (Bitfield-Mask: 0x01)                             */
#define TIM_DIER_TDE                     (0x4000UL)                /*!< TDE (Bitfield-Mask: 0x01)                             */
#define TIM_DIER_COMDE_Pos               (13UL)                    /*!< COMDE (Bit 13)                                        */
#define TIM_DIER_COMDE_Msk               (0x2000UL)                /*!< COMDE (Bitfield-Mask: 0x01)                           */
#define TIM_DIER_COMDE                   (0x2000UL)                /*!< COMDE (Bitfield-Mask: 0x01)                           */
#define TIM_DIER_CC4DE_Pos               (12UL)                    /*!< CC4DE (Bit 12)                                        */
#define TIM_DIER_CC4DE_Msk               (0x1000UL)                /*!< CC4DE (Bitfield-Mask: 0x01)                           */
#define TIM_DIER_CC4DE                   (0x1000UL)                /*!< CC4DE (Bitfield-Mask: 0x01)                           */
#define TIM_DIER_CC3DE_Pos               (11UL)                    /*!< CC3DE (Bit 11)                                        */
#define TIM_DIER_CC3DE_Msk               (0x800UL)                 /*!< CC3DE (Bitfield-Mask: 0x01)                           */
#define TIM_DIER_CC3DE                   (0x800UL)                 /*!< CC3DE (Bitfield-Mask: 0x01)                           */
#define TIM_DIER_CC2DE_Pos               (10UL)                    /*!< CC2DE (Bit 10)                                        */
#define TIM_DIER_CC2DE_Msk               (0x400UL)                 /*!< CC2DE (Bitfield-Mask: 0x01)                           */
#define TIM_DIER_CC2DE                   (0x400UL)                 /*!< CC2DE (Bitfield-Mask: 0x01)                           */
#define TIM_DIER_CC1DE_Pos               (9UL)                     /*!< CC1DE (Bit 9)                                         */
#define TIM_DIER_CC1DE_Msk               (0x200UL)                 /*!< CC1DE (Bitfield-Mask: 0x01)                           */
#define TIM_DIER_CC1DE                   (0x200UL)                 /*!< CC1DE (Bitfield-Mask: 0x01)                           */
#define TIM_DIER_UDE_Pos                 (8UL)                     /*!< UDE (Bit 8)                                           */
#define TIM_DIER_UDE_Msk                 (0x100UL)                 /*!< UDE (Bitfield-Mask: 0x01)                             */
#define TIM_DIER_UDE                     (0x100UL)                 /*!< UDE (Bitfield-Mask: 0x01)                             */
#define TIM_DIER_BIE_Pos                 (7UL)                     /*!< BIE (Bit 7)                                           */
#define TIM_DIER_BIE_Msk                 (0x80UL)                  /*!< BIE (Bitfield-Mask: 0x01)                             */
#define TIM_DIER_BIE                     (0x80UL)                  /*!< BIE (Bitfield-Mask: 0x01)                             */
#define TIM_DIER_TIE_Pos                 (6UL)                     /*!< TIE (Bit 6)                                           */
#define TIM_DIER_TIE_Msk                 (0x40UL)                  /*!< TIE (Bitfield-Mask: 0x01)                             */
#define TIM_DIER_TIE                     (0x40UL)                  /*!< TIE (Bitfield-Mask: 0x01)                             */
#define TIM_DIER_COMIE_Pos               (5UL)                     /*!< COMIE (Bit 5)                                         */
#define TIM_DIER_COMIE_Msk               (0x20UL)                  /*!< COMIE (Bitfield-Mask: 0x01)                           */
#define TIM_DIER_COMIE                   (0x20UL)                  /*!< COMIE (Bitfield-Mask: 0x01)                           */
#define TIM_DIER_CC4IE_Pos               (4UL)                     /*!< CC4IE (Bit 4)                                         */
#define TIM_DIER_CC4IE_Msk               (0x10UL)                  /*!< CC4IE (Bitfield-Mask: 0x01)                           */
#define TIM_DIER_CC4IE                   (0x10UL)                  /*!< CC4IE (Bitfield-Mask: 0x01)                           */
#define TIM_DIER_CC3IE_Pos               (3UL)                     /*!< CC3IE (Bit 3)                                         */
#define TIM_DIER_CC3IE_Msk               (0x8UL)                   /*!< CC3IE (Bitfield-Mask: 0x01)                           */
#define TIM_DIER_CC3IE                   (0x8UL)                   /*!< CC3IE (Bitfield-Mask: 0x01)                           */
#define TIM_DIER_CC2IE_Pos               (2UL)                     /*!< CC2IE (Bit 2)                                         */
#define TIM_DIER_CC2IE_Msk               (0x4UL)                   /*!< CC2IE (Bitfield-Mask: 0x01)                           */
#define TIM_DIER_CC2IE                   (0x4UL)                   /*!< CC2IE (Bitfield-Mask: 0x01)                           */
#define TIM_DIER_CC1IE_Pos               (1UL)                     /*!< CC1IE (Bit 1)                                         */
#define TIM_DIER_CC1IE_Msk               (0x2UL)                   /*!< CC1IE (Bitfield-Mask: 0x01)                           */
#define TIM_DIER_CC1IE                   (0x2UL)                   /*!< CC1IE (Bitfield-Mask: 0x01)                           */
#define TIM_DIER_UIE_Pos                 (0UL)                     /*!< UIE (Bit 0)                                           */
#define TIM_DIER_UIE_Msk                 (0x1UL)                   /*!< UIE (Bitfield-Mask: 0x01)                             */
#define TIM_DIER_UIE                     (0x1UL)                   /*!< UIE (Bitfield-Mask: 0x01)                             */
/* ==========================================================  SR  =========================================================== */
#define TIM_SR_CC4OF_Pos                 (12UL)                    /*!< CC4OF (Bit 12)                                        */
#define TIM_SR_CC4OF_Msk                 (0x1000UL)                /*!< CC4OF (Bitfield-Mask: 0x01)                           */
#define TIM_SR_CC4OF                     (0x1000UL)                /*!< CC4OF (Bitfield-Mask: 0x01)                           */
#define TIM_SR_CC3OF_Pos                 (11UL)                    /*!< CC3OF (Bit 11)                                        */
#define TIM_SR_CC3OF_Msk                 (0x800UL)                 /*!< CC3OF (Bitfield-Mask: 0x01)                           */
#define TIM_SR_CC3OF                     (0x800UL)                 /*!< CC3OF (Bitfield-Mask: 0x01)                           */
#define TIM_SR_CC2OF_Pos                 (10UL)                    /*!< CC2OF (Bit 10)                                        */
#define TIM_SR_CC2OF_Msk                 (0x400UL)                 /*!< CC2OF (Bitfield-Mask: 0x01)                           */
#define TIM_SR_CC2OF                     (0x400UL)                 /*!< CC2OF (Bitfield-Mask: 0x01)                           */
#define TIM_SR_CC1OF_Pos                 (9UL)                     /*!< CC1OF (Bit 9)                                         */
#define TIM_SR_CC1OF_Msk                 (0x200UL)                 /*!< CC1OF (Bitfield-Mask: 0x01)                           */
#define TIM_SR_CC1OF                     (0x200UL)                 /*!< CC1OF (Bitfield-Mask: 0x01)                           */
#define TIM_SR_BIF_Pos                   (7UL)                     /*!< BIF (Bit 7)                                           */
#define TIM_SR_BIF_Msk                   (0x80UL)                  /*!< BIF (Bitfield-Mask: 0x01)                             */
#define TIM_SR_BIF                       (0x80UL)                  /*!< BIF (Bitfield-Mask: 0x01)                             */
#define TIM_SR_TIF_Pos                   (6UL)                     /*!< TIF (Bit 6)                                           */
#define TIM_SR_TIF_Msk                   (0x40UL)                  /*!< TIF (Bitfield-Mask: 0x01)                             */
#define TIM_SR_TIF                       (0x40UL)                  /*!< TIF (Bitfield-Mask: 0x01)                             */
#define TIM_SR_COMIF_Pos                 (5UL)                     /*!< COMIF (Bit 5)                                         */
#define TIM_SR_COMIF_Msk                 (0x20UL)                  /*!< COMIF (Bitfield-Mask: 0x01)                           */
#define TIM_SR_COMIF                     (0x20UL)                  /*!< COMIF (Bitfield-Mask: 0x01)                           */
#define TIM_SR_CC4IF_Pos                 (4UL)                     /*!< CC4IF (Bit 4)                                         */
#define TIM_SR_CC4IF_Msk                 (0x10UL)                  /*!< CC4IF (Bitfield-Mask: 0x01)                           */
#define TIM_SR_CC4IF                     (0x10UL)                  /*!< CC4IF (Bitfield-Mask: 0x01)                           */
#define TIM_SR_CC3IF_Pos                 (3UL)                     /*!< CC3IF (Bit 3)                                         */
#define TIM_SR_CC3IF_Msk                 (0x8UL)                   /*!< CC3IF (Bitfield-Mask: 0x01)                           */
#define TIM_SR_CC3IF                     (0x8UL)                   /*!< CC3IF (Bitfield-Mask: 0x01)                           */
#define TIM_SR_CC2IF_Pos                 (2UL)                     /*!< CC2IF (Bit 2)                                         */
#define TIM_SR_CC2IF_Msk                 (0x4UL)                   /*!< CC2IF (Bitfield-Mask: 0x01)                           */
#define TIM_SR_CC2IF                     (0x4UL)                   /*!< CC2IF (Bitfield-Mask: 0x01)                           */
#define TIM_SR_CC1IF_Pos                 (1UL)                     /*!< CC1IF (Bit 1)                                         */
#define TIM_SR_CC1IF_Msk                 (0x2UL)                   /*!< CC1IF (Bitfield-Mask: 0x01)                           */
#define TIM_SR_CC1IF                     (0x2UL)                   /*!< CC1IF (Bitfield-Mask: 0x01)                           */
#define TIM_SR_UIF_Pos                   (0UL)                     /*!< UIF (Bit 0)                                           */
#define TIM_SR_UIF_Msk                   (0x1UL)                   /*!< UIF (Bitfield-Mask: 0x01)                             */
#define TIM_SR_UIF                       (0x1UL)                   /*!< UIF (Bitfield-Mask: 0x01)                             */
/* ==========================================================  EGR  ========================================================== */
#define TIM_EGR_BG_Pos                   (7UL)                     /*!< BG (Bit 7)                                            */
#define TIM_EGR_BG_Msk                   (0x80UL)                  /*!< BG (Bitfield-Mask: 0x01)                              */
#define TIM_EGR_BG                       (0x80UL)                  /*!< BG (Bitfield-Mask: 0x01)                              */
#define TIM_EGR_TG_Pos                   (6UL)                     /*!< TG (Bit 6)                                            */
#define TIM_EGR_TG_Msk                   (0x40UL)                  /*!< TG (Bitfield-Mask: 0x01)                              */
#define TIM_EGR_TG                       (0x40UL)                  /*!< TG (Bitfield-Mask: 0x01)                              */
#define TIM_EGR_COMG_Pos                 (5UL)                     /*!< COMG (Bit 5)                                          */
#define TIM_EGR_COMG_Msk                 (0x20UL)                  /*!< COMG (Bitfield-Mask: 0x01)                            */
#define TIM_EGR_COMG                     (0x20UL)                  /*!< COMG (Bitfield-Mask: 0x01)                            */
#define TIM_EGR_CC4G_Pos                 (4UL)                     /*!< CC4G (Bit 4)                                          */
#define TIM_EGR_CC4G_Msk                 (0x10UL)                  /*!< CC4G (Bitfield-Mask: 0x01)                            */
#define TIM_EGR_CC4G                     (0x10UL)                  /*!< CC4G (Bitfield-Mask: 0x01)                            */
#define TIM_EGR_CC3G_Pos                 (3UL)                     /*!< CC3G (Bit 3)                                          */
#define TIM_EGR_CC3G_Msk                 (0x8UL)                   /*!< CC3G (Bitfield-Mask: 0x01)                            */
#define TIM_EGR_CC3G                     (0x8UL)                   /*!< CC3G (Bitfield-Mask: 0x01)                            */
#define TIM_EGR_CC2G_Pos                 (2UL)                     /*!< CC2G (Bit 2)                                          */
#define TIM_EGR_CC2G_Msk                 (0x4UL)                   /*!< CC2G (Bitfield-Mask: 0x01)                            */
#define TIM_EGR_CC2G                     (0x4UL)                   /*!< CC2G (Bitfield-Mask: 0x01)                            */
#define TIM_EGR_CC1G_Pos                 (1UL)                     /*!< CC1G (Bit 1)                                          */
#define TIM_EGR_CC1G_Msk                 (0x2UL)                   /*!< CC1G (Bitfield-Mask: 0x01)                            */
#define TIM_EGR_CC1G                     (0x2UL)                   /*!< CC1G (Bitfield-Mask: 0x01)                            */
#define TIM_EGR_UG_Pos                   (0UL)                     /*!< UG (Bit 0)                                            */
#define TIM_EGR_UG_Msk                   (0x1UL)                   /*!< UG (Bitfield-Mask: 0x01)                              */
#define TIM_EGR_UG                       (0x1UL)                   /*!< UG (Bitfield-Mask: 0x01)                              */
/* =====================================================  CCMR1_Output  ====================================================== */
#define TIM_CCMR1_OC2CE_Pos       (15UL)                    /*!< OC2CE (Bit 15)                                        */
#define TIM_CCMR1_OC2CE_Msk       (0x8000UL)                /*!< OC2CE (Bitfield-Mask: 0x01)                           */
#define TIM_CCMR1_OC2CE           (0x8000UL)                /*!< OC2CE (Bitfield-Mask: 0x01)                           */
#define TIM_CCMR1_OC2M_Pos        (12UL)                    /*!< OC2M (Bit 12)                                         */
#define TIM_CCMR1_OC2M_Msk        (0x7000UL)                /*!< OC2M (Bitfield-Mask: 0x07)                            */
#define TIM_CCMR1_OC2M            (0x7000UL)                /*!< OC2M (Bitfield-Mask: 0x07)                            */
#define TIM_CCMR1_OC2PE_Pos       (11UL)                    /*!< OC2PE (Bit 11)                                        */
#define TIM_CCMR1_OC2PE_Msk       (0x800UL)                 /*!< OC2PE (Bitfield-Mask: 0x01)                           */
#define TIM_CCMR1_OC2PE           (0x800UL)                 /*!< OC2PE (Bitfield-Mask: 0x01)                           */
#define TIM_CCMR1_OC2FE_Pos       (10UL)                    /*!< OC2FE (Bit 10)                                        */
#define TIM_CCMR1_OC2FE_Msk       (0x400UL)                 /*!< OC2FE (Bitfield-Mask: 0x01)                           */
#define TIM_CCMR1_OC2FE           (0x400UL)                 /*!< OC2FE (Bitfield-Mask: 0x01)                           */
#define TIM_CCMR1_CC2S_Pos        (8UL)                     /*!< CC2S (Bit 8)                                          */
#define TIM_CCMR1_CC2S_Msk        (0x300UL)                 /*!< CC2S (Bitfield-Mask: 0x03)                            */
#define TIM_CCMR1_CC2S            (0x300UL)                 /*!< CC2S (Bitfield-Mask: 0x03)                            */
#define TIM_CCMR1_OC1CE_Pos       (7UL)                     /*!< OC1CE (Bit 7)                                         */
#define TIM_CCMR1_OC1CE_Msk       (0x80UL)                  /*!< OC1CE (Bitfield-Mask: 0x01)                           */
#define TIM_CCMR1_OC1CE           (0x80UL)                  /*!< OC1CE (Bitfield-Mask: 0x01)                           */
#define TIM_CCMR1_OC1M_Pos        (4UL)                     /*!< OC1M (Bit 4)                                          */
#define TIM_CCMR1_OC1M_Msk        (0x70UL)                  /*!< OC1M (Bitfield-Mask: 0x07)                            */
#define TIM_CCMR1_OC1M            (0x70UL)                  /*!< OC1M (Bitfield-Mask: 0x07)                            */
#define TIM_CCMR1_OC1PE_Pos       (3UL)                     /*!< OC1PE (Bit 3)                                         */
#define TIM_CCMR1_OC1PE_Msk       (0x8UL)                   /*!< OC1PE (Bitfield-Mask: 0x01)                           */
#define TIM_CCMR1_OC1PE           (0x8UL)                   /*!< OC1PE (Bitfield-Mask: 0x01)                           */
#define TIM_CCMR1_OC1FE_Pos       (2UL)                     /*!< OC1FE (Bit 2)                                         */
#define TIM_CCMR1_OC1FE_Msk       (0x4UL)                   /*!< OC1FE (Bitfield-Mask: 0x01)                           */
#define TIM_CCMR1_OC1FE           (0x4UL)                   /*!< OC1FE (Bitfield-Mask: 0x01)                           */
#define TIM_CCMR1_CC1S_Pos        (0UL)                     /*!< CC1S (Bit 0)                                          */
#define TIM_CCMR1_CC1S_Msk        (0x3UL)                   /*!< CC1S (Bitfield-Mask: 0x03)                            */
#define TIM_CCMR1_CC1S            (0x3UL)                   /*!< CC1S (Bitfield-Mask: 0x03)                            */
/* ======================================================  CCMR1_Input  ====================================================== */
#define TIM_CCMR1_IC2F_Pos         (12UL)                    /*!< IC2F (Bit 12)                                         */
#define TIM_CCMR1_IC2F_Msk         (0xf000UL)                /*!< IC2F (Bitfield-Mask: 0x0f)                            */
#define TIM_CCMR1_IC2F             (0xf000UL)                /*!< IC2F (Bitfield-Mask: 0x0f)                            */
#define TIM_CCMR1_IC2PSC_Pos       (10UL)                    /*!< IC2PSC (Bit 10)                                       */
#define TIM_CCMR1_IC2PSC_Msk       (0xc00UL)                 /*!< IC2PSC (Bitfield-Mask: 0x03)                          */
#define TIM_CCMR1_IC2PSC           (0xc00UL)                 /*!< IC2PSC (Bitfield-Mask: 0x03)                          */
#define TIM_CCMR1_CC2S_Pos         (8UL)                     /*!< CC2S (Bit 8)                                          */
#define TIM_CCMR1_CC2S_Msk         (0x300UL)                 /*!< CC2S (Bitfield-Mask: 0x03)                            */
#define TIM_CCMR1_CC2S             (0x300UL)                 /*!< CC2S (Bitfield-Mask: 0x03)                            */
#define TIM_CCMR1_IC1F_Pos         (4UL)                     /*!< IC1F (Bit 4)                                          */
#define TIM_CCMR1_IC1F_Msk         (0xf0UL)                  /*!< IC1F (Bitfield-Mask: 0x0f)                            */
#define TIM_CCMR1_IC1F             (0xf0UL)                  /*!< IC1F (Bitfield-Mask: 0x0f)                            */
#define TIM_CCMR1_IC1PSC_Pos       (2UL)                     /*!< IC1PSC (Bit 2)                                        */
#define TIM_CCMR1_IC1PSC_Msk       (0xcUL)                   /*!< IC1PSC (Bitfield-Mask: 0x03)                          */
#define TIM_CCMR1_IC1PSC           (0xcUL)                   /*!< IC1PSC (Bitfield-Mask: 0x03)                          */
#define TIM_CCMR1_CC1S_Pos         (0UL)                     /*!< CC1S (Bit 0)                                          */
#define TIM_CCMR1_CC1S_Msk         (0x3UL)                   /*!< CC1S (Bitfield-Mask: 0x03)                            */
#define TIM_CCMR1_CC1S             (0x3UL)                   /*!< CC1S (Bitfield-Mask: 0x03)                            */
/* =====================================================  CCMR2_Output  ====================================================== */
#define TIM_CCMR2_OC4CE_Pos       (15UL)                    /*!< OC4CE (Bit 15)                                        */
#define TIM_CCMR2_OC4CE_Msk       (0x8000UL)                /*!< OC4CE (Bitfield-Mask: 0x01)                           */
#define TIM_CCMR2_OC4CE           (0x8000UL)                /*!< OC4CE (Bitfield-Mask: 0x01)                           */
#define TIM_CCMR2_OC4M_Pos        (12UL)                    /*!< OC4M (Bit 12)                                         */
#define TIM_CCMR2_OC4M_Msk        (0x7000UL)                /*!< OC4M (Bitfield-Mask: 0x07)                            */
#define TIM_CCMR2_OC4M            (0x7000UL)                /*!< OC4M (Bitfield-Mask: 0x07)                            */
#define TIM_CCMR2_OC4PE_Pos       (11UL)                    /*!< OC4PE (Bit 11)                                        */
#define TIM_CCMR2_OC4PE_Msk       (0x800UL)                 /*!< OC4PE (Bitfield-Mask: 0x01)                           */
#define TIM_CCMR2_OC4PE           (0x800UL)                 /*!< OC4PE (Bitfield-Mask: 0x01)                           */
#define TIM_CCMR2_OC4FE_Pos       (10UL)                    /*!< OC4FE (Bit 10)                                        */
#define TIM_CCMR2_OC4FE_Msk       (0x400UL)                 /*!< OC4FE (Bitfield-Mask: 0x01)                           */
#define TIM_CCMR2_OC4FE           (0x400UL)                 /*!< OC4FE (Bitfield-Mask: 0x01)                           */
#define TIM_CCMR2_CC4S_Pos        (8UL)                     /*!< CC4S (Bit 8)                                          */
#define TIM_CCMR2_CC4S_Msk        (0x300UL)                 /*!< CC4S (Bitfield-Mask: 0x03)                            */
#define TIM_CCMR2_CC4S            (0x300UL)                 /*!< CC4S (Bitfield-Mask: 0x03)                            */
#define TIM_CCMR2_OC3CE_Pos       (7UL)                     /*!< OC3CE (Bit 7)                                         */
#define TIM_CCMR2_OC3CE_Msk       (0x80UL)                  /*!< OC3CE (Bitfield-Mask: 0x01)                           */
#define TIM_CCMR2_OC3CE           (0x80UL)                  /*!< OC3CE (Bitfield-Mask: 0x01)                           */
#define TIM_CCMR2_OC3M_Pos        (4UL)                     /*!< OC3M (Bit 4)                                          */
#define TIM_CCMR2_OC3M_Msk        (0x70UL)                  /*!< OC3M (Bitfield-Mask: 0x07)                            */
#define TIM_CCMR2_OC3M            (0x70UL)                  /*!< OC3M (Bitfield-Mask: 0x07)                            */
#define TIM_CCMR2_OC3PE_Pos       (3UL)                     /*!< OC3PE (Bit 3)                                         */
#define TIM_CCMR2_OC3PE_Msk       (0x8UL)                   /*!< OC3PE (Bitfield-Mask: 0x01)                           */
#define TIM_CCMR2_OC3PE           (0x8UL)                   /*!< OC3PE (Bitfield-Mask: 0x01)                           */
#define TIM_CCMR2_OC3FE_Pos       (2UL)                     /*!< OC3FE (Bit 2)                                         */
#define TIM_CCMR2_OC3FE_Msk       (0x4UL)                   /*!< OC3FE (Bitfield-Mask: 0x01)                           */
#define TIM_CCMR2_OC3FE           (0x4UL)                   /*!< OC3FE (Bitfield-Mask: 0x01)                           */
#define TIM_CCMR2_CC3S_Pos        (0UL)                     /*!< CC3S (Bit 0)                                          */
#define TIM_CCMR2_CC3S_Msk        (0x3UL)                   /*!< CC3S (Bitfield-Mask: 0x03)                            */
#define TIM_CCMR2_CC3S            (0x3UL)                   /*!< CC3S (Bitfield-Mask: 0x03)                            */
/* ======================================================  CCMR2_Input  ====================================================== */
#define TIM_CCMR2_IC4F_Pos         (12UL)                    /*!< IC4F (Bit 12)                                         */
#define TIM_CCMR2_IC4F_Msk         (0xf000UL)                /*!< IC4F (Bitfield-Mask: 0x0f)                            */
#define TIM_CCMR2_IC4F             (0xf000UL)                /*!< IC4F (Bitfield-Mask: 0x0f)                            */
#define TIM_CCMR2_IC4PSC_Pos       (10UL)                    /*!< IC4PSC (Bit 10)                                       */
#define TIM_CCMR2_IC4PSC_Msk       (0xc00UL)                 /*!< IC4PSC (Bitfield-Mask: 0x03)                          */
#define TIM_CCMR2_IC4PSC           (0xc00UL)                 /*!< IC4PSC (Bitfield-Mask: 0x03)                          */
#define TIM_CCMR2_CC4S_Pos         (8UL)                     /*!< CC4S (Bit 8)                                          */
#define TIM_CCMR2_CC4S_Msk         (0x300UL)                 /*!< CC4S (Bitfield-Mask: 0x03)                            */
#define TIM_CCMR2_CC4S             (0x300UL)                 /*!< CC4S (Bitfield-Mask: 0x03)                            */
#define TIM_CCMR2_IC3F_Pos         (4UL)                     /*!< IC3F (Bit 4)                                          */
#define TIM_CCMR2_IC3F_Msk         (0xf0UL)                  /*!< IC3F (Bitfield-Mask: 0x0f)                            */
#define TIM_CCMR2_IC3F             (0xf0UL)                  /*!< IC3F (Bitfield-Mask: 0x0f)                            */
#define TIM_CCMR2_IC3PSC_Pos       (2UL)                     /*!< IC3PSC (Bit 2)                                        */
#define TIM_CCMR2_IC3PSC_Msk       (0xcUL)                   /*!< IC3PSC (Bitfield-Mask: 0x03)                          */
#define TIM_CCMR2_IC3PSC           (0xcUL)                   /*!< IC3PSC (Bitfield-Mask: 0x03)                          */
#define TIM_CCMR2_CC3S_Pos         (0UL)                     /*!< CC3S (Bit 0)                                          */
#define TIM_CCMR2_CC3S_Msk         (0x3UL)                   /*!< CC3S (Bitfield-Mask: 0x03)                            */
#define TIM_CCMR2_CC3S             (0x3UL)                   /*!< CC3S (Bitfield-Mask: 0x03)                            */
/* =========================================================  CCER  ========================================================== */
#define TIM_CCER_CC4P_Pos                (13UL)                    /*!< CC4P (Bit 13)                                         */
#define TIM_CCER_CC4P_Msk                (0x2000UL)                /*!< CC4P (Bitfield-Mask: 0x01)                            */
#define TIM_CCER_CC4P                    (0x2000UL)                /*!< CC4P (Bitfield-Mask: 0x01)                            */
#define TIM_CCER_CC4E_Pos                (12UL)                    /*!< CC4E (Bit 12)                                         */
#define TIM_CCER_CC4E_Msk                (0x1000UL)                /*!< CC4E (Bitfield-Mask: 0x01)                            */
#define TIM_CCER_CC4E                    (0x1000UL)                /*!< CC4E (Bitfield-Mask: 0x01)                            */
#define TIM_CCER_CC3NP_Pos               (11UL)                    /*!< CC3NP (Bit 11)                                        */
#define TIM_CCER_CC3NP_Msk               (0x800UL)                 /*!< CC3NP (Bitfield-Mask: 0x01)                           */
#define TIM_CCER_CC3NP                   (0x800UL)                 /*!< CC3NP (Bitfield-Mask: 0x01)                           */
#define TIM_CCER_CC3NE_Pos               (10UL)                    /*!< CC3NE (Bit 10)                                        */
#define TIM_CCER_CC3NE_Msk               (0x400UL)                 /*!< CC3NE (Bitfield-Mask: 0x01)                           */
#define TIM_CCER_CC3NE                   (0x400UL)                 /*!< CC3NE (Bitfield-Mask: 0x01)                           */
#define TIM_CCER_CC3P_Pos                (9UL)                     /*!< CC3P (Bit 9)                                          */
#define TIM_CCER_CC3P_Msk                (0x200UL)                 /*!< CC3P (Bitfield-Mask: 0x01)                            */
#define TIM_CCER_CC3P                    (0x200UL)                 /*!< CC3P (Bitfield-Mask: 0x01)                            */
#define TIM_CCER_CC3E_Pos                (8UL)                     /*!< CC3E (Bit 8)                                          */
#define TIM_CCER_CC3E_Msk                (0x100UL)                 /*!< CC3E (Bitfield-Mask: 0x01)                            */
#define TIM_CCER_CC3E                    (0x100UL)                 /*!< CC3E (Bitfield-Mask: 0x01)                            */
#define TIM_CCER_CC2NP_Pos               (7UL)                     /*!< CC2NP (Bit 7)                                         */
#define TIM_CCER_CC2NP_Msk               (0x80UL)                  /*!< CC2NP (Bitfield-Mask: 0x01)                           */
#define TIM_CCER_CC2NP                   (0x80UL)                  /*!< CC2NP (Bitfield-Mask: 0x01)                           */
#define TIM_CCER_CC2NE_Pos               (6UL)                     /*!< CC2NE (Bit 6)                                         */
#define TIM_CCER_CC2NE_Msk               (0x40UL)                  /*!< CC2NE (Bitfield-Mask: 0x01)                           */
#define TIM_CCER_CC2NE                   (0x40UL)                  /*!< CC2NE (Bitfield-Mask: 0x01)                           */
#define TIM_CCER_CC2P_Pos                (5UL)                     /*!< CC2P (Bit 5)                                          */
#define TIM_CCER_CC2P_Msk                (0x20UL)                  /*!< CC2P (Bitfield-Mask: 0x01)                            */
#define TIM_CCER_CC2P                    (0x20UL)                  /*!< CC2P (Bitfield-Mask: 0x01)                            */
#define TIM_CCER_CC2E_Pos                (4UL)                     /*!< CC2E (Bit 4)                                          */
#define TIM_CCER_CC2E_Msk                (0x10UL)                  /*!< CC2E (Bitfield-Mask: 0x01)                            */
#define TIM_CCER_CC2E                    (0x10UL)                  /*!< CC2E (Bitfield-Mask: 0x01)                            */
#define TIM_CCER_CC1NP_Pos               (3UL)                     /*!< CC1NP (Bit 3)                                         */
#define TIM_CCER_CC1NP_Msk               (0x8UL)                   /*!< CC1NP (Bitfield-Mask: 0x01)                           */
#define TIM_CCER_CC1NP                   (0x8UL)                   /*!< CC1NP (Bitfield-Mask: 0x01)                           */
#define TIM_CCER_CC1NE_Pos               (2UL)                     /*!< CC1NE (Bit 2)                                         */
#define TIM_CCER_CC1NE_Msk               (0x4UL)                   /*!< CC1NE (Bitfield-Mask: 0x01)                           */
#define TIM_CCER_CC1NE                   (0x4UL)                   /*!< CC1NE (Bitfield-Mask: 0x01)                           */
#define TIM_CCER_CC1P_Pos                (1UL)                     /*!< CC1P (Bit 1)                                          */
#define TIM_CCER_CC1P_Msk                (0x2UL)                   /*!< CC1P (Bitfield-Mask: 0x01)                            */
#define TIM_CCER_CC1P                    (0x2UL)                   /*!< CC1P (Bitfield-Mask: 0x01)                            */
#define TIM_CCER_CC1E_Pos                (0UL)                     /*!< CC1E (Bit 0)                                          */
#define TIM_CCER_CC1E_Msk                (0x1UL)                   /*!< CC1E (Bitfield-Mask: 0x01)                            */
#define TIM_CCER_CC1E                    (0x1UL)                   /*!< CC1E (Bitfield-Mask: 0x01)                            */
/* ==========================================================  CNT  ========================================================== */
#define TIM_CNT_CNT_Pos                  (0UL)                     /*!< CNT (Bit 0)                                           */
#define TIM_CNT_CNT_Msk                  (0xffffUL)                /*!< CNT (Bitfield-Mask: 0xffff)                           */
#define TIM_CNT_CNT                      (0xffffUL)                /*!< CNT (Bitfield-Mask: 0xffff)                           */
/* ==========================================================  PSC  ========================================================== */
#define TIM_PSC_PSC_Pos                  (0UL)                     /*!< PSC (Bit 0)                                           */
#define TIM_PSC_PSC_Msk                  (0xffffUL)                /*!< PSC (Bitfield-Mask: 0xffff)                           */
#define TIM_PSC_PSC                      (0xffffUL)                /*!< PSC (Bitfield-Mask: 0xffff)                           */
/* ==========================================================  ARR  ========================================================== */
#define TIM_ARR_ARR_Pos                  (0UL)                     /*!< ARR (Bit 0)                                           */
#define TIM_ARR_ARR_Msk                  (0xffffUL)                /*!< ARR (Bitfield-Mask: 0xffff)                           */
#define TIM_ARR_ARR                      (0xffffUL)                /*!< ARR (Bitfield-Mask: 0xffff)                           */
/* ==========================================================  RCR  ========================================================== */
#define TIM_RCR_REP_Pos                  (0UL)                     /*!< REP (Bit 0)                                           */
#define TIM_RCR_REP_Msk                  (0xffUL)                  /*!< REP (Bitfield-Mask: 0xff)                             */
#define TIM_RCR_REP                      (0xffUL)                  /*!< REP (Bitfield-Mask: 0xff)                             */
/* =========================================================  CCR1  ========================================================== */
#define TIM_CCR1_CCR1_Pos                (0UL)                     /*!< CCR1 (Bit 0)                                          */
#define TIM_CCR1_CCR1_Msk                (0xffffUL)                /*!< CCR1 (Bitfield-Mask: 0xffff)                          */
#define TIM_CCR1_CCR1                    (0xffffUL)                /*!< CCR1 (Bitfield-Mask: 0xffff)                          */
/* =========================================================  CCR2  ========================================================== */
#define TIM_CCR2_CCR2_Pos                (0UL)                     /*!< CCR2 (Bit 0)                                          */
#define TIM_CCR2_CCR2_Msk                (0xffffUL)                /*!< CCR2 (Bitfield-Mask: 0xffff)                          */
#define TIM_CCR2_CCR2                    (0xffffUL)                /*!< CCR2 (Bitfield-Mask: 0xffff)                          */
/* =========================================================  CCR3  ========================================================== */
#define TIM_CCR3_CCR3_Pos                (0UL)                     /*!< CCR3 (Bit 0)                                          */
#define TIM_CCR3_CCR3_Msk                (0xffffUL)                /*!< CCR3 (Bitfield-Mask: 0xffff)                          */
#define TIM_CCR3_CCR3                    (0xffffUL)                /*!< CCR3 (Bitfield-Mask: 0xffff)                          */
/* =========================================================  CCR4  ========================================================== */
#define TIM_CCR4_CCR4_Pos                (0UL)                     /*!< CCR4 (Bit 0)                                          */
#define TIM_CCR4_CCR4_Msk                (0xffffUL)                /*!< CCR4 (Bitfield-Mask: 0xffff)                          */
#define TIM_CCR4_CCR4                    (0xffffUL)                /*!< CCR4 (Bitfield-Mask: 0xffff)                          */
/* =========================================================  BDTR  ========================================================== */
#define TIM_BDTR_MOE_Pos                 (15UL)                    /*!< MOE (Bit 15)                                          */
#define TIM_BDTR_MOE_Msk                 (0x8000UL)                /*!< MOE (Bitfield-Mask: 0x01)                             */
#define TIM_BDTR_MOE                     (0x8000UL)                /*!< MOE (Bitfield-Mask: 0x01)                             */
#define TIM_BDTR_AOE_Pos                 (14UL)                    /*!< AOE (Bit 14)                                          */
#define TIM_BDTR_AOE_Msk                 (0x4000UL)                /*!< AOE (Bitfield-Mask: 0x01)                             */
#define TIM_BDTR_AOE                     (0x4000UL)                /*!< AOE (Bitfield-Mask: 0x01)                             */
#define TIM_BDTR_BKP_Pos                 (13UL)                    /*!< BKP (Bit 13)                                          */
#define TIM_BDTR_BKP_Msk                 (0x2000UL)                /*!< BKP (Bitfield-Mask: 0x01)                             */
#define TIM_BDTR_BKP                     (0x2000UL)                /*!< BKP (Bitfield-Mask: 0x01)                             */
#define TIM_BDTR_BKE_Pos                 (12UL)                    /*!< BKE (Bit 12)                                          */
#define TIM_BDTR_BKE_Msk                 (0x1000UL)                /*!< BKE (Bitfield-Mask: 0x01)                             */
#define TIM_BDTR_BKE                     (0x1000UL)                /*!< BKE (Bitfield-Mask: 0x01)                             */
#define TIM_BDTR_OSSR_Pos                (11UL)                    /*!< OSSR (Bit 11)                                         */
#define TIM_BDTR_OSSR_Msk                (0x800UL)                 /*!< OSSR (Bitfield-Mask: 0x01)                            */
#define TIM_BDTR_OSSR                    (0x800UL)                 /*!< OSSR (Bitfield-Mask: 0x01)                            */
#define TIM_BDTR_OSSI_Pos                (10UL)                    /*!< OSSI (Bit 10)                                         */
#define TIM_BDTR_OSSI_Msk                (0x400UL)                 /*!< OSSI (Bitfield-Mask: 0x01)                            */
#define TIM_BDTR_OSSI                    (0x400UL)                 /*!< OSSI (Bitfield-Mask: 0x01)                            */
#define TIM_BDTR_LOCK_Pos                (8UL)                     /*!< LOCK (Bit 8)                                          */
#define TIM_BDTR_LOCK_Msk                (0x300UL)                 /*!< LOCK (Bitfield-Mask: 0x03)                            */
#define TIM_BDTR_LOCK                    (0x300UL)                 /*!< LOCK (Bitfield-Mask: 0x03)                            */
#define TIM_BDTR_DTG_Pos                 (0UL)                     /*!< DTG (Bit 0)                                           */
#define TIM_BDTR_DTG_Msk                 (0xffUL)                  /*!< DTG (Bitfield-Mask: 0xff)                             */
#define TIM_BDTR_DTG                     (0xffUL)                  /*!< DTG (Bitfield-Mask: 0xff)                             */
/* ==========================================================  DCR  ========================================================== */
#define TIM_DCR_DBL_Pos                  (8UL)                     /*!< DBL (Bit 8)                                           */
#define TIM_DCR_DBL_Msk                  (0x1f00UL)                /*!< DBL (Bitfield-Mask: 0x1f)                             */
#define TIM_DCR_DBL                      (0x1f00UL)                /*!< DBL (Bitfield-Mask: 0x1f)                             */
#define TIM_DCR_DBA_Pos                  (0UL)                     /*!< DBA (Bit 0)                                           */
#define TIM_DCR_DBA_Msk                  (0x1fUL)                  /*!< DBA (Bitfield-Mask: 0x1f)                             */
#define TIM_DCR_DBA                      (0x1fUL)                  /*!< DBA (Bitfield-Mask: 0x1f)                             */
/* =========================================================  DMAR  ========================================================== */
#define TIM_DMAR_DMAB_Pos                (0UL)                     /*!< DMAB (Bit 0)                                          */
#define TIM_DMAR_DMAB_Msk                (0xffffUL)                /*!< DMAB (Bitfield-Mask: 0xffff)                          */
#define TIM_DMAR_DMAB                    (0xffffUL)                /*!< DMAB (Bitfield-Mask: 0xffff)                          */
/* ==========================================================  OR  =========================================================== */
#define TIM_OR_IOCREF_CLR_Pos            (0UL)                     /*!< IOCREF_CLR (Bit 0)                                    */
#define TIM_OR_IOCREF_CLR_Msk            (0x3UL)                   /*!< IOCREF_CLR (Bitfield-Mask: 0x03)                      */
#define TIM_OR_IOCREF_CLR                (0x3UL)                   /*!< IOCREF_CLR (Bitfield-Mask: 0x03)                      */
/* =========================================================  TISEL  ========================================================= */
#define TIM_TISEL_TI4SEL_Pos             (24UL)                    /*!< TI4SEL (Bit 24)                                       */
#define TIM_TISEL_TI4SEL_Msk             (0xf000000UL)             /*!< TI4SEL (Bitfield-Mask: 0x0f)                          */
#define TIM_TISEL_TI4SEL                 (0xf000000UL)             /*!< TI4SEL (Bitfield-Mask: 0x0f)                          */
#define TIM_TISEL_TI3SEL_Pos             (16UL)                    /*!< TI3SEL (Bit 16)                                       */
#define TIM_TISEL_TI3SEL_Msk             (0xf0000UL)               /*!< TI3SEL (Bitfield-Mask: 0x0f)                          */
#define TIM_TISEL_TI3SEL                 (0xf0000UL)               /*!< TI3SEL (Bitfield-Mask: 0x0f)                          */
#define TIM_TISEL_TI2SEL_Pos             (8UL)                     /*!< TI2SEL (Bit 8)                                        */
#define TIM_TISEL_TI2SEL_Msk             (0xf00UL)                 /*!< TI2SEL (Bitfield-Mask: 0x0f)                          */
#define TIM_TISEL_TI2SEL                 (0xf00UL)                 /*!< TI2SEL (Bitfield-Mask: 0x0f)                          */
#define TIM_TISEL_TI1SEL_Pos             (0UL)                     /*!< TI1SEL (Bit 0)                                        */
#define TIM_TISEL_TI1SEL_Msk             (0xfUL)                   /*!< TI1SEL (Bitfield-Mask: 0x0f)                          */
#define TIM_TISEL_TI1SEL                 (0xfUL)                   /*!< TI1SEL (Bitfield-Mask: 0x0f)                          */


/* =========================================================================================================================== */
/* ================                                          DBGMCU                                           ================ */
/* =========================================================================================================================== */

/* ======================================================  DBG_IDCODE  ======================================================= */
#define DBGMCU_DBG_IDCODE_DEVICE_ID_Pos   (0UL)                     /*!< DEVICE_ID (Bit 0)                                     */
#define DBGMCU_DBG_IDCODE_DEVICE_ID_Msk   (0xffffffffUL)            /*!< DEVICE_ID (Bitfield-Mask: 0xffffffff)                 */
#define DBGMCU_DBG_IDCODE_DEVICE_ID       (0xffffffffUL)            /*!< DEVICE_ID (Bitfield-Mask: 0xffffffff)                 */
/* ==========================================================  CR  =========================================================== */
#define DBGMCU_CR_DBG_STOP_Pos            (1UL)                     /*!< DBG_STOP (Bit 1)                                      */
#define DBGMCU_CR_DBG_STOP_Msk            (0x2UL)                   /*!< DBG_STOP (Bitfield-Mask: 0x01)                        */
#define DBGMCU_CR_DBG_STOP                (0x2UL)                   /*!< DBG_STOP (Bitfield-Mask: 0x01)                        */
/* ======================================================  DBG_APB_FZ1  ====================================================== */
#define DBGMCU_DBG_APB_FZ1_DBG_LPTIM_STOP_Pos (31UL)                /*!< DBG_LPTIM_STOP (Bit 31)                               */
#define DBGMCU_DBG_APB_FZ1_DBG_LPTIM_STOP_Msk (0x80000000UL)        /*!< DBG_LPTIM_STOP (Bitfield-Mask: 0x01)                  */
#define DBGMCU_DBG_APB_FZ1_DBG_LPTIM_STOP     (0x80000000UL)        /*!< DBG_LPTIM_STOP (Bitfield-Mask: 0x01)                  */
#define DBGMCU_DBG_APB_FZ1_DBG_IWDG_STOP_Pos (12UL)                 /*!< DBG_IWDG_STOP (Bit 12)                                */
#define DBGMCU_DBG_APB_FZ1_DBG_IWDG_STOP_Msk (0x1000UL)             /*!< DBG_IWDG_STOP (Bitfield-Mask: 0x01)                   */
#define DBGMCU_DBG_APB_FZ1_DBG_IWDG_STOP     (0x1000UL)             /*!< DBG_IWDG_STOP (Bitfield-Mask: 0x01)                   */
#define DBGMCU_DBG_APB_FZ1_DBG_WWDG_STOP_Pos (11UL)                 /*!< DBG_WWDG_STOP (Bit 11)                                */
#define DBGMCU_DBG_APB_FZ1_DBG_WWDG_STOP_Msk (0x800UL)              /*!< DBG_WWDG_STOP (Bitfield-Mask: 0x01)                   */
#define DBGMCU_DBG_APB_FZ1_DBG_WWDG_STOP     (0x800UL)              /*!< DBG_WWDG_STOP (Bitfield-Mask: 0x01)                   */
#define DBGMCU_DBG_APB_FZ1_DBG_RTC_STOP_Pos (10UL)                  /*!< DBG_RTC_STOP (Bit 10)                                 */
#define DBGMCU_DBG_APB_FZ1_DBG_RTC_STOP_Msk (0x400UL)               /*!< DBG_RTC_STOP (Bitfield-Mask: 0x01)                    */
#define DBGMCU_DBG_APB_FZ1_DBG_RTC_STOP     (0x400UL)               /*!< DBG_RTC_STOP (Bitfield-Mask: 0x01)                    */
#define DBGMCU_DBG_APB_FZ1_DBG_TIM6_STOP_Pos (4UL)                  /*!< DBG_TIM6_STOP (Bit 4)                                 */
#define DBGMCU_DBG_APB_FZ1_DBG_TIM6_STOP_Msk (0x10UL)               /*!< DBG_TIM6_STOP (Bitfield-Mask: 0x01)                   */
#define DBGMCU_DBG_APB_FZ1_DBG_TIM6_STOP     (0x10UL)               /*!< DBG_TIM6_STOP (Bitfield-Mask: 0x01)                   */
#define DBGMCU_DBG_APB_FZ1_DBG_TIM3_STOP_Pos (1UL)                  /*!< DBG_TIM3_STOP (Bit 1)                                 */
#define DBGMCU_DBG_APB_FZ1_DBG_TIM3_STOP_Msk (0x2UL)                /*!< DBG_TIM3_STOP (Bitfield-Mask: 0x01)                   */
#define DBGMCU_DBG_APB_FZ1_DBG_TIM3_STOP     (0x2UL)                /*!< DBG_TIM3_STOP (Bitfield-Mask: 0x01)                   */
/* ======================================================  DBG_APB_FZ2  ====================================================== */
#define DBGMCU_DBG_APB_FZ2_DBG_TIM17_STOP_Pos (18UL)                /*!< DBG_TIM17_STOP (Bit 18)                               */
#define DBGMCU_DBG_APB_FZ2_DBG_TIM17_STOP_Msk (0x40000UL)           /*!< DBG_TIM17_STOP (Bitfield-Mask: 0x01)                  */
#define DBGMCU_DBG_APB_FZ2_DBG_TIM17_STOP     (0x40000UL)           /*!< DBG_TIM17_STOP (Bitfield-Mask: 0x01)                  */
#define DBGMCU_DBG_APB_FZ2_DBG_TIM16_STOP_Pos (17UL)                /*!< DBG_TIM16_STOP (Bit 17)                               */
#define DBGMCU_DBG_APB_FZ2_DBG_TIM16_STOP_Msk (0x20000UL)           /*!< DBG_TIM16_STOP (Bitfield-Mask: 0x01)                  */
#define DBGMCU_DBG_APB_FZ2_DBG_TIM16_STOP     (0x20000UL)           /*!< DBG_TIM16_STOP (Bitfield-Mask: 0x01)                  */
#define DBGMCU_DBG_APB_FZ2_DBG_TIM15_STOP_Pos (16UL)                /*!< DBG_TIM15_STOP (Bit 16)                               */
#define DBGMCU_DBG_APB_FZ2_DBG_TIM15_STOP_Msk (0x10000UL)           /*!< DBG_TIM15_STOP (Bitfield-Mask: 0x01)                  */
#define DBGMCU_DBG_APB_FZ2_DBG_TIM15_STOP     (0x10000UL)           /*!< DBG_TIM15_STOP (Bitfield-Mask: 0x01)                  */
#define DBGMCU_DBG_APB_FZ2_DBG_TIM14_STOP_Pos (15UL)                /*!< DBG_TIM14_STOP (Bit 15)                               */
#define DBGMCU_DBG_APB_FZ2_DBG_TIM14_STOP_Msk (0x8000UL)            /*!< DBG_TIM14_STOP (Bitfield-Mask: 0x01)                  */
#define DBGMCU_DBG_APB_FZ2_DBG_TIM14_STOP     (0x8000UL)            /*!< DBG_TIM14_STOP (Bitfield-Mask: 0x01)                  */
#define DBGMCU_DBG_APB_FZ2_DBG_TIM1_STOP_Pos (11UL)                 /*!< DBG_TIM1_STOP (Bit 11)                                */
#define DBGMCU_DBG_APB_FZ2_DBG_TIM1_STOP_Msk (0x800UL)              /*!< DBG_TIM1_STOP (Bitfield-Mask: 0x01)                   */
#define DBGMCU_DBG_APB_FZ2_DBG_TIM1_STOP     (0x800UL)              /*!< DBG_TIM1_STOP (Bitfield-Mask: 0x01)                   */


/* =========================================================================================================================== */
/* ================                                           SPI1                                            ================ */
/* =========================================================================================================================== */

/* ==========================================================  CR1  ========================================================== */
#define SPI_CR1_BIDIMODE_Pos             (15UL)                    /*!< BIDIMODE (Bit 15)                                     */
#define SPI_CR1_BIDIMODE_Msk             (0x8000UL)                /*!< BIDIMODE (Bitfield-Mask: 0x01)                        */
#define SPI_CR1_BIDIMODE                 (0x8000UL)                /*!< BIDIMODE (Bitfield-Mask: 0x01)                        */
#define SPI_CR1_BIDIOE_Pos               (14UL)                    /*!< BIDIOE (Bit 14)                                       */
#define SPI_CR1_BIDIOE_Msk               (0x4000UL)                /*!< BIDIOE (Bitfield-Mask: 0x01)                          */
#define SPI_CR1_BIDIOE                   (0x4000UL)                /*!< BIDIOE (Bitfield-Mask: 0x01)                          */
#define SPI_CR1_RXONLY_Pos               (10UL)                    /*!< RXONLY (Bit 10)                                       */
#define SPI_CR1_RXONLY_Msk               (0x400UL)                 /*!< RXONLY (Bitfield-Mask: 0x01)                          */
#define SPI_CR1_RXONLY                   (0x400UL)                 /*!< RXONLY (Bitfield-Mask: 0x01)                          */
#define SPI_CR1_SSM_Pos                  (9UL)                     /*!< SSM (Bit 9)                                           */
#define SPI_CR1_SSM_Msk                  (0x200UL)                 /*!< SSM (Bitfield-Mask: 0x01)                             */
#define SPI_CR1_SSM                      (0x200UL)                 /*!< SSM (Bitfield-Mask: 0x01)                             */
#define SPI_CR1_SSI_Pos                  (8UL)                     /*!< SSI (Bit 8)                                           */
#define SPI_CR1_SSI_Msk                  (0x100UL)                 /*!< SSI (Bitfield-Mask: 0x01)                             */
#define SPI_CR1_SSI                      (0x100UL)                 /*!< SSI (Bitfield-Mask: 0x01)                             */
#define SPI_CR1_LSBFIRST_Pos             (7UL)                     /*!< LSBFIRST (Bit 7)                                      */
#define SPI_CR1_LSBFIRST_Msk             (0x80UL)                  /*!< LSBFIRST (Bitfield-Mask: 0x01)                        */
#define SPI_CR1_LSBFIRST                 (0x80UL)                  /*!< LSBFIRST (Bitfield-Mask: 0x01)                        */
#define SPI_CR1_SPE_Pos                  (6UL)                     /*!< SPE (Bit 6)                                           */
#define SPI_CR1_SPE_Msk                  (0x40UL)                  /*!< SPE (Bitfield-Mask: 0x01)                             */
#define SPI_CR1_SPE                      (0x40UL)                  /*!< SPE (Bitfield-Mask: 0x01)                             */
#define SPI_CR1_BR_Pos                   (3UL)                     /*!< BR (Bit 3)                                            */
#define SPI_CR1_BR_Msk                   (0x38UL)                  /*!< BR (Bitfield-Mask: 0x07)                              */
#define SPI_CR1_BR                       (0x38UL)                  /*!< BR (Bitfield-Mask: 0x07)                              */
#define SPI_CR1_MSTR_Pos                 (2UL)                     /*!< MSTR (Bit 2)                                          */
#define SPI_CR1_MSTR_Msk                 (0x4UL)                   /*!< MSTR (Bitfield-Mask: 0x01)                            */
#define SPI_CR1_MSTR                     (0x4UL)                   /*!< MSTR (Bitfield-Mask: 0x01)                            */
#define SPI_CR1_CPOL_Pos                 (1UL)                     /*!< CPOL (Bit 1)                                          */
#define SPI_CR1_CPOL_Msk                 (0x2UL)                   /*!< CPOL (Bitfield-Mask: 0x01)                            */
#define SPI_CR1_CPOL                     (0x2UL)                   /*!< CPOL (Bitfield-Mask: 0x01)                            */
#define SPI_CR1_CPHA_Pos                 (0UL)                     /*!< CPHA (Bit 0)                                          */
#define SPI_CR1_CPHA_Msk                 (0x1UL)                   /*!< CPHA (Bitfield-Mask: 0x01)                            */
#define SPI_CR1_CPHA                     (0x1UL)                   /*!< CPHA (Bitfield-Mask: 0x01)                            */
/* ==========================================================  CR2  ========================================================== */
#define SPI_CR2_SLVFM_Pos                (15UL)                    /*!< SLVFM (Bit 15)                                        */
#define SPI_CR2_SLVFM_Msk                (0x8000UL)                /*!< SLVFM (Bitfield-Mask: 0x01)                           */
#define SPI_CR2_SLVFM                    (0x8000UL)                /*!< SLVFM (Bitfield-Mask: 0x01)                           */
#define SPI_CR2_LDMA_TX_Pos              (14UL)                    /*!< LDMA_TX (Bit 14)                                      */
#define SPI_CR2_LDMA_TX_Msk              (0x4000UL)                /*!< LDMA_TX (Bitfield-Mask: 0x01)                         */
#define SPI_CR2_LDMA_TX                  (0x4000UL)                /*!< LDMA_TX (Bitfield-Mask: 0x01)                         */
#define SPI_CR2_LDMA_RX_Pos              (13UL)                    /*!< LDMA_RX (Bit 13)                                      */
#define SPI_CR2_LDMA_RX_Msk              (0x2000UL)                /*!< LDMA_RX (Bitfield-Mask: 0x01)                         */
#define SPI_CR2_LDMA_RX                  (0x2000UL)                /*!< LDMA_RX (Bitfield-Mask: 0x01)                         */
#define SPI_CR2_FRXTH_Pos                (12UL)                    /*!< FRXTH (Bit 12)                                        */
#define SPI_CR2_FRXTH_Msk                (0x1000UL)                /*!< FRXTH (Bitfield-Mask: 0x01)                           */
#define SPI_CR2_FRXTH                    (0x1000UL)                /*!< FRXTH (Bitfield-Mask: 0x01)                           */
#define SPI_CR2_DS_Pos                   (11UL)                    /*!< DS (Bit 11)                                           */
#define SPI_CR2_DS_Msk                   (0x800UL)                 /*!< DS (Bitfield-Mask: 0x01)                              */
#define SPI_CR2_DS                       (0x800UL)                 /*!< DS (Bitfield-Mask: 0x01)                              */
#define SPI_CR2_TXEIE_Pos                (7UL)                     /*!< TXEIE (Bit 7)                                         */
#define SPI_CR2_TXEIE_Msk                (0x80UL)                  /*!< TXEIE (Bitfield-Mask: 0x01)                           */
#define SPI_CR2_TXEIE                    (0x80UL)                  /*!< TXEIE (Bitfield-Mask: 0x01)                           */
#define SPI_CR2_RXNEIE_Pos               (6UL)                     /*!< RXNEIE (Bit 6)                                        */
#define SPI_CR2_RXNEIE_Msk               (0x40UL)                  /*!< RXNEIE (Bitfield-Mask: 0x01)                          */
#define SPI_CR2_RXNEIE                   (0x40UL)                  /*!< RXNEIE (Bitfield-Mask: 0x01)                          */
#define SPI_CR2_ERRIE_Pos                (5UL)                     /*!< ERRIE (Bit 5)                                         */
#define SPI_CR2_ERRIE_Msk                (0x20UL)                  /*!< ERRIE (Bitfield-Mask: 0x01)                           */
#define SPI_CR2_ERRIE                    (0x20UL)                  /*!< ERRIE (Bitfield-Mask: 0x01)                           */
#define SPI_CR2_SSOE_Pos                 (2UL)                     /*!< SSOE (Bit 2)                                          */
#define SPI_CR2_SSOE_Msk                 (0x4UL)                   /*!< SSOE (Bitfield-Mask: 0x01)                            */
#define SPI_CR2_SSOE                     (0x4UL)                   /*!< SSOE (Bitfield-Mask: 0x01)                            */
#define SPI_CR2_TXDMAEN_Pos              (1UL)                     /*!< TXDMAEN (Bit 1)                                       */
#define SPI_CR2_TXDMAEN_Msk              (0x2UL)                   /*!< TXDMAEN (Bitfield-Mask: 0x01)                         */
#define SPI_CR2_TXDMAEN                  (0x2UL)                   /*!< TXDMAEN (Bitfield-Mask: 0x01)                         */
#define SPI_CR2_RXDMAEN_Pos              (0UL)                     /*!< RXDMAEN (Bit 0)                                       */
#define SPI_CR2_RXDMAEN_Msk              (0x1UL)                   /*!< RXDMAEN (Bitfield-Mask: 0x01)                         */
#define SPI_CR2_RXDMAEN                  (0x1UL)                   /*!< RXDMAEN (Bitfield-Mask: 0x01)                         */
/* ==========================================================  SR  =========================================================== */
#define SPI_SR_FTLVL_Pos                 (11UL)                    /*!< FTLVL (Bit 11)                                        */
#define SPI_SR_FTLVL_Msk                 (0x1800UL)                /*!< FTLVL (Bitfield-Mask: 0x03)                           */
#define SPI_SR_FTLVL                     (0x1800UL)                /*!< FTLVL (Bitfield-Mask: 0x03)                           */
#define SPI_SR_FRLVL_Pos                 (9UL)                     /*!< FRLVL (Bit 9)                                         */
#define SPI_SR_FRLVL_Msk                 (0x600UL)                 /*!< FRLVL (Bitfield-Mask: 0x03)                           */
#define SPI_SR_FRLVL                     (0x600UL)                 /*!< FRLVL (Bitfield-Mask: 0x03)                           */
#define SPI_SR_BSY_Pos                   (7UL)                     /*!< BSY (Bit 7)                                           */
#define SPI_SR_BSY_Msk                   (0x80UL)                  /*!< BSY (Bitfield-Mask: 0x01)                             */
#define SPI_SR_BSY                       (0x80UL)                  /*!< BSY (Bitfield-Mask: 0x01)                             */
#define SPI_SR_OVR_Pos                   (6UL)                     /*!< OVR (Bit 6)                                           */
#define SPI_SR_OVR_Msk                   (0x40UL)                  /*!< OVR (Bitfield-Mask: 0x01)                             */
#define SPI_SR_OVR                       (0x40UL)                  /*!< OVR (Bitfield-Mask: 0x01)                             */
#define SPI_SR_MODF_Pos                  (5UL)                     /*!< MODF (Bit 5)                                          */
#define SPI_SR_MODF_Msk                  (0x20UL)                  /*!< MODF (Bitfield-Mask: 0x01)                            */
#define SPI_SR_MODF                      (0x20UL)                  /*!< MODF (Bitfield-Mask: 0x01)                            */
#define SPI_SR_TXE_Pos                   (1UL)                     /*!< TXE (Bit 1)                                           */
#define SPI_SR_TXE_Msk                   (0x2UL)                   /*!< TXE (Bitfield-Mask: 0x01)                             */
#define SPI_SR_TXE                       (0x2UL)                   /*!< TXE (Bitfield-Mask: 0x01)                             */
#define SPI_SR_RXNE_Pos                  (0UL)                     /*!< RXNE (Bit 0)                                          */
#define SPI_SR_RXNE_Msk                  (0x1UL)                   /*!< RXNE (Bitfield-Mask: 0x01)                            */
#define SPI_SR_RXNE                      (0x1UL)                   /*!< RXNE (Bitfield-Mask: 0x01)                            */
/* ==========================================================  DR  =========================================================== */
#define SPI_DR_DR_Pos                    (0UL)                     /*!< DR (Bit 0)                                            */
#define SPI_DR_DR_Msk                    (0xffffUL)                /*!< DR (Bitfield-Mask: 0xffff)                            */
#define SPI_DR_DR                        (0xffffUL)                /*!< DR (Bitfield-Mask: 0xffff)                            */


/* =========================================================================================================================== */
/* ================                                            TSC                                            ================ */
/* =========================================================================================================================== */

/* =========================================================  TKCR1  ========================================================= */
#define TSC_TKCR1_TKCLKSEL_Pos            (31UL)                    /*!< TKCLKSEL (Bit 31)                                     */
#define TSC_TKCR1_TKCLKSEL_Msk            (0x80000000UL)            /*!< TKCLKSEL (Bitfield-Mask: 0x01)                        */
#define TSC_TKCR1_TKCLKSEL                (0x80000000UL)            /*!< TKCLKSEL (Bitfield-Mask: 0x01)                        */
#define TSC_TKCR1_ACTH_Pos                (13UL)                    /*!< ACTH (Bit 13)                                         */
#define TSC_TKCR1_ACTH_Msk                (0x2000UL)                /*!< ACTH (Bitfield-Mask: 0x01)                            */
#define TSC_TKCR1_ACTH                    (0x2000UL)                /*!< ACTH (Bitfield-Mask: 0x01)                            */
#define TSC_TKCR1_ASMTO_Pos               (10UL)                    /*!< ASMTO (Bit 10)                                        */
#define TSC_TKCR1_ASMTO_Msk               (0x1c00UL)                /*!< ASMTO (Bitfield-Mask: 0x07)                           */
#define TSC_TKCR1_ASMTO                   (0x1c00UL)                /*!< ASMTO (Bitfield-Mask: 0x07)                           */
#define TSC_TKCR1_ASMP_Pos                (8UL)                     /*!< ASMP (Bit 8)                                          */
#define TSC_TKCR1_ASMP_Msk                (0x300UL)                 /*!< ASMP (Bitfield-Mask: 0x03)                            */
#define TSC_TKCR1_ASMP                    (0x300UL)                 /*!< ASMP (Bitfield-Mask: 0x03)                            */
#define TSC_TKCR1_TK16S_Pos               (5UL)                     /*!< TK16S (Bit 5)                                         */
#define TSC_TKCR1_TK16S_Msk               (0x60UL)                  /*!< TK16S (Bitfield-Mask: 0x03)                           */
#define TSC_TKCR1_TK16S                   (0x60UL)                  /*!< TK16S (Bitfield-Mask: 0x03)                           */
#define TSC_TKCR1_TKFS_Pos                (3UL)                     /*!< TKFS (Bit 3)                                          */
#define TSC_TKCR1_TKFS_Msk                (0x18UL)                  /*!< TKFS (Bitfield-Mask: 0x03)                            */
#define TSC_TKCR1_TKFS                    (0x18UL)                  /*!< TKFS (Bitfield-Mask: 0x03)                            */
#define TSC_TKCR1_TKMOD_Pos               (1UL)                     /*!< TKMOD (Bit 1)                                         */
#define TSC_TKCR1_TKMOD_Msk               (0x6UL)                   /*!< TKMOD (Bitfield-Mask: 0x03)                           */
#define TSC_TKCR1_TKMOD                   (0x6UL)                   /*!< TKMOD (Bitfield-Mask: 0x03)                           */
#define TSC_TKCR1_TKST_Pos                (0UL)                     /*!< TKST (Bit 0)                                          */
#define TSC_TKCR1_TKST_Msk                (0x1UL)                   /*!< TKST (Bitfield-Mask: 0x01)                            */
#define TSC_TKCR1_TKST                    (0x1UL)                   /*!< TKST (Bitfield-Mask: 0x01)                            */
/* =========================================================  TKCR2  ========================================================= */
#define TSC_TKCR2_FEN_Pos                 (11UL)                    /*!< FEN (Bit 11)                                          */
#define TSC_TKCR2_FEN_Msk                 (0x800UL)                 /*!< FEN (Bitfield-Mask: 0x01)                             */
#define TSC_TKCR2_FEN                     (0x800UL)                 /*!< FEN (Bitfield-Mask: 0x01)                             */
#define TSC_TKCR2_TSS_Pos                 (8UL)                     /*!< TSS (Bit 8)                                           */
#define TSC_TKCR2_TSS_Msk                 (0x300UL)                 /*!< TSS (Bitfield-Mask: 0x03)                             */
#define TSC_TKCR2_TSS                     (0x300UL)                 /*!< TSS (Bitfield-Mask: 0x03)                             */
#define TSC_TKCR2_ROEN_Pos                (7UL)                     /*!< ROEN (Bit 7)                                          */
#define TSC_TKCR2_ROEN_Msk                (0x80UL)                  /*!< ROEN (Bitfield-Mask: 0x01)                            */
#define TSC_TKCR2_ROEN                    (0x80UL)                  /*!< ROEN (Bitfield-Mask: 0x01)                            */
#define TSC_TKCR2_KOEN_Pos                (6UL)                     /*!< KOEN (Bit 6)                                          */
#define TSC_TKCR2_KOEN_Msk                (0x40UL)                  /*!< KOEN (Bitfield-Mask: 0x01)                            */
#define TSC_TKCR2_KOEN                    (0x40UL)                  /*!< KOEN (Bitfield-Mask: 0x01)                            */
#define TSC_TKCR2_SOFC_Pos                (3UL)                     /*!< SOFC (Bit 3)                                          */
#define TSC_TKCR2_SOFC_Msk                (0x8UL)                   /*!< SOFC (Bitfield-Mask: 0x01)                            */
#define TSC_TKCR2_SOFC                    (0x8UL)                   /*!< SOFC (Bitfield-Mask: 0x01)                            */
#define TSC_TKCR2_SOF_Pos                 (0UL)                     /*!< SOF (Bit 0)                                           */
#define TSC_TKCR2_SOF_Msk                 (0x7UL)                   /*!< SOF (Bitfield-Mask: 0x07)                             */
#define TSC_TKCR2_SOF                     (0x7UL)                   /*!< SOF (Bitfield-Mask: 0x07)                             */
/* ========================================================  TKCNTR  ========================================================= */
#define TSC_TKCNTR_TK16D_Pos              (0UL)                     /*!< TK16D (Bit 0)                                         */
#define TSC_TKCNTR_TK16D_Msk              (0xffffUL)                /*!< TK16D (Bitfield-Mask: 0xffff)                         */
#define TSC_TKCNTR_TK16D                  (0xffffUL)                /*!< TK16D (Bitfield-Mask: 0xffff)                         */
/* ========================================================  TKTSCRR  ======================================================== */
#define TSC_TKTSCRR_TKTMR_Pos             (0UL)                     /*!< TKTMR (Bit 0)                                         */
#define TSC_TKTSCRR_TKTMR_Msk             (0xffUL)                  /*!< TKTMR (Bitfield-Mask: 0xff)                           */
#define TSC_TKTSCRR_TKTMR                 (0xffUL)                  /*!< TKTMR (Bitfield-Mask: 0xff)                           */
/* =========================================================  TKIER  ========================================================= */
#define TSC_TKIER_TKRCOVWUEN_Pos          (3UL)                     /*!< TKRCOVWUEN (Bit 3)                                    */
#define TSC_TKIER_TKRCOVWUEN_Msk          (0x8UL)                   /*!< TKRCOVWUEN (Bitfield-Mask: 0x01)                      */
#define TSC_TKIER_TKRCOVWUEN              (0x8UL)                   /*!< TKRCOVWUEN (Bitfield-Mask: 0x01)                      */
#define TSC_TKIER_TKTHWUEN_Pos            (2UL)                     /*!< TKTHWUEN (Bit 2)                                      */
#define TSC_TKIER_TKTHWUEN_Msk            (0x4UL)                   /*!< TKTHWUEN (Bitfield-Mask: 0x01)                        */
#define TSC_TKIER_TKTHWUEN                (0x4UL)                   /*!< TKTHWUEN (Bitfield-Mask: 0x01)                        */
#define TSC_TKIER_TKRCOVE_Pos             (1UL)                     /*!< TKRCOVE (Bit 1)                                       */
#define TSC_TKIER_TKRCOVE_Msk             (0x2UL)                   /*!< TKRCOVE (Bitfield-Mask: 0x01)                         */
#define TSC_TKIER_TKRCOVE                 (0x2UL)                   /*!< TKRCOVE (Bitfield-Mask: 0x01)                         */
#define TSC_TKIER_TKTHE_Pos               (0UL)                     /*!< TKTHE (Bit 0)                                         */
#define TSC_TKIER_TKTHE_Msk               (0x1UL)                   /*!< TKTHE (Bitfield-Mask: 0x01)                           */
#define TSC_TKIER_TKTHE                   (0x1UL)                   /*!< TKTHE (Bitfield-Mask: 0x01)                           */
/* =========================================================  TKSR1  ========================================================= */
#define TSC_TKSR1_HCKRDY_Pos              (5UL)                     /*!< HCKRDY (Bit 5)                                        */
#define TSC_TKSR1_HCKRDY_Msk              (0x20UL)                  /*!< HCKRDY (Bitfield-Mask: 0x01)                          */
#define TSC_TKSR1_HCKRDY                  (0x20UL)                  /*!< HCKRDY (Bitfield-Mask: 0x01)                          */
#define TSC_TKSR1_TKBUSY_Pos              (4UL)                     /*!< TKBUSY (Bit 4)                                        */
#define TSC_TKSR1_TKBUSY_Msk              (0x10UL)                  /*!< TKBUSY (Bitfield-Mask: 0x01)                          */
#define TSC_TKSR1_TKBUSY                  (0x10UL)                  /*!< TKBUSY (Bitfield-Mask: 0x01)                          */
#define TSC_TKSR1_TKCFOV_Pos              (3UL)                     /*!< TKCFOV (Bit 3)                                        */
#define TSC_TKSR1_TKCFOV_Msk              (0x8UL)                   /*!< TKCFOV (Bitfield-Mask: 0x01)                          */
#define TSC_TKSR1_TKCFOV                  (0x8UL)                   /*!< TKCFOV (Bitfield-Mask: 0x01)                          */
#define TSC_TKSR1_TK16OV_Pos              (2UL)                     /*!< TK16OV (Bit 2)                                        */
#define TSC_TKSR1_TK16OV_Msk              (0x4UL)                   /*!< TK16OV (Bitfield-Mask: 0x01)                          */
#define TSC_TKSR1_TK16OV                  (0x4UL)                   /*!< TK16OV (Bitfield-Mask: 0x01)                          */
#define TSC_TKSR1_TKRCOV_Pos              (1UL)                     /*!< TKRCOV (Bit 1)                                        */
#define TSC_TKSR1_TKRCOV_Msk              (0x2UL)                   /*!< TKRCOV (Bitfield-Mask: 0x01)                          */
#define TSC_TKSR1_TKRCOV                  (0x2UL)                   /*!< TKRCOV (Bitfield-Mask: 0x01)                          */
#define TSC_TKSR1_TKTHF_Pos               (0UL)                     /*!< TKTHF (Bit 0)                                         */
#define TSC_TKSR1_TKTHF_Msk               (0x1UL)                   /*!< TKTHF (Bitfield-Mask: 0x01)                           */
#define TSC_TKSR1_TKTHF                   (0x1UL)                   /*!< TKTHF (Bitfield-Mask: 0x01)                           */
/* =========================================================  TKSR2  ========================================================= */
#define TSC_TKSR2_K23THF_Pos              (23UL)                    /*!< K23THF (Bit 23)                                       */
#define TSC_TKSR2_K23THF_Msk              (0x800000UL)              /*!< K23THF (Bitfield-Mask: 0x01)                          */
#define TSC_TKSR2_K23THF                  (0x800000UL)              /*!< K23THF (Bitfield-Mask: 0x01)                          */
#define TSC_TKSR2_K22THF_Pos              (22UL)                    /*!< K22THF (Bit 22)                                       */
#define TSC_TKSR2_K22THF_Msk              (0x400000UL)              /*!< K22THF (Bitfield-Mask: 0x01)                          */
#define TSC_TKSR2_K22THF                  (0x400000UL)              /*!< K22THF (Bitfield-Mask: 0x01)                          */
#define TSC_TKSR2_K21THF_Pos              (21UL)                    /*!< K21THF (Bit 21)                                       */
#define TSC_TKSR2_K21THF_Msk              (0x200000UL)              /*!< K21THF (Bitfield-Mask: 0x01)                          */
#define TSC_TKSR2_K21THF                  (0x200000UL)              /*!< K21THF (Bitfield-Mask: 0x01)                          */
#define TSC_TKSR2_K20THF_Pos              (20UL)                    /*!< K20THF (Bit 20)                                       */
#define TSC_TKSR2_K20THF_Msk              (0x100000UL)              /*!< K20THF (Bitfield-Mask: 0x01)                          */
#define TSC_TKSR2_K20THF                  (0x100000UL)              /*!< K20THF (Bitfield-Mask: 0x01)                          */
#define TSC_TKSR2_K19THF_Pos              (19UL)                    /*!< K19THF (Bit 19)                                       */
#define TSC_TKSR2_K19THF_Msk              (0x80000UL)               /*!< K19THF (Bitfield-Mask: 0x01)                          */
#define TSC_TKSR2_K19THF                  (0x80000UL)               /*!< K19THF (Bitfield-Mask: 0x01)                          */
#define TSC_TKSR2_K18THF_Pos              (18UL)                    /*!< K18THF (Bit 18)                                       */
#define TSC_TKSR2_K18THF_Msk              (0x40000UL)               /*!< K18THF (Bitfield-Mask: 0x01)                          */
#define TSC_TKSR2_K18THF                  (0x40000UL)               /*!< K18THF (Bitfield-Mask: 0x01)                          */
#define TSC_TKSR2_K17THF_Pos              (17UL)                    /*!< K17THF (Bit 17)                                       */
#define TSC_TKSR2_K17THF_Msk              (0x20000UL)               /*!< K17THF (Bitfield-Mask: 0x01)                          */
#define TSC_TKSR2_K17THF                  (0x20000UL)               /*!< K17THF (Bitfield-Mask: 0x01)                          */
#define TSC_TKSR2_K16THF_Pos              (16UL)                    /*!< K16THF (Bit 16)                                       */
#define TSC_TKSR2_K16THF_Msk              (0x10000UL)               /*!< K16THF (Bitfield-Mask: 0x01)                          */
#define TSC_TKSR2_K16THF                  (0x10000UL)               /*!< K16THF (Bitfield-Mask: 0x01)                          */
#define TSC_TKSR2_K15THF_Pos              (15UL)                    /*!< K15THF (Bit 15)                                       */
#define TSC_TKSR2_K15THF_Msk              (0x8000UL)                /*!< K15THF (Bitfield-Mask: 0x01)                          */
#define TSC_TKSR2_K15THF                  (0x8000UL)                /*!< K15THF (Bitfield-Mask: 0x01)                          */
#define TSC_TKSR2_K14THF_Pos              (14UL)                    /*!< K14THF (Bit 14)                                       */
#define TSC_TKSR2_K14THF_Msk              (0x4000UL)                /*!< K14THF (Bitfield-Mask: 0x01)                          */
#define TSC_TKSR2_K14THF                  (0x4000UL)                /*!< K14THF (Bitfield-Mask: 0x01)                          */
#define TSC_TKSR2_K13THF_Pos              (13UL)                    /*!< K13THF (Bit 13)                                       */
#define TSC_TKSR2_K13THF_Msk              (0x2000UL)                /*!< K13THF (Bitfield-Mask: 0x01)                          */
#define TSC_TKSR2_K13THF                  (0x2000UL)                /*!< K13THF (Bitfield-Mask: 0x01)                          */
#define TSC_TKSR2_K12THF_Pos              (12UL)                    /*!< K12THF (Bit 12)                                       */
#define TSC_TKSR2_K12THF_Msk              (0x1000UL)                /*!< K12THF (Bitfield-Mask: 0x01)                          */
#define TSC_TKSR2_K12THF                  (0x1000UL)                /*!< K12THF (Bitfield-Mask: 0x01)                          */
#define TSC_TKSR2_K11THF_Pos              (11UL)                    /*!< K11THF (Bit 11)                                       */
#define TSC_TKSR2_K11THF_Msk              (0x800UL)                 /*!< K11THF (Bitfield-Mask: 0x01)                          */
#define TSC_TKSR2_K11THF                  (0x800UL)                 /*!< K11THF (Bitfield-Mask: 0x01)                          */
#define TSC_TKSR2_K10THF_Pos              (10UL)                    /*!< K10THF (Bit 10)                                       */
#define TSC_TKSR2_K10THF_Msk              (0x400UL)                 /*!< K10THF (Bitfield-Mask: 0x01)                          */
#define TSC_TKSR2_K10THF                  (0x400UL)                 /*!< K10THF (Bitfield-Mask: 0x01)                          */
#define TSC_TKSR2_K9THF_Pos               (9UL)                     /*!< K9THF (Bit 9)                                         */
#define TSC_TKSR2_K9THF_Msk               (0x200UL)                 /*!< K9THF (Bitfield-Mask: 0x01)                           */
#define TSC_TKSR2_K9THF                   (0x200UL)                 /*!< K9THF (Bitfield-Mask: 0x01)                           */
#define TSC_TKSR2_K8THF_Pos               (8UL)                     /*!< K8THF (Bit 8)                                         */
#define TSC_TKSR2_K8THF_Msk               (0x100UL)                 /*!< K8THF (Bitfield-Mask: 0x01)                           */
#define TSC_TKSR2_K8THF                   (0x100UL)                 /*!< K8THF (Bitfield-Mask: 0x01)                           */
#define TSC_TKSR2_K7THF_Pos               (7UL)                     /*!< K7THF (Bit 7)                                         */
#define TSC_TKSR2_K7THF_Msk               (0x80UL)                  /*!< K7THF (Bitfield-Mask: 0x01)                           */
#define TSC_TKSR2_K7THF                   (0x80UL)                  /*!< K7THF (Bitfield-Mask: 0x01)                           */
#define TSC_TKSR2_K6THF_Pos               (6UL)                     /*!< K6THF (Bit 6)                                         */
#define TSC_TKSR2_K6THF_Msk               (0x40UL)                  /*!< K6THF (Bitfield-Mask: 0x01)                           */
#define TSC_TKSR2_K6THF                   (0x40UL)                  /*!< K6THF (Bitfield-Mask: 0x01)                           */
#define TSC_TKSR2_K5THF_Pos               (5UL)                     /*!< K5THF (Bit 5)                                         */
#define TSC_TKSR2_K5THF_Msk               (0x20UL)                  /*!< K5THF (Bitfield-Mask: 0x01)                           */
#define TSC_TKSR2_K5THF                   (0x20UL)                  /*!< K5THF (Bitfield-Mask: 0x01)                           */
#define TSC_TKSR2_K4THF_Pos               (4UL)                     /*!< K4THF (Bit 4)                                         */
#define TSC_TKSR2_K4THF_Msk               (0x10UL)                  /*!< K4THF (Bitfield-Mask: 0x01)                           */
#define TSC_TKSR2_K4THF                   (0x10UL)                  /*!< K4THF (Bitfield-Mask: 0x01)                           */
#define TSC_TKSR2_K3THF_Pos               (3UL)                     /*!< K3THF (Bit 3)                                         */
#define TSC_TKSR2_K3THF_Msk               (0x8UL)                   /*!< K3THF (Bitfield-Mask: 0x01)                           */
#define TSC_TKSR2_K3THF                   (0x8UL)                   /*!< K3THF (Bitfield-Mask: 0x01)                           */
#define TSC_TKSR2_K2THF_Pos               (2UL)                     /*!< K2THF (Bit 2)                                         */
#define TSC_TKSR2_K2THF_Msk               (0x4UL)                   /*!< K2THF (Bitfield-Mask: 0x01)                           */
#define TSC_TKSR2_K2THF                   (0x4UL)                   /*!< K2THF (Bitfield-Mask: 0x01)                           */
#define TSC_TKSR2_K1THF_Pos               (1UL)                     /*!< K1THF (Bit 1)                                         */
#define TSC_TKSR2_K1THF_Msk               (0x2UL)                   /*!< K1THF (Bitfield-Mask: 0x01)                           */
#define TSC_TKSR2_K1THF                   (0x2UL)                   /*!< K1THF (Bitfield-Mask: 0x01)                           */
#define TSC_TKSR2_K0THF_Pos               (0UL)                     /*!< K0THF (Bit 0)                                         */
#define TSC_TKSR2_K0THF_Msk               (0x1UL)                   /*!< K0THF (Bitfield-Mask: 0x01)                           */
#define TSC_TKSR2_K0THF                   (0x1UL)                   /*!< K0THF (Bitfield-Mask: 0x01)                           */
/* =======================================================  TKENCFGR  ======================================================== */
#define TSC_TKENCFGR_K23EN_Pos            (23UL)                    /*!< K23EN (Bit 23)                                        */
#define TSC_TKENCFGR_K23EN_Msk            (0x800000UL)              /*!< K23EN (Bitfield-Mask: 0x01)                           */
#define TSC_TKENCFGR_K23EN                (0x800000UL)              /*!< K23EN (Bitfield-Mask: 0x01)                           */
#define TSC_TKENCFGR_K22EN_Pos            (22UL)                    /*!< K22EN (Bit 22)                                        */
#define TSC_TKENCFGR_K22EN_Msk            (0x400000UL)              /*!< K22EN (Bitfield-Mask: 0x01)                           */
#define TSC_TKENCFGR_K22EN                (0x400000UL)              /*!< K22EN (Bitfield-Mask: 0x01)                           */
#define TSC_TKENCFGR_K21EN_Pos            (21UL)                    /*!< K21EN (Bit 21)                                        */
#define TSC_TKENCFGR_K21EN_Msk            (0x200000UL)              /*!< K21EN (Bitfield-Mask: 0x01)                           */
#define TSC_TKENCFGR_K21EN                (0x200000UL)              /*!< K21EN (Bitfield-Mask: 0x01)                           */
#define TSC_TKENCFGR_K20EN_Pos            (20UL)                    /*!< K20EN (Bit 20)                                        */
#define TSC_TKENCFGR_K20EN_Msk            (0x100000UL)              /*!< K20EN (Bitfield-Mask: 0x01)                           */
#define TSC_TKENCFGR_K20EN                (0x100000UL)              /*!< K20EN (Bitfield-Mask: 0x01)                           */
#define TSC_TKENCFGR_K19EN_Pos            (19UL)                    /*!< K19EN (Bit 19)                                        */
#define TSC_TKENCFGR_K19EN_Msk            (0x80000UL)               /*!< K19EN (Bitfield-Mask: 0x01)                           */
#define TSC_TKENCFGR_K19EN                (0x80000UL)               /*!< K19EN (Bitfield-Mask: 0x01)                           */
#define TSC_TKENCFGR_K18EN_Pos            (18UL)                    /*!< K18EN (Bit 18)                                        */
#define TSC_TKENCFGR_K18EN_Msk            (0x40000UL)               /*!< K18EN (Bitfield-Mask: 0x01)                           */
#define TSC_TKENCFGR_K18EN                (0x40000UL)               /*!< K18EN (Bitfield-Mask: 0x01)                           */
#define TSC_TKENCFGR_K17EN_Pos            (17UL)                    /*!< K17EN (Bit 17)                                        */
#define TSC_TKENCFGR_K17EN_Msk            (0x20000UL)               /*!< K17EN (Bitfield-Mask: 0x01)                           */
#define TSC_TKENCFGR_K17EN                (0x20000UL)               /*!< K17EN (Bitfield-Mask: 0x01)                           */
#define TSC_TKENCFGR_K16EN_Pos            (16UL)                    /*!< K16EN (Bit 16)                                        */
#define TSC_TKENCFGR_K16EN_Msk            (0x10000UL)               /*!< K16EN (Bitfield-Mask: 0x01)                           */
#define TSC_TKENCFGR_K16EN                (0x10000UL)               /*!< K16EN (Bitfield-Mask: 0x01)                           */
#define TSC_TKENCFGR_K15EN_Pos            (15UL)                    /*!< K15EN (Bit 15)                                        */
#define TSC_TKENCFGR_K15EN_Msk            (0x8000UL)                /*!< K15EN (Bitfield-Mask: 0x01)                           */
#define TSC_TKENCFGR_K15EN                (0x8000UL)                /*!< K15EN (Bitfield-Mask: 0x01)                           */
#define TSC_TKENCFGR_K14EN_Pos            (14UL)                    /*!< K14EN (Bit 14)                                        */
#define TSC_TKENCFGR_K14EN_Msk            (0x4000UL)                /*!< K14EN (Bitfield-Mask: 0x01)                           */
#define TSC_TKENCFGR_K14EN                (0x4000UL)                /*!< K14EN (Bitfield-Mask: 0x01)                           */
#define TSC_TKENCFGR_K13EN_Pos            (13UL)                    /*!< K13EN (Bit 13)                                        */
#define TSC_TKENCFGR_K13EN_Msk            (0x2000UL)                /*!< K13EN (Bitfield-Mask: 0x01)                           */
#define TSC_TKENCFGR_K13EN                (0x2000UL)                /*!< K13EN (Bitfield-Mask: 0x01)                           */
#define TSC_TKENCFGR_K12EN_Pos            (12UL)                    /*!< K12EN (Bit 12)                                        */
#define TSC_TKENCFGR_K12EN_Msk            (0x1000UL)                /*!< K12EN (Bitfield-Mask: 0x01)                           */
#define TSC_TKENCFGR_K12EN                (0x1000UL)                /*!< K12EN (Bitfield-Mask: 0x01)                           */
#define TSC_TKENCFGR_K11EN_Pos            (11UL)                    /*!< K11EN (Bit 11)                                        */
#define TSC_TKENCFGR_K11EN_Msk            (0x800UL)                 /*!< K11EN (Bitfield-Mask: 0x01)                           */
#define TSC_TKENCFGR_K11EN                (0x800UL)                 /*!< K11EN (Bitfield-Mask: 0x01)                           */
#define TSC_TKENCFGR_K10EN_Pos            (10UL)                    /*!< K10EN (Bit 10)                                        */
#define TSC_TKENCFGR_K10EN_Msk            (0x400UL)                 /*!< K10EN (Bitfield-Mask: 0x01)                           */
#define TSC_TKENCFGR_K10EN                (0x400UL)                 /*!< K10EN (Bitfield-Mask: 0x01)                           */
#define TSC_TKENCFGR_K9EN_Pos             (9UL)                     /*!< K9EN (Bit 9)                                          */
#define TSC_TKENCFGR_K9EN_Msk             (0x200UL)                 /*!< K9EN (Bitfield-Mask: 0x01)                            */
#define TSC_TKENCFGR_K9EN                 (0x200UL)                 /*!< K9EN (Bitfield-Mask: 0x01)                            */
#define TSC_TKENCFGR_K8EN_Pos             (8UL)                     /*!< K8EN (Bit 8)                                          */
#define TSC_TKENCFGR_K8EN_Msk             (0x100UL)                 /*!< K8EN (Bitfield-Mask: 0x01)                            */
#define TSC_TKENCFGR_K8EN                 (0x100UL)                 /*!< K8EN (Bitfield-Mask: 0x01)                            */
#define TSC_TKENCFGR_K7EN_Pos             (7UL)                     /*!< K7EN (Bit 7)                                          */
#define TSC_TKENCFGR_K7EN_Msk             (0x80UL)                  /*!< K7EN (Bitfield-Mask: 0x01)                            */
#define TSC_TKENCFGR_K7EN                 (0x80UL)                  /*!< K7EN (Bitfield-Mask: 0x01)                            */
#define TSC_TKENCFGR_K6EN_Pos             (6UL)                     /*!< K6EN (Bit 6)                                          */
#define TSC_TKENCFGR_K6EN_Msk             (0x40UL)                  /*!< K6EN (Bitfield-Mask: 0x01)                            */
#define TSC_TKENCFGR_K6EN                 (0x40UL)                  /*!< K6EN (Bitfield-Mask: 0x01)                            */
#define TSC_TKENCFGR_K5EN_Pos             (5UL)                     /*!< K5EN (Bit 5)                                          */
#define TSC_TKENCFGR_K5EN_Msk             (0x20UL)                  /*!< K5EN (Bitfield-Mask: 0x01)                            */
#define TSC_TKENCFGR_K5EN                 (0x20UL)                  /*!< K5EN (Bitfield-Mask: 0x01)                            */
#define TSC_TKENCFGR_K4EN_Pos             (4UL)                     /*!< K4EN (Bit 4)                                          */
#define TSC_TKENCFGR_K4EN_Msk             (0x10UL)                  /*!< K4EN (Bitfield-Mask: 0x01)                            */
#define TSC_TKENCFGR_K4EN                 (0x10UL)                  /*!< K4EN (Bitfield-Mask: 0x01)                            */
#define TSC_TKENCFGR_K3EN_Pos             (3UL)                     /*!< K3EN (Bit 3)                                          */
#define TSC_TKENCFGR_K3EN_Msk             (0x8UL)                   /*!< K3EN (Bitfield-Mask: 0x01)                            */
#define TSC_TKENCFGR_K3EN                 (0x8UL)                   /*!< K3EN (Bitfield-Mask: 0x01)                            */
#define TSC_TKENCFGR_K2EN_Pos             (2UL)                     /*!< K2EN (Bit 2)                                          */
#define TSC_TKENCFGR_K2EN_Msk             (0x4UL)                   /*!< K2EN (Bitfield-Mask: 0x01)                            */
#define TSC_TKENCFGR_K2EN                 (0x4UL)                   /*!< K2EN (Bitfield-Mask: 0x01)                            */
#define TSC_TKENCFGR_K1EN_Pos             (1UL)                     /*!< K1EN (Bit 1)                                          */
#define TSC_TKENCFGR_K1EN_Msk             (0x2UL)                   /*!< K1EN (Bitfield-Mask: 0x01)                            */
#define TSC_TKENCFGR_K1EN                 (0x2UL)                   /*!< K1EN (Bitfield-Mask: 0x01)                            */
#define TSC_TKENCFGR_K0EN_Pos             (0UL)                     /*!< K0EN (Bit 0)                                          */
#define TSC_TKENCFGR_K0EN_Msk             (0x1UL)                   /*!< K0EN (Bitfield-Mask: 0x01)                            */
#define TSC_TKENCFGR_K0EN                 (0x1UL)                   /*!< K0EN (Bitfield-Mask: 0x01)                            */
/* =======================================================  TKTHSCFGR  ======================================================= */
#define TSC_TKTHSCFGR_K23THS_Pos          (23UL)                    /*!< K23THS (Bit 23)                                       */
#define TSC_TKTHSCFGR_K23THS_Msk          (0x800000UL)              /*!< K23THS (Bitfield-Mask: 0x01)                          */
#define TSC_TKTHSCFGR_K23THS              (0x800000UL)              /*!< K23THS (Bitfield-Mask: 0x01)                          */
#define TSC_TKTHSCFGR_K22THS_Pos          (22UL)                    /*!< K22THS (Bit 22)                                       */
#define TSC_TKTHSCFGR_K22THS_Msk          (0x400000UL)              /*!< K22THS (Bitfield-Mask: 0x01)                          */
#define TSC_TKTHSCFGR_K22THS              (0x400000UL)              /*!< K22THS (Bitfield-Mask: 0x01)                          */
#define TSC_TKTHSCFGR_K21THS_Pos          (21UL)                    /*!< K21THS (Bit 21)                                       */
#define TSC_TKTHSCFGR_K21THS_Msk          (0x200000UL)              /*!< K21THS (Bitfield-Mask: 0x01)                          */
#define TSC_TKTHSCFGR_K21THS              (0x200000UL)              /*!< K21THS (Bitfield-Mask: 0x01)                          */
#define TSC_TKTHSCFGR_K20THS_Pos          (20UL)                    /*!< K20THS (Bit 20)                                       */
#define TSC_TKTHSCFGR_K20THS_Msk          (0x100000UL)              /*!< K20THS (Bitfield-Mask: 0x01)                          */
#define TSC_TKTHSCFGR_K20THS              (0x100000UL)              /*!< K20THS (Bitfield-Mask: 0x01)                          */
#define TSC_TKTHSCFGR_K19THS_Pos          (19UL)                    /*!< K19THS (Bit 19)                                       */
#define TSC_TKTHSCFGR_K19THS_Msk          (0x80000UL)               /*!< K19THS (Bitfield-Mask: 0x01)                          */
#define TSC_TKTHSCFGR_K19THS              (0x80000UL)               /*!< K19THS (Bitfield-Mask: 0x01)                          */
#define TSC_TKTHSCFGR_K18THS_Pos          (18UL)                    /*!< K18THS (Bit 18)                                       */
#define TSC_TKTHSCFGR_K18THS_Msk          (0x40000UL)               /*!< K18THS (Bitfield-Mask: 0x01)                          */
#define TSC_TKTHSCFGR_K18THS              (0x40000UL)               /*!< K18THS (Bitfield-Mask: 0x01)                          */
#define TSC_TKTHSCFGR_K17THS_Pos          (17UL)                    /*!< K17THS (Bit 17)                                       */
#define TSC_TKTHSCFGR_K17THS_Msk          (0x20000UL)               /*!< K17THS (Bitfield-Mask: 0x01)                          */
#define TSC_TKTHSCFGR_K17THS              (0x20000UL)               /*!< K17THS (Bitfield-Mask: 0x01)                          */
#define TSC_TKTHSCFGR_K16THS_Pos          (16UL)                    /*!< K16THS (Bit 16)                                       */
#define TSC_TKTHSCFGR_K16THS_Msk          (0x10000UL)               /*!< K16THS (Bitfield-Mask: 0x01)                          */
#define TSC_TKTHSCFGR_K16THS              (0x10000UL)               /*!< K16THS (Bitfield-Mask: 0x01)                          */
#define TSC_TKTHSCFGR_K15THS_Pos          (15UL)                    /*!< K15THS (Bit 15)                                       */
#define TSC_TKTHSCFGR_K15THS_Msk          (0x8000UL)                /*!< K15THS (Bitfield-Mask: 0x01)                          */
#define TSC_TKTHSCFGR_K15THS              (0x8000UL)                /*!< K15THS (Bitfield-Mask: 0x01)                          */
#define TSC_TKTHSCFGR_K14THS_Pos          (14UL)                    /*!< K14THS (Bit 14)                                       */
#define TSC_TKTHSCFGR_K14THS_Msk          (0x4000UL)                /*!< K14THS (Bitfield-Mask: 0x01)                          */
#define TSC_TKTHSCFGR_K14THS              (0x4000UL)                /*!< K14THS (Bitfield-Mask: 0x01)                          */
#define TSC_TKTHSCFGR_K13THS_Pos          (13UL)                    /*!< K13THS (Bit 13)                                       */
#define TSC_TKTHSCFGR_K13THS_Msk          (0x2000UL)                /*!< K13THS (Bitfield-Mask: 0x01)                          */
#define TSC_TKTHSCFGR_K13THS              (0x2000UL)                /*!< K13THS (Bitfield-Mask: 0x01)                          */
#define TSC_TKTHSCFGR_K12THS_Pos          (12UL)                    /*!< K12THS (Bit 12)                                       */
#define TSC_TKTHSCFGR_K12THS_Msk          (0x1000UL)                /*!< K12THS (Bitfield-Mask: 0x01)                          */
#define TSC_TKTHSCFGR_K12THS              (0x1000UL)                /*!< K12THS (Bitfield-Mask: 0x01)                          */
#define TSC_TKTHSCFGR_K11THS_Pos          (11UL)                    /*!< K11THS (Bit 11)                                       */
#define TSC_TKTHSCFGR_K11THS_Msk          (0x800UL)                 /*!< K11THS (Bitfield-Mask: 0x01)                          */
#define TSC_TKTHSCFGR_K11THS              (0x800UL)                 /*!< K11THS (Bitfield-Mask: 0x01)                          */
#define TSC_TKTHSCFGR_K10THS_Pos          (10UL)                    /*!< K10THS (Bit 10)                                       */
#define TSC_TKTHSCFGR_K10THS_Msk          (0x400UL)                 /*!< K10THS (Bitfield-Mask: 0x01)                          */
#define TSC_TKTHSCFGR_K10THS              (0x400UL)                 /*!< K10THS (Bitfield-Mask: 0x01)                          */
#define TSC_TKTHSCFGR_K9THS_Pos           (9UL)                     /*!< K9THS (Bit 9)                                         */
#define TSC_TKTHSCFGR_K9THS_Msk           (0x200UL)                 /*!< K9THS (Bitfield-Mask: 0x01)                           */
#define TSC_TKTHSCFGR_K9THS               (0x200UL)                 /*!< K9THS (Bitfield-Mask: 0x01)                           */
#define TSC_TKTHSCFGR_K8THS_Pos           (8UL)                     /*!< K8THS (Bit 8)                                         */
#define TSC_TKTHSCFGR_K8THS_Msk           (0x100UL)                 /*!< K8THS (Bitfield-Mask: 0x01)                           */
#define TSC_TKTHSCFGR_K8THS               (0x100UL)                 /*!< K8THS (Bitfield-Mask: 0x01)                           */
#define TSC_TKTHSCFGR_K7THS_Pos           (7UL)                     /*!< K7THS (Bit 7)                                         */
#define TSC_TKTHSCFGR_K7THS_Msk           (0x80UL)                  /*!< K7THS (Bitfield-Mask: 0x01)                           */
#define TSC_TKTHSCFGR_K7THS               (0x80UL)                  /*!< K7THS (Bitfield-Mask: 0x01)                           */
#define TSC_TKTHSCFGR_K6THS_Pos           (6UL)                     /*!< K6THS (Bit 6)                                         */
#define TSC_TKTHSCFGR_K6THS_Msk           (0x40UL)                  /*!< K6THS (Bitfield-Mask: 0x01)                           */
#define TSC_TKTHSCFGR_K6THS               (0x40UL)                  /*!< K6THS (Bitfield-Mask: 0x01)                           */
#define TSC_TKTHSCFGR_K5THS_Pos           (5UL)                     /*!< K5THS (Bit 5)                                         */
#define TSC_TKTHSCFGR_K5THS_Msk           (0x20UL)                  /*!< K5THS (Bitfield-Mask: 0x01)                           */
#define TSC_TKTHSCFGR_K5THS               (0x20UL)                  /*!< K5THS (Bitfield-Mask: 0x01)                           */
#define TSC_TKTHSCFGR_K4THS_Pos           (4UL)                     /*!< K4THS (Bit 4)                                         */
#define TSC_TKTHSCFGR_K4THS_Msk           (0x10UL)                  /*!< K4THS (Bitfield-Mask: 0x01)                           */
#define TSC_TKTHSCFGR_K4THS               (0x10UL)                  /*!< K4THS (Bitfield-Mask: 0x01)                           */
#define TSC_TKTHSCFGR_K3THS_Pos           (3UL)                     /*!< K3THS (Bit 3)                                         */
#define TSC_TKTHSCFGR_K3THS_Msk           (0x8UL)                   /*!< K3THS (Bitfield-Mask: 0x01)                           */
#define TSC_TKTHSCFGR_K3THS               (0x8UL)                   /*!< K3THS (Bitfield-Mask: 0x01)                           */
#define TSC_TKTHSCFGR_K2THS_Pos           (2UL)                     /*!< K2THS (Bit 2)                                         */
#define TSC_TKTHSCFGR_K2THS_Msk           (0x4UL)                   /*!< K2THS (Bitfield-Mask: 0x01)                           */
#define TSC_TKTHSCFGR_K2THS               (0x4UL)                   /*!< K2THS (Bitfield-Mask: 0x01)                           */
#define TSC_TKTHSCFGR_K1THS_Pos           (1UL)                     /*!< K1THS (Bit 1)                                         */
#define TSC_TKTHSCFGR_K1THS_Msk           (0x2UL)                   /*!< K1THS (Bitfield-Mask: 0x01)                           */
#define TSC_TKTHSCFGR_K1THS               (0x2UL)                   /*!< K1THS (Bitfield-Mask: 0x01)                           */
#define TSC_TKTHSCFGR_K0THS_Pos           (0UL)                     /*!< K0THS (Bit 0)                                         */
#define TSC_TKTHSCFGR_K0THS_Msk           (0x1UL)                   /*!< K0THS (Bitfield-Mask: 0x01)                           */
#define TSC_TKTHSCFGR_K0THS               (0x1UL)                   /*!< K0THS (Bitfield-Mask: 0x01)                           */
/* ========================================================  TKROCPR  ======================================================== */
#define TSC_TKROCPR_TKRO_Pos              (0UL)                     /*!< TKRO (Bit 0)                                          */
#define TSC_TKROCPR_TKRO_Msk              (0x3ffUL)                 /*!< TKRO (Bitfield-Mask: 0x3ff)                           */
#define TSC_TKROCPR_TKRO                  (0x3ffUL)                 /*!< TKRO (Bitfield-Mask: 0x3ff)                           */
/* ========================================================  TKK0CPR  ======================================================== */
#define TSC_TKK0CPR_TKRO_K0_Pos           (0UL)                     /*!< TKRO_K0 (Bit 0)                                       */
#define TSC_TKK0CPR_TKRO_K0_Msk           (0x3ffUL)                 /*!< TKRO_K0 (Bitfield-Mask: 0x3ff)                        */
#define TSC_TKK0CPR_TKRO_K0               (0x3ffUL)                 /*!< TKRO_K0 (Bitfield-Mask: 0x3ff)                        */
/* ========================================================  TKK1CPR  ======================================================== */
#define TSC_TKK1CPR_TKRO_K1_Pos           (0UL)                     /*!< TKRO_K1 (Bit 0)                                       */
#define TSC_TKK1CPR_TKRO_K1_Msk           (0x3ffUL)                 /*!< TKRO_K1 (Bitfield-Mask: 0x3ff)                        */
#define TSC_TKK1CPR_TKRO_K1               (0x3ffUL)                 /*!< TKRO_K1 (Bitfield-Mask: 0x3ff)                        */
/* ========================================================  TKK2CPR  ======================================================== */
#define TSC_TKK2CPR_TKRO_K2_Pos           (0UL)                     /*!< TKRO_K2 (Bit 0)                                       */
#define TSC_TKK2CPR_TKRO_K2_Msk           (0x3ffUL)                 /*!< TKRO_K2 (Bitfield-Mask: 0x3ff)                        */
#define TSC_TKK2CPR_TKRO_K2               (0x3ffUL)                 /*!< TKRO_K2 (Bitfield-Mask: 0x3ff)                        */
/* ========================================================  TKK3CPR  ======================================================== */
#define TSC_TKK3CPR_TKRO_K3_Pos           (0UL)                     /*!< TKRO_K3 (Bit 0)                                       */
#define TSC_TKK3CPR_TKRO_K3_Msk           (0x3ffUL)                 /*!< TKRO_K3 (Bitfield-Mask: 0x3ff)                        */
#define TSC_TKK3CPR_TKRO_K3               (0x3ffUL)                 /*!< TKRO_K3 (Bitfield-Mask: 0x3ff)                        */
/* ========================================================  TKK4CPR  ======================================================== */
#define TSC_TKK4CPR_TKRO_K4_Pos           (0UL)                     /*!< TKRO_K4 (Bit 0)                                       */
#define TSC_TKK4CPR_TKRO_K4_Msk           (0x3ffUL)                 /*!< TKRO_K4 (Bitfield-Mask: 0x3ff)                        */
#define TSC_TKK4CPR_TKRO_K4               (0x3ffUL)                 /*!< TKRO_K4 (Bitfield-Mask: 0x3ff)                        */
/* ========================================================  TKK5CPR  ======================================================== */
#define TSC_TKK5CPR_TKRO_K5_Pos           (0UL)                     /*!< TKRO_K5 (Bit 0)                                       */
#define TSC_TKK5CPR_TKRO_K5_Msk           (0x3ffUL)                 /*!< TKRO_K5 (Bitfield-Mask: 0x3ff)                        */
#define TSC_TKK5CPR_TKRO_K5               (0x3ffUL)                 /*!< TKRO_K5 (Bitfield-Mask: 0x3ff)                        */
/* ========================================================  TKK6CPR  ======================================================== */
#define TSC_TKK6CPR_TKRO_K6_Pos           (0UL)                     /*!< TKRO_K6 (Bit 0)                                       */
#define TSC_TKK6CPR_TKRO_K6_Msk           (0x3ffUL)                 /*!< TKRO_K6 (Bitfield-Mask: 0x3ff)                        */
#define TSC_TKK6CPR_TKRO_K6               (0x3ffUL)                 /*!< TKRO_K6 (Bitfield-Mask: 0x3ff)                        */
/* ========================================================  TKK7CPR  ======================================================== */
#define TSC_TKK7CPR_TKRO_K7_Pos           (0UL)                     /*!< TKRO_K7 (Bit 0)                                       */
#define TSC_TKK7CPR_TKRO_K7_Msk           (0x3ffUL)                 /*!< TKRO_K7 (Bitfield-Mask: 0x3ff)                        */
#define TSC_TKK7CPR_TKRO_K7               (0x3ffUL)                 /*!< TKRO_K7 (Bitfield-Mask: 0x3ff)                        */
/* ========================================================  TKK8CPR  ======================================================== */
#define TSC_TKK8CPR_TKRO_K8_Pos           (0UL)                     /*!< TKRO_K8 (Bit 0)                                       */
#define TSC_TKK8CPR_TKRO_K8_Msk           (0x3ffUL)                 /*!< TKRO_K8 (Bitfield-Mask: 0x3ff)                        */
#define TSC_TKK8CPR_TKRO_K8               (0x3ffUL)                 /*!< TKRO_K8 (Bitfield-Mask: 0x3ff)                        */
/* ========================================================  TKK9CPR  ======================================================== */
#define TSC_TKK9CPR_TKRO_K9_Pos           (0UL)                     /*!< TKRO_K9 (Bit 0)                                       */
#define TSC_TKK9CPR_TKRO_K9_Msk           (0x3ffUL)                 /*!< TKRO_K9 (Bitfield-Mask: 0x3ff)                        */
#define TSC_TKK9CPR_TKRO_K9               (0x3ffUL)                 /*!< TKRO_K9 (Bitfield-Mask: 0x3ff)                        */
/* ========================================================  TKKACPR  ======================================================== */
#define TSC_TKKACPR_TKRO_KA_Pos           (0UL)                     /*!< TKRO_KA (Bit 0)                                       */
#define TSC_TKKACPR_TKRO_KA_Msk           (0x3ffUL)                 /*!< TKRO_KA (Bitfield-Mask: 0x3ff)                        */
#define TSC_TKKACPR_TKRO_KA               (0x3ffUL)                 /*!< TKRO_KA (Bitfield-Mask: 0x3ff)                        */
/* ========================================================  TKKBCPR  ======================================================== */
#define TSC_TKKBCPR_TKRO_KB_Pos           (0UL)                     /*!< TKRO_KB (Bit 0)                                       */
#define TSC_TKKBCPR_TKRO_KB_Msk           (0x3ffUL)                 /*!< TKRO_KB (Bitfield-Mask: 0x3ff)                        */
#define TSC_TKKBCPR_TKRO_KB               (0x3ffUL)                 /*!< TKRO_KB (Bitfield-Mask: 0x3ff)                        */
/* ========================================================  TKKCCPR  ======================================================== */
#define TSC_TKKCCPR_TKRO_KC_Pos           (0UL)                     /*!< TKRO_KC (Bit 0)                                       */
#define TSC_TKKCCPR_TKRO_KC_Msk           (0x3ffUL)                 /*!< TKRO_KC (Bitfield-Mask: 0x3ff)                        */
#define TSC_TKKCCPR_TKRO_KC               (0x3ffUL)                 /*!< TKRO_KC (Bitfield-Mask: 0x3ff)                        */
/* ========================================================  TKKDCPR  ======================================================== */
#define TSC_TKKDCPR_TKRO_KD_Pos           (0UL)                     /*!< TKRO_KD (Bit 0)                                       */
#define TSC_TKKDCPR_TKRO_KD_Msk           (0x3ffUL)                 /*!< TKRO_KD (Bitfield-Mask: 0x3ff)                        */
#define TSC_TKKDCPR_TKRO_KD               (0x3ffUL)                 /*!< TKRO_KD (Bitfield-Mask: 0x3ff)                        */
/* ========================================================  TKKECPR  ======================================================== */
#define TSC_TKKECPR_TKRO_KE_Pos           (0UL)                     /*!< TKRO_KE (Bit 0)                                       */
#define TSC_TKKECPR_TKRO_KE_Msk           (0x3ffUL)                 /*!< TKRO_KE (Bitfield-Mask: 0x3ff)                        */
#define TSC_TKKECPR_TKRO_KE               (0x3ffUL)                 /*!< TKRO_KE (Bitfield-Mask: 0x3ff)                        */
/* ========================================================  TKKFCPR  ======================================================== */
#define TSC_TKKFCPR_TKRO_KF_Pos           (0UL)                     /*!< TKRO_KF (Bit 0)                                       */
#define TSC_TKKFCPR_TKRO_KF_Msk           (0x3ffUL)                 /*!< TKRO_KF (Bitfield-Mask: 0x3ff)                        */
#define TSC_TKKFCPR_TKRO_KF               (0x3ffUL)                 /*!< TKRO_KF (Bitfield-Mask: 0x3ff)                        */
/* =======================================================  TKCFCNTR  ======================================================== */
#define TSC_TKCFCNTR_TK16D_Pos            (0UL)                     /*!< TK16D (Bit 0)                                         */
#define TSC_TKCFCNTR_TK16D_Msk            (0xffffUL)                /*!< TK16D (Bitfield-Mask: 0xffff)                         */
#define TSC_TKCFCNTR_TK16D                (0xffffUL)                /*!< TK16D (Bitfield-Mask: 0xffff)                         */
/* =======================================================  TKK0CNTR  ======================================================== */
#define TSC_TKK0CNTR_TK16D_K0_Pos         (0UL)                     /*!< TK16D_K0 (Bit 0)                                      */
#define TSC_TKK0CNTR_TK16D_K0_Msk         (0xffffUL)                /*!< TK16D_K0 (Bitfield-Mask: 0xffff)                      */
#define TSC_TKK0CNTR_TK16D_K0             (0xffffUL)                /*!< TK16D_K0 (Bitfield-Mask: 0xffff)                      */
/* =======================================================  TKK1CNTR  ======================================================== */
#define TSC_TKK1CNTR_TK16D_K1_Pos         (0UL)                     /*!< TK16D_K1 (Bit 0)                                      */
#define TSC_TKK1CNTR_TK16D_K1_Msk         (0xffffUL)                /*!< TK16D_K1 (Bitfield-Mask: 0xffff)                      */
#define TSC_TKK1CNTR_TK16D_K1             (0xffffUL)                /*!< TK16D_K1 (Bitfield-Mask: 0xffff)                      */
/* =======================================================  TKK2CNTR  ======================================================== */
#define TSC_TKK2CNTR_TK16D_K2_Pos         (0UL)                     /*!< TK16D_K2 (Bit 0)                                      */
#define TSC_TKK2CNTR_TK16D_K2_Msk         (0xffffUL)                /*!< TK16D_K2 (Bitfield-Mask: 0xffff)                      */
#define TSC_TKK2CNTR_TK16D_K2             (0xffffUL)                /*!< TK16D_K2 (Bitfield-Mask: 0xffff)                      */
/* =======================================================  TKK3CNTR  ======================================================== */
#define TSC_TKK3CNTR_TK16D_K3_Pos         (0UL)                     /*!< TK16D_K3 (Bit 0)                                      */
#define TSC_TKK3CNTR_TK16D_K3_Msk         (0xffffUL)                /*!< TK16D_K3 (Bitfield-Mask: 0xffff)                      */
#define TSC_TKK3CNTR_TK16D_K3             (0xffffUL)                /*!< TK16D_K3 (Bitfield-Mask: 0xffff)                      */
/* =======================================================  TKK4CNTR  ======================================================== */
#define TSC_TKK4CNTR_TK16D_K4_Pos         (0UL)                     /*!< TK16D_K4 (Bit 0)                                      */
#define TSC_TKK4CNTR_TK16D_K4_Msk         (0xffffUL)                /*!< TK16D_K4 (Bitfield-Mask: 0xffff)                      */
#define TSC_TKK4CNTR_TK16D_K4             (0xffffUL)                /*!< TK16D_K4 (Bitfield-Mask: 0xffff)                      */
/* =======================================================  TKK5CNTR  ======================================================== */
#define TSC_TKK5CNTR_TK16D_K5_Pos         (0UL)                     /*!< TK16D_K5 (Bit 0)                                      */
#define TSC_TKK5CNTR_TK16D_K5_Msk         (0xffffUL)                /*!< TK16D_K5 (Bitfield-Mask: 0xffff)                      */
#define TSC_TKK5CNTR_TK16D_K5             (0xffffUL)                /*!< TK16D_K5 (Bitfield-Mask: 0xffff)                      */
/* =======================================================  TKK6CNTR  ======================================================== */
#define TSC_TKK6CNTR_TK16D_K6_Pos         (0UL)                     /*!< TK16D_K6 (Bit 0)                                      */
#define TSC_TKK6CNTR_TK16D_K6_Msk         (0xffffUL)                /*!< TK16D_K6 (Bitfield-Mask: 0xffff)                      */
#define TSC_TKK6CNTR_TK16D_K6             (0xffffUL)                /*!< TK16D_K6 (Bitfield-Mask: 0xffff)                      */
/* =======================================================  TKK7CNTR  ======================================================== */
#define TSC_TKK7CNTR_TK16D_K7_Pos         (0UL)                     /*!< TK16D_K7 (Bit 0)                                      */
#define TSC_TKK7CNTR_TK16D_K7_Msk         (0xffffUL)                /*!< TK16D_K7 (Bitfield-Mask: 0xffff)                      */
#define TSC_TKK7CNTR_TK16D_K7             (0xffffUL)                /*!< TK16D_K7 (Bitfield-Mask: 0xffff)                      */
/* =======================================================  TKK8CNTR  ======================================================== */
#define TSC_TKK8CNTR_TK16D_K8_Pos         (0UL)                     /*!< TK16D_K8 (Bit 0)                                      */
#define TSC_TKK8CNTR_TK16D_K8_Msk         (0xffffUL)                /*!< TK16D_K8 (Bitfield-Mask: 0xffff)                      */
#define TSC_TKK8CNTR_TK16D_K8             (0xffffUL)                /*!< TK16D_K8 (Bitfield-Mask: 0xffff)                      */
/* =======================================================  TKK9CNTR  ======================================================== */
#define TSC_TKK9CNTR_TK16D_K9_Pos         (0UL)                     /*!< TK16D_K9 (Bit 0)                                      */
#define TSC_TKK9CNTR_TK16D_K9_Msk         (0xffffUL)                /*!< TK16D_K9 (Bitfield-Mask: 0xffff)                      */
#define TSC_TKK9CNTR_TK16D_K9             (0xffffUL)                /*!< TK16D_K9 (Bitfield-Mask: 0xffff)                      */
/* =======================================================  TKKACNTR  ======================================================== */
#define TSC_TKKACNTR_TK16D_KA_Pos         (0UL)                     /*!< TK16D_KA (Bit 0)                                      */
#define TSC_TKKACNTR_TK16D_KA_Msk         (0xffffUL)                /*!< TK16D_KA (Bitfield-Mask: 0xffff)                      */
#define TSC_TKKACNTR_TK16D_KA             (0xffffUL)                /*!< TK16D_KA (Bitfield-Mask: 0xffff)                      */
/* =======================================================  TKKBCNTR  ======================================================== */
#define TSC_TKKBCNTR_TK16D_KB_Pos         (0UL)                     /*!< TK16D_KB (Bit 0)                                      */
#define TSC_TKKBCNTR_TK16D_KB_Msk         (0xffffUL)                /*!< TK16D_KB (Bitfield-Mask: 0xffff)                      */
#define TSC_TKKBCNTR_TK16D_KB             (0xffffUL)                /*!< TK16D_KB (Bitfield-Mask: 0xffff)                      */
/* =======================================================  TKKCCNTR  ======================================================== */
#define TSC_TKKCCNTR_TK16D_KC_Pos         (0UL)                     /*!< TK16D_KC (Bit 0)                                      */
#define TSC_TKKCCNTR_TK16D_KC_Msk         (0xffffUL)                /*!< TK16D_KC (Bitfield-Mask: 0xffff)                      */
#define TSC_TKKCCNTR_TK16D_KC             (0xffffUL)                /*!< TK16D_KC (Bitfield-Mask: 0xffff)                      */
/* =======================================================  TKKDCNTR  ======================================================== */
#define TSC_TKKDCNTR_TK16D_KD_Pos         (0UL)                     /*!< TK16D_KD (Bit 0)                                      */
#define TSC_TKKDCNTR_TK16D_KD_Msk         (0xffffUL)                /*!< TK16D_KD (Bitfield-Mask: 0xffff)                      */
#define TSC_TKKDCNTR_TK16D_KD             (0xffffUL)                /*!< TK16D_KD (Bitfield-Mask: 0xffff)                      */
/* =======================================================  TKKECNTR  ======================================================== */
#define TSC_TKKECNTR_TK16D_KE_Pos         (0UL)                     /*!< TK16D_KE (Bit 0)                                      */
#define TSC_TKKECNTR_TK16D_KE_Msk         (0xffffUL)                /*!< TK16D_KE (Bitfield-Mask: 0xffff)                      */
#define TSC_TKKECNTR_TK16D_KE             (0xffffUL)                /*!< TK16D_KE (Bitfield-Mask: 0xffff)                      */
/* =======================================================  TKKFCNTR  ======================================================== */
#define TSC_TKKFCNTR_TK16D_KF_Pos         (0UL)                     /*!< TK16D_KF (Bit 0)                                      */
#define TSC_TKKFCNTR_TK16D_KF_Msk         (0xffffUL)                /*!< TK16D_KF (Bitfield-Mask: 0xffff)                      */
#define TSC_TKKFCNTR_TK16D_KF             (0xffffUL)                /*!< TK16D_KF (Bitfield-Mask: 0xffff)                      */
/* ========================================================  TKK0THR  ======================================================== */
#define TSC_TKK0THR_TK0M0TH16_Pos         (0UL)                     /*!< TK0M0TH16 (Bit 0)                                     */
#define TSC_TKK0THR_TK0M0TH16_Msk         (0xffffUL)                /*!< TK0M0TH16 (Bitfield-Mask: 0xffff)                     */
#define TSC_TKK0THR_TK0M0TH16             (0xffffUL)                /*!< TK0M0TH16 (Bitfield-Mask: 0xffff)                     */
/* ========================================================  TKK1THR  ======================================================== */
#define TSC_TKK1THR_TK1M0TH16_Pos         (0UL)                     /*!< TK1M0TH16 (Bit 0)                                     */
#define TSC_TKK1THR_TK1M0TH16_Msk         (0xffffUL)                /*!< TK1M0TH16 (Bitfield-Mask: 0xffff)                     */
#define TSC_TKK1THR_TK1M0TH16             (0xffffUL)                /*!< TK1M0TH16 (Bitfield-Mask: 0xffff)                     */
/* ========================================================  TKK2THR  ======================================================== */
#define TSC_TKK2THR_TK2M0TH16_Pos         (0UL)                     /*!< TK2M0TH16 (Bit 0)                                     */
#define TSC_TKK2THR_TK2M0TH16_Msk         (0xffffUL)                /*!< TK2M0TH16 (Bitfield-Mask: 0xffff)                     */
#define TSC_TKK2THR_TK2M0TH16             (0xffffUL)                /*!< TK2M0TH16 (Bitfield-Mask: 0xffff)                     */
/* ========================================================  TKK3THR  ======================================================== */
#define TSC_TKK3THR_TK3M0TH16_Pos         (0UL)                     /*!< TK3M0TH16 (Bit 0)                                     */
#define TSC_TKK3THR_TK3M0TH16_Msk         (0xffffUL)                /*!< TK3M0TH16 (Bitfield-Mask: 0xffff)                     */
#define TSC_TKK3THR_TK3M0TH16             (0xffffUL)                /*!< TK3M0TH16 (Bitfield-Mask: 0xffff)                     */
/* ========================================================  TKK4THR  ======================================================== */
#define TSC_TKK4THR_TK4M0TH16_Pos         (0UL)                     /*!< TK4M0TH16 (Bit 0)                                     */
#define TSC_TKK4THR_TK4M0TH16_Msk         (0xffffUL)                /*!< TK4M0TH16 (Bitfield-Mask: 0xffff)                     */
#define TSC_TKK4THR_TK4M0TH16             (0xffffUL)                /*!< TK4M0TH16 (Bitfield-Mask: 0xffff)                     */
/* ========================================================  TKK5THR  ======================================================== */
#define TSC_TKK5THR_TK5M0TH16_Pos         (0UL)                     /*!< TK5M0TH16 (Bit 0)                                     */
#define TSC_TKK5THR_TK5M0TH16_Msk         (0xffffUL)                /*!< TK5M0TH16 (Bitfield-Mask: 0xffff)                     */
#define TSC_TKK5THR_TK5M0TH16             (0xffffUL)                /*!< TK5M0TH16 (Bitfield-Mask: 0xffff)                     */
/* ========================================================  TKK6THR  ======================================================== */
#define TSC_TKK6THR_TK6M0TH16_Pos         (0UL)                     /*!< TK6M0TH16 (Bit 0)                                     */
#define TSC_TKK6THR_TK6M0TH16_Msk         (0xffffUL)                /*!< TK6M0TH16 (Bitfield-Mask: 0xffff)                     */
#define TSC_TKK6THR_TK6M0TH16             (0xffffUL)                /*!< TK6M0TH16 (Bitfield-Mask: 0xffff)                     */
/* ========================================================  TKK7THR  ======================================================== */
#define TSC_TKK7THR_TK7M0TH16_Pos         (0UL)                     /*!< TK7M0TH16 (Bit 0)                                     */
#define TSC_TKK7THR_TK7M0TH16_Msk         (0xffffUL)                /*!< TK7M0TH16 (Bitfield-Mask: 0xffff)                     */
#define TSC_TKK7THR_TK7M0TH16             (0xffffUL)                /*!< TK7M0TH16 (Bitfield-Mask: 0xffff)                     */
/* ========================================================  TKK8THR  ======================================================== */
#define TSC_TKK8THR_TK8M0TH16_Pos         (0UL)                     /*!< TK8M0TH16 (Bit 0)                                     */
#define TSC_TKK8THR_TK8M0TH16_Msk         (0xffffUL)                /*!< TK8M0TH16 (Bitfield-Mask: 0xffff)                     */
#define TSC_TKK8THR_TK8M0TH16             (0xffffUL)                /*!< TK8M0TH16 (Bitfield-Mask: 0xffff)                     */
/* ========================================================  TKK9THR  ======================================================== */
#define TSC_TKK9THR_TK9M0TH16_Pos         (0UL)                     /*!< TK9M0TH16 (Bit 0)                                     */
#define TSC_TKK9THR_TK9M0TH16_Msk         (0xffffUL)                /*!< TK9M0TH16 (Bitfield-Mask: 0xffff)                     */
#define TSC_TKK9THR_TK9M0TH16             (0xffffUL)                /*!< TK9M0TH16 (Bitfield-Mask: 0xffff)                     */
/* ========================================================  TKKATHR  ======================================================== */
#define TSC_TKKATHR_TKAM0TH16_Pos         (0UL)                     /*!< TKAM0TH16 (Bit 0)                                     */
#define TSC_TKKATHR_TKAM0TH16_Msk         (0xffffUL)                /*!< TKAM0TH16 (Bitfield-Mask: 0xffff)                     */
#define TSC_TKKATHR_TKAM0TH16             (0xffffUL)                /*!< TKAM0TH16 (Bitfield-Mask: 0xffff)                     */
/* ========================================================  TKKBTHR  ======================================================== */
#define TSC_TKKBTHR_TKBM0TH16_Pos         (0UL)                     /*!< TKBM0TH16 (Bit 0)                                     */
#define TSC_TKKBTHR_TKBM0TH16_Msk         (0xffffUL)                /*!< TKBM0TH16 (Bitfield-Mask: 0xffff)                     */
#define TSC_TKKBTHR_TKBM0TH16             (0xffffUL)                /*!< TKBM0TH16 (Bitfield-Mask: 0xffff)                     */
/* ========================================================  TKKCTHR  ======================================================== */
#define TSC_TKKCTHR_TKCM0TH16_Pos         (0UL)                     /*!< TKCM0TH16 (Bit 0)                                     */
#define TSC_TKKCTHR_TKCM0TH16_Msk         (0xffffUL)                /*!< TKCM0TH16 (Bitfield-Mask: 0xffff)                     */
#define TSC_TKKCTHR_TKCM0TH16             (0xffffUL)                /*!< TKCM0TH16 (Bitfield-Mask: 0xffff)                     */
/* ========================================================  TKKDTHR  ======================================================== */
#define TSC_TKKDTHR_TKDM0TH16_Pos         (0UL)                     /*!< TKDM0TH16 (Bit 0)                                     */
#define TSC_TKKDTHR_TKDM0TH16_Msk         (0xffffUL)                /*!< TKDM0TH16 (Bitfield-Mask: 0xffff)                     */
#define TSC_TKKDTHR_TKDM0TH16             (0xffffUL)                /*!< TKDM0TH16 (Bitfield-Mask: 0xffff)                     */
/* ========================================================  TKKETHR  ======================================================== */
#define TSC_TKKETHR_TKEM0TH16_Pos         (0UL)                     /*!< TKEM0TH16 (Bit 0)                                     */
#define TSC_TKKETHR_TKEM0TH16_Msk         (0xffffUL)                /*!< TKEM0TH16 (Bitfield-Mask: 0xffff)                     */
#define TSC_TKKETHR_TKEM0TH16             (0xffffUL)                /*!< TKEM0TH16 (Bitfield-Mask: 0xffff)                     */
/* ========================================================  TKKFTHR  ======================================================== */
#define TSC_TKKFTHR_TKFM0TH16_Pos         (0UL)                     /*!< TKFM0TH16 (Bit 0)                                     */
#define TSC_TKKFTHR_TKFM0TH16_Msk         (0xffffUL)                /*!< TKFM0TH16 (Bitfield-Mask: 0xffff)                     */
#define TSC_TKKFTHR_TKFM0TH16             (0xffffUL)                /*!< TKFM0TH16 (Bitfield-Mask: 0xffff)                     */


/* =========================================================================================================================== */
/* ================                                           TEST                                            ================ */
/* =========================================================================================================================== */

/* ======================================================  TEST_MODER  ======================================================= */
#define TEST_TEST_MODER_KEY_Pos           (16UL)                    /*!< KEY (Bit 16)                                          */
#define TEST_TEST_MODER_KEY_Msk           (0xffff0000UL)            /*!< KEY (Bitfield-Mask: 0xffff)                           */
#define TEST_TEST_MODER_KEY               (0xffff0000UL)            /*!< KEY (Bitfield-Mask: 0xffff)                           */
#define TEST_TEST_MODER_TEST_MODE_Pos     (0UL)                     /*!< TEST_MODE (Bit 0)                                     */
#define TEST_TEST_MODER_TEST_MODE_Msk     (0xffUL)                  /*!< TEST_MODE (Bitfield-Mask: 0xff)                       */
#define TEST_TEST_MODER_TEST_MODE         (0xffUL)                  /*!< TEST_MODE (Bitfield-Mask: 0xff)                       */
/* ======================================================  TEST_TRIMR1  ====================================================== */
#define TEST_TEST_TRIMR1_TS_TRIM_Pos      (28UL)                    /*!< TS_TRIM (Bit 28)                                      */
#define TEST_TEST_TRIMR1_TS_TRIM_Msk      (0xf0000000UL)            /*!< TS_TRIM (Bitfield-Mask: 0x0f)                         */
#define TEST_TEST_TRIMR1_TS_TRIM          (0xf0000000UL)            /*!< TS_TRIM (Bitfield-Mask: 0x0f)                         */
#define TEST_TEST_TRIMR1_TRIM_BG_Pos      (19UL)                    /*!< TRIM_BG (Bit 19)                                      */
#define TEST_TEST_TRIMR1_TRIM_BG_Msk      (0xff80000UL)             /*!< TRIM_BG (Bitfield-Mask: 0x1ff)                        */
#define TEST_TEST_TRIMR1_TRIM_BG          (0xff80000UL)             /*!< TRIM_BG (Bitfield-Mask: 0x1ff)                        */
#define TEST_TEST_TRIMR1_TRIM_POR_Pos     (15UL)                    /*!< TRIM_POR (Bit 15)                                     */
#define TEST_TEST_TRIMR1_TRIM_POR_Msk     (0x78000UL)               /*!< TRIM_POR (Bitfield-Mask: 0x0f)                        */
#define TEST_TEST_TRIMR1_TRIM_POR         (0x78000UL)               /*!< TRIM_POR (Bitfield-Mask: 0x0f)                        */
#define TEST_TEST_TRIMR1_TP_OUT_SEL_Pos   (12UL)                    /*!< TP_OUT_SEL (Bit 12)                                   */
#define TEST_TEST_TRIMR1_TP_OUT_SEL_Msk   (0x7000UL)                /*!< TP_OUT_SEL (Bitfield-Mask: 0x07)                      */
#define TEST_TEST_TRIMR1_TP_OUT_SEL       (0x7000UL)                /*!< TP_OUT_SEL (Bitfield-Mask: 0x07)                      */
#define TEST_TEST_TRIMR1_TRIM_VREF_Pos    (9UL)                     /*!< TRIM_VREF (Bit 9)                                     */
#define TEST_TEST_TRIMR1_TRIM_VREF_Msk    (0xe00UL)                 /*!< TRIM_VREF (Bitfield-Mask: 0x07)                       */
#define TEST_TEST_TRIMR1_TRIM_VREF        (0xe00UL)                 /*!< TRIM_VREF (Bitfield-Mask: 0x07)                       */
#define TEST_TEST_TRIMR1_TRIM_MR_Pos      (4UL)                     /*!< TRIM_MR (Bit 4)                                       */
#define TEST_TEST_TRIMR1_TRIM_MR_Msk      (0xf0UL)                  /*!< TRIM_MR (Bitfield-Mask: 0x0f)                         */
#define TEST_TEST_TRIMR1_TRIM_MR          (0xf0UL)                  /*!< TRIM_MR (Bitfield-Mask: 0x0f)                         */
#define TEST_TEST_TRIMR1_BIAS_CR_Pos      (0UL)                     /*!< BIAS_CR (Bit 0)                                       */
#define TEST_TEST_TRIMR1_BIAS_CR_Msk      (0xfUL)                   /*!< BIAS_CR (Bitfield-Mask: 0x0f)                         */
#define TEST_TEST_TRIMR1_BIAS_CR          (0xfUL)                   /*!< BIAS_CR (Bitfield-Mask: 0x0f)                         */
/* ======================================================  TEST_TRIMR2  ====================================================== */
#define TEST_TEST_TRIMR2_DIV_Pos          (31UL)                    /*!< DIV (Bit 31)                                          */
#define TEST_TEST_TRIMR2_DIV_Msk          (0x80000000UL)            /*!< DIV (Bitfield-Mask: 0x01)                             */
#define TEST_TEST_TRIMR2_DIV              (0x80000000UL)            /*!< DIV (Bitfield-Mask: 0x01)                             */
#define TEST_TEST_TRIMR2_HSI_FS_Pos       (29UL)                    /*!< HSI_FS (Bit 29)                                       */
#define TEST_TEST_TRIMR2_HSI_FS_Msk       (0x60000000UL)            /*!< HSI_FS (Bitfield-Mask: 0x03)                          */
#define TEST_TEST_TRIMR2_HSI_FS           (0x60000000UL)            /*!< HSI_FS (Bitfield-Mask: 0x03)                          */
#define TEST_TEST_TRIMR2_HSI_TRIM_Pos     (16UL)                    /*!< HSI_TRIM (Bit 16)                                     */
#define TEST_TEST_TRIMR2_HSI_TRIM_Msk     (0x3ff0000UL)             /*!< HSI_TRIM (Bitfield-Mask: 0x3ff)                       */
#define TEST_TEST_TRIMR2_HSI_TRIM         (0x3ff0000UL)             /*!< HSI_TRIM (Bitfield-Mask: 0x3ff)                       */
#define TEST_TEST_TRIMR2_LSI_TRIM_Pos     (0UL)                     /*!< LSI_TRIM (Bit 0)                                      */
#define TEST_TEST_TRIMR2_LSI_TRIM_Msk     (0x7fUL)                  /*!< LSI_TRIM (Bitfield-Mask: 0x7f)                        */
#define TEST_TEST_TRIMR2_LSI_TRIM         (0x7fUL)                  /*!< LSI_TRIM (Bitfield-Mask: 0x7f)                        */

/** @} */ /* End of group PosMask_peripherals */


/** @addtogroup EnumValue_peripherals
  * @{
  */



/* =========================================================================================================================== */
/* ================                                           FLASH                                           ================ */
/* =========================================================================================================================== */

/* ==========================================================  ACR  ========================================================== */
/* ===============================================  FLASH ACR LATENCY [0..1]  ================================================ */
#define   FLASH_ACR_LATENCY_00                 (0UL<<0)     /*!< 00 : No waiting status                                           */
#define   FLASH_ACR_LATENCY_01                 (1UL<<0)     /*!< 01 : One waiting status                                          */
#define   FLASH_ACR_LATENCY_10                 (2UL<<0)     /*!< 10 : Two waiting status                                          */
#define   FLASH_ACR_LATENCY_11                 (3UL<<0)     /*!< 11 : Reserved                                                    */

/* =========================================================  KEYR  ========================================================== */
/* ========================================================  OPTKEYR  ======================================================== */
/* ==========================================================  SR  =========================================================== */
/* ==========================================================  CR  =========================================================== */
/* =========================================================  OPTR  ========================================================== */
/* ==============================================  FLASH OPTR BOR_LEV [9..11]  =============================================== */
#define   FLASH_OPTR_BOR_LEV_000               (0UL<<9)     /*!< 000 : Rise threshold 1.8V, Decrease threshold 1.7V               */
#define   FLASH_OPTR_BOR_LEV_001               (1UL<<9)     /*!< 001 : Rise threshold 2.0V, Decrease threshold 1.9V               */
#define   FLASH_OPTR_BOR_LEV_010               (2UL<<9)     /*!< 010 : Rise threshold 2.2V, Decrease threshold 2.1V               */
#define   FLASH_OPTR_BOR_LEV_011               (3UL<<9)     /*!< 011 : Rise threshold 2.4V, Decrease threshold 2.3V               */
#define   FLASH_OPTR_BOR_LEV_100               (4UL<<9)     /*!< 100 : Rise threshold 2.6V, Decrease threshold 2.5V               */
#define   FLASH_OPTR_BOR_LEV_101               (5UL<<9)     /*!< 101 : Rise threshold 2.8V, Decrease threshold 2.7V               */
#define   FLASH_OPTR_BOR_LEV_110               (6UL<<9)     /*!< 110 : Rise threshold 3.0V, Decrease threshold 2.9V               */
#define   FLASH_OPTR_BOR_LEV_111               (7UL<<9)     /*!< 111 : Rise threshold 3.2V, Decrease threshold 3.1V               */

/* ========================================================  PCROPR  ========================================================= */
/* =========================================================  WRPR  ========================================================== */
/* =========================================================  SEQ0  ========================================================== */
/* ================================================  FLASH SEQ0 SEQ0 [0..8]  ================================================= */
#define   FLASH_SEQ0_SEQ0_16MHz                (99UL<<0)    /*!< 16MHz : 16MHz                                                    */
#define   FLASH_SEQ0_SEQ0_24MHz                (148UL<<0)   /*!< 24MHz : 24MHz                                                    */
#define   FLASH_SEQ0_SEQ0_36MHz                (223UL<<0)   /*!< 36MHz : 36MHz                                                    */

/* =========================================================  SEQ1  ========================================================== */
/* ================================================  FLASH SEQ1 SEQ1 [0..9]  ================================================= */
#define   FLASH_SEQ1_SEQ1_16MHz                (247UL<<0)   /*!< 16MHz : 16MHz                                                    */
#define   FLASH_SEQ1_SEQ1_24MHz                (371UL<<0)   /*!< 24MHz : 24MHz                                                    */
#define   FLASH_SEQ1_SEQ1_36MHz                (556UL<<0)   /*!< 36MHz : 36MHz                                                    */

/* ========================================================  SEQ2P1  ========================================================= */
/* ==============================================  FLASH SEQ2P1 SEQ2P1 [0..7]  =============================================== */
#define   FLASH_SEQ2P1_SEQ2P1_16MHz            (83UL<<0)    /*!< 16MHz : 16MHz                                                    */
#define   FLASH_SEQ2P1_SEQ2P1_24MHz            (124UL<<0)   /*!< 24MHz : 24MHz                                                    */
#define   FLASH_SEQ2P1_SEQ2P1_36MHz            (186UL<<0)   /*!< 36MHz : 36MHz                                                    */

/* ========================================================  SEQ2P3  ========================================================= */
/* ==============================================  FLASH SEQ2P3 SEQ2P3 [0..11]  ============================================== */
#define   FLASH_SEQ2P3_SEQ2P3_16MHz            (989UL<<0)   /*!< 16MHz : 16MHz                                                    */
#define   FLASH_SEQ2P3_SEQ2P3_24MHz            (1484UL<<0)  /*!< 24MHz : 24MHz                                                    */
#define   FLASH_SEQ2P3_SEQ2P3_36MHz            (2225UL<<0)  /*!< 36MHz : 36MHz                                                    */

/* =========================================================  SEQ3  ========================================================== */
/* ================================================  FLASH SEQ3 SEQ3 [0..7]  ================================================= */
#define   FLASH_SEQ3_SEQ3_16MHz                (83UL<<0)    /*!< 16MHz : 16MHz                                                    */
#define   FLASH_SEQ3_SEQ3_24MHz                (124UL<<0)   /*!< 24MHz : 24MHz                                                    */
#define   FLASH_SEQ3_SEQ3_36MHz                (186UL<<0)   /*!< 36MHz : 36MHz                                                    */

/* =====================================================  PREPG_SEQ2P2  ====================================================== */
/* ========================================  FLASH PREPG_SEQ2P2 PREPG_SEQ2P2 [0..15]  ======================================== */
#define   FLASH_PREPG_SEQ2P2_PREPG_SEQ2P2_16MHz (3296UL<<0) /*!< 16MHz : 16MHz                                                    */
#define   FLASH_PREPG_SEQ2P2_PREPG_SEQ2P2_24MHz (4944UL<<0) /*!< 24MHz : 24MHz                                                    */
#define   FLASH_PREPG_SEQ2P2_PREPG_SEQ2P2_36MHz (7416UL<<0) /*!< 36MHz : 36MHz                                                    */

/* =======================================================  PE_SEQ2P2  ======================================================= */
/* ===========================================  FLASH PE_SEQ2P2 PE_SEQ2P2 [0..16]  =========================================== */
#define   FLASH_PE_SEQ2P2_PE_SEQ2P2_16MHz      (41200UL<<0) /*!< 16MHz : 16MHz                                                    */
#define   FLASH_PE_SEQ2P2_PE_SEQ2P2_24MHz      (61800UL<<0) /*!< 24MHz : 24MHz                                                    */
#define   FLASH_PE_SEQ2P2_PE_SEQ2P2_36MHz      (92700UL<<0) /*!< 36MHz : 36MHz                                                    */

/* ======================================================  SME_SEQ2P2  ======================================================= */
/* ==========================================  FLASH SME_SEQ2P2 SME_SEQ2P2 [0..16]  ========================================== */
#define   FLASH_SME_SEQ2P2_SME_SEQ2P2_16MHz    (44496UL<<0) /*!< 16MHz : 16MHz                                                    */
#define   FLASH_SME_SEQ2P2_SME_SEQ2P2_24MHz    (66744UL<<0) /*!< 24MHz : 24MHz                                                    */
#define   FLASH_SME_SEQ2P2_SME_SEQ2P2_36MHz    (100116UL<<0)/*!< 36MHz : 36MHz                                                    */

/* =======================================================  PP_SEQ2P2  ======================================================= */
/* ===========================================  FLASH PP_SEQ2P2 PP_SEQ2P2 [0..16]  =========================================== */
#define   FLASH_PP_SEQ2P2_PP_SEQ2P2_16MHz      (24720UL<<0) /*!< 16MHz : 16MHz                                                    */
#define   FLASH_PP_SEQ2P2_PP_SEQ2P2_24MHz      (37080UL<<0) /*!< 24MHz : 24MHz                                                    */
#define   FLASH_PP_SEQ2P2_PP_SEQ2P2_36MHz      (55620UL<<0) /*!< 36MHz : 36MHz                                                    */

/* ======================================================  SMP_SEQ2P2  ======================================================= */
/* ==========================================  FLASH SMP_SEQ2P2 SME_SEQ2P2 [0..16]  ========================================== */
#define   FLASH_SMP_SEQ2P2_SME_SEQ2P2_16MHz    (28016UL<<0) /*!< 16MHz : 16MHz                                                    */
#define   FLASH_SMP_SEQ2P2_SME_SEQ2P2_24MHz    (42024UL<<0) /*!< 24MHz : 24MHz                                                    */
#define   FLASH_SMP_SEQ2P2_SME_SEQ2P2_36MHz    (63036UL<<0) /*!< 36MHz : 36MHz                                                    */



/* =========================================================================================================================== */
/* ================                                            PWR                                            ================ */
/* =========================================================================================================================== */

/* ==========================================================  CR1  ========================================================== */
/* ==========================================================  CR2  ========================================================== */
/* ===============================================  PWR CR2 FLT_TIME [9..11]  ================================================ */
#define   PWR_CR2_FLT_TIME_1                   (0UL<<9)     /*!< 1 : 30us(1 LSI or LSE clock)                                     */
#define   PWR_CR2_FLT_TIME_2                   (1UL<<9)     /*!< 2 : 60us(2 LSI or LSE clock)                                     */
#define   PWR_CR2_FLT_TIME_4                   (2UL<<9)     /*!< 4 : 120us(4 LSI or LSE clock)                                    */
#define   PWR_CR2_FLT_TIME_16                  (3UL<<9)     /*!< 16 : 480us(16 LSI or LSE clock)                                  */
#define   PWR_CR2_FLT_TIME_64                  (4UL<<9)     /*!< 64 : 1.92ms(64 LSI or LSE clock)                                 */
#define   PWR_CR2_FLT_TIME_128                 (5UL<<9)     /*!< 128 : 3.8ms(128 LSI or LSE clock)                                */
#define   PWR_CR2_FLT_TIME_1024                (6UL<<9)     /*!< 1024 : 30.7ms(1024 LSI or LSE clock)                             */

/* ==================================================  PWR CR2 PVDT [4..6]  ================================================== */
#define   PWR_CR2_PVDT_VPVD0                   (0UL<<4)     /*!< VPVD0 : around 1.8V                                              */
#define   PWR_CR2_PVDT_VPVD1                   (1UL<<4)     /*!< VPVD1 : around 2.0V                                              */
#define   PWR_CR2_PVDT_VPVD2                   (2UL<<4)     /*!< VPVD2 : around 2.2V                                              */
#define   PWR_CR2_PVDT_VPVD3                   (3UL<<4)     /*!< VPVD3 : around 2.4V                                              */
#define   PWR_CR2_PVDT_VPVD4                   (4UL<<4)     /*!< VPVD4 : around 2.6V                                              */
#define   PWR_CR2_PVDT_VPVD5                   (5UL<<4)     /*!< VPVD5 : around 2.8V                                              */
#define   PWR_CR2_PVDT_VPVD6                   (6UL<<4)     /*!< VPVD6 : around 3.0V                                              */
#define   PWR_CR2_PVDT_VPVD7                   (7UL<<4)     /*!< VPVD7 : around 3.2V                                              */

/* ==========================================================  SR  =========================================================== */


/* =========================================================================================================================== */
/* ================                                            RCC                                            ================ */
/* =========================================================================================================================== */

/* ==========================================================  CR  =========================================================== */
/* ================================================  RCC CR HSIDIV [11..13]  ================================================= */
#define   RCC_CR_HSIDIV_1                      (0UL<<11)     /*!< 1 : 1 Division                                                  */
#define   RCC_CR_HSIDIV_2                      (1UL<<11)     /*!< 2 : 2 Division                                                  */
#define   RCC_CR_HSIDIV_4                      (2UL<<11)     /*!< 4 : 4 Division                                                  */
#define   RCC_CR_HSIDIV_8                      (3UL<<11)     /*!< 8 : 8 Division                                                  */
#define   RCC_CR_HSIDIV_16                     (4UL<<11)     /*!< 16 : 16 Division                                                */
#define   RCC_CR_HSIDIV_32                     (5UL<<11)     /*!< 32 : 32 Division                                                */
#define   RCC_CR_HSIDIV_64                     (6UL<<11)     /*!< 64 : 64 Division                                                */
#define   RCC_CR_HSIDIV_128                    (7UL<<11)     /*!< 128 : 128 Division                                              */

/* =========================================================  ICSCR  ========================================================= */
/* ===============================================  RCC ICSCR HSI_FS [13..14]  =============================================== */
#define   RCC_ICSCR_HSI_FS_48Mhz               (0UL<<13)     /*!< 48Mhz : 48Mhz                                                   */
#define   RCC_ICSCR_HSI_FS_36Mhz               (1UL<<13)     /*!< 36Mhz : 36Mhz                                                   */
#define   RCC_ICSCR_HSI_FS_24Mhz               (2UL<<13)     /*!< 24Mhz : 24Mhz                                                   */
#define   RCC_ICSCR_HSI_FS_16Mhz               (3UL<<13)     /*!< 16Mhz : 16Mhz                                                   */

/* =========================================================  CFGR  ========================================================== */
/* ===============================================  RCC CFGR MCOPRE [28..30]  ================================================ */
#define   RCC_CFGR_MCOPRE_1                    (0UL<<28)     /*!< 1 : MCO 1 Division                                              */
#define   RCC_CFGR_MCOPRE_2                    (1UL<<28)     /*!< 2 : MCO 2 Division                                              */
#define   RCC_CFGR_MCOPRE_4                    (2UL<<28)     /*!< 4 : MCO 4 Division                                              */
#define   RCC_CFGR_MCOPRE_8                    (3UL<<28)     /*!< 8 : MCO 8 Division                                              */
#define   RCC_CFGR_MCOPRE_16                   (4UL<<28)     /*!< 16 : MCO 16 Division                                            */
#define   RCC_CFGR_MCOPRE_32                   (5UL<<28)     /*!< 32 : MCO 32 Division                                            */
#define   RCC_CFGR_MCOPRE_64                   (6UL<<28)     /*!< 64 : MCO 64 Division                                            */
#define   RCC_CFGR_MCOPRE_128                  (7UL<<28)     /*!< 128 : MCO 128 Division                                          */

/* ===============================================  RCC CFGR MCOSEL [24..26]  ================================================ */
#define   RCC_CFGR_MCOSEL_Noclock              (0UL<<24)     /*!< Noclock : Noclock                                               */
#define   RCC_CFGR_MCOSEL_SYSCLK               (1UL<<24)     /*!< SYSCLK : SYSCLK                                                 */
#define   RCC_CFGR_MCOSEL_HSI_10M              (2UL<<24)     /*!< HSI_10M : HSI_10M                                               */
#define   RCC_CFGR_MCOSEL_HSI                  (3UL<<24)     /*!< HSI : HSI                                                       */
#define   RCC_CFGR_MCOSEL_HSE                  (4UL<<24)     /*!< HSE : HSE                                                       */
#define   RCC_CFGR_MCOSEL_PLLCLK               (5UL<<24)     /*!< PLLCLK : PLLCLK                                                 */
#define   RCC_CFGR_MCOSEL_LSI                  (6UL<<24)     /*!< LSI : LSI                                                       */
#define   RCC_CFGR_MCOSEL_LSE                  (7UL<<24)     /*!< LSE : LSE                                                       */

/* ================================================  RCC CFGR PPRE [12..14]  ================================================= */
#define   RCC_CFGR_PPRE_1                      (0UL<<12)     /*!< 1 : 1 Division                                                  */
#define   RCC_CFGR_PPRE_2                      (4UL<<12)     /*!< 2 : 2 Division                                                  */
#define   RCC_CFGR_PPRE_4                      (5UL<<12)     /*!< 4 : 4 Division                                                  */
#define   RCC_CFGR_PPRE_8                      (6UL<<12)     /*!< 8 : 8 Division                                                  */
#define   RCC_CFGR_PPRE_16                     (7UL<<12)     /*!< 16 : 16 Division                                                */

/* =================================================  RCC CFGR HPRE [8..11]  ================================================= */
#define   RCC_CFGR_HPRE_1                      (0UL<<8)     /*!< 1 : 1 Division                                                   */
#define   RCC_CFGR_HPRE_2                      (8UL<<8)     /*!< 2 : 2 Division                                                   */
#define   RCC_CFGR_HPRE_4                      (9UL<<8)     /*!< 4 : 4 Division                                                   */
#define   RCC_CFGR_HPRE_8                      (10UL<<8)    /*!< 8 : 8 Division                                                   */
#define   RCC_CFGR_HPRE_16                     (11UL<<8)    /*!< 16 : 16 Division                                                 */
#define   RCC_CFGR_HPRE_64                     (12UL<<8)    /*!< 64 : 64 Division                                                 */
#define   RCC_CFGR_HPRE_128                    (13UL<<8)    /*!< 128 : 128 Division                                               */
#define   RCC_CFGR_HPRE_256                    (14UL<<8)    /*!< 256 : 256 Division                                               */
#define   RCC_CFGR_HPRE_512                    (15UL<<8)    /*!< 512 : 512 Division                                               */

/* ==================================================  RCC CFGR SWS [3..5]  ================================================== */
#define   RCC_CFGR_SWS_HSISYS                  (0UL<<3)     /*!< HSISYS : HSISYS                                                  */
#define   RCC_CFGR_SWS_HSE                     (1UL<<3)     /*!< HSE : HSE                                                        */
#define   RCC_CFGR_SWS_PLLCLK                  (2UL<<3)     /*!< PLLCLK : PLLCLK                                                  */
#define   RCC_CFGR_SWS_LSI                     (3UL<<3)     /*!< LSI : LSI                                                        */
#define   RCC_CFGR_SWS_LSE                     (4UL<<3)     /*!< LSE : LSE                                                        */

/* ==================================================  RCC CFGR SW [0..2]  =================================================== */
#define   RCC_CFGR_SW_HSISYS                   (0UL<<0)     /*!< HSISYS : HSISYS                                                  */
#define   RCC_CFGR_SW_HSE                      (1UL<<0)     /*!< HSE : HSE                                                        */
#define   RCC_CFGR_SW_PLLCLK                   (2UL<<0)     /*!< PLLCLK : PLLCLK                                                  */
#define   RCC_CFGR_SW_LSI                      (3UL<<0)     /*!< LSI : LSI                                                        */
#define   RCC_CFGR_SW_LSE                      (4UL<<0)     /*!< LSE : LSE                                                        */

/* ========================================================  PLLCFGR  ======================================================== */
/* =========================================================  ECSCR  ========================================================= */
/* =============================================  RCC ECSCR LSE_DRIVER [16..17]  ============================================= */
#define   RCC_ECSCR_LSE_DRIVER_00              (0UL<<16)     /*!< 00 : LSE OFF                                                    */
#define   RCC_ECSCR_LSE_DRIVER_01              (1UL<<16)     /*!< 01 : Weak                                                       */
#define   RCC_ECSCR_LSE_DRIVER_10              (2UL<<16)     /*!< 10 : Default                                                    */
#define   RCC_ECSCR_LSE_DRIVER_11              (3UL<<16)     /*!< 11 : Strong                                                     */

/* ===============================================  RCC ECSCR HSE_FREQ [2..3]  =============================================== */
#define   RCC_ECSCR_HSE_FREQ_00                (0UL<<2)     /*!< 00 : 00                                                          */
#define   RCC_ECSCR_HSE_FREQ_4MHz8MHz          (1UL<<2)     /*!< 4MHz8MHz : 4MHz8MHz                                              */
#define   RCC_ECSCR_HSE_FREQ_8MHz16MHz         (2UL<<2)     /*!< 8MHz16MHz : 8MHz16MHz                                            */
#define   RCC_ECSCR_HSE_FREQ_16MHz32MHz        (3UL<<2)     /*!< 16MHz32MHz : 16MHz32MHz                                          */

/* =========================================================  CIER  ========================================================== */
/* =========================================================  CIFR  ========================================================== */
/* =========================================================  CICR  ========================================================== */
/* ========================================================  IOPRSTR  ======================================================== */
/* ========================================================  AHBRSTR  ======================================================== */
/* =======================================================  APBRSTR1  ======================================================== */
/* =======================================================  APBRSTR2  ======================================================== */
/* ========================================================  IOPENR  ========================================================= */
/* ========================================================  AHBENR  ========================================================= */
/* ========================================================  APBENR1  ======================================================== */
/* ========================================================  APBENR2  ======================================================== */
/* =========================================================  CCIPR  ========================================================= */
/* ==============================================  RCC CCIPR LPTIMSEL [18..19]  ============================================== */
#define   RCC_CCIPR_LPTIMSEL_PCLK              (0UL<<18)     /*!< PCLK : PCLK                                                     */
#define   RCC_CCIPR_LPTIMSEL_LSI               (1UL<<18)     /*!< LSI : LSI                                                       */
#define   RCC_CCIPR_LPTIMSEL_Noclock           (2UL<<18)     /*!< Noclock : Noclock                                               */
#define   RCC_CCIPR_LPTIMSEL_LSE               (3UL<<18)     /*!< LSE : LSE                                                       */

/* =========================================================  BDCR  ========================================================== */
/* ================================================  RCC BDCR RTCSEL [8..9]  ================================================= */
#define   RCC_BDCR_RTCSEL_Noclock              (0UL<<8)     /*!< Noclock : Noclock                                                */
#define   RCC_BDCR_RTCSEL_LSE                  (1UL<<8)     /*!< LSE : LSE                                                        */
#define   RCC_BDCR_RTCSEL_LSI                  (2UL<<8)     /*!< LSI : LSI                                                        */
#define   RCC_BDCR_RTCSEL_HSEdividedby128      (3UL<<8)     /*!< HSEdividedby128 : HSEdividedby128                                */

/* ==========================================================  CSR  ========================================================== */
/* =======================================================  MRTRIM_CR  ======================================================= */


/* =========================================================================================================================== */
/* ================                                           GPIOA                                           ================ */
/* =========================================================================================================================== */

/* =========================================================  MODER  ========================================================= */
/* ==============================================  GPIOA MODER MODE15 [30..31]  ============================================== */
#define   GPIO_MODER_MODE15_Input             (0UL<<30)     /*!< Input : Input                                                   */
#define   GPIO_MODER_MODE15_Output            (1UL<<30)     /*!< Output : Output                                                 */
#define   GPIO_MODER_MODE15_Alternate         (2UL<<30)     /*!< Alternate : Alternate                                           */
#define   GPIO_MODER_MODE15_Analog            (3UL<<30)     /*!< Analog : Analog                                                 */

/* ==============================================  GPIOA MODER MODE14 [28..29]  ============================================== */
#define   GPIO_MODER_MODE14_Input             (0UL<<28)     /*!< Input : Input                                                   */
#define   GPIO_MODER_MODE14_Output            (1UL<<28)     /*!< Output : Output                                                 */
#define   GPIO_MODER_MODE14_Alternate         (2UL<<28)     /*!< Alternate : Alternate                                           */
#define   GPIO_MODER_MODE14_Analog            (3UL<<28)     /*!< Analog : Analog                                                 */

/* ==============================================  GPIOA MODER MODE13 [26..27]  ============================================== */
#define   GPIO_MODER_MODE13_Input             (0UL<<26)     /*!< Input : Input                                                   */
#define   GPIO_MODER_MODE13_Output            (1UL<<26)     /*!< Output : Output                                                 */
#define   GPIO_MODER_MODE13_Alternate         (2UL<<26)     /*!< Alternate : Alternate                                           */
#define   GPIO_MODER_MODE13_Analog            (3UL<<26)     /*!< Analog : Analog                                                 */

/* ==============================================  GPIOA MODER MODE12 [24..25]  ============================================== */
#define   GPIO_MODER_MODE12_Input             (0UL<<24)     /*!< Input : Input                                                   */
#define   GPIO_MODER_MODE12_Output            (1UL<<24)     /*!< Output : Output                                                 */
#define   GPIO_MODER_MODE12_Alternate         (2UL<<24)     /*!< Alternate : Alternate                                           */
#define   GPIO_MODER_MODE12_Analog            (3UL<<24)     /*!< Analog : Analog                                                 */

/* ==============================================  GPIOA MODER MODE11 [22..23]  ============================================== */
#define   GPIO_MODER_MODE11_Input             (0UL<<22)     /*!< Input : Input                                                   */
#define   GPIO_MODER_MODE11_Output            (1UL<<22)     /*!< Output : Output                                                 */
#define   GPIO_MODER_MODE11_Alternate         (2UL<<22)     /*!< Alternate : Alternate                                           */
#define   GPIO_MODER_MODE11_Analog            (3UL<<22)     /*!< Analog : Analog                                                 */

/* ==============================================  GPIOA MODER MODE10 [20..21]  ============================================== */
#define   GPIO_MODER_MODE10_Input             (0UL<<20)     /*!< Input : Input                                                   */
#define   GPIO_MODER_MODE10_Output            (1UL<<20)     /*!< Output : Output                                                 */
#define   GPIO_MODER_MODE10_Alternate         (2UL<<20)     /*!< Alternate : Alternate                                           */
#define   GPIO_MODER_MODE10_Analog            (3UL<<20)     /*!< Analog : Analog                                                 */

/* ==============================================  GPIOA MODER MODE9 [18..19]  =============================================== */
#define   GPIO_MODER_MODE9_Input              (0UL<<18)     /*!< Input : Input                                                   */
#define   GPIO_MODER_MODE9_Output             (1UL<<18)     /*!< Output : Output                                                 */
#define   GPIO_MODER_MODE9_Alternate          (2UL<<18)     /*!< Alternate : Alternate                                           */
#define   GPIO_MODER_MODE9_Analog             (3UL<<18)     /*!< Analog : Analog                                                 */

/* ==============================================  GPIOA MODER MODE8 [16..17]  =============================================== */
#define   GPIO_MODER_MODE8_Input              (0UL<<16)     /*!< Input : Input                                                   */
#define   GPIO_MODER_MODE8_Output             (1UL<<16)     /*!< Output : Output                                                 */
#define   GPIO_MODER_MODE8_Alternate          (2UL<<16)     /*!< Alternate : Alternate                                           */
#define   GPIO_MODER_MODE8_Analog             (3UL<<16)     /*!< Analog : Analog                                                 */

/* ==============================================  GPIOA MODER MODE7 [14..15]  =============================================== */
#define   GPIO_MODER_MODE7_Input              (0UL<<14)     /*!< Input : Input                                                   */
#define   GPIO_MODER_MODE7_Output             (1UL<<14)     /*!< Output : Output                                                 */
#define   GPIO_MODER_MODE7_Alternate          (2UL<<14)     /*!< Alternate : Alternate                                           */
#define   GPIO_MODER_MODE7_Analog             (3UL<<14)     /*!< Analog : Analog                                                 */

/* ==============================================  GPIOA MODER MODE6 [12..13]  =============================================== */
#define   GPIO_MODER_MODE6_Input              (0UL<<12)     /*!< Input : Input                                                   */
#define   GPIO_MODER_MODE6_Output             (1UL<<12)     /*!< Output : Output                                                 */
#define   GPIO_MODER_MODE6_Alternate          (2UL<<12)     /*!< Alternate : Alternate                                           */
#define   GPIO_MODER_MODE6_Analog             (3UL<<12)     /*!< Analog : Analog                                                 */

/* ==============================================  GPIOA MODER MODE5 [10..11]  =============================================== */
#define   GPIO_MODER_MODE5_Input              (0UL<<10)     /*!< Input : Input                                                   */
#define   GPIO_MODER_MODE5_Output             (1UL<<10)     /*!< Output : Output                                                 */
#define   GPIO_MODER_MODE5_Alternate          (2UL<<10)     /*!< Alternate : Alternate                                           */
#define   GPIO_MODER_MODE5_Analog             (3UL<<10)     /*!< Analog : Analog                                                 */

/* ===============================================  GPIOA MODER MODE4 [8..9]  ================================================ */
#define   GPIO_MODER_MODE4_Input              (0UL<<8)     /*!< Input : Input                                                    */
#define   GPIO_MODER_MODE4_Output             (1UL<<8)     /*!< Output : Output                                                  */
#define   GPIO_MODER_MODE4_Alternate          (2UL<<8)     /*!< Alternate : Alternate                                            */
#define   GPIO_MODER_MODE4_Analog             (3UL<<8)     /*!< Analog : Analog                                                  */

/* ===============================================  GPIOA MODER MODE3 [6..7]  ================================================ */
#define   GPIO_MODER_MODE3_Input              (0UL<<6)     /*!< Input : Input                                                    */
#define   GPIO_MODER_MODE3_Output             (1UL<<6)     /*!< Output : Output                                                  */
#define   GPIO_MODER_MODE3_Alternate          (2UL<<6)     /*!< Alternate : Alternate                                            */
#define   GPIO_MODER_MODE3_Analog             (3UL<<6)     /*!< Analog : Analog                                                  */

/* ===============================================  GPIOA MODER MODE2 [4..5]  ================================================ */
#define   GPIO_MODER_MODE2_Input              (0UL<<4)     /*!< Input : Input                                                    */
#define   GPIO_MODER_MODE2_Output             (1UL<<4)     /*!< Output : Output                                                  */
#define   GPIO_MODER_MODE2_Alternate          (2UL<<4)     /*!< Alternate : Alternate                                            */
#define   GPIO_MODER_MODE2_Analog             (3UL<<4)     /*!< Analog : Analog                                                  */

/* ===============================================  GPIOA MODER MODE1 [2..3]  ================================================ */
#define   GPIO_MODER_MODE1_Input              (0UL<<2)     /*!< Input : Input                                                    */
#define   GPIO_MODER_MODE1_Output             (1UL<<2)     /*!< Output : Output                                                  */
#define   GPIO_MODER_MODE1_Alternate          (2UL<<2)     /*!< Alternate : Alternate                                            */
#define   GPIO_MODER_MODE1_Analog             (3UL<<2)     /*!< Analog : Analog                                                  */

/* ===============================================  GPIOA MODER MODE0 [0..1]  ================================================ */
#define   GPIO_MODER_MODE0_Input              (0UL<<0)     /*!< Input : Input                                                    */
#define   GPIO_MODER_MODE0_Output             (1UL<<0)     /*!< Output : Output                                                  */
#define   GPIO_MODER_MODE0_Alternate          (2UL<<0)     /*!< Alternate : Alternate                                            */
#define   GPIO_MODER_MODE0_Analog             (3UL<<0)     /*!< Analog : Analog                                                  */

/* ========================================================  OTYPER  ========================================================= */
/* ========================================================  OSPEEDR  ======================================================== */
/* ============================================  GPIOA OSPEEDR OSPEED15 [30..31]  ============================================ */
#define   GPIO_OSPEEDR_OSPEED15_VeryLow       (0UL<<30)     /*!< VeryLow : VeryLow                                               */
#define   GPIO_OSPEEDR_OSPEED15_Low           (1UL<<30)     /*!< Low : Low                                                       */
#define   GPIO_OSPEEDR_OSPEED15_High          (2UL<<30)     /*!< High : High                                                     */
#define   GPIO_OSPEEDR_OSPEED15_VeryHigh      (3UL<<30)     /*!< VeryHigh : VeryHigh                                             */

/* ============================================  GPIOA OSPEEDR OSPEED14 [28..29]  ============================================ */
#define   GPIO_OSPEEDR_OSPEED14_VeryLow       (0UL<<28)     /*!< VeryLow : VeryLow                                               */
#define   GPIO_OSPEEDR_OSPEED14_Low           (1UL<<28)     /*!< Low : Low                                                       */
#define   GPIO_OSPEEDR_OSPEED14_High          (2UL<<28)     /*!< High : High                                                     */
#define   GPIO_OSPEEDR_OSPEED14_VeryHigh      (3UL<<28)     /*!< VeryHigh : VeryHigh                                             */

/* ============================================  GPIOA OSPEEDR OSPEED13 [26..27]  ============================================ */
#define   GPIO_OSPEEDR_OSPEED13_VeryLow       (0UL<<26)     /*!< VeryLow : VeryLow                                               */
#define   GPIO_OSPEEDR_OSPEED13_Low           (1UL<<26)     /*!< Low : Low                                                       */
#define   GPIO_OSPEEDR_OSPEED13_High          (2UL<<26)     /*!< High : High                                                     */
#define   GPIO_OSPEEDR_OSPEED13_VeryHigh      (3UL<<26)     /*!< VeryHigh : VeryHigh                                             */

/* ============================================  GPIOA OSPEEDR OSPEED12 [24..25]  ============================================ */
#define   GPIO_OSPEEDR_OSPEED12_VeryLow       (0UL<<24)     /*!< VeryLow : VeryLow                                               */
#define   GPIO_OSPEEDR_OSPEED12_Low           (1UL<<24)     /*!< Low : Low                                                       */
#define   GPIO_OSPEEDR_OSPEED12_High          (2UL<<24)     /*!< High : High                                                     */
#define   GPIO_OSPEEDR_OSPEED12_VeryHigh      (3UL<<24)     /*!< VeryHigh : VeryHigh                                             */

/* ============================================  GPIOA OSPEEDR OSPEED11 [22..23]  ============================================ */
#define   GPIO_OSPEEDR_OSPEED11_VeryLow       (0UL<<22)     /*!< VeryLow : VeryLow                                               */
#define   GPIO_OSPEEDR_OSPEED11_Low           (1UL<<22)     /*!< Low : Low                                                       */
#define   GPIO_OSPEEDR_OSPEED11_High          (2UL<<22)     /*!< High : High                                                     */
#define   GPIO_OSPEEDR_OSPEED11_VeryHigh      (3UL<<22)     /*!< VeryHigh : VeryHigh                                             */

/* ============================================  GPIOA OSPEEDR OSPEED10 [20..21]  ============================================ */
#define   GPIO_OSPEEDR_OSPEED10_VeryLow       (0UL<<20)     /*!< VeryLow : VeryLow                                               */
#define   GPIO_OSPEEDR_OSPEED10_Low           (1UL<<20)     /*!< Low : Low                                                       */
#define   GPIO_OSPEEDR_OSPEED10_High          (2UL<<20)     /*!< High : High                                                     */
#define   GPIO_OSPEEDR_OSPEED10_VeryHigh      (3UL<<20)     /*!< VeryHigh : VeryHigh                                             */

/* ============================================  GPIOA OSPEEDR OSPEED9 [18..19]  ============================================= */
#define   GPIO_OSPEEDR_OSPEED9_VeryLow        (0UL<<18)     /*!< VeryLow : VeryLow                                               */
#define   GPIO_OSPEEDR_OSPEED9_Low            (1UL<<18)     /*!< Low : Low                                                       */
#define   GPIO_OSPEEDR_OSPEED9_High           (2UL<<18)     /*!< High : High                                                     */
#define   GPIO_OSPEEDR_OSPEED9_VeryHigh       (3UL<<18)     /*!< VeryHigh : VeryHigh                                             */

/* ============================================  GPIOA OSPEEDR OSPEED8 [16..17]  ============================================= */
#define   GPIO_OSPEEDR_OSPEED8_VeryLow        (0UL<<16)     /*!< VeryLow : VeryLow                                               */
#define   GPIO_OSPEEDR_OSPEED8_Low            (1UL<<16)     /*!< Low : Low                                                       */
#define   GPIO_OSPEEDR_OSPEED8_High           (2UL<<16)     /*!< High : High                                                     */
#define   GPIO_OSPEEDR_OSPEED8_VeryHigh       (3UL<<16)     /*!< VeryHigh : VeryHigh                                             */

/* ============================================  GPIOA OSPEEDR OSPEED7 [14..15]  ============================================= */
#define   GPIO_OSPEEDR_OSPEED7_VeryLow        (0UL<<14)     /*!< VeryLow : VeryLow                                               */
#define   GPIO_OSPEEDR_OSPEED7_Low            (1UL<<14)     /*!< Low : Low                                                       */
#define   GPIO_OSPEEDR_OSPEED7_High           (2UL<<14)     /*!< High : High                                                     */
#define   GPIO_OSPEEDR_OSPEED7_VeryHigh       (3UL<<14)     /*!< VeryHigh : VeryHigh                                             */

/* ============================================  GPIOA OSPEEDR OSPEED6 [12..13]  ============================================= */
#define   GPIO_OSPEEDR_OSPEED6_VeryLow        (0UL<<12)     /*!< VeryLow : VeryLow                                               */
#define   GPIO_OSPEEDR_OSPEED6_Low            (1UL<<12)     /*!< Low : Low                                                       */
#define   GPIO_OSPEEDR_OSPEED6_High           (2UL<<12)     /*!< High : High                                                     */
#define   GPIO_OSPEEDR_OSPEED6_VeryHigh       (3UL<<12)     /*!< VeryHigh : VeryHigh                                             */

/* ============================================  GPIOA OSPEEDR OSPEED5 [10..11]  ============================================= */
#define   GPIO_OSPEEDR_OSPEED5_VeryLow        (0UL<<10)     /*!< VeryLow : VeryLow                                               */
#define   GPIO_OSPEEDR_OSPEED5_Low            (1UL<<10)     /*!< Low : Low                                                       */
#define   GPIO_OSPEEDR_OSPEED5_High           (2UL<<10)     /*!< High : High                                                     */
#define   GPIO_OSPEEDR_OSPEED5_VeryHigh       (3UL<<10)     /*!< VeryHigh : VeryHigh                                             */

/* =============================================  GPIOA OSPEEDR OSPEED4 [8..9]  ============================================== */
#define   GPIO_OSPEEDR_OSPEED4_VeryLow        (0UL<<8)     /*!< VeryLow : VeryLow                                                */
#define   GPIO_OSPEEDR_OSPEED4_Low            (1UL<<8)     /*!< Low : Low                                                        */
#define   GPIO_OSPEEDR_OSPEED4_High           (2UL<<8)     /*!< High : High                                                      */
#define   GPIO_OSPEEDR_OSPEED4_VeryHigh       (3UL<<8)     /*!< VeryHigh : VeryHigh                                              */

/* =============================================  GPIOA OSPEEDR OSPEED3 [6..7]  ============================================== */
#define   GPIO_OSPEEDR_OSPEED3_VeryLow        (0UL<<6)     /*!< VeryLow : VeryLow                                                */
#define   GPIO_OSPEEDR_OSPEED3_Low            (1UL<<6)     /*!< Low : Low                                                        */
#define   GPIO_OSPEEDR_OSPEED3_High           (2UL<<6)     /*!< High : High                                                      */
#define   GPIO_OSPEEDR_OSPEED3_VeryHigh       (3UL<<6)     /*!< VeryHigh : VeryHigh                                              */

/* =============================================  GPIOA OSPEEDR OSPEED2 [4..5]  ============================================== */
#define   GPIO_OSPEEDR_OSPEED2_VeryLow        (0UL<<4)     /*!< VeryLow : VeryLow                                                */
#define   GPIO_OSPEEDR_OSPEED2_Low            (1UL<<4)     /*!< Low : Low                                                        */
#define   GPIO_OSPEEDR_OSPEED2_High           (2UL<<4)     /*!< High : High                                                      */
#define   GPIO_OSPEEDR_OSPEED2_VeryHigh       (3UL<<4)     /*!< VeryHigh : VeryHigh                                              */

/* =============================================  GPIOA OSPEEDR OSPEED1 [2..3]  ============================================== */
#define   GPIO_OSPEEDR_OSPEED1_VeryLow        (0UL<<2)     /*!< VeryLow : VeryLow                                                */
#define   GPIO_OSPEEDR_OSPEED1_Low            (1UL<<2)     /*!< Low : Low                                                        */
#define   GPIO_OSPEEDR_OSPEED1_High           (2UL<<2)     /*!< High : High                                                      */
#define   GPIO_OSPEEDR_OSPEED1_VeryHigh       (3UL<<2)     /*!< VeryHigh : VeryHigh                                              */

/* =============================================  GPIOA OSPEEDR OSPEED0 [0..1]  ============================================== */
#define   GPIO_OSPEEDR_OSPEED0_VeryLow        (0UL<<0)     /*!< VeryLow : VeryLow                                                */
#define   GPIO_OSPEEDR_OSPEED0_Low            (1UL<<0)     /*!< Low : Low                                                        */
#define   GPIO_OSPEEDR_OSPEED0_High           (2UL<<0)     /*!< High : High                                                      */
#define   GPIO_OSPEEDR_OSPEED0_VeryHigh       (3UL<<0)     /*!< VeryHigh : VeryHigh                                              */

/* =========================================================  PUPDR  ========================================================= */
/* ==============================================  GPIOA PUPDR PUPD15 [30..31]  ============================================== */
#define   GPIO_PUPDR_PUPD15_None              (0UL<<30)     /*!< None : None                                                     */
#define   GPIO_PUPDR_PUPD15_Up                (1UL<<30)     /*!< Up : Up                                                         */
#define   GPIO_PUPDR_PUPD15_Down              (2UL<<30)     /*!< Down : Down                                                     */
#define   GPIO_PUPDR_PUPD15_Reserve           (3UL<<30)     /*!< Reserve : Reserve                                               */

/* ==============================================  GPIOA PUPDR PUPD14 [28..29]  ============================================== */
#define   GPIO_PUPDR_PUPD14_None              (0UL<<28)     /*!< None : None                                                     */
#define   GPIO_PUPDR_PUPD14_Up                (1UL<<28)     /*!< Up : Up                                                         */
#define   GPIO_PUPDR_PUPD14_Down              (2UL<<28)     /*!< Down : Down                                                     */
#define   GPIO_PUPDR_PUPD14_Reserve           (3UL<<28)     /*!< Reserve : Reserve                                               */

/* ==============================================  GPIOA PUPDR PUPD13 [26..27]  ============================================== */
#define   GPIO_PUPDR_PUPD13_None              (0UL<<26)     /*!< None : None                                                     */
#define   GPIO_PUPDR_PUPD13_Up                (1UL<<26)     /*!< Up : Up                                                         */
#define   GPIO_PUPDR_PUPD13_Down              (2UL<<26)     /*!< Down : Down                                                     */
#define   GPIO_PUPDR_PUPD13_Reserve           (3UL<<26)     /*!< Reserve : Reserve                                               */

/* ==============================================  GPIOA PUPDR PUPD12 [24..25]  ============================================== */
#define   GPIO_PUPDR_PUPD12_None              (0UL<<24)     /*!< None : None                                                     */
#define   GPIO_PUPDR_PUPD12_Up                (1UL<<24)     /*!< Up : Up                                                         */
#define   GPIO_PUPDR_PUPD12_Down              (2UL<<24)     /*!< Down : Down                                                     */
#define   GPIO_PUPDR_PUPD12_Reserve           (3UL<<24)     /*!< Reserve : Reserve                                               */

/* ==============================================  GPIOA PUPDR PUPD11 [22..23]  ============================================== */
#define   GPIO_PUPDR_PUPD11_None              (0UL<<22)     /*!< None : None                                                     */
#define   GPIO_PUPDR_PUPD11_Up                (1UL<<22)     /*!< Up : Up                                                         */
#define   GPIO_PUPDR_PUPD11_Down              (2UL<<22)     /*!< Down : Down                                                     */
#define   GPIO_PUPDR_PUPD11_Reserve           (3UL<<22)     /*!< Reserve : Reserve                                               */

/* ==============================================  GPIOA PUPDR PUPD10 [20..21]  ============================================== */
#define   GPIO_PUPDR_PUPD10_None              (0UL<<20)     /*!< None : None                                                     */
#define   GPIO_PUPDR_PUPD10_Up                (1UL<<20)     /*!< Up : Up                                                         */
#define   GPIO_PUPDR_PUPD10_Down              (2UL<<20)     /*!< Down : Down                                                     */
#define   GPIO_PUPDR_PUPD10_Reserve           (3UL<<20)     /*!< Reserve : Reserve                                               */

/* ==============================================  GPIOA PUPDR PUPD9 [18..19]  =============================================== */
#define   GPIO_PUPDR_PUPD9_None               (0UL<<18)     /*!< None : None                                                     */
#define   GPIO_PUPDR_PUPD9_Up                 (1UL<<18)     /*!< Up : Up                                                         */
#define   GPIO_PUPDR_PUPD9_Down               (2UL<<18)     /*!< Down : Down                                                     */
#define   GPIO_PUPDR_PUPD9_Reserve            (3UL<<18)     /*!< Reserve : Reserve                                               */

/* ==============================================  GPIOA PUPDR PUPD8 [16..17]  =============================================== */
#define   GPIO_PUPDR_PUPD8_None               (0UL<<16)     /*!< None : None                                                     */
#define   GPIO_PUPDR_PUPD8_Up                 (1UL<<16)     /*!< Up : Up                                                         */
#define   GPIO_PUPDR_PUPD8_Down               (2UL<<16)     /*!< Down : Down                                                     */
#define   GPIO_PUPDR_PUPD8_Reserve            (3UL<<16)     /*!< Reserve : Reserve                                               */

/* ==============================================  GPIOA PUPDR PUPD7 [14..15]  =============================================== */
#define   GPIO_PUPDR_PUPD7_None               (0UL<<14)     /*!< None : None                                                     */
#define   GPIO_PUPDR_PUPD7_Up                 (1UL<<14)     /*!< Up : Up                                                         */
#define   GPIO_PUPDR_PUPD7_Down               (2UL<<14)     /*!< Down : Down                                                     */
#define   GPIO_PUPDR_PUPD7_Reserve            (3UL<<14)     /*!< Reserve : Reserve                                               */

/* ==============================================  GPIOA PUPDR PUPD6 [12..13]  =============================================== */
#define   GPIO_PUPDR_PUPD6_None               (0UL<<12)     /*!< None : None                                                     */
#define   GPIO_PUPDR_PUPD6_Up                 (1UL<<12)     /*!< Up : Up                                                         */
#define   GPIO_PUPDR_PUPD6_Down               (2UL<<12)     /*!< Down : Down                                                     */
#define   GPIO_PUPDR_PUPD6_Reserve            (3UL<<12)     /*!< Reserve : Reserve                                               */

/* ==============================================  GPIOA PUPDR PUPD5 [10..11]  =============================================== */
#define   GPIO_PUPDR_PUPD5_None               (0UL<<10)     /*!< None : None                                                     */
#define   GPIO_PUPDR_PUPD5_Up                 (1UL<<10)     /*!< Up : Up                                                         */
#define   GPIO_PUPDR_PUPD5_Down               (2UL<<10)     /*!< Down : Down                                                     */
#define   GPIO_PUPDR_PUPD5_Reserve            (3UL<<10)     /*!< Reserve : Reserve                                               */

/* ===============================================  GPIOA PUPDR PUPD4 [8..9]  ================================================ */
#define   GPIO_PUPDR_PUPD4_None               (0UL<<8)     /*!< None : None                                                      */
#define   GPIO_PUPDR_PUPD4_Up                 (1UL<<8)     /*!< Up : Up                                                          */
#define   GPIO_PUPDR_PUPD4_Down               (2UL<<8)     /*!< Down : Down                                                      */
#define   GPIO_PUPDR_PUPD4_Reserve            (3UL<<8)     /*!< Reserve : Reserve                                                */

/* ===============================================  GPIOA PUPDR PUPD3 [6..7]  ================================================ */
#define   GPIO_PUPDR_PUPD3_None               (0UL<<6)     /*!< None : None                                                      */
#define   GPIO_PUPDR_PUPD3_Up                 (1UL<<6)     /*!< Up : Up                                                          */
#define   GPIO_PUPDR_PUPD3_Down               (2UL<<6)     /*!< Down : Down                                                      */
#define   GPIO_PUPDR_PUPD3_Reserve            (3UL<<6)     /*!< Reserve : Reserve                                                */

/* ===============================================  GPIOA PUPDR PUPD2 [4..5]  ================================================ */
#define   GPIO_PUPDR_PUPD2_None               (0UL<<4)     /*!< None : None                                                      */
#define   GPIO_PUPDR_PUPD2_Up                 (1UL<<4)     /*!< Up : Up                                                          */
#define   GPIO_PUPDR_PUPD2_Down               (2UL<<4)     /*!< Down : Down                                                      */
#define   GPIO_PUPDR_PUPD2_Reserve            (3UL<<4)     /*!< Reserve : Reserve                                                */

/* ===============================================  GPIOA PUPDR PUPD1 [2..3]  ================================================ */
#define   GPIO_PUPDR_PUPD1_None               (0UL<<2)     /*!< None : None                                                      */
#define   GPIO_PUPDR_PUPD1_Up                 (1UL<<2)     /*!< Up : Up                                                          */
#define   GPIO_PUPDR_PUPD1_Down               (2UL<<2)     /*!< Down : Down                                                      */
#define   GPIO_PUPDR_PUPD1_Reserve            (3UL<<2)     /*!< Reserve : Reserve                                                */

/* ===============================================  GPIOA PUPDR PUPD0 [0..1]  ================================================ */
#define   GPIO_PUPDR_PUPD0_None               (0UL<<0)     /*!< None : None                                                      */
#define   GPIO_PUPDR_PUPD0_Up                 (1UL<<0)     /*!< Up : Up                                                          */
#define   GPIO_PUPDR_PUPD0_Down               (2UL<<0)     /*!< Down : Down                                                      */
#define   GPIO_PUPDR_PUPD0_Reserve            (3UL<<0)     /*!< Reserve : Reserve                                                */

/* ==========================================================  IDR  ========================================================== */
/* ==========================================================  ODR  ========================================================== */
/* =========================================================  BSRR  ========================================================== */
/* =========================================================  LCKR  ========================================================== */
/* =========================================================  AFRL  ========================================================== */
/* ==============================================  GPIOA AFRL AFSEL7 [28..31]  =============================================== */
#define   GPIO_AFRL_AFSEL7_AF0                (0UL<<28)     /*!< AF0 : AF0                                                       */
#define   GPIO_AFRL_AFSEL7_AF1                (1UL<<28)     /*!< AF1 : AF1                                                       */
#define   GPIO_AFRL_AFSEL7_AF2                (2UL<<28)     /*!< AF2 : AF2                                                       */
#define   GPIO_AFRL_AFSEL7_AF3                (3UL<<28)     /*!< AF3 : AF3                                                       */
#define   GPIO_AFRL_AFSEL7_AF4                (4UL<<28)     /*!< AF4 : AF4                                                       */
#define   GPIO_AFRL_AFSEL7_AF5                (5UL<<28)     /*!< AF5 : AF5                                                       */
#define   GPIO_AFRL_AFSEL7_AF6                (6UL<<28)     /*!< AF6 : AF6                                                       */
#define   GPIO_AFRL_AFSEL7_AF7                (7UL<<28)     /*!< AF7 : AF7                                                       */
#define   GPIO_AFRL_AFSEL7_AF8                (8UL<<28)     /*!< AF8 : AF8                                                       */
#define   GPIO_AFRL_AFSEL7_AF9                (9UL<<28)     /*!< AF9 : AF9                                                       */
#define   GPIO_AFRL_AFSEL7_AF10               (10UL<<28)    /*!< AF10 : AF10                                                     */
#define   GPIO_AFRL_AFSEL7_AF11               (11UL<<28)    /*!< AF11 : AF11                                                     */
#define   GPIO_AFRL_AFSEL7_AF12               (12UL<<28)    /*!< AF12 : AF12                                                     */
#define   GPIO_AFRL_AFSEL7_AF13               (13UL<<28)    /*!< AF13 : AF13                                                     */
#define   GPIO_AFRL_AFSEL7_AF14               (14UL<<28)    /*!< AF14 : AF14                                                     */
#define   GPIO_AFRL_AFSEL7_AF15               (15UL<<28)    /*!< AF15 : AF15                                                     */

/* ==============================================  GPIOA AFRL AFSEL6 [24..27]  =============================================== */
#define   GPIO_AFRL_AFSEL6_AF0                (0UL<<24)     /*!< AF0 : AF0                                                       */
#define   GPIO_AFRL_AFSEL6_AF1                (1UL<<24)     /*!< AF1 : AF1                                                       */
#define   GPIO_AFRL_AFSEL6_AF2                (2UL<<24)     /*!< AF2 : AF2                                                       */
#define   GPIO_AFRL_AFSEL6_AF3                (3UL<<24)     /*!< AF3 : AF3                                                       */
#define   GPIO_AFRL_AFSEL6_AF4                (4UL<<24)     /*!< AF4 : AF4                                                       */
#define   GPIO_AFRL_AFSEL6_AF5                (5UL<<24)     /*!< AF5 : AF5                                                       */
#define   GPIO_AFRL_AFSEL6_AF6                (6UL<<24)     /*!< AF6 : AF6                                                       */
#define   GPIO_AFRL_AFSEL6_AF7                (7UL<<24)     /*!< AF7 : AF7                                                       */
#define   GPIO_AFRL_AFSEL6_AF8                (8UL<<24)     /*!< AF8 : AF8                                                       */
#define   GPIO_AFRL_AFSEL6_AF9                (9UL<<24)     /*!< AF9 : AF9                                                       */
#define   GPIO_AFRL_AFSEL6_AF10               (10UL<<24)    /*!< AF10 : AF10                                                     */
#define   GPIO_AFRL_AFSEL6_AF11               (11UL<<24)    /*!< AF11 : AF11                                                     */
#define   GPIO_AFRL_AFSEL6_AF12               (12UL<<24)    /*!< AF12 : AF12                                                     */
#define   GPIO_AFRL_AFSEL6_AF13               (13UL<<24)    /*!< AF13 : AF13                                                     */
#define   GPIO_AFRL_AFSEL6_AF14               (14UL<<24)    /*!< AF14 : AF14                                                     */
#define   GPIO_AFRL_AFSEL6_AF15               (15UL<<24)    /*!< AF15 : AF15                                                     */

/* ==============================================  GPIOA AFRL AFSEL5 [20..23]  =============================================== */
#define   GPIO_AFRL_AFSEL5_AF0                (0UL<<20)     /*!< AF0 : AF0                                                       */
#define   GPIO_AFRL_AFSEL5_AF1                (1UL<<20)     /*!< AF1 : AF1                                                       */
#define   GPIO_AFRL_AFSEL5_AF2                (2UL<<20)     /*!< AF2 : AF2                                                       */
#define   GPIO_AFRL_AFSEL5_AF3                (3UL<<20)     /*!< AF3 : AF3                                                       */
#define   GPIO_AFRL_AFSEL5_AF4                (4UL<<20)     /*!< AF4 : AF4                                                       */
#define   GPIO_AFRL_AFSEL5_AF5                (5UL<<20)     /*!< AF5 : AF5                                                       */
#define   GPIO_AFRL_AFSEL5_AF6                (6UL<<20)     /*!< AF6 : AF6                                                       */
#define   GPIO_AFRL_AFSEL5_AF7                (7UL<<20)     /*!< AF7 : AF7                                                       */
#define   GPIO_AFRL_AFSEL5_AF8                (8UL<<20)     /*!< AF8 : AF8                                                       */
#define   GPIO_AFRL_AFSEL5_AF9                (9UL<<20)     /*!< AF9 : AF9                                                       */
#define   GPIO_AFRL_AFSEL5_AF10               (10UL<<20)    /*!< AF10 : AF10                                                     */
#define   GPIO_AFRL_AFSEL5_AF11               (11UL<<20)    /*!< AF11 : AF11                                                     */
#define   GPIO_AFRL_AFSEL5_AF12               (12UL<<20)    /*!< AF12 : AF12                                                     */
#define   GPIO_AFRL_AFSEL5_AF13               (13UL<<20)    /*!< AF13 : AF13                                                     */
#define   GPIO_AFRL_AFSEL5_AF14               (14UL<<20)    /*!< AF14 : AF14                                                     */
#define   GPIO_AFRL_AFSEL5_AF15               (15UL<<20)    /*!< AF15 : AF15                                                     */

/* ==============================================  GPIOA AFRL AFSEL4 [16..19]  =============================================== */
#define   GPIO_AFRL_AFSEL4_AF0                (0UL<<16)     /*!< AF0 : AF0                                                       */
#define   GPIO_AFRL_AFSEL4_AF1                (1UL<<16)     /*!< AF1 : AF1                                                       */
#define   GPIO_AFRL_AFSEL4_AF2                (2UL<<16)     /*!< AF2 : AF2                                                       */
#define   GPIO_AFRL_AFSEL4_AF3                (3UL<<16)     /*!< AF3 : AF3                                                       */
#define   GPIO_AFRL_AFSEL4_AF4                (4UL<<16)     /*!< AF4 : AF4                                                       */
#define   GPIO_AFRL_AFSEL4_AF5                (5UL<<16)     /*!< AF5 : AF5                                                       */
#define   GPIO_AFRL_AFSEL4_AF6                (6UL<<16)     /*!< AF6 : AF6                                                       */
#define   GPIO_AFRL_AFSEL4_AF7                (7UL<<16)     /*!< AF7 : AF7                                                       */
#define   GPIO_AFRL_AFSEL4_AF8                (8UL<<16)     /*!< AF8 : AF8                                                       */
#define   GPIO_AFRL_AFSEL4_AF9                (9UL<<16)     /*!< AF9 : AF9                                                       */
#define   GPIO_AFRL_AFSEL4_AF10               (10UL<<16)    /*!< AF10 : AF10                                                     */
#define   GPIO_AFRL_AFSEL4_AF11               (11UL<<16)    /*!< AF11 : AF11                                                     */
#define   GPIO_AFRL_AFSEL4_AF12               (12UL<<16)    /*!< AF12 : AF12                                                     */
#define   GPIO_AFRL_AFSEL4_AF13               (13UL<<16)    /*!< AF13 : AF13                                                     */
#define   GPIO_AFRL_AFSEL4_AF14               (14UL<<16)    /*!< AF14 : AF14                                                     */
#define   GPIO_AFRL_AFSEL4_AF15               (15UL<<16)    /*!< AF15 : AF15                                                     */

/* ==============================================  GPIOA AFRL AFSEL3 [12..15]  =============================================== */
#define   GPIO_AFRL_AFSEL3_AF0                (0UL<<12)     /*!< AF0 : AF0                                                       */
#define   GPIO_AFRL_AFSEL3_AF1                (1UL<<12)     /*!< AF1 : AF1                                                       */
#define   GPIO_AFRL_AFSEL3_AF2                (2UL<<12)     /*!< AF2 : AF2                                                       */
#define   GPIO_AFRL_AFSEL3_AF3                (3UL<<12)     /*!< AF3 : AF3                                                       */
#define   GPIO_AFRL_AFSEL3_AF4                (4UL<<12)     /*!< AF4 : AF4                                                       */
#define   GPIO_AFRL_AFSEL3_AF5                (5UL<<12)     /*!< AF5 : AF5                                                       */
#define   GPIO_AFRL_AFSEL3_AF6                (6UL<<12)     /*!< AF6 : AF6                                                       */
#define   GPIO_AFRL_AFSEL3_AF7                (7UL<<12)     /*!< AF7 : AF7                                                       */
#define   GPIO_AFRL_AFSEL3_AF8                (8UL<<12)     /*!< AF8 : AF8                                                       */
#define   GPIO_AFRL_AFSEL3_AF9                (9UL<<12)     /*!< AF9 : AF9                                                       */
#define   GPIO_AFRL_AFSEL3_AF10               (10UL<<12)    /*!< AF10 : AF10                                                     */
#define   GPIO_AFRL_AFSEL3_AF11               (11UL<<12)    /*!< AF11 : AF11                                                     */
#define   GPIO_AFRL_AFSEL3_AF12               (12UL<<12)    /*!< AF12 : AF12                                                     */
#define   GPIO_AFRL_AFSEL3_AF13               (13UL<<12)    /*!< AF13 : AF13                                                     */
#define   GPIO_AFRL_AFSEL3_AF14               (14UL<<12)    /*!< AF14 : AF14                                                     */
#define   GPIO_AFRL_AFSEL3_AF15               (15UL<<12)    /*!< AF15 : AF15                                                     */

/* ===============================================  GPIOA AFRL AFSEL2 [8..11]  =============================================== */
#define   GPIO_AFRL_AFSEL2_AF0                (0UL<<8)     /*!< AF0 : AF0                                                        */
#define   GPIO_AFRL_AFSEL2_AF1                (1UL<<8)     /*!< AF1 : AF1                                                        */
#define   GPIO_AFRL_AFSEL2_AF2                (2UL<<8)     /*!< AF2 : AF2                                                        */
#define   GPIO_AFRL_AFSEL2_AF3                (3UL<<8)     /*!< AF3 : AF3                                                        */
#define   GPIO_AFRL_AFSEL2_AF4                (4UL<<8)     /*!< AF4 : AF4                                                        */
#define   GPIO_AFRL_AFSEL2_AF5                (5UL<<8)     /*!< AF5 : AF5                                                        */
#define   GPIO_AFRL_AFSEL2_AF6                (6UL<<8)     /*!< AF6 : AF6                                                        */
#define   GPIO_AFRL_AFSEL2_AF7                (7UL<<8)     /*!< AF7 : AF7                                                        */
#define   GPIO_AFRL_AFSEL2_AF8                (8UL<<8)     /*!< AF8 : AF8                                                        */
#define   GPIO_AFRL_AFSEL2_AF9                (9UL<<8)     /*!< AF9 : AF9                                                        */
#define   GPIO_AFRL_AFSEL2_AF10               (10UL<<8)    /*!< AF10 : AF10                                                      */
#define   GPIO_AFRL_AFSEL2_AF11               (11UL<<8)    /*!< AF11 : AF11                                                      */
#define   GPIO_AFRL_AFSEL2_AF12               (12UL<<8)    /*!< AF12 : AF12                                                      */
#define   GPIO_AFRL_AFSEL2_AF13               (13UL<<8)    /*!< AF13 : AF13                                                      */
#define   GPIO_AFRL_AFSEL2_AF14               (14UL<<8)    /*!< AF14 : AF14                                                      */
#define   GPIO_AFRL_AFSEL2_AF15               (15UL<<8)    /*!< AF15 : AF15                                                      */

/* ===============================================  GPIOA AFRL AFSEL1 [4..7]  ================================================ */
#define   GPIO_AFRL_AFSEL1_AF0                (0UL<<4)     /*!< AF0 : AF0                                                        */
#define   GPIO_AFRL_AFSEL1_AF1                (1UL<<4)     /*!< AF1 : AF1                                                        */
#define   GPIO_AFRL_AFSEL1_AF2                (2UL<<4)     /*!< AF2 : AF2                                                        */
#define   GPIO_AFRL_AFSEL1_AF3                (3UL<<4)     /*!< AF3 : AF3                                                        */
#define   GPIO_AFRL_AFSEL1_AF4                (4UL<<4)     /*!< AF4 : AF4                                                        */
#define   GPIO_AFRL_AFSEL1_AF5                (5UL<<4)     /*!< AF5 : AF5                                                        */
#define   GPIO_AFRL_AFSEL1_AF6                (6UL<<4)     /*!< AF6 : AF6                                                        */
#define   GPIO_AFRL_AFSEL1_AF7                (7UL<<4)     /*!< AF7 : AF7                                                        */
#define   GPIO_AFRL_AFSEL1_AF8                (8UL<<4)     /*!< AF8 : AF8                                                        */
#define   GPIO_AFRL_AFSEL1_AF9                (9UL<<4)     /*!< AF9 : AF9                                                        */
#define   GPIO_AFRL_AFSEL1_AF10               (10UL<<4)    /*!< AF10 : AF10                                                      */
#define   GPIO_AFRL_AFSEL1_AF11               (11UL<<4)    /*!< AF11 : AF11                                                      */
#define   GPIO_AFRL_AFSEL1_AF12               (12UL<<4)    /*!< AF12 : AF12                                                      */
#define   GPIO_AFRL_AFSEL1_AF13               (13UL<<4)    /*!< AF13 : AF13                                                      */
#define   GPIO_AFRL_AFSEL1_AF14               (14UL<<4)    /*!< AF14 : AF14                                                      */
#define   GPIO_AFRL_AFSEL1_AF15               (15UL<<4)    /*!< AF15 : AF15                                                      */

/* ===============================================  GPIOA AFRL AFSEL0 [0..3]  ================================================ */
#define   GPIO_AFRL_AFSEL0_AF0                (0UL<<0)     /*!< AF0 : AF0                                                        */
#define   GPIO_AFRL_AFSEL0_AF1                (1UL<<0)     /*!< AF1 : AF1                                                        */
#define   GPIO_AFRL_AFSEL0_AF2                (2UL<<0)     /*!< AF2 : AF2                                                        */
#define   GPIO_AFRL_AFSEL0_AF3                (3UL<<0)     /*!< AF3 : AF3                                                        */
#define   GPIO_AFRL_AFSEL0_AF4                (4UL<<0)     /*!< AF4 : AF4                                                        */
#define   GPIO_AFRL_AFSEL0_AF5                (5UL<<0)     /*!< AF5 : AF5                                                        */
#define   GPIO_AFRL_AFSEL0_AF6                (6UL<<0)     /*!< AF6 : AF6                                                        */
#define   GPIO_AFRL_AFSEL0_AF7                (7UL<<0)     /*!< AF7 : AF7                                                        */
#define   GPIO_AFRL_AFSEL0_AF8                (8UL<<0)     /*!< AF8 : AF8                                                        */
#define   GPIO_AFRL_AFSEL0_AF9                (9UL<<0)     /*!< AF9 : AF9                                                        */
#define   GPIO_AFRL_AFSEL0_AF10               (10UL<<0)    /*!< AF10 : AF10                                                      */
#define   GPIO_AFRL_AFSEL0_AF11               (11UL<<0)    /*!< AF11 : AF11                                                      */
#define   GPIO_AFRL_AFSEL0_AF12               (12UL<<0)    /*!< AF12 : AF12                                                      */
#define   GPIO_AFRL_AFSEL0_AF13               (13UL<<0)    /*!< AF13 : AF13                                                      */
#define   GPIO_AFRL_AFSEL0_AF14               (14UL<<0)    /*!< AF14 : AF14                                                      */
#define   GPIO_AFRL_AFSEL0_AF15               (15UL<<0)    /*!< AF15 : AF15                                                      */

/* =========================================================  AFRH  ========================================================== */
/* ==============================================  GPIOA AFRH AFSEL15 [28..31]  ============================================== */
#define   GPIO_AFRH_AFSEL15_AF0               (0UL<<28)     /*!< AF0 : AF0                                                       */
#define   GPIO_AFRH_AFSEL15_AF1               (1UL<<28)     /*!< AF1 : AF1                                                       */
#define   GPIO_AFRH_AFSEL15_AF2               (2UL<<28)     /*!< AF2 : AF2                                                       */
#define   GPIO_AFRH_AFSEL15_AF3               (3UL<<28)     /*!< AF3 : AF3                                                       */
#define   GPIO_AFRH_AFSEL15_AF4               (4UL<<28)     /*!< AF4 : AF4                                                       */
#define   GPIO_AFRH_AFSEL15_AF5               (5UL<<28)     /*!< AF5 : AF5                                                       */
#define   GPIO_AFRH_AFSEL15_AF6               (6UL<<28)     /*!< AF6 : AF6                                                       */
#define   GPIO_AFRH_AFSEL15_AF7               (7UL<<28)     /*!< AF7 : AF7                                                       */
#define   GPIO_AFRH_AFSEL15_AF8               (8UL<<28)     /*!< AF8 : AF8                                                       */
#define   GPIO_AFRH_AFSEL15_AF9               (9UL<<28)     /*!< AF9 : AF9                                                       */
#define   GPIO_AFRH_AFSEL15_AF10              (10UL<<28)    /*!< AF10 : AF10                                                     */
#define   GPIO_AFRH_AFSEL15_AF11              (11UL<<28)    /*!< AF11 : AF11                                                     */
#define   GPIO_AFRH_AFSEL15_AF12              (12UL<<28)    /*!< AF12 : AF12                                                     */
#define   GPIO_AFRH_AFSEL15_AF13              (13UL<<28)    /*!< AF13 : AF13                                                     */
#define   GPIO_AFRH_AFSEL15_AF14              (14UL<<28)    /*!< AF14 : AF14                                                     */
#define   GPIO_AFRH_AFSEL15_AF15              (15UL<<28)    /*!< AF15 : AF15                                                     */

/* ==============================================  GPIOA AFRH AFSEL14 [24..27]  ============================================== */
#define   GPIO_AFRH_AFSEL14_AF0               (0UL<<24)     /*!< AF0 : AF0                                                       */
#define   GPIO_AFRH_AFSEL14_AF1               (1UL<<24)     /*!< AF1 : AF1                                                       */
#define   GPIO_AFRH_AFSEL14_AF2               (2UL<<24)     /*!< AF2 : AF2                                                       */
#define   GPIO_AFRH_AFSEL14_AF3               (3UL<<24)     /*!< AF3 : AF3                                                       */
#define   GPIO_AFRH_AFSEL14_AF4               (4UL<<24)     /*!< AF4 : AF4                                                       */
#define   GPIO_AFRH_AFSEL14_AF5               (5UL<<24)     /*!< AF5 : AF5                                                       */
#define   GPIO_AFRH_AFSEL14_AF6               (6UL<<24)     /*!< AF6 : AF6                                                       */
#define   GPIO_AFRH_AFSEL14_AF7               (7UL<<24)     /*!< AF7 : AF7                                                       */
#define   GPIO_AFRH_AFSEL14_AF8               (8UL<<24)     /*!< AF8 : AF8                                                       */
#define   GPIO_AFRH_AFSEL14_AF9               (9UL<<24)     /*!< AF9 : AF9                                                       */
#define   GPIO_AFRH_AFSEL14_AF10              (10UL<<24)    /*!< AF10 : AF10                                                     */
#define   GPIO_AFRH_AFSEL14_AF11              (11UL<<24)    /*!< AF11 : AF11                                                     */
#define   GPIO_AFRH_AFSEL14_AF12              (12UL<<24)    /*!< AF12 : AF12                                                     */
#define   GPIO_AFRH_AFSEL14_AF13              (13UL<<24)    /*!< AF13 : AF13                                                     */
#define   GPIO_AFRH_AFSEL14_AF14              (14UL<<24)    /*!< AF14 : AF14                                                     */
#define   GPIO_AFRH_AFSEL14_AF15              (15UL<<24)    /*!< AF15 : AF15                                                     */

/* ==============================================  GPIOA AFRH AFSEL13 [20..23]  ============================================== */
#define   GPIO_AFRH_AFSEL13_AF0               (0UL<<20)     /*!< AF0 : AF0                                                       */
#define   GPIO_AFRH_AFSEL13_AF1               (1UL<<20)     /*!< AF1 : AF1                                                       */
#define   GPIO_AFRH_AFSEL13_AF2               (2UL<<20)     /*!< AF2 : AF2                                                       */
#define   GPIO_AFRH_AFSEL13_AF3               (3UL<<20)     /*!< AF3 : AF3                                                       */
#define   GPIO_AFRH_AFSEL13_AF4               (4UL<<20)     /*!< AF4 : AF4                                                       */
#define   GPIO_AFRH_AFSEL13_AF5               (5UL<<20)     /*!< AF5 : AF5                                                       */
#define   GPIO_AFRH_AFSEL13_AF6               (6UL<<20)     /*!< AF6 : AF6                                                       */
#define   GPIO_AFRH_AFSEL13_AF7               (7UL<<20)     /*!< AF7 : AF7                                                       */
#define   GPIO_AFRH_AFSEL13_AF8               (8UL<<20)     /*!< AF8 : AF8                                                       */
#define   GPIO_AFRH_AFSEL13_AF9               (9UL<<20)     /*!< AF9 : AF9                                                       */
#define   GPIO_AFRH_AFSEL13_AF10              (10UL<<20)    /*!< AF10 : AF10                                                     */
#define   GPIO_AFRH_AFSEL13_AF11              (11UL<<20)    /*!< AF11 : AF11                                                     */
#define   GPIO_AFRH_AFSEL13_AF12              (12UL<<20)    /*!< AF12 : AF12                                                     */
#define   GPIO_AFRH_AFSEL13_AF13              (13UL<<20)    /*!< AF13 : AF13                                                     */
#define   GPIO_AFRH_AFSEL13_AF14              (14UL<<20)    /*!< AF14 : AF14                                                     */
#define   GPIO_AFRH_AFSEL13_AF15              (15UL<<20)    /*!< AF15 : AF15                                                     */

/* ==============================================  GPIOA AFRH AFSEL12 [16..19]  ============================================== */
#define   GPIO_AFRH_AFSEL12_AF0               (0UL<<16)     /*!< AF0 : AF0                                                       */
#define   GPIO_AFRH_AFSEL12_AF1               (1UL<<16)     /*!< AF1 : AF1                                                       */
#define   GPIO_AFRH_AFSEL12_AF2               (2UL<<16)     /*!< AF2 : AF2                                                       */
#define   GPIO_AFRH_AFSEL12_AF3               (3UL<<16)     /*!< AF3 : AF3                                                       */
#define   GPIO_AFRH_AFSEL12_AF4               (4UL<<16)     /*!< AF4 : AF4                                                       */
#define   GPIO_AFRH_AFSEL12_AF5               (5UL<<16)     /*!< AF5 : AF5                                                       */
#define   GPIO_AFRH_AFSEL12_AF6               (6UL<<16)     /*!< AF6 : AF6                                                       */
#define   GPIO_AFRH_AFSEL12_AF7               (7UL<<16)     /*!< AF7 : AF7                                                       */
#define   GPIO_AFRH_AFSEL12_AF8               (8UL<<16)     /*!< AF8 : AF8                                                       */
#define   GPIO_AFRH_AFSEL12_AF9               (9UL<<16)     /*!< AF9 : AF9                                                       */
#define   GPIO_AFRH_AFSEL12_AF10              (10UL<<16)    /*!< AF10 : AF10                                                     */
#define   GPIO_AFRH_AFSEL12_AF11              (11UL<<16)    /*!< AF11 : AF11                                                     */
#define   GPIO_AFRH_AFSEL12_AF12              (12UL<<16)    /*!< AF12 : AF12                                                     */
#define   GPIO_AFRH_AFSEL12_AF13              (13UL<<16)    /*!< AF13 : AF13                                                     */
#define   GPIO_AFRH_AFSEL12_AF14              (14UL<<16)    /*!< AF14 : AF14                                                     */
#define   GPIO_AFRH_AFSEL12_AF15              (15UL<<16)    /*!< AF15 : AF15                                                     */

/* ==============================================  GPIOA AFRH AFSEL11 [12..15]  ============================================== */
#define   GPIO_AFRH_AFSEL11_AF0               (0UL<<12)     /*!< AF0 : AF0                                                       */
#define   GPIO_AFRH_AFSEL11_AF1               (1UL<<12)     /*!< AF1 : AF1                                                       */
#define   GPIO_AFRH_AFSEL11_AF2               (2UL<<12)     /*!< AF2 : AF2                                                       */
#define   GPIO_AFRH_AFSEL11_AF3               (3UL<<12)     /*!< AF3 : AF3                                                       */
#define   GPIO_AFRH_AFSEL11_AF4               (4UL<<12)     /*!< AF4 : AF4                                                       */
#define   GPIO_AFRH_AFSEL11_AF5               (5UL<<12)     /*!< AF5 : AF5                                                       */
#define   GPIO_AFRH_AFSEL11_AF6               (6UL<<12)     /*!< AF6 : AF6                                                       */
#define   GPIO_AFRH_AFSEL11_AF7               (7UL<<12)     /*!< AF7 : AF7                                                       */
#define   GPIO_AFRH_AFSEL11_AF8               (8UL<<12)     /*!< AF8 : AF8                                                       */
#define   GPIO_AFRH_AFSEL11_AF9               (9UL<<12)     /*!< AF9 : AF9                                                       */
#define   GPIO_AFRH_AFSEL11_AF10              (10UL<<12)    /*!< AF10 : AF10                                                     */
#define   GPIO_AFRH_AFSEL11_AF11              (11UL<<12)    /*!< AF11 : AF11                                                     */
#define   GPIO_AFRH_AFSEL11_AF12              (12UL<<12)    /*!< AF12 : AF12                                                     */
#define   GPIO_AFRH_AFSEL11_AF13              (13UL<<12)    /*!< AF13 : AF13                                                     */
#define   GPIO_AFRH_AFSEL11_AF14              (14UL<<12)    /*!< AF14 : AF14                                                     */
#define   GPIO_AFRH_AFSEL11_AF15              (15UL<<12)    /*!< AF15 : AF15                                                     */

/* ==============================================  GPIOA AFRH AFSEL10 [8..11]  =============================================== */
#define   GPIO_AFRH_AFSEL10_AF0               (0UL<<8)     /*!< AF0 : AF0                                                        */
#define   GPIO_AFRH_AFSEL10_AF1               (1UL<<8)     /*!< AF1 : AF1                                                        */
#define   GPIO_AFRH_AFSEL10_AF2               (2UL<<8)     /*!< AF2 : AF2                                                        */
#define   GPIO_AFRH_AFSEL10_AF3               (3UL<<8)     /*!< AF3 : AF3                                                        */
#define   GPIO_AFRH_AFSEL10_AF4               (4UL<<8)     /*!< AF4 : AF4                                                        */
#define   GPIO_AFRH_AFSEL10_AF5               (5UL<<8)     /*!< AF5 : AF5                                                        */
#define   GPIO_AFRH_AFSEL10_AF6               (6UL<<8)     /*!< AF6 : AF6                                                        */
#define   GPIO_AFRH_AFSEL10_AF7               (7UL<<8)     /*!< AF7 : AF7                                                        */
#define   GPIO_AFRH_AFSEL10_AF8               (8UL<<8)     /*!< AF8 : AF8                                                        */
#define   GPIO_AFRH_AFSEL10_AF9               (9UL<<8)     /*!< AF9 : AF9                                                        */
#define   GPIO_AFRH_AFSEL10_AF10              (10UL<<8)    /*!< AF10 : AF10                                                      */
#define   GPIO_AFRH_AFSEL10_AF11              (11UL<<8)    /*!< AF11 : AF11                                                      */
#define   GPIO_AFRH_AFSEL10_AF12              (12UL<<8)    /*!< AF12 : AF12                                                      */
#define   GPIO_AFRH_AFSEL10_AF13              (13UL<<8)    /*!< AF13 : AF13                                                      */
#define   GPIO_AFRH_AFSEL10_AF14              (14UL<<8)    /*!< AF14 : AF14                                                      */
#define   GPIO_AFRH_AFSEL10_AF15              (15UL<<8)    /*!< AF15 : AF15                                                      */

/* ===============================================  GPIOA AFRH AFSEL9 [4..7]  ================================================ */
#define   GPIO_AFRH_AFSEL9_AF0                (0UL<<4)     /*!< AF0 : AF0                                                        */
#define   GPIO_AFRH_AFSEL9_AF1                (1UL<<4)     /*!< AF1 : AF1                                                        */
#define   GPIO_AFRH_AFSEL9_AF2                (2UL<<4)     /*!< AF2 : AF2                                                        */
#define   GPIO_AFRH_AFSEL9_AF3                (3UL<<4)     /*!< AF3 : AF3                                                        */
#define   GPIO_AFRH_AFSEL9_AF4                (4UL<<4)     /*!< AF4 : AF4                                                        */
#define   GPIO_AFRH_AFSEL9_AF5                (5UL<<4)     /*!< AF5 : AF5                                                        */
#define   GPIO_AFRH_AFSEL9_AF6                (6UL<<4)     /*!< AF6 : AF6                                                        */
#define   GPIO_AFRH_AFSEL9_AF7                (7UL<<4)     /*!< AF7 : AF7                                                        */
#define   GPIO_AFRH_AFSEL9_AF8                (8UL<<4)     /*!< AF8 : AF8                                                        */
#define   GPIO_AFRH_AFSEL9_AF9                (9UL<<4)     /*!< AF9 : AF9                                                        */
#define   GPIO_AFRH_AFSEL9_AF10               (10UL<<4)    /*!< AF10 : AF10                                                      */
#define   GPIO_AFRH_AFSEL9_AF11               (11UL<<4)    /*!< AF11 : AF11                                                      */
#define   GPIO_AFRH_AFSEL9_AF12               (12UL<<4)    /*!< AF12 : AF12                                                      */
#define   GPIO_AFRH_AFSEL9_AF13               (13UL<<4)    /*!< AF13 : AF13                                                      */
#define   GPIO_AFRH_AFSEL9_AF14               (14UL<<4)    /*!< AF14 : AF14                                                      */
#define   GPIO_AFRH_AFSEL9_AF15               (15UL<<4)    /*!< AF15 : AF15                                                      */

/* ===============================================  GPIOA AFRH AFSEL8 [0..3]  ================================================ */
#define   GPIO_AFRH_AFSEL8_AF0                (0UL<<0)     /*!< AF0 : AF0                                                        */
#define   GPIO_AFRH_AFSEL8_AF1                (1UL<<0)     /*!< AF1 : AF1                                                        */
#define   GPIO_AFRH_AFSEL8_AF2                (2UL<<0)     /*!< AF2 : AF2                                                        */
#define   GPIO_AFRH_AFSEL8_AF3                (3UL<<0)     /*!< AF3 : AF3                                                        */
#define   GPIO_AFRH_AFSEL8_AF4                (4UL<<0)     /*!< AF4 : AF4                                                        */
#define   GPIO_AFRH_AFSEL8_AF5                (5UL<<0)     /*!< AF5 : AF5                                                        */
#define   GPIO_AFRH_AFSEL8_AF6                (6UL<<0)     /*!< AF6 : AF6                                                        */
#define   GPIO_AFRH_AFSEL8_AF7                (7UL<<0)     /*!< AF7 : AF7                                                        */
#define   GPIO_AFRH_AFSEL8_AF8                (8UL<<0)     /*!< AF8 : AF8                                                        */
#define   GPIO_AFRH_AFSEL8_AF9                (9UL<<0)     /*!< AF9 : AF9                                                        */
#define   GPIO_AFRH_AFSEL8_AF10               (10UL<<0)    /*!< AF10 : AF10                                                      */
#define   GPIO_AFRH_AFSEL8_AF11               (11UL<<0)    /*!< AF11 : AF11                                                      */
#define   GPIO_AFRH_AFSEL8_AF12               (12UL<<0)    /*!< AF12 : AF12                                                      */
#define   GPIO_AFRH_AFSEL8_AF13               (13UL<<0)    /*!< AF13 : AF13                                                      */
#define   GPIO_AFRH_AFSEL8_AF14               (14UL<<0)    /*!< AF14 : AF14                                                      */
#define   GPIO_AFRH_AFSEL8_AF15               (15UL<<0)    /*!< AF15 : AF15                                                      */

/* ==========================================================  BRR  ========================================================== */


/* =========================================================================================================================== */
/* ================                                          SYSCFG                                           ================ */
/* =========================================================================================================================== */

/* =========================================================  CFGR1  ========================================================= */
/* =============================================  SYSCFG CFGR1 MEM_MODE [0..1]  ============================================== */
#define   SYSCFG_CFGR1_MEM_MODE_Mainflash      (0UL<<0)     /*!< Mainflash : Mainflash                                            */
#define   SYSCFG_CFGR1_MEM_MODE_SRAM           (1UL<<0)     /*!< SRAM : SRAM                                                      */
#define   SYSCFG_CFGR1_MEM_MODE_Systemflash    (3UL<<0)     /*!< Systemflash : Systemflash                                        */

/* =========================================================  CFGR2  ========================================================= */
/* ==========================================  SYSCFG CFGR2 ETR_SRC_TIM1 [19..21]  =========================================== */
#define   SYSCFG_CFGR2_ETR_SRC_TIM1_GPIO       (0UL<<19)     /*!< GPIO : GPIO                                                     */
#define   SYSCFG_CFGR2_ETR_SRC_TIM1_COMP1      (1UL<<19)     /*!< COMP1 : COMP1                                                   */
#define   SYSCFG_CFGR2_ETR_SRC_TIM1_COMP2      (2UL<<19)     /*!< COMP2 : COMP2                                                   */
#define   SYSCFG_CFGR2_ETR_SRC_TIM1_COMP3      (3UL<<19)     /*!< COMP3 : COMP3                                                   */
#define   SYSCFG_CFGR2_ETR_SRC_TIM1_COMP4      (4UL<<19)     /*!< COMP4 : COMP4                                                   */

/* =========================================================  CFGR3  ========================================================= */
/* ============================================  SYSCFG CFGR3 DMA3_MAP [16..21]  ============================================= */
#define   SYSCFG_CFGR3_DMA3_MAP_ADC            (0UL<<16)     /*!< ADC : ADC                                                       */
#define   SYSCFG_CFGR3_DMA3_MAP_SPI1_TX        (1UL<<16)     /*!< SPI1_TX : SPI1_TX                                               */
#define   SYSCFG_CFGR3_DMA3_MAP_SPI1_RX        (2UL<<16)     /*!< SPI1_RX : SPI1_RX                                               */
#define   SYSCFG_CFGR3_DMA3_MAP_SPI2_TX        (3UL<<16)     /*!< SPI2_TX : SPI2_TX                                               */
#define   SYSCFG_CFGR3_DMA3_MAP_SPI2_RX        (4UL<<16)     /*!< SPI2_RX : SPI2_RX                                               */
#define   SYSCFG_CFGR3_DMA3_MAP_UART1_TX       (5UL<<16)     /*!< UART1_TX : UART1_TX                                             */
#define   SYSCFG_CFGR3_DMA3_MAP_UART1_RX       (6UL<<16)     /*!< UART1_RX : UART1_RX                                             */
#define   SYSCFG_CFGR3_DMA3_MAP_UART2_TX       (7UL<<16)     /*!< UART2_TX : UART2_TX                                             */
#define   SYSCFG_CFGR3_DMA3_MAP_UART2_RX       (8UL<<16)     /*!< UART2_RX : UART2_RX                                             */
#define   SYSCFG_CFGR3_DMA3_MAP_I2C1_TX        (9UL<<16)     /*!< I2C1_TX : I2C1_TX                                               */
#define   SYSCFG_CFGR3_DMA3_MAP_I2C1_RX        (10UL<<16)    /*!< I2C1_RX : I2C1_RX                                               */
#define   SYSCFG_CFGR3_DMA3_MAP_I2C2_TX        (11UL<<16)    /*!< I2C2_TX : I2C2_TX                                               */
#define   SYSCFG_CFGR3_DMA3_MAP_I2C2_RX        (12UL<<16)    /*!< I2C2_RX : I2C2_RX                                               */
#define   SYSCFG_CFGR3_DMA3_MAP_TIM1_CH1       (13UL<<16)    /*!< TIM1_CH1 : TIM1_CH1                                             */
#define   SYSCFG_CFGR3_DMA3_MAP_TIM1_CH2       (14UL<<16)    /*!< TIM1_CH2 : TIM1_CH2                                             */
#define   SYSCFG_CFGR3_DMA3_MAP_TIM1_CH3       (15UL<<16)    /*!< TIM1_CH3 : TIM1_CH3                                             */
#define   SYSCFG_CFGR3_DMA3_MAP_TIM1_CH4       (16UL<<16)    /*!< TIM1_CH4 : TIM1_CH4                                             */
#define   SYSCFG_CFGR3_DMA3_MAP_TIM1_COM       (17UL<<16)    /*!< TIM1_COM : TIM1_COM                                             */
#define   SYSCFG_CFGR3_DMA3_MAP_TIM1_UP        (18UL<<16)    /*!< TIM1_UP : TIM1_UP                                               */
#define   SYSCFG_CFGR3_DMA3_MAP_TIM1_TRIG      (19UL<<16)    /*!< TIM1_TRIG : TIM1_TRIG                                           */
#define   SYSCFG_CFGR3_DMA3_MAP_TIM3_CH1       (20UL<<16)    /*!< TIM3_CH1 : TIM3_CH1                                             */
#define   SYSCFG_CFGR3_DMA3_MAP_TIM3_CH3       (21UL<<16)    /*!< TIM3_CH3 : TIM3_CH3                                             */
#define   SYSCFG_CFGR3_DMA3_MAP_TIM3_CH4       (22UL<<16)    /*!< TIM3_CH4 : TIM3_CH4                                             */
#define   SYSCFG_CFGR3_DMA3_MAP_TIM3_TRG       (23UL<<16)    /*!< TIM3_TRG : TIM3_TRG                                             */
#define   SYSCFG_CFGR3_DMA3_MAP_TIM3_UP        (24UL<<16)    /*!< TIM3_UP : TIM3_UP                                               */
#define   SYSCFG_CFGR3_DMA3_MAP_TIM6_UP        (25UL<<16)    /*!< TIM6_UP : TIM6_UP                                               */
#define   SYSCFG_CFGR3_DMA3_MAP_TIM15_CH1      (26UL<<16)    /*!< TIM15_CH1 : TIM15_CH1                                           */
#define   SYSCFG_CFGR3_DMA3_MAP_TIM15_UP       (27UL<<16)    /*!< TIM15_UP : TIM15_UP                                             */
#define   SYSCFG_CFGR3_DMA3_MAP_TIM15_TRIG     (28UL<<16)    /*!< TIM15_TRIG : TIM15_TRIG                                         */
#define   SYSCFG_CFGR3_DMA3_MAP_TIM15_COM      (29UL<<16)    /*!< TIM15_COM : TIM15_COM                                           */
#define   SYSCFG_CFGR3_DMA3_MAP_TIM16_CH1      (30UL<<16)    /*!< TIM16_CH1 : TIM16_CH1                                           */
#define   SYSCFG_CFGR3_DMA3_MAP_TIM16_UP       (31UL<<16)    /*!< TIM16_UP : TIM16_UP                                             */
#define   SYSCFG_CFGR3_DMA3_MAP_TIM17_CH1      (32UL<<16)    /*!< TIM17_CH1 : TIM17_CH1                                           */
#define   SYSCFG_CFGR3_DMA3_MAP_TIM17_UP       (33UL<<16)    /*!< TIM17_UP : TIM17_UP                                             */
#define   SYSCFG_CFGR3_DMA3_MAP_DMA_M2M        (34UL<<16)    /*!< DMA_M2M : DMA_M2M                                               */

/* =============================================  SYSCFG CFGR3 DMA2_MAP [8..13]  ============================================= */
#define   SYSCFG_CFGR3_DMA2_MAP_ADC            (0UL<<8)     /*!< ADC : ADC                                                        */
#define   SYSCFG_CFGR3_DMA2_MAP_SPI1_TX        (1UL<<8)     /*!< SPI1_TX : SPI1_TX                                                */
#define   SYSCFG_CFGR3_DMA2_MAP_SPI1_RX        (2UL<<8)     /*!< SPI1_RX : SPI1_RX                                                */
#define   SYSCFG_CFGR3_DMA2_MAP_SPI2_TX        (3UL<<8)     /*!< SPI2_TX : SPI2_TX                                                */
#define   SYSCFG_CFGR3_DMA2_MAP_SPI2_RX        (4UL<<8)     /*!< SPI2_RX : SPI2_RX                                                */
#define   SYSCFG_CFGR3_DMA2_MAP_UART1_TX       (5UL<<8)     /*!< UART1_TX : UART1_TX                                              */
#define   SYSCFG_CFGR3_DMA2_MAP_UART1_RX       (6UL<<8)     /*!< UART1_RX : UART1_RX                                              */
#define   SYSCFG_CFGR3_DMA2_MAP_UART2_TX       (7UL<<8)     /*!< UART2_TX : UART2_TX                                              */
#define   SYSCFG_CFGR3_DMA2_MAP_UART2_RX       (8UL<<8)     /*!< UART2_RX : UART2_RX                                              */
#define   SYSCFG_CFGR3_DMA2_MAP_I2C1_TX        (9UL<<8)     /*!< I2C1_TX : I2C1_TX                                                */
#define   SYSCFG_CFGR3_DMA2_MAP_I2C1_RX        (10UL<<8)    /*!< I2C1_RX : I2C1_RX                                                */
#define   SYSCFG_CFGR3_DMA2_MAP_I2C2_TX        (11UL<<8)    /*!< I2C2_TX : I2C2_TX                                                */
#define   SYSCFG_CFGR3_DMA2_MAP_I2C2_RX        (12UL<<8)    /*!< I2C2_RX : I2C2_RX                                                */
#define   SYSCFG_CFGR3_DMA2_MAP_TIM1_CH1       (13UL<<8)    /*!< TIM1_CH1 : TIM1_CH1                                              */
#define   SYSCFG_CFGR3_DMA2_MAP_TIM1_CH2       (14UL<<8)    /*!< TIM1_CH2 : TIM1_CH2                                              */
#define   SYSCFG_CFGR3_DMA2_MAP_TIM1_CH3       (15UL<<8)    /*!< TIM1_CH3 : TIM1_CH3                                              */
#define   SYSCFG_CFGR3_DMA2_MAP_TIM1_CH4       (16UL<<8)    /*!< TIM1_CH4 : TIM1_CH4                                              */
#define   SYSCFG_CFGR3_DMA2_MAP_TIM1_COM       (17UL<<8)    /*!< TIM1_COM : TIM1_COM                                              */
#define   SYSCFG_CFGR3_DMA2_MAP_TIM1_UP        (18UL<<8)    /*!< TIM1_UP : TIM1_UP                                                */
#define   SYSCFG_CFGR3_DMA2_MAP_TIM1_TRIG      (19UL<<8)    /*!< TIM1_TRIG : TIM1_TRIG                                            */
#define   SYSCFG_CFGR3_DMA2_MAP_TIM3_CH1       (20UL<<8)    /*!< TIM3_CH1 : TIM3_CH1                                              */
#define   SYSCFG_CFGR3_DMA2_MAP_TIM3_CH3       (21UL<<8)    /*!< TIM3_CH3 : TIM3_CH3                                              */
#define   SYSCFG_CFGR3_DMA2_MAP_TIM3_CH4       (22UL<<8)    /*!< TIM3_CH4 : TIM3_CH4                                              */
#define   SYSCFG_CFGR3_DMA2_MAP_TIM3_TRG       (23UL<<8)    /*!< TIM3_TRG : TIM3_TRG                                              */
#define   SYSCFG_CFGR3_DMA2_MAP_TIM3_UP        (24UL<<8)    /*!< TIM3_UP : TIM3_UP                                                */
#define   SYSCFG_CFGR3_DMA2_MAP_TIM6_UP        (25UL<<8)    /*!< TIM6_UP : TIM6_UP                                                */
#define   SYSCFG_CFGR3_DMA2_MAP_TIM15_CH1      (26UL<<8)    /*!< TIM15_CH1 : TIM15_CH1                                            */
#define   SYSCFG_CFGR3_DMA2_MAP_TIM15_UP       (27UL<<8)    /*!< TIM15_UP : TIM15_UP                                              */
#define   SYSCFG_CFGR3_DMA2_MAP_TIM15_TRIG     (28UL<<8)    /*!< TIM15_TRIG : TIM15_TRIG                                          */
#define   SYSCFG_CFGR3_DMA2_MAP_TIM15_COM      (29UL<<8)    /*!< TIM15_COM : TIM15_COM                                            */
#define   SYSCFG_CFGR3_DMA2_MAP_TIM16_CH1      (30UL<<8)    /*!< TIM16_CH1 : TIM16_CH1                                            */
#define   SYSCFG_CFGR3_DMA2_MAP_TIM16_UP       (31UL<<8)    /*!< TIM16_UP : TIM16_UP                                              */
#define   SYSCFG_CFGR3_DMA2_MAP_TIM17_CH1      (32UL<<8)    /*!< TIM17_CH1 : TIM17_CH1                                            */
#define   SYSCFG_CFGR3_DMA2_MAP_TIM17_UP       (33UL<<8)    /*!< TIM17_UP : TIM17_UP                                              */
#define   SYSCFG_CFGR3_DMA2_MAP_DMA_M2M        (34UL<<8)    /*!< DMA_M2M : DMA_M2M                                                */

/* =============================================  SYSCFG CFGR3 DMA1_MAP [0..5]  ============================================== */
#define   SYSCFG_CFGR3_DMA1_MAP_ADC            (0UL<<0)     /*!< ADC : ADC                                                        */
#define   SYSCFG_CFGR3_DMA1_MAP_SPI1_TX        (1UL<<0)     /*!< SPI1_TX : SPI1_TX                                                */
#define   SYSCFG_CFGR3_DMA1_MAP_SPI1_RX        (2UL<<0)     /*!< SPI1_RX : SPI1_RX                                                */
#define   SYSCFG_CFGR3_DMA1_MAP_SPI2_TX        (3UL<<0)     /*!< SPI2_TX : SPI2_TX                                                */
#define   SYSCFG_CFGR3_DMA1_MAP_SPI2_RX        (4UL<<0)     /*!< SPI2_RX : SPI2_RX                                                */
#define   SYSCFG_CFGR3_DMA1_MAP_UART1_TX       (5UL<<0)     /*!< UART1_TX : UART1_TX                                              */
#define   SYSCFG_CFGR3_DMA1_MAP_UART1_RX       (6UL<<0)     /*!< UART1_RX : UART1_RX                                              */
#define   SYSCFG_CFGR3_DMA1_MAP_UART2_TX       (7UL<<0)     /*!< UART2_TX : UART2_TX                                              */
#define   SYSCFG_CFGR3_DMA1_MAP_UART2_RX       (8UL<<0)     /*!< UART2_RX : UART2_RX                                              */
#define   SYSCFG_CFGR3_DMA1_MAP_I2C1_TX        (9UL<<0)     /*!< I2C1_TX : I2C1_TX                                                */
#define   SYSCFG_CFGR3_DMA1_MAP_I2C1_RX        (10UL<<0)    /*!< I2C1_RX : I2C1_RX                                                */
#define   SYSCFG_CFGR3_DMA1_MAP_I2C2_TX        (11UL<<0)    /*!< I2C2_TX : I2C2_TX                                                */
#define   SYSCFG_CFGR3_DMA1_MAP_I2C2_RX        (12UL<<0)    /*!< I2C2_RX : I2C2_RX                                                */
#define   SYSCFG_CFGR3_DMA1_MAP_TIM1_CH1       (13UL<<0)    /*!< TIM1_CH1 : TIM1_CH1                                              */
#define   SYSCFG_CFGR3_DMA1_MAP_TIM1_CH2       (14UL<<0)    /*!< TIM1_CH2 : TIM1_CH2                                              */
#define   SYSCFG_CFGR3_DMA1_MAP_TIM1_CH3       (15UL<<0)    /*!< TIM1_CH3 : TIM1_CH3                                              */
#define   SYSCFG_CFGR3_DMA1_MAP_TIM1_CH4       (16UL<<0)    /*!< TIM1_CH4 : TIM1_CH4                                              */
#define   SYSCFG_CFGR3_DMA1_MAP_TIM1_COM       (17UL<<0)    /*!< TIM1_COM : TIM1_COM                                              */
#define   SYSCFG_CFGR3_DMA1_MAP_TIM1_UP        (18UL<<0)    /*!< TIM1_UP : TIM1_UP                                                */
#define   SYSCFG_CFGR3_DMA1_MAP_TIM1_TRIG      (19UL<<0)    /*!< TIM1_TRIG : TIM1_TRIG                                            */
#define   SYSCFG_CFGR3_DMA1_MAP_TIM3_CH1       (20UL<<0)    /*!< TIM3_CH1 : TIM3_CH1                                              */
#define   SYSCFG_CFGR3_DMA1_MAP_TIM3_CH3       (21UL<<0)    /*!< TIM3_CH3 : TIM3_CH3                                              */
#define   SYSCFG_CFGR3_DMA1_MAP_TIM3_CH4       (22UL<<0)    /*!< TIM3_CH4 : TIM3_CH4                                              */
#define   SYSCFG_CFGR3_DMA1_MAP_TIM3_TRG       (23UL<<0)    /*!< TIM3_TRG : TIM3_TRG                                              */
#define   SYSCFG_CFGR3_DMA1_MAP_TIM3_UP        (24UL<<0)    /*!< TIM3_UP : TIM3_UP                                                */
#define   SYSCFG_CFGR3_DMA1_MAP_TIM6_UP        (25UL<<0)    /*!< TIM6_UP : TIM6_UP                                                */
#define   SYSCFG_CFGR3_DMA1_MAP_TIM15_CH1      (26UL<<0)    /*!< TIM15_CH1 : TIM15_CH1                                            */
#define   SYSCFG_CFGR3_DMA1_MAP_TIM15_UP       (27UL<<0)    /*!< TIM15_UP : TIM15_UP                                              */
#define   SYSCFG_CFGR3_DMA1_MAP_TIM15_TRIG     (28UL<<0)    /*!< TIM15_TRIG : TIM15_TRIG                                          */
#define   SYSCFG_CFGR3_DMA1_MAP_TIM15_COM      (29UL<<0)    /*!< TIM15_COM : TIM15_COM                                            */
#define   SYSCFG_CFGR3_DMA1_MAP_TIM16_CH1      (30UL<<0)    /*!< TIM16_CH1 : TIM16_CH1                                            */
#define   SYSCFG_CFGR3_DMA1_MAP_TIM16_UP       (31UL<<0)    /*!< TIM16_UP : TIM16_UP                                              */
#define   SYSCFG_CFGR3_DMA1_MAP_TIM17_CH1      (32UL<<0)    /*!< TIM17_CH1 : TIM17_CH1                                            */
#define   SYSCFG_CFGR3_DMA1_MAP_TIM17_UP       (33UL<<0)    /*!< TIM17_UP : TIM17_UP                                              */
#define   SYSCFG_CFGR3_DMA1_MAP_DMA_M2M        (34UL<<0)    /*!< DMA_M2M : DMA_M2M                                                */

/* =========================================================  CFGR4  ========================================================= */
/* =============================================  SYSCFG CFGR4 DMA5_MAP [8..13]  ============================================= */
#define   SYSCFG_CFGR4_DMA5_MAP_ADC            (0UL<<8)     /*!< ADC : ADC                                                        */
#define   SYSCFG_CFGR4_DMA5_MAP_SPI1_TX        (1UL<<8)     /*!< SPI1_TX : SPI1_TX                                                */
#define   SYSCFG_CFGR4_DMA5_MAP_SPI1_RX        (2UL<<8)     /*!< SPI1_RX : SPI1_RX                                                */
#define   SYSCFG_CFGR4_DMA5_MAP_SPI2_TX        (3UL<<8)     /*!< SPI2_TX : SPI2_TX                                                */
#define   SYSCFG_CFGR4_DMA5_MAP_SPI2_RX        (4UL<<8)     /*!< SPI2_RX : SPI2_RX                                                */
#define   SYSCFG_CFGR4_DMA5_MAP_UART1_TX       (5UL<<8)     /*!< UART1_TX : UART1_TX                                              */
#define   SYSCFG_CFGR4_DMA5_MAP_UART1_RX       (6UL<<8)     /*!< UART1_RX : UART1_RX                                              */
#define   SYSCFG_CFGR4_DMA5_MAP_UART2_TX       (7UL<<8)     /*!< UART2_TX : UART2_TX                                              */
#define   SYSCFG_CFGR4_DMA5_MAP_UART2_RX       (8UL<<8)     /*!< UART2_RX : UART2_RX                                              */
#define   SYSCFG_CFGR4_DMA5_MAP_I2C1_TX        (9UL<<8)     /*!< I2C1_TX : I2C1_TX                                                */
#define   SYSCFG_CFGR4_DMA5_MAP_I2C1_RX        (10UL<<8)    /*!< I2C1_RX : I2C1_RX                                                */
#define   SYSCFG_CFGR4_DMA5_MAP_I2C2_TX        (11UL<<8)    /*!< I2C2_TX : I2C2_TX                                                */
#define   SYSCFG_CFGR4_DMA5_MAP_I2C2_RX        (12UL<<8)    /*!< I2C2_RX : I2C2_RX                                                */
#define   SYSCFG_CFGR4_DMA5_MAP_TIM1_CH1       (13UL<<8)    /*!< TIM1_CH1 : TIM1_CH1                                              */
#define   SYSCFG_CFGR4_DMA5_MAP_TIM1_CH2       (14UL<<8)    /*!< TIM1_CH2 : TIM1_CH2                                              */
#define   SYSCFG_CFGR4_DMA5_MAP_TIM1_CH3       (15UL<<8)    /*!< TIM1_CH3 : TIM1_CH3                                              */
#define   SYSCFG_CFGR4_DMA5_MAP_TIM1_CH4       (16UL<<8)    /*!< TIM1_CH4 : TIM1_CH4                                              */
#define   SYSCFG_CFGR4_DMA5_MAP_TIM1_COM       (17UL<<8)    /*!< TIM1_COM : TIM1_COM                                              */
#define   SYSCFG_CFGR4_DMA5_MAP_TIM1_UP        (18UL<<8)    /*!< TIM1_UP : TIM1_UP                                                */
#define   SYSCFG_CFGR4_DMA5_MAP_TIM1_TRIG      (19UL<<8)    /*!< TIM1_TRIG : TIM1_TRIG                                            */
#define   SYSCFG_CFGR4_DMA5_MAP_TIM3_CH1       (20UL<<8)    /*!< TIM3_CH1 : TIM3_CH1                                              */
#define   SYSCFG_CFGR4_DMA5_MAP_TIM3_CH3       (21UL<<8)    /*!< TIM3_CH3 : TIM3_CH3                                              */
#define   SYSCFG_CFGR4_DMA5_MAP_TIM3_CH4       (22UL<<8)    /*!< TIM3_CH4 : TIM3_CH4                                              */
#define   SYSCFG_CFGR4_DMA5_MAP_TIM3_TRG       (23UL<<8)    /*!< TIM3_TRG : TIM3_TRG                                              */
#define   SYSCFG_CFGR4_DMA5_MAP_TIM3_UP        (24UL<<8)    /*!< TIM3_UP : TIM3_UP                                                */
#define   SYSCFG_CFGR4_DMA5_MAP_TIM6_UP        (25UL<<8)    /*!< TIM6_UP : TIM6_UP                                                */
#define   SYSCFG_CFGR4_DMA5_MAP_TIM15_CH1      (26UL<<8)    /*!< TIM15_CH1 : TIM15_CH1                                            */
#define   SYSCFG_CFGR4_DMA5_MAP_TIM15_UP       (27UL<<8)    /*!< TIM15_UP : TIM15_UP                                              */
#define   SYSCFG_CFGR4_DMA5_MAP_TIM15_TRIG     (28UL<<8)    /*!< TIM15_TRIG : TIM15_TRIG                                          */
#define   SYSCFG_CFGR4_DMA5_MAP_TIM15_COM      (29UL<<8)    /*!< TIM15_COM : TIM15_COM                                            */
#define   SYSCFG_CFGR4_DMA5_MAP_TIM16_CH1      (30UL<<8)    /*!< TIM16_CH1 : TIM16_CH1                                            */
#define   SYSCFG_CFGR4_DMA5_MAP_TIM16_UP       (31UL<<8)    /*!< TIM16_UP : TIM16_UP                                              */
#define   SYSCFG_CFGR4_DMA5_MAP_TIM17_CH1      (32UL<<8)    /*!< TIM17_CH1 : TIM17_CH1                                            */
#define   SYSCFG_CFGR4_DMA5_MAP_TIM17_UP       (33UL<<8)    /*!< TIM17_UP : TIM17_UP                                              */
#define   SYSCFG_CFGR4_DMA5_MAP_DMA_M2M        (34UL<<8)    /*!< DMA_M2M : DMA_M2M                                                */

/* =============================================  SYSCFG CFGR4 DMA4_MAP [0..5]  ============================================== */
#define   SYSCFG_CFGR4_DMA4_MAP_ADC            (0UL<<0)     /*!< ADC : ADC                                                        */
#define   SYSCFG_CFGR4_DMA4_MAP_SPI1_TX        (1UL<<0)     /*!< SPI1_TX : SPI1_TX                                                */
#define   SYSCFG_CFGR4_DMA4_MAP_SPI1_RX        (2UL<<0)     /*!< SPI1_RX : SPI1_RX                                                */
#define   SYSCFG_CFGR4_DMA4_MAP_SPI2_TX        (3UL<<0)     /*!< SPI2_TX : SPI2_TX                                                */
#define   SYSCFG_CFGR4_DMA4_MAP_SPI2_RX        (4UL<<0)     /*!< SPI2_RX : SPI2_RX                                                */
#define   SYSCFG_CFGR4_DMA4_MAP_UART1_TX       (5UL<<0)     /*!< UART1_TX : UART1_TX                                              */
#define   SYSCFG_CFGR4_DMA4_MAP_UART1_RX       (6UL<<0)     /*!< UART1_RX : UART1_RX                                              */
#define   SYSCFG_CFGR4_DMA4_MAP_UART2_TX       (7UL<<0)     /*!< UART2_TX : UART2_TX                                              */
#define   SYSCFG_CFGR4_DMA4_MAP_UART2_RX       (8UL<<0)     /*!< UART2_RX : UART2_RX                                              */
#define   SYSCFG_CFGR4_DMA4_MAP_I2C1_TX        (9UL<<0)     /*!< I2C1_TX : I2C1_TX                                                */
#define   SYSCFG_CFGR4_DMA4_MAP_I2C1_RX        (10UL<<0)    /*!< I2C1_RX : I2C1_RX                                                */
#define   SYSCFG_CFGR4_DMA4_MAP_I2C2_TX        (11UL<<0)    /*!< I2C2_TX : I2C2_TX                                                */
#define   SYSCFG_CFGR4_DMA4_MAP_I2C2_RX        (12UL<<0)    /*!< I2C2_RX : I2C2_RX                                                */
#define   SYSCFG_CFGR4_DMA4_MAP_TIM1_CH1       (13UL<<0)    /*!< TIM1_CH1 : TIM1_CH1                                              */
#define   SYSCFG_CFGR4_DMA4_MAP_TIM1_CH2       (14UL<<0)    /*!< TIM1_CH2 : TIM1_CH2                                              */
#define   SYSCFG_CFGR4_DMA4_MAP_TIM1_CH3       (15UL<<0)    /*!< TIM1_CH3 : TIM1_CH3                                              */
#define   SYSCFG_CFGR4_DMA4_MAP_TIM1_CH4       (16UL<<0)    /*!< TIM1_CH4 : TIM1_CH4                                              */
#define   SYSCFG_CFGR4_DMA4_MAP_TIM1_COM       (17UL<<0)    /*!< TIM1_COM : TIM1_COM                                              */
#define   SYSCFG_CFGR4_DMA4_MAP_TIM1_UP        (18UL<<0)    /*!< TIM1_UP : TIM1_UP                                                */
#define   SYSCFG_CFGR4_DMA4_MAP_TIM1_TRIG      (19UL<<0)    /*!< TIM1_TRIG : TIM1_TRIG                                            */
#define   SYSCFG_CFGR4_DMA4_MAP_TIM3_CH1       (20UL<<0)    /*!< TIM3_CH1 : TIM3_CH1                                              */
#define   SYSCFG_CFGR4_DMA4_MAP_TIM3_CH3       (21UL<<0)    /*!< TIM3_CH3 : TIM3_CH3                                              */
#define   SYSCFG_CFGR4_DMA4_MAP_TIM3_CH4       (22UL<<0)    /*!< TIM3_CH4 : TIM3_CH4                                              */
#define   SYSCFG_CFGR4_DMA4_MAP_TIM3_TRG       (23UL<<0)    /*!< TIM3_TRG : TIM3_TRG                                              */
#define   SYSCFG_CFGR4_DMA4_MAP_TIM3_UP        (24UL<<0)    /*!< TIM3_UP : TIM3_UP                                                */
#define   SYSCFG_CFGR4_DMA4_MAP_TIM6_UP        (25UL<<0)    /*!< TIM6_UP : TIM6_UP                                                */
#define   SYSCFG_CFGR4_DMA4_MAP_TIM15_CH1      (26UL<<0)    /*!< TIM15_CH1 : TIM15_CH1                                            */
#define   SYSCFG_CFGR4_DMA4_MAP_TIM15_UP       (27UL<<0)    /*!< TIM15_UP : TIM15_UP                                              */
#define   SYSCFG_CFGR4_DMA4_MAP_TIM15_TRIG     (28UL<<0)    /*!< TIM15_TRIG : TIM15_TRIG                                          */
#define   SYSCFG_CFGR4_DMA4_MAP_TIM15_COM      (29UL<<0)    /*!< TIM15_COM : TIM15_COM                                            */
#define   SYSCFG_CFGR4_DMA4_MAP_TIM16_CH1      (30UL<<0)    /*!< TIM16_CH1 : TIM16_CH1                                            */
#define   SYSCFG_CFGR4_DMA4_MAP_TIM16_UP       (31UL<<0)    /*!< TIM16_UP : TIM16_UP                                              */
#define   SYSCFG_CFGR4_DMA4_MAP_TIM17_CH1      (32UL<<0)    /*!< TIM17_CH1 : TIM17_CH1                                            */
#define   SYSCFG_CFGR4_DMA4_MAP_TIM17_UP       (33UL<<0)    /*!< TIM17_UP : TIM17_UP                                              */
#define   SYSCFG_CFGR4_DMA4_MAP_DMA_M2M        (34UL<<0)    /*!< DMA_M2M : DMA_M2M                                                */

/* ====================================================  SRAM_TEST_CFGR  ===================================================== */
/* ============================================  SYSCFG SRAM_TEST_CFGR RM [1..4]  ============================================ */
#define   SYSCFG_SRAM_TEST_CFGR_RM_veryslow    (0UL<<1)     /*!< veryslow : veryslow                                              */
#define   SYSCFG_SRAM_TEST_CFGR_RM_slow        (1UL<<1)     /*!< slow : slow                                                      */
#define   SYSCFG_SRAM_TEST_CFGR_RM_fast        (2UL<<1)     /*!< fast : fast                                                      */
#define   SYSCFG_SRAM_TEST_CFGR_RM_veryfast    (4UL<<1)     /*!< veryfast : veryfast                                              */



/* =========================================================================================================================== */
/* ================                                            DMA                                            ================ */
/* =========================================================================================================================== */

/* ==========================================================  ISR  ========================================================== */
/* =========================================================  IFCR  ========================================================== */


/* =========================================================================================================================== */
/* ================                                       DMA_CHANNEL1                                        ================ */
/* =========================================================================================================================== */

/* ==========================================================  CCR  ========================================================== */
/* =============================================  DMA_CHANNEL1 CCR PL [12..13]  ============================================== */
#define   DMA_CHANNEL_CCR_PL_Low              (0UL<<12)     /*!< Low : Low                                                       */
#define   DMA_CHANNEL_CCR_PL_Mid              (1UL<<12)     /*!< Mid : Mid                                                       */
#define   DMA_CHANNEL_CCR_PL_High             (2UL<<12)     /*!< High : High                                                     */
#define   DMA_CHANNEL_CCR_PL_VeryHigh         (3UL<<12)     /*!< VeryHigh : VeryHigh                                             */

/* ============================================  DMA_CHANNEL1 CCR MSIZE [10..11]  ============================================ */
#define   DMA_CHANNEL_CCR_MSIZE_8             (0UL<<10)     /*!< 8 : 8 bits                                                      */
#define   DMA_CHANNEL_CCR_MSIZE_16            (1UL<<10)     /*!< 16 : 16 bits                                                    */
#define   DMA_CHANNEL_CCR_MSIZE_32            (2UL<<10)     /*!< 32 : 32 bits                                                    */
#define   DMA_CHANNEL_CCR_MSIZE_Reserve       (3UL<<10)     /*!< Reserve : Reserve                                               */

/* =============================================  DMA_CHANNEL1 CCR PSIZE [8..9]  ============================================= */
#define   DMA_CHANNEL_CCR_PSIZE_8             (0UL<<8)     /*!< 8 : 8 bits                                                       */
#define   DMA_CHANNEL_CCR_PSIZE_16            (1UL<<8)     /*!< 16 : 16 bits                                                     */
#define   DMA_CHANNEL_CCR_PSIZE_32            (2UL<<8)     /*!< 32 : 32 bits                                                     */
#define   DMA_CHANNEL_CCR_PSIZE_Reserve       (3UL<<8)     /*!< Reserve : Reserve                                                */

/* =========================================================  CNDTR  ========================================================= */
/* =========================================================  CPAR  ========================================================== */
/* =========================================================  CMAR  ========================================================== */


/* =========================================================================================================================== */
/* ================                                           EXTI                                            ================ */
/* =========================================================================================================================== */

/* =========================================================  RTSR  ========================================================== */
/* =========================================================  FTSR  ========================================================== */
/* =========================================================  SWIER  ========================================================= */
/* ==========================================================  PR  =========================================================== */
/* ========================================================  EXTICR1  ======================================================== */
/* ==============================================  EXTI EXTICR1 EXTI3 [24..25]  ============================================== */
#define   EXTI_EXTICR1_EXTI3_PA3               (0UL<<24)     /*!< PA3 : PA3                                                       */
#define   EXTI_EXTICR1_EXTI3_PB3               (1UL<<24)     /*!< PB3 : PB3                                                       */
#define   EXTI_EXTICR1_EXTI3_Reserve           (2UL<<24)     /*!< Reserve : Reserve                                               */
#define   EXTI_EXTICR1_EXTI3_PF3               (3UL<<24)     /*!< PF3 : PF3                                                       */

/* ==============================================  EXTI EXTICR1 EXTI2 [16..17]  ============================================== */
#define   EXTI_EXTICR1_EXTI2_PA2               (0UL<<16)     /*!< PA2 : PA2                                                       */
#define   EXTI_EXTICR1_EXTI2_PB2               (1UL<<16)     /*!< PB2 : PB2                                                       */
#define   EXTI_EXTICR1_EXTI2_Reserve           (2UL<<16)     /*!< Reserve : Reserve                                               */
#define   EXTI_EXTICR1_EXTI2_PF2               (3UL<<16)     /*!< PF2 : PF2                                                       */

/* ===============================================  EXTI EXTICR1 EXTI1 [8..9]  =============================================== */
#define   EXTI_EXTICR1_EXTI1_PA1               (0UL<<8)     /*!< PA1 : PA1                                                        */
#define   EXTI_EXTICR1_EXTI1_PB1               (1UL<<8)     /*!< PB1 : PB1                                                        */
#define   EXTI_EXTICR1_EXTI1_Reserve           (2UL<<8)     /*!< Reserve : Reserve                                                */
#define   EXTI_EXTICR1_EXTI1_PF1               (3UL<<8)     /*!< PF1 : PF1                                                        */

/* ===============================================  EXTI EXTICR1 EXTI0 [0..1]  =============================================== */
#define   EXTI_EXTICR1_EXTI0_PA0               (0UL<<0)     /*!< PA0 : PA0                                                        */
#define   EXTI_EXTICR1_EXTI0_PB0               (1UL<<0)     /*!< PB0 : PB0                                                        */
#define   EXTI_EXTICR1_EXTI0_Reserve           (2UL<<0)     /*!< Reserve : Reserve                                                */
#define   EXTI_EXTICR1_EXTI0_PF0               (3UL<<0)     /*!< PF0 : PF0                                                        */

/* ========================================================  EXTICR2  ======================================================== */
/* ==============================================  EXTI EXTICR2 EXTI7 [24..25]  ============================================== */
#define   EXTI_EXTICR2_EXTI7_PA7               (0UL<<24)     /*!< PA7 : PA7                                                       */
#define   EXTI_EXTICR2_EXTI7_PB7               (1UL<<24)     /*!< PB7 : PB7                                                       */
#define   EXTI_EXTICR2_EXTI7_Reserve           (2UL<<24)     /*!< Reserve : Reserve                                               */
#define   EXTI_EXTICR2_EXTI7_PF7               (3UL<<24)     /*!< PF7 : PF7                                                       */

/* ==============================================  EXTI EXTICR2 EXTI6 [16..17]  ============================================== */
#define   EXTI_EXTICR2_EXTI6_PA6               (0UL<<16)     /*!< PA6 : PA6                                                       */
#define   EXTI_EXTICR2_EXTI6_PB6               (1UL<<16)     /*!< PB6 : PB6                                                       */
#define   EXTI_EXTICR2_EXTI6_Reserve           (2UL<<16)     /*!< Reserve : Reserve                                               */
#define   EXTI_EXTICR2_EXTI6_PF6               (3UL<<16)     /*!< PF6 : PF6                                                       */

/* ===============================================  EXTI EXTICR2 EXTI4 [0..1]  =============================================== */
#define   EXTI_EXTICR2_EXTI4_PA4               (0UL<<0)     /*!< PA4 : PA4                                                        */
#define   EXTI_EXTICR2_EXTI4_PB4               (1UL<<0)     /*!< PB4 : PB4                                                        */
#define   EXTI_EXTICR2_EXTI4_Reserve           (2UL<<0)     /*!< Reserve : Reserve                                                */
#define   EXTI_EXTICR2_EXTI4_PF4               (3UL<<0)     /*!< PF4 : PF4                                                        */

/* ========================================================  EXTICR3  ======================================================== */
/* =============================================  EXTI EXTICR3 EXTI11 [24..25]  ============================================== */
#define   EXTI_EXTICR3_EXTI11_PA11             (0UL<<24)     /*!< PA11 : PA11                                                     */
#define   EXTI_EXTICR3_EXTI11_PB11             (1UL<<24)     /*!< PB11 : PB11                                                     */
#define   EXTI_EXTICR3_EXTI11_Reserve          (2UL<<24)     /*!< Reserve : Reserve                                               */

/* =============================================  EXTI EXTICR3 EXTI10 [16..17]  ============================================== */
#define   EXTI_EXTICR3_EXTI10_PA10             (0UL<<16)     /*!< PA10 : PA10                                                     */
#define   EXTI_EXTICR3_EXTI10_PB10             (1UL<<16)     /*!< PB10 : PB10                                                     */
#define   EXTI_EXTICR3_EXTI10_Reserve          (2UL<<16)     /*!< Reserve : Reserve                                               */

/* ===============================================  EXTI EXTICR3 EXTI9 [8..9]  =============================================== */
#define   EXTI_EXTICR3_EXTI9_PA9               (0UL<<8)     /*!< PA9 : PA9                                                        */
#define   EXTI_EXTICR3_EXTI9_PB9               (1UL<<8)     /*!< PB9 : PB9                                                        */
#define   EXTI_EXTICR3_EXTI9_Reserve           (2UL<<8)     /*!< Reserve : Reserve                                                */
#define   EXTI_EXTICR3_EXTI9_PF9               (3UL<<8)     /*!< PF9 : PF9                                                        */

/* ===============================================  EXTI EXTICR3 EXTI8 [0..1]  =============================================== */
#define   EXTI_EXTICR3_EXTI8_PA8               (0UL<<0)     /*!< PA8 : PA8                                                        */
#define   EXTI_EXTICR3_EXTI8_PB8               (1UL<<0)     /*!< PB8 : PB8                                                        */
#define   EXTI_EXTICR3_EXTI8_Reserve           (2UL<<0)     /*!< Reserve : Reserve                                                */
#define   EXTI_EXTICR3_EXTI8_PF8               (3UL<<0)     /*!< PF8 : PF8                                                        */

/* ========================================================  EXTICR4  ======================================================== */
/* =============================================  EXTI EXTICR4 EXTI15 [24..25]  ============================================== */
#define   EXTI_EXTICR4_EXTI15_PA15             (0UL<<24)     /*!< PA15 : PA15                                                     */
#define   EXTI_EXTICR4_EXTI15_PB15             (1UL<<24)     /*!< PB15 : PB15                                                     */
#define   EXTI_EXTICR4_EXTI15_PC15             (2UL<<24)     /*!< PC15 : PC15                                                     */
#define   EXTI_EXTICR4_EXTI15_Reserve          (3UL<<24)     /*!< Reserve : Reserve                                               */

/* =============================================  EXTI EXTICR4 EXTI14 [16..17]  ============================================== */
#define   EXTI_EXTICR4_EXTI14_PA14             (0UL<<16)     /*!< PA14 : PA14                                                     */
#define   EXTI_EXTICR4_EXTI14_PB14             (1UL<<16)     /*!< PB14 : PB14                                                     */
#define   EXTI_EXTICR4_EXTI14_PC14             (2UL<<16)     /*!< PC14 : PC14                                                     */
#define   EXTI_EXTICR4_EXTI14_Reserve          (3UL<<16)     /*!< Reserve : Reserve                                               */

/* ==============================================  EXTI EXTICR4 EXTI13 [8..9]  =============================================== */
#define   EXTI_EXTICR4_EXTI13_PA13             (0UL<<8)     /*!< PA13 : PA13                                                      */
#define   EXTI_EXTICR4_EXTI13_PB13             (1UL<<8)     /*!< PB13 : PB13                                                      */
#define   EXTI_EXTICR4_EXTI13_PC13             (2UL<<8)     /*!< PC13 : PC13                                                      */
#define   EXTI_EXTICR4_EXTI13_Reserve          (3UL<<8)     /*!< Reserve : Reserve                                                */

/* ==========================================================  IMR  ========================================================== */
/* ==========================================================  EMR  ========================================================== */


/* =========================================================================================================================== */
/* ================                                            ADC                                            ================ */
/* =========================================================================================================================== */

/* ==========================================================  SR  =========================================================== */
/* ==========================================================  CR1  ========================================================== */
/* ===============================================  ADC CR1 DISCNUM [16..19]  ================================================ */
#define   ADC_CR1_DISCNUM_1                    (0UL<<16)     /*!< 1 : 1 Channel                                                   */
#define   ADC_CR1_DISCNUM_2                    (1UL<<16)     /*!< 2 : 2 Channel                                                   */
#define   ADC_CR1_DISCNUM_3                    (2UL<<16)     /*!< 3 : 3 Channel                                                   */
#define   ADC_CR1_DISCNUM_4                    (3UL<<16)     /*!< 4 : 4 Channel                                                   */
#define   ADC_CR1_DISCNUM_5                    (4UL<<16)     /*!< 5 : 5 Channel                                                   */
#define   ADC_CR1_DISCNUM_6                    (5UL<<16)     /*!< 6 : 6 Channel                                                   */
#define   ADC_CR1_DISCNUM_7                    (6UL<<16)     /*!< 7 : 7 Channel                                                   */
#define   ADC_CR1_DISCNUM_8                    (7UL<<16)     /*!< 8 : 8 Channel                                                   */
#define   ADC_CR1_DISCNUM_9                    (8UL<<16)     /*!< 9 : 9 Channel                                                   */
#define   ADC_CR1_DISCNUM_10                   (9UL<<16)     /*!< 10 : 10 Channel                                                 */
#define   ADC_CR1_DISCNUM_11                   (10UL<<16)    /*!< 11 : 11 Channel                                                 */

/* =================================================  ADC CR1 AWDCH [0..4]  ================================================== */
#define   ADC_CR1_AWDCH_Res                    (0UL<<0)     /*!< Res : Res                                                        */
#define   ADC_CR1_AWDCH_1                      (1UL<<0)     /*!< 1 : ADC Analog Input Channel 1                                   */
#define   ADC_CR1_AWDCH_2                      (2UL<<0)     /*!< 2 : ADC Analog Input Channel 2                                   */
#define   ADC_CR1_AWDCH_3                      (3UL<<0)     /*!< 3 : ADC Analog Input Channel 3                                   */
#define   ADC_CR1_AWDCH_4                      (4UL<<0)     /*!< 4 : ADC Analog Input Channel 4                                   */
#define   ADC_CR1_AWDCH_5                      (5UL<<0)     /*!< 5 : ADC Analog Input Channel 5                                   */
#define   ADC_CR1_AWDCH_6                      (6UL<<0)     /*!< 6 : ADC Analog Input Channel 6                                   */
#define   ADC_CR1_AWDCH_7                      (7UL<<0)     /*!< 7 : ADC Analog Input Channel 7                                   */
#define   ADC_CR1_AWDCH_8                      (8UL<<0)     /*!< 8 : ADC Analog Input Channel 8                                   */
#define   ADC_CR1_AWDCH_9                      (9UL<<0)     /*!< 9 : ADC Analog Input Channel 9                                   */
#define   ADC_CR1_AWDCH_10                     (10UL<<0)    /*!< 10 : ADC Analog Input Channel 10                                 */
#define   ADC_CR1_AWDCH_11                     (11UL<<0)    /*!< 11 : ADC Analog Input Channel 11                                 */
#define   ADC_CR1_AWDCH_12                     (12UL<<0)    /*!< 12 : ADC Analog Input Channel 12                                 */
#define   ADC_CR1_AWDCH_13                     (13UL<<0)    /*!< 13 : ADC Analog Input Channel 13                                 */
#define   ADC_CR1_AWDCH_14                     (14UL<<0)    /*!< 14 : ADC Analog Input Channel 14                                 */
#define   ADC_CR1_AWDCH_15                     (15UL<<0)    /*!< 15 : ADC Analog Input Channel 15                                 */
#define   ADC_CR1_AWDCH_16                     (16UL<<0)    /*!< 16 : ADC Analog Input Channel 16                                 */
#define   ADC_CR1_AWDCH_17                     (17UL<<0)    /*!< 17 : ADC Analog Input Channel 17                                 */
#define   ADC_CR1_AWDCH_18                     (18UL<<0)    /*!< 18 : ADC Analog Input Channel 18                                 */
#define   ADC_CR1_AWDCH_19                     (19UL<<0)    /*!< 19 : ADC Analog Input Channel 19                                 */
#define   ADC_CR1_AWDCH_20                     (20UL<<0)    /*!< 20 : ADC Analog Input Channel 20                                 */

/* ==========================================================  CR2  ========================================================== */
/* ================================================  ADC CR2 CKMODE [28..31]  ================================================ */
#define   ADC_CR2_CKMODE_PCLK                  (0UL<<28)     /*!< PCLK : PCLK                                                     */
#define   ADC_CR2_CKMODE_PCLK2                 (1UL<<28)     /*!< PCLK2 : PCLK2                                                   */
#define   ADC_CR2_CKMODE_PCLK4                 (2UL<<28)     /*!< PCLK4 : PCLK4                                                   */
#define   ADC_CR2_CKMODE_PCLK6                 (3UL<<28)     /*!< PCLK6 : PCLK6                                                   */
#define   ADC_CR2_CKMODE_PCLK8                 (4UL<<28)     /*!< PCLK8 : PCLK8                                                   */
#define   ADC_CR2_CKMODE_HSI                   (5UL<<28)     /*!< HSI : HSI                                                       */
#define   ADC_CR2_CKMODE_HSI2                  (6UL<<28)     /*!< HSI2 : HSI2                                                     */
#define   ADC_CR2_CKMODE_HSI4                  (7UL<<28)     /*!< HSI4 : HSI4                                                     */
#define   ADC_CR2_CKMODE_HSI6                  (8UL<<28)     /*!< HSI6 : HSI6                                                     */
#define   ADC_CR2_CKMODE_HSI8                  (9UL<<28)     /*!< HSI8 : HSI8                                                     */

/* ================================================  ADC CR2 EXTSEL [17..19]  ================================================ */
#define   ADC_CR2_EXTSEL_T1CC1                 (0UL<<17)     /*!< T1CC1 : T1CC1                                                   */
#define   ADC_CR2_EXTSEL_T1CC2                 (1UL<<17)     /*!< T1CC2 : T1CC2                                                   */
#define   ADC_CR2_EXTSEL_T1CC3                 (2UL<<17)     /*!< T1CC3 : T1CC3                                                   */
#define   ADC_CR2_EXTSEL_T3CC2                 (3UL<<17)     /*!< T3CC2 : T3CC2                                                   */
#define   ADC_CR2_EXTSEL_T15CC2                (4UL<<17)     /*!< T15CC2 : T15CC2                                                 */
#define   ADC_CR2_EXTSEL_T15TRGO               (5UL<<17)     /*!< T15TRGO : T15TRGO                                               */
#define   ADC_CR2_EXTSEL_EXTI4                 (6UL<<17)     /*!< EXTI4 : EXTI4                                                   */
#define   ADC_CR2_EXTSEL_SWSTART               (7UL<<17)     /*!< SWSTART : SWSTART                                               */

/* ===============================================  ADC CR2 JEXTSEL [12..14]  ================================================ */
#define   ADC_CR2_JEXTSEL_TIM1_TRGO            (0UL<<12)     /*!< TIM1_TRGO : TIM1_TRGO                                           */
#define   ADC_CR2_JEXTSEL_TIM1_CC4             (1UL<<12)     /*!< TIM1_CC4 : TIM1_CC4                                             */
#define   ADC_CR2_JEXTSEL_TIM1_CC3             (2UL<<12)     /*!< TIM1_CC3 : TIM1_CC3                                             */
#define   ADC_CR2_JEXTSEL_TIM3_CC1             (3UL<<12)     /*!< TIM3_CC1 : TIM3_CC1                                             */
#define   ADC_CR2_JEXTSEL_TIM3_TRGO            (4UL<<12)     /*!< TIM3_TRGO : TIM3_TRGO                                           */
#define   ADC_CR2_JEXTSEL_TIM15_CC1            (5UL<<12)     /*!< TIM15_CC1 : TIM15_CC1                                           */
#define   ADC_CR2_JEXTSEL_EXTI9                (6UL<<12)     /*!< EXTI9 : EXTI9                                                   */
#define   ADC_CR2_JEXTSEL_SWSTART              (7UL<<12)     /*!< SWSTART : SWSTART                                               */

/* ==================================================  ADC CR2 CUR [4..5]  =================================================== */
#define   ADC_CR2_CUR_00                       (0UL<<4)     /*!< 00 : vcm_buffer=8uA,comp=16uA                                    */
#define   ADC_CR2_CUR_01                       (1UL<<4)     /*!< 01 : vcm_buffer=10uA,comp=20uA default                           */
#define   ADC_CR2_CUR_10                       (2UL<<4)     /*!< 10 : vcm_buffer=12uA,comp=24uA                                   */
#define   ADC_CR2_CUR_11                       (3UL<<4)     /*!< 11 : vcm_buffer=12uA,comp=28uA                                   */

/* =========================================================  SMPR  ========================================================== */
/* ==================================================  ADC SMPR SMP [0..3]  ================================================== */
#define   ADC_SMPR_SMP_1_5                     (0UL<<0)     /*!< 1_5 : 1.5 cycles                                                 */
#define   ADC_SMPR_SMP_2_5                     (1UL<<0)     /*!< 2_5 : 2.5 cycles                                                 */
#define   ADC_SMPR_SMP_3_5                     (2UL<<0)     /*!< 3_5 : 3.5 cycles                                                 */
#define   ADC_SMPR_SMP_4_5                     (3UL<<0)     /*!< 4_5 : 4.5 cycles                                                 */
#define   ADC_SMPR_SMP_5_5                     (4UL<<0)     /*!< 5_5 : 5.5 cycles                                                 */
#define   ADC_SMPR_SMP_6_5                     (5UL<<0)     /*!< 6_5 : 6.5 cycles                                                 */
#define   ADC_SMPR_SMP_7_5                     (6UL<<0)     /*!< 7_5 : 7.5 cycles                                                 */
#define   ADC_SMPR_SMP_8_5                     (7UL<<0)     /*!< 8_5 : 8.5 cycles                                                 */
#define   ADC_SMPR_SMP_9_5                     (8UL<<0)     /*!< 9_5 : 9.5 cycles                                                 */
#define   ADC_SMPR_SMP_10_5                    (9UL<<0)     /*!< 10_5 : 10.5 cycles                                               */
#define   ADC_SMPR_SMP_11_5                    (10UL<<0)    /*!< 11_5 : 11.5 cycles                                               */
#define   ADC_SMPR_SMP_15_5                    (11UL<<0)    /*!< 15_5 : 15.5 cycles                                               */
#define   ADC_SMPR_SMP_31_5                    (12UL<<0)    /*!< 31_5 : 31.5 cycles                                               */
#define   ADC_SMPR_SMP_63_5                    (13UL<<0)    /*!< 63_5 : 63.5 cycles                                               */
#define   ADC_SMPR_SMP_127_5                   (14UL<<0)    /*!< 127_5 : 127.5 cycles                                             */
#define   ADC_SMPR_SMP_255_5                   (15UL<<0)    /*!< 255_5 : 255.5 cycles                                             */

/* =========================================================  JOFR1  ========================================================= */
/* =========================================================  JOFR2  ========================================================= */
/* =========================================================  JOFR3  ========================================================= */
/* =========================================================  JOFR4  ========================================================= */
/* =========================================================  JOFR5  ========================================================= */
/* ==========================================================  HTR  ========================================================== */
/* ==========================================================  LTR  ========================================================== */
/* =========================================================  SQR1  ========================================================== */
/* ==================================================  ADC SQR1 L [10..14]  ================================================== */
#define   ADC_SQR1_L_1                         (0UL<<10)     /*!< 1 : 1 Conversion                                                */
#define   ADC_SQR1_L_2                         (1UL<<10)     /*!< 2 : 2 Conversion                                                */
#define   ADC_SQR1_L_3                         (2UL<<10)     /*!< 3 : 3 Conversion                                                */
#define   ADC_SQR1_L_4                         (3UL<<10)     /*!< 4 : 4 Conversion                                                */
#define   ADC_SQR1_L_5                         (4UL<<10)     /*!< 5 : 5 Conversion                                                */
#define   ADC_SQR1_L_6                         (5UL<<10)     /*!< 6 : 6 Conversion                                                */
#define   ADC_SQR1_L_7                         (6UL<<10)     /*!< 7 : 7 Conversion                                                */
#define   ADC_SQR1_L_8                         (7UL<<10)     /*!< 8 : 8 Conversion                                                */
#define   ADC_SQR1_L_9                         (8UL<<10)     /*!< 9 : 9 Conversion                                                */
#define   ADC_SQR1_L_10                        (9UL<<10)     /*!< 10 : 10 Conversion                                              */
#define   ADC_SQR1_L_11                        (10UL<<10)    /*!< 11 : 11 Conversion                                              */
#define   ADC_SQR1_L_12                        (11UL<<10)    /*!< 12 : 12 Conversion                                              */
#define   ADC_SQR1_L_13                        (12UL<<10)    /*!< 13 : 13 Conversion                                              */
#define   ADC_SQR1_L_14                        (13UL<<10)    /*!< 14 : 14 Conversion                                              */
#define   ADC_SQR1_L_15                        (14UL<<10)    /*!< 15 : 15 Conversion                                              */
#define   ADC_SQR1_L_16                        (15UL<<10)    /*!< 16 : 16 Conversion                                              */
#define   ADC_SQR1_L_17                        (16UL<<10)    /*!< 17 : 17 Conversion                                              */
#define   ADC_SQR1_L_18                        (17UL<<10)    /*!< 18 : 18 Conversion                                              */
#define   ADC_SQR1_L_19                        (18UL<<10)    /*!< 19 : 19 Conversion                                              */
#define   ADC_SQR1_L_20                        (19UL<<10)    /*!< 20 : 20 Conversion                                              */

/* =========================================================  SQR2  ========================================================== */
/* =========================================================  SQR3  ========================================================== */
/* =========================================================  SQR4  ========================================================== */
/* =========================================================  JSQR  ========================================================== */
/* =================================================  ADC JSQR JL [25..27]  ================================================== */
#define   ADC_JSQR_JL_1                        (0UL<<25)     /*!< 1 : 1 Conversion                                                */
#define   ADC_JSQR_JL_2                        (1UL<<25)     /*!< 2 : 2 Conversion                                                */
#define   ADC_JSQR_JL_3                        (2UL<<25)     /*!< 3 : 3 Conversion                                                */
#define   ADC_JSQR_JL_4                        (3UL<<25)     /*!< 4 : 4 Conversion                                                */
#define   ADC_JSQR_JL_5                        (4UL<<25)     /*!< 5 : 5 Conversion                                                */

/* =========================================================  JDR1  ========================================================== */
/* =========================================================  JDR2  ========================================================== */
/* =========================================================  JDR3  ========================================================== */
/* =========================================================  JDR4  ========================================================== */
/* =========================================================  JDR5  ========================================================== */
/* ==========================================================  DR  =========================================================== */


/* =========================================================================================================================== */
/* ================                                           COMP1                                           ================ */
/* =========================================================================================================================== */

/* ==========================================================  CSR  ========================================================== */
/* ==============================================  COMP1 CSR PWRMODE [18..19]  =============================================== */
#define   COMP_CSR_PWRMODE_00                 (0UL<<18)     /*!< 00 : High                                                       */
#define   COMP_CSR_PWRMODE_01                 (1UL<<18)     /*!< 01 : Low                                                        */
#define   COMP_CSR_PWRMODE_10                 (2UL<<18)     /*!< 10 : Reserved                                                   */
#define   COMP_CSR_PWRMODE_11                 (3UL<<18)     /*!< 11 : Reserved                                                   */

/* ===============================================  COMP1 CSR INPSEL [8..10]  ================================================ */
#define   COMP_CSR_INPSEL_PF4                 (0UL<<8)     /*!< PF4 : PF4                                                        */
#define   COMP_CSR_INPSEL_PB2                 (5UL<<8)     /*!< PB2 : PB2                                                        */
#define   COMP_CSR_INPSEL_PA3                 (7UL<<8)     /*!< PA3 : PA3                                                        */

/* ================================================  COMP1 CSR INMSEL [4..7]  ================================================ */
#define   COMP_CSR_INMSEL_14                  (0UL<<4)     /*!< 14 : 1/4 VREFINT                                                 */
#define   COMP_CSR_INMSEL_12                  (1UL<<4)     /*!< 12 : 1/2 VREFINT                                                 */
#define   COMP_CSR_INMSEL_34                  (2UL<<4)     /*!< 34 : 3/4 VREFINT                                                 */
#define   COMP_CSR_INMSEL_VREFINT             (3UL<<4)     /*!< VREFINT : VREFINT                                                */
#define   COMP_CSR_INMSEL_PB7                 (4UL<<4)     /*!< PB7 : PB7                                                        */
#define   COMP_CSR_INMSEL_PA0                 (8UL<<4)     /*!< PA0 : PA0                                                        */
#define   COMP_CSR_INMSEL_PB3                 (13UL<<4)    /*!< PB3 : PB3                                                        */
#define   COMP_CSR_INMSEL_PB1                 (14UL<<4)    /*!< PB1 : PB1                                                        */

/* ==========================================================  FR  =========================================================== */


/* =========================================================================================================================== */
/* ================                                           COMP2                                           ================ */
/* =========================================================================================================================== */

/* ==========================================================  CSR  ========================================================== */
/* ==============================================  COMP2 CSR PWRMODE [18..19]  =============================================== */
#define   COMP2_CSR_PWRMODE_00                 (0UL<<18)     /*!< 00 : High                                                       */
#define   COMP2_CSR_PWRMODE_01                 (1UL<<18)     /*!< 01 : Low                                                        */
#define   COMP2_CSR_PWRMODE_10                 (2UL<<18)     /*!< 10 : Reserved                                                   */
#define   COMP2_CSR_PWRMODE_11                 (3UL<<18)     /*!< 11 : Reserved                                                   */

/* ===============================================  COMP2 CSR INPSEL [8..10]  ================================================ */
#define   COMP2_CSR_INPSEL_PF4                 (0UL<<8)     /*!< PF4 : PF4                                                        */
#define   COMP2_CSR_INPSEL_PA3                 (5UL<<8)     /*!< PA3 : PA3                                                        */
#define   COMP2_CSR_INPSEL_PA1                 (7UL<<8)     /*!< PA1 : PA1                                                        */

/* ================================================  COMP2 CSR INMSEL [4..7]  ================================================ */
#define   COMP2_CSR_INMSEL_14                  (0UL<<4)     /*!< 14 : 1/4 VREFINT                                                 */
#define   COMP2_CSR_INMSEL_12                  (1UL<<4)     /*!< 12 : 1/2 VREFINT                                                 */
#define   COMP2_CSR_INMSEL_34                  (2UL<<4)     /*!< 34 : 3/4 VREFINT                                                 */
#define   COMP2_CSR_INMSEL_VREFINT             (3UL<<4)     /*!< VREFINT : VREFINT                                                */
#define   COMP2_CSR_INMSEL_PA4                 (4UL<<4)     /*!< PA4 : PA4                                                        */
#define   COMP2_CSR_INMSEL_PA2                 (8UL<<4)     /*!< PA2 : PA2                                                        */
#define   COMP2_CSR_INMSEL_PB7                 (13UL<<4)    /*!< PB7 : PB7                                                        */
#define   COMP2_CSR_INMSEL_PA5                 (14UL<<4)    /*!< PA5 : PA5                                                        */

/* ==========================================================  FR  =========================================================== */


/* =========================================================================================================================== */
/* ================                                           COMP3                                           ================ */
/* =========================================================================================================================== */

/* ==========================================================  CSR  ========================================================== */
/* ==============================================  COMP3 CSR PWRMODE [18..19]  =============================================== */
#define   COMP3_CSR_PWRMODE_00                 (0UL<<18)     /*!< 00 : High                                                       */
#define   COMP3_CSR_PWRMODE_01                 (1UL<<18)     /*!< 01 : Low                                                        */
#define   COMP3_CSR_PWRMODE_10                 (2UL<<18)     /*!< 10 : Reserved                                                   */
#define   COMP3_CSR_PWRMODE_11                 (3UL<<18)     /*!< 11 : Reserved                                                   */

/* ===============================================  COMP3 CSR INPSEL [8..10]  ================================================ */
#define   COMP3_CSR_INPSEL_PA1                 (0UL<<8)     /*!< PA1 : PA1                                                        */
#define   COMP3_CSR_INPSEL_PB0                 (5UL<<8)     /*!< PB0 : PB0                                                        */
#define   COMP3_CSR_INPSEL_PA5                 (7UL<<8)     /*!< PA5 : PA5                                                        */

/* ================================================  COMP3 CSR INMSEL [4..7]  ================================================ */
#define   COMP3_CSR_INMSEL_14                  (0UL<<4)     /*!< 14 : 1/4 VREFINT                                                 */
#define   COMP3_CSR_INMSEL_12                  (1UL<<4)     /*!< 12 : 1/2 VREFINT                                                 */
#define   COMP3_CSR_INMSEL_34                  (2UL<<4)     /*!< 34 : 3/4 VREFINT                                                 */
#define   COMP3_CSR_INMSEL_VREFINT             (3UL<<4)     /*!< VREFINT : VREFINT                                                */
#define   COMP3_CSR_INMSEL_PB2                 (4UL<<4)     /*!< PB2 : PB2                                                        */
#define   COMP3_CSR_INMSEL_PA2                 (8UL<<4)     /*!< PA2 : PA2                                                        */
#define   COMP3_CSR_INMSEL_PB13                (13UL<<4)    /*!< PB13 : PB13                                                      */
#define   COMP3_CSR_INMSEL_PB5                 (14UL<<4)    /*!< PB5 : PB5                                                        */

/* ==========================================================  FR  =========================================================== */


/* =========================================================================================================================== */
/* ================                                           COMP4                                           ================ */
/* =========================================================================================================================== */

/* ==========================================================  CSR  ========================================================== */
/* ==============================================  COMP4 CSR PWRMODE [18..19]  =============================================== */
#define   COMP4_CSR_PWRMODE_00                 (0UL<<18)     /*!< 00 : High                                                       */
#define   COMP4_CSR_PWRMODE_01                 (1UL<<18)     /*!< 01 : Low                                                        */
#define   COMP4_CSR_PWRMODE_10                 (2UL<<18)     /*!< 10 : Reserved                                                   */
#define   COMP4_CSR_PWRMODE_11                 (3UL<<18)     /*!< 11 : Reserved                                                   */

/* ===============================================  COMP4 CSR INPSEL [8..10]  ================================================ */
#define   COMP4_CSR_INPSEL_PA0                 (0UL<<8)     /*!< PA0 : PA0                                                        */
#define   COMP4_CSR_INPSEL_PB3                 (5UL<<8)     /*!< PB3 : PB3                                                        */
#define   COMP4_CSR_INPSEL_PA5                 (7UL<<8)     /*!< PA5 : PA5                                                        */

/* ================================================  COMP4 CSR INMSEL [4..7]  ================================================ */
#define   COMP4_CSR_INMSEL_14                  (0UL<<4)     /*!< 14 : 1/4 VREFINT                                                 */
#define   COMP4_CSR_INMSEL_12                  (1UL<<4)     /*!< 12 : 1/2 VREFINT                                                 */
#define   COMP4_CSR_INMSEL_34                  (2UL<<4)     /*!< 34 : 3/4 VREFINT                                                 */
#define   COMP4_CSR_INMSEL_VREFINT             (3UL<<4)     /*!< VREFINT : VREFINT                                                */
#define   COMP4_CSR_INMSEL_PA4                 (4UL<<4)     /*!< PA4 : PA4                                                        */
#define   COMP4_CSR_INMSEL_PA1                 (8UL<<4)     /*!< PA1 : PA1                                                        */
#define   COMP4_CSR_INMSEL_PB13                (13UL<<4)    /*!< PB13 : PB13                                                      */
#define   COMP4_CSR_INMSEL_PB1                 (14UL<<4)    /*!< PB1 : PB1                                                        */

/* ==========================================================  FR  =========================================================== */


/* =========================================================================================================================== */
/* ================                                            LED                                            ================ */
/* =========================================================================================================================== */

/* =========================================================  ICDR  ========================================================== */
/* =========================================================  OTCR  ========================================================== */
/* ==========================================================  GCR  ========================================================== */
/* ==============================================  LED GCR SCAN_FIRST [12..15]  ============================================== */
#define   LED_GCR_SCAN_FIRST_LED0              (0UL<<12)     /*!< LED0 : LED0                                                     */
#define   LED_GCR_SCAN_FIRST_LED1              (1UL<<12)     /*!< LED1 : LED1                                                     */
#define   LED_GCR_SCAN_FIRST_LED2              (2UL<<12)     /*!< LED2 : LED2                                                     */
#define   LED_GCR_SCAN_FIRST_LED3              (3UL<<12)     /*!< LED3 : LED3                                                     */
#define   LED_GCR_SCAN_FIRST_LED4              (4UL<<12)     /*!< LED4 : LED4                                                     */
#define   LED_GCR_SCAN_FIRST_LED5              (5UL<<12)     /*!< LED5 : LED5                                                     */
#define   LED_GCR_SCAN_FIRST_LED6              (6UL<<12)     /*!< LED6 : LED6                                                     */
#define   LED_GCR_SCAN_FIRST_LED7              (7UL<<12)     /*!< LED7 : LED7                                                     */
#define   LED_GCR_SCAN_FIRST_LED8              (8UL<<12)     /*!< LED8 : LED8                                                     */

/* ==============================================  LED GCR ARRAY_MODE [9..11]  =============================================== */
#define   LED_GCR_ARRAY_MODE_None              (0UL<<9)     /*!< None : No ARRAY                                                  */
#define   LED_GCR_ARRAY_MODE_44                (1UL<<9)     /*!< 44 : 4*4 ARRAY                                                   */
#define   LED_GCR_ARRAY_MODE_55                (2UL<<9)     /*!< 55 : 5*5 ARRAY                                                   */
#define   LED_GCR_ARRAY_MODE_66                (3UL<<9)     /*!< 66 : 6*6 ARRAY                                                   */
#define   LED_GCR_ARRAY_MODE_67                (4UL<<9)     /*!< 67 : 6*7 ARRAY                                                   */
#define   LED_GCR_ARRAY_MODE_77                (5UL<<9)     /*!< 77 : 7*7 ARRAY                                                   */
#define   LED_GCR_ARRAY_MODE_78                (6UL<<9)     /*!< 78 : 7*8 ARRAY                                                   */
#define   LED_GCR_ARRAY_MODE_88                (7UL<<9)     /*!< 88 : 8*8 ARRAY                                                   */

/* =========================================================  SCR1  ========================================================== */
/* =========================================================  SCR2  ========================================================== */
/* =========================================================  OPSR1  ========================================================= */
/* =========================================================  OPSR2  ========================================================= */
/* ========================================================  COMENR  ========================================================= */


/* =========================================================================================================================== */
/* ================                                          VREFBUF                                          ================ */
/* =========================================================================================================================== */

/* ==========================================================  CSR  ========================================================== */
/* ==============================================  VREFBUF CSR VREF_SEL [1..2]  ============================================== */
#define   VREFBUF_CSR_VREF_SEL_VREF            (0UL<<1)     /*!< VREF : VREF                                                      */
#define   VREFBUF_CSR_VREF_SEL_VCC             (2UL<<1)     /*!< VCC : VCC                                                        */
#define   VREFBUF_CSR_VREF_SEL_VREFBUF         (3UL<<1)     /*!< VREFBUF : VREFBUF                                                */

/* ==========================================================  CCR  ========================================================== */


/* =========================================================================================================================== */
/* ================                                            CRC                                            ================ */
/* =========================================================================================================================== */

/* ==========================================================  SR  =========================================================== */
/* ========================================================  RESULT  ========================================================= */
/* =========================================================  DATA  ========================================================== */


/* =========================================================================================================================== */
/* ================                                           I2C1                                            ================ */
/* =========================================================================================================================== */

/* ==========================================================  CR1  ========================================================== */
/* =================================================  I2C1 CR1 DNF [8..11]  ================================================== */
#define   I2C_CR1_DNF_None                    (0UL<<8)     /*!< None : None                                                      */
#define   I2C_CR1_DNF_1                       (1UL<<8)     /*!< 1 : Enable digital filters-1*tI2C_CLK                            */
#define   I2C_CR1_DNF_2                       (2UL<<8)     /*!< 2 : Enable digital filters-2*tI2C_CLK                            */
#define   I2C_CR1_DNF_3                       (3UL<<8)     /*!< 3 : Enable digital filters-3*tI2C_CLK                            */
#define   I2C_CR1_DNF_4                       (4UL<<8)     /*!< 4 : Enable digital filters-4*tI2C_CLK                            */
#define   I2C_CR1_DNF_5                       (5UL<<8)     /*!< 5 : Enable digital filters-5*tI2C_CLK                            */
#define   I2C_CR1_DNF_6                       (6UL<<8)     /*!< 6 : Enable digital filters-6*tI2C_CLK                            */
#define   I2C_CR1_DNF_7                       (7UL<<8)     /*!< 7 : Enable digital filters-7*tI2C_CLK                            */
#define   I2C_CR1_DNF_8                       (8UL<<8)     /*!< 8 : Enable digital filters-8*tI2C_CLK                            */
#define   I2C_CR1_DNF_9                       (9UL<<8)     /*!< 9 : Enable digital filters-9*tI2C_CLK                            */
#define   I2C_CR1_DNF_10                      (10UL<<8)    /*!< 10 : Enable digital filters-10*tI2C_CLK                          */
#define   I2C_CR1_DNF_11                      (11UL<<8)    /*!< 11 : Enable digital filters-11*tI2C_CLK                          */
#define   I2C_CR1_DNF_12                      (12UL<<8)    /*!< 12 : Enable digital filters-12*tI2C_CLK                          */
#define   I2C_CR1_DNF_13                      (13UL<<8)    /*!< 13 : Enable digital filters-13*tI2C_CLK                          */
#define   I2C_CR1_DNF_14                      (14UL<<8)    /*!< 14 : Enable digital filters-14*tI2C_CLK                          */
#define   I2C_CR1_DNF_15                      (15UL<<8)    /*!< 15 : Enable digital filters-15*tI2C_CLK                          */

/* ==========================================================  CR2  ========================================================== */
/* =========================================================  OAR1  ========================================================== */
/* =========================================================  OAR2  ========================================================== */
/* ===============================================  I2C1 OAR2 OA2MSK [8..10]  ================================================ */
#define   I2C_OAR2_OA2MSK_000                 (0UL<<8)     /*!< 000 : No Mask                                                    */
#define   I2C_OAR2_OA2MSK_001                 (1UL<<8)     /*!< 001 : Mask OA2[1],Compare only OA2[7:2]                          */
#define   I2C_OAR2_OA2MSK_010                 (2UL<<8)     /*!< 010 : Mask OA2[2:1],Compare only OA2[7:3]                        */
#define   I2C_OAR2_OA2MSK_011                 (3UL<<8)     /*!< 011 : Mask OA2[3:1],Compare only OA2[7:4]                        */
#define   I2C_OAR2_OA2MSK_100                 (4UL<<8)     /*!< 100 : Mask OA2[4:1],Compare only OA2[7:5]                        */
#define   I2C_OAR2_OA2MSK_101                 (5UL<<8)     /*!< 101 : Mask OA2[5:1],Compare only OA2[7:6]                        */
#define   I2C_OAR2_OA2MSK_110                 (6UL<<8)     /*!< 110 : Mask OA2[6:1],Compare only OA2[7]                          */
#define   I2C_OAR2_OA2MSK_111                 (7UL<<8)     /*!< 111 : Mask OA2[7:1],No Compare                                   */

/* ========================================================  TIMINGR  ======================================================== */
/* ==========================================================  ISR  ========================================================== */
/* ==========================================================  ICR  ========================================================== */
/* =========================================================  RXDR  ========================================================== */
/* =========================================================  TXDR  ========================================================== */


/* =========================================================================================================================== */
/* ================                                           UART1                                           ================ */
/* =========================================================================================================================== */

/* ==========================================================  CR1  ========================================================== */
/* ==========================================================  CR2  ========================================================== */
/* ===============================================  UART1 CR2 ABRMOD [21..22]  =============================================== */
#define   UART_CR2_ABRMOD_00                  (0UL<<21)     /*!< 00 : Measuring the start bit                                    */
#define   UART_CR2_ABRMOD_01                  (1UL<<21)     /*!< 01 : Falling edge measurement                                   */
#define   UART_CR2_ABRMOD_Reserve             (2UL<<21)     /*!< Reserve : Reserve                                               */

/* ================================================  UART1 CR2 STOP [12..13]  ================================================ */
#define   UART_CR2_STOP_1                     (0UL<<12)     /*!< 1 : 1 STOP bit                                                  */
#define   UART_CR2_STOP_01                    (1UL<<12)     /*!< 01 : Reserved                                                   */
#define   UART_CR2_STOP_2                     (2UL<<12)     /*!< 2 : 2 STOP bits                                                 */
#define   UART_CR2_STOP_11                    (3UL<<12)     /*!< 11 : Reserved                                                   */

/* ==========================================================  CR3  ========================================================== */
/* ==========================================================  BRR  ========================================================== */
/* =========================================================  RTOR  ========================================================== */
/* ==========================================================  RQR  ========================================================== */
/* ==========================================================  ISR  ========================================================== */
/* ==========================================================  ICR  ========================================================== */
/* ==========================================================  RDR  ========================================================== */
/* ==========================================================  TDR  ========================================================== */


/* =========================================================================================================================== */
/* ================                                           WWDG                                            ================ */
/* =========================================================================================================================== */

/* ==========================================================  CR  =========================================================== */
/* ==========================================================  CFR  ========================================================== */
/* =================================================  WWDG CFR WDGTB [7..8]  ================================================= */
#define   WWDG_CFR_WDGTB_00                    (0UL<<7)     /*!< 00 : PCLK/4096/1                                                 */
#define   WWDG_CFR_WDGTB_01                    (1UL<<7)     /*!< 01 : PCLK/4096/2                                                 */
#define   WWDG_CFR_WDGTB_10                    (2UL<<7)     /*!< 10 : PCLK/4096/4                                                 */
#define   WWDG_CFR_WDGTB_11                    (3UL<<7)     /*!< 11 : PCLK/4096/8                                                 */

/* ==========================================================  SR  =========================================================== */


/* =========================================================================================================================== */
/* ================                                           IWDG                                            ================ */
/* =========================================================================================================================== */

/* ==========================================================  KR  =========================================================== */
/* ==========================================================  PR  =========================================================== */
/* ===================================================  IWDG PR PR [0..2]  =================================================== */
#define   IWDG_PR_PR_4                         (0UL<<0)     /*!< 4 : 4 frequency division                                         */
#define   IWDG_PR_PR_8                         (1UL<<0)     /*!< 8 : 8 frequency division                                         */
#define   IWDG_PR_PR_16                        (2UL<<0)     /*!< 16 : 16 frequency division                                       */
#define   IWDG_PR_PR_32                        (3UL<<0)     /*!< 32 : 32 frequency division                                       */
#define   IWDG_PR_PR_64                        (4UL<<0)     /*!< 64 : 64 frequency division                                       */
#define   IWDG_PR_PR_128                       (5UL<<0)     /*!< 128 : 128 frequency division                                     */
#define   IWDG_PR_PR_256                       (6UL<<0)     /*!< 256 : 256 frequency division                                     */

/* ==========================================================  RLR  ========================================================== */
/* ==========================================================  SR  =========================================================== */
/* =========================================================  WINR  ========================================================== */


/* =========================================================================================================================== */
/* ================                                            RTC                                            ================ */
/* =========================================================================================================================== */

/* =========================================================  ICSR  ========================================================== */
/* =========================================================  PRER  ========================================================== */
/* ==========================================================  CR  =========================================================== */
/* ==========================================================  WPR  ========================================================== */
/* =========================================================  CALR  ========================================================== */
/* ==========================================================  SR  =========================================================== */
/* ==========================================================  SCR  ========================================================== */


/* =========================================================================================================================== */
/* ================                                           LPTIM                                           ================ */
/* =========================================================================================================================== */

/* ==========================================================  CNT  ========================================================== */
/* ==========================================================  ARR  ========================================================== */
/* ==========================================================  CR  =========================================================== */
/* =========================================================  OVFR  ========================================================== */
/* =========================================================  OCLR  ========================================================== */


/* =========================================================================================================================== */
/* ================                                           TIM                                            ================ */
/* =========================================================================================================================== */

/* ==========================================================  CR1  ========================================================== */
/* ==================================================  TIM CR1 CKD [8..9]  ================================================== */
#define   TIM_CR1_CKD_tCK_INT                 (0UL<<8)     /*!< tCK_INT : tCK_INT                                                */
#define   TIM_CR1_CKD_2tCK_INT                (1UL<<8)     /*!< 2tCK_INT : 2tCK_INT                                              */
#define   TIM_CR1_CKD_4tCK_INT                (2UL<<8)     /*!< 4tCK_INT : 4tCK_INT                                              */
#define   TIM_CR1_CKD_Reserve                 (3UL<<8)     /*!< Reserve : No configuration                                       */

/* ==================================================  TIM CR1 CMS [5..6]  ================================================== */
#define   TIM_CR1_CMS_00                      (0UL<<5)     /*!< 00 : Edge alignment mode                                         */
#define   TIM_CR1_CMS_01                      (1UL<<5)     /*!< 01 : Center alignment mode 1                                     */
#define   TIM_CR1_CMS_10                      (2UL<<5)     /*!< 10 : Center alignment mode 2                                     */
#define   TIM_CR1_CMS_11                      (3UL<<5)     /*!< 11 : Center alignment mode 3                                     */

/* ==========================================================  CR2  ========================================================== */
/* ==================================================  TIM CR2 MMS [4..6]  ================================================== */
#define   TIM_CR2_MMS_Reset                   (0UL<<4)     /*!< Reset : Reset                                                    */
#define   TIM_CR2_MMS_001                     (1UL<<4)     /*!< 001 : Enable                                                     */
#define   TIM_CR2_MMS_010                     (2UL<<4)     /*!< 010 : Update                                                     */
#define   TIM_CR2_MMS_011                     (3UL<<4)     /*!< 011 : Comparison Pulse                                           */
#define   TIM_CR2_MMS_100                     (4UL<<4)     /*!< 100 : Compare-OC1REF                                             */
#define   TIM_CR2_MMS_101                     (5UL<<4)     /*!< 101 : Compare-OC2REF                                             */
#define   TIM_CR2_MMS_110                     (6UL<<4)     /*!< 110 : Compare-OC3REF                                             */
#define   TIM_CR2_MMS_111                     (7UL<<4)     /*!< 111 : Compare-OC4REF                                             */

/* =========================================================  SMCR  ========================================================== */
/* ================================================  TIM SMCR ETPS [12..13]  ================================================ */
#define   TIM_SMCR_ETPS_Close                 (0UL<<12)     /*!< Close : Close                                                   */
#define   TIM_SMCR_ETPS_2                     (1UL<<12)     /*!< 2 : 2 division of ETRP frequency                                */
#define   TIM_SMCR_ETPS_4                     (2UL<<12)     /*!< 4 : 4 division of ETRP frequency                                */
#define   TIM_SMCR_ETPS_8                     (3UL<<12)     /*!< 8 : 8 division of ETRP frequency                                */

/* =================================================  TIM SMCR ETF [8..11]  ================================================= */
#define   TIM_SMCR_ETF_0000                   (0UL<<8)     /*!< 0000 : No filter                                                 */
#define   TIM_SMCR_ETF_0001                   (1UL<<8)     /*!< 0001 : fSAMPLING=fCK_INT, N=2                                    */
#define   TIM_SMCR_ETF_0010                   (2UL<<8)     /*!< 0010 : fSAMPLING=fCK_INT, N=4                                    */
#define   TIM_SMCR_ETF_0011                   (3UL<<8)     /*!< 0011 : fSAMPLING=fCK_INT, N=8                                    */
#define   TIM_SMCR_ETF_0100                   (4UL<<8)     /*!< 0100 : fSAMPLING=fDTS/2, N=6                                     */
#define   TIM_SMCR_ETF_0101                   (5UL<<8)     /*!< 0101 : fSAMPLING=fDTS/2, N=8                                     */
#define   TIM_SMCR_ETF_0110                   (6UL<<8)     /*!< 0110 : fSAMPLING=fDTS/4, N=6                                     */
#define   TIM_SMCR_ETF_0111                   (7UL<<8)     /*!< 0111 : fSAMPLING=fDTS/4, N=8                                     */
#define   TIM_SMCR_ETF_1000                   (8UL<<8)     /*!< 1000 : fSAMPLING=fDTS/8, N=6                                     */
#define   TIM_SMCR_ETF_1001                   (9UL<<8)     /*!< 1001 : fSAMPLING=fDTS/8, N=8                                     */
#define   TIM_SMCR_ETF_1010                   (10UL<<8)    /*!< 1010 : fSAMPLING=fDTS/16, N=5                                    */
#define   TIM_SMCR_ETF_1011                   (11UL<<8)    /*!< 1011 : fSAMPLING=fDTS/16, N=6                                    */
#define   TIM_SMCR_ETF_1100                   (12UL<<8)    /*!< 1100 : fSAMPLING=fDTS/16, N=8                                    */
#define   TIM_SMCR_ETF_1101                   (13UL<<8)    /*!< 1101 : fSAMPLING=fDTS/32, N=5                                    */
#define   TIM_SMCR_ETF_1110                   (14UL<<8)    /*!< 1110 : fSAMPLING=fDTS/32, N=6                                    */
#define   TIM_SMCR_ETF_1111                   (15UL<<8)    /*!< 1111 : fSAMPLING=fDTS/32, N=8                                    */

/* ==================================================  TIM SMCR TS [4..6]  ================================================== */
#define   TIM_SMCR_TS_ITR0                    (0UL<<4)     /*!< ITR0 : ITR0                                                      */
#define   TIM_SMCR_TS_ITR1                    (1UL<<4)     /*!< ITR1 : ITR1                                                      */
#define   TIM_SMCR_TS_ITR2                    (2UL<<4)     /*!< ITR2 : ITR2                                                      */
#define   TIM_SMCR_TS_ITR3                    (3UL<<4)     /*!< ITR3 : ITR3                                                      */
#define   TIM_SMCR_TS_TI1F_ED                 (4UL<<4)     /*!< TI1F_ED : TI1F_ED                                                */
#define   TIM_SMCR_TS_TI1FP1                  (5UL<<4)     /*!< TI1FP1 : TI1FP1                                                  */
#define   TIM_SMCR_TS_TI2FP2                  (6UL<<4)     /*!< TI2FP2 : TI2FP2                                                  */
#define   TIM_SMCR_TS_ETRF                    (7UL<<4)     /*!< ETRF : ETRF                                                      */

/* =================================================  TIM SMCR SMS [0..2]  ================================================== */
#define   TIM_SMCR_SMS_000                    (0UL<<0)     /*!< 000 : Close Slave mode                                           */
#define   TIM_SMCR_SMS_001                    (1UL<<0)     /*!< 001 : Encoder mode 1                                             */
#define   TIM_SMCR_SMS_010                    (2UL<<0)     /*!< 010 : Encoder mode 2                                             */
#define   TIM_SMCR_SMS_011                    (3UL<<0)     /*!< 011 : Encoder mode 3                                             */
#define   TIM_SMCR_SMS_100                    (4UL<<0)     /*!< 100 : Reset mode                                                 */
#define   TIM_SMCR_SMS_101                    (5UL<<0)     /*!< 101 : Gated mode                                                 */
#define   TIM_SMCR_SMS_110                    (6UL<<0)     /*!< 110 : Trigger mode                                               */
#define   TIM_SMCR_SMS_111                    (7UL<<0)     /*!< 111 : External clock mode 1                                      */

/* =========================================================  DIER  ========================================================== */
/* ==========================================================  SR  =========================================================== */
/* ==========================================================  EGR  ========================================================== */
/* =====================================================  CCMR1_Output  ====================================================== */
/* ============================================  TIM CCMR1_Output OC2M [12..14]  ============================================ */
#define   TIM_CCMR1_OC2M_000           (0UL<<12)     /*!< 000 : Frozen                                                    */
#define   TIM_CCMR1_OC2M_001           (1UL<<12)     /*!< 001 : Set Channel as active level                               */
#define   TIM_CCMR1_OC2M_010           (2UL<<12)     /*!< 010 : Set Channel as inactive level                             */
#define   TIM_CCMR1_OC2M_011           (3UL<<12)     /*!< 011 : Toggle                                                    */
#define   TIM_CCMR1_OC2M_100           (4UL<<12)     /*!< 100 : Force to be low                                           */
#define   TIM_CCMR1_OC2M_101           (5UL<<12)     /*!< 101 : Force to be high                                          */
#define   TIM_CCMR1_OC2M_110           (6UL<<12)     /*!< 110 : PWM mode1                                                 */
#define   TIM_CCMR1_OC2M_111           (7UL<<12)     /*!< 111 : PWM mode2                                                 */

/* =============================================  TIM CCMR1_Output CC2S [8..9]  ============================================= */
#define   TIM_CCMR1_CC2S_00            (0UL<<8)     /*!< 00 : CC2 Channel output                                          */
#define   TIM_CCMR1_CC2S_01            (1UL<<8)     /*!< 01 : CC2 Channel Input, IC2-TI2                                  */
#define   TIM_CCMR1_CC2S_10            (2UL<<8)     /*!< 10 : CC2 Channel Input, IC2-TI1                                  */
#define   TIM_CCMR1_CC2S_11            (3UL<<8)     /*!< 11 : CC2 Channel Input, IC2-TRC                                  */

/* =============================================  TIM CCMR1_Output OC1M [4..6]  ============================================= */
#define   TIM_CCMR1_OC1M_000           (0UL<<4)     /*!< 000 : Frozen                                                     */
#define   TIM_CCMR1_OC1M_001           (1UL<<4)     /*!< 001 : Set Channel as active level                                */
#define   TIM_CCMR1_OC1M_010           (2UL<<4)     /*!< 010 : Set Channel as inactive level                              */
#define   TIM_CCMR1_OC1M_011           (3UL<<4)     /*!< 011 : Toggle                                                     */
#define   TIM_CCMR1_OC1M_100           (4UL<<4)     /*!< 100 : Force to be low                                            */
#define   TIM_CCMR1_OC1M_101           (5UL<<4)     /*!< 101 : Force to be high                                           */
#define   TIM_CCMR1_OC1M_110           (6UL<<4)     /*!< 110 : PWM mode1                                                  */
#define   TIM_CCMR1_OC1M_111           (7UL<<4)     /*!< 111 : PWM mode2                                                  */

/* =============================================  TIM CCMR1_Output CC1S [0..1]  ============================================= */
#define   TIM_CCMR1_CC1S_00            (0UL<<0)     /*!< 00 : CC1 Channel output                                          */
#define   TIM_CCMR1_CC1S_01            (1UL<<0)     /*!< 01 : CC1 Channel Input, IC1-TI1                                  */
#define   TIM_CCMR1_CC1S_10            (2UL<<0)     /*!< 10 : CC1 Channel Input, IC1-TI2                                  */
#define   TIM_CCMR1_CC1S_11            (3UL<<0)     /*!< 11 : CC1 Channel Input, IC1-TRC                                  */

/* ======================================================  CCMR1_Input  ====================================================== */
/* ============================================  TIM CCMR1_Input IC2F [12..15]  ============================================= */
#define   TIM_CCMR1_IC2F_0000           (0UL<<12)     /*!< 0000 : No filter                                                */
#define   TIM_CCMR1_IC2F_0001           (1UL<<12)     /*!< 0001 : fSAMPLING=fCK_INT, N=2                                   */
#define   TIM_CCMR1_IC2F_0010           (2UL<<12)     /*!< 0010 : fSAMPLING=fCK_INT, N=4                                   */
#define   TIM_CCMR1_IC2F_0011           (3UL<<12)     /*!< 0011 : fSAMPLING=fCK_INT, N=8                                   */
#define   TIM_CCMR1_IC2F_0100           (4UL<<12)     /*!< 0100 : fSAMPLING=fDTS/2, N=6                                    */
#define   TIM_CCMR1_IC2F_0101           (5UL<<12)     /*!< 0101 : fSAMPLING=fDTS/2, N=8                                    */
#define   TIM_CCMR1_IC2F_0110           (6UL<<12)     /*!< 0110 : fSAMPLING=fDTS/4, N=6                                    */
#define   TIM_CCMR1_IC2F_0111           (7UL<<12)     /*!< 0111 : fSAMPLING=fDTS/4, N=8                                    */
#define   TIM_CCMR1_IC2F_1000           (8UL<<12)     /*!< 1000 : fSAMPLING=fDTS/8, N=6                                    */
#define   TIM_CCMR1_IC2F_1001           (9UL<<12)     /*!< 1001 : fSAMPLING=fDTS/8, N=8                                    */
#define   TIM_CCMR1_IC2F_1010           (10UL<<12)    /*!< 1010 : fSAMPLING=fDTS/16, N=5                                   */
#define   TIM_CCMR1_IC2F_1011           (11UL<<12)    /*!< 1011 : fSAMPLING=fDTS/16, N=6                                   */
#define   TIM_CCMR1_IC2F_1100           (12UL<<12)    /*!< 1100 : fSAMPLING=fDTS/16, N=8                                   */
#define   TIM_CCMR1_IC2F_1101           (13UL<<12)    /*!< 1101 : fSAMPLING=fDTS/32, N=5                                   */
#define   TIM_CCMR1_IC2F_1110           (14UL<<12)    /*!< 1110 : fSAMPLING=fDTS/32, N=6                                   */
#define   TIM_CCMR1_IC2F_1111           (15UL<<12)    /*!< 1111 : fSAMPLING=fDTS/32, N=8                                   */

/* ===========================================  TIM CCMR1_Input IC2PSC [10..11]  ============================================ */
#define   TIM_CCMR1_IC2PSC_00           (0UL<<10)     /*!< 00 : Every edge trigger one capture                             */
#define   TIM_CCMR1_IC2PSC_01           (1UL<<10)     /*!< 01 : 2 events trigger one capture                               */
#define   TIM_CCMR1_IC2PSC_10           (2UL<<10)     /*!< 10 : 4 events trigger one capture                               */
#define   TIM_CCMR1_IC2PSC_11           (3UL<<10)     /*!< 11 : 8 events trigger one capture                               */

/* =============================================  TIM CCMR1_Input CC2S [8..9]  ============================================== */
#define   TIM_CCMR1_CC2S_00             (0UL<<8)     /*!< 00 : CC2 Channel output                                          */
#define   TIM_CCMR1_CC2S_01             (1UL<<8)     /*!< 01 : CC2 Channel Input, IC2-TI2                                  */
#define   TIM_CCMR1_CC2S_10             (2UL<<8)     /*!< 10 : CC2 Channel Input, IC2-TI1                                  */
#define   TIM_CCMR1_CC2S_11             (3UL<<8)     /*!< 11 : CC2 Channel Input, IC2-TRC                                  */

/* =============================================  TIM CCMR1_Input IC1F [4..7]  ============================================== */
#define   TIM_CCMR1_IC1F_0000           (0UL<<4)     /*!< 0000 : No filter                                                 */
#define   TIM_CCMR1_IC1F_0001           (1UL<<4)     /*!< 0001 : fSAMPLING=fCK_INT, N=2                                    */
#define   TIM_CCMR1_IC1F_0010           (2UL<<4)     /*!< 0010 : fSAMPLING=fCK_INT, N=4                                    */
#define   TIM_CCMR1_IC1F_0011           (3UL<<4)     /*!< 0011 : fSAMPLING=fCK_INT, N=8                                    */
#define   TIM_CCMR1_IC1F_0100           (4UL<<4)     /*!< 0100 : fSAMPLING=fDTS/2, N=6                                     */
#define   TIM_CCMR1_IC1F_0101           (5UL<<4)     /*!< 0101 : fSAMPLING=fDTS/2, N=8                                     */
#define   TIM_CCMR1_IC1F_0110           (6UL<<4)     /*!< 0110 : fSAMPLING=fDTS/4, N=6                                     */
#define   TIM_CCMR1_IC1F_0111           (7UL<<4)     /*!< 0111 : fSAMPLING=fDTS/4, N=8                                     */
#define   TIM_CCMR1_IC1F_1000           (8UL<<4)     /*!< 1000 : fSAMPLING=fDTS/8, N=6                                     */
#define   TIM_CCMR1_IC1F_1001           (9UL<<4)     /*!< 1001 : fSAMPLING=fDTS/8, N=8                                     */
#define   TIM_CCMR1_IC1F_1010           (10UL<<4)    /*!< 1010 : fSAMPLING=fDTS/16, N=5                                    */
#define   TIM_CCMR1_IC1F_1011           (11UL<<4)    /*!< 1011 : fSAMPLING=fDTS/16, N=6                                    */
#define   TIM_CCMR1_IC1F_1100           (12UL<<4)    /*!< 1100 : fSAMPLING=fDTS/16, N=8                                    */
#define   TIM_CCMR1_IC1F_1101           (13UL<<4)    /*!< 1101 : fSAMPLING=fDTS/32, N=5                                    */
#define   TIM_CCMR1_IC1F_1110           (14UL<<4)    /*!< 1110 : fSAMPLING=fDTS/32, N=6                                    */
#define   TIM_CCMR1_IC1F_1111           (15UL<<4)    /*!< 1111 : fSAMPLING=fDTS/32, N=8                                    */

/* ============================================  TIM CCMR1_Input IC1PSC [2..3]  ============================================= */
#define   TIM_CCMR1_IC1PSC_00           (0UL<<2)     /*!< 00 : Every edge trigger one capture                              */
#define   TIM_CCMR1_IC1PSC_01           (1UL<<2)     /*!< 01 : 2 events trigger one capture                                */
#define   TIM_CCMR1_IC1PSC_10           (2UL<<2)     /*!< 10 : 4 events trigger one capture                                */
#define   TIM_CCMR1_IC1PSC_11           (3UL<<2)     /*!< 11 : 8 events trigger one capture                                */

/* =============================================  TIM CCMR1_Input CC1S [0..1]  ============================================== */
#define   TIM_CCMR1_CC1S_00             (0UL<<0)     /*!< 00 : CC1 Channel output                                          */
#define   TIM_CCMR1_CC1S_01             (1UL<<0)     /*!< 01 : CC1 Channel Input, IC1-TI1                                  */
#define   TIM_CCMR1_CC1S_10             (2UL<<0)     /*!< 10 : CC1 Channel Input, IC1-TI2                                  */
#define   TIM_CCMR1_CC1S_11             (3UL<<0)     /*!< 11 : CC1 Channel Input, IC1-TRC                                  */

/* =====================================================  CCMR2_Output  ====================================================== */
/* ============================================  TIM CCMR2_Output OC4M [12..14]  ============================================ */
#define   TIM_CCMR2_OC4M_000           (0UL<<12)     /*!< 000 : Frozen                                                    */
#define   TIM_CCMR2_OC4M_001           (1UL<<12)     /*!< 001 : Set Channel as active level                               */
#define   TIM_CCMR2_OC4M_010           (2UL<<12)     /*!< 010 : Set Channel as inactive level                             */
#define   TIM_CCMR2_OC4M_011           (3UL<<12)     /*!< 011 : Toggle                                                    */
#define   TIM_CCMR2_OC4M_100           (4UL<<12)     /*!< 100 : Force to be low                                           */
#define   TIM_CCMR2_OC4M_101           (5UL<<12)     /*!< 101 : Force to be high                                          */
#define   TIM_CCMR2_OC4M_110           (6UL<<12)     /*!< 110 : PWM mode1                                                 */
#define   TIM_CCMR2_OC4M_111           (7UL<<12)     /*!< 111 : PWM mode2                                                 */

/* =============================================  TIM CCMR2_Output CC4S [8..9]  ============================================= */
#define   TIM_CCMR2_CC4S_00            (0UL<<8)     /*!< 00 : CC4 Channel output                                          */
#define   TIM_CCMR2_CC4S_01            (1UL<<8)     /*!< 01 : CC4 Channel Input, IC4-TI4                                  */
#define   TIM_CCMR2_CC4S_10            (2UL<<8)     /*!< 10 : CC4 Channel Input, IC4-TI3                                  */
#define   TIM_CCMR2_CC4S_11            (3UL<<8)     /*!< 11 : CC4 Channel Input, IC4-TRC                                  */

/* =============================================  TIM CCMR2_Output OC3M [4..6]  ============================================= */
#define   TIM_CCMR2_OC3M_000           (0UL<<4)     /*!< 000 : Frozen                                                     */
#define   TIM_CCMR2_OC3M_001           (1UL<<4)     /*!< 001 : Set Channel as active level                                */
#define   TIM_CCMR2_OC3M_010           (2UL<<4)     /*!< 010 : Set Channel as inactive level                              */
#define   TIM_CCMR2_OC3M_011           (3UL<<4)     /*!< 011 : Toggle                                                     */
#define   TIM_CCMR2_OC3M_100           (4UL<<4)     /*!< 100 : Force to be low                                            */
#define   TIM_CCMR2_OC3M_101           (5UL<<4)     /*!< 101 : Force to be high                                           */
#define   TIM_CCMR2_OC3M_110           (6UL<<4)     /*!< 110 : PWM mode1                                                  */
#define   TIM_CCMR2_OC3M_111           (7UL<<4)     /*!< 111 : PWM mode2                                                  */

/* =============================================  TIM CCMR2_Output CC3S [0..1]  ============================================= */
#define   TIM_CCMR2_CC3S_00            (0UL<<0)     /*!< 00 : CC3 Channel output                                          */
#define   TIM_CCMR2_CC3S_01            (1UL<<0)     /*!< 01 : CC3 Channel Input, IC3-TI3                                  */
#define   TIM_CCMR2_CC3S_10            (2UL<<0)     /*!< 10 : CC3 Channel Input, IC3-TI4                                  */
#define   TIM_CCMR2_CC3S_11            (3UL<<0)     /*!< 11 : CC3 Channel Input, IC3-TRC                                  */

/* ======================================================  CCMR2_Input  ====================================================== */
/* ============================================  TIM CCMR2_Input IC4F [12..15]  ============================================= */
#define   TIM_CCMR2_IC4F_0000           (0UL<<12)     /*!< 0000 : No filter                                                */
#define   TIM_CCMR2_IC4F_0001           (1UL<<12)     /*!< 0001 : fSAMPLING=fCK_INT, N=2                                   */
#define   TIM_CCMR2_IC4F_0010           (2UL<<12)     /*!< 0010 : fSAMPLING=fCK_INT, N=4                                   */
#define   TIM_CCMR2_IC4F_0011           (3UL<<12)     /*!< 0011 : fSAMPLING=fCK_INT, N=8                                   */
#define   TIM_CCMR2_IC4F_0100           (4UL<<12)     /*!< 0100 : fSAMPLING=fDTS/2, N=6                                    */
#define   TIM_CCMR2_IC4F_0101           (5UL<<12)     /*!< 0101 : fSAMPLING=fDTS/2, N=8                                    */
#define   TIM_CCMR2_IC4F_0110           (6UL<<12)     /*!< 0110 : fSAMPLING=fDTS/4, N=6                                    */
#define   TIM_CCMR2_IC4F_0111           (7UL<<12)     /*!< 0111 : fSAMPLING=fDTS/4, N=8                                    */
#define   TIM_CCMR2_IC4F_1000           (8UL<<12)     /*!< 1000 : fSAMPLING=fDTS/8, N=6                                    */
#define   TIM_CCMR2_IC4F_1001           (9UL<<12)     /*!< 1001 : fSAMPLING=fDTS/8, N=8                                    */
#define   TIM_CCMR2_IC4F_1010           (10UL<<12)    /*!< 1010 : fSAMPLING=fDTS/16, N=5                                   */
#define   TIM_CCMR2_IC4F_1011           (11UL<<12)    /*!< 1011 : fSAMPLING=fDTS/16, N=6                                   */
#define   TIM_CCMR2_IC4F_1100           (12UL<<12)    /*!< 1100 : fSAMPLING=fDTS/16, N=8                                   */
#define   TIM_CCMR2_IC4F_1101           (13UL<<12)    /*!< 1101 : fSAMPLING=fDTS/32, N=5                                   */
#define   TIM_CCMR2_IC4F_1110           (14UL<<12)    /*!< 1110 : fSAMPLING=fDTS/32, N=6                                   */
#define   TIM_CCMR2_IC4F_1111           (15UL<<12)    /*!< 1111 : fSAMPLING=fDTS/32, N=8                                   */

/* ===========================================  TIM CCMR2_Input IC4PSC [10..11]  ============================================ */
#define   TIM_CCMR2_IC4PSC_00           (0UL<<10)     /*!< 00 : Every edge trigger one capture                             */
#define   TIM_CCMR2_IC4PSC_01           (1UL<<10)     /*!< 01 : 2 events trigger one capture                               */
#define   TIM_CCMR2_IC4PSC_10           (2UL<<10)     /*!< 10 : 4 events trigger one capture                               */
#define   TIM_CCMR2_IC4PSC_11           (3UL<<10)     /*!< 11 : 8 events trigger one capture                               */

/* =============================================  TIM CCMR2_Input CC4S [8..9]  ============================================== */
#define   TIM_CCMR2_CC4S_00             (0UL<<8)     /*!< 00 : CC4 Channel output                                          */
#define   TIM_CCMR2_CC4S_01             (1UL<<8)     /*!< 01 : CC4 Channel Input, IC4-TI4                                  */
#define   TIM_CCMR2_CC4S_10             (2UL<<8)     /*!< 10 : CC4 Channel Input, IC4-TI3                                  */
#define   TIM_CCMR2_CC4S_11             (3UL<<8)     /*!< 11 : CC4 Channel Input, IC4-TRC                                  */

/* =============================================  TIM CCMR2_Input IC3F [4..7]  ============================================== */
#define   TIM_CCMR2_IC3F_0000           (0UL<<4)     /*!< 0000 : No filter                                                 */
#define   TIM_CCMR2_IC3F_0001           (1UL<<4)     /*!< 0001 : fSAMPLING=fCK_INT, N=2                                    */
#define   TIM_CCMR2_IC3F_0010           (2UL<<4)     /*!< 0010 : fSAMPLING=fCK_INT, N=4                                    */
#define   TIM_CCMR2_IC3F_0011           (3UL<<4)     /*!< 0011 : fSAMPLING=fCK_INT, N=8                                    */
#define   TIM_CCMR2_IC3F_0100           (4UL<<4)     /*!< 0100 : fSAMPLING=fDTS/2, N=6                                     */
#define   TIM_CCMR2_IC3F_0101           (5UL<<4)     /*!< 0101 : fSAMPLING=fDTS/2, N=8                                     */
#define   TIM_CCMR2_IC3F_0110           (6UL<<4)     /*!< 0110 : fSAMPLING=fDTS/4, N=6                                     */
#define   TIM_CCMR2_IC3F_0111           (7UL<<4)     /*!< 0111 : fSAMPLING=fDTS/4, N=8                                     */
#define   TIM_CCMR2_IC3F_1000           (8UL<<4)     /*!< 1000 : fSAMPLING=fDTS/8, N=6                                     */
#define   TIM_CCMR2_IC3F_1001           (9UL<<4)     /*!< 1001 : fSAMPLING=fDTS/8, N=8                                     */
#define   TIM_CCMR2_IC3F_1010           (10UL<<4)    /*!< 1010 : fSAMPLING=fDTS/16, N=5                                    */
#define   TIM_CCMR2_IC3F_1011           (11UL<<4)    /*!< 1011 : fSAMPLING=fDTS/16, N=6                                    */
#define   TIM_CCMR2_IC3F_1100           (12UL<<4)    /*!< 1100 : fSAMPLING=fDTS/16, N=8                                    */
#define   TIM_CCMR2_IC3F_1101           (13UL<<4)    /*!< 1101 : fSAMPLING=fDTS/32, N=5                                    */
#define   TIM_CCMR2_IC3F_1110           (14UL<<4)    /*!< 1110 : fSAMPLING=fDTS/32, N=6                                    */
#define   TIM_CCMR2_IC3F_1111           (15UL<<4)    /*!< 1111 : fSAMPLING=fDTS/32, N=8                                    */

/* ============================================  TIM CCMR2_Input IC3PSC [2..3]  ============================================= */
#define   TIM_CCMR2_IC3PSC_00           (0UL<<2)     /*!< 00 : Every edge trigger one capture                              */
#define   TIM_CCMR2_IC3PSC_01           (1UL<<2)     /*!< 01 : 2 events trigger one capture                                */
#define   TIM_CCMR2_IC3PSC_10           (2UL<<2)     /*!< 10 : 4 events trigger one capture                                */
#define   TIM_CCMR2_IC3PSC_11           (3UL<<2)     /*!< 11 : 8 events trigger one capture                                */

/* =============================================  TIM CCMR2_Input CC3S [0..1]  ============================================== */
#define   TIM_CCMR2_CC3S_00             (0UL<<0)     /*!< 00 : CC3 Channel output                                          */
#define   TIM_CCMR2_CC3S_01             (1UL<<0)     /*!< 01 : CC3 Channel Input, IC3-TI3                                  */
#define   TIM_CCMR2_CC3S_10             (2UL<<0)     /*!< 10 : CC3 Channel Input, IC3-TI4                                  */
#define   TIM_CCMR2_CC3S_11             (3UL<<0)     /*!< 11 : CC3 Channel Input, IC3-TRC                                  */

/* =========================================================  CCER  ========================================================== */
/* ==========================================================  CNT  ========================================================== */
/* ==========================================================  PSC  ========================================================== */
/* ==========================================================  ARR  ========================================================== */
/* ==========================================================  RCR  ========================================================== */
/* =========================================================  CCR1  ========================================================== */
/* =========================================================  CCR2  ========================================================== */
/* =========================================================  CCR3  ========================================================== */
/* =========================================================  CCR4  ========================================================== */
/* =========================================================  BDTR  ========================================================== */
/* =================================================  TIM BDTR LOCK [8..9]  ================================================= */
#define   TIM_BDTR_LOCK_0                     (0UL<<8)     /*!< 0 : OFF                                                          */
#define   TIM_BDTR_LOCK_1                     (1UL<<8)     /*!< 1 : Level 1                                                      */
#define   TIM_BDTR_LOCK_2                     (2UL<<8)     /*!< 2 : Level 2                                                      */
#define   TIM_BDTR_LOCK_3                     (3UL<<8)     /*!< 3 : Level 3                                                      */

/* ==========================================================  DCR  ========================================================== */
/* =================================================  TIM DCR DBL [8..12]  ================================================== */
#define   TIM_DCR_DBL_1                       (0UL<<8)     /*!< 1 : 1 transmission                                               */
#define   TIM_DCR_DBL_2                       (1UL<<8)     /*!< 2 : 2 transmission                                               */
#define   TIM_DCR_DBL_3                       (2UL<<8)     /*!< 3 : 3 transmission                                               */
#define   TIM_DCR_DBL_4                       (3UL<<8)     /*!< 4 : 4 transmission                                               */
#define   TIM_DCR_DBL_5                       (4UL<<8)     /*!< 5 : 5 transmission                                               */
#define   TIM_DCR_DBL_6                       (5UL<<8)     /*!< 6 : 6 transmission                                               */
#define   TIM_DCR_DBL_7                       (6UL<<8)     /*!< 7 : 7 transmission                                               */
#define   TIM_DCR_DBL_8                       (7UL<<8)     /*!< 8 : 8 transmission                                               */
#define   TIM_DCR_DBL_9                       (8UL<<8)     /*!< 9 : 9 transmission                                               */
#define   TIM_DCR_DBL_10                      (9UL<<8)     /*!< 10 : 10 transmission                                             */
#define   TIM_DCR_DBL_11                      (10UL<<8)    /*!< 11 : 11 transmission                                             */
#define   TIM_DCR_DBL_12                      (11UL<<8)    /*!< 12 : 12 transmission                                             */
#define   TIM_DCR_DBL_13                      (12UL<<8)    /*!< 13 : 13 transmission                                             */
#define   TIM_DCR_DBL_14                      (13UL<<8)    /*!< 14 : 14 transmission                                             */
#define   TIM_DCR_DBL_15                      (14UL<<8)    /*!< 15 : 15 transmission                                             */
#define   TIM_DCR_DBL_16                      (15UL<<8)    /*!< 16 : 16 transmission                                             */
#define   TIM_DCR_DBL_17                      (16UL<<8)    /*!< 17 : 17 transmission                                             */
#define   TIM_DCR_DBL_18                      (17UL<<8)    /*!< 18 : 18 transmission                                             */

/* ==================================================  TIM DCR DBA [0..4]  ================================================== */
#define   TIM_DCR_DBA_CR1                     (0UL<<0)     /*!< CR1 : CR1                                                        */
#define   TIM_DCR_DBA_CR2                     (1UL<<0)     /*!< CR2 : CR2                                                        */
#define   TIM_DCR_DBA_SMCR                    (2UL<<0)     /*!< SMCR : SMCR                                                      */
#define   TIM_DCR_DBA_DIER                    (3UL<<0)     /*!< DIER : DIER                                                      */
#define   TIM_DCR_DBA_SR                      (4UL<<0)     /*!< SR : SR                                                          */
#define   TIM_DCR_DBA_EGR                     (5UL<<0)     /*!< EGR : EGR                                                        */
#define   TIM_DCR_DBA_CCMR1                   (6UL<<0)     /*!< CCMR1 : CCMR1                                                    */
#define   TIM_DCR_DBA_CCMR2                   (7UL<<0)     /*!< CCMR2 : CCMR2                                                    */
#define   TIM_DCR_DBA_CCER                    (8UL<<0)     /*!< CCER : CCER                                                      */
#define   TIM_DCR_DBA_CNT                     (9UL<<0)     /*!< CNT : CNT                                                        */
#define   TIM_DCR_DBA_PSC                     (10UL<<0)    /*!< PSC : PSC                                                        */
#define   TIM_DCR_DBA_ARR                     (11UL<<0)    /*!< ARR : ARR                                                        */
#define   TIM_DCR_DBA_RCR                     (12UL<<0)    /*!< RCR : RCR                                                        */
#define   TIM_DCR_DBA_CCR1                    (13UL<<0)    /*!< CCR1 : CCR1                                                      */
#define   TIM_DCR_DBA_CCR2                    (14UL<<0)    /*!< CCR2 : CCR2                                                      */
#define   TIM_DCR_DBA_CCR3                    (15UL<<0)    /*!< CCR3 : CCR3                                                      */
#define   TIM_DCR_DBA_CCR4                    (16UL<<0)    /*!< CCR4 : CCR4                                                      */
#define   TIM_DCR_DBA_BDTR                    (17UL<<0)    /*!< BDTR : BDTR                                                      */

/* =========================================================  DMAR  ========================================================== */
/* ==========================================================  OR  =========================================================== */
/* ===============================================  TIM OR IOCREF_CLR [0..1]  =============================================== */
#define   TIM_OR_IOCREF_CLR_COMP1             (0UL<<0)     /*!< COMP1 : COMP1                                                    */
#define   TIM_OR_IOCREF_CLR_COMP2             (1UL<<0)     /*!< COMP2 : COMP2                                                    */
#define   TIM_OR_IOCREF_CLR_COMP3             (2UL<<0)     /*!< COMP3 : COMP3                                                    */
#define   TIM_OR_IOCREF_CLR_COMP4             (3UL<<0)     /*!< COMP4 : COMP4                                                    */

/* =========================================================  TISEL  ========================================================= */
/* ==============================================  TIM TISEL TI4SEL [24..27]  =============================================== */
#define   TIM_TISEL_TI4SEL_CH4                (0UL<<24)     /*!< CH4 : CH4                                                       */
#define   TIM_TISEL_TI4SEL_COMP4              (1UL<<24)     /*!< COMP4 : COMP4                                                   */

/* ==============================================  TIM TISEL TI3SEL [16..19]  =============================================== */
#define   TIM_TISEL_TI3SEL_CH3                (0UL<<16)     /*!< CH3 : CH3                                                       */
#define   TIM_TISEL_TI3SEL_COMP3              (1UL<<16)     /*!< COMP3 : COMP3                                                   */

/* ===============================================  TIM TISEL TI2SEL [8..11]  =============================================== */
#define   TIM_TISEL_TI2SEL_CH2                (0UL<<8)     /*!< CH2 : CH2                                                        */
#define   TIM_TISEL_TI2SEL_COMP2              (1UL<<8)     /*!< COMP2 : COMP2                                                    */

/* ===============================================  TIM TISEL TI1SEL [0..3]  ================================================ */
#define   TIM_TISEL_TI1SEL_CH1                (0UL<<0)     /*!< CH1 : CH1                                                        */
#define   TIM_TISEL_TI1SEL_COMP1              (1UL<<0)     /*!< COMP1 : COMP1                                                    */



/* =========================================================================================================================== */
/* ================                                          DBGMCU                                           ================ */
/* =========================================================================================================================== */

/* ======================================================  DBG_IDCODE  ======================================================= */
/* ==========================================================  CR  =========================================================== */
/* ======================================================  DBG_APB_FZ1  ====================================================== */
/* ======================================================  DBG_APB_FZ2  ====================================================== */


/* =========================================================================================================================== */
/* ================                                           SPI1                                            ================ */
/* =========================================================================================================================== */

/* ==========================================================  CR1  ========================================================== */
/* ==================================================  SPI1 CR1 BR [3..5]  =================================================== */
#define   SPI_CR1_BR_fPCLK2                   (0UL<<3)     /*!< fPCLK2 : fPCLK2                                                  */
#define   SPI_CR1_BR_fPCLK4                   (1UL<<3)     /*!< fPCLK4 : fPCLK4                                                  */
#define   SPI_CR1_BR_fPCLK8                   (2UL<<3)     /*!< fPCLK8 : fPCLK8                                                  */
#define   SPI_CR1_BR_fPCLK16                  (3UL<<3)     /*!< fPCLK16 : fPCLK16                                                */
#define   SPI_CR1_BR_fPCLK32                  (4UL<<3)     /*!< fPCLK32 : fPCLK32                                                */
#define   SPI_CR1_BR_fPCLK64                  (5UL<<3)     /*!< fPCLK64 : fPCLK64                                                */
#define   SPI_CR1_BR_fPCLK128                 (6UL<<3)     /*!< fPCLK128 : fPCLK128                                              */
#define   SPI_CR1_BR_fPCLK256                 (7UL<<3)     /*!< fPCLK256 : fPCLK256                                              */

/* ==========================================================  CR2  ========================================================== */
/* ==========================================================  SR  =========================================================== */
/* ================================================  SPI1 SR FTLVL [11..12]  ================================================= */
#define   SPI_SR_FTLVL_00                     (0UL<<11)     /*!< 00 : FIFO empty                                                 */
#define   SPI_SR_FTLVL_01                     (1UL<<11)     /*!< 01 : 1/4 FIFO                                                   */
#define   SPI_SR_FTLVL_10                     (2UL<<11)     /*!< 10 : 1/2 FIFO                                                   */
#define   SPI_SR_FTLVL_11                     (3UL<<11)     /*!< 11 : FIFO full                                                  */

/* =================================================  SPI1 SR FRLVL [9..10]  ================================================= */
#define   SPI_SR_FRLVL_00                     (0UL<<9)     /*!< 00 : FIFO empty                                                  */
#define   SPI_SR_FRLVL_01                     (1UL<<9)     /*!< 01 : 1/4 FIFO                                                    */
#define   SPI_SR_FRLVL_10                     (2UL<<9)     /*!< 10 : 1/2 FIFO                                                    */
#define   SPI_SR_FRLVL_11                     (3UL<<9)     /*!< 11 : FIFO full                                                   */

/* ==========================================================  DR  =========================================================== */


/* =========================================================================================================================== */
/* ================                                            TSC                                            ================ */
/* =========================================================================================================================== */

/* =========================================================  TKCR1  ========================================================= */
/* ===============================================  TSC TKCR1 ASMTO [10..12]  ================================================ */
#define   TSC_TKCR1_ASMTO_000                  (0UL<<10)     /*!< 000 : TASMTO = 2^13/fLSI                                        */
#define   TSC_TKCR1_ASMTO_001                  (1UL<<10)     /*!< 001 : TASMTO = 2^14/fLSI                                        */
#define   TSC_TKCR1_ASMTO_010                  (2UL<<10)     /*!< 010 : TASMTO = 2^15/fLSI                                        */
#define   TSC_TKCR1_ASMTO_011                  (3UL<<10)     /*!< 011 : TASMTO = 2^16/fLSI                                        */
#define   TSC_TKCR1_ASMTO_100                  (4UL<<10)     /*!< 100 : TASMTO = 2^17/fLSI                                        */
#define   TSC_TKCR1_ASMTO_101                  (5UL<<10)     /*!< 101 : TASMTO = 2^18/fLSI                                        */
#define   TSC_TKCR1_ASMTO_110                  (6UL<<10)     /*!< 110 : TASMTO = 2^18/fLSI                                        */
#define   TSC_TKCR1_ASMTO_111                  (7UL<<10)     /*!< 111 : TASMTO = 2^18/fLSI                                        */

/* =================================================  TSC TKCR1 ASMP [8..9]  ================================================= */
#define   TSC_TKCR1_ASMP_2                     (0UL<<8)     /*!< 2 : TASMTO/2                                                     */
#define   TSC_TKCR1_ASMP_4                     (1UL<<8)     /*!< 4 : TASMTO/4                                                     */
#define   TSC_TKCR1_ASMP_8                     (2UL<<8)     /*!< 8 : TASMTO/8                                                     */
#define   TSC_TKCR1_ASMP_16                    (3UL<<8)     /*!< 16 : TASMTO/16                                                   */

/* ================================================  TSC TKCR1 TK16S [5..6]  ================================================= */
#define   TSC_TKCR1_TK16S_16                   (0UL<<5)     /*!< 16 : fTKCLK/16                                                   */
#define   TSC_TKCR1_TK16S_32                   (1UL<<5)     /*!< 32 : fTKCLK/32                                                   */
#define   TSC_TKCR1_TK16S_64                   (2UL<<5)     /*!< 64 : fTKCLK/64                                                   */
#define   TSC_TKCR1_TK16S_128                  (3UL<<5)     /*!< 128 : fTKCLK/128                                                 */

/* =================================================  TSC TKCR1 TKFS [3..4]  ================================================= */
#define   TSC_TKCR1_TKFS_1MHz                  (0UL<<3)     /*!< 1MHz : 1MHz                                                      */
#define   TSC_TKCR1_TKFS_5MHz                  (1UL<<3)     /*!< 5MHz : 5MHz                                                      */
#define   TSC_TKCR1_TKFS_13MHz                 (2UL<<3)     /*!< 13MHz : 13MHz                                                    */

/* ================================================  TSC TKCR1 TKMOD [1..2]  ================================================= */
#define   TSC_TKCR1_TKMOD_00                   (0UL<<1)     /*!< 00 : Auto                                                        */
#define   TSC_TKCR1_TKMOD_01                   (1UL<<1)     /*!< 01 : Manual                                                      */
#define   TSC_TKCR1_TKMOD_10                   (2UL<<1)     /*!< 10 : Periodic automatic scan mode                                */
#define   TSC_TKCR1_TKMOD_11                   (3UL<<1)     /*!< 11 : Periodic automatic scan mode                                */

/* =========================================================  TKCR2  ========================================================= */
/* =================================================  TSC TKCR2 TSS [8..9]  ================================================== */
#define   TSC_TKCR2_TSS_00                     (0UL<<8)     /*!< 00 : Reference oscillator clock                                  */
#define   TSC_TKCR2_TSS_01                     (1UL<<8)     /*!< 01 : fTKCLK/32                                                   */
#define   TSC_TKCR2_TSS_10                     (2UL<<8)     /*!< 10 : fTKCLK/64                                                   */
#define   TSC_TKCR2_TSS_11                     (3UL<<8)     /*!< 11 : fTKCLK/128                                                  */

/* =================================================  TSC TKCR2 SOF [0..2]  ================================================== */
#define   TSC_TKCR2_SOF_1_429                  (0UL<<0)     /*!< 1_429 : 1.429M                                                   */
#define   TSC_TKCR2_SOF_1_412                  (1UL<<0)     /*!< 1_412 : 1.412M                                                   */
#define   TSC_TKCR2_SOF_1_395                  (2UL<<0)     /*!< 1_395 : 1.395M                                                   */
#define   TSC_TKCR2_SOF_1_378                  (3UL<<0)     /*!< 1_378 : 1.378M                                                   */
#define   TSC_TKCR2_SOF_1_362                  (4UL<<0)     /*!< 1_362 : 1.362M                                                   */
#define   TSC_TKCR2_SOF_1_346                  (5UL<<0)     /*!< 1_346 : 1.346M                                                   */
#define   TSC_TKCR2_SOF_1_333                  (6UL<<0)     /*!< 1_333 : 1.333M                                                   */

/* ========================================================  TKCNTR  ========================================================= */
/* ========================================================  TKTSCRR  ======================================================== */
/* =========================================================  TKIER  ========================================================= */
/* =========================================================  TKSR1  ========================================================= */
/* =========================================================  TKSR2  ========================================================= */
/* =======================================================  TKENCFGR  ======================================================== */
/* =======================================================  TKTHSCFGR  ======================================================= */
/* ========================================================  TKROCPR  ======================================================== */
/* ========================================================  TKK0CPR  ======================================================== */
/* ========================================================  TKK1CPR  ======================================================== */
/* ========================================================  TKK2CPR  ======================================================== */
/* ========================================================  TKK3CPR  ======================================================== */
/* ========================================================  TKK4CPR  ======================================================== */
/* ========================================================  TKK5CPR  ======================================================== */
/* ========================================================  TKK6CPR  ======================================================== */
/* ========================================================  TKK7CPR  ======================================================== */
/* ========================================================  TKK8CPR  ======================================================== */
/* ========================================================  TKK9CPR  ======================================================== */
/* ========================================================  TKKACPR  ======================================================== */
/* ========================================================  TKKBCPR  ======================================================== */
/* ========================================================  TKKCCPR  ======================================================== */
/* ========================================================  TKKDCPR  ======================================================== */
/* ========================================================  TKKECPR  ======================================================== */
/* ========================================================  TKKFCPR  ======================================================== */
/* =======================================================  TKCFCNTR  ======================================================== */
/* =======================================================  TKK0CNTR  ======================================================== */
/* =======================================================  TKK1CNTR  ======================================================== */
/* =======================================================  TKK2CNTR  ======================================================== */
/* =======================================================  TKK3CNTR  ======================================================== */
/* =======================================================  TKK4CNTR  ======================================================== */
/* =======================================================  TKK5CNTR  ======================================================== */
/* =======================================================  TKK6CNTR  ======================================================== */
/* =======================================================  TKK7CNTR  ======================================================== */
/* =======================================================  TKK8CNTR  ======================================================== */
/* =======================================================  TKK9CNTR  ======================================================== */
/* =======================================================  TKKACNTR  ======================================================== */
/* =======================================================  TKKBCNTR  ======================================================== */
/* =======================================================  TKKCCNTR  ======================================================== */
/* =======================================================  TKKDCNTR  ======================================================== */
/* =======================================================  TKKECNTR  ======================================================== */
/* =======================================================  TKKFCNTR  ======================================================== */
/* ========================================================  TKK0THR  ======================================================== */
/* ========================================================  TKK1THR  ======================================================== */
/* ========================================================  TKK2THR  ======================================================== */
/* ========================================================  TKK3THR  ======================================================== */
/* ========================================================  TKK4THR  ======================================================== */
/* ========================================================  TKK5THR  ======================================================== */
/* ========================================================  TKK6THR  ======================================================== */
/* ========================================================  TKK7THR  ======================================================== */
/* ========================================================  TKK8THR  ======================================================== */
/* ========================================================  TKK9THR  ======================================================== */
/* ========================================================  TKKATHR  ======================================================== */
/* ========================================================  TKKBTHR  ======================================================== */
/* ========================================================  TKKCTHR  ======================================================== */
/* ========================================================  TKKDTHR  ======================================================== */
/* ========================================================  TKKETHR  ======================================================== */
/* ========================================================  TKKFTHR  ======================================================== */


/* =========================================================================================================================== */
/* ================                                           TEST                                            ================ */
/* =========================================================================================================================== */

/* ======================================================  TEST_MODER  ======================================================= */
/* ======================================================  TEST_TRIMR1  ====================================================== */
/* ======================================================  TEST_TRIMR2  ====================================================== */
/* ===========================================  TEST TEST_TRIMR2 HSI_FS [29..30]  ============================================ */
#define   TEST_TEST_TRIMR2_HSI_FS_48Mhz        (0UL<<29)     /*!< 48Mhz : 48Mhz                                                   */
#define   TEST_TEST_TRIMR2_HSI_FS_36Mhz        (1UL<<29)     /*!< 36Mhz : 36Mhz                                                   */
#define   TEST_TEST_TRIMR2_HSI_FS_24Mhz        (2UL<<29)     /*!< 24Mhz : 24Mhz                                                   */
#define   TEST_TEST_TRIMR2_HSI_FS_16Mhz        (3UL<<29)     /*!< 16Mhz : 16Mhz                                                   */



/* =========================================================================================================================== */
/* ================                                          TIM_3                                           ================  */
/* =========================================================================================================================== */
#define TIM_CCER_CC4NP_Pos               (15UL)                         /*!< CC4NP (Bit 11)                                    */
#define TIM_CCER_CC4NP_Msk               (0x00008000UL)                 /*!< CC4NP (Bitfield-Mask: 0x01)                       */
#define TIM_CCER_CC4NP                   (0x00008000UL)                 /*!< CC4NP (Bitfield-Mask: 0x01)                       */

/* =========================================================================================================================== */
/* ================                                          TIM_14                                           ================ */
/* =========================================================================================================================== */
#define TIM14_OR_TI1_RMP_00               (0<<0)           /*!< 00 : 00                                                        */
#define TIM14_OR_TI1_RMP_Reserve          (1<<0)           /*!< Reserve : Reserve                                              */
#define TIM14_OR_TI1_RMP_10               (2<<0)           /*!< 10 : 10                                                        */
#define TIM14_OR_TI1_RMP_11               (3<<0)           /*!< 11 : 11                                                        */

#define TIM14_OR_TI1_RMP_Pos              (0UL)            /*!< TI1_RMP                                                        */
#define TIM14_OR_TI1_RMP_Msk              (0x3UL)          /*!< TI1_RMP                                                        */
#define TIM14_OR_TI1_RMP                  (0x3UL)          /*!< TI1_RMP                                                        */

/** @} */ /* End of group EnumValue_peripherals */
/****************************** TIM Instances *********************************/
#define IS_TIM_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM3)    || \
   ((INSTANCE) == TIM6)    || \
   ((INSTANCE) == TIM14)   || \
   ((INSTANCE) == TIM15)   || \
   ((INSTANCE) == TIM16)   || \
   ((INSTANCE) == TIM17))

#define IS_TIM_CC1_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM3)    || \
   ((INSTANCE) == TIM14)   || \
   ((INSTANCE) == TIM15)   || \
   ((INSTANCE) == TIM16)   || \
   ((INSTANCE) == TIM17))

#define IS_TIM_CC2_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM3)    || \
   ((INSTANCE) == TIM15))

#define IS_TIM_CC3_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM3))

#define IS_TIM_CC4_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM3))

#define IS_TIM_CLOCKSOURCE_ETRMODE1_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM3))

#define IS_TIM_CLOCKSOURCE_ETRMODE2_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM3))

#define IS_TIM_CLOCKSOURCE_TIX_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM3)    || \
   ((INSTANCE) == TIM15))

#define IS_TIM_CLOCKSOURCE_ITRX_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM3)    || \
   ((INSTANCE) == TIM15)   || \
   ((INSTANCE) == TIM16)   || \
   ((INSTANCE) == TIM17))
		
#define IS_TIM_OCXREF_CLEAR_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM3))

#define IS_TIM_ENCODER_INTERFACE_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM3))

#define IS_TIM_HALL_INTERFACE_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1))
  
#define IS_TIM_HALL_SENSOR_INTERFACE_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1))

#define IS_TIM_XOR_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM3))

#define IS_TIM_MASTER_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM3)    || \
   ((INSTANCE) == TIM15))

#define IS_TIM_SLAVE_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM3)    || \
   ((INSTANCE) == TIM15))

#define IS_TIM_32B_COUNTER_INSTANCE(INSTANCE) (0)

#define IS_TIM_DMABURST_INSTANCE(INSTANCE)\
    (((INSTANCE) == TIM1)    || \
     ((INSTANCE) == TIM3)    || \
     ((INSTANCE) == TIM15)   || \
     ((INSTANCE) == TIM16)   || \
     ((INSTANCE) == TIM17))

#define IS_TIM_BREAK_INSTANCE(INSTANCE)\
      (((INSTANCE) == TIM1)    || \
       ((INSTANCE) == TIM15)   || \
       ((INSTANCE) == TIM16)   || \
       ((INSTANCE) == TIM17))

#define IS_TIM_CCX_INSTANCE(INSTANCE, CHANNEL) \
    ((((INSTANCE) == TIM1) &&                   \
     (((CHANNEL) == TIM_CHANNEL_1) ||          \
      ((CHANNEL) == TIM_CHANNEL_2) ||          \
      ((CHANNEL) == TIM_CHANNEL_3) ||          \
      ((CHANNEL) == TIM_CHANNEL_4)))           \
    ||                                         \
    (((INSTANCE) == TIM3) &&                   \
     (((CHANNEL) == TIM_CHANNEL_1) ||          \
      ((CHANNEL) == TIM_CHANNEL_2) ||          \
      ((CHANNEL) == TIM_CHANNEL_3) ||          \
      ((CHANNEL) == TIM_CHANNEL_4)))           \
    ||                                         \
    (((INSTANCE) == TIM14) &&                  \
     (((CHANNEL) == TIM_CHANNEL_1)))           \
    ||                                         \
    (((INSTANCE) == TIM15) &&                  \
     (((CHANNEL) == TIM_CHANNEL_1) ||          \
      ((CHANNEL) == TIM_CHANNEL_2)))           \
    ||                                         \
    (((INSTANCE) == TIM16) &&                  \
     (((CHANNEL) == TIM_CHANNEL_1)))           \
    ||                                         \
    (((INSTANCE) == TIM17) &&                  \
     (((CHANNEL) == TIM_CHANNEL_1))))

#define IS_TIM_CCXN_INSTANCE(INSTANCE, CHANNEL) \
   ((((INSTANCE) == TIM1) &&                    \
     (((CHANNEL) == TIM_CHANNEL_1) ||           \
      ((CHANNEL) == TIM_CHANNEL_2) ||           \
      ((CHANNEL) == TIM_CHANNEL_3)))            \
    ||                                          \
    (((INSTANCE) == TIM15) &&                   \
      ((CHANNEL) == TIM_CHANNEL_1))             \
    ||                                          \
    (((INSTANCE) == TIM16) &&                   \
     ((CHANNEL) == TIM_CHANNEL_1))              \
    ||                                          \
    (((INSTANCE) == TIM17) &&                   \
     ((CHANNEL) == TIM_CHANNEL_1)))

#define IS_TIM_COUNTER_MODE_SELECT_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM3))

#define IS_TIM_REPETITION_COUNTER_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM15)   || \
   ((INSTANCE) == TIM16)   || \
   ((INSTANCE) == TIM17))

#define IS_TIM_CLOCK_DIVISION_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM3)    || \
   ((INSTANCE) == TIM14)   || \
   ((INSTANCE) == TIM15)   || \
   ((INSTANCE) == TIM16)   || \
   ((INSTANCE) == TIM17))

#define IS_TIM_DMA_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM3)    || \
   ((INSTANCE) == TIM6)    || \
   ((INSTANCE) == TIM15)   || \
   ((INSTANCE) == TIM16)   || \
   ((INSTANCE) == TIM17))
    
#define IS_TIM_DMA_CC_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM3)    || \
   ((INSTANCE) == TIM15)   || \
   ((INSTANCE) == TIM16)   || \
   ((INSTANCE) == TIM17))
    
#define IS_TIM_COMMUTATION_EVENT_INSTANCE(INSTANCE)\
  (((INSTANCE) == TIM1)    || \
   ((INSTANCE) == TIM15)   || \
   ((INSTANCE) == TIM16)   || \
   ((INSTANCE) == TIM17))
    
#define IS_TIM_REMAP_INSTANCE(INSTANCE)\
   ((INSTANCE) == TIM14)

#define IS_TIM_ADVANCED_INSTANCE(INSTANCE)\
  ((INSTANCE) == TIM1)
/******************************** DMA Instances *******************************/
#define IS_DMA_ALL_INSTANCE(INSTANCE) (((INSTANCE) == DMA_CHANNEL1) || \
                                       ((INSTANCE) == DMA_CHANNEL2) || \
                                       ((INSTANCE) == DMA_CHANNEL3) || \
                                       ((INSTANCE) == DMA_CHANNEL4) || \
                                       ((INSTANCE) == DMA_CHANNEL5))

/****************************** SPI Instances *********************************/
#define IS_SPI_ALL_INSTANCE(INSTANCE) (((INSTANCE) == SPI1) || \
                                       ((INSTANCE) == SPI2))

typedef DMA_CHANNEL_TypeDef   DMA_Channel_TypeDef;

#define DMA_Channel1          DMA_CHANNEL1
#define DMA_Channel2          DMA_CHANNEL2
#define DMA_Channel3          DMA_CHANNEL3
#define DMA_Channel4          DMA_CHANNEL4
#define DMA_Channel5          DMA_CHANNEL5

#define RCC_CFGR_SWS_HSI      RCC_CFGR_SWS_HSISYS
#define RCC_CFGR_SWS_PLL      RCC_CFGR_SWS_PLLCLK
#define RCC_CFGR_SW_HSI       RCC_CFGR_SW_HSISYS
#define RCC_CFGR_SW_PLL       RCC_CFGR_SW_PLLCLK

#define FLASH_END             (0x0800EFFFUL)  /*!< FLASH end address */
#define FLASH_SIZE            (FLASH_END - 0x08000000UL + 1UL)
#define SRAM_BASE             (0x20000000UL)  /*!< SRAM base address */
#define SRAM_END              (0x20001FFFUL)  /*!< SRAM end address */
#define FLASH_PAGE_SIZE       0x00000100U     /*!< FLASH Page Size, 256 Bytes */
#define FLASH_PAGE_NB         ((FLASH_END + 1UL)/FLASH_PAGE_SIZE)
#define FLASH_SECTOR_SIZE     0x00000400U     /*!< FLASH Sector Size, 1024 Bytes */
#define FLASH_KEY1            0x45670123UL                    /*!< Flash program erase key1 */
#define FLASH_KEY2            0xCDEF89ABUL                    /*!< Flash program erase key2 */
#define FLASH_OPTKEY1         0x08192A3BUL                    /*!< Flash option key1 */
#define FLASH_OPTKEY2         0x4C5D6E7FUL                    /*!< Flash option key2 */

#define SET_BIT(REG, BIT)     ((REG) |= (BIT))
#define CLEAR_BIT(REG, BIT)   ((REG) &= ~(BIT))
#define READ_BIT(REG, BIT)    ((REG) & (BIT))

#define CLEAR_REG(REG)        ((REG) = (0x0))
#define WRITE_REG(REG, VAL)   ((REG) = (VAL))
#define READ_REG(REG)         ((REG))

#define MODIFY_REG(REG, CLEARMASK, SETMASK)  WRITE_REG((REG), (((READ_REG(REG)) & (~(CLEARMASK))) | (SETMASK)))

typedef enum {RESET = 0, SET = !RESET} FlagStatus, ITStatus;

typedef enum {DISABLE = 0, ENABLE = !DISABLE} FunctionalState;
#define IS_FUNCTIONAL_STATE(STATE) (((STATE) == DISABLE) || ((STATE) == ENABLE))

typedef enum {ERROR = 0, SUCCESS = !ERROR} ErrorStatus;

#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <stdint.h>
#include <assert.h>

#if defined(USE_FULL_LL_DRIVER)
#include "ys32_assert.h"
#elif defined(USE_FULL_HAL_DRIVER)
#else
#include "ys32t031_conf.h"
#endif

#ifdef __cplusplus
}
#endif

#endif /* YS32T031_H */


/** @} */ /* End of group ys32t031 */

/** @} */ /* End of group YSPRING Ltd. */

