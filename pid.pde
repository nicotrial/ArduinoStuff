    
int sensorValue = 0;
int outputValue = 0;

long target = 300;
float KP = 2.25 ; //position multiplier (gain)
float KI = .35; // Intergral multiplier (gain)
float KD = 1.0; // derivative multiplier (gain)

int lastError = 0;
int sumError = 0;

int iMax = 100;
int iMin = 0;

    void setup() {
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
}
    
void loop() {
  sensorValue = analogRead(A5);
  long error = sensorValue - target ;
  long ms = KP * error + KD * (error - lastError) +KI * (sumError);
  if(sumError > iMax) {
      sumError = iMax;
      } else if(sumError < iMin){
      sumError = iMin;
  } 
  if(ms > 0){
    digitalWrite(2,HIGH);
    digitalWrite(4,LOW);      
  }
  if(ms < 0){
    digitalWrite(2,LOW);
    digitalWrite(4,HIGH);    
    ms = -1 * ms;
  }
  int motorSpeed = map(ms,0,1024,0,100);
  analogWrite(3,motorSpeed);
}
