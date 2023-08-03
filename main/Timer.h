struct Time {
  int Hour;
  int Minute;
  int Second;
  bool Enable;
};



unsigned long timer_millis = 0;

void TimeCountdown(struct Time *t) {

  if ((*t).Enable) {
    if (millis() - timer_millis >= 1000) {
      timer_millis = millis();
      (*t).Second--;


      if ((*t).Second < 0) {
        (*t).Second = 59;
        (*t).Minute--;
      }

      if ((*t).Minute < 0) {
        (*t).Hour--;
      }

      if ((*t).Hour <= 0 && (*t).Minute <= 0) {
        (*t).Enable = false;
      }
    }
  }
}

void TimeIncrement(struct Time *t) {

  (*t).Minute++;

  if ((*t).Minute >= 60) {
    (*t).Hour++;
    (*t).Minute = 0;
  }
}

void TimeDecrement(struct Time *t) {
  (*t).Minute--;
  if ((*t).Minute < 0) {
    (*t).Minute = 59;
    (*t).Hour--;
  }
  if ((*t).Hour <= 0) {
    (*t).Hour = 0;
  }
}