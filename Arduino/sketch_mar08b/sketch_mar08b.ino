#define knop 9
#define LED1 2

int toestand = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(knop, INPUT_PULLUP);
  pinMode(LED1, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(knop) == LOW) {
    switch(toestand) {
      case 0: digitalWrite(LED1, HIGH);toestand=1;break;
      case 1: digitalWrite(LED1, LOW);toestand=0;break;
    }
    while(digitalRead(knop) == LOW) {
      delay(50);
    }
  }

}
