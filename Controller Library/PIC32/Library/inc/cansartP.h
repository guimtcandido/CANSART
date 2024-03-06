#ifndef CANSARTP_H
#define CANSARTP_H

#include "cansart.h"
#include <String.h>
struct framesT
{
    uint8_t ID;
    uint8_t DATA1 ;
    uint8_t DATA2 ;
    uint8_t DATA3 ;
    uint8_t DATA4 ;
    uint8_t DATA5;
    uint8_t DATA6 ;
    uint8_t DATA7 ;
    uint8_t DATA8 ;
    uint8_t LENGHT ;
};


uint8_t updateDB(void *source);
uint8_t write_slave_DB(void *source);

#endif