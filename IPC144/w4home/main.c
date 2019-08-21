/*
 Name:           Liu,Yu-Che
 Student Number: 134379189
 Email:          yliu545@myseneca.ca
 Section:        SKK
 Workshop:       4(at_home)
 */

#include <stdio.h>
#define MAX 10
#define MIN 3
int main() {
    
    int i = 0, num = 0, highest = -1999, lowest = 1999, dayH = 0, dayL = 0, key = 0, sum = 0,  rangeend = 0;
    int rangestart = 1;
    int high[MAX], low[MAX];
    
    printf("---=== IPC Temperature Calculator V2.0 ===---\n");
    printf("Please enter the number of days, between %d and %d, inclusive: ", MIN, MAX);
    scanf("%d", &num);
    printf("\n");
    while (num < MIN || num > MAX)
    {
        printf("Invalid entry, please enter a number between %d and %d, inclusive: ", MIN, MAX);
        scanf("%d", &num);
        printf("\n");
    }
    
    for (i = 0; num >= MIN && num <= MAX && i < num; i++)
    {
        printf("Day %d - High: ", i+1);
        scanf("%d", &high[i]);
        printf("Day %d - Low: ", i+1);
        scanf("%d", &low[i]);
        
        if (highest < high[i]) { //-1999<2
            highest = high[i]; // highest=2
            dayH = i; //
        }
        if (lowest > low[i]) {
            lowest = low[i];
            dayL = i;
        }
    }
    printf("\n");
    printf("Day  Hi  Low\n");
    for (i = 0; i < num; i++)
    {
        printf("%d%5d%6d\n", i+1, high[i], low[i]);
    }
    printf("\nThe highest temperature was %d, on day %d\n", highest, dayH);
    printf("The lowest temperature was %d, on day %d\n", lowest, dayL);
   
    rangeend = i;
    
    while (1) //  everything except 0, means true
    {
        sum = 0;
        printf("\nEnter a number between %d and %d to see the average temperature for the entered number of days, enter a negative number to exit: ", rangestart, rangeend);
        scanf("%d", &key);
        
        if (key < 0)
        {
            printf("\nGoodbye!\n");
            return 0;
        }
        
        while (key > rangeend || key < rangestart) //
        {
            printf("\nInvalid entry, please enter a number between %d and %d, inclusive: ", rangestart, rangeend);
            scanf("%d", &key);
            if (key < 0)
            {
                printf("\nGoodbye!\n");
                return 0;
            }
            
            
        }

        for (i = 0;i < key && key>0 ;i++)
        {
            sum += high[i];
            sum += low[i];
        }
        printf("\nThe average temperature up to day %d is: %.2lf\n", key, (double)sum / (key * 2));
        
    }
    
    return 0;
}
