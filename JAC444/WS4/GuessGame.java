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
import java.util.*;

public class GuessGame {
    private static ArrayList<String> lines =new ArrayList<>() ;
    private static String answer  ;

    public static void start() throws IOException {
        read("hangman.txt");
        setAnswer();
        System.out.println(getAnswer()); // testing
        guess();
    }

    public static void setAnswer(){
        int target= (int) ( (Math.random()* (lines.size())  ) );
        answer = lines.get(target);
    }

    private static String getAnswer(){
        return answer;
    }

    public static void read(String filename)  {
        try {
            File myObj = new File(filename);
            Scanner myReader = new Scanner(myObj);
            while (myReader.hasNextLine()) {
                String data = myReader.nextLine();
                lines.add(data);
            }
            myReader.close();
         } catch (FileNotFoundException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }
    }
    public static void guess(){
        int count = 0;
        char yourGuess;
        String temp="";
        boolean flag = true;
        for (int i = 0; i<getAnswer().length();i++){
            temp += '*'; // movement
        }
        StringBuilder correct = new StringBuilder(temp);

        while ( flag) {
            boolean stop = false;
            String temp_ans = getAnswer();
            System.out.print("(Guess) Enter A letter in word " + correct + ": ");
            Scanner scanner = new Scanner(System.in);
            yourGuess = scanner.nextLine().charAt(0);
            for (int i = 0; i < getAnswer().length()  ; i++) {
                if( yourGuess == correct.charAt(i)){
                    System.out.println( yourGuess+ " is already in the word.");
                    stop =true;
                }
                else if (yourGuess == temp_ans.charAt(i) ) {
                    correct.setCharAt(i, yourGuess);
                    temp_ans.replace( temp_ans.charAt(i),yourGuess );
                    stop = true;
                    System.out.println("You got the letter["+yourGuess+"] at the position "+ (i+1));
                }
                if (!correct.toString().contains("*")) {
                    flag = false;
                }
            }

            if ( temp.contains( Character.toString(yourGuess)) &&!stop && count>0 ){
                System.out.println("You have guessed this letter:" + yourGuess + " before, please try a new one.");
                stop = true;

            }
            if( !stop  ){
                System.out.println( yourGuess + " is not in the word");
                count++;
                temp += yourGuess;
            }
            System.out.println("Missed count:  "+count);
        } // while ends

        System.out.println("You Got it!!\n The word is: "+getAnswer()+". You missed "+ count+ " time(s)");
    }

    public static void write(String filename) throws IOException {
        System.out.printf("\nEnter a new word to be added in the memory> ");
        Scanner scanner = new Scanner(System.in);
        String newWord = scanner.nextLine();
        System.out.println(newWord);
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(filename, true));
        bufferedWriter.append("\n"+ newWord);
        bufferedWriter.close();
    }

}
