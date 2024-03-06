#ifndef DRIVER_H
#define DRIVER_H

#include "cansart.h"
#include "stdio.h"
//#include "main.h"

void sendData(uint16_t sendByte);
void sendFinishData();

int newData();
uint8_t getData();


#endif