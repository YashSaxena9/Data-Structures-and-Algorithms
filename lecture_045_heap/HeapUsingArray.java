public class HeapUsingArray {
    private int arr[];
    private int endIdx;

    public HeapUsingArray() {
        this(10);   //  deafult constructor
    }
    
    public HeapUsingArray(int size) {
        this.arr = new int[size];
        endIdx = -1;
    }

    public HeapUsingArray(int[] heapArr) {
        this.arr = new int[heapArr.length];
        int i = 0;
        while (i < heapArr.length) {
            this.arr[i] = heapArr[i];
            i++;
        }
        this.endIdx = --i;
        while (i >= 0) {
            downHeapify(i--);
        }
    }

    private void growHeap() {
        int newArr[] = new int[this.endIdx + ((this.endIdx + 1) >> 1) + 1];
        for (int i = 0; i <= this.endIdx; i++) {
            newArr[i] = this.arr[i];
        }
        this.arr = newArr;
        System.gc();    //  calling garbage collector
    }

    @Override
    public String toString() {
        return toString_helper(0).toString();
    }

    private StringBuilder toString_helper(int idx) {
        if (idx > this.endIdx) {
            return new StringBuilder("");
        }
        StringBuilder str = new StringBuilder();
        int lci = 2 * idx + 1;
        int rci = 2 * idx + 2;
        str.append((lci <= this.endIdx) ? arr[lci] : " . " );
        str.append(" -> " + arr[idx] + " <- ");
        str.append((rci <= this.endIdx) ? arr[rci] : " . " );
        str.append("\n");
        str.append(toString_helper(lci));
        str.append(toString_helper(rci));
        return str;
    }


    private void swap(int idx1, int idx2) {
        int temp = arr[idx1];
        arr[idx1] = arr[idx2];
        arr[idx2] = temp; 
    }
    
    private void downHeapify(int idx) {
        int maxIdx = idx;
        int lci = 2 * idx + 1;
        int rci = 2 * idx + 2;
        if (lci <= this.endIdx && this.arr[lci] > this.arr[maxIdx]) {
            maxIdx = lci;
        }
        if (rci <= this.endIdx && this.arr[rci] > this.arr[maxIdx]) {
            maxIdx = rci;
        }
        if (maxIdx != idx) {
            swap(maxIdx, idx);
            downHeapify(maxIdx);
        }
    }

    private void upHeapify(int cidx) {
        int parIdx = (cidx - 1) >> 1;
        if (parIdx >= 0 && this.arr[parIdx] < this.arr[cidx]) {
            swap(parIdx, cidx);
            upHeapify(parIdx);
        }
    }

    public void push(int data) {
        if (endIdx + 1 >= this.arr.length) {
            growHeap();
        }
        this.endIdx++;
        this.arr[endIdx] = data;
        upHeapify(endIdx);
    }

    public int pop() {
        if (endIdx == -1) {
            System.err.println("Underflow, heap is empty");
            System.err.println("can't perform pop() operation");
            return Integer.MIN_VALUE;
        }
        int ans = this.arr[0];
        swap(0, endIdx);
        this.arr[endIdx--] = 0;
        downHeapify(0);
        return ans;
    }

    public void update(int idx, int data) {
        if (idx > this.endIdx) {    //  should generate error
            System.err.println("Heap index out-of-bound");
            System.err.println("can't perform update() operation");
            return;
        }
        this.arr[idx] = data;
        upHeapify(idx);
        downHeapify(idx);
    }

    public int size() {
        return this.endIdx + 1;
    }

    public int capacity() {
        return this.arr.length;
    }

    public boolean isEmpty() {
        return endIdx == -1;
    }

/* 
    private void downHeapify_btr(int idx) {
        if (2 * idx + 1 >= arr.length)      return;     // base case if node is a leaf node in heap
        int maxIdx = idx;       //  index of maximum element in sub-heap(default root)
        int maxChildIdx = 2 * idx + 1;      //  index of max child
        if (2 * idx + 2 < arr.length) {     //  cheacking if right child exist
            maxChildIdx = (arr[maxChildIdx] > arr[2 * idx + 2]) ? maxChildIdx : (2 * idx + 2);
        }
        if (arr[maxIdx] < arr[maxChildIdx]) {
            swap(maxChildIdx, maxIdx);
            downHeapify_btr(maxChildIdx);
        }
    }
*/
}