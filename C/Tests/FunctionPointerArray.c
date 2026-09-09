#include <stdio.h>

void empty(){}
void add() { printf("Add\n"); }
void subtract() { printf("Subtract\n"); }
void multiply() { printf("Multiply\n"); }
void (*operations[10])() = {add, subtract, multiply};
void (*operations[10])() = {add, subtract, multiply};

// function declaration
void AddListener(void (*func)());
void Test();

int main()
{
  int lenghtArray = sizeof(operations) / sizeof(operations[0]);

  printf("size : %d\n", lenghtArray);

  AddListener(Test);

  lenghtArray = sizeof(operations) / sizeof(operations[0]);
  printf("size : %d\n", lenghtArray);

  
  for (int i = 0; i < 3; i++)
  {
    operations[i]();
  }
  

  return 0;
}

void AddListener(void (*func)())
{
  operations[2] = *func;
  //func();
}

void Test()
{
  printf("Test\n");
}