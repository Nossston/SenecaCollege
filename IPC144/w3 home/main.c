
 #define NUMS 4
 #include <stdio.h>
 int high=0, low=0, i=0, highestday=0, lowestday=0; //
 double daysH=0 , daysL=0 ,Totalaverage=0 ; // sum
 const int LOWEST = -41; //this is to specifiy the lower bond and declare const to avoid being modified
 const int HIGHEST = 41;
 int lowest = 41; //this is to make sure every suitable vaule can replace the initial number.
 int highest = -41;//otherwise, int Variable were set in 0; and these can make the program not working as expected.
 int main(void)
 {
 printf("---=== IPC Temperature Analyzer ===---\n");
 
 for (i = 0; i < NUMS;) { // += used in if loop to prevent endless adding i.
 printf("Enter the high value for day %d: ", i + 1);
 scanf("%d", &high);
 printf("\n");
 printf("Enter the low value for day %d: ", i + 1);
 scanf("%d", &low);
 
if ( high < HIGHEST && low >LOWEST && high > low) {  //I put && here can also prevent some huge numbers replace highest or lowest number
    i++ ;
    daysH += high;
    daysL += low;
    if (low < lowest ) {
          lowest=low ;
        lowestday = i;
    }
    if (high > highest) {
        highest  = high;
        highestday = i;
    }
}
else
printf("\nIncorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n");
printf("\n");
}
daysH /= NUMS;
daysL /= NUMS;
Totalaverage = (daysH + daysL) / 2; // 2 in my opinion is not a magic number. It is for calculating the average.
printf("The average (mean) LOW temperature was: %.2lf\n", daysL);
printf("The average (mean) HIGH temperature was: %.2lf\n", daysH);
printf("The average (mean) temperature was: %.2lf\n", Totalaverage);
printf("The highest temperature was %d, on day %d\n", highest, highestday);
printf("The lowest temperature was %d, on day %d\n", lowest, lowestday);
return 0;
}

