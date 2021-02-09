import java.util.Scanner;               // used to import in-build scanner file to take input from console
//  import java.util.* imports all utility library files
//verified
public class simpleInterest {

    public static void main(String[] args){
        Scanner scn=new Scanner(System.in);     //  used to use Scanner util as " scn " to take input in program of every new/next variable

        // int p = 1000;
        // int r = 2;
        // int t = 3;

        //  with user input:-
        System.out.print("enter p: ");
        int p = scn.nextInt();          //  " scn.nextInt() " used to take an int type input into a variable

        System.out.print("enter r: ");
        int r = scn.nextInt();

        System.out.print("enter t: ");
        int t = scn.nextInt();
        //  end:-

        int si = (p * r * t)/100;

        System.out.println("simple interest: " + si);         // takes the cursor to next line
        System.out.print(si);                                 // doesn't take the cursor to next line
        System.out.print(si);
    }
}