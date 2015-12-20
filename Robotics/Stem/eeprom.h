#ifndef eeprom_h
#define eeprom_h

	void eeprom_write(unsigned int add,unsigned char data)
	{
	EEAR=add;
	EEDR=data;
	EECR|=(1<<EEMWE);
	EECR|=(1<<EEWE);
	while((EECR&(1<<EEWE)));
	}

	unsigned char eeprom_read(unsigned int add)
	{
	EEAR=add;
	EECR|=(1<<EERE);
	while((EECR&(1<<EERE)));
	return EEDR;
	}
#endif
