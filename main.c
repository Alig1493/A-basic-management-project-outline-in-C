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

/*Defining the maximum number of employees that
we want to save in our database (i.e FILES)
Here the our limit is upto a 100 employees.*/
#define MAX_NUMBER_OF_EMPLOYEES 100

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
                password[i] = character_input;
                printf("*");
                i++;
            }
            printf("\n");

            if (strcmp(password, correct_password) == 0)
            {
                /*
                A successful match of both the user and the password
                will cause the credentials() function to return a
                value of 1, with which we can use to determine that the
                login attempt was a success.
                */
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


int main()
{
    // system("cls")
    printf("Welcome to a demo management system! Enter the proper username and password to access the main menu!\n");
    printf("%d", credentials());

    /*while(true)
    {

    }*/
    return 0;
}
