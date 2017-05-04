// Sweep
// by BARRAGAN <http://barraganstudio.com> 
// This example code is in the public domain.
 
int i=0,n=0,x[4]={0,0,1,1},y[4]={0,1,0,1},c[4]={1,1,1,1},t=1;
float incr=0.025,bias=0.5,w[3]={0,0.75,0.75},z[4]={0,0,0,1},zd[4]={1,0,1,1};

void setup() 
{ 
    // initialize the serial communication:
  Serial.begin(9600);
} 
 
 
void loop() 
{ 
  while(i<4){
  //if((w[0]*c[i]+w[1]*x[i]+w[2]*y[i])>=t){z[i]=1;}else{z[i]=0;}
  z[i]=(w[0]*c[i]+w[1]*x[i]+w[2]*y[i])>=t;
  i++;
  }
  i=0;
  
  while(i<4){
  if(z[i]<zd[i]){
    if(c[i]){w[0]=(w[0]+incr);}
    if(x[i]){w[1]=(w[1]+incr);}
    if(y[i]){w[2]=(w[2]+incr);}
  }else{
    if(z[i]==zd[i]){}else{
    if(c[i]){w[0]=(w[0]-incr);}
    if(x[i]){w[1]=(w[1]-incr);}
    if(y[i]){w[2]=(w[2]-incr);}
    }}
  i++;
  }
  i=0;
  
  Serial.print("  peso0=");
  Serial.print(w[0]);
  Serial.print("  peso1=");
  Serial.print(w[1]);
  Serial.print("  peso2=");
  Serial.print(w[2]);
 delay(100);
 Serial.print("salida0");
 Serial.print("= "); 
 Serial.println(z[0], DEC);
 delay(100);
 Serial.print("salida1");
 Serial.print("= "); 
 Serial.println(z[1], DEC);
 delay(100);
 Serial.print("salida2");
 Serial.print("= "); 
 Serial.println(z[2], DEC);
 delay(100);
 Serial.print("salida3");
 Serial.print("= "); 
 Serial.println(z[3], DEC);
   delay(500);
} 
