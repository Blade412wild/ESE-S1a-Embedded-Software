#include <stdio.h>

void Empty(){}
void add() { printf("Add\n"); }
void subtract() { printf("Subtract\n"); }
void multiply() { printf("Multiply\n"); }
void (*ListenerArray[10])() = {add, subtract, multiply};
void (*ListenerArray[10])() = {add, subtract, multiply};

// function declaration
void AddListener(void (*func)());
void Test();

int main()
{
  int lenghtArray = sizeof(ListenerArray) / sizeof(ListenerArray[0]);

  printf("size : %d\n", lenghtArray);

  AddListener(Test);

  lenghtArray = sizeof(ListenerArray) / sizeof(ListenerArray[0]);
  printf("size : %d\n", lenghtArray);

  
  for (int i = 0; i < 3; i++)
  {
    ListenerArray[i]();
  }
  

  return 0;
}

void AddListener(void (*func)())
{
  ListenerArray[2] = *func;
  //func();
}

void Test()
{
  printf("Test\n");
}