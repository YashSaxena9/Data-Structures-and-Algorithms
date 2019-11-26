import java.util.Scanner;
//verified
public class oddeven{
    public static void main(String[] args){
        Scanner scn=new Scanner(System.in);
        int a=scn.nextInt();
        if(a % 2 !=0){
            System.out.print(a + " is odd");
        }
        else{
            System.out.print(a + " is even");
        }
    }
}