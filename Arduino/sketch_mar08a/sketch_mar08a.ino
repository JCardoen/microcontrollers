const byte ledArray[] = {2,3,4,5};
const byte knoppen[] = {9,10,11};
byte index = 0;
void setup() {
  // put your setup code here, to run once:
  for(int i = 0; i < 3; i ++){
    pinMode(knoppen[i], INPUT_PULLUP);
  }

  for(int i = 0; i < 5; i ++){
    pinMode(ledArray[i], OUTPUT);
  }
  
  digitalWrite(ledArray[0], HIGH);

}

void loop() {
  // put your main code here, to run repeatedly:

  if(digitalRead(knoppen[2]) == LOW) {
    digitalWrite(ledArray[index], LOW);
    index++;
    delay(200);
    
    if(index > 3) {
      index = 0;
    }

    digitalWrite(ledArray[index], HIGH);
    delay(200);
  }

  if(digitalRead(knoppen[0]) == LOW) {
    digitalWrite(ledArray[index], LOW);
    if(index == 0) {
      index = 3;
    }
    else {
      index--;
    }
    delay(200);
    digitalWrite(ledArray[index], HIGH);
    delay(200);
  }

  if(digitalRead(knoppen[1]) == LOW) {
    digitalWrite(ledArray[index], LOW);
    index = 0;
    delay(200);
    digitalWrite(ledArray[index], HIGH);
    delay(200);
  }

}
