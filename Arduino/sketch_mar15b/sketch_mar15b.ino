#define LED 2
const byte knoppen[] = {9, 10, 11};
unsigned int drukken = 0;
unsigned int statusVar;
void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < 3; i ++) {
    pinMode(knoppen[i], INPUT_PULLUP);
  }
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(LED) == LOW) {
    if (digitalRead(knoppen[0]) == LOW) {
      statusVar = 1;

      if (statusVar == 1) {
        Serial.print("K1 ingedrukt");
        drukken++;
      }
      delay(50);
      statusVar = 0;
    }

    if (digitalRead(knoppen[1]) == LOW && digitalRead(knoppen[0]) == HIGH) {
      statusVar = 1;
      if (statusVar == 1) {
        Serial.print("K2 ingedrukt");
        Serial.write(drukken + "\n");
      }
      delay(50);
      statusVar = 0;
    }

    if (digitalRead(knoppen[2]) == LOW) {
      drukken = 0;
      statusVar = 0;
    }
  }

  digitalWrite(LED, HIGH);
  delay(500);
  digitalWrite(LED, LOW);
  delay(500);
}
