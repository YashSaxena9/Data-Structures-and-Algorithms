import java.util.ArrayList;

public class Heap {
    private ArrayList<Integer> arr;

    public Heap() {
        this.arr = new ArrayList<>();
    }

    public Heap(int size) {
        this.arr = new ArrayList<>(size);
    }

    public Heap(int[] arr) {
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
        int maxIdx = idx;
        int lci = 2 * idx + 1;
        int rci = 2 * idx + 2;
        if (lci < arr.size() && arr.get(lci) > arr.get(maxIdx)) {
            maxIdx = lci;
        }
        if (rci < arr.size() && arr.get(rci) > arr.get(maxIdx)) {
            maxIdx = rci;
        }
        if (maxIdx != idx) {
            swap(maxIdx, idx);
            downHeapify(maxIdx);
        }
    }

    private void upHeapify(int cidx) {
        int pidx = (cidx - 1) >> 1;
        if (pidx >= 0 && arr.get(pidx) < arr.get(cidx)) {
            swap(pidx, cidx);
            upHeapify(pidx);
        }
    }

    public void push(int data) {
        arr.add(data);
        upHeapify(arr.size() - 1);
    }

    public int pop() {
        int val = arr.get(0);
        arr.set(0, arr.remove(arr.size() - 1));
        downHeapify(0);
        return val;
    }

    public void update(int idx, int data) {
        arr.set(idx, data);
        upHeapify(idx);
        downHeapify(idx);
    }

    public int top() {
        return arr.get(0);
    }

    public int size() {
        return arr.size();
    }

    public boolean isEmpty() {
        return arr.size() == 0;
    }
}