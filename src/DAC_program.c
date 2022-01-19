/*  Author  : fatma                          */
/*  Date    : 19 December 2021                  */
/*  version : V1                             */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "DAC_interface.h"
#include "DAC_private.h"
#include "DAC_config.h"

#include <Hello.h>
#include <Help.h>
#include <Hungry.h>
#include <Water.h>


volatile u16 flag1=0;
volatile u16 flag2=0;
volatile u16 flag3=0;
volatile u16 flag4=0;

void DAC_voidInit(void)
{
	   MGPIO_voidSetPinDirection(GPIOA, PIN8, OUTPUT_SPEED_2MHZ_PP);
	   MGPIO_voidSetPinDirection(GPIOA, PIN9, OUTPUT_SPEED_2MHZ_PP);
	   MGPIO_voidSetPinDirection(GPIOA, PIN10, OUTPUT_SPEED_2MHZ_PP);
	   MGPIO_voidSetPinDirection(GPIOA, PIN11, OUTPUT_SPEED_2MHZ_PP);
	   MGPIO_voidSetPinDirection(GPIOA, PIN12, OUTPUT_SPEED_2MHZ_PP);
	   MGPIO_voidSetPinDirection(GPIOA, PIN15, OUTPUT_SPEED_2MHZ_PP);
	   MGPIO_voidSetPinDirection(GPIOC, PIN13, OUTPUT_SPEED_2MHZ_PP);
	   MGPIO_voidSetPinDirection(GPIOC, PIN14, OUTPUT_SPEED_2MHZ_PP);


}


void voidSetDAC_Hello(void)
{

	u8 Local_u8BIT;


	if(flag1<5476)
	{
		for(int iteration=0; iteration<8; iteration++)
		{
			/* Get bit value */
			Local_u8BIT = GET_BIT(Hello_raw[flag1],iteration);

			/*Set value in desire pin */
			MGPIO_voidSetPinValue(PIN_DATA[iteration][0],PIN_DATA[iteration][1], Local_u8BIT);
		}
	}

	flag1 ++;

}


void voidSetDAC_Help(void)
{

	u8 Local_u8BIT;

	if(flag2 < 4021)
	{
		for(int iteration=0; iteration<8; iteration++)
		{
			/* Get bit value */
			Local_u8BIT = GET_BIT(Help_raw[flag2],iteration);

			/*Set value in desire pin */
			MGPIO_voidSetPinValue(PIN_DATA[iteration][0],PIN_DATA[iteration][1], Local_u8BIT);
		}
	}

	flag2 ++;
}


void voidSetDAC_Hungry(void)
{

	u8 Local_u8BIT;

	if(flag3 < 5226)
	{
		for(int iteration=0; iteration<8; iteration++)
		{
			/* Get bit value */
			Local_u8BIT = GET_BIT(Hungry_raw[flag3],iteration);

			/*Set value in desire pin */
			MGPIO_voidSetPinValue(PIN_DATA[iteration][0],PIN_DATA[iteration][1], Local_u8BIT);
		}
	}
	flag3 ++;
}


void voidSetDAC_Water(void)
{

	u8 Local_u8BIT;

	if(flag4 < 4517)
	{
		for(int iteration=0; iteration<8; iteration++)
		{
			/* Get bit value */
			Local_u8BIT = GET_BIT(Water_raw[flag4],iteration);

			/*Set value in desire pin */
			MGPIO_voidSetPinValue(PIN_DATA[iteration][0],PIN_DATA[iteration][1], Local_u8BIT);
		}
	}

	flag4 ++;
}
