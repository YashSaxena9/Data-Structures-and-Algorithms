//  leetcode 208, 211, 212, 472, 642


#include <iostream>
#include <vector>
using namespace std;

class Trie {
private :
    class Node {
    public :
        int wordEnd = 0;
        string word = "";
        Node** childs;

        Node() {
            this->childs = new Node*[26];
            this->wordEnd = 0;
        }
    };
    Node* root = nullptr;

public :
    void insert(string word) {
        Node* curr = root;
        int n = word.length();
        for (int i = 0; i < n; i++) {
            int idx = word[i] - 'a';
            if (curr->childs[idx] == nullptr) {
                curr->childs[idx] = new Node();
            }
            curr = curr->childs[idx];
        }
        curr->wordEnd++;
    }

    bool search(string word) {
        Node* curr = root;
        int n = word.length();
        for (int i = 0; i < n; i++) {
            int idx = word[i] - 'a';
            curr = curr->childs[idx];
            if (curr == nullptr) {
                return false;
            }
        }
        return curr->wordEnd > 0;
    }

    
    bool search_wild(string word) {
        return searchWithUnknown(root, 0, word);
    }
    bool searchWithUnknown(Node* node, int si, string word) {     //  for words like a.ad for word abad
        if (node == nullptr) return false;
        if (si == word.length()) return node->wordEnd != 0;

        bool res = false;
        if (word[si] == '.') {
            for (int i = 0; i < 26; i++) {
                if (node->childs[i] != nullptr) {
                    res = res || searchWithUnknown(node->childs[i], si + 1, word);
                }
            }
        } else {
            int idx = word[si] - 'a';
            if (node->childs[idx] != nullptr) {
                res = res || searchWithUnknown(node->childs[idx], si + 1, word);
            }
        }
        return res;
    }


    bool startsWith(string prefix) {      //  cheack prefix, not necessary to have word end
        Node* curr = root;
        int n = prefix.length();
        for (int i = 0; i < n; i++) {
            int idx = prefix[i] - 'a';
            curr = curr->childs[idx];
            if (curr == nullptr) {
                return false;
            }
        }
        return true;
    }
};