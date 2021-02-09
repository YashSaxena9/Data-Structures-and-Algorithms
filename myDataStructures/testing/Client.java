/**
 * Client
 */
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.Collection;
import java.util.Collections;
import java.util.Comparator;
public class Client {

    public static void main(String[] args) {
        // Avl<Integer, Integer> tree0 = new Avl<>();
        // Avl<String, Integer> tree1 = new Avl<>();
        // Avl<Boolean, Integer> tree2 = new Avl<>();
        // Avl<Character, Integer> tree3 = new Avl<>();
        // Avl<Double, Integer> tree = new Avl<>(true);
        // tree.add(10.0, 50);
        // tree.add(20.0, 50);
        // tree.add(30.0, 50);
        // tree.add(40.0, 50);
        // tree.add(50.0, 50);
        // tree.add(60.0, 50);
        // System.out.println(tree);
        // Pair<String, Boolean> p1 = new Pair<>("yash", null);
        // System.out.println(p1);
        Pair<myClass2, Integer> p2 = new Pair<>(new myClass2(10), null);
        // Pair<myClass2, Integer> p2 = new Pair<>(new myClass2(10), null, new Comparator<Pair<myClass2, Integer>>() {
        //     @Override
        //     public int compare(Pair<myClass2, Integer> t, Pair<myClass2, Integer> o) {
        //         return t.first.i - o.first.i;
        //     }
        // });
        Pair<myClass2, Integer> p3 = new Pair<>(new myClass2(), null);
        System.out.println(p2.hashCode() + " " + p3.hashCode());
        System.out.println(p2.compareTo(p3));
        System.out.println(p2);
        // ArrayList arr = new ArrayList();
        // arr.add("yash");
        // arr.add("saxena");
        // arr.add(99);
        // System.out.println(arr.get(2).getClass());
        // System.out.println(arr);

        // Avl noType = new Avl();
        // noType.add("yash", "saxena");
        // noType.add("aash", "saxena");
        // noType.add("bash", "saxena");
        // noType.add("uash", "saxena");
        // noType.add("pash", "saxena");
        // noType.add("ymash", "saxena");
        // System.out.println(noType);
        
        // Avl<String, Object> oneType = new Avl<>();
        // noType.add("yash", "saxena");
        // noType.add("aash", "saxena");
        // noType.add("bash", "saxena");
        // noType.add("uash", "saxena");
        // noType.add("pash", "saxena");
        // noType.add("ymash", "saxena");
        // System.out.println(noType);
        // Avl<String, String>[] treeArr = new Avl[10];
        // System.out.println(treeArr[6]);

        solve();
    }

    public static void solve() {
        PriorityQueue<myClass> pq = new PriorityQueue<>();
        myClass2 o1 = new myClass2(89);
        myClass2 o2 = new myClass2(89);
        System.out.println(o1.hashCode() + " " + o2.hashCode());
        System.out.println(o1.hashCode() - o2.hashCode());
        System.out.println((int)o1.hashCode());

        //  -----------------------
        Pair<myClass, Integer> pp1 = new Pair<>(new myClass(9), 1234);
        Pair<myClass, Integer> pp2 = new Pair<>(new myClass(10), 1234);
        System.out.println(pp2.compareTo(pp1));

        //  -----------------------
        Pair<myClass2, Integer> pp1_ = new Pair<>(new myClass2(9), 1234, (Pair<myClass2, Integer> a, Pair<myClass2, Integer> b)->(
            (int)(a.second.compareTo(b.second))
        ));
        Pair<myClass2, Integer> pp2_ = new Pair<>(new myClass2(10), 1234, new Comparator<Pair<myClass2, Integer>>() {
            @Override
            public int compare(Pair<myClass2, Integer> t, Pair<myClass2, Integer> o) {
                return t.first.i - o.first.i;
            }
        });
        System.out.println(pp2_.compareTo(pp1_));
        System.out.println(pp1_.compareTo(pp2_));
        // System.out.println(pp1_.compareTo(pp2_));    //  error
        myClass2 c1 = new myClass2(55);
        // Comparable<myClass2> comp = (Comparable<myClass2>) c1;      //  invalid typecast, run time error
        myClass c2 = new myClass(55);
        Comparable<myClass> comp = (Comparable<myClass>) c2;      //  valid typecast, as myClass extends Comparable
        
    }

    static class myClass implements Comparable<myClass>{
        int i = 10;
        myClass(int i) {
            this.i = i;
        }
        @Override
        public int compareTo(myClass o) {
            return this.i - o.i;
        }
    }

    static class myClass2 {
        int i;
        myClass2(int i) {
            this.i = i;
        }
        myClass2() {
            this(10);
        }
        @Override
        public String toString() {
            return i + "";
        }
    }
}