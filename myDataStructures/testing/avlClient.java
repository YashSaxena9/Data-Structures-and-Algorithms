public class avlClient {
    public static void main(String[] str) {
        Avl<Integer> tree = new Avl<>();
        tree.add(56);
        tree.add(46);
        tree.add(556);
        tree.add(896);
        tree.add(336);
        tree.add(6);
        tree.add(96);
        tree.add(506);
        tree.add(5069);
        System.out.println(tree);
        // System.out.println(tree.getLeft());
        // System.out.println(tree.getLeftValue());
        Avl<Integer> itr = tree;
        // Avl<Integer> itr1 = tree;
        System.out.println(tree.getClass());
        while (itr.getLeft() != null) {
            System.out.println(itr.getData());
            itr = itr.getLeft();
        }
        itr.add(123456);
        System.out.println(itr);
        tree.balanceTree();
        System.out.println(tree);

        Integer i1 = 999;
        Integer i2 = new Integer(i1);
        System.out.println(i1);
        i2 = 0;
        System.out.println(i1 + " " + i2);
    }
}