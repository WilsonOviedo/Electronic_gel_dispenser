#include <Arduino.h>

long distancia=0;
long duracion=0;

int ultrasonicRead(int pinTrig, int pinEcho)
{

    digitalWrite(pinTrig, LOW);
    delayMicroseconds(2);
    digitalWrite(pinTrig, HIGH);
    delayMicroseconds(10);
    digitalWrite(pinTrig, LOW);
    duracion = pulseIn(pinEcho, HIGH);
    distancia = (duracion / 2) / 29;
    return distancia;
}

int infraredRead(int pinSensor)
{

    return map(analogRead(pinSensor),0,1023,0,20);
}