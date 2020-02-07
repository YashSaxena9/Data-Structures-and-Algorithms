import java.util.ArrayList;
import java.util.LinkedList;
/**
 * Client
 */
public class Client {

    public static void main(String[] args) {
        int[] tree1 = {
            10, 20, 30, 40, -1, -1, 50, -1, -1, 60, 70, -1, -1, -1, 80, 90, 100, 120, -1, -1, 130, -1, -1, 110, -1, -1, 140, -1, -1
        };
        // int[] lvl_tree1 = {
        //     10, 20, 80, 30, 60, 90, 140, 40, 50, 70, -1, 100, 110, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 120, 130
        // };
        // int[] tree2 = {
        //     10, 20, 30, -1, -1, 40, 50, -1, -1, 60, -1, -1, 70, 80, 100, -1, -1, 110, 140, -1, -1, -1, 90, -1, -1
        // };
        // int[] lvl_tree2 = {
        //     10, 20, 70, 30, 40, 80, 90, -1, -1, 50, 60, 100, 110, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 140
        // };
        // int[] tree3 = {
        //     10, 20, 30, -1, -1, 40, 50, -1, -1, 60, -1, -1, 70, 80, 100, 101, 102, -1, -1, -1, -1, 
        //     110, 140, 139, -1, 142, 146, -1, -1, -1, 141, 143, 147, -1, -1, 148, -1, -1, -1, -1, 90, 
        //     191, -1, -1, 180, 190, -1, -1, 200, -1, -1
        // };
        // BinaryTree root1 = new BinaryTree(tree3);
        BinaryTree root1 = new BinaryTree(tree1);
        // // BinaryTree root1 = new BinaryTree(lvl_tree1, false);
        // System.out.println(root1);
        //     // BinaryTree root2 = new BinaryTree(lvl_tree2, false);
        //     // BinaryTree root2 = new BinaryTree(tree2);
        //     // System.out.println(root2);
        // // root1.display();
        // // System.out.println(root1.toString());
        //     // BinaryTree pseudoRoot = new BinaryTree();
        //     // pseudoRoot.displayWithoutMakingTree(lvl_tree1, 0);       //  display without making tree
        // System.out.println(root1.maxValue());
        // System.out.println(root1.minValue());
        // System.out.println(root1.size());
        // System.out.println(root1.find(40));
        // System.out.println(root1.heightInEdges());
        // System.out.println(root1.heightInNodes());
        // System.out.println(root1.maxNode().data);         //  Node class is private
        // System.out.println(root1.minNode().data);         //  Node class is private
        // System.out.println(root1.findNode(100).data);         //  Node class is private
        // // System.out.println(root1.root);           // .root is private
        // for (int n : root1.rootToNodePath(100)) {
        //     System.out.print(n + " ");
        // }   System.out.println();
        // System.out.println(root1.lowestCommAnces(100, 140));
        // root1.print_k_Away(110, 4);
        // System.out.println();
        // for (int i : root1.get_k_Away(110, 4)) {
        //     System.out.print(i + " ");
        // }   System.out.println();
        // System.out.println(root1.get_k_Away_noSpace(110, 4));
        // root1.print_k_Away_noSpace(110, 4);     System.out.println();
        // System.out.println(root1.preOrder_return());
        // System.out.println(root1.inOrder_return());
        // System.out.println(root1.postOrder_return());
        // root1.preOrder_print();
        // root1.inOrder_print();
        // root1.postOrder_print();
        root1.lvl_print();
    }
}