uint8_t MSB[] = {0x3B,0X0C,0x00,0x00,0xF3};
uint8_t LSB[] = {0x47,0x87,0x0F,0x07,0x87};
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Methode 1");
  for(int i = 0; i < 5;i ++){
    uint16_t waarde_unsigned = MSB[i]*256 + LSB[i];
    waarde_unsigned = waarde_unsigned >> 7;
    int16_t waarde_signed = MSB[i]*256 + LSB[i] ;
    waarde_signed = waarde_signed >> 7;
    if(waarde_unsigned != waarde_signed){
      Serial.print("Negatieve waarde : ");
      Serial.println(waarde_signed);
    }

    else {
      Serial.println(waarde_unsigned);
    }
  }

  Serial.println("\nMethode 2");
  for(int j = 0; j < 5; j ++){
    
    uint16_t waarde_unsigned = MSB[j]*256 + LSB[j];
    Serial.println(waarde_unsigned);
    
    byte negatiefGetal = bitRead(MSB[j],7);
    if(negatiefGetal > 0){
      uint16_t waarde = waarde_unsigned;
      waarde = ~waarde;
      waarde = waarde >> 7;
      waarde = waarde + B00000001;
      Serial.print("Negatieve waarde : -");
      Serial.println(waarde);
    }
    else{
     Serial.println(waarde_unsigned);
    }
  }

  Serial.print("\n");

}

void loop() {
  // put your main code here, to run repeatedly:

}
