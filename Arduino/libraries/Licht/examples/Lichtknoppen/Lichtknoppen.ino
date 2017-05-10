#include <Licht.h>

Licht led(4);
Licht knop1(9);
Licht knop2(10);
Licht knop3(11);

void setup() {
  // put your setup code here, to run once:
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if(knop1.leesKnop()) {
    led.toggle();
  }  
}
