/*
 Name:           Liu,Yu-Che
 Student Number: 134379189
 Email:          yliu545@myseneca.ca
 Section:        SKK
 Workshop:       3(in_lab)
 */
#define NUMS 3
#include <stdio.h>
int high,low  ;
int i=0 ;
int main   ()
{
    printf("---=== IPC Temperature Analyzer ===---\n");
    
    
         do {
            printf("Enter the high value for day %d:",i+1);
            scanf("%d",&high );
            printf("Enter the low value for day %d:",i+1);
            scanf("%d",&low);
            
            if (high>=41 || low <= -41 || high<low){
                printf("Incorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n");
                
            }
            
            else
                i++ ;
         }while (i < NUMS);
        return 0;
    
}
