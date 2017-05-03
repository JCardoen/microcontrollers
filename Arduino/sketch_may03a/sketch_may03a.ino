#include <TimeLib.h>

time_t tijd = 1493812045;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  printTijd();
  delay(1000);
}

void printTijd() {
  tijd+=1;
  setTime(tijd);
  Serial.print(hour());
  printDigits(minute());
  printDigits(second());
  Serial.print(" ");
  Serial.print(dayStr(weekday()));
  Serial.print(" ");
  Serial.print(day());
  Serial.print(" ");
  Serial.print(monthStr(month()));
  Serial.print(" ");
  Serial.print(year());
  Serial.println();
}

void printDigits ( int digits ) {
  Serial.print (":");
  if (digits < 10)
    Serial.print ("0") ;
    Serial.print(digits);
}
