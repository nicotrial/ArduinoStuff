
#include <SoftwareSerial.h>
#include <Servo.h> 
#define rxPin 2
#define txPin 3
SoftwareSerial mySerial =  SoftwareSerial(rxPin, txPin);

Servo myservo;
String inData;
String Data;
int state=0;
boolean armed=false;
boolean pass=false;

void setup(){
  myservo.attach(6);
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  pinMode(12, OUTPUT); //parlante
  pinMode(11, OUTPUT);//Led
  pinMode(8, INPUT);//puerta
  pinMode(9, INPUT);//puerta
  pinMode(10, INPUT);//puerta
  mySerial.begin(9600);
  Serial.begin(9600);
  mySerial.println("Power On Bluetooth");
  Serial.println("Power On");
}



void loop()
{

   while (mySerial.available() > 0){
        char recieved = mySerial.read();
        // Process message when new line character is recieved
        if (recieved == '\n'){
            mySerial.print("Arduino Received: ");
            mySerial.println(inData);
            
            if(inData=="helo"){
              mySerial.println("Hi there..How Are U");
              soundAlarm();
            }
            
            
            
            Data=inData;
            inData = ""; // Clear recieved buffer
        }else{
          inData += recieved;
        }
    }
    
    switch(state){
      case 0: 
        if(pass==false){
          mySerial.println("Welcome");
          mySerial.println("InsertPassword");
          digitalWrite(11,LOW);
          pass=true;
        }
          if(Data=="npjmfl1010"){
            state=1;
            soundAlarm();
            pass=false;
          }
        break;
     
      case 1: 
          if(pass==false){
            mySerial.println("Contraseña correcta");
            mySerial.println("Alarma Desactivada");
            mySerial.println("Escriba 'arm' para activar");
            
            pass=true;
          }
          if(Data=="arm"){
            state=2;
            soundAlarm();
            soundAlarm();
            pass=false;
          }
          digitalWrite(11,LOW);
          myservo.write(45);
          
        break;
       
       case 2: 
          if(pass==false){
            mySerial.println("Alarma Activada");
            mySerial.println("Escriba Contraseña para desactivar");
            pass=true;
          }
          if(Data=="npjmfl1010"){
            state=1;
            soundAlarm();
            pass=false;
          }
          digitalWrite(11,HIGH);
          myservo.write(90);
          if(digitalRead(9)==LOW||digitalRead(10)==LOW){
            soundAlarm();
            mySerial.println("LLAMANDO POLICIA!!");
          }
        break;     
        
      default:
      break; 
    }
  
}   


void soundAlarm(){
  for(int i=0;i<100;i++){
      digitalWrite(12, 1);
      delay(1);
      digitalWrite(12, 0);
      delay(1);
   }
   for(int i=0;i<100;i++){
      digitalWrite(12, 1);
      delay(2);
      digitalWrite(12, 0);
      delay(2);
   }
}
