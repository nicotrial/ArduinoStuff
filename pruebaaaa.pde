#include <Servo.h>

Servo servo;

const int analogInPin = A0;

int pos;
int sensorValue = 0;        // value read from the pot
int outputValue = 0;


void setup(){
 servo.attach(3);
}

void loop(){
servo.write(pos);
sensorValue = analogRead(analogInPin); 
outputValue = map(sensorValue, 0, 1023, 0, 180); 
pos=outputValue;
}
