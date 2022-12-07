#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>
#include<Wire.h>
#include <LiquidCrystal_I2C.h>     //LiquidCrystal 라이브러리 추가 
LiquidCrystal_I2C lcd(0x3F, 16, 2);  //lcd 객체 선언

Servo servo1;
Servo servo2;
int value1=0;
int value2=0;


#define RST_PIN   49     // reset핀 설정
#define SS_PIN    53    // 데이터를 주고받는 역할의 핀( SS = Slave Selector )

int IN1Pin=3;
int IN2Pin=4;
int ENpin=5;

MFRC522 mfrc(SS_PIN, RST_PIN);           // 이 코드에서 MFR522를 이용하기 위해 mfrc객체를 생성해 줍니다.





void setup() {
  Serial.begin(9600);                     // 시리얼 통신, 속도는 9600
  SPI.begin();                             // SPI 초기화(SPI : 하나의 마스터와 다수의 SLAVE(종속적인 역활)간의 통신 방식)

   lcd.init(); 
  lcd.backlight();
  
 servo1.attach(22);
 servo2.attach(23);

 pinMode(IN1Pin,OUTPUT);
 pinMode(IN2Pin,OUTPUT);
 analogWrite(ENpin,255);
           
  mfrc.PCD_Init();  
  }


void loop() {

  digitalWrite(IN1Pin,HIGH);
  digitalWrite(IN2Pin,LOW);
  
  
  if ( ! mfrc.PICC_IsNewCardPresent() || ! mfrc.PICC_ReadCardSerial() ) {    //  태그 접촉이 되지 않았을때 또는 아이디가 읽혀지지 않았을때
    delay(500);        
    return;                                   // return
  }
   
  if(mfrc.uid.uidByte[0] == 220 && mfrc.uid.uidByte[1] == 219
       && mfrc.uid.uidByte[2] == 187 && mfrc.uid.uidByte[3] == 22) {    // 1번 태그 ID가 맞을경우
  
    servo1.write(40);
    servo2.write(40);
    delay(15);

     lcd.setCursor(3, 0);    
  lcd.print("LEFT  SIDE"); 
   lcd.setCursor(4, 1);   
  lcd.print("1ST ITEM");
  delay(3000);            
  lcd.clear();
    
   Serial.print("1");
    delay(1000);
  }    
     

  if(mfrc.uid.uidByte[0] == 209 && mfrc.uid.uidByte[1] == 193
       && mfrc.uid.uidByte[2] == 133 && mfrc.uid.uidByte[3] == 2) {    
        
        servo1.write(90);
    servo2.write(90);
    delay(15);

    lcd.setCursor(4, 0);   
  lcd.print("STRAIGHT"); 
   lcd.setCursor(4, 1);    
  lcd.print("2ND ITEM");
  delay(3000);   
  lcd.clear();// 1초 대기
 
  Serial.print("2");
    delay(1000);
       }

    if(mfrc.uid.uidByte[0] == 241 && mfrc.uid.uidByte[1] == 7
       && mfrc.uid.uidByte[2] == 140 && mfrc.uid.uidByte[3] == 27) {    

         servo1.write(137);
    servo2.write(137);
    delay(15);

    lcd.setCursor(3, 0);    
  lcd.print("RIGHT SIDE"); 
   lcd.setCursor(4, 1);    
  lcd.print("3RD ITEM");
  delay(3000);  
  lcd.clear();// 1초 대기
 
 
  Serial.print("3");
    delay(1000);
  }            

 
       
  }  






 
