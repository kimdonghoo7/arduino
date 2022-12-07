#include <util/delay.h>
#define DELAY 100
#define DELAY1 50

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F, 16, 2);

volatile int count1 = 0;
volatile int count2 = 0;

const byte interruptPin1 = 2;
const byte interruptPin2 = 3;


void setup() {
lcd.init();
  lcd.backlight();
  noInterrupts();
  DDRA = 0xff;
  interrupts();
  
  attachInterrupt(digitalPinToInterrupt(interruptPin1),cnt1,FALLING);
  attachInterrupt(digitalPinToInterrupt(interruptPin2),cnt2,RISING);
}


void loop() {
  if(digitalRead(2)==HIGH){
    swled1();
  }

  if(digitalRead(3)==HIGH){
  swled2();
  }
}

void swled1(){
  lcd.setCursor(0,0);
    lcd.print("FALLINGEDGE");
    lcd.setCursor(0,1);
    lcd.print(count1);
  if(count1==1){
    PORTA = 0x08;
  }
  if(count1==2){
    PORTA = 0x0c;
  }
  if(count1==3){
    PORTA = 0x0e;
  }
  if(count1==4){
    PORTA = 0x0f;
  } 
   if(count1==5){
   PORTA = 0x1e;
  }
  if(count1==6){
    PORTA = 0x1c;
  }
  if(count1==7){
    PORTA = 0x18;
  }
  if(count1==8){  
    PORTA = 0x00;
  }
  if(count1>8){
    PORTA = 0x00;
    count1=0;
  }
}

void swled2(){
    lcd.setCursor(0,0);
    lcd.print("RISINGEDGE");
    lcd.setCursor(0,1);
    lcd.print(count2);
  if(count2==1){
    PORTA = 0x01;
  }
  if(count2==2){
    PORTA = 0x03;
  }
  if(count2==3){
    PORTA = 0x07;
  }
  if(count2==4){
    PORTA = 0x0f;
  } 
  if(count2==5){
   PORTA = 0x07;
  }
  if(count2==6){
    PORTA = 0x03;
  }
  if(count2==7){
    PORTA = 0x01;
  }
  if(count2==8){  
    PORTA = 0x00;
  }
  if(count2>8){
    PORTA = 0x00;
    count2=0;
  }
}

void cnt1(){
 _delay_ms(DELAY1);
  if(digitalRead(2)==HIGH){
    count1++;
}
}

void cnt2(){
   _delay_ms(DELAY);
  if(digitalRead(3)==HIGH){
    count2++;
}
}
