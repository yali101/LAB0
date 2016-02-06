/* 
 * File:   switch.h
 * Author: Ali
 *
 * Created on February 3, 2016, 10:15 AM
*/


#include <xc.h>
#include <sys/attribs.h>
#include "switch.h"
#include "timer.h"
#include "led.h"
#include "interrupt.h"
#include "config.h"

#define OUTPUT 0
#define INPUT 1

#define ON 1
#define OFF 0
#define LED1 LATDbits.LATD0 
#define LED2 LATDbits.LATD1
#define LED3 LATDbits.LATD2
/********************************************THIS IS PART #3***************************************/
//part 2

typedef enum stateTypeEnum{
    led1, led2, led3
}stateType;


//TODO: Use volatile variables that change within interrupts
volatile stateType state = led3;

int main() {
    //SYSTEMConfigPerformance(10000000);    //Configures low-level system parameters for 10 MHz clock
    enableInterrupts();                   //This function is necessary to use interrupts.

    //TODO: Write each initialization function
    initLEDs();
    initTimer1();
    
    while(1){
        //TODO: Implement a state machine to create the desired functionality
        
        switch(state){
            case led1:  //LED1 is on
                LATDbits.LATD0 = ON;
                LATDbits.LATD1 = OFF;
                LATDbits.LATD2 = OFF;
                break;
            case led2:  //LED2 is on
                LATDbits.LATD0 = OFF;
                LATDbits.LATD1 = ON;
                LATDbits.LATD2 = OFF;
                break;
            case led3:  //LED3 is on
                LATDbits.LATD0 = OFF;
                LATDbits.LATD1 = OFF;
                LATDbits.LATD2 = ON;
                break;
        } 
    }
    return 0;
}

//TODO: Add interrupt service routines that manage the change of states
//for particular events as needed
//the function you want to call when the CN gets triggered
void __ISR(_TIMER_1_VECTOR, IPL7SRS) _T1Interrupt(){
    IFS0bits.T1IF = 0;  //ALWAYS set Interrupt Flag back down
    
    if(state == led1){          
        state = led2;   
    }else if(state == led2){    
        state = led3;
    }else if(state == led3){    
        state = led1;
    }
}







//part3

/*
typedef enum stateTypeEnum{
 
    led1, led2, led3, wait, secondWait, debouncePress, debounceRelease, debounceRelease2
} stateType;
 
//TODO: Use volatile variables that change within interrupts
 
volatile int state=led1;
 
volatile int timing=0;

int main() {
  
    SYSTEMConfigPerformance(10000000);
    enableInterrupts();
    initSwitch1();
    initLEDs();
    initTimer1();
     initTimer2();
      int PrevState=0;  
     while(1)
    {
            switch(state){
               case  led1:
                    LED1=ON;
                    LED2=OFF; 
                    LED3=OFF;
                     PrevState=1;
                   if(PORTDbits.RD6==0)
                   {
                        state=debouncePress; 
                  }
                     break;
                case led2:
                    LED1=OFF;
                    LED2=ON;
                    LED3=OFF;
                    PrevState=2;
                 if(PORTDbits.RD6==0)
                   {
                      state=debouncePress;
                    }
                    break;
 
               case led3:
 
                    LED1=OFF;
                     LED2=OFF;
                     LED3=ON;
                      PrevState=3;
 
                if(PORTDbits.RD6==0)
                  {

                      state=debouncePress;
                  }
 
                    break;
                    
                case debouncePress:
                  delayMs(10);
                  state=wait;

                  break;      
 
              case debounceRelease: 
                  delayMs(10); 
                  state=secondWait;
                   break;
                   
              case wait:
 
                    if(PORTDbits.RD6==0)
 
                    {
                         state=wait;
                     }
 
                    else
                    {
 
                        state=debounceRelease;
                    }
 
                    break;
 
                case secondWait:
                    if (timing==1)
                     {
                         if(PrevState==1)
                        {
                             timing=0;
                             TMR1=0;
                             state=led3;

                        }
                        else if(PrevState==2)
                        {
                            timing=0;
                            TMR1=0;
                             state=led1;
                         }
                         else if(PrevState==3)
                         {
                             timing=0;
                             TMR1=0;
                             state=led2;
                         }
                     }
                     else
                     {
                        if(PrevState==1)
 
                        {
                            timing=0; 
                            TMR1=0;
                            state=led2;
 
                        }
                         else if(PrevState==2)
                         {
                             timing=0;
                             TMR1=0;
                             state=led3;
 
                        }
                         else if(PrevState==3)
                         {   
                            timing=0;
                             TMR1=0;
                             state=led1;
                         }
                     } 
                   break;
            }
 
        }
  
    return 0;
 
}
 

void __ISR(_TIMER_1_VECTOR, IPL7SRS) __T1Interupt()
{

    IFS0bits.T1IF=0;        //set flag back down
 
    timing=1;
 
}
 */