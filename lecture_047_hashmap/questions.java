import java.util.ArrayList;
import java.util.HashMap;

/**
 * questions
 */
public class questions {
    public static void main(String[] args) {
        int[] first = {1, 1, 1, 2, 2, 3, 5};
        int[] second = {1, 1, 2, 2, 2, 3, 3, 5, 4};
        findCommonValues_noRepeat(first, second);
        findCommonValues_withRepeat(second, first);
    }

    public static void findCommonValues_noRepeat(int[] first, int[] second) {
        HashMap<Integer, Boolean> map = new HashMap<>();
        for (int i : first) {
            map.put(i, false);
        }
        for (int i : second) {
            if (map.containsKey(i)) {
                map.put(i, true);
            }
        }
        ArrayList<Integer> ans = new ArrayList<>();
        for (Integer i : map.keySet()) {
            if (map.get(i)) {
                ans.add(i);
            }
        }
        System.out.println(ans);
    }

    public static void findCommonValues_withRepeat(int[] first, int[] second) {
        HashMap<Integer, Integer> map = new HashMap<>();    //  key = number, value = freq
        for (int i : first) {
            map.put(i, map.getOrDefault(i, 0) + 1);
        }
        ArrayList<Integer> ans = new ArrayList<>();
        for (int i : second) {
            if (map.containsKey(i) && map.get(i) > 0) {
                ans.add(i);
                map.put(i, map.get(i) - 1);
            }
        }
        System.out.println(ans);
    }


}