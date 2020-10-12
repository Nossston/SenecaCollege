/**********************************************
 Workshop 1
 Course:<JAC444NCC> - 4th Semester
 Last Name: Liu
 First Name: Yu-Che
 ID:134379189
 Section:NCC
 This assignment represents my own work in accordance with Seneca Academic Policy. Signature
 Date:2020/09/23
 **********************************************/

package com.company;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        System.out.println("Program starts...\n ...\n ... \n");
        MaxLocation.Act();
        System.out.println("\n\nFirst Program ends.");
        promptEnterKey();
        RollDice.Act();
    }
    public static void promptEnterKey(){
        System.out.println("Press \"ENTER\" to continue...");
        Scanner scanner = new Scanner(System.in);
        scanner.nextLine();
    }
}
