/**
 * Client
 */
import java.util.LinkedList;

public class Client {

    public static void main(String[] args) {
        // MyHashMap map = new MyHashMap();
        // MyHashMap_generic<String, Boolean> map2 = new MyHashMap_generic<>();
        // map.put(999, 1000);
        // map.put(998, 40);
        // map.put(989, 99);
        // map.put(996, 0);
        // map.put(999, 1001);
        // // System.out.println(map.remove(999));
        // System.out.println(map.containsKey(999));
        // // map.clear();
        // System.out.println(map);
        // System.out.println(map.keyArray().length);
        // for (int k : map.keyArray()) {
        //     System.out.print(map.get(k) + " " + k + ", ");
        // } System.out.println();
        // map2.put("yash", true);
        // map2.put("abc", false);
        // System.out.println(map2);
        // System.out.println(map2.get("abc"));
        MyHashMap_generic<Integer, Integer> map3 = new MyHashMap_generic<>();
        double start= System.currentTimeMillis();
        for (int i = 150000; i >= 0; i--) {
            map3.put(i, 0);
        }
        double end = System.currentTimeMillis();
        // System.out.println(map3);
        System.out.println(end - start);
    }
}