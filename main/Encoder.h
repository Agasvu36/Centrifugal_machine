
int A, B, C, Step;

unsigned long Enc_Time_Check = 0;

void Encoder_Init(int pinA, int pinB, int pinC) {

  A = pinA;
  B = pinB;
  C = pinC;
}

bool Checked = 0;
int Encoder_Check() {
  if (digitalRead(A) == 1 && digitalRead(C) == 1) {
    Checked = 0;
  }
  if (!Checked) {
    if (digitalRead(A) < digitalRead(C)) {
      Checked = 1;
      return 1;
    }
    if (digitalRead(A) > digitalRead(C)) {
      Checked = 1;
      return -1;
    }
  }
  return 0;
}

int Encoder_Button_Check() {
  if(millis() - Enc_Time_Check > 150)
  {
    Enc_Time_Check = millis();
    return digitalRead(B);
  }
  else{
    return -1;
  }  
}