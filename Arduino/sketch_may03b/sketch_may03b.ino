#include <Time.h>
#include <Wire.h>
#include <DS1307RTC.h>
#include <TM1636.h>

TM1636 tm1636(7,8);
time_t currentTijd = 1493814822;
int8_t tijd[4];
bool toonPunt = true;
  
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  setTime(currentTijd);
  RTC.set(now());
  setSyncProvider(RTC.get);
  if(timeStatus()!= timeSet) 
     Serial.println("Unable to sync with the RTC");
  else
     Serial.println("RTC has set the system time");  
  tm1636.init();
}

void loop() {
  // put your main code here, to run repeatedly:
  tmElements_t tm;
  if(RTC.read(tm)) {
    tijd[0] = hour() / 10;
    tijd[1] = hour()% 10;
    tijd[2] = minute()/ 10;
    tijd[3] = minute()% 10;
  }
  tm1636.display(tijd);
  
  tm1636.point(toonPunt);
  
  if(toonPunt) {
    toonPunt = false;
  } else {
    toonPunt = true;
  }
  
  delay(500);
  
  tm1636.point(toonPunt);
  
}

