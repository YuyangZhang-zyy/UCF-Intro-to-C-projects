//Yuyang Zhang
//Dr. Steinberg
//COP 3223 Section 5
//Large Program 2

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
void Greeting(); //welcome the user to their dining account
void DisplayMenu(); //display food menu
void Purchase(double *balance); //user will make a purchase
void ViewAccount(double *balance); //display current account balance of user
void Transaction(double *balance, double price); //transaction with user account
void Reload(double *balance); //reload your account balance

int main(void)//Main function first function called
{
    //Variables set
    char option;
    char enter;
    double balance = 0.00;
    double price;

    Greeting();//function call

    do
    {
        //Output option menu
        printf("*********************************************************************\n");
        printf("Please select one of the following options.\n");
        printf("P: Make a Purchase at Knightstop\n");
        printf("V: View Knight's Account Summary\n");
        printf("B: Browse Inventory at Knightstop\n");
        printf("R: Reload Knight's Account\n");
        printf("E: Exit\n");
        printf("*********************************************************************\n");

        //collect input
        printf("Please select what you would like to do.\n");
        printf("Option Selected: ");
        scanf("%c%c", &option, &enter);

        //determine option
        if (option == 'P' || option == 'p')
        {
            printf("\n");
            printf("You have selected the Purchase Option.\n");
            Purchase(&balance);//function call
        }
        else if (option == 'V' || option == 'v')
        {
            printf("\n");
            printf("You selected View Account Summary Option.\n");
            ViewAccount(&balance);//function call
        }
        else if (option == 'B' || option == 'b')
        {
            printf("\n");
            printf("You selected Browse Option.\n");
            DisplayMenu();//function call
        }
        else if (option == 'R' || option == 'r')
        {
            printf("\n");
            printf("You have selected the Reload Knight's Account Option.\n");
            Reload(&balance);//function call
        }
    }
    while (option != 'E' && option != 'e');//determine exit and break loop

        //Output statement
        printf("\n");
        printf("*********************************************************************\n");
        printf("You are now exiting the application!\n");
        printf("You have $%0.2lf in your account.\n", balance);
        printf("Have a great day!\n");
        printf("Go Knights! Charge On!\n");
        printf("*********************************************************************\n");

    return 0;//terminator
}

void Greeting()//function definition
{
    //output statement
    printf("*********************************************************************\n");
    printf("Welcome to UCF's Knight's Account Services!\n");
    printf("This is where you will manage your Knight's Account for all your purchasing needs at UCF!\n");
    printf("How can we help you today?\n");
    printf("*********************************************************************\n");
}

void DisplayMenu()//function definition
{
    //output food menu
    printf("*********************************************************************\n");
    printf("Here is what we have in stock today!\n");
    printf("1.  Bottled Water                 $1.00\n");
    printf("2.  Chips                         $2.13\n");
    printf("3.  Soda                          $1.12\n");
    printf("4.  Wrap                          $5.31\n");
    printf("5.  Candy Bag                     $3.21\n");
    printf("6.  Cheese Pizza                  $6.24\n");
    printf("7.  Chocolate Brownie             $1.23\n");
    printf("8.  Chocolate Chip Cookie         $1.15\n");
    printf("*********************************************************************\n");
}

void Purchase(double *balance)//function definition
{
    //set variable
    int op2;
    char s2;
    double price = 0.00;

    DisplayMenu();//function call

    //collect input
    printf("What would you like today?\n");
    printf("Option Selected: ");
    scanf("%d%c", &op2, &s2);


    switch (op2)//determine price option
    {
    case 1:
        price = 1.00;
        printf("Bottled Water has been selected. Total cost is: $1.00\n");
        break;
    case 2:
        price = 2.13;
        printf("Chips has been selected. Total cost is: $2.13\n");
        break;
    case 3:
        price = 1.12;
        printf("Soda has been selected. Total cost is: $1.12\n");
        break;
    case 4:
        price = 5.31;
        printf("Wrap has been selected. Total cost is: $5.31\n");
        break;
    case 5:
        price = 3.21;
        printf("Candy Bag has been selected. Total cost is: $3.21\n");
        break;
    case 6:
        price = 6.24;
        printf("Cheese Pizza has been selected. Total cost is: $6.24\n");
        break;
    case 7:
        price = 1.23;
        printf("Chocolate Brownie has been selected. Total cost is: $1.23\n");
        break;
    case 8:
        price = 1.15;
        printf("Chocolate Chip Cookie has been selected. Total cost is: $1.15\n");
        break;
    }

    Transaction(balance, price);//function call
}

void ViewAccount(double *balance)//function definition
{
    //output balance
    printf("*********************************************************************\n");
    printf("Here is your current Knight's Account balance.\n");
    printf("You have $%0.2lf in your account.\n", *balance);

    printf("*********************************************************************\n");
}

void Transaction(double *balance, double price)//function definition
{
    printf("Beginning Transaction Process.\n");

    while (*balance < price)//loop when balance not enough
    {
        //output statement
        printf("You do not have enough in your account.\n");
        printf("Please reload your account balance.\n");

        Reload(balance);//function call
    }

        //Output statement
        printf("Your account balance before official transaction: $%0.2lf\n", *balance);
        printf("Billing $%0.2lf to your account.\n", price);
        *balance = *balance - price;//calculate
        printf("Transaction was successful!\n");
        printf("You have now $%0.2lf in your account balance.\n", *balance);
        printf("*********************************************************************\n");
}

void Reload(double *balance)//function call
{
    //set variable
    int op1;
    char s1;
    double load;

    //output statement
    printf("*********************************************************************\n");
    printf("How much would you like to reload to your Knight's Account?\n");
    printf("1: $1.00\n");
    printf("2: $5.00\n");
    printf("3: $10.00\n");
    //collect input
    printf("Option Selected: ");
    scanf("%d%c", &op1, &s1);


    switch (op1)//determine load amount
    {
        case 1:
            load = 1.00;
            break;
        case 2:
            load = 5.00;
            break;
        case 3:
            load = 10.00;
            break;
    }

    *balance = *balance + load;//calculate
    //output statement
    printf("*********************************************************************\n");
    printf("$%0.2lf has been added to your Knight's Account successfully!\n", load);
    printf("*********************************************************************\n");
}
