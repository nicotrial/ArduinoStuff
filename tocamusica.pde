#define aC 131
#define aCs 138
#define aD 147
#define aDs 155
#define aE 165
#define aF 174
#define aFs 185
#define aG 196
#define aGs 208
#define aA 220
#define aAs 233
#define aB 247

#define bC 261
#define bCs 277
#define bD 293
#define bDs 311
#define bE 329
#define bF 349
#define bFs 370
#define bG 392
#define bGs 415
#define bA 440
#define bAs 466
#define bB 494

#define cC 523
#define cCs 554
#define cD 587
#define cDs 622
#define cE 659
#define cF 698
#define cFs 740
#define cG 784
#define cGs 830
#define cA 880
#define cAs 932
#define cB 988

#define dC 1046
#define dCs 1108
#define dD 1174
#define dDs 1244
#define dE 1318
#define dF 1396
#define dFs 1479
#define dG 1567
#define dGs 1661
#define dA 1760
#define dAs 1864
#define dB 1975

int i[]={dE,100,dE,200,dE,200,dC,100,dE,200,dG,500,(cG+bG)/2,500,dC,300,dG,300,cE,300,cA,200,cB,200,cAs,100,cA,200,cG,100,dE,200,dG,100,dA,200,dF,100,dG,200,dE,200,dC,100,dD,100,cB,400,dC,300,dG,300,cE,300,cA,200,cB,200,cAs,100,cA,200,cG,100,dE,200,dG,100,dA,200,dF,100,dG,200,dE,200,dC,100,dD,100,cB,500,dG,100,dFs,100,dF,100,dDs,200,dE,200,cA,200,dC,200,cA,200,dC,100,dD,100,dE,200,dG,100,dFs,100,dF,100,dD,200,dE,300,dC+cC/2,200,dC+cC/2,100,dC+cC/2,600,dG,100,dFs,100,dF,100,dDs,200,dE,200,cA,200,dC,200,cA,200,dC,100,dD,200,dE,200,dDs,300,dD,300,dC,900,dC,400,cG,400,cE,400,cGs,300,cAs,300,cGs,300,cG,200,cA,300,cG,300,cFs,100,cE,100,cFs,900};
//int i[]={dC,400,cG,400,cE,400,cGs,300,cAs,300,cGs,300,cG,200,cA,300,cG,300,cFs,100,cE,100,cFs,900};
long sel=0;
void setup() {
  pinMode(9, OUTPUT);
}

void loop() {
tone(9,i[sel]/10);
delay(i[sel+1]);
noTone(9);
delay(50);
sel=sel+2;
if(sel==174){
  while(1){
    digitalWrite(9,1);
    delay(100);
    digitalWrite(9,0);
    delay(700);
    }
  }
      // save the last time you blinked the LED  
    
  }


