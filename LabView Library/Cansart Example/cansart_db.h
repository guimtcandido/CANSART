#ifndef CANSART_DB_H
#define CANSART_DB_H

#include <Arduino.h>

#define SLAVEMODE 0

#define SERVICE_FRAMES_SIZE 2

struct frame10
{
    uint8_t ID = 10;
    uint8_t DATA1 = 10;
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