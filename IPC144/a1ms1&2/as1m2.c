/* -------------------------------------------
 Name: Yu-Che,Liu
 Student number:134379189
 Email:yliu545@myseneca.ca
 Section:SKK
 Date:3/7
 ----------------------------------------------
 Assignment: 1
 Milestone:  2
 ---------------------------------------------- */
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> // A library function always is first.

#include "contacts.h" // My stuff are always after the libraries.

int main (void)
{
    // Declare variables here:
    struct Name name = {{0}};
    struct Address address = { 0 };
    struct Numbers numbers = {{0}};
    char input;
    
    // Display the title
    printf("Contact Management System\n");
    printf("-------------------------\n");
    
    // Contact Name Input:
    printf("Please enter the contact's first name: ");
    scanf("%30[^\n]",name.firstName);
    // This [^\n] weird thing means scanf function store everything until enter is typed.
    // 30 means that this program accepts up to 30words and 1 new-line special character.
    // This logic applies to the below codes.
    
    /*
     From what we have learned, we do not know how eat overflow chars.
     However, Nick gave me a clue, it is scanf.
     This scanf can eat overflow chars once overflowing happens.
     I tested that, unfortunately, it will require users to type something if there is no overflowing.
     
     char eat[]='\0';
     scanf(" %s",eat);
     
     Or use while loop(as a function) to eat overflow words.
     This function might need regulate expression which we have not learned too much in Linux.
     
     Or simply use             fflush(stdin);

     */
    
    printf("Do you want to enter a middle initial(s)? (y or n): ");
    scanf(" %c",&input);
    // This space is intended to leave. It can eat special characters preventing from the skipping lines.
    
    switch (input)
    {        // This switch only give users one chance to enter their information.
             // Without a doubt, I can put a flag here to make sure users type the 'y''Y''n''N'.
             // However I want to keep this program simple to read, I only give user one time to type.
        case 'Y':
        case 'y':
            printf("Please enter the contact's middle initial(s): ");
            scanf(" %6[^\n]",name.middleInitial);

            break;
        case 'n':
        case 'N':
            break;
        default:
            printf("\n!!Invaild input!!\n\n");
            break;
    }
    
    printf("Please enter the contact's last name: ");
    scanf(" %35[^\n]",name.lastName);
    
    // Contact Address Input:
    printf("Please enter the contact's street number: ");
    scanf("%d",&address.streetNumber);
    printf("Please enter the contact's street name: ");
    scanf(" %40[^\n]",address.street);
    printf("Do you want to enter an apartment number? (y or n): ");
    scanf(" %c",&input);
    
    switch (input)
    {
        case 'Y':
        case 'y':
            printf("Please enter the contact's apartment number: ");
            scanf(" %d",&address.apartmentNumber);
            break;
            
        case 'n':
        case 'N':
            break;
        default:
            printf("\n!!Invaild input!!\n\n");
            break;
    }
    
    printf("Please enter the contact's postal code: ");
    scanf(" %7[^\n]",address.postalCode);
    printf("Please enter the contact's city: ");
    scanf(" %40[^\n]",address.city);
    
    // Contact Numbers Input:
    
    printf("Do you want to enter a cell phone number? (y or n): ");
    scanf(" %c",&input);
    
    switch (input)
    {
        case 'Y':
        case 'y':
            printf("Please enter the contact's cell phone number: ");
            scanf(" %10[^\n]",numbers.cell);
            break;
        case 'n':
        case 'N':
            break;
        default:
            printf("\n!!Invaild input!!\n\n");
            break;
    }

    printf("Do you want to enter a home phone number? (y or n): ");
    scanf(" %c",&input);
    switch (input)
    {
        case 'Y':
        case 'y':
            printf("Please enter the contact's home phone number: ");
            scanf(" %10[^\n]",numbers.home);
            break;
        case 'n':
        case 'N':
            break;
        default:
            printf("\n!!Invaild input!!\n\n");
            break;
    }
    
    printf("Do you want to enter a business phone number? (y or n): ");
    scanf(" %c",&input);
    switch (input)
    {
        case 'Y':
        case 'y':
            printf("Please enter the contact's business phone number: ");;
            scanf(" %10s",numbers.business);
            break;
        case 'n':
        case 'N':
            break;
        default:
            printf("\n!!Invaild input!!\n\n");
            break;
    }

    // Display Contact Summary Details
    printf("\nContact Details\n");
    printf("---------------\n");
    printf("Name Details\n");
    printf("First name: %s\n",name.firstName);
    printf("Middle initial(s): %s\n",name.middleInitial);
    printf("Last name: %s\n",name.lastName);
    
    printf("\nAddress Details\n");
    printf("Street number: %d\n",address.streetNumber);
    printf("Street name: %s\n",address.street);
    printf("Apartment: %d\n",address.apartmentNumber);
    printf("Postal code: %s\n",address.postalCode);
    printf("City: %s\n",address.city);
    
    printf("\nPhone Numbers:\n");
    printf("Cell phone number: %s\n",numbers.cell);
    printf("Home phone number: %s\n",numbers.home);
    printf("Business phone number: %s\n",numbers.business);
    // Display Completion Message
    printf("\nStructure test for Name, Address, and Numbers Done!\n");
    return 0;
}

/*  SAMPLE OUTPUT:
 Contact Management System
 -------------------------
 Please enter the contact's first name: Tom
 Do you want to enter a middle initial(s)? (y or n): y
 Please enter the contact's middle initial(s): L. A.
 Please enter the contact's last name: Wong Song
 Please enter the contact's street number: 20
 Please enter the contact's street name: Keele Street
 Do you want to enter an apartment number? (y or n): y
 Please enter the contact's apartment number: 40
 Please enter the contact's postal code: A8A 4J4
 Please enter the contact's city: North York
 Do you want to enter a cell phone number? (y or n): Y
 Please enter the contact's cell phone number: 9051116666
 Do you want to enter a home phone number? (y or n): Y
 Please enter the contact's home phone number: 7052227777
 Do you want to enter a business phone number? (y or n): Y
 Please enter the contact's business phone number: 4163338888
 */
