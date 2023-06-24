//Yuyang Zhang
//Dr. Steinberg
//COP 3223 Section 5
//Large Program 1

#define ROUNDS 5
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

void Greeting(); //display welcome message to user
void SetSeed(int seed); //set the seed of pseudo random generator
int PlayRound(char answer, int round); //play one round
char GetGuess(); //retrieve the user's guess
int CompareLetters(char guess, char answer); //compare the user's guess with the answer
void RoundResult(int result, char answer); //determine if the user won or loss the round


int main()//Main function first function called
{
    //Variables set
	int seed = 3;
	int round;
    char answer;
    int result;

    Greeting();//function call
    SetSeed(seed);//function call

	for (int game = 1; game <= ROUNDS; game++)//this loop will allow the user play 5 rounds. You have to fill in the missing code that simulates the round and result. You will also need to determine random letter answer the program will store
		//DO NOT REMOVE OR CHANGE THE LOOP!!!
	{
		int round = game;//Variable assigned
		char random = rand()%26 + 65;//Use ASCII code to set random numbers to uppercase letters

		answer = random;//Assign random to answer

		result = PlayRound(answer, round);//function call and assign to result

        RoundResult(result, answer);//function call
		//this loop will allow the user play 5 rounds. You have to fill in the missing code that simulates the round and result. You will also need to determine random letter answer the program will store
		//DO NOT REMOVE OR CHANGE THE LOOP!!!
	}

	printf("Thank you for playing!");

	return 0;//function terminator
}

void Greeting()//function definition
{
    //Output statement
    printf("Welcome to the Letter Guessing Game!\n");
    printf("Here are the rules.\n");
    printf("I will think of a letter in the English Alphabet and you will have to guess it!\n");
    printf("I will provide you a limit of 5 chances to guess the correct the letter.\n");
    printf("Are you ready to play 5 rounds? Here we go!\n");
    printf("********************************************************\n");
    printf("********************************************************\n");
}

void SetSeed(int seed)//function definition
{
    srand (seed);//Set pseudo-random number
}

int PlayRound(char answer, int round)//function definition
{
    //Set variable
	char guess;
    int result;

	printf("Round %d\n", round);//Output round number

	for (int chance = 1; chance <= 5; chance++)
	{
        printf("Guess #%d\n", chance);//Output Guess number

        guess = GetGuess();//function call and assign to guess

        result = CompareLetters(guess, answer);//function call

        if (result == 2)//Determine whether to break out of the loop
        {
           break;
        }
	}
	//this loop will allow the user to guess until they are out of chances, you have fill in the missing code that checks to see if user guessed correctly
		//DO NOT REMOVE OR CHANGE THE LOOP!!!

        return result;//return result to main

	 RoundResult(result, answer);//function call
}

char GetGuess()//function definition
{
    //Variables set
    char guess;
    char enter;
    char g1;

    printf("Enter your guess: ");//Output statement
    scanf("%c%c", &g1, &enter);//input player's guess

    if (g1 >= 97 && g1 <= 122)//Convert lowercase letters to uppercase letters
    {
        g1 = g1 - 32;
    }
}

int CompareLetters(char guess, char answer)//function definition
{
    int judge;//Variable set

    //Use conditional statements to determine the position of letters and output statement
    if (guess < answer)
    {
        judge = 1;
        printf("The letter you picked comes before the one I am thinking of.\n\n");
    }

    else if (guess > answer)
    {
        judge = 1;
        printf("The letter you picked comes after the one I am thinking of.\n\n");
    }

    else if (guess == answer)
    {
        judge = 2;
        printf("The letter you picked is the one I am thinking of.\n\n");
    }

    return judge;//Return an integer to determine whether to end the loop
}

void RoundResult(int result, char answer)//function definition
{
    //According to the previous result, use conditional statements to determine whether player win or lose
    if (result == 2)
    {
        printf("Congratulations! You won the round!\n");
        printf("********************************************************\n");
    }

    else if (result == 1)
    {
        printf("Sorry! You didn't win the round!\n");
        printf("The letter I was thinking of was %c.\n", answer);//Output correct answer
        printf("********************************************************\n");
    }

}
