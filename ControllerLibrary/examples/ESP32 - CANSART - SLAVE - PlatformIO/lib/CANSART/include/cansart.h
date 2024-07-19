#ifndef CANSART_H
#define CANSART_H

#define CANSART_VERSION "3.0.0"

#include "stdint.h"
#include "cansart_db.h"
#include "cansartP.h"
#include "driver.h"

struct framesT
{
    uint8_t ID ;
    uint8_t DATA1 ;
    uint8_t DATA2 ;
    uint8_t DATA3 ;
    uint8_t DATA4 ;
    uint8_t DATA5 ;
    uint8_t DATA6 ;
    uint8_t DATA7 ;
    uint8_t DATA8 ;
    uint8_t LENGHT;
};

#if MCU_TYPE == MY_ARDUINO
void cansart_init(HardwareSerial &serialPort, uint32_t baudrate);
#elif MCU_TYPE == STM32
void cansart_init(UART_HandleTypeDef serialPort,unsigned long baudrate);
#elif MCU_TYPE == PIC32
// To include
#elif MCU_TYPE == RENESAS
// To include
#endif

void cansart_init_Frames();
uint8_t cansart_updateDB(void *source);
uint8_t cansart_write_slave_DB(void *source);

#endif