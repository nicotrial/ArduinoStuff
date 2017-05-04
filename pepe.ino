#include <SoftwareSerial.h>
#include <stdlib.h>
#define rxPin 2
#define txPin 3
SoftwareSerial mySerial =  SoftwareSerial(rxPin, txPin);


char inData[5];
String Data;
int state=0;
int spd=255;
int y;
int i;
int leftMotor;
int rightMotor;
char recieved;

void setup(){
  analogWrite(5,0);
  analogWrite(9,0);
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  mySerial.begin(9600);
  //Serial.begin(9600);
  mySerial.println("Power On Bluetooth");
  //Serial.println("Power On");
}



void loop()
{

   while (mySerial.available() > 0){
        char recievedin = mySerial.read();
        recieved=recievedin;
        if (recieved == 'w'){
         digitalWrite(10,HIGH);
         digitalWrite(11,LOW);
         analogWrite(9,spd);
         digitalWrite(6,HIGH);
         digitalWrite(7,LOW);
         analogWrite(5,spd);
        }
        if (recieved == 's'){
         digitalWrite(10,LOW);
         digitalWrite(11,HIGH);
         analogWrite(9,spd);
         digitalWrite(6,LOW);
         digitalWrite(7,HIGH);
         analogWrite(5,spd);
        }
        
        if (recieved == 'd'){
         digitalWrite(10,LOW);
         digitalWrite(11,HIGH);
         analogWrite(9,spd);
         digitalWrite(6,HIGH);
         digitalWrite(7,LOW);
         analogWrite(5,spd);
        }
        
        if (recieved == 'a'){
         digitalWrite(10,HIGH);
         digitalWrite(11,LOW);
         analogWrite(9,spd);
         digitalWrite(6,LOW);
         digitalWrite(7,HIGH);
         analogWrite(5,spd);
        }
        if (recieved == 'o'){
         spd++;
        }
        if (recieved == 'l'){
         spd--;
        }
        if (recieved == '0'){
         analogWrite(5,0);
         analogWrite(9,0);
        }
        
        // Process message when new line character is recieved
     
   }
   
   //analogWrite(5,0);
   //analogWrite(9,0);
    
}   
