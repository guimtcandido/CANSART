fndef DRIVER_H
#define DRIVER_H

//#include"Arduino.h"
#include "cansart.h"
#include "stdio.h"
#include "main.h"

extern UART_HandleTypeDef Cusart;

void setCANSART_Driver(UART_HandleTypeDef* usart,unsigned long baudrate);
void sendData(uint16_t sendByte);
void sendFinishData();
void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart,uint16_t Size);

int newData();
uint8_t getData(uint8_t *pData);


#endif
