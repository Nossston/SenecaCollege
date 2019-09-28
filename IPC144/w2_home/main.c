/*
 Name:           Liu,Yu-Che
 Student Number: 134379189
 Email:          yliu545@myseneca.ca
 Section:        SKK
 Workshop:       2 (at_home)
 */
// Start your code below:
#include <stdio.h>
int main()
{
    double M; //money
    int L; // Loonies
    int q ; // Quaters
    int dimes;
    int nickels;
    int pennies;
    double gst;
    
    printf("Please enter the amount to be paid: $");
    scanf("%lf", &M);
    gst = M * .13+ 0.005;// at the end, I couldn't find out how to set gst into const. gst= x *.13 +.005?
    M = M + gst;
    printf("GST: %.2lf\n",gst);
    printf("Balance owing: %.2lf\n",M);
    
    L = M / 1;
    M = M*100;
    M = (int)M % 100;
    M=(double)M/100;
    printf("Loonies required: %d, balance owing: %.2lf\n", L, M);
    
    q =  M / 0.25 ; // q =2
    M =  M * 100; //.68 becomes to 68=M8
    M = (int)M % 25; // 68%25= 18=M
    M = (double)M/100; //M=.18
    printf( "Quaters required: %d, balance owing: %1.2lf\n",q,M); //tried (float)M/100; not working
    
    dimes = M/0.10;
    M =  M * 100;
    M = (int)M % 10; //
    M = (double)M/100; //
    printf( "Dimes required: %d, balance owing: %.2lf\n",dimes,M);
    
    nickels = M/0.05;
    M =  M * 100; //
    M = (int)M % 5; //
    M = (double)M/100; //
    printf("Nickels required: %d, balance owing: %.2lf\n",nickels,M);
    
    pennies = M/0.01;
    M =  M * 100; //
    M = (int)M % 1; //
    M = (double)M/100; //
    printf("Pennies required: %d, balance owing: %.2lf\n",pennies,M);
    
    
    return 0;
}


