#ifndef _USART_H
#define _USART_H

#define DEBUG_USART1

#include "stm32f10x.h"

void USART1_GPIO_config();
void USART2_GPIO_config();
void USART3_GPIO_config();
void USART1_config(u32 BaudRate);
void USART2_config(u32 BaudRate);
void USART3_config(u32 BaudRate);
void usart_init(u32 BaudRate);

#endif 
