#define LED1 2
#define K1 9
#define K2 10
#define K3 11
int teller = 0;
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
  pinMode(LED1, OUTPUT);
  pciSetup(K1);
  pciSetup(K2);
  pciSetup(K3);
}

ISR (PCINT0_vect) {
  delay(50);
  if(digitalRead(K1) == LOW) {
     teller++;
  }
  if(digitalRead(K2) == LOW) {
    Serial.println(teller);
  }
  if(digitalRead(K3) == LOW) {
    teller = 0;
  }
}



void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED1, HIGH);
  delay(100);
  digitalWrite(LED1, LOW);
  delay(100);
}
