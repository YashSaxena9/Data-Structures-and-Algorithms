/**
 * client
 */
public class client {

    public static void main(String[] args) {
        // Stack st = new Stack(5);
        // st.push(10);
        // st.push(20);
        // st.push(30);
        // st.push(40);
        // st.push(50);
        // // st.push(60);
        // System.out.println(st);
        // System.out.println(st);
        solve();
    }

    public static void solve() {
        // int[] arr1 = {4, 5, 2, 25};
        // int[] arr2 = {2,1,3,8,7,5,4,6,13,9};
        // nextGreaterRight(arr2);
        // nextGreaterLeft(arr2);
        // nextLesserRight(arr2);
        // nextLesserLeft(arr2);
        Solution sol = new Solution();
        for (int d : sol.asteroidCollision(new int[] {-2, -1, 1, 2})) {
            System.out.print(d + " ");
        }
    }

    public static void nextGreaterRight(int[] arr) {
        Stack st = new Stack();
        for (int i = 0; i < arr.length; i++) {
            if (st.size() == 0) {
                st.push(arr[i]);
                continue;
            }
            while (st.size() != 0 && st.top() < arr[i]) {
                System.out.println(st.pop() + " -> " + arr[i]);
            }
            st.push(arr[i]);
        }
        while (st.size() != 0) {
            System.out.println(st.pop() + " -> null");
        }
        System.out.println();
    }

    public static void nextGreaterLeft(int[] arr) {
        Stack st = new Stack();
        for (int i = arr.length - 1; i >= 0; i--) {
            if (st.size() == 0) {
                st.push(arr[i]);
                continue;
            }
            while (st.size() != 0 && st.top() < arr[i]) {
                System.out.println(st.pop() + " -> " + arr[i]);
            }
            st.push(arr[i]);
        }
        while (st.size() != 0) {
            System.out.println(st.pop() + " -> null");
        }
        System.out.println();
    }
    
    public static void nextLesserRight(int[] arr) {
        Stack st = new Stack();
        for (int i = 0; i < arr.length; i++) {
            if (st.size() == 0) {
                st.push(arr[i]);
                continue;
            }
            while (st.size() != 0 && st.top() > arr[i]) {
                System.out.println(st.pop() + " -> " + arr[i]);
            }
            st.push(arr[i]);
        }
        while (st.size() != 0) {
            System.out.println(st.pop() + " -> null");
        }
        System.out.println();
    }
    
    public static void nextLesserLeft(int[] arr) {
        Stack st = new Stack();
        for (int i = arr.length - 1; i >= 0; i--) {
            if (st.size() == 0) {
                st.push(arr[i]);
                continue;
            }
            while (st.size() != 0 && st.top() > arr[i]) {
                System.out.println(st.pop() + " -> " + arr[i]);
            }
            st.push(arr[i]);
        }
        while (st.size() != 0) {
            System.out.println(st.pop() + " -> null");
        }
        System.out.println();
    }

    static class Solution {
        Stack st = new Stack();
        public int[] asteroidCollision(int[] arr) {
            for (int i = 0; i < arr.length; i++) {
                if (arr[i] > 0) {
                    st.push(arr[i]);
                } else {
                    while (st.size() != 0 && st.top() > 0 && st.top() < -arr[i]) {
                        st.pop();
                    }
                    if (st.size() != 0 && st.top() == -arr[i]) {
                        st.pop();
                    } 
                    else if (st.size() == 0 || arr[i] < 0) {
                        st.push(arr[i]);
                    }
                }
            }
            int[] ans = new int[st.size()];
            for (int i = ans.length - 1; i >= 0; i--) {
                ans[i] = st.pop();
            }
            return ans;
        }
    }
}