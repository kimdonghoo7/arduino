#include <Stepper.h>

int IN1 = 22; //IN1은 2번 핀에 연결
int IN2 = 24; //IN2는 3번 핀에 연결
int IN3 = 26; //IN3는 4번 핀에 연결
int IN4 = 28; //IN4는 5번 핀에 연결
Stepper step1(2048, IN1, IN3, IN2, IN4);


int echo = 23;
int trig = 25;

void setup() {
  step1.setSpeed(10); //분당 10회 회전
Serial.begin(9600);
pinMode(trig,OUTPUT);
pinMode(echo,INPUT);
}

void loop() {
   float cycletime;
 float distance;

 digitalWrite(trig,HIGH);
 delay(10);
 digitalWrite(trig,LOW);

 cycletime = pulseIn(echo,HIGH);

 distance = ((340 * cycletime)/10000)/2;

  Serial.print("Distance");
   Serial.print(distance);
    Serial.println("cm");
    delay(2000);
 if (distance<=10){
  step1.step(1024);
  step1.step(-1024);
}
else if (distance>10&&30>distance){
  step1.step(2048);
  }
  else if (distance>30){
  step1.step(-2048);
  }
}
