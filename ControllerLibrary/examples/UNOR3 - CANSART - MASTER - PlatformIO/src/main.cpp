
#include <Arduino.h>
#include "cansart.h"
#include <SoftwareSerial.h> 

#define INPUT_PIN 6

SoftwareSerial mySerial(2, 3); // RX, TX

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
  mySerial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(INPUT_PIN, INPUT);
  mySerial.println("CANSART MASTER");  
}

void loop()
{

  if (millis() - oldMillis > 500)
  {
    mySerial.print("ID: ");
    mySerial.print(frames10.ID);
    mySerial.print(" DATA1: ");
    mySerial.print(frames10.DATA1);
    mySerial.print(" DATA2: ");
    mySerial.print(frames10.DATA2);
    mySerial.print(" DATA3: ");
    mySerial.print(frames10.DATA3);
    mySerial.print(" DATA4: ");
    mySerial.print(frames10.DATA4);
    mySerial.print(" DATA5: ");
    mySerial.print(frames10.DATA5);
    mySerial.print(" DATA6: ");
    mySerial.print(frames10.DATA6);
    mySerial.print(" DATA7: ");
    mySerial.print(frames10.DATA7);
    mySerial.print(" DATA8: ");
    mySerial.println(frames10.DATA8);

frames121.DATA2++;

    oldMillis = millis();
  }

  if(frames121.DATA2 >= 250){
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
