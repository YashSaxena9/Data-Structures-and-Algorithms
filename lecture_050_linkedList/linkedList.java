import java.util.NoSuchElementException;

public class linkedList<E> {
    private class Node {
        E data;
        Node next;
        Node() {
            this(null, null);
        }
        Node(E data) {
            this(data, null);
        }
        Node(E data, Node next) {
            this.data = data;
            next = null;
        }
        @Override
        public String toString() {
            return this.data + "";
        }
    }

    private Node head;
    private Node tail;
    private int nodeCount;

    public linkedList() {
        this.head = null;
        this.tail = null;
        this.nodeCount = 0;
    }

    public linkedList(linkedList<E> ll) {
        this.head = ll.head;
        this.tail = ll.tail;
        this.nodeCount = ll.nodeCount;
    }

    @Override
    public String toString() {
        if (this.nodeCount == 0) {
            return "[]";
        }
        StringBuilder str = new StringBuilder();
        str.append("[");
        Node curr = this.head;
        while (curr.next != null) {
            str.append(curr + ", ");
            curr = curr.next;
        }
        str.append(curr);
        str.append("]");
        return str.toString();
    }

    //  basic functions ==================

    public int size() {
        return this.nodeCount;
    }

    public boolean isEmpty() {
        return this.nodeCount == 0;
    }

    private Node getNodeAt(int idx) {
        if (idx < 0 || idx >= this.nodeCount) {
            throw new NullPointerException();
        }
        Node curr = this.head;
        while (idx-- > 0) {
            curr = curr.next;
        }
        return curr;
    }

    //  Add =======================================
    
    public void add(E data) {
        addLast(data);
    }

    public void addFirst(E data) {
        Node node = new Node(data);
        addFirstNode(node);
    }

    private void addFirstNode(Node node) {
        if (this.nodeCount == 0) {
            this.tail = node;
        }
        node.next = this.head;
        this.head = node;
        this.nodeCount++;
    }
    
    public void addLast(E data) {
        Node node = new Node(data);
        addLastNode(node);
    }
    
    private void addLastNode(Node node) {
        if (this.nodeCount == 0) {
            this.head = node;
            this.tail = node;
        } else {
            this.tail.next = node;
            this.tail = node;
        }
        this.nodeCount++;
    }

    public void addAt(int idx, E data) {
        if (idx == 0) {
            addFirst(data);
        } else if (idx == this.nodeCount) {
            addLast(data);
        } else {
            addNodeAt(idx, new Node(data));
        }
    }
    
    private void addNodeAt(int idx, Node node) {
        Node prev = getNodeAt(idx - 1);
        node.next = prev.next;
        prev.next = node;
        this.nodeCount++;
    }

    //  get =======================================

    public E getFirst() {
        if (this.nodeCount == 0) {
            throw new NoSuchElementException();
        }
        return this.head.data;
    }

    public E getLast() {
        if (this.nodeCount == 0) {
            throw new NoSuchElementException();
        }
        return this.tail.data;
    }

    public E getAt(int idx) {
        return getNodeAt(idx).data;
    }

    //  set =======================================

    public void setFirst(E data) {
        if (this.nodeCount == 0) {
            throw new NoSuchElementException();
        }
        this.head.data = data;
    }

    public void setLast(E data) {
        if (this.nodeCount == 0) {
            throw new NoSuchElementException();
        }
        this.tail.data = data;
    }

    public void setAt(int idx, E data) {
        getNodeAt(idx).data = data;
    }

    //  remove =======================================

    public E removeFirst() {
        if (this.nodeCount == 0) {
            throw new NoSuchElementException();
        }
        return removeFirstNode().data;
    }
    
    private Node removeFirstNode() {
        Node rNode = this.head;
        if (this.nodeCount == 1) {
            this.tail = null;
        }
        this.head = this.head.next;
        this.nodeCount--;
        rNode.next = null;
        return rNode;
    }

    public E removeLast() {
        if (this.nodeCount == 0) {
            throw new NoSuchElementException();
        }
        return removeLastNode().data;
    }

    private Node removeLastNode() {
        Node rNode = this.tail;
        if (this.nodeCount == 1) {
            this.head = null;
            this.tail = null;
        } else {
            this.tail = getNodeAt(this.nodeCount - 2);
            this.tail.next = null;
        }
        this.nodeCount--;
        rNode.next = null;
        return rNode;
    }

    public E removeAt(int idx) {
        return removeNodeAt(idx).data;
    }

    private Node removeNodeAt(int idx) {
        c
    }

    //  others ============================

    public E getMiddleFromSize() {
        return middleNodeSize().data;
    }

    private Node middleNodeSize() {     //  middle on the basis of size, not idx
        Node slow = this.head;
        Node fast = this.head;
        while (fast != null && fast.next != null && fast.next.next != null) {       //  gives mid on the basis of idx
            slow = slow.next;
            fast = fast.next.next;
        }
        return fast.next == null ? slow : slow.next;
    }
    
    public E getMiddleFromidx() {
        return middleNodeIdx().data;
    }

    private Node middleNodeIdx() {     //  middle on the basis of idx
        Node slow = this.head;
        Node fast = this.head;
        while (fast != null && fast.next != null && fast.next.next != null) {       //  gives mid on the basis of idx
            slow = slow.next;
            fast = fast.next.next;
        }
        return slow;
    }

    private Node reverseList(Node node) {
        if (this.nodeCount <= 1) {
            return node;
        }
        Node prev = null;
        Node curr = node;
        Node frwd = null;
        while (curr != null) {
            frwd = curr.next;
            curr.next = prev;
            prev = curr;
            curr = frwd;
        }
        return prev;
    }

    public void reverseList() {
        this.tail = this.head;
        this.head = reverseList(this.head);
    }
}