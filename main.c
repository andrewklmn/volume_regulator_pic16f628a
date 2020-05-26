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
unsigned char resistence = 0;
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


    while(1)
    {
        
        if (C2OUT==1) {
            if (resistence > 0 ) resistence--;
        } else {
            if (resistence < 15 ) resistence++;
        }; 
        
        /* 
         *  volume regulator with two buttons
         * 
        if (VOLUME_UP == IS_PRESSED
            && VOLUME_DOWN == IS_UNPRESSED) {
            // volume up
            if (resistence>0) resistence--;
            
        } else if (VOLUME_UP == IS_UNPRESSED
            && VOLUME_DOWN == IS_PRESSED) {
            // volume down
            if (resistence<15) resistence++;
        };
        */
        
        
        TRISB = ~((resistence<<4) + resistence);
        PORTB = ~((resistence<<4) + resistence);
        
        __delay_ms(200);
        
        /* 
        for (unsigned char i=0; i<16; i++) {
            TRISB = ~(((15-i)<<4) + i);
            PORTB = ~(((15-i)<<4) + i);
            __delay_ms(30);
        };        
        for (unsigned char i=0; i<16; i++) {
            TRISB = ~((i<<4) + 15-i);
            PORTB = ~((i<<4) + 15-i);
            __delay_ms(30);
        }; 
        */       
    };
};

