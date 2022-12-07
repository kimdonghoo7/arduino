#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F, 16, 2);
#include <util/delay.h>
#define DELAY 100

volatile int count=0;
volatile int count1=0;
const byte interruptPin=2;
const byte interruptPin1=3;


void setup() {
  lcd.init();
  lcd.backlight();
  
  Serial.begin(9600);
 noInterrupts();
DDRA=0x00;
 interrupts();
 attachInterrupt(digitalPinToInterrupt(interruptPin),cnt,FALLING);
 attachInterrupt(digitalPinToInterrupt(interruptPin1),cnt1,RISING);
 
}

void loop() {

if(digitalRead(2)==HIGH){
  swled();
}
   


if(digitalRead(3)==HIGH)
{
  swled1();
}
}

void swled(){
  lcd.setCursor(0,0);
    lcd.print("FALLING EDGE");
    lcd.setCursor(0,1);
    lcd.print(count1);
  if(count==1){
    PORTA = 0x08;
  }
  if(count==2){
    PORTA = 0x0c;
  }
  if(count==3){
    PORTA = 0x0e;
  }
  if(count==4){
    PORTA = 0x0f;
  } 
   if(count==5){
   PORTA = 0x1e;
  }
  if(count==6){
    PORTA = 0x1c;
  }
  if(count==7){
    PORTA = 0x18;
  }
  if(count==8){  
    PORTA = 0x00;
  }
  if(count>8){
    PORTA = 0x00;
    count=0;
  }
}

void swled1(){
  lcd.setCursor(0,0);
    lcd.print("RISING EDGE");
    lcd.setCursor(0,1);
    lcd.print(count1);
  if(count1==1){
    PORTA = 0x01;
  }
  if(count1==2){
    PORTA = 0x03;
  }
  if(count1==3){
    PORTA = 0x07;
  }
  if(count1==4){
    PORTA = 0x0f;
  } 
  if(count1==5){
   PORTA = 0x07;
  }
  if(count1==6){
    PORTA = 0x03;
  }
  if(count1==7){
    PORTA = 0x01;
  }
  if(count1==8){  
    PORTA = 0x00;
  }
  if(count1>8){
    PORTA = 0x00;
    count1=0;
  }
  
}
void cnt()
 {
  _delay_ms(DELAY);
  if(digitalRead(2)==HIGH){
    count++;
  }
 }

  void cnt1()
  {
    _delay_ms(DELAY);
  if(digitalRead(3)==HIGH){
    count1++;
  }
  }
  
