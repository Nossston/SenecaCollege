/* -------------------------------
 Name: Yu-Che, Liu
 Student number: 134379189
 Email: yliu545@myseneca.ca
 Section: SKK
 Date: 3.24
 ----------------------------------
 Assignment: 2
 Milestone:  2
 ---------------------------------------------------------------------
 Description: This header file modularizes general helper functions to
 help reduce redundant coding for common repetitive tasks.
 ---------------------------------------------------------------------*/

// HINT:
// You will most likely want to include this header file
// in other files of the project since it provides general
// helper functions that can be used throughout.


//--------------------------------
// Function Prototypes
//--------------------------------

// +-------------------------------------------+
// | ====== Assignment 2 | Milestone 1 ======= |
// +-------------------------------------------+

#ifndef contactHelpers_h
#define contactHelpers_h

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


#endif /* contactHelpers_h */
