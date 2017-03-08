int checkBounds;
void setup() {
  // put your setup code here, to run once:
  DDRD = B11111111;
  DDRB = B11110001;

  // INPUT_PULLUP activeren bij alle knoppen
  PORTB = B00001110;

  // LED1 op high
  PORTD = B00000100;
}

void loop() {
  // put your main code here, to run repeatedly:
  checkBounds = PORTD;
  
  if((PINB & (1<<PB1)) == 0) {
    
    if(checkBounds == 4) {
      PORTD = B00100000;
    } else {
      PORTD = PIND >> 1;
    }
    
    delay(200);
    
  }

  if((PINB & (1<<PB3)) == 0) {
    if(checkBounds == 32) {
      PORTD = B00000100;
    } else {
       PORTD = PIND << 1;
    }
    
    delay(200);
    
  }
}
