/* -------------------------------
 Name: Yu-Che, Liu
 Student number: 134379189
 Email: yliu545@myseneca.ca
 Section: SKK
 Date: 3.28
 ----------------------------------
 Assignment: 2
 Milestone:  4
 ---------------------------------- */
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
// This source file needs to "know about" the SYSTEM string library functions.
// HINT: The library name is string.h.
//       #include the string.h header file on the next line:

#include <string.h>
// -------------------------------
// Include your contactHelpers header file on the next line:

#include "contactHelpers.h"


// -------------------------------
// define MAXCONTACTS for sizing contacts array (5):

#define MAXCONTACTS 5

//--------------------------------
// Function Definitions
//--------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        function definitions below...            |
// +-------------------------------------------------+

// clearKeyboard:  Empty function definition
void clearKeyboard(void)
{
    while (getchar() != '\n') // This one is truly the one which can empty the buffer.
        ;
}

// pause: Empty function definition goes here:
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
    do
    {
        scanf(" %c",&answer);
        if (getchar() != '\n')
        {
            printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
            clearKeyboard();
        }
        else
        {
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
                    break;
            }
        }
    } while (flag);

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
    
    struct Contact contacts[MAXCONTACTS] =
        { { {"Rick",{ '\0' },"Grimes" } ,{ 11,"Trailer Park",0, "A7A 2J2", "King City" } ,{ "4161112222", "4162223333", "4163334444" } } ,
        { { "Maggie","R.", "Greene" } ,{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" } ,{ "9051112222", "9052223333", "9053334444" } } ,
        { { "Morgan", "A.", "Jones" } ,{ 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" } ,{ "7051112222", "7052223333", "7053334444" } } ,
        { { "Sasha",{ '\0' }, "Williams" },{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },{ "9052223333", "9052223333", "9054445555" } }, };
    
    int option, flag = 1,exitcode;
    
    do{
        option= menu();
        printf("\n");

        switch (option)
        {
            case 1:
                displayContacts(contacts, MAXCONTACTS);
                pause1();
                break;
            case 2:
                addContact(contacts, MAXCONTACTS);
                pause1();
                break;
            case 3:
                updateContact(contacts, MAXCONTACTS);
                pause1();
                break;
            case 4:
                deleteContact(contacts, MAXCONTACTS);
                pause1();
                break;
            case 5:
                searchContacts(contacts, MAXCONTACTS);
                pause1();
                break;
            case 6:
                sortContacts(contacts, MAXCONTACTS);
                flag = 1;
                pause1();
                break;
            case 0:
                printf("Exit the program? (Y)es/(N)o: ");
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



// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        empty function definitions below...      |
// +-------------------------------------------------+
// Generic function to get a ten-digit phone number:
// getTenDigitPhone:

void getTenDigitPhone(char* phoneNum)
{
    int i = 0;
    scanf(" %[^\n]s",phoneNum);
    clearKeyboard();
    for ( i = 0 ; i < 10 ; i++ )
    {
        while (phoneNum[i] < '0' || phoneNum[i] > '9' || strlen(phoneNum) != 10)
        {
            printf("Enter a 10-digit phone number: ");
            scanf(" %[^\n]s",phoneNum);
            i = 0;
            clearKeyboard();
        }
    }
    
};

// findContactIndex:
int findContactIndex(const struct Contact* contacts, int size, const char *cellNum)
{
    int result= -1, i = 0;
    for ( i = 0; i < size; i++)
    {
        if ( strcmp(contacts[i].numbers.cell, cellNum) == 0)
            result = i;
    }
    return result;
};
// displayContactHeader:
void displayContactHeader(void)
{
    printf("+-----------------------------------------------------------------------------+\n");
    printf("|                              Contacts Listing                               |\n");
    printf("+-----------------------------------------------------------------------------+\n");
};
// displayContactFooter:
void displayContactFooter(int count)
{
    printf("+-----------------------------------------------------------------------------+\n");
    printf("Total contacts: %d\n\n",count);
}
// displayContact:
void displayContact(const struct Contact *contact)
{
    if ( (*contact).name.middleInitial[0] == '\0')
        printf(" %s %s\n",(*contact).name.firstName,(*contact).name.lastName);
    else
        printf(" %s %s %s\n",(*contact).name.firstName,(*contact).name.middleInitial,(*contact).name.lastName);
        printf("    C: %-10s   H: %-10s   B: %-10s\n",(*contact).numbers.cell,(*contact).numbers.home,(*contact).numbers.business);
        printf("       %d %s, ",(*contact).address.streetNumber,(*contact).address.street);

    if ((*contact).address.apartmentNumber >0)
    {
        printf("Apt# %d, ",(*contact).address.apartmentNumber);
    }
        printf("%s, %s\n",(*contact).address.city,(*contact).address.postalCode);
};
// displayContacts:
void displayContacts(const struct Contact *contacts, int size)
{
    int count = 0, i = 0;
    displayContactHeader();
    
    for (i = 0; i < size; i++)
    {
        if (strlen(contacts[i].numbers.cell) > 0)
        {
            displayContact(&contacts[i]);
            count++;
        }
    }
    displayContactFooter(count);
};
// searchContacts:
void searchContacts(const struct Contact contacts[], int size)
{
    int position = 0;
    char phoneNum[11]= {'\0'};
    printf("Enter the cell number for the contact: ");
    getTenDigitPhone(phoneNum);
    position = findContactIndex(contacts, size , phoneNum);
   
    if (position != -1 )
    {
        printf("\n");

        displayContact(&contacts[position]);
        printf("\n");
    }
    else
        printf("*** Contact NOT FOUND ***\n\n");
    
};

// addContact:
void addContact(struct Contact contacts[], int size)
{
    int position = -1, i = 0;
    for (i = 0 ; i < size; i++)
    {
        if (strlen(contacts[i].numbers.cell) == 0)
            position = i;
    }
    if (position == -1)
    {
        printf("*** ERROR: The contact list is full! ***\n\n");
    }
    else
    {
        getContact(&contacts[position]);
        printf("--- New contact added! ---\n\n");
        
    }
};

// updateContact:
void updateContact(struct Contact contacts[], int size)
{
    int position = 0, choice = 0;
    char phoneNum[11]= {'\0'};
    printf("Enter the cell number for the contact: ");
    getTenDigitPhone(phoneNum);
    
    position = findContactIndex(contacts, size, phoneNum);
    if (position != -1)
    {
        printf("\nContact found:\n");
        displayContact(&contacts[position]);
        
        printf("\nDo you want to update the name? (y or n): ");
        choice = yes();
        if (choice == 1)
            getName(&contacts[position].name);
        
        printf("Do you want to update the address? (y or n): ");
        choice = yes();
        if (choice == 1)
        {
            getAddress(&contacts[position].address);
        }
        
        printf("Do you want to update the numbers? (y or n): ");
        choice = yes();
        if (choice == 1)
        {
            getNumbers(&contacts[position].numbers);
        }
        
        printf("--- Contact Updated! ---\n\n");
        
    }
    else
        printf("*** Contact NOT FOUND ***\n\n");
};

// deleteContact:
void deleteContact(struct Contact contacts[], int size)
{
    char phoneNum[11]= {'\0'};
    int position = 0, choice = 0;
    printf("Enter the cell number for the contact: ");
    getTenDigitPhone(phoneNum);
    
    position = findContactIndex(contacts, size, phoneNum);
    if (position == -1)
        printf("*** Contact NOT FOUND ***\n\n");
    else
    {
        printf("\nContact found:\n");
        displayContact(&contacts[position]);
        printf("\nCONFIRM: Delete this contact? (y or n): ");
        choice = yes();
        if (choice == 1)
        {
            *contacts[position].numbers.cell = '\0';
            *contacts[position].numbers.home = '\0';
            printf("--- Contact deleted! ---\n");
        }
    }
    printf("\n");
};

// sortContacts:
void sortContacts(struct Contact contacts[], int size)
{
    int i, j ;
    struct Contact temp = { {{'\0'}},{0},{{'\0'}} };
    
    for (i = 0; i < (size-1); i++)
    {
        for (j = 0; j < (i+1); j++)
        {
            if ( strcmp(contacts[j].numbers.cell,contacts[j+1].numbers.cell) > 0 )
            {
                temp = contacts[j] ;
                contacts[j] = contacts[j+1];
                contacts[j+1] = temp ;
            }
        }
    }
    printf("--- Contacts sorted! ---\n\n");
    };

