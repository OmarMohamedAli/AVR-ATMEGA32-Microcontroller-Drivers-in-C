/*
 * Led Blinking.c
 *
 * Created: 3/2/2021 6:30:54 PM
 * Author : Fannan
 */ 
#include "D:\omar\GITHUB\DRIVERS\AVR ATMEGA32 Microcontroller\AVR MCAL Projects\Led Blinking\AVR DIO\Std_Types.h"
#include "D:\omar\GITHUB\DRIVERS\AVR ATMEGA32 Microcontroller\AVR MCAL Projects\Led Blinking\AVR DIO\Bit_Math.h"
#include "D:\omar\GITHUB\DRIVERS\AVR ATMEGA32 Microcontroller\AVR MCAL Projects\Led Blinking\AVR DIO\AVR_DIO_private.h"
#include "D:\omar\GITHUB\DRIVERS\AVR ATMEGA32 Microcontroller\AVR MCAL Projects\Led Blinking\AVR DIO\AVR_DIO_interface.h"


//#define F_CPU 8000000
#include <util/delay.h>

int main(void)
{
	Port_Direction(A , output);
	Bin_Direction (C, 4,output);
	Bin_Direction (D, 0, input );
	Port_Direction(B , output);
	while (1)
	{
		Pin_Write(A ,1 ,1 );
		Bin_Reset (C , 4);
		_delay_ms(500);
		Bin_Set (C, 4);
		Pin_Write(A ,1 ,0 );
		_delay_ms(500);
		Port_Write(B,255);
		_delay_ms(500);
		Port_Write(B,0);
		if((Pin_Read(D, 0))){
			Bin_Set(A ,2 );
			_delay_ms(500);
			Bin_Reset(A ,2 );
			_delay_ms(500);
		}
	}
}



