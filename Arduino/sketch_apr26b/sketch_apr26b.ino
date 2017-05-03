#include <TM1636.h>
#define K1 9
#define K2 10
#define K3 11

TM1636 tm(7, 8);

int8_t jaar[4] = {1,9,9,6};
int8_t maand[4] = {0,0,0,6};
int8_t dag[4] = {0,0,1,1};
int8_t disp[4];

bool toonJaar = false;
bool toonMaand = false;
bool toonDag = false;

void pciSetup(byte pin) {
  *digitalPinToPCMSK(pin) |= bit (digitalPinToPCMSKbit(pin)) ; // enable pin
  PCIFR |= bit (digitalPinToPCICRbit(pin));
  // clear any outstanding interrupt
  PCICR |= bit (digitalPinToPCICRbit(pin));
  // enable interrupt for the group
}

void setup() {
  // put your setup code here, to run once:
  pinMode(K1, INPUT_PULLUP);
  pinMode(K2, INPUT_PULLUP);
  pinMode(K3, INPUT_PULLUP);
  tm.init();
  pciSetup(K1);
  pciSetup(K2);
  pciSetup(K3);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < 4; i++) {
    if(toonJaar) {
      disp[i] = jaar[i];
    }
    if(toonMaand) {
      disp[i] = maand[i];
    }
    if(toonDag) {
      disp[i] = dag[i];
    } 
  }
  tm.point(true);
  tm.display(disp);
  delay(500);
  tm.point(false);
  tm.display(disp);
  delay(500);
}

ISR (PCINT0_vect){ 
  if(digitalRead(K1)==LOW){ 
    toonJaar = true;
    toonMaand = false;
    toonDag = false;
  } 
  if(digitalRead(K2)==LOW){ 
   toonJaar = false;
    toonMaand = true;
    toonDag = false;
  } 
  if(digitalRead(K3)==LOW){ 
    toonJaar = false;
    toonMaand = false;
    toonDag = true; 
  } 
}
