/**
 * userClient
 */
public class userClient {

    public static void main(String[] args) {
        UserHashMap<Integer, Integer> yash = new UserHashMap<>();
        // yash.put(23, 45);
        // yash.put(45, 9521);
        // yash.put(90, 951);
        // yash.put(278, 753);
        // yash.put(11, 88);
        // yash.put(0, 33);
        // yash.put(457, 45);
        // yash.putIfAbsent(4567, 455);
        double start= System.currentTimeMillis();
        for (int i = 150000; i >= 0; i--) {
            yash.put(i, 0);
        }
        double end = System.currentTimeMillis();
        System.out.println(end - start);
        // System.out.println(yash.get(23));
        // System.out.println(yash.get(45));
        // System.out.println(yash.get(278));
        // System.out.println(yash.get(99));
        // System.out.println(yash.keyList());
        // System.out.println(yash.getOrDefault(10, 0));
        // yash.clear();
        // yash.remove(70);
        // System.out.println(yash.containsKey(70));
        // System.out.println(yash.getOrDefault(70, 70));
        // yash.putIfAbsent(70, 8);
        // System.out.println(yash.get(70));
        // System.out.println(yash.containsKey(70));
        // System.out.println(yash);
        yash.display();
        // System.out.println(yash.size());
    }

    static class myClass {
    }
}