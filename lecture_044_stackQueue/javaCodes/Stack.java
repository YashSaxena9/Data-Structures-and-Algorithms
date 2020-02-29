/**
 * stack
 */
public class Stack {
    
    protected int[] st;   //  space for stack
    protected int tos;    //  top of stack (for empty stack = -1)
    
    Stack() {
        this(10);       //  default size 10
    }
    
    Stack(int capacity) {
        this.st = new int[capacity];     //  default size 10
        this.tos = -1;
    }
    
    boolean isEmpty() {
        return this.tos == -1;
    }
    
    int size() {
        return tos + 1;
    }
    
    int capacity() {
        return st.length;
    }
    
    void display() {
        StringBuilder str = new StringBuilder("[");
        for (int i = this.tos; i > 0; i--) {
            str.append(this.st[i] + ", ");
        }
        str.append(this.st[0] + " ]");
        System.out.println(str);
    }

    @Override
    public String toString() {
        StringBuilder str = new StringBuilder("[");
        for (int i = this.tos; i > 0; i--) {
            str.append(this.st[i] + ", ");
        }
        str.append(this.st[0] + " ]");
        return str.toString();
    }

    void push(int val) {
        if (this.tos == st.length - 1) {
            System.out.println("Overflow, Stack is full");
            return;
        }
        this.st[++this.tos] = val;
    }

    int pop() {
        if (this.tos == -1) {
            System.out.println("Underflow, Stack is empty");
            return -1;
        }
        int rm = st[tos];
        st[tos--] = 0;
        return rm;
    }

    int top() {
        if (this.tos == -1) {
            System.out.println("Underflow, Stack is empty");
            return -1;
        }
        return st[tos];
    }
}