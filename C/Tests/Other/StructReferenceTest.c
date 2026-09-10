#include <stdio.h>

typedef struct
{
    int Age;
} Person;

Person Human;

void SetValue(Person human, int value);
void SetValueThroughReference(Person* humanPtr, int value);
void ShowAge(Person human);

int main()
{

    Human.Age = 20;
    ShowAge(Human);

    //SetValue(Human, 30);
    //ShowAge(Human); // shows 20 because SetValue a struct is not a reference type

    SetValueThroughReference(&Human, 60);
    ShowAge(Human); 


    return 0;
}

void SetValueThroughReference(Person* humanPtr, int value)
{
    float test;
    humanPtr->Age = value;
    printf("size of pointer : %d\n", sizeof(humanPtr));
}

void SetValue(Person human, int value)
{
    human.Age = value;
    ShowAge(human);
}

void ShowAge(Person human)
{
    printf("human is : %d old\n", human.Age);
}
