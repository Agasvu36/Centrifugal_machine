
int A, B, C, Step;

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

unsigned int time = 0;
int Encoder_Button_Check() {
  time = millis();
  if(digitalRead(B) == 0 && time > 100)
  {
    return 0;
  }
  else
  {
    return 1;
  }
}