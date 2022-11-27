void Time_Telling(){
  Serial.print(now_time[0]);
  Serial.print(" : ");
  Serial.println(now_time[1]);
  delay(2000);
}

void Talk(){
  Serial.println("You have...");
  delay(2000);
}
