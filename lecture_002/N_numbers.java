import java.util.Scanner;

public class N_numbers{
	public static void main(String[] args){
		Scanner scn=new Scanner(System.in);
		System.out.print("enter the Nth number: ");
		int n = scn.nextInt();
		//  for loop 
    	for(int i = 1; i <= n; i++){            //  here int i has scope upto end of the loop, not beyond that
        	System.out.println(i);
    	}
    	//  end of for loop
	}
}