/**
 * client
 */
public class client {

	public static void main(String[] args) {
		int[] arr = {10,20,40,80,-1,-1,90,-1,-1,50,100,-1,-1,-1,30,60,-1,110,-1,-1,70,120,-1,-1,-1};
		BTree bt = new BTree(arr);
		bt.display();
		bt.preOrder();	System.out.println();
		bt.inOrder();	System.out.println();
		bt.postOrder();	System.out.println();
		System.out.println(bt.min());
		System.out.println(bt.max());
		System.out.println(bt.find(100));
		bt.shortestPath(100);
		bt.shortestPath(1000);
		bt.shortestPath_return(100);
		bt.shortestPath_return(1000);
		bt.leafNodes();
		bt.lvlOrder_inLine();
		bt.lvlOrder_pyramid_withNull();
		bt.lvlOrder_pyramid();
		bt.lvlOrder_pyramid_2que();
		
	}
}