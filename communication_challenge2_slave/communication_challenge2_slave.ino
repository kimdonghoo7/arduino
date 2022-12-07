#include <Wire.h>
#define slave 0x04
int led = 13;
int motor = 12;
int buzzer = 11;


byte rec[128];

void setup() {
Wire.begin(slave);
pinMode(led,OUTPUT);
pinMode(buzzer,OUTPUT);
pinMode(motor,OUTPUT);
}

void loop() {
Wire.onReceive(record);
if(rec[0] == 'a'){
  digitalWrite(led,HIGH);
 
}
else if(rec[0]== 'b'){
  digitalWrite(led,LOW);
  }
  else if(rec[0]== 'c'){
  digitalWrite(motor,HIGH);
  }
  else if(rec[0]== 'd'){
  digitalWrite(motor,LOW);
  }
  else if(rec[0]== 'e'){
  digitalWrite(buzzer,HIGH);
  }
  else if(rec[0]== 'f'){
  digitalWrite(buzzer,LOW);
  }
}
void record(int receiveNum){
  for(int i=0; i< receiveNum; i++){
    rec[i]=Wire.read();
    }
  }
   
 
