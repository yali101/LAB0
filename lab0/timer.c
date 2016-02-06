/* 
 * File:   switch.h
 * Author: Ali
 *
 * Created on February 3, 2016, 10:15 AM
 */


#include <xc.h>

//part2

void initTimer1(){
    //TODO: Initialize Timer 1 to have a period of
    T1CONbits.TCKPS = 3;// initial pre-scalar
    //T1CONbits.TCS = 0;  // Setting the oscillator
    TMR1 = 0;           // clear TMR1
    PR1  = 5000;       // initialize PR1   
    IEC0bits.T1IE = 1;  // Enable the interrupt
    IFS0bits.T1IF = 0;  // Put the flag down
    IPC1bits.T1IP = 7;  // Configure the Interrupt Priority
    T1CONbits.ON = 1;   // Turn the timer on
}


//part3

void initTimer1(){
    //TODO: Initialize Timer 1 to have a period of
    T1CONbits.TCKPS = 3;// initial pre-scalar
    //T1CONbits.TCS = 0;  // Setting the oscillator
    TMR1 = 0;           // clear TMR1
    PR1  = 39061;       // initialize PR1   
    IEC0bits.T1IE = 1;  // Enable the interrupt
    IFS0bits.T1IF = 0;  // Put the flag down
    IPC1bits.T1IP = 7;  // Configure the Interrupt Priority
    T1CONbits.ON = 1;   // Turn the timer on
}

initTimer2(){
    TMR2 = 0;
    IFS0bits.T2IF = 0; //put the flag down 
}

delayMs(int delay){
    TMR2 = 0;
    T2CONbits.ON=1;
    T2CONbits.TCKPS = 7;
    PR2= 5000;
    IFS0bits.T2IF = 0;
    while(IFS0bits.T2IF = 0){
        
    }
        T2CONbits.ON=0;
        IFS0bits.T2IF = 0;


    //TODO: Using timer 2, create a delay
    // that is delay amount of ms.
}
