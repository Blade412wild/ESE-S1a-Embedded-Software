#ifndef BUTTONMANAGER_H
#define BUTTONMANAGER_H

#include <stdio.h>
#include <stdbool.h>
#include "Button.h"

// fields 
ButtonInput ActiveButtons[6];
ButtonInput IdleButtons[6];

// method declarations 
void _InitButtons();
void _ReadButtonInput();



#endif