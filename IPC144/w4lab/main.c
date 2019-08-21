/*
 Name:           Liu,Yu-Che
 Student Number: 134379189
 Email:          yliu545@myseneca.ca
 Section:        SKK
 Workshop:       4(in_lab)
 */

#include <stdio.h>
int main(){
    int i=0,num=0;
    const int MAX=10;
    const int MIN=3;
    int high[MAX],low[MAX];
    printf("---=== IPC Temperature Calculator V2.0 ===---\n");
    printf("Please enter the number of days, between %d and %d, inclusive: ",MIN,MAX);
    scanf("%d",&num );
    printf("\n");
    while (num<MIN||num>MAX){
        printf("Invalid entry, please enter a number between %d and %d, inclusive: ",MIN,MAX);
        scanf("%d",&num );
        printf("\n");
    }
    
    for (i=1; num >=MIN&&num <=MAX&&i<=num;i++) {
    printf("Day %d - High: ",i);
        scanf("%d",&high[i] );
    printf("Day %d - Low: ",i);
        scanf("%d",&low[i] );
    }
    printf("\n");
    printf("Day  Hi  Low\n");
    for (i=1;i<=num;i++){
        printf("%d%5d%6d\n",i,high[i],low[i]);
    }
    
    return 0;
}

