#include <stdio.h>

void empty() {}
void add() { printf("Add\n"); }
void subtract() { printf("Subtract\n"); }
void multiply() { printf("Multiply\n"); }
void (*operations[10])();

typedef struct
{
    int arrayIndex;
    int (*ptr)();
} EventListenElement;

// EventListenElement testElement = {0, Test1};

int listenerCounter;

// function declaration
void AddListener(void (*func)());
void RemoveListener(void (*func)());
void Invoke();

void RemoveListenerAtPoint(int index);
void UpdateListenerArray(int startIndex);
int GetIndex(void (*func)());

void Test0();
void Test1();
void Test2();

int main()
{

    printf("size : %d\n", listenerCounter);

    AddListener(Test0);
    AddListener(Test1);
    AddListener(Test2);

    printf("size : %d\n", listenerCounter);

    Invoke();
    RemoveListener(Test1);
    Invoke();

    return 0;
}

void AddListener(void (*func)())
{
    operations[listenerCounter] = *func;
    listenerCounter++;
}

void RemoveListener(void (*func)())
{
    printf("\n-----Remove listener from array-----\n");

    int index = GetIndex(*func);
    RemoveListenerAtPoint(index);
}

void Invoke()
{
    printf("\n\n---Invoke---\n");
    for (int i = 0; i < listenerCounter; i++)
    {
        operations[i]();
    }
}

int GetIndex(void (*func)())
{
    for (int i = 0; i < 10; i++)
    {
        if (operations[i] == *func)
        {
            printf("FOUND IT | i : %d", i);
            return i;
        }
    }
}

void RemoveListenerAtPoint(int index)
{
    operations[index] = empty;

    if (index < listenerCounter)
        UpdateListenerArray(index);
}

void UpdateListenerArray(int startIndex)
{
    for (int i = startIndex; i < listenerCounter; i++)
    {
        operations[i] = operations[i + 1];
    }

    listenerCounter--;
}

void Test0()
{
    printf("Test0\n");
}

void Test1()
{
    printf("Test1\n");
}

void Test2()
{
    printf("Test2\n");
}
