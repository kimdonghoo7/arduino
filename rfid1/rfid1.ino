#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN   49     // reset핀 설정
#define SS_PIN    53    // 데이터를 주고받는 역할의 핀( SS = Slave Selector )

MFRC522 mfrc(SS_PIN, RST_PIN);           // 이 코드에서 MFR522를 이용하기 위해 mfrc객체를 생성해 줍니다.

#define A 22
#define B 23
#define C 24
#define D 25
#define E 26
#define F 28
#define G 27

void number1(){
  digitalWrite(A,LOW);
  digitalWrite(B,HIGH);
  digitalWrite(C,HIGH);
  digitalWrite(D,LOW);
  digitalWrite(E,LOW);
  digitalWrite(F,LOW);
  digitalWrite(G,LOW);
}

void number2(){
  digitalWrite(A,HIGH);
  digitalWrite(B,HIGH);
  digitalWrite(C,LOW);
  digitalWrite(D,HIGH);
  digitalWrite(E,HIGH);
  digitalWrite(F,LOW);
  digitalWrite(G,HIGH);
}

void number3(){
  digitalWrite(A,HIGH);
  digitalWrite(B,HIGH);
  digitalWrite(C,HIGH);
  digitalWrite(D,HIGH);
  digitalWrite(E,LOW);
  digitalWrite(F,LOW);
  digitalWrite(G,HIGH);
}

void number4(){
  digitalWrite(A,LOW);
  digitalWrite(B,HIGH);
  digitalWrite(C,HIGH);
  digitalWrite(D,LOW);
  digitalWrite(E,LOW);
  digitalWrite(F,HIGH);
  digitalWrite(G,HIGH);
}

void setup() {
  Serial.begin(9600);                     // 시리얼 통신, 속도는 9600
  SPI.begin();                             // SPI 초기화(SPI : 하나의 마스터와 다수의 SLAVE(종속적인 역활)간의 통신 방식)

  pinMode(A,OUTPUT);
    pinMode(B,OUTPUT);
      pinMode(C,OUTPUT);
        pinMode(D,OUTPUT);
          pinMode(E,OUTPUT);
            pinMode(F,OUTPUT);
              pinMode(G,OUTPUT);
             
  mfrc.PCD_Init();  
  }


void loop() {
  if ( ! mfrc.PICC_IsNewCardPresent() || ! mfrc.PICC_ReadCardSerial() ) {    //  태그 접촉이 되지 않았을때 또는 아이디가 읽혀지지 않았을때
    delay(500);        
    return;                                   // return
  }
   
  if(mfrc.uid.uidByte[0] == 220 && mfrc.uid.uidByte[1] == 219
       && mfrc.uid.uidByte[2] == 187 && mfrc.uid.uidByte[3] == 22) {    
  number1();
  Serial.print("1");
    delay(1000);
  }    
     
  // 3번핀 에 연결된 led 켜지기
                // 4번핀 에 연결된 led 꺼지기
                 
   
  if(mfrc.uid.uidByte[0] == 209 && mfrc.uid.uidByte[1] == 193
       && mfrc.uid.uidByte[2] == 133 && mfrc.uid.uidByte[3] == 2) {    
  number2();
  Serial.print("2");
    delay(1000);
       }

    if(mfrc.uid.uidByte[0] == 241 && mfrc.uid.uidByte[1] == 7
       && mfrc.uid.uidByte[2] == 140 && mfrc.uid.uidByte[3] == 27) {    
  number3();
  Serial.print("3");
    delay(1000);
  }            

  if(mfrc.uid.uidByte[0] == 67 && mfrc.uid.uidByte[1] == 97
       && mfrc.uid.uidByte[2] == 10 && mfrc.uid.uidByte[3] == 3) {    
  number4();
  Serial.print("4");
    delay(1000);
  }            
   
  }  
