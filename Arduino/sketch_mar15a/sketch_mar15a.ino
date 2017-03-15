#define LED 2
const byte knoppen[] = {9, 10, 11};
unsigned long time;
bool beide = false;
int statusVar;
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

  // Druk op K1
  if (digitalRead(knoppen[0]) == LOW) {

    // Tijd onthouden bij druk op knop
    time = millis();

    // Status is hoog, 1
    statusVar = 1;
    
    delay(50);
  }

  // Als status hoog is (indrukken/enkele druk)
  if (statusVar == 1) {
    // Bij druk op K3 gaat LED UIT
    if (digitalRead(knoppen[2]) == LOW || beide) {

      // Verschil in tijd tussen druk knop en nieuwe druk, huidige millis()
      if (millis() - time <= 1000) {
        digitalWrite(LED, LOW);

        //DEBUG
        Serial.print("KNOP3\n");
      }

      delay(50);
      statusVar = 0;
    }

    if (digitalRead(knoppen[1]) == LOW && digitalRead(knoppen[2]) == LOW) {
      beide = true;
    }

    // Bij druk op K2 gaat LED AAN
    if (digitalRead(knoppen[1]) == LOW && !beide ) {

      // Verschil in tijd tussen druk knop en nieuwe druk, huidige millis()
      if (millis() - time <= 1000) {
        digitalWrite(LED, HIGH);

        //DEBUG
        Serial.print("KNOP2\n");
      }

      delay(50);
      statusVar = 0;
    }
  }
}
