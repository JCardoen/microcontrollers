#include <Licht.h>

Licht licht(4);

void setup() {
  // put your setup code here, to run once:
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if(licht.leesKnop(9)) {
    licht.aan();
  }

  if(licht.leesKnop(10)) {
    licht.uit();
  }

  if(licht.leesKnop(11)) {
    licht.flits(50);
  }
  
}
