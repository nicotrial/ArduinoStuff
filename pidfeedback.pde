    
int sensorValue = 0;
int sensorValue1 = 0;
int outputValue = 0;
unsigned int i=0,time=0;
int motorSpeed=0;
int feedback=0;

int target = 0;
float KP = 5.0 ; //position multiplier (gain)
float KI = 0.03; // Intergral multiplier (gain)
float KD = 8.0; // derivative multiplier (gain)

int lastError = 0;
int integral = 0;
int derivative = 0;

int iMax = 600;
int iMin = -600;

    void setup() {
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
 //Serial.begin(9600);
}
    
void loop() {
  sensorValue = analogRead(A0);
  if(time>1000){target =degsin()1000;time=0;}else{time++;} //analogRead(A1);
  feedback=map(analogRead(A2),0,120  ,0,255);
  int error = target- sensorValue;
  integral= integral + error;
  derivative= error - lastError;
  long ms = KP * error + KD * (derivative) +KI * (integral);
  
  lastError = error;
  
  if(integral > iMax) {
      integral = iMax;
      } else if(integral < iMin){
      integral = iMin;
      
  if(ms>6000)ms=6000;else if(ms<-6000)ms=-6000;
  } 
  
  if(ms > 0){
    digitalWrite(2,HIGH);
    digitalWrite(4,LOW);
    //ms = -1 * ms;
    motorSpeed = map(ms,0,300,0,255);
    if(motorSpeed >= 255)motorSpeed=255;
    analogWrite(3,motorSpeed);
   //feedback output
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);
    analogWrite(9,feedback);
    
  }
  if(ms < 0){
    digitalWrite(2,LOW);
    digitalWrite(4,HIGH); 
     ms = -1 * ms;
    motorSpeed = map(ms,0,300,0,255);
    if(motorSpeed>=255)motorSpeed=255;
    analogWrite(3,motorSpeed);
    
    //feedback output
    digitalWrite(7,HIGH);
    digitalWrite(8,LOW);
    analogWrite(9,feedback);
    
  }
  //Serial.print("\n sensor = ");
  //Serial.print(sensorValue);
  //Serial.print(" output = ");
  //Serial.print(ms);
  //Serial.print(" derivative = ");
  //Serial.print(derivative);
  //Serial.print(" integral = ");
  //Serial.print(integral);
  //Serial.print(" error = ");
  //Serial.print(error);
  //Serial.print(" acceleracion = ");
  //Serial.print(motorSpeed);
}
