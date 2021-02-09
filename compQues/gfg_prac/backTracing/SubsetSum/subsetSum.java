//  coin change problem
//  target sum

/**
 * subsetSum
 */
public class subsetSum {

    public static void main(String[] args) {
        int[] arr = {2,3,5,7};
        int tar = 10;
        System.out.println(targetSum(arr, 0, tar, ""));
    }

    public static int targetSum(int[] arr, int vidx, int tar, String ans) {
        if (tar == 0) {
            System.out.println(ans);
            return 1;
        }
        int count = 0;
        for (int i = vidx; i < arr.length; i++) {
            if (tar - arr[i] >= 0)
            count += targetSum(arr, i + 1, tar - arr[i], ans + arr[i] + " ");
        }
        return count;
    }
}