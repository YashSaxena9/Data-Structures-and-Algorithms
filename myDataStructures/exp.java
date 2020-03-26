import java.util.ArrayList;
import java.util.Arrays;

/**
 * exp
 */
public class exp {

    public static void main(String[] args) {
        // int[] arr = new int[10];
        // for (int i = 0; i < 10; i++) {
        //     arr[i] = 10 - i;
        // }
        // for (int i : arr) {
        //     System.out.println(i);
        // }
        // Arrays.sort(arr, (a, b)->
        //     (a - b)
        // );
        ArrayList<Integer> arr = new ArrayList<>();
        for (int i = 0; i < 10; i++) {
            arr.add(10 - i);
        }
        for (int i : arr) {
            System.out.print(i + " ");
        }
        Arrays.sort(arr, (a, b)->
            (a - b)
        );
    }
}