
#include <Arduino.h>
#include "cansart.h"

#define INPUT_PIN 16

frame10 frames10;
frame121 frames121;

uint8_t i = 0;

unsigned long oldMillis = 0;

uint8_t temp_LED_SET = 0;
uint8_t LED_SET = 0;

void cansartTasks();
void setup()
{

  Serial.begin(115200);

  cansart_init_Frames();
  cansart_init(Serial1, 115200,4,2,millis); //Set Serial Driver, Baudrate, RX pin, TX pin, ms Timer function (As it is Arduino, we pass millis())
  
  pinMode(INPUT_PIN, INPUT);

  Serial.println("CANSART MASTER");

}

void loop()
{

  if (millis() - oldMillis > 500)
  {
    Serial.print("ID: ");
    Serial.print(frames10.ID);
    Serial.print(" DATA1: ");
    Serial.print(frames10.DATA1);
    Serial.print(" DATA2: ");
    Serial.print(frames10.DATA2);
    Serial.print(" DATA3: ");
    Serial.print(frames10.DATA3);
    Serial.print(" DATA4: ");
    Serial.print(frames10.DATA4);
    Serial.print(" DATA5: ");
    Serial.print(frames10.DATA5);
    Serial.print(" DATA6: ");
    Serial.print(frames10.DATA6);
    Serial.print(" DATA7: ");
    Serial.print(frames10.DATA7);
    Serial.print(" DATA8: ");
    Serial.println(frames10.DATA8);

    frames121.DATA2++;

    oldMillis = millis();
  }

  if (frames121.DATA2 >= 250)
  {
    frames121.DATA2 = 0;
  }

  frames121.DATA1 = digitalRead(INPUT_PIN);

  cansartTasks();
}

void cansartTasks()
{
  cansart_updateDB(&frames10);
  cansart_updateDB(&frames121);
}
