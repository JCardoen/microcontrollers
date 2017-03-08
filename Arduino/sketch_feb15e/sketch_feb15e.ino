const byte ledArray[] = {2, 3, 4, 5};
byte a = 0;
byte arrayBits[] = {};
boolean notFifteen = true;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for (byte led : ledArray) {
    pinMode(led, OUTPUT);
  }
}

void loop() {
  for (int i = 0; i < 4; i ++) {
    arrayBits[i] = 0;
  }
  
  int n = a;
  arrayBits[0] = a % 2;
  a = a / 2;
  arrayBits[1] = a % 2;
  a = a / 2;
  arrayBits[2] = a % 2;
  a = a / 2;
  arrayBits[3] = a % 2;
  a = a / 2;

  for (int k = 0; k < 4; k ++) {
    if (arrayBits[k] == 1) {
      digitalWrite(ledArray[k], HIGH);
    }
    else {
      digitalWrite(ledArray[k], LOW);
    }
    Serial.print(arrayBits[k]);
  }
  Serial.println();
  a = n;
  a++;
  delay(500);
}
