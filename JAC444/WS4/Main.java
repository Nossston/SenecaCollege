/**********************************************
 Workshop 4
 Course:<JAC444NCC> - 4th Semester
 Last Name: Liu
 First Name: Yu-Che
 ID:134379189
 Section:NCC
 This assignment represents my own work in accordance with Seneca Academic Policy. Signature
 Date:2020/10/17
 **********************************************/

package noston;

import java.io.IOException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        boolean flag = true;
        try {
            while(flag){
                GuessGame.start();
                System.out.print("Do you want to guess another word? Enter y or n>");
                Scanner scanner = new Scanner(System.in);
                char ans =scanner.nextLine().charAt(0);
                if ( ans == 'y' || ans == 'Y' ){ }
                else if(ans == 'n' || ans == 'N') {flag=false;}
                else {
                    System.out.println("You enter neither Y or N, first task ends");
                    flag =false;
                }
            }
            GuessGame.write("hangman.txt");
        } catch (IOException e) {
            e.printStackTrace();
        }
        System.out.println("\n!!!...--------------------------------.....!!!\nSecond Programs starts :");
        ReadFile.start();  // We use 1.txt for this WS
    }
}
