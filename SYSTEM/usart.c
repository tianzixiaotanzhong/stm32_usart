#include "usart.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_usart.h"
#include "stdio.h"

void USART1_GPIO_config()
{
    GPIO_InitTypeDef GPIO_InitStructrue;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);

    GPIO_InitStructrue.GPIO_Pin = GPIO_Pin_9;
    GPIO_InitStructrue.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructrue.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA,&GPIO_InitStructrue);

    GPIO_InitStructrue.GPIO_Pin = GPIO_Pin_10;
    GPIO_InitStructrue.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIOA,&GPIO_InitStructrue);
}

void USART2_GPIO_config()
{
    GPIO_InitTypeDef GPIO_InitStructrue;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);

    GPIO_InitStructrue.GPIO_Pin = GPIO_Pin_2;
    GPIO_InitStructrue.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructrue.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA,&GPIO_InitStructrue);

    GPIO_InitStructrue.GPIO_Pin = GPIO_Pin_3;
    GPIO_InitStructrue.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIOA,&GPIO_InitStructrue);
}

void USART3_GPIO_config()
{
    GPIO_InitTypeDef GPIO_InitStructrue;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);

    GPIO_InitStructrue.GPIO_Pin = GPIO_Pin_10;
    GPIO_InitStructrue.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructrue.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA,&GPIO_InitStructrue);

    GPIO_InitStructrue.GPIO_Pin = GPIO_Pin_11;
    GPIO_InitStructrue.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIOB,&GPIO_InitStructrue);
}

void USART1_config(u32 BaudRate)
{
    USART_InitTypeDef USART_InitStructrue;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);

    USART_InitStructrue.USART_BaudRate = BaudRate;
    USART_InitStructrue.USART_WordLength = USART_WordLength_8b;
    USART_InitStructrue.USART_StopBits = USART_StopBits_1;
    USART_InitStructrue.USART_Parity = USART_Parity_No;
    USART_InitStructrue.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_InitStructrue.USART_Mode = USART_Mode_Rx |USART_Mode_Tx;
    USART_Init(USART1,&USART_InitStructrue);

    USART_Cmd(USART1,ENABLE);
}

void USART2_config(u32 BaudRate)
{
    USART_InitTypeDef USART_InitStructrue;

    RCC_APB2PeriphClockCmd(RCC_APB1Periph_USART2,ENABLE);

    USART_InitStructrue.USART_BaudRate = BaudRate;
    USART_InitStructrue.USART_WordLength = USART_WordLength_8b;
    USART_InitStructrue.USART_StopBits = USART_StopBits_1;
    USART_InitStructrue.USART_Parity = USART_Parity_No;
    USART_InitStructrue.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_InitStructrue.USART_Mode = USART_Mode_Rx |USART_Mode_Tx;
    USART_Init(USART2,&USART_InitStructrue);

    USART_Cmd(USART2,ENABLE);
}

void USART3_config(u32 BaudRate)
{
    USART_InitTypeDef USART_InitStructrue;

    RCC_APB2PeriphClockCmd(RCC_APB1Periph_USART3,ENABLE);

    USART_InitStructrue.USART_BaudRate = BaudRate;
    USART_InitStructrue.USART_WordLength = USART_WordLength_8b;
    USART_InitStructrue.USART_StopBits = USART_StopBits_1;
    USART_InitStructrue.USART_Parity = USART_Parity_No;
    USART_InitStructrue.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_InitStructrue.USART_Mode = USART_Mode_Rx |USART_Mode_Tx;
    USART_Init(USART3,&USART_InitStructrue);

    USART_Cmd(USART3,ENABLE);
}

void usart_init(u32 BaudRate)
{
    #ifdef DEBUG_USART1
	{
		USART1_GPIO_config();
        USART1_config(BaudRate);
	}
	#endif
    #ifdef DEBUG_USART1
	{
        USART2_GPIO_config();
        USART2_config(BaudRate);
	}
	#endif
    #ifdef DEBUG_USART1
	{
        USART3_GPIO_config();
        USART3_config(BaudRate);
	}
    #endif
}

#ifdef DEBUG_USART1
//重定义fputc函数
int fputc(int ch, FILE *f)
{   
	//发送一个字节数据到串口
	USART_SendData(USART1,(u8)ch);
	//等待发送完毕
	while(USART_GetFlagStatus(USART1,USART_FLAG_TXE) == RESET);
	
	return ch;
}

//重定义fgetc函数
int fgetc(FILE *f)
{
	//等待串口输入数据
	while(USART_GetFlagStatus(USART1,USART_FLAG_RXNE) == RESET);
	
	return (int)USART_ReceiveData(USART1);
}
#endif 

#ifdef DEBUG_USART2
//重定义fputc函数
int fputc(int ch, FILE *f)
{   
	//发送一个字节数据到串口
	USART_SendData(USART2,(u8)ch);
	//等待发送完毕
	while(USART_GetFlagStatus(USART2,USART_FLAG_TXE) == RESET);
	
	return ch;
}

//重定义fgetc函数
int fgetc(FILE *f)
{
	//等待串口输入数据
	while(USART_GetFlagStatus(USART2,USART_FLAG_RXNE) == RESET);
	
	return (int)USART_ReceiveData(USART1);
}
#endif 

#ifdef DEBUG_USART3
//重定义fputc函数
int fputc(int ch, FILE *f)
{   
	//发送一个字节数据到串口
	USART_SendData(USART3,(u8)ch);
	//等待发送完毕
	while(USART_GetFlagStatus(USART3,USART_FLAG_TXE) == RESET);
	
	return ch;
}

//重定义fgetc函数
int fgetc(FILE *f)
{
	//等待串口输入数据
	while(USART_GetFlagStatus(USART3,USART_FLAG_RXNE) == RESET);
	
	return (int)USART_ReceiveData(USART1);
}
#endif 
