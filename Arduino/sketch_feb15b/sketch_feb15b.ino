void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  int a = 0x41;
  String naam = "Cardoen";
  String voornaam = "Joachim";

  // Print integer value of HEX
  Serial.println(a);

  // Print ASCII value of HEX/int
  Serial.write(a);

  Serial.println("\n" + naam + " " + voornaam);
  for (int i = 0; i < naam.length() ; i++ ) {
    char a = naam.charAt(i);
    Serial.write(a);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
