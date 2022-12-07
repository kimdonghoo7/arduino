#include<TimerOne.h>

int buz = 22;
int led = 23;
int led2 = 24;
int sw = 2;
int switch_state;

void setup() {
  pinMode(buz,OUTPUT);
  pinMode(led,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(sw,INPUT);

  Timer1.initialize(2000000);
  Timer1.attachInterrupt( timerIsr );

}

void loop() {
  if(digitalRead(sw)==HIGH){
    digitalWrite(buz,HIGH);
  }
  else{
    digitalWrite(buz,LOW);
  }
  
}

void timerIsr()
{
  digitalWrite(led,digitalRead(led)^1);
  if(digitalRead(led)==LOW){
    digitalWrite(led2,HIGH);
  }
  else{
    digitalWrite(led2,LOW);
  }
}
