#include <Wire.h>
#include<eeprom_extend.h>

#define i2c_mem 0x50

eeprom_extend mem(i2c_mem);

void setup() {

  Serial.begin(9600);
  Serial.println("Testando modulos no barramento i2c.");

  Wire.begin(); 

  // testa comunicacao Memoria
  Wire.beginTransmission(i2c_mem);
  int error = Wire.endTransmission();
  if (error == 0) {
    Serial.println("Memoria EEPROM Online");
  } else {
    Serial.println("Memoria EEPROM Offline");
  }

  Serial.println("Gravando numeros de teste!");
  mem.eeprom_write(1,150); // Grava valor 150 na posicao 1 da memoria
  mem.eeprom_write_long2(5,65000); // Grava valor 500 nas posições 10 e 11 da porta
  // no formato long2 são utilizados 2 posições de memoria para cada gravação.
  delay(50);
}

void loop() {

  Serial.println("Lendo a memoria!");
  unsigned int val = mem.eeprom_read(1); // le o endereco numero 1
  Serial.println(val);
  unsigned int val2 = mem.eeprom_read_long2(5);// le o endereco 5 ("10 e 11") na memoria
  Serial.println(val2);
  delay(500);
}
