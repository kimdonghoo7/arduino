int IN1 = 22;
int IN2 = 24;
int IN3 = 26;
int IN4 = 28;
int k = 0;

void setup() {
  pinMode(IN1, OUTPUT); //blue
  pinMode(IN2, OUTPUT); //pink
  pinMode(IN3, OUTPUT); //yellow
  pinMode(IN4, OUTPUT); //orange
  Serial.begin(9600);
}

void loop() {
if(k<5){
  k++;
  Serial.println(k);
  for (int i = 0; i < 64; i++) {
    for (int j = 0; j < 8; j++) {
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      delay(1);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, HIGH);
      delay(1);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      delay(1);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      delay(1);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      delay(1);
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      delay(1);
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      delay(1);
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4,HIGH);
      delay(1);
    }
    }
}
    if(k==5){
      delay(3000);
    }
  }
