#include <TimerOne.h>

long int teller1 = 0;
long int teller2 = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Timer1.initialize(1000);
  Timer1.attachInterrupt(timerIsr);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1);
  teller1++;
  if(teller1%1000 == 0) {
    Serial.print("Met delay :");
    Serial.println(teller1);
  }
  
}

void timerIsr() {
  teller2++;
  if(teller2%1000 == 0) {
    Serial.print("Met timer :");
    Serial.println(teller2);
  }
}

