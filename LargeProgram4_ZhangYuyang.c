//Yuyang Zhang
//Dr. Steinberg
//COP 3223 Section 5
//Large Program 4

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//create structure that has 5 elements
typedef struct{
    int id;
    char firstname[25];
    char lastname[25];
    char house[25];
    double gpa;
}Hogwarts;

void menu();//display options
Hogwarts * createarray(int maxsize, int currentsize);//create dynamic array
Hogwarts * Insert(Hogwarts *myarray, int *maxsize, int *currentsize);//add a brand new record to the array
int Remove(Hogwarts *arr, int size);//remove an existing record from the array
void Search(Hogwarts *myarray, int *currentsize);//check to see if a record exists in the array
void Display(Hogwarts *myarray, int currentsize);//display all records in the array
Hogwarts *doubleit(Hogwarts *arr, int size);//double array when memory is full
int write_file(Hogwarts *myarray, int currentsize);//write in record

int main(void)
{
    int maxsize = 30;
    char option = 'z';
    int currentsize = 6;//set initial size in array

    Hogwarts *myarray = createarray(maxsize, currentsize);//function 2 call

    printf("Welcome to the Hogwarts School Student Record System!\n");

    do
    {
        menu();//function 1 call
        printf("Enter here: ");
        scanf(" %c", &option);

        //determine each option
        if(option == 'a' || option == 'A')
        {
            printf("*************************************************************\n");
            printf("Adding new student to the system.\n");
            myarray = Insert(myarray, &maxsize, &currentsize);//function 3 call
        }
        else if(option == 'd' || option == 'D')
        {
            printf("*************************************************************\n");
            printf("Displaying all student records.\n");
            Display(myarray, currentsize);//function 6 call
        }
        else if(option == 'r' || option == 'R')
        {
            printf("*************************************************************\n");
            printf("Removing student from the system.\n");
            currentsize = Remove(myarray, currentsize);//function 4 call
        }
        else if(option == 'l' || option == 'L')
        {
            printf("*************************************************************\n");
            printf("Looking up a student record.\n");
            Search(myarray, &currentsize);//function 5 call
        }
        else if(option == 'e' || option == 'E')
        {
            printf("*************************************************************\n");
            printf("Exiting the system and saving records to a text file called Records.txt.\n");
            break;
        }
        else
            printf("Invalid Selection...\n");
    }
    while(option != 'e' || option != 'E');

    write_file(myarray, currentsize);//function 8 call

	free(myarray);
	myarray = NULL;//make sure dynamic array is null

	return 0;
}

void menu()//function 1 definition
{
    //output menu
    printf("*************************************************************\n");
    printf("What would you like to do?\n");
    printf("A: Add Student Record\n");
    printf("R: Remove Student Record\n");
    printf("D: Display All Student Records\n");
    printf("L: Lookup Student Record\n");
    printf("E: Exit Program\n");
}

Hogwarts * createarray(int maxsize, int currentsize)//function 2 definition
{
    Hogwarts * myarray = (Hogwarts *) malloc(maxsize * sizeof(Hogwarts));//request dynamic memory
    if (myarray == NULL)//determine if malloc function work or not
    {
        printf("Memory allocation error!");
        exit(0);
    }

    //set initial records that contain 6 students
    Hogwarts initialarray[] = {{1,"Harry","Potter","Gryffindor",3.87},{2,"Ron","Wesley","Gryffindor",3.01},{3,"Hermonie","Granger","Gryffindor",4.00},{4,"Draco","Malfoy","Slytherin",2.57},{5,"Luna","Lovegood","Ravenclaw",3.42},{6,"Cedric","Diggory","Hufflepuff",3.38}};


    for(int i = 0; i < currentsize; ++i)//Put records under the corresponding pointers
    {
        (i + myarray)->id = initialarray[i].id;
        strcpy((i + myarray)->firstname, initialarray[i].firstname);
        strcpy((i + myarray)->lastname, initialarray[i].lastname);
        strcpy((i + myarray)->house, initialarray[i].house);
        (i + myarray)->gpa = initialarray[i].gpa;
    }

    return myarray;
}

