/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

#if defined(__XC)
    #include <xc.h>         /* XC8 General Include File */
#elif defined(HI_TECH_C)
    #include <htc.h>        /* HiTech General Include File */
#endif

#include <stdint.h>         /* For uint8_t definition */
#include <stdbool.h>        /* For true/false definition */
#include <pic16f628a.h>

#include "system.h"
#include "user.h"

/******************************************************************************/
/* User Functions                                                             */
/******************************************************************************/

/* <Initialize variables in user.h and insert code for user algorithms.> */

void InitApp(void)
{
    /* Disable interrupts */
    INTCON = 0b00000000;
    
    CMCON = 0b00000011; //Enable comparators
    /* Setup analog functionality and port direction */
    
    //it sets half volume for both channels 
    TRISA = 0b00100111;
    PORTA = 0b00100111;
    
    nRBPU=1; // pull-ups are disabled
    
    TRISB = 0b00000000;    
    PORTB = 0b10001000;
    
    MIN_REACHED_LED = LIGHT_ON;
    MAX_REACHED_LED = LIGHT_ON;
    __delay_ms(500);
    MIN_REACHED_LED = LIGHT_OFF;
    MAX_REACHED_LED = LIGHT_OFF;
    __delay_ms(500);
    MIN_REACHED_LED = LIGHT_ON;
    MAX_REACHED_LED = LIGHT_ON;
    __delay_ms(500);
    MIN_REACHED_LED = LIGHT_OFF;
    MAX_REACHED_LED = LIGHT_OFF;
    __delay_ms(500);
    MIN_REACHED_LED = LIGHT_ON;
    MAX_REACHED_LED = LIGHT_ON;
    __delay_ms(500);
    MIN_REACHED_LED = LIGHT_OFF;
    MAX_REACHED_LED = LIGHT_OFF;
    __delay_ms(500);
    MIN_REACHED_LED = LIGHT_ON;
    MAX_REACHED_LED = LIGHT_ON;
    __delay_ms(500);
    MIN_REACHED_LED = LIGHT_OFF;
    MAX_REACHED_LED = LIGHT_OFF;
    __delay_ms(500);
    MIN_REACHED_LED = LIGHT_ON;
    MAX_REACHED_LED = LIGHT_ON;
    __delay_ms(500);
    MIN_REACHED_LED = LIGHT_OFF;
    MAX_REACHED_LED = LIGHT_OFF;
    __delay_ms(500);
    
    /* Setup analog functionality and port direction */

    /* Initialize peripherals */

    /* Enable interrupts */
}

