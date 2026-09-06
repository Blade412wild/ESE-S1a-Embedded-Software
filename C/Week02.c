#include <stdio.h>
#include <stdbool.h>

const int maxGuesses = 3;
const int secretNumber = 5;

const int minRange = 0;
const int maxRange = 100;

int guesCounter = 3; // maxGuesses
char playerName[30];

bool guesIsCorrect = false;

// Method declarations
void Introduction();
void AttemptGues();
int GetUserGues();
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

    int input = GetUserGues();

    ///*

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

int GetUserGues()
{
    int userGues;

    printf("number : ");
    scanf("%d", &userGues);
    guesCounter--;
    // printf("%s you guessed : %d", playerName, userGues);

    return userGues;
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
