#ifndef BUTTON_H
#define BUTTON_H

#include <stdio.h>
#include <stdbool.h>

#include "Event.h"


typedef enum
{
    START,
    PERFORMED,
    EXIT
}ButtonState;


typedef struct
{
    // Fields
    int CurrentState; // TODO: mabey make it a lower number because it's or a 0 or a 1
    int PreviousState;

    int hardwarePin; 

    // mabey the manager should decide instead for each individual button
    int HighSignalDefiner; // this to know what a highSignal is
    int LowSignalDefiner; // this to know what a highSignal is
    
    ButtonState currentState;
    
    // events that functions can listen to
    CustomEvent OnStart;
    CustomEvent OnPreformed;
    CustomEvent OnExit;
    
} ButtonInput;

#endif