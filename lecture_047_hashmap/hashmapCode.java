import java.util.ArrayList;
import java.util.HashMap;

public class hashmapCode {
    public static void main(String[] args) {
        // findAllIndexOfChar("yashsaxena");
        // freqMapOfChar("yashsaxena");
        // printKeyValuePair();
        System.out.println(largetContinuous(new int[] {1, 2, 7, 8, 97, 98, 99, 100, 105}));
    }

    public static void findAllIndexOfChar(String str) {
        HashMap<Character, ArrayList<Integer>> myMap = new HashMap<>();
        for (int i = 0; i < str.length(); i++) {
            char ch = str.charAt(i);
            if (!myMap.containsKey(ch)) {
                myMap.put(ch, new ArrayList<>());
            }
            myMap.get(ch).add(i);
        }

        for (Character c : myMap.keySet()) {
            System.out.println(c + " -> " + myMap.get(c));
        }
    }

    public static void freqMapOfChar(String str) {
        HashMap<Character, Integer> myMap = new HashMap<>();
        for (int i = 0; i < str.length(); i++) {
            char ch = str.charAt(i);
            myMap.put(ch, myMap.getOrDefault(ch, 0) + 1);
        }
        for (Character c : myMap.keySet()) {
            System.out.println(c + " -> " + myMap.get(c));
        }
    }

    public static void printKeyValuePair() {
        HashMap<String, Integer> myMap = new HashMap<>();
        myMap.put("Germany", 200);
        myMap.put("Australia", 400);
        myMap.put("China", 800);
        myMap.put("Japan", 100);
        myMap.put("India", 300);
        myMap.put("India", 394);        //  updates
        System.out.println(myMap);
    }

    public static int largetContinuous(int[] arr) {
        HashMap<Integer, Integer> lenMap = new HashMap<>();
        lenMap.put(0, 1);
        int lastMapKey = 0;
        for (int i = 1; i < arr.length; i++) {
            if (arr[i] - 1 == arr[i - 1]) {
                lenMap.put(lastMapKey, lenMap.get(lastMapKey) + 1);
            } else {
                lenMap.put(i, 1);
                lastMapKey = i;
            }
        }
        int max = 0;
        for (int key : lenMap.keySet()) {
            max = Math.max(max, lenMap.get(key));
        }
        System.err.println(lenMap.entrySet());
        return max;
    }
}