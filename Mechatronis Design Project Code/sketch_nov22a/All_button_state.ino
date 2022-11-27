unsigned long previousMillis = 0;
boolean state = 0;

int Main_Button_State() {
  unsigned long currentMillis = millis();
  boolean button = digitalRead(Main_Push_Button);
  if (!button) {
    if ((currentMillis - previousMillis) > 70) {
      state = 1;
    }
  }
  else {
    previousMillis = currentMillis;
    state = 0;
  }
  return state;
}

//return 0 for no click , return 1 for single click , return 2 for double click
byte click_count, clicK = 0; boolean check = 0;
unsigned long mil, mil2;

void Single_Double_Click_Events() {
  byte click_type = Click_Detect_Single_Double();
  if(click_type == 2){
    Time_Telling();
  }
  else if(click_type == 1){
    Talk();
  }
  else{
    //doing nothing
  }
  clicK = 0;
}

int Click_Detect_Single_Double() {

  boolean pushBT = Main_Button_State();
  if (pushBT == 1 && check == 0) {
    click_count++;
    check = 1;
  }
  if (pushBT == 0) {
    check = 0;
  }
  mil = millis();
  if (click_count > 0) {
    if (mil - mil2 >= 500) {
      clicK = click_count;
      click_count = 0;
    }
  }
  else{
    mil2 = mil;
  }
  return clicK;
}
