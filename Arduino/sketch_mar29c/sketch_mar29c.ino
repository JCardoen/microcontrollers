#define LED1 2
#define K1 9
#define K2 10
#define K3 11
float dim = 1;
int magBranden = 1;

void pciSetup(byte pin) {
  *digitalPinToPCMSK ( pin ) |= bit (digitalPinToPCMSKbit ( pin ) ) ; // enable pin
  PCIFR |= bit ( digitalPinToPCICRbit ( pin ) ) ;
  // clear any outstanding interrupt
  PCICR |= bit ( digitalPinToPCICRbit ( pin ) ) ;
  // enable interrupt for the group
}

ISR (PCINT0_vect) {
  delay(50);
  if(digitalRead(K1) == LOW) {
    dim += 0.25;
    if(dim >= 1) {
      digitalWrite(LED1, LOW);
      dim=1;
      magBranden = 0;
      Serial.println(dim);
    }
  }
  
  if(digitalRead(K2) == LOW) {
    if(magBranden == 0) {
      magBranden = 1;
    }
    else {
      magBranden = 0;
      digitalWrite(LED1, LOW);
    }
  }
  
  if(digitalRead(K3) == LOW) {
    magBranden = 1;
    dim -= 0.25;
    if(dim < 0) {
      dim = 0;
      
    }
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(K1, INPUT_PULLUP);
  pinMode(K2, INPUT_PULLUP);
  pinMode(K3, INPUT_PULLUP);
  pciSetup(K1);
  pciSetup(K2);
  pciSetup(K3);
  pinMode(LED1, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(magBranden == 1) {
    digitalWrite(LED1, HIGH);
    delay(15*dim);
    digitalWrite(LED1, LOW);
    delay(15*dim);
  }
}
