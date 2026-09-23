#include <stdio.h>

#include "Event.h"
#include "EventManager2.h"
#include "Button.h"

ButtonInput ButtonA;
ButtonInput ButtonB;

// function declarations

void InitEvents();
void SetEvents();

void Activate();
void Cancel();

int main()
{
    InitEvents();
    SetEvents();

    printf("test");

    return 0;
}

void InitEvents()
{
    InitEvent(&ButtonA.OnStart);
    InitEvent(&ButtonB.OnStart);
}

void SetEvents()
{
    AddListener(&ButtonA.OnStart, Activate);
    AddListener(&ButtonB.OnStart, Cancel);
}

void Activate()
{
    printf("Activate\n");
}


void Cancel()
{
    printf("Cancel\n");
}
