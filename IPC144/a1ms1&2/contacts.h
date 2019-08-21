/* -------------------------------------------
 Name: Yu-Che,Liu
 Student number:134379189
 Email:yliu545@myseneca.ca
 Section:SKK
 Date:3/7
 ----------------------------------------------
 Assignment: 1
 Milestone:  1
 ---------------------------------------------- */

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
