#ifndef adc_h
#define adc_h

	void ADC_init(void)
	{
		DDRA=0x00;
		PORTA=0xFF;
		ADCSRA|=(1<<ADEN)|(1<<ADPS2); // Adc enable...selects prescaler FCPU/16
	}

	unsigned char read_adc(unsigned char adc_input)			// This gives u a 8bit value on the particular channel no.
	{
	ADMUX=adc_input|0x20;  // Selects the channel and puts the ref to Vref and selects ADLAR as left adjust

	// Start the AD conversion
	ADCSRA|=0x40;

	// Wait for the AD conversion to complete
	while ((ADCSRA & (1<<ADIF))==0);	// The value of ADIF will be 1 , once the convertion is complete

	ADCSRA|=0x10;		// ADIF bit is cleared by writting a 1 to it.

	return ADCH;
	}

#endif
