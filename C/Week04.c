#include <stdio.h>
#include <stdbool.h>

#define MAXGUESSES 8

const int maxGuesses = MAXGUESSES;
int guesCounter = 0;
const int secretNumber = 67;

int guesHistory[MAXGUESSES];

const int minRange = 0;
const int maxRange = 100;

char playerName[30];

const int hintActivationThreshold = 75;

bool guesIsCorrect = false;

// Method declarations
void Introduction();
void Win();
void Lose();
void AttemptGues();
int GetUserGues();
bool CheckIfInputIsValid(int userInput);
void GiveUserAHint(int input);
void AddGuesToHistory(int input, int index);
void PrintGuesHistory();

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

    printf("%d", maxGuesses);

    if (maxGuesses == 1)
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
    printf("\nGreat <%s>, let's get started. (%d Guesses left)\n", playerName, (maxGuesses - guesCounter));
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

    AddGuesToHistory(input, guesCounter);

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
        if (guesCounter < maxGuesses)
        {
            printf("\nwrong...");
            GiveUserAHint(input);
            printf("\ntry again (%d guesses left)\n", (maxGuesses - guesCounter));

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

void AddGuesToHistory(int input, int index)
{
    guesHistory[index] = input;
    guesCounter++;
}

void PrintGuesHistory()
{
    printf("\n--------------------");
    printf("\nGuesHistory\n");
    for (int i = 0; i < guesCounter; i++)
    {
        printf("attempt [%d] : %d \n", i, guesHistory[i]);
    }
    printf("\n--------------------");
}

void Win()
{

    if (guesCounter == 1)
    {
        printf("\nCongradulations you guessed correct!!\nYou did it in %d attempt", guesCounter);

        printf("\n\n----------------END OF Game-----------------");
    }
    else
    {
        printf("\nCongradulations you guessed correct!!\nYou did it in %d attempts", guesCounter);

        printf("\n\n----------------END OF Game-----------------");
    }
}

void Lose()
{
    printf("I'm sorry you're out of guesses, See you next Time\n");
    PrintGuesHistory();

    printf("\n\n----------------END OF Game-----------------");
}