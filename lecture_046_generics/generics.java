public class generics {
    public static void main(String[] args) {
        // Student<rollNo> stu = new Student<>();   //  error: rollNo does not implement Comparable
        Student<Integer> stu = new Student<>(10);
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

    class rollNo {
    }

    /* 
    class rollNo implements Comparable<rollNo> {
        @Override
        public int compareTo(rollNo obj) {
            return 1;
        }
    }
    */
}