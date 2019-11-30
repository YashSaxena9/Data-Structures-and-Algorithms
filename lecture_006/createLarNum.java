//  
public class createLarNum {
    public static void main(String[] args) {
        int[] arr = {3, 30, 34, 5, 9};
        String num = largestNum_(arr);
        System.out.println(num);;
    }

    public static void display(int[] arr) {
        for (int i : arr) {
            System.out.print(i + " ");
        }
    }

    public static String largestNum_(int[] arr) {
        int limit = 1;
        while (limit < arr.length - 1) {
            for (int i = 0; i < arr.length - limit; i++) {
                if ( isFirstLarge( arr[i], arr[i + 1])) {
                    arr[i] = arr[i] ^ arr[i + 1] ^ (arr[i + 1] = arr[i]);
                }
            }
            limit++;
        }
        String ans = "";
        for (int i : arr) {
            ans = i + ans;
        }
        return ans;
    }

    public static boolean isFirstLarge(int num1, int num2) {
        boolean flag = true;
        if (num1 == 0) {
            flag = !flag;
        }
        while (num1 != 0 && num2 != 0) {
            if (num1 % 10 > num2 % 10) {
                flag = true;
            } else if (num1 % 10 < num2 % 10) {
                flag = false;
            }
            num1 /= 10;
            num2 /= 10;
        }
        return flag;
    }
}