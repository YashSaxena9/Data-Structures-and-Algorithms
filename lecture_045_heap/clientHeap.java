import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.PriorityQueue;
public class clientHeap {
    public static void main(String[] args) {
        // Heap maxHeap = new Heap(new int[] {30, 22, 13, 7, 8, 10, 5, 6, -2, 8, -3, 9, -4}, true);
        // System.out.println(maxHeap);
        // maxHeap.push(40);
        // System.out.println(maxHeap);
        // maxHeap.pop();
        // System.out.println(maxHeap);
        // maxHeap.update(maxHeap.size() - 1, 40);
        // System.out.println(maxHeap);
        // System.out.println(maxHeap.size());
        // System.out.println(maxHeap.isEmpty());
        
        // HeapUsingArray maxHeap = new HeapUsingArray(new int[] {30, 22, 13, 7, 8, 10, 5, 6, -2, 8, -3, 9, -4}, true);
        // System.out.println(maxHeap);
        // maxHeap.push(40);
        // System.out.println(maxHeap);
        // maxHeap.pop();
        // System.out.println(maxHeap);
        // maxHeap.update(maxHeap.size() - 1, 40);
        // System.out.println(maxHeap);
        // System.out.println(maxHeap.size());
        // System.out.println(maxHeap.isEmpty());

        // Heap minHeap = new Heap(new int[] {30, 22, 13, 7, 8, 10, 5, 6, -2, 8, -3, 9, -4});
        // PriorityQueue<Integer> testPQ = new PriorityQueue<>(Arrays.asList(30, 22, 13, 7, 8, 10, 5, 6, -2, 8, -3, 9, -4));
        // System.out.println(minHeap);
        // while (!minHeap.isEmpty()) {
        //     System.out.println(minHeap.pop() + " : " + testPQ.poll());
        // }
        
        Heap maxHeap = new Heap(new int[] {30, 22, 13, 7, 8, 10, 5, 6, -2, 8, -3, 9, -4}, true);
        System.out.println(maxHeap);
        
        PriorityQueue<Integer> testPQ2 = new PriorityQueue<>(13, new Comparator<Integer>() {
            public int compare(Integer o1, Integer o2){
                return o2 - o1;
            }
        });
        testPQ2.addAll(Arrays.asList(30, 22, 13, 7, 8, 10, 5, 6, -2, 8, -3, 9, -4));
        while (!maxHeap.isEmpty()) {
            System.out.println(maxHeap.pop() + " : " + testPQ2.poll());
        }

    }
    
}