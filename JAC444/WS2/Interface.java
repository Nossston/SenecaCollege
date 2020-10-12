/**********************************************
 Workshop 2
 Course:<JAC444NCC> - 4th Semester
 Last Name: Liu
 First Name: Yu-Che
 ID:134379189
 Section:NCC
 This assignment represents my own work in accordance with Seneca Academic Policy. Signature
 Date:2020/10/02
 **********************************************/
package com.company;

import java.util.Arrays;
import java.util.Scanner;

public class Interface {
    private static final int  INTERVAL  = 1000;

    public static void display(){
        System.out.println("**************** Seneca Workshop 2 **********" );
        System.out.println("1: Compute personal income Tax" );
        System.out.println("2: Print the tax tables for taxable incomes (with range)");
        System.out.println("3 :Exit");
        boolean flag = true;
     while (flag) {
         System.out.printf("Please enter your choice: ") ;
         Scanner scanner = new Scanner(System.in);
         byte choice = scanner.nextByte();

        switch (choice) {
            case 1:
                printComputerTax();
                System.out.println("\nProgram ends");
                flag = false;
                break;
            case 2:
                printTaxTables();
                System.out.println("\nProgram ends");
                flag = false;
                break;
            case 3:
                System.out.println("\nProgram ends");
                flag = false;
                break;
            default:
                System.out.println("You are only to enter 1 or 2 or 3");
                break;
        }
     }
    }

    public static void printComputerTax(){
        Scanner scanner = new Scanner(System.in);
        System.out.println("\n\n0 - single filer");
        System.out.println("1 - married jointly or qualifying widow(er)");
        System.out.println("2 - married separately");
        System.out.println("3 - head of household");
        System.out.printf("Enter the filing status: ");
        IncomeTax.setFilingStatus( scanner.nextByte());
        System.out.printf("Enter the Taxable Income: $");
        IncomeTax.setTaxableIncome(scanner.nextDouble());
        System.out.println("Tax is:   $"+ IncomeTax.getTaxableIncome(IncomeTax.getTaxableIncome(),IncomeTax.getFilingStatus() ) );
    }

    public static double computerTax(){
        double tax=0;
        //double tax = ( IncomeTax.getTaxableIncome() * IncomeTax.getRates() );
        return tax;
    }

    public static void printTaxTables(){
        boolean flag = true;
        while (flag){
            Scanner scanner = new Scanner(System.in);
            System.out.printf("Enter the amount From: $");
            IncomeTax.setStart_taxableIncome(scanner.nextDouble()) ;
            System.out.printf("Enter the amount To:   $");
            IncomeTax.setEnd_taxableIncome(scanner.nextDouble());
            if ( IncomeTax.getStart_taxableIncome() < INTERVAL || IncomeTax.getEnd_taxableIncome() < INTERVAL ){
                System.out.println("Please enter numbers both above $1000");
            }else if(IncomeTax.getEnd_taxableIncome() < IncomeTax.getStart_taxableIncome() ){
                System.out.println("Please enter larger number for second amount!");
            }
            else{
                flag=false;
            }
        }

        IncomeTax.getTables();
    }
}
