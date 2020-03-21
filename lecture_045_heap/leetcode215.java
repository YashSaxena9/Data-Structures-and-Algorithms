import java.util.Collections;
import java.util.PriorityQueue;

class leetcode215 {
    static PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
    public static int findKthLargest(int[] nums, int k) {
        for (int i = 0; i < nums.length; i++) {
            pq.add(nums[i]);
        }
        int ans = pq.peek();
        while (k-- != 0) {
            ans = pq.poll();
        }
        return ans;
    }

    public static void main(String[] args) {
        int[] arr = {3,2,1,5,6,4};
        System.out.println(findKthLargest(arr, 2));
    }
}