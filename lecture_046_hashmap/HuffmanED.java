import java.util.HashMap;
import java.util.PriorityQueue;

public class HuffmanED {

    private String getRulesOfEncoding() {
        return "qqqqqqqqqqqqqqqwerrrrrrrrrrrrdwwwwwwwwwwwweeeeeeeeerrrrrrrrrrrrrrtttttttttttttyyyyyyyyyyyyyyyuuuuuuuuuuuuiiiiiiiiiiiiiiiiiiiiooooooooooooooooooppppppppppppppppppaaaaaaaaaaaaaaaaaassssssssssssssssssssssssddddddddddddddddfffffffffffffffffffgggggggghhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaavvvvvvvvvvvvvvvvvvvvvvzzzzzzzzzzzzzzzzzbbbbbbbbbbbbbbxxxxxxxnnnnnnnnnnnnnnnnnnhjmmmmmmmklllllllllllllppppppppppasdcvhnfxhdilgabfbvzsbnvlaurhgtliawnhlcasdkjzbsdhvbgsjfjnhgclaksdzmcsdzgfvzselawerapwefao";
    }
    
    private class Node implements Comparable<Node> {
        public char data = '\0';
        public int freq = 0;
        public Node left = null;
        public Node right = null;

        Node(char c, int freq, Node left, Node right) {
            this.data = c;
            this.freq = freq;
            this.left = left;
            this.right = right;
        }

        @Override
        public int compareTo(Node obj) {
            return this.freq - obj.freq;
        }
    }

    private HashMap<Character, String> encodeMap;
    private HashMap<String, Character> decodeMap;

    public HuffmanED() {
        this.encodeMap = new HashMap<>();
        this.decodeMap = new HashMap<>();
        huffmanTree();
    }

    private void huffmanTree() {
        String encodingStr = getRulesOfEncoding();
        int[] freqCount = new int[26];
        // int[] freqCount = new int[256];
        for (int i = 0; i < encodingStr.length(); i++) {
            freqCount[encodingStr.charAt(i) - 'a']++;
            // freqCount[(int)encodingStr.charAt(i)]++;
        }
        PriorityQueue<Node> pq = new PriorityQueue<>();
        for (int i = 0; i < freqCount.length; i++) {
            int freq = freqCount[i];
            if (freq > 0) {
                pq.add(new Node((char)(i + 'a'), freq, null, null));
            }
        }
        while (pq.size() != 1) {
            Node first = pq.poll();
            Node second = pq.poll();
            pq.add(new Node('?', first.freq + second.freq, first, second));             //  ? = first.data + second.data
        }
        huffmanTraversal(pq.poll(), "");
    }

    private void huffmanTraversal(Node node, String BinaryCode) {
        if (node == null) {
            return;
        }
        if (node.left == null && node.right == null) {
            encodeMap.put(node.data, BinaryCode);
            decodeMap.put(BinaryCode, node.data);
            return;
        }
        huffmanTraversal(node.left, BinaryCode + "0");
        huffmanTraversal(node.right, BinaryCode + "1");
    }

    public String encode(String str) {
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < str.length(); i++)
        {
            char ch = str.charAt(i);
            sb.append(encodeMap.get(ch));
        }
        return sb.toString();
    }

    public String decode(String str) {
        // StringBuilder sb = new StringBuilder();  // we will use benefit to string intel pool
        // sb.append(str);
        StringBuilder ans_Sb = new StringBuilder();
        int si = 0, ei = 1;
        while (si < str.length()) {
            String subStr = str.substring(si, ei);
            if (decodeMap.containsKey(subStr)) {
                ans_Sb.append(decodeMap.get(subStr));
                si = ei;
            }
            ei++;
            if (ei > str.length()) {
                break;
            }
        }
        return ans_Sb.toString();
    }
}