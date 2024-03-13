#include <Arduino.h>
#include <HardwareSerial.h>
#include "cansart.h"
#include "SoftwareSerial.h"

#define POTENTIOMETER_PIN A0

SoftwareSerial mySerial(11, 10); // RX, TX

HardwareSerial &serialPort = Serial;

frame10 frames10;
//frame23 frames23;
frame121 frames121;

uint8_t tx_ID = 25;
uint8_t tx_LENGHT = 8;
uint8_t tx_DATA[8] = {10, 1, 2, 3, 4, 5, 6, 7};

unsigned long oldMillis = 0;

void cansartTasks();

void setup()
{

  setCANSART_Driver(serialPort, (unsigned long)115200);

  mySerial.begin(115200);

  pinMode(13, OUTPUT);

  mySerial.println("Slave Mode!");

  delay(1000);
}

void loop()
{

  uint16_t analogTest = analogRead(POTENTIOMETER_PIN);

  frames10.DATA7 = analogTest >> 8;
  frames10.DATA8 = analogTest;

  if (frames10.RPM > 250)
  {
    frames10.RPM = 0;
  }
  if (frames10.SPEED > 250)
  {
    frames10.SPEED = 0;
  }
 //if (frames23.TEMP > 250)
 //{
 //  frames23.TEMP = 0;
 //}
 //if (frames23.OIL > 250)
 //{
 //  frames23.OIL = 0;
 //}
  if (frames121.SetPower > 250)
  {
    frames121.SetPower = 0;
  }
  if (frames121.SetRPM > 250)
  {
    frames121.SetRPM = 0;
  }

  if (millis() - oldMillis > 1000)
  {
    digitalWrite(13, !digitalRead(13));
    frames121.SetRPM++;
    frames121.SetPower++;
    frames10.RPM++;
    frames10.SPEED++;
   // frames23.TEMP++;
    //frames23.OIL++;
    mySerial.print("setRPM: ");
    mySerial.print(frames121.SetRPM);
    mySerial.print("  setPWR: ");
    mySerial.print(frames121.SetPower);
    mySerial.print("  RPM: ");
    mySerial.print(frames10.RPM);
    mySerial.print("  SPEED: ");
    mySerial.print(frames10.SPEED);
    //mySerial.print("  TEMP: ");
   // mySerial.print(frames23.TEMP);
   // mySerial.print("  OIL: ");
   // mySerial.print(frames23.OIL);
    mySerial.println(" ");

    oldMillis = millis();
  }

  cansartTasks();
}

void cansartTasks()
{
  updateDB(&frames121);
  updateDB(&frames10);
 // updateDB(&frames23);
}
