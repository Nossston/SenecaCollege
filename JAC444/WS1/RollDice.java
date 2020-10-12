package com.company;

public class RollDice {

    private static byte res ,res2,sum;
    private static boolean flag=true;

    public static void Act(){
        Roll();
        switch (sum){
            case 7,11:
                System.out.println("Congratulations, You win.");
                break;
            case 2,3,12:
                System.out.println("Craps, Better Luck Next Time, You Lose.");
                break;
            default:
                System.out.println("Point is (established) set to: "+sum);
                byte temp = sum;
                while (flag){
                    Roll();
                    if(sum == 7){
                        System.out.println("Craps, Better Luck Next Time, You Lose.");
                        flag = false;
                    }
                    else if (temp == sum){
                        System.out.println("Congratulations, You win.");
                        flag = false;
                    }
                }
        }

    }
    public static byte Roll(){
        res = (byte) ((Math.random()*6 )+1);
        res2 = (byte) ((Math.random()*6 )+1);
        sum = (byte) (res+res2);
        System.out.println("You rolled: "+res+"+"+ res2 +"="+ sum );
        return sum;
    }
}
