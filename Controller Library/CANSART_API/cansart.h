#ifndef CANSARTP_H
#define CANSARTP_H

#include "stdint.h"
#include "cansart_db.h"
#include "cansartP.h"

#if MCU_TYPE == ARDUINO
#include "HardwareSerial.h"
#elif MCU_TYPE == STM32
// To include
#elif MCU_TYPE == PIC32
// To include
#elif MCU_TYPE == RENESAS
// To include
#endif

struct framesT
{
    uint8_t ID = 0;
    uint8_t DATA1 = 0;
    uint8_t DATA2 = 0;
    uint8_t DATA3 = 0;
    uint8_t DATA4 = 0;
    uint8_t DATA5 = 0;
    uint8_t DATA6 = 0;
    uint8_t DATA7 = 0;
    uint8_t DATA8 = 0;
    uint8_t LENGHT = 0;
};


uint8_t updateDB(void *source);
uint8_t write_slave_DB(void *source);

#endif