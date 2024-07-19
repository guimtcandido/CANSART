#ifndef CANSART_DB_H
#define CANSART_DB_H

#include "stdint.h"

#define CANSART_VERSION "3.0.0"

/**
 * @brief Define the MCU type
 * 
 * @param MY_ARDUINO
 * @param STM32 
 * @param PIC32 
 * @param RENESAS
 */
#define MCU_TYPE MY_ARDUINO

/**
 * @brief Define the mode of the device - always need a master and a slave on the network
 * 
 * @param MASTERMODE : Works as data requester and data provider
 * @param SLAVEMODE  : Works as data provider
 */
#define SLAVEMODE 1

struct frame10
{
    uint8_t ID ;
    uint8_t DATA1 ;
    uint8_t DATA2;
    uint8_t DATA3 ;
    uint8_t DATA4 ;
    uint8_t DATA5 ;
    uint8_t DATA6 ;
    uint8_t DATA7 ;
    uint8_t DATA8 ;
    uint8_t LENGHT ;
};

struct frame121
{
    uint8_t ID ;
    uint8_t DATA1 ;
    uint8_t DATA2;
    uint8_t DATA3 ;
    uint8_t DATA4 ;
    uint8_t DATA5 ;
    uint8_t DATA6 ;
    uint8_t DATA7 ;
    uint8_t DATA8 ;
    uint8_t LENGHT ;
};


#endif