           

void setup() {
  // set the speed at 60 rpm:

  analogWrite(5,130);
  analogWrite(9,130);
  // initialize the serial port:
  //Serial.begin(9600);
}

void loop() {
  // step one revolution  in one direction:
   //Serial.println("clockwise");
  steperFW(((48*1)/16)*60*4*0.3,4,220);
  delay(500);
  steperBW(((48*1)/16)*60*4*0.3,4,220);
  delay(500);
  
}

void steperFW(int steps,int spd,int pwr){
  analogWrite(5,pwr);
  analogWrite(9,pwr);
  steps=steps/4;
  for(int i=0;i<steps;i++){
    digitalWrite(6,LOW);
    digitalWrite(7,HIGH);
    digitalWrite(10,HIGH);
    digitalWrite(11,LOW);
    delay(spd);
    digitalWrite(6,LOW);
    digitalWrite(7,HIGH);
    digitalWrite(10,LOW);
    digitalWrite(11,HIGH);
    delay(spd);
    digitalWrite(6,HIGH);
    digitalWrite(7,LOW);
    digitalWrite(10,LOW);
    digitalWrite(11,HIGH);
    delay(spd);
    digitalWrite(6,HIGH);
    digitalWrite(7,LOW);
    digitalWrite(10,HIGH);
    digitalWrite(11,LOW);
    delay(spd);
    }
  }
  
  void steperBW(int steps,int spd,int pwr){
  analogWrite(5,pwr);
  analogWrite(9,pwr);
  steps=steps/4;
    for(int i=0;i<steps;i++){
    digitalWrite(6,HIGH);
    digitalWrite(7,LOW);
    digitalWrite(10,HIGH);
    digitalWrite(11,LOW);
    delay(spd);
    digitalWrite(6,HIGH);
    digitalWrite(7,LOW);
    digitalWrite(10,LOW);
    digitalWrite(11,HIGH);
    delay(spd);
    digitalWrite(6,LOW);
    digitalWrite(7,HIGH);
    digitalWrite(10,LOW);
    digitalWrite(11,HIGH);
    delay(spd);
    digitalWrite(6,LOW);
    digitalWrite(7,HIGH);
    digitalWrite(10,HIGH);
    digitalWrite(11,LOW);
    delay(spd);
    }
}


