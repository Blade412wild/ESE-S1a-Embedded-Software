#include <stdio.h>
#include <stdbool.h>

const int maxGuesses = 8;
const int secretNumber = 67;

const int minRange = 0;
const int maxRange = 100;

int guesCounter = 8; // maxGuesses
char playerName[30];

const int hintActivationThreshold = 75;

bool guesIsCorrect = false;

// Method declarations
void Introduction();
void AttemptGues();
int GetUserGues();
int GetUserGues();
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
    printf("---------------------------------\n\n");
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
    printf("\nGreat <%s>, let's get started. (%d Guesses left)\n", playerName, guesCounter);
}
void AttemptGues()
{

    bool validInput = false;
    int input;

    while (validInput == false)
    {
        input = GetUserGues();
        validInput = CheckIfInputIsValid(input); // belangrijk escape while loop
    }

    guesCounter--;

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
            printf("\nwrong...");
            GiveUserAHint(input);
            printf("\ntry again (%d guesses left)\n", guesCounter);

            AttemptGues();
        }
        else
        {
            Lose();
        }
    }
    //*/
}

int GetUserGues()
{
    int userGues;

    printf("number : ");
    scanf("%d", &userGues);
    return userGues;
}

void GiveUserAHint(int input)
{
    // /*

    printf("\n the secret number is ");
    if (input < secretNumber)
    {

        printf("higher\n");
    }
    else if (input > secretNumber)
    {
        printf("lower\n");
    }
    // */
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
        printf("\n\n---------------------------------");
    }
    else
    {
        printf("\nCongradulations you guessed correct!!\nYou did it in %d attempts", guesAttempts);
    }
}

void Lose()
{
    printf("I'm sorry you're out of guesses, See you next Time");
    printf("\n\n---------------------------------");
}
