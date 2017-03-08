uint8_t MSB[] = {0x3B,0X0C,0x00,0x00,0xF3};
uint8_t LSB[] = {0x47,0x87,0x0F,0x07,0x87};
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for(int j = 0; j < 5; j ++){   
    uint16_t waarde_unsigned = MSB[j]*256 + LSB[j];
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
      waarde_unsigned = waarde_unsigned >> 7;
      byte telBij = waarde_unsigned & B01000000;
      waarde_unsigned = waarde_unsigned >> 7;
      if(telBij > 0){
        float waarde = waarde_unsigned + 0.5;
        Serial.print(waarde);
        Serial.print("\n");
      }
      else {
        Serial.print(waarde_unsigned);
        Serial.print("\n");
      }
    }
  }

  Serial.print("\n");

}

void loop() {
  // put your main code here, to run repeatedly:

}

