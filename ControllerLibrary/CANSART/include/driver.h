#ifndef DRIVER_H
#define DRIVER_H

#include "stdint.h"
#include "string.h"
#include "stdio.h"
#include "cansart_db.h"

#define MY_ARDUINO 0
#define STM32 1
#define PIC32 2
#define RENESAS 3

#if MCU_TYPE == MY_ARDUINO

#include "HardwareSerial.h"
void setCANSART_Driver(HardwareSerial &usart,unsigned long baudrate);

#elif MCU_TYPE == STM32
#include "stm32f1xx_hal.h"
#include "usart.h"
void setCANSART_Driver(UART_HandleTypeDef usart,unsigned long baudrate);
#elif MCU_TYPE == PIC32
// To include
#elif MCU_TYPE == RENESAS
// To include
#endif




void sendData(uint16_t sendByte);
void sendFinishData();

int newData();
uint8_t getData(uint8_t *pData);


#endif
