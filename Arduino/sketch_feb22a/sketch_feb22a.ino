uint8_t MSB[] = {0x3B,0X0C,0x00,0x00,0xF3};
uint8_t LSB[] = {0x47,0x87,0x0F,0x07,0x87};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for(int i = 0; i < 5;i ++){
    int16_t waarde_signed = MSB[i]*256 + LSB[i];
    waarde_signed = waarde_signed >> 7;
    Serial.print(waarde_signed);
    Serial.print(" ");
  }

  Serial.print("\n");

  for(int j = 0; j < 5; j ++){
    uint16_t waarde_unsigned = MSB[j]*256 + LSB[j];
    waarde_unsigned = waarde_unsigned >> 7;
    Serial.print(waarde_unsigned);
    Serial.print(" ");
  }
  

}

void loop() {
  // put your main code here, to run repeatedly:

}
