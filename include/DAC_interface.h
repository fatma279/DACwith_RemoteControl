/*  Autour  : fatma                          */
/*  Date    : 19 December 2021               */
/*  version : V1                             */


#ifndef DAC_INTERFACE_H
#define DAC_INTERFACE_H


void DAC_voidInit(void);

void voidSetDAC_Hello(void);

void voidSetDAC_Help(void);

void voidSetDAC_Hungry(void);

void voidSetDAC_Water(void);

extern volatile u16 flag1;
extern volatile u16 flag2;
extern volatile u16 flag3;
extern volatile u16 flag4;

#endif
