/**
 * Client
 */
import java.util.LinkedList;

public class Client {

    public static void main(String[] args) {
        MyHashMap map = new MyHashMap();
        map.put(999, 1000);
        map.put(998, 40);
        map.put(989, 99);
        map.put(996, 0);
        map.put(999, 1001);
        // System.out.println(map.remove(999));
        System.out.println(map.containsKey(999));
        // map.clear();
        System.out.println(map);
        System.out.println(map.keyArray().length);
        for (int k : map.keyArray()) {
            System.out.print(map.get(k) + " " + k + ", ");
        } System.out.println();
    }
}