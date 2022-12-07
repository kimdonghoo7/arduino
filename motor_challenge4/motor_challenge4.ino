int IN1 = 22;
int IN2 = 24;
int IN3 = 26;
int IN4 = 28;
int Steps = 0;
int steps_left = 8190;

boolean Direction = true;

unsigned long last_time;

unsigned long currentMills ;

long time;

void setup() {
  Serial.begin(9600);
  pinMode(IN1, OUTPUT); //blue
  pinMode(IN2, OUTPUT); //pink
  pinMode(IN3, OUTPUT); //yellow
  pinMode(IN4, OUTPUT); //orange
}

void loop() {
  while (steps_left > 0)
  {
    currentMills = micros();
    if (currentMills - last_time >= 1000)
    {
      stepper(1);
      time = time + micros() - last_time;
      last_time = micros();
      steps_left--;
    }
  }
  Serial.println(Steps);
  Serial.println("Wait...!");
  delay(3000);

  Direction = !Direction;
  steps_left = 8190;
}
void stepper(int xw)
{
  for  (int x = 0; x < xw; x++)
  {
    switch (Steps)
    {
      case 0: runStep(LOW, LOW, LOW, HIGH); break;
      case 1: runStep(LOW, LOW, HIGH, HIGH); break;
      case 2: runStep(LOW, LOW, HIGH, LOW); break;
      case 3: runStep(LOW, HIGH, HIGH, LOW); break;
      case 4: runStep(LOW, HIGH, LOW, LOW); break;
      case 5: runStep(HIGH, HIGH, LOW, LOW); break;
      case 6: runStep(HIGH, LOW, LOW, LOW); break;
      case 7: runStep(HIGH, LOW, LOW, HIGH); break;
      default: runStep(LOW, LOW, LOW, LOW); break;
    }
    SetDirection();
  }
}

void runStep(int value1, int value2,  int value3, int value4)
{
  digitalWrite(IN1,value1);
  digitalWrite(IN2,value2);
  digitalWrite(IN3,value3);
  digitalWrite(IN4,value4);
  }
  void SetDirection()
  {
    if(Direction==1){Steps++; }
    if(Direction==0){Steps--; }
    if(Steps>7){Steps=0; }
    if(Steps<0){Steps=7; }
    }
