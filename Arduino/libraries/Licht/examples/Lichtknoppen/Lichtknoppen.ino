#include <Licht.h>

Licht led(4);
Licht knop1(9);

void setup() {
  // put your setup code here, to run once:
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if(knop1.leesKnop()) {
    led.toggle();
  }  
}
