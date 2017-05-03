#define LED 5
#define K1 9
#define K2 10
#define K3 11

int dimfactor = 250;

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
  pinMode(LED, OUTPUT); 
  Serial.begin(9600);
  pciSetup(K1);
  pciSetup(K2);
  pciSetup(K3);
}

void loop() {
  // put your main code here, to run repeatedly: 
  analogWrite(LED, dimfactor);
}

ISR (PCINT0_vect){ 
  if(digitalRead(K1)==LOW){
    dimfactor -= 25;
    if(dimfactor < 0) {
      dimfactor = 0;
    }
    Serial.println(dimfactor);
  } 
  if(digitalRead(K2)==LOW){ 
    dimfactor = 0;
    Serial.println(dimfactor);
  } 
  if(digitalRead(K3)==LOW){ 
    dimfactor += 25;
    if(dimfactor > 250) {
      dimfactor = 250;
    }
    Serial.println(dimfactor);
  } 
}

