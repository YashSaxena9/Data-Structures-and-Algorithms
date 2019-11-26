import java.util.Scanner;
//verified
public class largestofthree{
    public static void main(String[] args){
        Scanner scn=new Scanner(System.in);
        int a, b, c;

        System.out.print("enter a: ");
        a = scn.nextInt();
        System.out.print("enter b: ");
        b = scn.nextInt();
        System.out.print("enter c: ");
        c = scn.nextInt();
        if (a>b && b>c){
            System.out.print("largest is a:" + a);
        }
        else if (b>a && b>c){
            System.out.print("largest is b:" + b);
        }
        else{
            System.out.print("largest is c:" + c);
        }
    }
}