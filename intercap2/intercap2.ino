int led = 22;
  volatile int state = LOW;

void setup() {
  pinMode(led,OUTPUT);
  pinMode(2, INPUT);
  attachInterrupt(0,blink,RISING);
}

void loop() {
  digitalWrite(led,state);
}

void blink(){
  state=!state;
}
