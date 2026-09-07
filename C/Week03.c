#include <stdio.h>
#include <stdbool.h>

const int maxGuesses = 3;
const int secretNumber = 5;

const int minRange = 0;
const int maxRange = 100;

int guesCounter = 3; // maxGuesses
char playerName[30];

const int hintActivationThreshold = 75;

bool guesIsCorrect = false;

// Method declarations
void Introduction();
void AttemptGues();
int GetUserGues();
int GetUserGues2();
bool CheckIfInputIsValid(int userInput);
void GiveUserAHint(int input);
void Win();
void Lose();

int main()
{
    Introduction();
    AttemptGues(); // recursive funtion

    return 0;
}
void Introduction()
{
    // introduction
    printf("Welcome to the guessing game!\n");
    printf("The objective of the game is to guess the secret number between %d and %d You get : ", minRange, maxRange);

    printf("%d", guesCounter);

    if (guesCounter == 1)
    {
        printf(" chance ...\n\n");
    }
    else
    {
        printf(" chances...\n\n");
    }

    printf("To address you personally, I would like to know your name.\n");
    printf("your name: ");

    // fills in name
    scanf("%s", playerName);
    printf("Great <%s>, let's get started. (%d Guesses left)\n", playerName, guesCounter);
}
void AttemptGues()
{

    bool validInput = false;
    int input;

    while (validInput == false)
    {
        input = GetUserGues2();
        validInput = CheckIfInputIsValid(input); // belangrijk escape while loop
    }
    
    guesCounter--;
    printf("out of while-loop");

    
    if (input == secretNumber)
    {
        guesIsCorrect = true;
    }
    
    
    if (guesIsCorrect)
    {
        Win();
    }
    else
    {
        if (guesCounter > 0)
        {
            printf("\nwrong, try again (%d guesses left)\n", guesCounter);
            AttemptGues();
        }
        else
        {
            Lose();
        }
    }
    //*/
}

int GetUserGues2()
{
    int userGues;

    printf("number : ");
    scanf("%d", &userGues);
    return userGues;
}
/*
int GetUserGues()
{
    int userGues;

    printf("number : ");
    scanf("%d", &userGues);

    CheckIfInputIsValid(userGues);
    guesCounter--;

    // printf("%s you guessed : %d", playerName, userGues);

    return userGues;
}

*/


void GiveUserAHint(int input){
    /*
    
    printf("a little hint : \n");

    char hint[] = " ";

    if(input < secretNumber){
        hint = "higher";
    }
    else if(input > secretNumber){
        hint = "lower";
    }
    printf("the secret number is %s\n", hint);
    */
    
}

bool CheckIfInputIsValid(int userInputPointer) // ervan uitgaan dat het een interger is
{
    if (userInputPointer < minRange || userInputPointer > maxRange)
    {
        printf("Input not in Range(%d-%d)\n", minRange, maxRange);
        return false;
    }

    return true;
}

void Win()
{

    int guesAttempts = maxGuesses - guesCounter;
    if (guesAttempts == 1)
    {
        printf("\nCongradulations you guessed correct!!\nYou did it in %d attempt", guesAttempts);
    }
    else
    {
        printf("\nCongradulations you guessed correct!!\nYou did it in %d attempts", guesAttempts);
    }
}

void Lose()
{
    printf("I'm sorry you're out of guesses, See you next Time");
}
