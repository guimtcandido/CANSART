#include <Arduino.h>
#include "ControllerLibrary/CANSART_API/inc/cansart.h"

frame10 frames10;
frame121 frames121;

uint8_t i = 0;

unsigned long oldMillis = 0;

uint8_t temp_LED_SET = 0;
uint8_t LED_SET = 0;

void cansartTasks();
void setup()
{

  cansart_init_Frames();
  cansart_init(Serial, 115200);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{

  if (temp_LED_SET)
  {
    LED_SET = 1;
  }
  else
  {
    LED_SET = 0;
  }

  digitalWrite(LED_BUILTIN, LED_SET);

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

  temp_LED_SET = frames121.DATA1;
  frames10.DATA1 = frames121.DATA2;
}
