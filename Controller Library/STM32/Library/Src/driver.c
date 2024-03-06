#include "driver.h"

UART_HandleTypeDef *Lusart;
uint8_t mainBuffer[49];
UART_HandleTypeDef Cusart;
volatile uint8_t uartDone = 0;

void setCANSART_Driver(UART_HandleTypeDef *usart, unsigned long baudrate) {
	Lusart = usart;
	HAL_UARTEx_ReceiveToIdle_DMA(Lusart, mainBuffer, 49);

}

void sendData(uint16_t sendByte) {
	Cusart = *Lusart;
	printf("%i", sendByte);
	printf("%c", '\0');
}

void sendFinishData() {
	Cusart = *Lusart;
	printf("%c", '\n');
}

int newData() {

	if (uartDone) {
		uartDone = 0;

		return 1;
	} else {

		return 0;
	}
}

uint8_t getData(uint8_t *pData) {

	memcpy(pData, mainBuffer, sizeof mainBuffer);
	memset(mainBuffer,0,sizeof mainBuffer);
	HAL_UARTEx_ReceiveToIdle_DMA(Lusart, mainBuffer, 49);
	return 1;
}

void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size){

	uartDone = 1;
}

