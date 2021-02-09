//  read total no. of digits and also rotate the number according to give rotation count of digits

//  e.g. =  if number = 235168932
//  rotation = 3, -3, 81
//  respective output = 168932235, 932235168, (after 9 rotaions to complete 81 digits) 235168932

import java.util.Scanner;

public class ques1{
    public static void main(String[] args){
        Scanner scn=new Scanner(System.in);
        int num;
        System.out.print("enter the number: ");
        num = scn.nextInt();
        
        //  length of the number
        int digits = 0, n = num;
        while (n!=0){
            digits++;
            n /= 10;
        }
        System.out.println("total no. of sigits in number are " + digits);
        //  end of counting


        //  rotation
        int rotate;
        System.out.print("enter r: ");
        rotate = scn.nextInt();
        rotate %= digits;                   //  in case we have more rotation than digits then we can eliminate rotation by digits count
        if (rotate < 0){
            rotate += digits;
        }           //  alternative ==>   rotate += (rotate<0)? digits: 0;


        //  creating 10 to power number
        int multi = 1, div = 1;
        for (int i =1; i <= digits; i++){
            if (i<=rotate){
                multi *= 10;
            }
            else{
                div *= 10;
            }
        }
        //  end of pow10 creation


        int rem = num % div;
        int leftout = num / div;
        int ans = rem*multi + leftout;
        System.out.println("answer is : " + ans);
    }
}