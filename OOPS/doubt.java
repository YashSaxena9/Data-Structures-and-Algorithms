class linkedlist {
	
	private class Node {
		public Node  next = null;
		public int data;

		Node(int data, Node next) {
			this.data = data;
			this.next = next;
		}
	}

	private Node n0 = new Node(60, null);
	private Node n1 = new Node(50, n0);
	private Node n2 = new Node(40, n1);
	private Node n3 = new Node(30, n2);
	private Node n4 = new Node(20, n3);
	private Node head = new Node(10, n4);

	public void print() {
		for(Node temp = head; temp != null; temp = temp.next) {
			System.out.print(temp.data + "->");
		}
		System.out.println();
	}

}

public class doubt { 

	void fun(){
		System.out.println("Hey! I m inside fun");
	}
	public static void main(String[] args) {
		// linkedlist list = new linkedlist();
		// list.print();


		// not working because of static
		// fun();

		// use function without static
		doubt d = new doubt();
		d.fun();
	}
} 