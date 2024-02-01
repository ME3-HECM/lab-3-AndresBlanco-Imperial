// CONFIG1L
#pragma config FEXTOSC = HS     // External Oscillator mode Selection bits (HS (crystal oscillator) above 8 MHz; PFM set to high power)
#pragma config RSTOSC = EXTOSC_4PLL// Power-up default value for COSC bits (EXTOSC with 4x PLL, with EXTOSC operating per FEXTOSC bits)
// CONFIG3L
#pragma config WDTE = OFF        // WDT operating mode (WDT enabled regardless of sleep)

#include <xc.h>

//#include "LEDarray.h"
#include "interrupts.h"
#include "comparator.h"



void main(void) {
	//call your initialisation functions to set up the hardware modules

    TRISHbits.TRISH3 = 0;
    LATHbits.LATH3=1;
    __delay_ms(300);
    LATHbits.LATH3 = 0;
    DAC_init();
    Comp1_init();
    Interrupts_init();
    while (1) {
        Sleep();
    }
}