#ifndef CANSART_DB_H
#define CANSART_DB_H

#include "cansart.h"

/**
 * @brief Define the MCU type
 * 
 * @param ARDUINO
 * @param STM32 
 * @param PIC32 
 * @param RENESAS
 */
#define MCU_TYPE ARDUINO

/**
 * @brief Define the mode of the device - always need a master and a slave on the network
 * 
 * @param MASTERMODE : Works as data requester and data provider
 * @param SLAVEMODE  : Works as data provider
 */
#define SLAVEMODE 1

struct frame10
{
    uint8_t ID = 10;
    uint8_t DATA1 = 0;
    uint8_t DATA2 = 0;
    uint8_t DATA3 = 0;
    uint8_t DATA4 = 0;
    uint8_t DATA5 = 0;
    uint8_t DATA6 = 0;
    uint8_t DATA7 = 0;
    uint8_t DATA8 = 0;
    uint8_t LENGHT = 8;
};

struct frame23
{
    uint8_t ID = 23;
    uint8_t DATA1 = 0;
    uint8_t DATA2 = 0;
    uint8_t DATA3 = 0;
    uint8_t DATA4 = 0;
    uint8_t DATA5 = 0;
    uint8_t DATA6 = 0;
    uint8_t DATA7 = 0;
    uint8_t DATA8 = 0;
    uint8_t LENGHT = 8;
};

struct frame121
{
    uint8_t ID = 121;
    uint8_t DATA1 = 0;
    uint8_t DATA2 = 0;
    uint8_t DATA3 = 0;
    uint8_t DATA4 = 0;
    uint8_t DATA5 = 0;
    uint8_t DATA6 = 0;
    uint8_t DATA7 = 0;
    uint8_t DATA8 = 0;
    uint8_t LENGHT = 8;
};

#endif