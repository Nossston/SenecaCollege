/* -------------------------------
 Name: Yu-Che, Liu
 Student number: 134379189
 Email: yliu545@myseneca.ca
 Section: SKK
 Date: 3.24
 ----------------------------------
 Assignment: 2
 Milestone:  1
 ---------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "contacts.h"
#include "contactHelpers.h"
// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:


// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-1 Milestone-4 |
// |        function definitions below...            |
// +-------------------------------------------------+

// getName:
void getName(struct Name *name){
    int answer;
    printf("Please enter the contact's first name: ");
    scanf("%30[^\n]",name->firstName);
    printf("Do you want to enter a middle initial(s)? (y or n): ");
    answer = yes();
    
    if ( answer == 1)
    {
        printf("Please enter the contact's middle initial(s): ");
        scanf(" %6[^\n]",name->middleInitial);
        clearKeyboard();
    }
    
    
    printf("Please enter the contact's last name: ");
    scanf(" %35[^\n]",name->lastName);
};

// getAddress:
void getAddress(struct Address *address){
    int flag = 1, answer;

    
    printf("Please enter the contact's street number: ");
    address->streetNumber  =  getInt();

    printf("Please enter the contact's street name: ");
    scanf(" %40[^\n]",address->street);
    while (address->streetNumber < 0)
    {
        printf("*** INVALID STREET NUMBER *** <must be a positive number>: ");
        scanf("%d",&address->streetNumber);
    }
    
    printf("Do you want to enter an apartment number? (y or n): ");
    answer = yes();
    
    while (answer == 1)
    {
        printf("Please enter the contact's apartment number: ");
        address->apartmentNumber = getInt();
        while (address->apartmentNumber < 0)
        {
            printf("*** INVALID APARTMENT NUMBER *** <must be a positive number>: ");
            scanf("%d",&address->apartmentNumber);
        }
    }
    //while( address->apartmentNumber>0)
    

    flag = 1;

    printf("Please enter the contact's postal code: ");
    scanf(" %7[^\n]",address->postalCode);
    clearKeyboard();
    printf("Please enter the contact's city: ");
    scanf(" %40[^\n]",address->city);
};

// getNumbers:
void getNumbers(struct Numbers *numbers){
    
    int flag = 1, answer;
    
    printf("Please enter the contact's cell phone number: ");
    scanf(" %10[^\n]",numbers->cell);
    
    
    printf("Do you want to enter a home phone number? (y or n): ");
    answer = yes();
    do
    {
        if (answer == 1)
        {
            printf("Please enter the contact's home phone number: ");
            scanf(" %10[^\n]",numbers->home);
            flag = 0;
        }
        else if ( answer == 0)
            flag = 0;
    } while (flag);
    
    printf("Do you want to enter a business phone number? (y or n): ");
    answer = yes();
    do
    {
        if (answer == 1)
        {
            printf("Please enter the contact's business phone number: ");;
            scanf(" %10s",numbers->business);
            flag = 0;
        }
        else if ( answer == 0)
            flag = 0;
    } while (flag);
}

// +-------------------------------------------+
// | ====== Assignment 2 | Milestone 1 ======= |
// +-------------------------------------------+

// getContact:
// Define Empty function definition below:
void getContact(struct Contact *contact)
{
    getName(&contact->name);
    getAddress(&contact->address);
    getNumbers(&contact->numbers);
}

