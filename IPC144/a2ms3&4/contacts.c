/* -------------------------------
 Name: Yu-Che, Liu
 Student number: 134379189
 Email: yliu545@myseneca.ca
 Section: SKK
 Date: 3.26
 ----------------------------------
 Assignment: 2
 Milestone:  4
 ---------------------------------- */
#include <stdio.h>


#define _CRT_SECURE_NO_WARNINGS

// +-------------------------------------------------+
// | NOTE:  Include additional header files...       |
// +-------------------------------------------------+

#include "contacts.h"
#include "contactHelpers.h"

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        source code below...                     |
// +-------------------------------------------------+

// getName:
void getName(struct Name *name)
{
    int answer,i;
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
    else
    {
        for (i = 0; i < 6; i++) {
            name->middleInitial[i] = '\0';
        }
    }
    
    
    printf("Please enter the contact's last name: ");
    scanf(" %35[^\n]",name->lastName);
};

// getAddress:
void getAddress(struct Address *address){
    int answer;
    
    printf("Please enter the contact's street number: ");
    address->streetNumber = getInt();
    while (address->streetNumber < 0)
    {
        printf("*** INVALID STREET NUMBER *** <must be a positive number>: ");
        scanf("%d",&address->streetNumber);
    }
    
    printf("Please enter the contact's street name: ");
    scanf(" %40[^\n]",address->street);
    
    
    printf("Do you want to enter an apartment number? (y or n): ");
    answer = yes();
    
    if ( answer != 0)
    {
        address->apartmentNumber = '\0';
    }
    while (answer == 1)
    {
        printf("Please enter the contact's apartment number: ");
        address->apartmentNumber = getInt();
        while (address->apartmentNumber < 0)
        {
            printf("*** INVALID APARTMENT NUMBER *** <must be a positive number>: ");
            scanf("%d",&address->apartmentNumber);
        }
        answer = 0;
    }
    
    
    printf("Please enter the contact's postal code: ");
    scanf(" %7[^\n]",address->postalCode);
    clearKeyboard();
    printf("Please enter the contact's city: ");
    scanf(" %40[^\n]",address->city);
};

// getNumbers:
void getNumbers(struct Numbers *numbers){
    
    int flag = 1, answer, i;
    
    printf("Please enter the contact's cell phone number: ");
    getTenDigitPhone(numbers->cell);
    
    
    printf("Do you want to enter a home phone number? (y or n): ");
    answer = yes();
    if (answer == 0)
    {
        for (i = 0; i<10; i++)
        {
            numbers->home[i] = '\0';
        }
    }
   while (flag)
   {
        if (answer == 1)
        {
            printf("Please enter the contact's home phone number: ");
            getTenDigitPhone(numbers->home);
            flag = 0;
        }
        else
        {
            flag = 0;
        }
    }
    
    printf("Do you want to enter a business phone number? (y or n): ");
    answer = yes();
    if ( answer == 0)
    {
        for (i = 0; i < 10; i++)
        {
            numbers->business[i] = '\0';
        }
    }
    
    flag = 1;
    while (flag)
    {
        if (answer == 1)
        {
            printf("Please enter the contact's business phone number: ");;
            getTenDigitPhone(numbers->business);
            flag = 0;
        }
        else if ( answer == 0)
            flag = 0;
    }
}

// getContact:
// Define Empty function definition below:
void getContact(struct Contact *contact)
{
   // getName(&contact->name);
    //getAddress(&contact->address);
    getNumbers(&contact->numbers);
}

