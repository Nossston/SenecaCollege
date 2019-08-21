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


//--------------------------------
// Structure Types
//--------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-1 Milestone-4 |
// |        structures here...                       |
// +-------------------------------------------------+
#ifndef contacts_h
#define contacts_h

struct Name {
    char firstName[31];
    char middleInitial[7];
    char lastName[36];
};

struct Address {
    int streetNumber;
    char street[41];
    int apartmentNumber;
    char postalCode[8];
    char city[41];
};

struct Numbers {
    char cell[11];
    char home[11];
    char business[11];
};

struct Contact {
    struct Name name;
    struct Address address;
    struct Numbers numbers;
};



//--------------------------------
// Function Prototypes
//--------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-1 Milestone-4 |
// |        function prototypes here...              |
// +-------------------------------------------------+

// Get and store from standard input the values for Name
// Place your code here...
void getName(struct Name *name);
// Get and store from standard input the values for Address
// Place your code here...
void getAddress(struct Address *address);
// Get and store from standard input the values for Numbers
// Place your code here...
void getNumbers(struct Numbers *numbers);

// Get and store from standard input the values for a Contact (NOT: Contacts)
// NOTE:  Make sure the structure Contact does not have an 's' on the end!
// Put function prototype below:
void getContact(struct Contact *contact);

#endif /* contacts_h */
