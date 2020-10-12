package com.company;

import java.util.Scanner;

public class MaxLocation {
    private static byte rowlocation;
    private static byte collocation ;
    private static float maxValue=0;

    public static void Act(){
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the number of rows in the array:");
        byte row = scanner.nextByte();
        System.out.print("Enter the number of columns in the array:");
        byte col = scanner.nextByte();
        for(byte i = 0; i< row; i++){
            for (byte j = 0; j< col; j++){
                System.out.print("Please enter the " + (j+1) + "th number in the "+ (i+1) +"th row: " );
                float tempo = scanner.nextFloat();
                if (tempo > maxValue){ // binary operator is not clear in here
                    maxValue= tempo;
                    rowlocation = j; // the example's location sets the first row and col as 0
                    collocation = i;
                }
            }
        }
        System.out.print("The largest value in the array is: " +maxValue+
                " the location of it is at the (row,col) :(" + collocation+","+rowlocation+")"   );
    }
}
