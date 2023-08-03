unsigned Button_Time_Check = 0;

int Button_Check(int Pin) {
  if(millis() - Button_Time_Check > 150)
  {
    Button_Time_Check = millis();
    return digitalRead(Pin);
  }
  else{
    return -1;
  }  
}