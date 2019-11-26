import java.util.Scanner;

/**
 * towerOfHanoi
 */
public class towerOfHanoi {
	public static Scanner scn = new Scanner(System.in);
	
	public static void main(String[] args) {
		System.out.print("enter the number of disks : ");
		int disks = scn.nextInt();
		solTowerOfHanoi(disks, 'A', 'B', 'C');
	}

	public static void solTowerOfHanoi(int disk, char start, char mid, char end) {
		if (disk == 1) {
			System.out.println("move disk " + disk + " from " + start + " to " + end);
			return;
		}
		solTowerOfHanoi(disk - 1, start, end, mid);
		System.out.println("move disk " + disk + " from " + start + " to " + end);
		solTowerOfHanoi(disk - 1, mid, start, end);
	}
}