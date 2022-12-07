
#include <FrequencyTimer2.h>

#define M {\
{0,1,1,0,0,1,1,0},\
{1,0,0,1,1,0,0,1},\
{1,0,0,1,1,0,0,1},\
{1,0,0,1,1,0,0,1},\
{1,0,0,1,1,0,0,1},\
{1,0,0,1,1,0,0,1},\
{1,0,0,1,1,0,0,1},\
{1,0,0,1,1,0,0,1},\
}
#define E {\
{0,1,1,1,1,1,1,1},\
{0,1,1,1,1,1,1,1},\
{0,0,0,0,0,0,0,1},\
{0,1,1,1,1,1,1,1},\
{0,1,1,1,1,1,1,1},\
{0,0,0,0,0,0,0,1},\
{0,1,1,1,1,1,1,1},\
{0,1,1,1,1,1,1,1},\
}
#define C {\
{0,0,1,1,1,1,0,0},\
{0,1,0,0,0,1,1,0},\
{0,0,0,0,0,0,1,1},\
{0,0,0,0,0,0,0,1},\
{0,0,0,0,0,0,0,1},\
{0,0,0,0,0,0,1,1},\
{0,1,0,0,0,1,1,0},\
{0,0,1,1,1,1,0,0},\
}
#define H {\
{0,1,0,0,0,0,1,0},\
{0,1,0,0,0,0,1,0},\
{0,1,0,0,0,0,1,0},\
{0,1,1,1,1,1,1,0},\
{0,1,1,1,1,1,1,0},\
{0,1,0,0,0,0,1,0},\
{0,1,0,0,0,0,1,0},\
{0,1,0,0,0,0,1,0},\
}
#define A{\
{0,0,0,1,1,0,0,0},\
{0,0,1,1,1,1,0,0},\
{0,1,1,0,0,1,1,0},\
{0,1,0,0,0,0,1,0},\
{0,1,1,1,1,1,1,0},\
{0,1,0,0,0,0,1,0},\
{0,1,0,0,0,0,1,0},\
{0,1,0,0,0,0,1,0},\
}
#define T{\
{1,1,1,1,1,1,1,1},\
{1,1,1,1,1,1,1,1},\
{0,0,0,1,1,0,0,0},\
{0,0,0,1,1,0,0,0},\
{0,0,0,1,1,0,0,0},\
{0,0,0,1,1,0,0,0},\
{0,0,0,1,1,0,0,0},\
{0,0,0,1,1,0,0,0},\
}
#define R{\
{0,0,0,1,1,1,1,0},\
{0,0,1,0,0,0,1,0},\
{0,0,1,0,0,0,1,0},\
{0,0,0,1,1,1,1,0},\
{0,0,0,0,0,1,1,0},\
{0,0,0,0,1,0,1,0},\
{0,0,0,1,0,0,1,0},\
{0,0,1,0,0,0,1,0},\
}
#define O{\
{0,0,1,1,1,1,0,0},\
{0,1,0,0,0,0,1,0},\
{1,0,0,0,0,0,0,1},\
{1,0,0,0,0,0,0,1},\
{1,0,0,0,0,0,0,1},\
{1,0,0,0,0,0,0,1},\
{0,1,0,0,0,0,1,0},\
{0,0,1,1,1,1,0,0},\
}
#define N {\
{0,1,0,0,0,0,1,0},\
{0,1,0,0,0,1,1,0},\
{0,1,0,0,1,0,1,0},\
{0,1,0,0,1,0,1,0},\
{0,1,0,1,0,0,1,0},\
{0,1,0,1,0,0,1,0},\
{0,1,1,0,0,0,1,0},\
{0,1,0,0,0,0,1,0},\
}
#define I {\
{0,0,1,1,1,1,0,0},\
{0,0,0,1,1,0,0,0},\
{0,0,0,1,1,0,0,0},\
{0,0,0,1,1,0,0,0},\
{0,0,0,1,1,0,0,0},\
{0,0,0,1,1,0,0,0},\
{0,0,0,1,1,0,0,0},\
{0,0,1,1,1,1,0,0},\
}
#define S{\
{0,0,1,1,1,1,1,0},\
{0,1,0,0,0,0,0,1},\
{0,0,0,0,0,0,0,1},\
{0,0,1,1,1,1,1,0},\
{0,1,0,0,0,0,0,0},\
{0,1,0,0,0,0,0,1},\
{0,0,1,1,1,1,1,0},\
{0,0,0,0,0,0,0,0},\
}

int sw = 2;
byte coli = 0;
byte LED[8][8];



int pin[17]={-1,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37};

int col[8]={pin[9],pin[10],pin[11],pin[12],pin[13],pin[14],pin[15],pin[16]};

int row[8]={pin[1],pin[2],pin[3],pin[4],pin[5],pin[6],pin[7],pin[8]};

int pattern = 0;

const int Patterns_no = 12;
byte patterns[Patterns_no][8][8] = {M, E, C, H, A, T, R, O, N, I, C, S };


void setup() {
 
  for(int i=1; i<=16; i++)
  pinMode(pin[i], OUTPUT);

  for (int i = 0; i < 8; i++){
    digitalWrite(row[i], LOW);
    }

    for (int i = 0; i < 8; i++){
    digitalWrite(col[i], HIGH);
    }

    LED_init();
    FrequencyTimer2::setOnOverflow(display);

    pinMode (sw, INPUT);

    Pattern_output(pattern);

    Serial.begin(9600);
}

void loop() {
  int sw_status = digitalRead(sw);

  if (sw_status == HIGH){
    Serial.println("ON");
    if(pattern == 11) pattern = 0;
    else pattern++;
    delay(300);
    }
    Pattern_output(pattern);
}
void LED_init(){
  for (int i = 0; i < 8; i++)
   for (int j = 0; j < 8; j++)
   LED[i][j] = 0;
}

void Pattern_output(int pattern){
  for (int i = 0; i< 8; i++)
   for (int j = 0; j< 8; j++)
    LED[i][j] = patterns[pattern][i][j];
  }

  void display(){
    digitalWrite(col[coli], LOW);
    coli++;
    if (coli == 8){
      coli = 0;
      }
      for (int row1 = 0; row1 <= 7; row1++){
        if(LED[coli][7-row1] == 1){
          digitalWrite(row[row1],LOW);
          }
          else {digitalWrite(row[row1],HIGH);
          }
      }
      digitalWrite(col[coli], HIGH);
         
       
    }
