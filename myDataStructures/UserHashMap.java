import java.util.ArrayList;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.List;

public class UserHashMap<K, V> {
    private Avl<Pair<K, V>>[] Buckets;
    private Comparator<Pair<K, V>> myComparator;
    private int size;
    private float maxLambda = 1.5f;

    public UserHashMap() {
        this(10);
    }
    
    public UserHashMap(int bucketSize) {
        this.myComparator = (Pair<K, V> t, Pair<K, V> o) -> (int)(t.compareTo(o));
        makeBuckets(bucketSize);
    }

    @SuppressWarnings("unchecked")
    private void makeBuckets(int size) {
        this.size = 0;
        this.Buckets = new Avl[size];
    }

    public UserHashMap(UserHashMap<K, V> obj) {
        this.Buckets = obj.Buckets;
        this.myComparator = obj.myComparator;
        this.size = obj.size;
    }

    public int myHashCode(K key) {
        return (int)key.hashCode();
    }

    public int myGroup(K key) {
        int extra = (Buckets.length * 9 + 6 % 20) + 100;
        return (myHashCode(key) + extra) % Buckets.length;
    }

    private String preOrder(Avl<Pair<K, V>> tree) {
        List<Pair<K, V>> arr = tree.preOrd();
        StringBuilder str = new StringBuilder();
        for (Pair<K, V> a : arr) {
            str.append(a.first + "=" + a.second + ", ");
        }
        return str.toString();
    }

    @Override
    public String toString() {
        if (this.size == 0) {
            return "{}";
        }
        StringBuilder str = new StringBuilder();
        str.append("{");
        for (Avl<Pair<K, V>> group : Buckets) {
            if (group != null && group.size() != 0) {
                str.append(preOrder(group));
            }
        }
        str.deleteCharAt(str.length() - 1);
        str.deleteCharAt(str.length() - 1);
        str.append("}");
        return str.toString();
    }

    private Pair<K, V> getNodeUtil(K key) {
        int code = myGroup(key);
        if (Buckets[code] == null) {
            Buckets[code] = new Avl<>(this.myComparator);
            return null;
        }
        return searchInGroup(Buckets[code], key);
    }
    
    /*
    !!!!  wrong : as initially bucket[code] == null and group will get null too.....null pointers don't get passed with address !!!!
     *  LinkedList<Node> group = buckets[code];
     *  if (group == null) {
     *      group = new LinkedList<>();
     *  }
    */
    public void put(K key, V value) {
        int code = myGroup(key);
        if (Buckets[code] == null) {
            Buckets[code] = new Avl<>(this.myComparator);
        }
        Avl<Pair<K, V>> group = Buckets[code];
        Pair<K, V> rn = searchInGroup(group, key);       // Node rn = getNodeUtil(key);
        if (rn != null) {
            rn.second = value;
        } else {
            group.add(new Pair<K, V>(key, value));
            this.size++;

            //  comparing with threshold
            double lambda = group.size() * 1.0 / Buckets.length;    //  getting threshold of group
            if (lambda > this.maxLambda) {     //  1.0 is maximum threshold value allowed
                rehash();
            }
        }
    }

    private Pair<K, V> searchInGroup(Avl<Pair<K, V>> group, K key) {
        if (group == null) {
            return null;
        }
        Pair<K, V> node = group.searchData(new Pair<K, V>(key, null));
        return node;
    }

    private V getNodeValue(K key) {
        Pair<K, V> rn = getNodeUtil(key);
        return (rn == null) ? null : rn.second;
    }
    
    public V get(K key) {
        return getNodeValue(key);
    }
    
    public V remove(K key) {
        int code = myGroup(key);
        Avl<Pair<K, V>> group = Buckets[code];
        Pair<K, V> rn = group.remove(new Pair<K, V>(key, null));
        if (rn == null) {
            System.err.println("element not found");
            return null;
        }
        this.size--;
        return rn.second;
    }

    public boolean containsKey(K key) {
        // int code = myGroup(key);
        // LinkedList<Node> group = buckets[code];
        // Node rn = searchInGroup(group, key);
        // return rn != null;
        return getNodeUtil(key) != null;
    }

    @SuppressWarnings("unchecked")
    public K[] keyArray() {
        if (this.size == 0) {
            return (K[])new Object[0];
        }
        Object[] keys = new Object[this.size];
        int i = 0;
        for (Avl<Pair<K, V>> ll : Buckets) {
            if (ll == null) {
                continue;
            }
            LinkedList<Pair<K, V>> arr = ll.preOrd();
            int lsize = arr.size();
            if (lsize != 0) {
                while (lsize --> 0) {
                    keys[i++] = arr.removeFirst().first;
                }
            }
        }
        return (K[])keys;
    }

    public ArrayList<K> keyList() {
        if (this.size == 0) {
            return new ArrayList<>();
        }
        ArrayList<K> keys = new ArrayList<>();
        for (Avl<Pair<K, V>> ll : Buckets) {
            if (ll == null) {
                continue;
            }
            LinkedList<Pair<K, V>> arr = ll.preOrd();
            if (arr == null) {
                continue;
            }
            int lsize = arr.size();
            if (lsize != 0) {
                while (lsize --> 0) {
                    keys.add(arr.removeFirst().first);
                }
            }
        }
        return keys;
    }

    public void clear() {
        for (Avl<Pair<K, V>> group : Buckets) {
            group = null;
        }
        this.size = 0;
    }

    public int size() {
        return this.size;
    }

    public boolean isEmpty() {
        return this.size == 0;
    }

    private void reassign() {
        for (Avl<Pair<K, V>> group : Buckets) {
            group = new Avl<>(this.myComparator);
        }
        this.size = 0;
    }

    @SuppressWarnings("unchecked")
    private void rehash() {
        Avl<Pair<K, V>> oldBuckets[] = this.Buckets;
        this.Buckets = new Avl[oldBuckets.length + (oldBuckets.length >> 1)];
        reassign();
        for (Avl<Pair<K, V>> oldll : oldBuckets) {
            if (oldll != null && oldll.size() > 0) {
                LinkedList<Pair<K, V>> arr = oldll.preOrd();
                while (arr.size() != 0) {
                    Pair<K, V> temp = arr.removeFirst();
                    put(temp.first, temp.second);
                }
            }
        }
    }

    public V getOrDefault(K key, V def_Value) {
        Pair<K, V> rn = getNodeUtil(key);
        if (rn == null) {
            return def_Value;
        }
        return rn.second;
    }

    public V putIfAbsent(K key, V value) {
        int code = myGroup(key);
        if (Buckets[code] == null) {
            Buckets[code] = new Avl<>(this.myComparator);
        }
        Avl<Pair<K, V>> group = Buckets[code];
        Pair<K, V> rn = searchInGroup(group, key);
        if (rn == null) {
            group.add(new Pair<K, V>(key, value));
            this.size++;

            //  comparing with threshold
            double lambda = group.size() * 1.0 / Buckets.length;    //  getting threshold of group
            if (lambda > this.maxLambda) {     //  1.0 is maximum threshold value allowed
                rehash();
            }
            return null;
        }
        return rn.second;
    }

    @Deprecated
    public void display() {
        for (Avl<Pair<K, V>> a : Buckets) {
            LinkedList<Pair<K, V>> ll = a.preOrd();
            for (Pair<K, V> p : ll) {
                System.out.print(p.first + "=" + p.second + " ");
            }
            System.out.println();
        }
    }
}