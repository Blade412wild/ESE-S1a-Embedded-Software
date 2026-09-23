#include <stdio.h>

#include "Event.h"
#include "EventManager2.h"

CustomEvent OnButtonPressLower;
CustomEvent OnButtonPressUpper;


// function declareations
void Attack();
void DoSomething();
void DoSomethingElse();

int main()
{
    InitEvent(&OnButtonPressLower);
    InitEvent(&OnButtonPressUpper);

    AddListener(&OnButtonPressLower, Attack);
    AddListener(&OnButtonPressLower, DoSomething);

    AddListener(&OnButtonPressUpper, DoSomethingElse);

    Invoke(&OnButtonPressLower);
    Invoke(&OnButtonPressUpper);
}

void Attack()
{
    printf("Attack\n");
}

void DoSomething()
{
    printf("Do something\n");
}

void DoSomethingElse()
{
    printf("Do something Crazy\n");
}




