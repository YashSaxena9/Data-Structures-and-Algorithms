import java.util.ArrayList;
import java.util.Comparator;
import java.util.Arrays;

/**
 * exp
 */
public class exp {

    public static void main(String[] args) {
        Integer[] arr = new Integer[10];
        for (int i = 0; i < 10; i++) {
            arr[i] = 10 - i;
        }
        for (int i : arr) {
            System.out.print(i + " ");
        }System.out.println();
        Arrays.sort(arr, (Integer a, Integer b)->(int) (a - b));;
        for (int i : arr) {
            System.out.print(i + " ");
        }
    }
}