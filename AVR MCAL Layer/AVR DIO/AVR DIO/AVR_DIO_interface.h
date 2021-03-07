

/*
 * File        : AVR_DIO_interface.h
 * Description : This file includes AVR DIO Driver prototypes for Atmega32
 * Author      : Omar Mohamed Embedded SW Engineer 
 * Date        : 2/3/20201
 * Git account : https://github.com/OmarMohamedAli
 * mail        : om1565580@gmail.com
 */


#include "Bit_Math.h"
#include "Std_Types.h"
#include "AVR_private.h"


#ifndef AVR_INTERFACE_H_
#define AVR_INTERFACE_H_

/********************************************************************* 
 * Prototype   : void Port_Direction(char base , char state);
 * Description : Set direction of the whole register
 * Arguments   : BASE Register: takes only A ,B ,C ,D
 *               Status  : takes (input) sets whole reg i/p ,(output) sets whole reg o/p
 * return      : Nothing 
 **********************************************************************/
void Port_Direction(char base , char state);


/********************************************************************** 
 * Prototype   : void Bin_Direction (char base, char bin,char state );
 * Description : Set direction of one bit of the register
 * Arguments   : BASE Register: takes only A ,B ,C ,D
				 bin          : takes number from 0 to 7
 *               Status       : takes only input , output
 * return      : Nothing 
 **********************************************************************/
void Bin_Direction (char base, char bin,char state );


/********************************************************************** 
 * Prototype   : void Bin_Reset (char base ,char bin);
 * Description : Set one bit of the register LOW
 * Arguments   : BASE Register: takes only A ,B ,C ,D
				 bin          : takes number from 0 to 7             
 * return      : Nothing 
 **********************************************************************/
void Bin_Reset (char base ,char bin);


/********************************************************************** 
 * Prototype   : void Bin_Set (char base , char bin );
 * Description : Set one bit of the register HIGH
 * Arguments   : BASE Register: takes only A ,B ,C ,D
				 bin          : takes number from 0 to 7             
 * return      : Nothing 
 **********************************************************************/
void Bin_Set (char base , char bin );


/********************************************************************* 
 * Prototype   : void Port_Write(char base ,char value);
 * Description : write o/p to  the whole register
 * Arguments   : BASE Register: takes only A ,B ,C ,D
 *               value        : takes number from 0 to 255
 * return      : Nothing 
 **********************************************************************/
void Port_Write(char base ,char value);


/********************************************************************* 
 * Prototype   : char Port_Read(char base );
 * Description : Read i/p of the whole register
 * Arguments   : BASE Register: takes only A ,B ,C ,D
 * return      : Nothing 
 **********************************************************************/
char Port_Read(char base );


/********************************************************************* 
 * Prototype   : char Pin_Read(char base ,char bin );
 * Description : Read pin value of one bit of the register
 * Arguments   : BASE Register: takes only A ,B ,C ,D
                 bin          : takes number from 0 to 7      
 * return      : Nothing 
 **********************************************************************/
char Pin_Read(char base ,char bin );


/********************************************************************* 
 * Prototype   : void Pin_Write(char base , char bin , char value);
 * Description : Write value of one bit of the register
 * Arguments   : BASE Register: takes only A ,B ,C ,D
                 bin          : takes number from 0 to 7 
				 value        : 0 or 1
 * return      : Nothing 
 **********************************************************************/
void Pin_Write(char base , char bin , char value);


#endif