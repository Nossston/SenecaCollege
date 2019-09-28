/*
 Name:           Liu,Yu-Che
 Student Number: 134379189
 Email:          yliu545@myseneca.ca
 Section:        SKK
 Workshop:       5(at_home)
 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// Define Number of Employees "SIZE" to be 4
#define SIZE 4

// Declare Struct Employee
struct Employee
    {
    int id;
    int age;
    double salary;
    };

/* main program */
int main(void) {
    int scanid = 0; // This variable is to check whether the input is matched to any number in the id array or not.
    int flag = 1; // This is a flag variable.
    int option = 0;
    int i = 0;
    int storei = 0;   //This is to store i value to prevent wrong value after for-loop's change.
    int newpositioni = -1 ;// This variable is to make sure not reordering the array but marking the exact line151 after removing an id.
                            // The whole point of this variable is about after removing, this variable will be triggered to work.
                            // The reason I set -1 is to avoid mess up with 0(false) in the C language.
    
    struct Employee emp[SIZE] = {{0}};
    printf("---=== EMPLOYEE DATA ===---\n\n");
    
    do {
        
        printf("1. Display Employee Information\n");
        printf("2. Add Employee\n");
        printf("3. Update Employee Salary\n");
        printf("4. Remove Employee\n");
        printf("0. Exit\n\n");
        printf("Please select from the above options: ");
        
        scanf("%d",&option);
        printf("\n");
        
        switch (option) {
            case 0:    // Exit the program
                printf("Exiting Employee Data Program. Good Bye!!!\r");
                break;
                
            case 1: // Display Employee Data
                printf("EMP ID  EMP AGE EMP SALARY\n");
                printf("======  ======= ==========\n");
                
                storei = i; // Without this temporary storing, i will be the same value as SIZE. It will make everything mess up.
                for (i = 0; i < SIZE; i++)
                {
                    if (emp[i].id != 0)
                    {
                        printf("%6d%9d%11.2lf\n",emp[i].id,emp[i].age,emp[i].salary);
                    }
                }
                i = storei; // Make sure to store back to original value after a for-loop.
                printf("\n");
                
                break;
                
            case 2:    // Adding Employee
                
                printf("Adding Employee\n");
                printf("===============\n");
                if (i >= SIZE && newpositioni < 0 )
                    // Error message has to be the first one to check.
                    // The second condition "newpositioni < 0" is related to case4.
                    // After removing, newposition will have have a value greater than -1.
                    // The reason is to insert the new value into the right position of the array.
                {
                    printf("ERROR!!! Maximum Number of Employees Reached\n\n");
                }
                else if (newpositioni >= 0 )
                    {
                    printf("Enter Employee ID: ");
                    scanf("%d",&emp[newpositioni].id);
                        if (emp[newpositioni].id <= 0)
                        {
                            printf("Invaild ID, please enter again\n");
                            
                        }
                    printf("Enter Employee Age: ");
                    scanf("%d",&emp[newpositioni].age);
                    printf("Enter Employee Salary: ");
                    scanf("%lf",&emp[newpositioni].salary);
                    printf("\n");
                    newpositioni = -1 ; // When the user want to add the value after removing, new id will be after the last one.
                    }
                else    {
                    printf("Enter Employee ID: ");
                    scanf("%d",&emp[i].id);
                    printf("Enter Employee Age: ");
                    scanf("%d",&emp[i].age);
                    printf("Enter Employee Salary: ");
                    scanf("%lf",&emp[i].salary);
                    printf("\n");
                    i++;
                        }
                
                break;
            
            case 3:
                printf("Update Employee Salary\n");
                printf("======================\n");
                storei = i; // Without this temporary storing, i will be the same value as SIZE. It will make everything mess up.
                do {
                    printf("Enter Employee ID: ");
                    scanf("%d",&scanid);
                    
                    for (i = 0 ; i < SIZE ; i++){
                        if (emp[i].id == scanid)
                        {
                             emp[i].id = scanid;
                            printf("The current salary is %.2lf\n",emp[i].salary);
                            printf("Enter Employee New Salary: ");
                            scanf("%lf",&emp[i].salary);
                            printf("\n");
                            flag = 0;
                        }
                                                }
                    if (flag == 1) {  // To avoid an extra message showing up after successfully removing an id.
                        printf("*** ERROR: Employee ID not found! ***\n");
                                   }
                    
                    }while (flag == 1 );
                i = storei; // Store back.
                flag = 1;
                break;
                
            case 4:
                printf("Remove Employee\n");
                printf("===============\n");
                do {
                    printf("Enter Employee ID: ");
                    scanf("%d",&scanid);
                    
                    for (i = 0 ; i < SIZE ; i++)
                     {
                        if (emp[i].id == scanid)
                        {
                            printf("Employee %d will be removed\n",emp[i].id);
                            emp[i].id = 0;
                            printf("\n");
                            newpositioni = i; // Trigger
                            flag = 0;
                        }
                     }
                            if( flag == 1)
                                    {
                                printf("*** ERROR: Employee ID not found! ***\n");
                                    }
                    
                    } while (flag == 1 );
                break;

            default:
                printf("ERROR: Incorrect Option: Try Again\n\n");
        }
        
    } while (option != 0);
    return 0;
}
    
