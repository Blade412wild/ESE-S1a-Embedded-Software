#include <stdio.h>
#include <stdbool.h>
#include "Button.h"

// fields
ButtonInput IdleButtons[6];
ButtonInput ActiveButtons[6];

int ActiveButtonsLenght = -1;

// method declarations
void SetupManager();
void UpdateButtonManager();

// private, don't use outside this class
void _SetupArrayLenght();
void _InitButtons();
void _ReadButtonInput();

void SetupManager()
{
    _SetupArrayLenght();
}

void _SetupArrayLenght()
{
    if (ActiveButtonsLenght == -1)
    {
        ActiveButtonsLenght = sizeof(ActiveButtons) / sizeof(ActiveButtons[0]);
    }
}

void _InitButtons()
{

}

void _ReadButtonInput()
{
    for (int i = 0; i <ActiveButtonsLenght; i++){
        
    }
}