Hogwarts * Insert(Hogwarts *myarray, int *maxsize, int *currentsize)//function 3 definition
{
    int option;
    if(*maxsize == *currentsize)//determine if dynamic array is full
	{
		printf("Array is full...Need to doubleit...\n");
		myarray = doubleit(myarray, *maxsize);//function 7 call
        *maxsize = *maxsize * 2;
	}

	myarray[*currentsize].id = myarray[*currentsize - 1].id + 1;//increase id

	//input new student information
    printf("Enter the student's first name: ");
	scanf("%s", myarray[*currentsize].firstname);
	printf("\n\n");

	printf("Enter the student's last name: ");
	scanf("%s", myarray[*currentsize].lastname);
	printf("\n\n");

	printf("Please select one of the following for the student's house.\n");
	printf("1: Gryffindor\n");
	printf("2: Hufflepuff\n");
	printf("3: Ravenclaw\n");
	printf("4: Slytherin\n");
	printf("Enter key: ");
	scanf("%d", &option);
	switch(option)
    {
        case 1:
            strcpy(myarray[*currentsize].house, "Gryffindor");
            printf("\n\n");
            printf("Gryffindor Selected.\n");
            break;

        case 2:
            strcpy(myarray[*currentsize].house, "Hufflepuff");
            printf("\n\n");
            printf("Hufflepuff Selected.\n");
            break;

        case 3:
            strcpy(myarray[*currentsize].house, "Ravenclaw");
            printf("\n\n");
            printf("Ravenclaw Selected.\n");
            break;

        case 4:
            strcpy(myarray[*currentsize].house, "Slytherin");
            printf("\n\n");
            printf("Slytherin Selected.\n");
            break;

        default:
            printf("Invalid Selection...\n");
    }

    printf("What is the %s's GPA: ", myarray[*currentsize].firstname);
    scanf("%lf", &myarray[*currentsize].gpa);

	++*currentsize;//expand size

	return myarray;
}

int Remove(Hogwarts *arr, int size)//function 4 definition
{
    int newsize = size;
    int id;
    printf("Please enter the Id of the student you want to move: ");
    scanf("%d", &id);

    for (int i = 0; i < size; ++i)
    {
        if(id == (i + arr)->id)//determine if the id matched
        {
            for(int i = 0; i + id < size; ++i)//adjust array elements, move to the previous one
            {
                (i + id - 1 + arr)->id = (i + id + arr)->id;
                strcpy((i + id - 1 + arr)->firstname, (i + id + arr)->firstname);
                strcpy((i + id - 1 + arr)->lastname, (i + id + arr)->lastname);
                strcpy((i + id - 1 + arr)->house, (i + id + arr)->house);
                (i + id - 1 + arr)->gpa = (i + id + arr)->gpa;
            }

            //empty the last one of each elements
            (size - 1 + arr)->id = 0;
            strcpy((size - 1 + arr)->firstname, "\0");
            strcpy((size - 1 + arr)->lastname, "\0");
            strcpy((size - 1 + arr)->house, "\0");
            (size - 1 + arr)->gpa = 0;

            newsize = size -1;//decrease size
        }
    }
    if(newsize == size)
        printf("The student is not in the list!\n");

    return newsize;
}

void Search(Hogwarts *myarray, int *currentsize)//function 5 definition
{
    int n;
    int p = 0;
    printf("Enter student id: ");
    scanf("%d", &n);

    for (int j = 0; j < *currentsize; ++j)
    {
        if(n == (j + myarray)->id)//determine if the id matched
        {
            //output the information corresponding to that id
            printf("\nHere is the student info.\n");
            printf("id: %d\n", (j + myarray)->id);
            printf("First Name: %s\n", (j + myarray)->firstname);
            printf("Last Name: %s\n", (j + myarray)->lastname);
            printf("House: %s\n", (j + myarray)->house);
            printf("GPA: %.2lf\n", (j + myarray)->gpa);
            p = 1;
        }
    }
    if(p == 0)//determine if id in the array
        printf("\nThe student does not exist in the system.\n");
}

void Display(Hogwarts *myarray, int currentsize)//function 6 definition
{
    //output array
    for(int i = 0; i < currentsize; ++i)
	{
	    printf("id: \t%d\n", (i + myarray)->id);
		printf("First Name: \t%s\n", (i + myarray)->firstname);
		printf("Last Name: \t%s\n", (i + myarray)->lastname);
		printf("House: \t%s\n", (i + myarray)->house);
		printf("GPA: \t%.2lf\n", (i + myarray)->gpa);
		printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	}
}

Hogwarts *doubleit(Hogwarts *arr, int size)//function 7 definition
{
    Hogwarts * newarr = (Hogwarts *) malloc(2 * size * sizeof(Hogwarts));//request extra dynamic memory
    if (newarr == NULL)//determine if request success
    {
        printf("Memory allocation error!");
        exit(-1);
    }
    for(int i = 0; i < size; ++i)//copy the information to new array
    {
        (i + newarr)->id = (i + arr)->id;
        strcpy((i + newarr)->firstname,(i + arr)->firstname);
        strcpy((i + newarr)->lastname,(i + arr)->lastname);
        strcpy((i + newarr)->house,(i + arr)->house);
        (i + newarr)->gpa = (i + arr)->gpa;
    }

    return newarr;
}

int write_file(Hogwarts *myarray, int currentsize)//function 8 definition
{
    FILE *fp = NULL;//set pointer
    fp = fopen("Records.txt", "w");//open records
    for(int i = 0; i < currentsize; i++, myarray++)//write information to the record text file
        fprintf(fp, "Id:\t%d\nFirst Name:\t%s\nLast Name:\t%s\nHouse:\t%s\nGPA:\t%.2lf\n\n", myarray->id, myarray->firstname, myarray->lastname, myarray->house, myarray->gpa);

    fclose(fp);//close record
    return 0;
}
