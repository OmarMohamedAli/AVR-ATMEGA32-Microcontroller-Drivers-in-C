
/*
 * File        : AVR_DIO_Program .c
 * Description : This file includes DIO Driver implementations for Atmega32
 * Author      : Omar Mohamed Embedded SW Engineer 
 * Date        : 2/3/20201
 * Git account : https://github.com/OmarMohamedAli
 * mail        : om1565580@gmail.com
 */


#include "Bit_Math.h"
#include "Std_Types.h"
#include "AVR_private.h"
#include "AVR_interface.h"


/********************************************************************* 
 * Prototype   : void Port_Direction(char base , char state);
 * Description : Set direction of the whole register
 * Arguments   : BASE Register: takes only A ,B ,C ,D
 *               Status  : takes (input) sets whole reg i/p ,(output) sets whole reg o/p
 * return      : Nothing 
 **********************************************************************/
void Port_Direction (char base , char state)
{   if (state==output)
	(*(volatile char *)(base+1)) =0xff ;
	else
	(*(volatile char *)(base+1)) =0x00 ;
}


/********************************************************************** 
 * Prototype   : void Bin_Direction (char base, char bin,char state );
 * Description : Set direction of one bit of the register
 * Arguments   : BASE Register: takes only A ,B ,C ,D
				 bin          : takes number from 0 to 7
 *               Status       : takes only input , output
 * return      : Nothing 
 **********************************************************************/
void Bin_Direction (char base, char bin,char state )
{    if (state==output)
	{
		(*(volatile char *)(base+1)) |= 1<<bin ;
	}
	else
	(*(volatile char *)(base+1)) &= ~(1<<bin) ;
}


/********************************************************************** 
 * Prototype   : void Bin_Reset (char base ,char bin);
 * Description : Set one bit of the register LOW
 * Arguments   : BASE Register: takes only A ,B ,C ,D
				 bin          : takes number from 0 to 7             
 * return      : Nothing 
 **********************************************************************/
void Bin_Reset (char base ,char bin  )
{
	(*(volatile char *)(base+2)) &= ~(1<<bin) ;
}


/********************************************************************** 
 * Prototype   : void Bin_Set (char base , char bin );
 * Description : Set one bit of the register HIGH
 * Arguments   : BASE Register: takes only A ,B ,C ,D
				 bin          : takes number from 0 to 7             
 * return      : Nothing 
 **********************************************************************/
void Bin_Set (char base , char bin )
{
	(*(volatile char *)(base+2)) |=1<<bin ;
}


/********************************************************************* 
 * Prototype   : void Port_Write(char base ,char value);
 * Description : write o/p to  the whole register
 * Arguments   : BASE Register: takes only A ,B ,C ,D
 *               value        : takes number from 0 to 255
 * return      : Nothing 
 **********************************************************************/
void Port_Write(char base ,char value  )
{
	(*(volatile char *)(base+2)) = value ;
}


/********************************************************************* 
 * Prototype   : char Port_Read(char base );
 * Description : Read i/p of the whole register
 * Arguments   : BASE Register: takes only A ,B ,C ,D
 * return      : Nothing 
 **********************************************************************/
char Port_Read(char base )
{ char Reg_value ;
	Reg_value = (*(volatile char *)(base)) ;
	return Reg_value ;
}


/********************************************************************* 
 * Prototype   : void Pin_Write(char base , char bin , char value);
 * Description : Write value of one bit of the register
 * Arguments   : BASE Register: takes only A ,B ,C ,D
                 bin          : takes number from 0 to 7 
				 value        : 0 or 1
 * return      : Nothing 
 **********************************************************************/
void Pin_Write(char base , char bin , char value)
{  if(value ==0)
	(*(volatile char *)(base+2)) &= ~(1<<bin) ;
	else
	(*(volatile char *)(base+2)) |= (1<<bin) ;
}


/********************************************************************* 
 * Prototype   : char Pin_Read(char base ,char bin );
 * Description : Read pin value of one bit of the register
 * Arguments   : BASE Register: takes only A ,B ,C ,D
                 bin          : takes number from 0 to 7      
 * return      : Nothing 
 **********************************************************************/
char Pin_Read(char base ,char bin )
{   char Pin_value ;
	Pin_value =(*(volatile char *)(base) && (1<<bin));
	if (Pin_value==0) return 0 ;
	else return 1 ;
}
