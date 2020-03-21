import java.util.ArrayList;

public class Heap {
    private ArrayList<Integer> arr;
    private boolean isMax;  //  default is false (Min heap by default)

    public Heap() {
        this.arr = new ArrayList<>();
        this.isMax = false;
    }
    
    public Heap(int size) {
        this.arr = new ArrayList<>(size);
        this.isMax = false;
    }
    
    public Heap(int size, boolean isMax) {
        this.arr = new ArrayList<>(size);
        this.isMax = isMax;         //  if isMax is true then its maxHeap
    }

    public Heap(boolean isMax) {
        this.arr = new ArrayList<>();
        this.isMax = isMax;         //  if isMax is true then its maxHeap
    }

    public Heap(int[] arr, boolean isMax) {
        this.isMax = isMax;
        createHeap(arr);
    }

    public Heap(int[] arr) {
        this.isMax = false;
        createHeap(arr);
    }
    
    private void createHeap(int[] arr) {
        this.arr = new ArrayList<>(arr.length);
        for (int i = 0; i < arr.length; i++) {
            this.arr.add(arr[i]);
        }
        for (int i = arr.length; i >= 0; i--) {
            downHeapify(i);
        }
    }

    @Override
    public String toString() {
        return toString_helper(0).toString();
    }

    private StringBuilder toString_helper(int idx) {
        if (idx >= arr.size()) {
            return new StringBuilder("");
        }
        StringBuilder str = new StringBuilder();
        int lci = 2 * idx + 1;
        int rci = 2 * idx + 2;
        str.append((lci < this.arr.size()) ? arr.get(lci) : " . " );
        str.append(" -> " + arr.get(idx) + " <- ");
        str.append((rci < this.arr.size()) ? arr.get(rci) : " . " );
        str.append("\n");
        str.append(toString_helper(lci));
        str.append(toString_helper(rci));
        return str;
    }

    private void swap(int idx1, int idx2) {
        int val1 = arr.get(idx1);
        int val2 = arr.get(idx2);
        arr.set(idx1, val2);
        arr.set(idx2, val1);
    }

    private void downHeapify(int idx) {
        int currIdx = idx;
        int lci = 2 * idx + 1;
        int rci = 2 * idx + 2;
        if (lci < arr.size() && compareTo(arr.get(lci), arr.get(currIdx)) > 0) {
            currIdx = lci;
        }
        if (rci < arr.size() && compareTo(arr.get(rci), arr.get(currIdx)) > 0) {
            currIdx = rci;
        }
        if (currIdx != idx) {
            swap(currIdx, idx);
            downHeapify(currIdx);
        }
    }

    private void upHeapify(int cidx) {
        int pidx = (cidx - 1) >> 1;
        if (pidx >= 0 && compareTo(arr.get(cidx), arr.get(pidx)) > 0) {
            swap(pidx, cidx);
            upHeapify(pidx);
        }
    }

    public void push(int data) {
        arr.add(data);
        upHeapify(arr.size() - 1);
    }

    public int pop() {
        if (arr.size() == 0) {
            System.err.println("UnderFlow, no data present");
            System.err.println("Heap is empty, cannot perform pop() operation");
            return 0;
        }
        if (arr.size() == 1) {
            return arr.remove(0);
        }
        int val = arr.get(0);
        arr.set(0, arr.remove(arr.size() - 1));
        downHeapify(0);
        return val;
    }

    public void update(int idx, int data) {
        if (idx < 0 || idx >= this.arr.size()) {
            System.err.println("Heap Index outofBound");
            return;
        }
        arr.set(idx, data);
        upHeapify(idx);
        downHeapify(idx);
    }

    public int top() {
        if (arr.size() == 0) {
            System.err.println("UnderFlow, no data present");
            System.err.println("Heap is empty, cannot perform top() operation");
            return 0;
        }
        return arr.get(0);
    }

    public int size() {
        return arr.size();
    }

    public boolean isEmpty() {
        return arr.size() == 0;
    }

    private int compareTo(int toChoose, int notToChoose) {
        if (this.isMax) {
            // return toChoose > notToChoose;   //  choose "toChoose" (maxHeap)
            return toChoose - notToChoose;    //  equivalent to above line 
        } else {
            // return toChoose < notToChoose;   //  choose "toChoose" (minHeap)
            return notToChoose - toChoose;    //  equivalent to above line 
        }
    }
}