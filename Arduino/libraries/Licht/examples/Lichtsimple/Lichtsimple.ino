#include <Licht.h>

Licht licht(4);

void setup() {
  // put your setup code here, to run once:
  
}

void loop() {
  // put your main code here, to run repeatedly:
  licht.aan();
  delay(2000);
  licht.uit();
  delay(2000);
  licht.flits(120);
  delay(2000);
}
