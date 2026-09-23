#include <stdio.h>

#define MAX_LISTENERS 10

int listenerCounter;

// function declaration
// public
void AddListener(void (*func)());
void RemoveListener(void (*func)());
void Invoke();

// private
void InitEvent();
void _RemoveListenerAtPoint(int index);
void _UpdateListenerArray(int startIndex);
int _GetIndex(void (*func)());

void Test0();
void Test1();
void Test2();
void Test9();
void ShowEventArray();
void Empty() { printf("Empty\n"); }
void (*ListenerArray[MAX_LISTENERS])(); // function pointer array

int main()
{
    InitEvent();
    ShowEventArray();

    AddListener(Test0);
    AddListener(Test1);
    AddListener(Test2);
    AddListener(Test2);
    AddListener(Test2);
    AddListener(Test2);
    AddListener(Test2);
    AddListener(Test2);
    AddListener(Test2);
    AddListener(Test9);

    ShowEventArray();

    RemoveListener(Test1);

    ShowEventArray();

    RemoveListener(Test9);

    AddListener(Test1);

    ShowEventArray();


    return 0;
}

void InitEvent()
{
    for (int i = 0; i < MAX_LISTENERS; i++)
    {
        ListenerArray[i] = Empty;
    }
}

void ShowEventArray()
{
    printf("\nshow all listeners\n");
    printf("size : %d \n", listenerCounter);
    for (int i = 0; i < MAX_LISTENERS; i++)
    {
        printf("index : [%d] : ", i);
        ListenerArray[i]();
    }
}

void AddListener(void (*func)())
{
    if (listenerCounter == MAX_LISTENERS)
    {
        printf("ListenersAreFull\n");
        return;
    }
    ListenerArray[listenerCounter] = *func;

    listenerCounter++;
}

void RemoveListener(void (*func)())
{
    printf("\n-----Remove listener from array-----\n");

    int index = _GetIndex(*func);
    _RemoveListenerAtPoint(index);
}

void Invoke()
{
    printf("\n\n---Invoke---\n");
    for (int i = 0; i < listenerCounter; i++)
    {
        ListenerArray[i]();
    }
}

int _GetIndex(void (*func)())
{
    for (int i = 0; i < 10; i++)
    {
        if (ListenerArray[i] == *func)
        {
            printf("FOUND IT | i : %d\n", i);
            return i;
        }
    }
}

void _RemoveListenerAtPoint(int index)
{
    ListenerArray[index] = Empty;

    if (index < listenerCounter)
        _UpdateListenerArray(index);
}

void _UpdateListenerArray(int startIndex)
{
    printf("startIndex : %d, | counter : %d \n", startIndex, listenerCounter);

    for (int i = startIndex; i < listenerCounter; i++)
    {

        if (i == MAX_LISTENERS - 1)
        {
            printf("maxReached\n");
            ListenerArray[i] = Empty;
            continue;
        }

        ListenerArray[i] = ListenerArray[i + 1];
    }

    // ListenerArray[MAX_LISTENERS] = Empty;

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

void Test9()
{
    printf("Test9\n");
}
