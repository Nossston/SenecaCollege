
/* -------------------------------------------
 Name: Yu-Che,Liu
 Student number:134379189
 Email:yliu545@myseneca.ca
 Section:SKK
 Date:3/13
 ----------------------------------------------
 Assignment: 1
 Milestone:  3
 ---------------------------------------------- */
#ifndef __h
#define __h

// Structure type Name declaration
struct Name {
    char firstName[31];
    char middleInitial[7];
    char lastName[36];
};

// Structure type Address declaration
// Place your code from Milestone #2 here...
struct Address {
    int streetNumber;
    char street[41];
    int apartmentNumber;
    char postalCode[8];
    char city[41];
};

// Structure type Numbers declaration
// Place your code from Milestone #2 here...
struct Numbers {
    char cell[11];
    char home[11];
    char business[11];
};

// Structure type Contact declaration
// Place your code here...

struct Contact {
    struct Name name;
    struct Address address;
    struct Numbers numbers;
};

//------------------------------------------------------
// Function Prototypes
//------------------------------------------------------

// ====== Milestone 4 =======

// Get and store from standard input the values for Name
// Place your code here...
char input;

void getName(struct Name *name){
    printf("Please enter the contact's first name: ");
    scanf("%30[^\n]",name->firstName);
    printf("Do you want to enter a middle initial(s)? (y or n): ");
    scanf(" %c",&input);
    
    switch (input)
    {
        case 'Y':
        case 'y':
            printf("Please enter the contact's middle initial(s): ");
            scanf(" %6[^\n]",name->middleInitial);
            
            break;
        case 'n':
        case 'N':
            break;
        default:
            printf("\n!!Invaild input!!\n\n");
            break;
    }
    
    printf("Please enter the contact's last name: ");
    scanf(" %35[^\n]",name->lastName);
    
};


// Get and store from standard input the values for Address
// Place your code here...
void getAddress(struct Address *address){
    printf("Please enter the contact's street number: ");
    scanf("%d",&address->streetNumber);
    printf("Please enter the contact's street name: ");
    scanf(" %40[^\n]",address->street);
    printf("Do you want to enter an apartment number? (y or n): ");
    scanf(" %c",&input);
    
    switch (input)
    {
        case 'Y':
        case 'y':
            printf("Please enter the contact's apartment number: ");
            scanf(" %d",&address->apartmentNumber);
            break;
            
        case 'n':
        case 'N':
            break;
        default:
            printf("\n!!Invaild input!!\n\n");
            break;
    }
    
    printf("Please enter the contact's postal code: ");
    scanf(" %7[^\n]",address->postalCode);
    printf("Please enter the contact's city: ");
    scanf(" %40[^\n]",address->city);
    
};

// Get and store from standard input the values for Numbers
// Place your code here...
void getNumbers(struct Numbers *numbers){
    printf("Do you want to enter a cell phone number? (y or n): ");
    scanf(" %c",&input);
    
    switch (input)
    {
        case 'Y':
        case 'y':
            printf("Please enter the contact's cell phone number: ");
            scanf(" %10[^\n]",numbers->cell);
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
            scanf(" %10[^\n]",numbers->home);
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
            scanf(" %10s",numbers->business);
            break;
        case 'n':
        case 'N':
            break;
        default:
            printf("\n!!Invaild input!!\n\n");
            break;
    }
}


#endif /* __h */
