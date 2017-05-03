#include <TimerOne.h>
#include <TM1636.h>

TM1636 tm(7,8);
int minuut = 0;
int seconde = 0;
int8_t disp[4];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Timer1.initialize(200000);
  Timer1.attachInterrupt(timerIsr);
  tm.init();
}

void loop() {
  // put your main code here, to run repeatedly:
}

void timerIsr() {
  seconde++;
  if(seconde < 10) {
    
  }
  if(seconde == 59) {
    seconde = 0;
    minuut++;
  }
  disp[0] = minuut / 10;
  disp[1] = minuut % 10;
  disp[2] = seconde / 10;
  disp[3] = seconde % 10;
  tm.display(disp);
}

