/**
 * Client
 */
public class Client {

    public static void main(String[] args) {
        int[] tree1 = {
            10, 20, 30, 40, -1, -1, 50, -1, -1, 60, -1, 70, -1, -1, 80, 90, 100, 120, -1, -1, 130, -1, -1, 110, -1, -1, 140, -1, -1
        };
        int[] tree2 = {
            10, 20, 30, -1, -1, 40, 50, -1, -1, 60, -1, -1, 70, 80, 100, -1, -1, 110, 140, -1, -1, -1, 90, -1, -1
        };
        int[] tree3 = {
            10, 20, 30, -1, -1, 40, 50, -1, -1, 60, -1, -1, 70, 80, 100, 101, 102, -1, -1, -1, -1, 
            110, 140, 139, -1, 142, 146, -1, -1, -1, 141, 143, 147, -1, -1, 148, -1, -1, -1, -1, 90, 
            191, -1, -1, 180, 190, -1, -1, 200, -1, -1
        };
        BinaryTree root = new BinaryTree(tree3);
        System.out.println(root);
        // root.display();
        // System.out.println(root.toString());
        System.out.println(root.maxValue());
        System.out.println(root.minValue());
        System.out.println(root.size());
        System.out.println(root.find(40));
        System.out.println(root.heightInEdges());
        System.out.println(root.heightInNodes());
        System.out.println(root.maxNode().data);         //  Node class is private
        System.out.println(root.minNode().data);         //  Node class is private
        System.out.println(root.findNode(100).data);         //  Node class is private
        // System.out.println(root.root);           // .root is private
        for (int n : root.rootToNodePath(100)) {
            System.out.print(n + " ");
        }   System.out.println();
        System.out.println(root.lowestCommAnces(100, 140));
        root.print_k_Away(110, 4);
        System.out.println();
        for (int i : root.get_k_Away(110, 4)) {
            System.out.print(i + " ");
        }   System.out.println();
        System.out.println(root.get_k_Away_noSpace(110, 4));
        root.print_k_Away_noSpace(110, 4);
    }    
}