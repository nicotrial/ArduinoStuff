
int number_in = 0;
char vel=100;
unsigned long previousMillis = 0;
unsigned long interval = 1000;
unsigned long currentMillis;

void setup() {
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  if (Serial.available() > 0) {
    number_in = Serial.read();
  }
currentMillis = millis();  
switch (number_in) {
    case 01:
    digitalWrite(2,LOW);
    digitalWrite(4,HIGH);
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);
    previousMillis = currentMillis+interval;
    break;
    case 02:
    digitalWrite(2,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(7,HIGH);
    digitalWrite(8,LOW);
    previousMillis = currentMillis+interval;
    break;
    case 03:
    digitalWrite(2,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);
    previousMillis = currentMillis+interval;
    break;
    case 04:
    digitalWrite(2,LOW);
    digitalWrite(4,HIGH);
    digitalWrite(7,HIGH);
    digitalWrite(8,LOW);
    previousMillis = currentMillis+interval;
    break;
    case 05:
    digitalWrite(2,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(7,HIGH);
    digitalWrite(8,HIGH);
    break;
    case 06:
    analogWrite(3,vel=vel-10);
    analogWrite(9,vel=vel-10);
    break;
    case 07:
    analogWrite(3,vel=10+vel);
    analogWrite(9,vel=10+vel);
    break;
    default:break;
}

  number_in = 0;
    if(currentMillis > (previousMillis)) {
    digitalWrite(2,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(7,HIGH);
    digitalWrite(8,HIGH);
      // save the last time you blinked the LED  
    
  }
}
