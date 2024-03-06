#include "driver.h"
#include "definitions.h"                // SYS function prototypes



void sendData(uint16_t sendByte) {

    printf("%i", sendByte);
    printf("%c", '\0');
}

void sendFinishData() {
    printf("%c", '\n');
}

int newData() {
    return UART1_ReceiverIsReady();
}

uint8_t getData() {
    return UART1_ReadByte();
}



