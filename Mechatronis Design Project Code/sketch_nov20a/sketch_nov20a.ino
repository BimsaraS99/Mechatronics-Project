#include <EEPROM.h>
#include "RTClib.h"
#define Buzzer 12
#define Main_Push_Button 8

RTC_DS1307 rtc;

int num_of_stored_data = 0; // number of data stored in data base array
int data_base[10][6] = {
  {255, 255, 255, 255, 255, 255},
  {255, 255, 255, 255, 255, 255},
  {255, 255, 255, 255, 255, 255},
  {255, 255, 255, 255, 255, 255},
  {255, 255, 255, 255, 255, 255},
  {255, 255, 255, 255, 255, 255},
  {255, 255, 255, 255, 255, 255},
  {255, 255, 255, 255, 255, 255},
  {255, 255, 255, 255, 255, 255},
  {255, 255, 255, 255, 255, 255},
};

void setup() {
  Serial.begin(9600);
  EEPROM_read();
#ifndef ESP8266
  while (!Serial); // wait for serial port to connect. Needed for native USB
#endif

  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    Serial.flush();
    while (1) delay(10);
  }

  if (! rtc.isrunning()) {
    Serial.println("RTC is NOT running, let's set the time!");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__))); // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }
  pinMode(Buzzer, OUTPUT);
  pinMode(Main_Push_Button, INPUT_PULLUP);
}

void loop() {
  User_Input();
  Time_and_Alarm();
}
