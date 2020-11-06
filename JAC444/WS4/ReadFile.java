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
import java.io.*;
import java.util.Scanner;
// idea from: https://stackoverflow.com/questions/27195932/count-all-occurrences-of-a-character-in-a-file

public class ReadFile {
    final static int CHAR_QUANTITY = 'z' - 'a'+1 ;
    private static int[] Low_arrOfnumber = new int[CHAR_QUANTITY];
    private static int[] Cap_arrOfnumber = new int[CHAR_QUANTITY];
    public static int low_start= 'a';
    public static int cap_start= 'A';

    public static void count(String input){
        StringBuilder temp = new StringBuilder(input);
        for (int j = 0; j < CHAR_QUANTITY; j++ ){
            for (int i =0 ; i < temp.length();i++ ){
                if ( temp.charAt(i)==  (char)low_start ){ // check the letter is matching to a for first int j loop
                    Low_arrOfnumber[j]++ ;
                }
            }
            System.out.println( "Number of "+(char)low_start + "'s: " + Low_arrOfnumber[j] );
            low_start++;
        }
        for (int j = 0; j < CHAR_QUANTITY; j++ ){
            for (int i =0 ; i < temp.length();i++ ){
                if ( temp.charAt(i)==  (char)cap_start ){
                    Cap_arrOfnumber[j]++ ;
                }
            }
            System.out.println( "Number of "+(char)cap_start + "'s: " + Cap_arrOfnumber[j] );
            cap_start++;
        }

    }

    static void start(){
        String data = "";
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter a file name to count alphabetic times: ");
        String filename = scan.nextLine();
        try {
            File myObj = new File(filename);
            Scanner myReader = new Scanner(myObj);
            while (myReader.hasNextLine()) {
                data += myReader.nextLine();
            }
            count(data);
            myReader.close();
        } catch (FileNotFoundException e) {
            System.out.println("An error occurred. This location doesn't have the file");
            e.printStackTrace();
        }
    }

}



