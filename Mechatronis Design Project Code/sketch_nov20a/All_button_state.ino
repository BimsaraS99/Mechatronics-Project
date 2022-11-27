unsigned long previousMillis = 0;
boolean state = 0;

int Main_Button_State() {
  unsigned long currentMillis = millis();
  boolean button = digitalRead(Main_Push_Button);
  if (!button) {
    if ((currentMillis - previousMillis) > 200) {
      state = 1;
    }
  }
  else {
      previousMillis = currentMillis;
    state = 0;
  }
  return state;
}
