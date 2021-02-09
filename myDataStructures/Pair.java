import java.util.Comparator;

public class Pair<K, V> implements Comparable<Pair<K, V>> {
    K first;
    V second;
    private Comparator<? super Pair<K, V>> comparator_pair;
    
    public Pair() {
        construct(null, null, null);
    }

    public Pair(K first, V second) {
        construct(first, second, null);
    }
    
    public Pair(K first, V second, Comparator<Pair<K, V>> pair_comparator) {
        construct(first, second, pair_comparator);
    }

    private void construct(K key, V value, Comparator<Pair<K, V>> comp_pair) {
        this.first = key;
        this.second = value;
        if (comp_pair != null) {
            this.comparator_pair = comp_pair;
        } else {
            this.comparator_pair = (Pair<K, V> t, Pair<K, V> o) -> (int)(t.first.hashCode() - o.first.hashCode());
        }
    }
    
    @Override
    public int compareTo(Pair<K, V> obj) {
        if (this.first instanceof Comparable<?>) {
            return compareWithComparable(obj.first);
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

    @Override
    public int hashCode() {
        return ((this.first == null) ? 0 : this.first.hashCode()) ^             //  ex-or operation
                ((this.second == null) ? 0 : this.second.hashCode());
    }

    @Override @SuppressWarnings("unchecked")
    public boolean equals(Object obj) {
        if (this == obj) {
            return true;
        }
        if (obj.getClass() != this.getClass() || obj == null) {
            return false;
        }
        Pair<K, V> o = (Pair<K, V>)obj;
        return (this.first.equals(o.first) && this.second.equals(o.second));
    }

}