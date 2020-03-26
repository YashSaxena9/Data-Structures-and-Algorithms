import java.util.Comparator;

public class Pair<K, V> implements Comparable<Pair<K, V>> {
    K first;
    V second;
    private Comparator<? super K> comparator_K;
    private Comparator<? super Pair<K, V>> comparator_pair;
    
    public Pair() {
        construct(null, null, null, null);
    }

    public Pair(K first, V second) {
        construct(first, second, null, null);
    }
    
    // public Pair(K first, V second, Comparator<K> key_comparator) {
    //     construct(first, second, key_comparator, null);
    // }
    
    public Pair(K first, V second, Comparator<Pair<K, V>> pair_comparator) {
        construct(first, second, null, pair_comparator);
    }

    private void construct(K key, V value, Comparator<? super K> comp_k, Comparator<? super Pair<K, V>> comp_pair) {
        this.first = key;
        this.second = value;
        this.comparator_K = comp_k;
        this.comparator_pair = comp_pair;
    }
    
    @Override
    public int compareTo(Pair<K, V> obj) {
        if (this.comparator_pair == null && this.comparator_K == null) {
            return compareWithComparable(obj.first);
        } else if (this.comparator_K != null) {
            return this.comparator_K.compare(this.first, obj.first);
        } else {
            return this.comparator_pair.compare(this, obj);
        }
    }
    
    @SuppressWarnings("unchecked")
    private <T> int compareWithComparable(T obj) {
        Comparable<? super T> o = (Comparable<? super T>) obj;
        return -o.compareTo((T)this.first);
    }

    @Override
    public String toString() {
        return "{" + this.first + ", " + this.second + "}";
    }

    // @Override

}