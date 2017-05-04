
#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

#define I2C_ADDR    0x3F // <<----- Add your address here.  Find it from I2C Scanner
#define BACKLIGHT_PIN     3
#define En_pin  2
#define Rw_pin  1
#define Rs_pin  0
#define D4_pin  4
#define D5_pin  5
#define D6_pin  6
#define D7_pin  7

unsigned long n = 1;
int l = 0;
unsigned int lap = 0;
unsigned int blap = 0;
unsigned long ltime = 0;
unsigned long btime = 4294967295;
int buttonState = 0;                                // variable for reading the pushbutton status


LiquidCrystal_I2C  lcd(I2C_ADDR,En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin);

void setup(){
  lcd.begin (16,2);                                   //  <<----- My LCD was 16x2
  pinMode(2,INPUT);                                   //redd switch
 
  // Switch on the backlight
  lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
  lcd.setBacklight(HIGH);
  lcd.home ();                                        // go home

  lcd.print("-= NicoRacing =-");

  cli();//stop interrupts
 
  TCCR1A = 0;                               // set entire TCCR1A register to 0
  TCCR1B = 0;                               // same for TCCR1B
  TCNT1  = 0;                               //initialize counter value to 0;
  // set timer count for 1khz increments
  OCR1A = 1999;// = (16*10^6) / (1000*8) - 1
  // turn on CTC mode
  TCCR1B |= (1 << WGM12);
  // Set CS11 bit for 8 prescaler
  TCCR1B |= (1 << CS11);   
  // enable timer compare interrupt
  TIMSK1 |= (1 << OCIE1A);
  
  sei();                                      //allow interrupts
}

ISR(TIMER1_COMPA_vect){                       //Interrupt at freq of 1kHz to measure reed switch
  n++;
}

void reed(){
  ltime = n;
  n=0;
  if (ltime < btime){
    btime = ltime;
    blap = lap;
    lcd.setCursor (0,0);        // go to start of 2nd line
    lcd.print("                ");
    for (l=0;l<=10;l++){
      lcd.setCursor (0,0);        // go to start of 2nd line
      lcd.print(print_time(btime));
      lcd.print(" Bst ");
      lcd.print(blap,DEC);
      lcd.setCursor (0,1);        // go to start of 2nd line
      lcd.print(print_time(ltime));
      //lcd.print(n++,DEC);
      lcd.print(" Lap ");
      lcd.print(lap,DEC);
      lcd.setBacklight(LOW);      // Backlight off
      delay(100);
      lcd.setBacklight(HIGH);     // Backlight on
      delay(200);
    }
  }else{
    for (l=0;l<=10;l++){
      lcd.setCursor (0,0);        // go to start of 2nd line
      lcd.print(print_time(btime));
      lcd.print(" Bst ");
      lcd.print(blap,DEC);
      lcd.setCursor (0,1);        // go to start of 2nd line
      lcd.print(print_time(ltime));
      //lcd.print(n++,DEC);
      lcd.print(" Lap ");
      lcd.print(lap,DEC);
      delay(200);
      lcd.setCursor (0,1);        // go to start of 2nd line
      lcd.print("                ");
      delay(100);
    }
  }
  lap++;
  lcd.setCursor (0,1);        // go to start of 2nd line
  lcd.print("                ");
}

String print_time(unsigned long t_milli){
    char buffer[20];
    int days, hours, mins, secs;
    int fractime;
    unsigned long inttime;

    inttime  = t_milli / 1000;
    fractime = t_milli % 1000;

    days     = inttime / (24*3600);
    inttime  = inttime % (24*3600);

    hours    = inttime / 3600;
    inttime  = inttime % 3600;

    mins     = inttime / 60;
    inttime  = inttime % 60;

    secs = inttime;       
    sprintf(buffer, "%02d:%02d.%03d",mins, secs, fractime);
    return buffer;
}

void loop(){
  lcd.setCursor (0,1);        // go to start of 2nd line
  lcd.print(print_time(n));
  //lcd.print(n++,DEC);
  lcd.print(" Lap ");
  lcd.print(lap,DEC);
  //delay(100);
  buttonState = digitalRead(2);
  if (buttonState == HIGH) {
    // turn LED on:
    reed();
  }
}
