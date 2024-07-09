#ifndef CANSART_H
#define CANSART_H

#include "cansart_db.h"
#include "cansartP.h"
#include "driver.h"

#define MCU MCU_TYPE

#if MCU == ARDUINO
#include <Arduino.h>
#include <HardwareSerial.h>

#elif MCU == STM32
// To include
#elif MCU == PIC32
// To include
#elif MCU == RENESAS
// To include
#endif

uint8_t transmitMessage(uint8_t ID, uint8_t *txmessageBuffer, uint8_t messageLength);
void tx_checksum_calculator();
uint8_t availableMessage(uint8_t *rxmessageBuffer);
uint8_t rx_checksum_calculator();
uint8_t convertData(char *receivedData);
uint8_t receiveUSART(char *buffer);

#endif
