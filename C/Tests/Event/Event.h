#ifndef EVENT_H
#define EVENT_H

#include <stdio.h>

#define MAX_LISTENERS 10


typedef struct
{
    int MaxListeners;
    int ListenerCounter;
    void (*ListenerArray[MAX_LISTENERS])(); // function pointer array
} CustomEvent;

#endif