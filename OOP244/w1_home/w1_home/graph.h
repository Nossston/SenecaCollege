/* -------------------------------------------
 Name: Yu-Che,Liu
 Student number:134379189
 Email:yliu545@myseneca.ca
 Section:SCC
 Date:5/12
 ---------------------------------------------- */

#ifndef Graph_h
#define Graph_h

#include "tools.h"

// Maximum number of samples in an graph
#define MAX_NO_OF_SAMPLES 20

namespace sict {
    
    // Prints a graph comparing the sample values visually
    void printGraph(int samples[], int noOfSamples);

    // Fills the samples array with the statistic samples
    void getSamples(int samples[], int noOfSamples);
    
    // Finds the largest sample in the samples array, if it is larger than 70,
    // therwise it will return 70.
    int findMax(int samples[], int noOfSamples);
    
    // Prints a scaled bar relevant to the maximum value in samples array
    void printBar(int val, int max);
    
}
#endif /* Graph_h */
