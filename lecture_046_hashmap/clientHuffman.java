import jdk.internal.net.http.hpack.Huffman;

public class clientHuffman {
    public static void main(String[] args) {
        HuffmanED converter = new HuffmanED();
        String encoded = converter.encode("yashsaxena");
        String decoded = converter.decode(encoded);
        System.out.println(encoded);
        System.out.println(decoded);
    }
}