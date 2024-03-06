#ifndef CANSART_DB_H
#define CANSART_DB_H

//#include <Arduino.h>
//#include "main.h"
#include <stdint.h>

#define SLAVEMODE 1


struct frame10
{
    uint8_t ID;
    uint8_t RPM;
    uint8_t SPEED;
    uint8_t DATA3;
    uint8_t DATA4;
    uint8_t DATA5;
    uint8_t DATA6 ;
    uint8_t DATA7 ;
    uint8_t DATA8 ;
    uint8_t LENGHT;
};



struct frame23
{
    uint8_t ID;
    uint8_t TEMP ;
    uint8_t OIL ;
    uint8_t DATA3 ;
    uint8_t DATA4 ;
    uint8_t DATA5 ;
    uint8_t DATA6 ;
    uint8_t DATA7 ;
    uint8_t DATA8 ;
    uint8_t LENGHT;
};

struct frame121
{
    uint8_t ID;
    uint8_t SetRPM ;
    uint8_t SetPower ;
    uint8_t DATA3 ;
    uint8_t DATA4 ;
    uint8_t DATA5 ;
    uint8_t DATA6 ;
    uint8_t DATA7 ;
    uint8_t DATA8 ;
    uint8_t LENGHT;
};

#endif
