#include <stdio.h>

//

typedef struct
{
    const int Index;
    const int Pin;
    int value;

} Input;

Input Arrow_Up_Button = {0, 9};
Input Arrow_Down_Button = {1, 10};
Input Arrow_Left_Button = {2, 11};
Input Arrow_Right_Button = {3, 12};

Input InputArray[5];

// methods declarations
void CheckInput(Input input);

int main()
{
    Arrow_Up_Button.value = 0;
    printf(" | up value : %d | ", Arrow_Down_Button.value);

    CheckInput(Arrow_Up_Button);

    printf(" | After Updated : %d | \n", Arrow_Up_Button.value);
    return 0;
}

void CheckInput(Input input)
{
    input.value = 10;
    printf(" | During Update : %d | ", input.value);
}

void CheckInput2(int* ptr){

}

int GetInputValue()
{

}

void CheckInputList()
{

}
