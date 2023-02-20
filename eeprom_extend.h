/*
  eeprom_extend.h - Biblioteca memoria extendida para Arduino desenvolvida por
  Luiz Fernando M. Arruda
*/

#ifndef eeprom_extend_h
#define eeprom_extend_h

#include "Arduino.h"

class eeprom_extend {
    public:
		eeprom_extend(byte address);
		void eeprom_write(int from_addr, int data);
		void eeprom_write_long2(int from_addr, int data);
		byte eeprom_read(int from_addr);
		int eeprom_read_long2(int from_addr);
	private:
		byte _Address;
};

#endif
