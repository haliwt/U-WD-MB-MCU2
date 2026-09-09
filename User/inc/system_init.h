/*
  ******************************************************************************
  * Copyright (c) 2024 Yspring.
  * All rights reserved..
  * @file    SYSTEM_INIT.H
  * @version V1.0.0
  * @date    2024
  * @author  Yspring Firmware Team  
  * @brief   system_init Header Code.
  ******************************************************************************      
*/
#ifndef __SYSTEM_INIT_H
#define __SYSTEM_INIT_H

#ifdef __cplusplus
extern "C" {
#endif
   
#include "ys32t031.h"
#include "system_ys32t031.h"
#include <stdint.h> 







extern void RCC_Configuration(void);
extern void GPIO_Configuration(void);
extern void NVIC_Configuration(void);



#ifdef __cplusplus
}
#endif

#endif /* __SYSTEM_INIT_H */

