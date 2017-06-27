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

    printf("Welcome to this demo employee management project!\n\n");

    while(flag)
    {
        printf("\nPlease choose one of the available options below:\n\n");

        printf("Enter 1 to see the list of current employee details.\n");
        printf("Enter 2 to enter one or more employee details.\n");
        printf("Enter 3 to edit one or more current employee details.\n");
        printf("Enter 4 to remove a current employee details from the system.\n");
        printf("Enter 5 to save data of current employee details.\n");
        printf("Enter 6 to save and exit the program.\n\n");

        printf("Your option: ");
        scanf("%d", &options);
        printf("\n");

        switch(options)
        {
            case 1:
                view_all_employee_records();
                break;
            case 2:
                enter_employee_records();
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
                printf("You have entered a wrong number as input! Please try again.\n");
        }

    }

}

void date_entry(char date[], int serial)
{
    char *token;
    int j, k = 0, date_in_integers[3];

    fflush(stdin);
    gets(date);

    /* get the first token */
   token = strtok(date, "-");

   /* walk through other tokens */
   while( token != NULL )
   {
      j = atoi (token);
      date_in_integers[k] = j;
      token = strtok(NULL, "-");
      k++;
   }

   employee_member[serial].joined.day = date_in_integers[0];
   employee_member[serial].joined.month = date_in_integers[1];
   employee_member[serial].joined.year = date_in_integers[2];

}

void enter_employee_records()
{
    int number_of_records, i = 0;
    char date[11];

    printf("How many employee records do you want to enter: ");
    scanf("%d", &number_of_records);
    printf("%d\n", number_of_records);

    printf("Enter employee details below:\n");
    printf("--------------------------------------------\n");

    while(i < number_of_records)
    {
        printf("--------------------------------------------\n");
        employee_member[i].employee_id = rand() % 9000 + 1000;
        printf("Enter details for employee %d:\n", i + 1);
        printf("Enter first name: ");
        fflush(stdin);
        gets(employee_member[i].first_name);
        printf("Enter last name: ");
        fflush(stdin);
        gets(employee_member[i].last_name);
        printf("Enter job title: ");
        fflush(stdin);
        gets(employee_member[i].job_title);
        printf("Enter salary: ");
        fflush(stdin);
        scanf("%f", &employee_member[i].salary);
        printf("Enter date in the following format (DD-MM-YYYY): ");
        date_entry(date, i);

        i++;
        number_of_current_employees++;
        printf("--------------------------------------------\n");
    }

    printf("--------------------------------------------\n");

}

void view_all_employee_records()
{
    int i = 0;

    printf("\n\n");
    printf("Current employee details in the system are as follows:\n");

    printf("--------------------------------------------\n");

    while(i < number_of_current_employees)
    {
        printf("--------------------------------------------");
        printf("\nEmployee ID: ");
        printf("%d\n", employee_member[i].employee_id);
        printf("\nEmployee Name: ");
        printf("%s %s\n", employee_member[i].first_name, employee_member[i].last_name);
        printf("\nEmployee Job Title: ");
        printf("%s\n", employee_member[i].job_title);
        printf("\nEmployee Current Salary: ");
        printf("%f\n", employee_member[i].salary);
        printf("\nEmployee Joining Date: ");
        printf("%d-", employee_member[i].joined.day);
        printf("%d-", employee_member[i].joined.month);
        printf("%d\n", employee_member[i].joined.year);
        i++;
        printf("--------------------------------------------");
        printf("\n");
    }

    printf("--------------------------------------------\n");
}

int main()
{
    printf("Welcome to a demo management system!\nEnter the proper username and password to access the main menu!\n");

    if (credentials())
        main_menu();
    else
        printf("Thank You for taking time to run this program");

    return 0;
}
