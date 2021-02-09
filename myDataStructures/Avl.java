// import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.Comparator;

public class Avl<E> {
    private class Node {
        E data;
        Node left;
        Node right;
        int bal, height;
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
        Node(Node obj) {
            this.data = obj.data;
            this.left = null;
            this.right = null;
            if (obj.left != null) {
                this.left = new Node(obj.left);
            }
            if (obj.right != null) {
                this.right = new Node(obj.right);
            }
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
            return str.toString();
        }
    }
    
    private Node root;
    private int size;
    private Comparator<E> comp_;

    public Avl() {
        this((Comparator<E>)null);
    }

    public Avl(Comparator<E> comp_) {
        this.comp_ = comp_;
        this.root = null;
        this.size = 0;
    }
    
    public Avl(E data) {
        this(data, null);
    }
    
    public Avl(E data, Comparator<E> comp_) {
        this.comp_ = comp_;
        this.root = new Node(data);
        this.size = 1;
    }

    public Avl(E[] arr) {
        this(arr, null);
    }

    public Avl(E[] arr, Comparator<E> Comparator_) {
        if (Comparator_ != null) {
            this.comp_ = Comparator_;
            Arrays.sort(arr, Comparator_);
        }
        else if (arr != null && arr[0] instanceof Comparable<?>) {
            Arrays.sort(arr);
        } else {
            System.err.println("data type not comparable");
            this.root = null;
            return;
        }
        root = makeBST(arr, 0, arr.length - 41);
        this.size = arr.length;
    }
    
    private Avl(Node node) {
        this.root = new Node(node);
    }

    public Avl(Avl<E> tree) {
        this(tree, null);
    }
    
    public Avl(Avl<E> tree, Comparator<E> comp_) {
        this.comp_ = comp_;
        tree.balanceTree();
        this.root = copyTree(tree.root);
    }

    private Node copyTree(Node from) {
        if (from == null) {
            return null;
        }
        Node temp = new Node(from.data);
        temp.left = copyTree(from.left);
        temp.right = copyTree(from.right);
        return temp;
    }

    private Node makeBST(E[] inOrd, int si, int ei) {
        if (si > ei) {
            return null;
        }
        int mid = (si + ei) >> 1;
        Node node = new Node(inOrd[mid]);
        node.left = makeBST(inOrd, si, mid - 1);
        node.right = makeBST(inOrd, mid + 1, ei);
        node = rotate(node);
        return node;
    }

    @Override
    public String toString() {
        // this.root = rotate(this.root);
        return root.toString();
    }

    public void add(E data) {
        this.root = addNode(root, data);
    }
    
    private Node addNode(Node node, E data) {
        if (node == null) {
            this.size++;        //  maintaining size
            return new Node(data);
        }
        if (compareDataForTree(node.data, data) > 0) {
            node.left = addNode(node.left, data);
        } else {
            node.right = addNode(node.right, data);
        }
        return rotate(node);
    }
    
    public E maxInTree() {
        return maxInTree(root).data;
    }

    private Node maxInTree(Node node) {
        node = rotate(node);
        if (node == null) {
            return null;
        }
        Node rnode = node;
        while (rnode.right != null) {
            rnode = rnode.right;
        }
        return rnode;
    }
    
    public E minInTree() {
        return minInTree(root).data;
    }
    
    private Node minInTree(Node node) {
        node = rotate(node);
        if (node == null) {
            return null;
        }
        Node rnode = node;
        while (rnode.left != null) {
            rnode = rnode.left;
        }
        return rnode;
    }

    public E remove(E data) {
        this.root = removeNode(root, data);
        return data;
    }

    private Node removeNode(Node node, E data) {
        if (node == null) {
            System.err.println("data doesn't exist");
            return null;
        }
        if (node.data.equals(data) || compareDataForTree(node.data, data) == 0) {
            if (node.left == null || node.right == null) {
                this.size--;        //  maintainging size
                return (node.left == null) ? node.right : node.left;
            }
            Node maxData = maxInTree(node.left);
            node.data = maxData.data;
            node.left = removeNode(node.left, maxData.data);
        } else if (compareDataForTree(node.data, data) > 0) {
            node.left = removeNode(node.left, data);
        } else {
            node.right = removeNode(node.right, data);
        }
        node = rotate(node);
        return node;
    }

    private Node ll(Node node) {     //  left left rotation
        Node leftNode = node.left;
        Node leftNode_right = leftNode.right;
        leftNode.right = node;
        node.left = leftNode_right;
        updateHeightBalance(node);
        updateHeightBalance(leftNode);
        return leftNode;
    }
    
    private Node rr(Node node) {     //  right right rotation
        Node rightNode = node.right;
        Node rightNode_left = rightNode.left;
        rightNode.left = node;
        node.right = rightNode_left;
        updateHeightBalance(node);
        updateHeightBalance(rightNode);
        return rightNode;
    }

    private void updateHeightBalance(Node node) {
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

    public void balanceTree() {
        this.root = rotate(this.root);
    }

    private Node rotate(Node node) {
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

    public E getLeftValue() {
        return (this.root.left == null) ? null : this.root.left.data;
    }

    /**
     * returns a deep copy of the sub-tree
     * shallow copy not supported 
     * (use not recommended, speed really slow)
     * @return new Avl();
     */
    public final Avl<E> getLeft() {
        return (this.root.left == null) ? null : new Avl<E>(this.root.left);
    }

    public E getRightValue() {
        return (this.root.right == null) ? null : this.root.right.data;
    }
    
    /**
     * returns a deep copy of the sub-tree
     * shallow copy not supported 
     * (use not recommended, speed really slow)
     * @return new Avl();
     */
    public final Avl<E> getRight() {
        return (this.root.right == null) ? null : new Avl<E>(this.root.right);
    }

    public E getData() {
        return this.root.data;
    }

    @SuppressWarnings("unchecked")
    private int compareDataForTree(E this_, E obj_) {
        if (this.comp_ != null) {
            return this.comp_.compare(this_, obj_);
        } else if (this_ instanceof Comparable<?>) {
            Comparable<E> c = (Comparable<E>)this_;
            return c.compareTo(obj_);
        } else {
            System.err.println("data type not comparable");
            return 0;
        }
    }

    public int size() {
        return this.size;
    }

    public LinkedList<E> preOrd() {
        return preOrder(this.root);
    }
    private LinkedList<E> preOrder(Node node) {
        if (node == null) {
            return null;
        }
        LinkedList<E> temp = new LinkedList<>();
        LinkedList<E> left = preOrder(node.left);
        LinkedList<E> right = preOrder(node.right);
        while (left != null && left.size() != 0) {
            temp.addFirst(left.removeFirst());
        }
        while (right != null && right.size() != 0) {
            temp.addFirst(right.removeFirst());
        }
        temp.addFirst(node.data);
        return temp;
    }

    public E searchData(E data) {
        Node temp = searchNode(this.root, data);
        return (temp == null) ? null : temp.data;
    }

    private Node searchNode(Node node, E data) {
        if (node == null) {
            return null;
        }
        int res = compareDataForTree(node.data, data);
        if (res == 0) {
            return node;
        } else if (res > 0) {
            return searchNode(node.left, data);
        } else {
            return searchNode(node.right, data);
        }
    }
}