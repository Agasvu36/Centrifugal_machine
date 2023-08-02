#include "UI.h"
#include "Encoder.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
    
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);

  pinMode(A0, OUTPUT);

  Encoder_Init(5, 7, 6);

  UI_Init();
  UI_Create();
}



int i = 0;
void loop() {
  digitalWrite(A0, 1);
  // put your main code here, to run repeatedly:
  i += Encoder_Check()*10;
  Serial.print(digitalRead(5));
  Serial.print(',');
  Serial.print(digitalRead(6));
  Serial.print(',');
 // Serial.print(i);
//  Serial.print(',');
  Serial.println(digitalRead(7));

  UI_Change_Velosity(i, 0);
  //UI_Change_Velosity(i, 1);
  //if (i >= 1000)
   // i = 0;
  //delay(25);
  //Serial.println(digitalRead(14));
  }
