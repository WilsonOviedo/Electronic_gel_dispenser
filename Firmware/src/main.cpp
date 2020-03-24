#include "config.h"
#include "functions.h"

Servo Servo_1;

void setup()
{
  //Servo setup
  Servo_1.attach(servoPin);

  //Ultrasonic Setup
  pinMode(sensorUltrasonicPinEcho, INPUT);
  pinMode(sensorUltrasonicPinTrig, OUTPUT);
  //IR sensor setup
  pinMode(sensorIRpin, INPUT);

  //Servo position init
  Servo_1.write(0);
}

void loop()
{

  if (mode == 0)
  {
    if (ultrasonicRead(sensorUltrasonicPinEcho, sensorUltrasonicPinTrig) < triger)
    {
      Servo_1.write(180);
      delay(timePress);
      Servo_1.write(0);
      delay(timeWait);
    }
    else
    {
      Servo_1.write(0);
    }
  }
  else
  {
    if (infraredRead(sensorIRpin) < triger)
    {
      Servo_1.write(180);
      delay(timePress);
      Servo_1.write(0);
      delay(timeWait);
    }
    else
    {
      Servo_1.write(0);
    }
  }
}