#include <Wire.h>
#define slave 0x04

void setup(){
  Wire.begin();
  Serial.begin(9600);
  }

  void loop(){
    Wire.requestFrom(slave, 1);
    delay(300);
      char c = Wire.read();
       Serial.println(String(c,DEC));
   
    }
