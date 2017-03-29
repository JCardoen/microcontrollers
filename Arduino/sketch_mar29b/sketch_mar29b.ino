#define K1 9
#define K2 10
#define K3 11
int leds[] = {2,3,4,5};
int index = 0;
int richting = 1;
bool start = 1;
void pciSetup(byte pin) {
  *digitalPinToPCMSK ( pin ) |= bit (digitalPinToPCMSKbit ( pin ) ) ; // enable pin
  PCIFR |= bit ( digitalPinToPCICRbit ( pin ) ) ;
  // clear any outstanding interrupt
  PCICR |= bit ( digitalPinToPCICRbit ( pin ) ) ;
  // enable interrupt for the group
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(K1, INPUT_PULLUP);
  pinMode(K2, INPUT_PULLUP);
  pinMode(K3, INPUT_PULLUP);
  for(int i = 0; i < 4; i ++) {
    pinMode(leds[i], OUTPUT);
  }
  pciSetup(K1);
  pciSetup(K2);
  pciSetup(K3);
}

ISR (PCINT0_vect) {
  if(digitalRead(K1) == LOW) {
    gaRechts();
  }
  if(digitalRead(K2) == LOW) {
    stopLoop();
  }
  if(digitalRead(K3) == LOW) {
    gaLinks();
  }
}

void gaRechts() {
  richting=-1;
}

void gaLinks() {
  richting=+1;
}

void stopLoop() {
  start = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
  while(start) {
    if(index < 0) {
      index = 3;
    }

    if(index == 4) {
      index = 0;
    }
    digitalWrite(leds[index], HIGH);
    delay(500);
    digitalWrite(leds[index], LOW);
    index +=richting;
  }
}
