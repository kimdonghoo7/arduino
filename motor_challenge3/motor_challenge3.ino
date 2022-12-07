#include<Stepper.h>

#define IN1_PIN 22
#define IN2_PIN 24
#define IN3_PIN 26
#define IN4_PIN 28

Stepper motor (64, IN1_PIN, IN2_PIN, IN3_PIN, IN4_PIN);

void setup() {
  for(int pin = IN1_PIN; pin<IN4_PIN; pin++)
  pinMode(pin,OUTPUT);

 Serial.begin(9600);
 motor.setSpeed(300);

 Serial.println("Speed : 300rpm");
 Serial.print("Enter steps : ");

}

void loop() {
 if(Serial.available()){
  int steps = Serial.parseInt();
 
  if (steps<=4){
  Serial.println(steps);
  motor.step(steps*2048);
  Serial.print("Enter steps : ");
  }
  if(steps>5){
    delay(500);
    }
 }

}
