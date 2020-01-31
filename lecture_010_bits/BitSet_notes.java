/**
 * charExp
 */
import java.util.BitSet;
public class charExp {

    public static void main(String[] args) {
        /* 
            int size = (int)1e4 - 100;
            System.out.println(size);
            System.out.println(yash.size());
            System.out.println(yash.get(4));
            yash.set(4);
            System.out.println(yash.get(4));
            System.out.println(yash);
            // yash.flip(4);
            System.out.println(yash.get(4));
            yash.flip(0, 8);
            System.out.println(0xffffffffffffffffL);
            long y = 0xffafffffffffffffL;
            System.out.println(y);
            System.out.println(1e6);
        */

        /* 
            BitSet yash = new BitSet();     //  size in brackets if > 64
            yash.set(4);
            yash.set(5);
            yash.set(3);
            System.out.println(yash);
            System.out.println("5 is " + yash.get(5) + ", 19 is " + yash.get(19));
            System.out.println("size : " + yash.size());
            System.out.println("length : " + yash.length());
            System.out.println("cardinality : " + yash.cardinality());
            yash.clear();       //  all false
        */

        BitSet bs1 = new BitSet();  bs1.set(3, 6);
        BitSet bs2 = new BitSet();  bs2.set(6, 10);
        System.out.println(bs1 + "\n" + bs2);
        System.out.println(bs1.intersects(bs2));
        bs1.xor(bs2);           //  logical xor of numbers (same set bits in both sets get removed)
        System.out.println(bs1);
        System.out.println(bs1.intersects(bs2));
        // bs1.flip(0, 88);
        // System.out.println(bs1 + "\n" + bs2);
        System.out.println(bs2.nextClearBit(0));
        System.out.println(bs2.nextSetBit(0));
        System.out.println(bs2.previousClearBit(4));
        System.out.println(bs2.previousSetBit(4));          //  -1 if not found
        bs1.and(bs2);
        bs1.or(bs2);
        bs1.andNot(bs2);
        bs1.xor(bs2);
        System.out.println(bs1 + "\n" + bs2);
        BitSet test = bs1.get(7, 10);
        System.out.println(test);

        long l = 1L;
        System.out.println(l + ", " + Long.reverse(l));     // .reverse()  flip the bits (e.g. 100010 to 010001)
    }
}