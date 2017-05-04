#include <SoftwareSerial.h>
#include <Servo.h> 
SoftwareSerial miSerial =  SoftwareSerial(2,3);

Servo miServo;
char letra;



void setup(){
 miSerial.begin(9600);
 miSerial.println("Hola Frank");
 miServo.attach(6);
}

void loop(){
  while(miSerial.available()>0){
    letra=miSerial.read();
    //miSerial.println(letra);
    switch(letra){
      case 'a':miServo.write(45);break;
      case 'b':miServo.write(120);break;
      case 'u':miServo.write(110);
               miSerial.println("hola");
               break;
    }
  }
  
}
