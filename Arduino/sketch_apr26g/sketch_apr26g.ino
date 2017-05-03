#include <TM1636.h>
#define TEMPERATUUR_SENSOR A0

int temperatuur;
int meetwaarde;

int tiental;
int eenheid;

TM1636 tm(7,8);

int8_t disp[4];

void setup() {
  // put your setup code here, to run once:
  tm.init();
}

void loop() {
  // put your main code here, to run repeatedly:
  meetwaarde = analogRead ( TEMPERATUUR_SENSOR );
  temperatuur = meetwaarde/4 - 95;
  tiental = temperatuur / 10;
  eenheid = temperatuur % 10;
  
  disp[0] = tiental;
  disp[1] = eenheid;
  disp[2] = 18;
  disp[3] = 12;
  
  tm.display(disp);
  delay(500);

}
