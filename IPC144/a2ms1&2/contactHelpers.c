/* -------------------------------
 Name: Yu-Che, Liu
 Student number: 134379189
 Email: yliu545@myseneca.ca
 Section: SKK
 Date: 3.24
 ----------------------------------
 Assignment: 2
 Milestone:  2
 ---------------------------------- */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// This source file needs to "know about" the functions you prototyped
//       in the contact helper header file.
// HINT: Put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
//       #include your contactHelpers header file on the next line:
#include "contactHelpers.h"


//--------------------------------
// Function Definitions
//--------------------------------

// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 2 =======       |
// +-------------------------------------------------+
// | Put empty function definitions below...         |
// |                                                 |
// | - The clearKeyboard function is done for you    |
// +-------------------------------------------------+

// clearKeyboard:  Empty function definition
void clearKeyboard(void)
{
       while (getchar() != '\n') // This one is truly the one which can empty the buffer.
           ;
}

// pause1: Empty function definition goes here:
void pause1(void)
{
    printf("(Press Enter to Continue)");
    while (getchar() != '\n') ;
}


// getInt: Empty function definition goes here:
int getInt(void){
    int keyboard,flag = 1, rc;
    
    do
    {
        rc = scanf("%d",&keyboard);
        if (rc == 0) {
            printf("*** INVALID INTEGER *** <Please enter an integer>: ");
            clearKeyboard();
        }
        else if (getchar() != '\n'){
            printf("*** INVALID INTEGER *** <Please enter an integer>: ");
            clearKeyboard();
        }
     
        else
            flag =0;
        
    } while (flag);
    
    return keyboard;
}

// getIntInRange: Empty function definition goes here:
int getIntInRange(int min,int max) {
    int keyboard, flag = 1, rc;
    
    do
    {
        rc = scanf("%d",&keyboard);
        if (rc == 0)
        {
            printf("*** INVALID INTEGER *** <Please enter an integer>: ");
            clearKeyboard();
        }
        else if (getchar() != '\n'){
            printf("*** INVALID INTEGER *** <Please enter an integer>: ");
            clearKeyboard();
        }
        else if (keyboard >max || keyboard <min)
            printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ",min,max);
        else
            flag =0;
    } while (flag);
    
    return keyboard;
}


// yes: Empty function definition goes here:
int yes(){
    char answer;
    int flag = 1;
    do{
        scanf(" %c",&answer);
        if (getchar() != '\n')
        {
            printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
            clearKeyboard();
        }
        else
        {
            flag = 0;
        }
    } while (flag);
        
        switch (answer)
    {
        case'y':
        case'Y':
            return 1;
        case'n':
        case'N':
            return 0;
        default:
            printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
            clearKeyboard();
            break;
    }
    return 0;
}



// menu: Empty function definition goes here:
int menu(void){
    int option;
    
    printf("Contact Management System\n");
    printf("-------------------------\n");
    printf("1. Display contacts\n");
    printf("2. Add a contact\n");
    printf("3. Update a contact\n");
    printf("4. Delete a contact\n");
    printf("5. Search contacts by cell phone number\n");
    printf("6. Sort contacts by cell phone number\n");
    printf("0. Exit\n\n");
    printf("Select an option:> ");
    
    option = getIntInRange(0, 6);
    return option;
}



// contactManagerSystem: Empty function definition goes here:

void contactManagerSystem(void){
    int option, flag = 1,exitcode;

    do{
        option= menu();
        switch (option)
        {
            case 1:
                printf("\n<<< Feature 1 is unavailable >>>\n\n");
                pause1();
                break;
            case 2:
                printf("\n<<< Feature 2 is unavailable >>>\n\n");
                pause1();
                break;
            case 3:
                printf("\n<<< Feature 3 is unavailable >>>\n\n");
                pause1();
                break;
            case 4:
                printf("\n<<< Feature 4 is unavailable >>>\n\n");
                pause1();
                break;
            case 5:
                printf("\n<<< Feature 5 is unavailable >>>\n\n");
                pause1();
                break;
            case 6:
                printf("\n<<< Feature 6 is unavailable >>>\n\n");
                pause1();
                break;
            case 0:
                printf("\nExit the program? (Y)es/(N)o: ");
                exitcode = yes();
                if (exitcode == 1)
                {
                    printf("\nContact Management System: terminated");
                    flag =0;
                }
                break;
            default:
                break;
        }
        printf("\n");
        
        
    }while(flag);
    
}

