/* 
 * File:   switch.h
 * Author: Ali
 *
 * Created on February 3, 2016, 10:15 AM
 */

#include <xc.h>


#define INPUT 1
#define OUTPUT 0

#define ENABLED 1 
#define DISABLED 0

void initSwitch1(){
    //TODO: Initialize switch 1
    TRISDbits.TRISD6 = INPUT;//Initialize switch
    CNPUDbits.CNPUD6 = ENABLED;   
}