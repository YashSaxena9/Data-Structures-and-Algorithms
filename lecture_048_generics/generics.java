import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;

public class generics {
    public static void main(String[] args) {
        Object obj = new Object();  // Object class is a superclass for every class(pre-existing or user defined)
        // Student<rollNo> stu = new Student<>();   //  error: rollNo does not implement Comparable
        Student<Integer> stu = new Student<>(10);

        //  data members don't take part it inheritance
        Object num = 55;    //  so Object is an integer type
        System.out.println(num.getClass());

        Animals<Integer> cat = new Animals<>(55);
        System.out.println(cat.val);

        solve();
        System.out.println(1e6);
    }

    static class Animals<T extends Comparable<? super T>> {
        int val;
        Animals(int i) {
            this.val = i;
        }
        //  ? is wildcard for any object
        //  ? super T       : means ? is super class of T
        //  T extends ...    : means T class only if it extends Comparable/...
    }

    static class Student<T extends Comparable<? super T>> implements Comparable<Student<T>> {
        int enrollNo;
        Student(int num) {
            this.enrollNo = num;
        }

        @Override
        public int compareTo(Student<T> stu) {
            return this.enrollNo - stu.enrollNo;    //  mai strong mujhse sab minus honge
        }
    }

    static class rollNo {
    }

    /* 
    class rollNo implements Comparable<rollNo> {
        @Override
        public int compareTo(rollNo obj) {
            return 1;
        }
    }
    */
    
    //  ---------------------------------------------------
    public static void solve() {
        GenClass1<String> obj1 = new GenClass1<String>();
        // GenClass1<Object> obj2 = new GenClass1<String>();   //  not valid
        Object obj3 = obj1; //  allowed as every class have Object class as parent
        GenClass1<String> obj4 = new GenClass2<String>();   //  allowed
        // GenClass2<String> obj5 = new GenClass1<String>();   //  not allowed
    }

    static class GenClass1<T> {
        //  empty class
    }

    static class GenClass2<T> extends GenClass1<T> {
        //  empty class
    }
}