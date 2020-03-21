public class clientHeap {
    public static void main(String[] args) {
        // Heap maxHeap = new Heap(new int[] {30, 22, 13, 7, 8, 10, 5, 6, -2, 8, -3, 9, -4});
        // System.out.println(maxHeap);
        // maxHeap.push(40);
        // System.out.println(maxHeap);
        // maxHeap.pop();
        // System.out.println(maxHeap);
        // maxHeap.update(maxHeap.size() - 1, 40);
        // System.out.println(maxHeap);
        // System.out.println(maxHeap.size());
        // System.out.println(maxHeap.isEmpty());
        int j = 999;
        System.out.println(j);
        
        HeapUsingArray maxHeap = new HeapUsingArray(new int[] {30, 22, 13, 7, 8, 10, 5, 6, -2, 8, -3, 9, -4});
        System.out.println(maxHeap);
        maxHeap.push(40);
        System.out.println(maxHeap);
        maxHeap.pop();
        System.out.println(maxHeap);
        maxHeap.update(maxHeap.size() - 1, 40);
        System.out.println(maxHeap);
        System.out.println(maxHeap.size());
        System.out.println(maxHeap.isEmpty());
    }
    
}