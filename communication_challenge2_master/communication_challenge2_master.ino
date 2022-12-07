#include <Wire.h>
#define slave 0x04


void setup() {
  Serial.begin(9600);
Wire.begin();

}

void loop() {
  if(Serial.available()>0){
    char ch = Serial.read();  

Wire.beginTransmission(slave);
Wire.write(ch);
Wire.endTransmission();
 Serial.println(ch);

  }

}
