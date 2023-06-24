//Yuyang Zhang
//Dr. Steinberg
//COP 3223 Section 5
//Large Program 3

#include<stdio.h>
#include<string.h>
#define maxstrike 6
#define maxwords 20


void rules(); //display rules of the game
void maskWord (char starword[], int size); //mask the word with stars to display to user in game
int playRound(char starword[], char answer[]); //function that plays a round of hangman. returns 1 if user won
int occurancesInWord(char userguess, char answer[]); //number of times letter occurs in word. Greater than 0 means letter exist
void updateStarWord(char starword[], char answer[], char userguess); //update starword. replace respective * character with respective letter
void playAgain(int *play); //ask user if to play again. 1 is yes 2 is no

int main(void)
{
    int play;
    int ww;
    char starword[maxwords];
    char answer[maxwords];

    rules();//function 1 call

    FILE *fp;//set file pointer
    fp = fopen("words.txt", "r");//file open
    if(fp == NULL)//determine if there still have words
        printf("fail to open the file!\n");

    do
    {
        fgets(answer, maxwords, fp);//get words from txt
        if (answer[strlen(answer) - 1]=='\n')
            answer[strlen(answer) - 2] = '\0';//delete space

        ww = playRound(starword, answer);//function 3 call
        if (ww == 1)//determine if player win
            printf("Congratulations! You won! The word was %s.\n", answer);

        else
        {
            printf("************************************************************************\n");
            printf("Sorry you did not win the round. The word was %s.\n", answer);
        }
        playAgain(&play);//function 6 call
    }
    while (play == 1);//determine player want to play or not

    fclose(fp);//close file
    printf("************************************************************************\n");
    printf("Thank you for playing today!");
    return 0;
}

void rules(void)//function 1 definition
{
    //output rule
    printf("Welcome to the Hangman Game!\n");
    printf("************************************************************************\n");
    printf("Here are the rules.\n");
    printf("I will provide you a set of * characters for each round.\n");
    printf("Each * represents a letter in the English Alphabet.\n");
    printf("You must figure out each letter of the missing word.\n");
    printf("For every correct letter guessed, I will reveal its place in the word.\n");
    printf("Each mistake will result in a strike.\n");
    printf("6 strikes will result in a loss that round.\n");
    printf("Are you ready? Here we go!\n");
}

void maskWord (char starword[], int size)//function 2 definition
{
    //set the initial starword to be a star string
    for (int i = 0; i < size; ++i)
    starword[i] = '*';
}

int playRound(char starword[], char answer[])//function 3 definition
{
    int strike = 0;//set initial strike
    char userguess;
    char space1;
    char record[maxwords] = "\0";//set initial player's record
    int n;
    int win = 0;
    char user[2];

    printf("************************************************************************\n");
    printf("Welcome to the Round!\n");

    int size = strlen(answer);//get word length
    printf("The size of the word has %d letters\n\n", size);
    answer[size] = '\0';//set initial answer string
    starword[size] = '\0';//set initial starword string

    maskWord (starword, size);//function 2 call

    //output information
    printf("You currently have %d strikes.\n", strike);
    printf("Letter you have guessed: \n\n");
    printf("%s", starword);
    printf("\n\n");

     do
     {
        do
        {
            printf("Enter your guess: ");
            scanf("%c%c", &userguess, &space1);
            printf("\n");

            if (isalpha(userguess) == 0)//check if player input an alphabet
                printf("You did not enter a letter from the alphabet.\n\n");
        }

        while (isalpha(userguess) == 0);

        userguess = tolower(userguess);//convert uppercase to lowercase

        n = occurancesInWord(userguess, answer);//function 4 call

        if (n == 0)//when player guess wrong
        {
            strike++;
            printf("The letter %c is NOT in the word.\n\n", userguess);

            if (strike >= maxstrike)//player gets the final strike and lose the round
            {
                win = 0;
                break;
            }
        }
        else//player guess correct
        {
            updateStarWord(starword, answer, userguess);//function 5 call

            if (strcmp(starword, answer) == 0)//player win the round
            {
                win = 1;
                break;
            }
            printf("The letter %c is in the word.\n\n", userguess);
        }

        printf("You currently have %d strike(s).\n", strike);

        user[0] = userguess;//convert character to string
        strcat(record, user);//connect userguess to record


        printf("Letter(s) you have guessed: %s\n\n", record);
        printf("%s\n\n", starword);

    }
    while (strike < maxstrike);

    return win;
}

int occurancesInWord(char userguess, char answer[])//function 4 definition
{
    int number = 0;
    char record[maxwords];
    for (int i = 0; i < strlen(answer); ++i)
    {
        if (answer[i] == userguess)//check same letter
            number++;
    }
    return number;//returns the number of occurrences of a single letter
}

void updateStarWord(char starword[], char answer[], char userguess)//function 5 definiton
{
    for (int i = 0; i < strlen(answer); ++i)
    {
        if (userguess == answer[i])
                starword[i] = userguess;//show the correct letter to replace star
    }
}

void playAgain(int *play)//function 6 definition
{
    int pp;
    char space2;
    printf("************************************************************************\n");
    printf("Would you like to play another round?\n");
    printf("1: Yes\n");
    printf("2: No\n");
    printf("Choice: ");
    scanf("%d%c", &pp, &space2);
    *play = pp;//assign the user's choice to the pointer
    printf("\n");
}
