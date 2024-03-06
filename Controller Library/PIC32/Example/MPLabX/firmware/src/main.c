/*******************************************************************************
  Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This file contains the "main" function for a project.

  Description:
    This file contains the "main" function for a project.  The
    "main" function calls the "SYS_Initialize" function to initialize the state
    machines of all modules in the system
 *******************************************************************************/

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "definitions.h"                // SYS function prototypes
#include "cansart.h"

// *****************************************************************************
// *****************************************************************************
// Section: Main Entry Point
// *****************************************************************************
// *****************************************************************************
unsigned long millis();
unsigned long vTimer2 = 0;

struct frame10 frames10;
struct frame23 frames23;
struct frame121 frames121;

unsigned long tempMillis = 0;

int main(void) {
    /* Initialize all modules */
    SYS_Initialize(NULL);

    frames10.ID = 10;
    frames23.ID = 23;
    frames121.ID = 121;

    frames10.LENGHT = 8;
    frames23.LENGHT = 8;
    frames121.LENGHT = 8;




    while (true) {
        /* Maintain state machines of all polled MPLAB Harmony modules. */
        SYS_Tasks();
        if (frames10.RPM >= 250) frames10.RPM = 0;
        if (millis() - vTimer2 >= 500) {
            frames10.RPM++;
            GPIO_RB1_Toggle();
            vTimer2 = millis();
        }
        
        tempMillis = millis();
        
        if (updateDB(&frames10) == 1) {
            frames10.SPEED = (millis() - tempMillis);
        }
        
        updateDB(&frames23);
        
        updateDB(&frames121);
    }

    /* Execution should not come here during normal operation */

    return ( EXIT_FAILURE);
}

unsigned long millis(void) {
    return (unsigned int) (CORETIMER_CounterGet() / (CORE_TIMER_FREQUENCY / 1000));
}
/*******************************************************************************
 End of File
 */

