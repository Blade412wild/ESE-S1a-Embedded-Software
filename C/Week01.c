#include <stdio.h>

const int maxGuesses = 10;
const int secretNumber = 5;

int guesCounter = 10; // maxGuesses
char playerName[30];


int main(){

    // introduction
    printf("Welcome to the guessing game!\n");
    printf("The objective of the game is to guess the secret number. You get : ");

    printf("%d", maxGuesses);

    if(maxGuesses == 1){
        printf(" chance ...\n\n");
    }
    else{
        printf(" chances...\n\n");
    }

    printf("To address you personally, I would like to know your name.\n");
    printf("your name: ");

    // fills in name
    scanf("%s", playerName);


    printf("Great <%s>, let's get started.\n", playerName);
    //printf("There is a secret number between 0 and 100, what is your first try:\n");

    return 0;

}


