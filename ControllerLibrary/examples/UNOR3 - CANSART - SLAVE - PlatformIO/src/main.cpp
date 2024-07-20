/* The library is hybrid, the slave project can run with a pc as master or a controller as master, no need to change anything except the serial driver if needed*/

#include <Arduino.h>
#include "cansart.h"
#include <SoftwareSerial.h>

#define OUTPUT_PIN 5 // SET a pin so you can togle from master

frame10 frames10;
frame121 frames121;

SoftwareSerial mySerial(10, 11); // RX, TX

uint8_t i = 0;

unsigned long oldMillis = 0;

uint8_t temp_OUT_SET = 0;
uint8_t OUT_SET = 0;

void cansartTasks();
void setup()
{

  Serial.begin(115200);

  cansart_init_Frames();
  cansart_init(Serial, 115200); // Set Serial Driver, Baudrate

  pinMode(OUTPUT_PIN, OUTPUT);

  mySerial.println("CANSART SLAVE");
}

void loop()
{

  if (temp_OUT_SET)
  {
    OUT_SET = 1;
  }
  else
  {
    OUT_SET = 0;
  }

  digitalWrite(OUTPUT_PIN, OUT_SET);

  if (millis() - oldMillis > 500)
  {
    frames10.DATA2 = i;
    frames10.DATA3 = i;
    frames10.DATA4 = i;
    frames10.DATA5 = i;
    frames10.DATA6 = i;
    frames10.DATA7 = i;
    frames10.DATA8 = i;

    i++;
    oldMillis = millis();
  }

  cansartTasks();
}

void cansartTasks()
{
  cansart_updateDB(&frames10);
  cansart_updateDB(&frames121);

  temp_OUT_SET = frames121.DATA1;

  frames10.DATA1 = frames121.DATA2;
}
