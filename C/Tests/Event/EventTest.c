#include <stdio.h>

#include "Event.h"
#include "EventManager2.h"

CustomEvent OnButtonPress;

// function declareations
void Attack();
void DoSomething();

int main()
{
    InitEvent(&OnButtonPress);

    AddListener(&OnButtonPress, Attack);
    AddListener(&OnButtonPress, DoSomething);


    Invoke(&OnButtonPress);
}

void Attack()
{
    printf("Attack\n");
}

void DoSomething(){
        printf("Do something\n");
}