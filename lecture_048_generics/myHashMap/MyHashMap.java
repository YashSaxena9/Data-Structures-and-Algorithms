import java.util.LinkedList;
import java.util.ArrayList;

public class MyHashMap {

    private class Node {
        int key;
        int value;

        public Node(int key, int value) {
            this.key = key;
            this.value = value;
        }

        @Override
        public String toString() {
            return this.key + "=" + this.value;
        }
    }

    private int size;       //  default = 0;

    // @SuppressWarnings("unchecked")
    private LinkedList<Node>[] buckets;     //  default size == 10
    
    public MyHashMap() {
        this(10);
    }

    @SuppressWarnings("unchecked")
    public MyHashMap(int groupSize) {
        this.buckets = new LinkedList[groupSize];
        /*  !!!!  already handled in put() function  !!!!
         *  for (int i = 0; i < this.buckets.length; i++) {
         *      this.buckets[i] = new LinkedList<>();
         *  }
         */
        this.size = 0;
    }
    
    public int myGroup(Integer key) {
        return myHashCode(key) % buckets.length;
    }

    public int myHashCode(Integer key) {
        return Math.abs(key.hashCode());
    }

    @Override
    public String toString() {
        if (this.size == 0) {
            return "{}";
        }
        StringBuilder str = new StringBuilder();
        str.append("{");
        for (LinkedList<Node> ll : buckets) {
            if (ll != null && ll.size() != 0) {
                for (Node n : ll) {
                    str.append(n + ", ");
                }
            }
        }
        str.deleteCharAt(str.length() - 1);
        str.deleteCharAt(str.length() - 1);
        str.append("}");
        return str.toString();
    }

    private Node getNodeUtil(int key) {
        int code = myGroup(key);
        if (buckets[code] == null) {
            buckets[code] = new LinkedList<>();
            return null;
        }
        return searchInGroup(buckets[code], key);
    }
    
    /*
    !!!!  wrong : as initially bucket[code] == null and group will get null too.....null pointers don't get passed with address !!!!
     *  LinkedList<Node> group = buckets[code];
     *  if (group == null) {
     *      group = new LinkedList<>();
     *  }
    */
    public void put(int key, int value) {
        int code = myGroup(key);
        if (buckets[code] == null) {
            buckets[code] = new LinkedList<>();
        }
        LinkedList<Node> group = buckets[code];
        Node rn = searchInGroup(group, key);       // Node rn = getNodeUtil(key);
        if (rn != null) {
            rn.value = value;
        } else {
            group.addFirst(new Node(key, value));
            this.size++;

            //  comparing with threshold
            double lambda = group.size() * 1.0 / buckets.length;    //  getting threshold of group
            if (lambda > 0.3) {     //  1.0 is maximum threshold value allowed
                rehash();
            }
        }
    }
    
    private Node searchInGroup(LinkedList<Node> group, int key) {
        if (group == null) {
            return null;
        }
        Node node = null;
        int size = group.size();
        while (size --> 0) {
            Node tempNode = group.getFirst();
            if (tempNode.key == key) {
                node = tempNode;        //  now required node is head
                break;
            }
            group.addLast(group.removeFirst());
        }
        return node;
    }

    private Integer getNodeValue(int key) {
        Node rn = getNodeUtil(key);
        return (rn == null) ? null : rn.value;
    }
    
    public Integer get(int key) {
        return getNodeValue(key);
    }
    
    public Integer remove(int key) {
        int code = myGroup(key);
        LinkedList<Node> group = buckets[code];
        Node rn = searchInGroup(group, key);
        // Node rn = getNodeUtil(key);
        if (rn == null) {
            System.err.println("element not found");
            return null;
        }
        this.size--;
        group.removeFirst();        //  uses group so getNodeUtil(key) not called
        return rn.value;
    }

    public boolean containsKey(int key) {
        // int code = myGroup(key);
        // LinkedList<Node> group = buckets[code];
        // Node rn = searchInGroup(group, key);
        // return rn != null;
        return getNodeUtil(key) != null;
    }

    public Integer[] keyArray() {
        if (this.size == 0) {
            return new Integer[0];
        }
        Integer[] keys = new Integer[this.size];
        int i = 0;
        for (LinkedList<Node> ll : buckets) {
            if (ll == null) {
                continue;
            }
            int lsize = ll.size();
            if (lsize != 0) {
                while (lsize --> 0) {
                    keys[i++] = ll.getFirst().key;
                    ll.addLast(ll.removeFirst());
                }
            }
        }
        return keys;
    }

    public ArrayList<Integer> keyList() {
        if (this.size == 0) {
            return new ArrayList<>();
        }
        ArrayList<Integer> keys = new ArrayList<>();
        for (LinkedList<Node> ll : buckets) {
            if (ll == null) {
                continue;
            }
            int lsize = ll.size();
            if (lsize != 0) {
                while (lsize --> 0) {
                    keys.add(ll.getFirst().key);
                    ll.addLast(ll.removeFirst());
                }
            }
        }
        return keys;
    }

    public void clear() {
        for (LinkedList<Node> group : buckets) {
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
        for (LinkedList<Node> group : buckets) {
            group = new LinkedList<>();
        }
        this.size = 0;
    }

    @SuppressWarnings("unchecked")
    private void rehash() {
        LinkedList<Node> oldBuckets[] = this.buckets;
        this.buckets = new LinkedList[oldBuckets.length * 2];
        reassign();
        for (LinkedList<Node> oldll : oldBuckets) {
            if (oldll != null && oldll.size() > 0) {
                int size = oldll.size();
                while (size --> 0) {
                    Node tnode = oldll.removeFirst();
                    put(tnode.key, tnode.value);
                }
            }
        }
    }

    public Integer getOrDefault(int key, int def_Value) {
        Node rn = getNodeUtil(key);
        if (rn == null) {
            return def_Value;
        }
        return rn.value;
    }

    public Integer putIfAbsent(int key, int value) {
        int code = myGroup(key);
        if (buckets[code] == null) {
            buckets[code] = new LinkedList<>();
        }
        LinkedList<Node> group = buckets[code];
        Node rn = searchInGroup(group, key);
        if (rn == null) {
            group.addFirst(new Node(key, value));
            this.size++;

            //  comparing with threshold
            double lambda = group.size() * 1.0 / buckets.length;    //  getting threshold of group
            if (lambda > 0.3) {     //  1.0 is maximum threshold value allowed
                rehash();
            }
            return null;
        }
        return rn.value;
    }

}