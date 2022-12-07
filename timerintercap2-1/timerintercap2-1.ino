
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


}

void loop() {
  switch_state=digitalRead(2);
 
   digitalWrite(led,HIGH);
   digitalWrite(led2,LOW);
   delay(2000);
    digitalWrite(led,LOW);
   digitalWrite(led2,HIGH);
   delay(2000);

   if(switch_state==HIGH){
    digitalWrite(buz,HIGH);
   }
   else{
    digitalWrite(buz,LOW);
   }
}



  
