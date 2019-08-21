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

// Hint:  This header file now has functions with parameters referring to
//        the struct Contact type so be sure to include the contacts.h header:
#include "contacts.h"

//--------------------------------
// Function Prototypes
//--------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        function prototypes here...              |
// +-------------------------------------------------+

// Clear the standard input buffer
void clearKeyboard(void);
// pause:
// Put function prototype below:
void pause1(void);
// getInt:
// Put function prototype below:
int getInt(void);
// getIntInRange:
// Put function prototype below:
int getIntInRange(int min,int max);

// yes:
// Put function prototype below:
int yes(void);

// menu:
// Put function prototype below:
int menu(void);

// contactManagerSystem:
// Put function prototype below:
void contactManagerSystem(void);


// Generic function to get a ten-digit phone number:
// getTenDigitPhone:

void getTenDigitPhone(char *phoneNum);

// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[]);

// displayContactHeader:
void displayContactHeader(void);

// displayContactFooter:
void displayContactFooter(int count);

// displayContact:

void displayContact(const struct Contact *contact);
// displayContacts:

void displayContacts(const struct Contact contacts[], int size);
// searchContacts:
void searchContacts(const struct Contact contacts[], int size);

// addContact:
void addContact(struct Contact contacts[], int size);

// updateContact:
void updateContact(struct Contact contacts[], int size);

// deleteContact:
void deleteContact(struct Contact contacts[], int size);

// sortContacts:
void sortContacts(struct Contact contacts[], int size);
