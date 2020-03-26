public class Avl<E extends Comparable<E>> {
    private class Node<E> {
        E data;
        Node left;
        Node right;
        int bal, height;
        Boolean forHashmap = false;
        Node() {
            //  default
            this(null, null, null);
        }
        Node(E data) {
            this(data, null, null);
        }
        Node(E data, Node left, Node right) {
            this.data = data;
            this.left = left;
            this.right = right;
            bal = 0; height = 0;
        }
        
        @Override
        public String toString() {
            StringBuilder str = new StringBuilder();
            str.append(this.left != null ? this.left.data : " . ");
            str.append(" -> " + this.data + " <- ");
            str.append(this.right != null ? this.right.data : " . ");
            str.append("\n");
            if (this.left != null) {
                str.append(this.left.toString());
            }
            if (this.right != null) {
                str.append(this.right.toString());
            }
        }
    }
    
    private Node<E> root;
    private int size;

    public Avl() {
        this.root = null;
        this.size = 0;
    }

    public Avl(E[] arr) {
        root = makeBST(arr, 0, arr.length);
        this.size = arr.length;
    }

    private Node<E> makeBST(E[] inOrd, int si, int ei) {
        if (si > ei) {
            return null;
        }
        int mid = (si + ei) >> 1;
        Node<E> node = new Node<>(inOrd[mid]);
        node.left = makeBST(inOrd, si, mid - 1);
        node.right = makeBST(inOrd, mid + 1, ei);
        node = rotate(node);
        return node;
    }

    @Override
    public String toString() {
        return root.toString();
    }

    public void add(E data) {
        this.root = addNode(root, data);
        this.size++;
    }

    private Node<E> addNode(Node<E> node, E data) {
        if (node == null) {
            return new Node<E>(data);
        }
        if (node.data.compareTo(data) > 0) {
            node.left = addNode(node.left, data);
        } else {
            node.right = addNode(node.right, data);
        }
        return rotate(node);
    }
    
    public E maxInTree() {
        return maxInTree(root).data;
    }

    private Node<E> maxInTree(Node<E> node) {
        if (node == null) {
            return null;
        }
        Node<E> rnode = node;
        while (node.right != null) {
            rnode = rnode.right;
        }
        return rnode;
    }

    public E remove(E data) {
        this.root = removeNode(root, key, value);
        this.size--;
        return data;
    }

    public Node<K, V> removeNode(Node<K, V> node, K key, V value) {
        if (node == null) {
            System.err.println("data doesn't exist");
            return null;
        }
        if (node.key.equals(key)) {
            if (node.left == null || node.right == null) {
                return (node.left == null) ? node.right : node.left;
            }
            Pair<K, V> maxData = maxInTree(node.left);
            node.key = maxData.first;
            node.value = maxData.second;
            node.left = removeNode(node.left, maxData.first, maxData.second);
        } else if (node.key.compareTo(key) > 0) {
            node.left = removeNode(node.left, key, value);
        } else {
            node.right = removeNode(node.right, key, value);
        }
        node = rotate(node);
        return node;
    }

    private Node<K, V> ll(Node<K, V> node) {     //  left left rotation
        Node<K, V> leftNode = node.left;
        Node<K, V> leftNode_right = leftNode.right;
        leftNode.right = node;
        node.left = leftNode_right;
        updateHeightBalance(node);
        updateHeightBalance(leftNode);
        return leftNode;
    }
    
    private Node<K, V> rr(Node<K, V> node) {     //  right right rotation
        Node<K, V> rightNode = node.right;
        Node<K, V> rightNode_left = rightNode.left;
        rightNode.left = node;
        node.right = rightNode_left;
        updateHeightBalance(node);
        updateHeightBalance(rightNode);
        return rightNode;
    }

    private void updateHeightBalance(Node<K, V> node) {
        // if (node == null)   return;
        int lh = -1, rh = -1;       //  default value if nodes are null
        if (node.left != null) {
            lh = node.left.height;
        }
        if (node.right != null) {
            rh = node.right.height;
        }
        node.height = Math.max(lh, rh) + 1;
        node.bal = lh - rh;
    }

    private Node<K, V> rotate(Node<K, V> node) {
        updateHeightBalance(node);
        if (node.bal == 2) {                                   // if (node.bal == 2) {
            if (node.left.bal == 1) {                          // if (node.left.bal == 1) {
                return ll(node);
            } else {                   // } else if (node.left.bal == -1) {
                node.left = rr(node.left);
                return ll(node);
            }
        } else if (node.bal == -2) {                           // } else if (node.bal == -2) {
            if (node.right.bal == -1) {                         // if (node.right.bal == -1) {
                return rr(node);
            } else  {                  // } else if (node.right.bal == 1) {
                node.right = ll(node.right);
                return rr(node);
            }
        }
        return node;
    }
}