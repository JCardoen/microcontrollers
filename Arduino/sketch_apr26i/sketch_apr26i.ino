#define LED 5
int dimfactor = 0;
int teken = 1;
void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT); 
}

void loop() {
  // put your main code here, to run repeatedly:
  dimfactor+=10 * teken;
  if(dimfactor >= 250) {
    teken = -1;
  }
  if (dimfactor <= 0) {
    teken = 1;
  }
  delay(50);
  analogWrite(LED, dimfactor);
  
}
