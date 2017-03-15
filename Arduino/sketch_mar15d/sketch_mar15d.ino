#define LED 2
const byte knoppen[] = {9, 10, 11};
const byte leds[] = {2,3,4,5};
unsigned long time;
unsigned int statusVar;
int index;
void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < 3; i ++) {
    pinMode(knoppen[i], INPUT_PULLUP);
  }
  for (int i = 0; i < 4; i ++) {
    pinMode(leds[i], OUTPUT);
  }
  
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(leds[0], HIGH);
  delay(200);
  digitalWrite(leds[0], LOW);
  digitalWrite(leds[1], HIGH);
  delay(200);
  digitalWrite(leds[1], LOW);
  digitalWrite(leds[2], HIGH);
  delay(200);
  digitalWrite(leds[2], LOW);
  digitalWrite(leds[3], HIGH);
  delay(200);
  digitalWrite(leds[3], LOW);
}


