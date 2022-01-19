/*  Author  : Fatma                          */
/*  Date    : 19 December 2021                */
/*  version : V1                             */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "DAC_interface.h"
#include "STK_interface.h"
#include "EXTI_interface.h"
#include "NVIC_interface.h"
#include "IR_interface.h"




void voidDetermineKey(u8 Copy_u8Key)
{
	switch(Copy_u8Key)
	{
		case ONE		:	 MSTK_voidSetIntervalPeriodic( 125, voidSetDAC_Hello);
		                     flag1=0;                                                         break;
		case TWO		:	 MSTK_voidSetIntervalPeriodic( 125, voidSetDAC_Help);
		                     flag2=0;                                                         break;
		case THREE		:	 MSTK_voidSetIntervalPeriodic( 125, voidSetDAC_Hungry);
		                     flag3=0;                                                         break;
		case FOUR		:	 MSTK_voidSetIntervalPeriodic( 125, voidSetDAC_Water);
		                     flag4=0;                                                         break;

	}
}

void main(void)
{
   MRCC_voidInitSysClock();                 /*chose clock system to HSE 8MHZ */
   MRCC_voidEnableClock(APB2, IOPA);        /*Enable GPIOA clock*/
   MRCC_voidEnableClock(APB2, IOPB);        /*Enable GPIOB clock */
   MRCC_voidEnableClock(APB2, IOPC);        /*Enable GPIOc clock */

   MGPIO_voidSetPinDirection(GPIOA,PIN0,INPUT_FLOATING); /* A0 Input Floating        */

   /*Init DAC pins*/
   DAC_voidInit();

	/* EXTI Initialization */
	MEXTI_voidSetCallBack(HIR_voidGetFrame, LINE0);
	MEXTI_voidInit(); /* A0 EXTI0 Enabled / Falling Edge */

	/* Enable EXTI0 from NVIC */
	MNVIC_voidInit();
	MNVIC_voidEnableInterrupt(6); /* EXTI0 */

	/*Init MSTK pins*/
   MSTK_voidInit();

   while(1)
   {
	   HIR_voidSetCallBack(voidDetermineKey);

   }



}
