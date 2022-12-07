#include <MsTimer2.h>

int buz = 22;
int led = 23;
int led2 = 24;
int sw = 2;
int switch_state;
int LED_state;

void setup() {
  pinMode(buz,OUTPUT);
  pinMode(led,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(sw,INPUT);
  MsTimer2::set(2000,timer0);
  MsTimer2::start();

}

void loop() {
 
   switch_state=digitalRead(2);
   if(switch_state==HIGH){
    digitalWrite(buz,HIGH);
   }
   
   else{
   digitalWrite(buz,LOW);
   }
}


 void timer0()
 {
 if(LED_state==HIGH){
  digitalWrite(led,LED_state);
  digitalWrite(led2,LOW);
 }
 if(LED_state==LOW){
  digitalWrite(led,LED_state);
  digitalWrite(led2,HIGH);
 }
 LED_state=!LED_state;
           
  }

  
