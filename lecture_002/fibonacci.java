//  fibonacci series

import java.util.Scanner;

public class fibonacci{
    public static void main(String[] args){
        Scanner scn=new Scanner(System.in);
        int n, next = 1, prev = 0, sum = 0;
        System.out.print("enter the n no. : ");
        n = scn.nextInt();

        if (n >= 1){
            System.out.print(prev + " ");
            if (n == 1){
                scn.close();                //  used to close Scanner util after running it
                return;
            }
        }
        
        if (n >= 2){
            System.out.print(next + " ");
            if (n == 2){
                scn.close();
                return;
            }
        }

        for (int i=3; i <= n; i++){
            sum = prev + next;
            prev = next;
            next = sum;
            System.out.print(sum + " ");
        }
        System.out.println();
        System.out.print("Nth digit is : \n" + sum);

        scn.close();
    }
}