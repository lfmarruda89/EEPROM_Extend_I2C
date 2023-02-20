/*
  eeprom_extend.h - Biblioteca memoria extendida para Arduino desenvolvida por
  Luiz Fernando M. Arruda
*/

#include "Arduino.h"
#include <Wire.h>
#include "eeprom_extend.h"


eeprom_extend::eeprom_extend(byte address){
	_Address = address;
}

void eeprom_extend::eeprom_write(int from_addr, int data) {
  Wire.beginTransmission(_Address);
  Wire.write((int)(from_addr >> 8)); // MSB
  Wire.write((int)(from_addr & 0xFF)); // LSB
  Wire.write(data);
  Wire.endTransmission();
  delay(5);
}

byte eeprom_extend::eeprom_read(int from_addr) {
  Wire.beginTransmission(_Address);
  Wire.write((int)(from_addr >> 8)); // MSB
  Wire.write((int)(from_addr & 0xFF)); // LSB
  Wire.endTransmission();
  Wire.requestFrom(_Address, 1);
  if(Wire.available())
    return Wire.read();
  else
    return 0xFF;
}

//utilizando 2 bytes
void eeprom_extend::eeprom_write_long2(int from_addr, int data) {
  byte two = (data & 0xFF);
  byte one = ((data >> 8) & 0xFF);
  Wire.beginTransmission(_Address);
  Wire.write((int)(from_addr >> 8)); // MSB
  Wire.write((int)(from_addr & 0xFF)); // LSB 
  delay(5);
  Wire.write(two);
  delay(5);
  Wire.write(one);
  delay(5);
  Wire.endTransmission();
}

int eeprom_extend::eeprom_read_long2(int from_addr) {
  Wire.beginTransmission(_Address);
  Wire.write((int)(from_addr >> 8));
  Wire.write((int)(from_addr & 0xFF)); 
  Wire.endTransmission();
  Wire.requestFrom(_Address, 2);
  if(Wire.available()){
    int two = Wire.read();
    int one = Wire.read();
    return ((two << 0) & 0xFF) + ((one << 8) & 0xFFFF);  
  } else {
    return 0xFF;
  }
}
