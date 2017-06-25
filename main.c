/*
Done By: Mohammed Ali Zubair

Rule of thumb: If you're gonna copy at least try and
understand it first.
You need to be able to sell yourself and you can't
do that unless you know
exactly what on earth is going on here.

THANK YOU!
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

/*
Defining the maximum number of employees that
we want to save in our database (i.e FILES)
Here the our limit is upto a 100 employees.
*/
#define MAX_NUMBER_OF_EMPLOYEES 100
/*
We will use this variable below to keep
track of the number of employees that will
be entered by the user during the duration
of the program. It will start off as 0 each
time the program runs. We will initialize it
with a different value when we are using files.
*/
static int number_of_current_employees = 0;
/*
Defining a basic structure to store date information
of integer types. C comes with its own built in
date and time functions, but for ease of use
and understanding we are going to be using our
own date format.
*/
typedef struct date
{
    int day;
    int month;
    int year;
}date;

/*
Defining a basic structure to store information
of various types. Date joined will be inherited
from the structure above for the date which we
have defined ourselves.
*/
typedef struct employee
{
    char first_name[50];
    char last_name[50];
    char job_title[30];
    int employee_id;
    float salary;
    date joined;

}employee_structure;

/*
using typedef I have named my structure
called employee employee_structure, and used it to
create an array of employee structures using the
defined limit mentioned above
*/
employee_structure employee_member[MAX_NUMBER_OF_EMPLOYEES];

/*this function, called "credentials, is mainly used
by me to verify if the user logging in the moderator of
the program. If he/she is the moderator, they will know
the username and password, which we ALSO HAVE TO MENTION AND
SAVE IT IN A VARIABLE OF THIS PROGRAM, since there are no
external database sources available to us. SO if the username
and password matches, it will direct you to the home screen where
you will have a couple of basic options to choose from. You will
have endless tries to try and enter the correct username and password,
that is unless you choose to exit  the program yourself.*/
int credentials()
{
    char username[30] = "", password[30] = "";
    char correct_username[] = "username", correct_password[] = "password";
    char continue_confirmation, character_input;
    int i;
    /*
    flag here is used to control the flow of the infinite while
    loop that we will be using to prompt the user for
    input.
    */
    int flag = 1;

    while(flag)
    {
        printf("Enter username: ");
        /*
        FFLUSH is a debug tool that we can sometimes
        use to flush out the input buffer, which we have done
        in this case by providing the STDIN argument.
        */
        fflush(stdin);
        gets(username);
        /*
        each strcmp compares the input with the available
        information for username and password, if there is
        a match, then we will proceed.*/
        if (strcmp(username, correct_username) == 0)
        {
            printf("Enter password: ");
            i = 0;
            /*
            We are taking character input as long as the
            user doesn't enter a new line, which can be detected
            when the enter key is pressed. New line input in C
            programming is detected via '\r' as opposed to '\n',
            which only gives us a new line during output formatting.
            */
            while((character_input = getch()) != '\r')
            {
                /*
                While taking the input password as *'s I have come
                to notice that even the backspace keys which is normally
                used to delete the previous entered inputs in the same line
                will be accepted as characters for getch(), as opposed to it's
                actual purpose of deleting the previous characters. As a
                result I have googled the fix to this problem by looking for
                the backspace input and deleting the previous characters entered.
                The stackoverflow link that helped me solve this problem is:
                https://stackoverflow.com/questions/8132245/backspace-and-delete-issues-with-the-getch-function-in-dos
                */
                if(character_input == '\b')
                {
                    i--;
                    if(i<0)
                        i++;
                    else
                        printf("\b \b");
                }
                /*
                Trying to give the user an authentic feel
                of being able to see stars when trying to
                provide password credentials.
                */
                else
                {
                    password[i] = character_input;
                    printf("*");
                    i++;
                }
            }
            /*
            Always good practice to terminate the end of a string in
            a character array with a null (i.e: \0)
            */
            password[i] = '\0';
            printf("\n");

            if (strcmp(password, correct_password) == 0)
            {
                /*
                A successful match of both the user and the password
                will cause the credentials() function to return a
                value of 1, with which we can use to determine that the
                login attempt was a success.
                */
                printf("Correct Username and Password!");
                Sleep(2000);
                return 1;
            }

            else
            {
                while(1)
                {
                    printf("Would you like to try again? Enter Y/y for yes and N/n for no:\n");
                    fflush(stdin);
                    scanf("%c", &continue_confirmation);

                    if(continue_confirmation == 'Y' || continue_confirmation == 'y')
                    {
                        flag = 1;
                        break;
                    }
                    else if(continue_confirmation == 'N' || continue_confirmation == 'n')
                    {
                        flag = 0;
                        break;
                    }
                    else
                        printf("Incorrect input! Try again!\n");
                }
            }

        }

        else
        {
            while(1)
            {
                printf("Would you like to try again? Enter Y/y for yes and N/n for no:\n");
                fflush(stdin);
                scanf("%c", &continue_confirmation);

                if(continue_confirmation == 'Y' || continue_confirmation == 'y')
                {
                    flag = 1;
                    break;
                }
                else if(continue_confirmation == 'N' || continue_confirmation == 'n')
                {
                    flag = 0;
                    break;
                }
                else
                    printf("Incorrect input! Try again!\n");
            }
        }
    }
    /*
    A failure to provide the proper authorization
    credentials will cause this function to return
    a value of 0, by which we can determine, that
    the login attempt was a failure, and the program
    will most likely end here.
    */
    return 0;

}

void main_menu()
{
    system("cls");

    int options, flag = 1;

    while(flag)
    {
        printf("Welcome to this demo employee management project!");
        printf("Please choose one of the available options below:");

        printf("Enter 1 to see the list of current employee details.");
        printf("Enter 2 to enter one or more employee details.");
        printf("Enter 3 to edit one or more current employee details.");
        printf("Enter 4 to remove a current employee details from the system.");
        printf("Enter 5 to save data of current employee details.");
        printf("Enter 6 to save and exit the program.");

        switch(options)
        {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                flag = 0;
                break;
            default:
                printf("You have entered a wrong number as input! Please try again.");
        }

    }

}


int main()
{
    printf("Welcome to a demo management system! Enter the proper username and password to access the main menu!\n");

    if (credentials())
        main_menu();
    else
        printf("Thank You for taking time to run this program");

    return 0;
}
