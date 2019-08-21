/*
 Name:           Liu,Yu-Che
 Student Number: 134379189
 Email:          yliu545@myseneca.ca
 Section:        SKK
 Workshop:       5(in_lab)
 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// Define Number of Employees "SIZE" to be 2
#define SIZE 2

// Declare Struct Employee
struct Employee {
    int id;
    int age;
    double salary;
};

/* main program */
int main(void) {
    
    int option = 0;
    int i=0;
    // Declare a struct Employee array "emp" with SIZE elements
    // and initialize all elements to zero
    struct Employee emp[SIZE] = {{0}};
    printf("---=== EMPLOYEE DATA ===---\n\n");
    
    do {
        printf("1. Display Employee Information\n");
        printf("2. Add Employee\n");
        printf("0. Exit\n\n");
        printf("Please select from the above options: ");
        
        scanf("%d",&option);
        printf("\n");
        
        switch (option) {
            case 0:    // Exit the program
                printf("Exiting Employee Data Program. Good Bye!!!");
                
                break;
            case 1: // Display Employee Data
                // @IN-LAB
                
                printf("EMP ID  EMP AGE EMP SALARY\n");
                printf("======  ======= ==========\n");
                
                // Use "%6d%9d%11.2lf" formatting in a
                
                
                for (i=0; i<SIZE; i++)
                {
                    if (emp[i].id != 0)
                    {
                        printf("%6d%9d%11.2lf\n",emp[i].id,emp[i].age,emp[i].salary);
                        
                    }
                    
                }
                printf("\n");
                
                // printf statement to display
                // employee id, age and salary of
                // all  employees using a loop construct
                
                // The loop construct will be run for SIZE times
                // and will only display Employee data
                // where the EmployeeID is > 0
                
                break;
            case 2:    // Adding Employee
                // @IN-LAB
                
                printf("Adding Employee\n");
                printf("===============\n");
                if (i >= SIZE)
                {
                    printf("ERROR!!! Maximum Number of Employees Reached\n\n");
                }
                else{
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
            default:
                printf("ERROR: Incorrect Option: Try Again\n\n");
        }
        
    } while (option != 0);
    
    
    return 0;
}

