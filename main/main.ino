
#include "UI.h"
#include "Encoder.h"
#include "Button.h"



int VelosityW, VelosityD = 50;

int *params[] = { &VelosityW, &VelosityD };

struct Time TimeW = { 2, 30, 00, false };
struct Time TimeD = { 2, 30, 00, false };
int buttonPin = 2;

void setup() {
  Serial.begin(9600);

  pinMode(5, INPUT);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(A0, OUTPUT);

  Encoder_Init(5, 7, 6);

  UI_Init();
  UI_Create();

  UI_Draw_Vector(3, 0);
  
  UI_Change_Velosity(VelosityW, 0);
  UI_Change_Velosity(VelosityW, 1);

  TimeIncrement(&TimeW);
  UI_Change_Time(&TimeW, 0);


  TimeIncrement(&TimeD);
  UI_Change_Time(&TimeD, 1);

  //TimeW.Enable = false;
  //TimeD.Enable = true;
}



int i = 0;
int step = 0;
int menu = 0;
bool started = 0;
unsigned long lastTimeMonitor = 0;

void loop() {
  digitalWrite(A0, 1);
  // put your main code here, to run repeatedly:

  //Serial.println();
  /* TimeCountdown(&TimeD);
  Serial.print("T: ");
  Serial.print(TimeD.Hour);
  Serial.print(":");
  Serial.print(TimeD.Minute);
  Serial.print(":");
  Serial.print(TimeD.Second);
  Serial.println();*/

  step = Encoder_Check();

  if (!Encoder_Button_Check()) {
    ++menu;

    if (menu > 1)
      menu = 0;
  }

  if (menu == 0) {
    if (step != 0) {
      i += step;
      if (i > 3)
        i = 0;
      if (i < 0)
        i = 3;

      if (i == 0)
        UI_Draw_Vector(3, 0);
      if (i == 1)
        UI_Draw_Vector(3, 1);
      if (i == 2)
        UI_Draw_Vector(10, 0);
      if (i == 3)
        UI_Draw_Vector(10, 1);
      Serial.println(i);
    }
  }

  if (menu == 1) {
    if (step != 0) {
      if (i < 2) {
        *params[i] += step * 10;
        if (*params[i] < 0)
          *params[i] = 1000;
        if (*params[i] > 1000)
          *params[i] = 0;
        UI_Change_Velosity(*params[i], i);
      }
      if (i == 2) {
        if (step > 0) {
          TimeIncrement(&TimeW);
          UI_Change_Time(&TimeW, 0);
        }
        if (step < 0) {
          TimeDecrement(&TimeW);
          UI_Change_Time(&TimeW, 0);
        }
      }

      if (i == 3) {
        if (step > 0) {
          TimeIncrement(&TimeD);
          UI_Change_Time(&TimeD, 1);
        }
        if (step < 0) {
          TimeDecrement(&TimeD);
          UI_Change_Time(&TimeD, 1);
        }
      }
    }
  }

  if (!Button_Check(buttonPin)) {
    started = 1;
    TimeW.Enable = true;
  }

  if (started) {
    TimeCountdown(&TimeW);
    if (millis() - lastTimeMonitor > 1000) {
      Serial.print("T: ");
      Serial.print(TimeW.Hour);
      Serial.print(":");
      Serial.print(TimeW.Minute);
      Serial.print(":");
      Serial.print(TimeW.Second);
      Serial.println();
      lastTimeMonitor = millis();
      UI_Change_Time(&TimeW, 0);
    }
  }
}
