#include <TM1636.h>
TM1636 tm(7,8);

int8_t disp[4];

void setup() {
  // put your setup code here, to run once:
  tm.init();
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 0; i < 4; i++) {
    disp[i] = i+1;
  }
  tm.point(true);
  tm.display(disp);
  delay(500);
  tm.point(false);
  tm.display(disp);
  delay(500);
}
