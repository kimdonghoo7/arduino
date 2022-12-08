#include <Stepper.h>

int IN1 = 22; //IN1은 2번 핀에 연결
#include <Stepper.h>

int IN1 = 22; //IN1은 2번 핀에 연결
int IN2 = 24; //IN2는 3번 핀에 연결
int IN3 = 26; //IN3는 4번 핀에 연결
int IN4 = 28; //IN4는 5번 핀에 연결
Stepper step1(2048, IN1, IN3, IN2, IN4);



int tilt = 30;
int sw = 2;
void setup() {

Serial.begin(9600);
attachInterrupt(0,blink,FALLING);
pinMode(2,INPUT);
pinMode(30,INPUT);
step1.setSpeed(10); //분당 10회 회전
}

void loop() {



 if (digitalRead(tilt)==HIGH){
Serial.println("COUNTERclockwise");
step1.step(-2048);
}
else if (digitalRead(tilt)==LOW){
  step1.step(2048);
  }

}

void blink(){
  int sw_status = digitalRead(sw);

  while (sw_status == HIGH){
    
    Serial.println("STEP MOTOR STOP");
    step1.step(0);
    }
  }
