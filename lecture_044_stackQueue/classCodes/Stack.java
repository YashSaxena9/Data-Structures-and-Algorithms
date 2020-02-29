public class Stack {
    private int tos = -1;   //  top of Stack (default -1)
    protected int[] st = null;    //  data holding array for stack
    
    public Stack() {
        this(10);   //  default size of stack is 10;
    }
    
    public Stack(int capacity) {
        this.st = new int[capacity];
        this.tos = -1;
    }
    
    public Stack(int[] arr) {
        this.st = new int[2 * arr.length];
        for (int i = 0; i < arr.length; i++) {
            this.st[i] = arr[i];
        }
        this.tos = arr.length - 1;
    }

    @Override
    public String toString() {
        StringBuilder str = new StringBuilder("[");
        for (int i = this.tos; i > 0; i--) {
            str.append(st[i] + ", ");
        }
        str.append(st[0] + "]");
        return str.toString();
    }

    public int size() {
        return this.tos + 1;
    }

    public boolean isEmpty() {
        return this.tos == -1;
    }

    public int capacity() {
        return this.st.length;
    }

    public void push(int data) {
        if (this.tos == st.length - 1) {
            int line = new Exception().getStackTrace()[1].getLineNumber();  //  to get line number from stack trace
            //  at index 1 of stack trace is the function which called present function(me/push)
            System.err.println("StackOverFlow(full stack) : at line" + line);
            System.err.println("\t topOfStack -> " + (this.tos + 1));
            return;
        }
        this.st[++this.tos] = data;
    }

    public int peek() {
        if (this.tos == -1) {
            int line = new Exception().getStackTrace()[1].getLineNumber();
            System.err.println("StackUnderFlow(empty stack) : at line" + line);
            System.err.println("\t topOfStack -> " + this.tos);
            return 0;
        }
        return this.st[this.tos];
    }    

    public int pop() {
        if (this.tos == -1) {
            int line = new Exception().getStackTrace()[1].getLineNumber();
            System.err.println("StackUnderFlow(empty stack) : at line" + line);
            System.err.println("\t topOfStack -> " + this.tos);
            return 0;
        }
        int val = this.st[this.tos--];
        this.st[this.tos + 1] = 0;
        return val;
    }
}