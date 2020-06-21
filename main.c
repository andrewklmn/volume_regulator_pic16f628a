                                                                             /******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

#if defined(__XC)
    #include <xc.h>         /* XC8 General Include File */
#elif defined(HI_TECH_C)
    #include <htc.h>        /* HiTech General Include File */
#endif

#include <stdint.h>        /* For uint8_t definition */
#include <stdbool.h>       /* For true/false definition */
#include <pic16f628a.h>

#include "system.h"        /* System funct/params, like osc/peripheral config */
#include "user.h"          /* User funct/params, such as InitApp */

/******************************************************************************/
/* User Global Variable Declaration                                           */
/******************************************************************************/
unsigned char resistence;
unsigned char output;
/* i.e. uint8_t <variable_name>; */

/******************************************************************************/
/* Main Program                                                               */
/******************************************************************************/
void main(void)
{
    /* Configure the oscillator for the device */
    ConfigureOscillator();

    /* Initialize I/O and Peripherals for application */
    InitApp();

    resistence = 8;
    PORTB = 0;
        
    while(1)
    {
        /* 
         * C1 - low limit signal, 
         * C2 - high limit signal 
         */ 
        
                
        RA7 = C1OUT;
        RA6 = C2OUT;
        
        
        if (C1OUT==1 && C2OUT==1) {
            // volume is to silent
            if (resistence <15 ) resistence++;
        } else if (C1OUT==0 && C2OUT==0 ) {
            // volume is to  high
            if (resistence > 0 ) resistence--;
        };
        
        if (AUTOVOLUME==IS_PRESSED) {
            TRISB = ~((resistence<<4) + resistence);
        } else {
            TRISB = 0b10111011;
        };
        
        if ( resistence==15 && RA6==1) { 
            MAX_REACHED_LED=LIGHT_ON;
        } else {
            MAX_REACHED_LED=LIGHT_OFF;
        };
        
        if ( resistence==0 ) { 
            MIN_REACHED_LED=LIGHT_OFF;
        } else {
            MIN_REACHED_LED=LIGHT_ON;
        };
        
        __delay_ms(300);
        
        
    };
};

