#ifndef DRIVER_H
#define DRIVER_H

#include"cansart.h"

#define ARDUINO 0
#define STM32 1
#define PIC32 2
#define RENESAS 3


void setCANSART_Driver(HardwareSerial &usart,unsigned long baudrate);
void sendData(uint16_t sendByte);
void sendFinishData();

int newData();
uint8_t getData();


#endif