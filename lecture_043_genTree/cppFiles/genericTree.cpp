#include<iostream>
#include<vector>
#include<string>
using namespace std;
    //  for avl
        //  default height is not -1 because a new node is a leaf node and has height 0
        //  -1 is for null nodes
class Node {
public:
    int data;
    vector<Node*> childs;
    Node() : data(0) {}
    Node(int data) {
        this->data = data;
    }
};

Node* createTree(vector<int>& preOrder) {
    vector<Node*> stack;
    for (int i = 0; i < preOrder.size() - 1; i++) {
        if (preOrder[i] != -1) {
            Node* node = new Node(preOrder[i]);
            stack.push_back(node);
        } else {
            Node * node = stack[stack.size() - 1];
            stack.pop_back();
            stack[stack.size() - 1]->childs.push_back(node);
        }
    }
    return stack[0];
}

void display(Node* node) {
    cout << node->data << " -> ";
    for (Node* child : node->childs) {
        cout << child->data << ", ";
    }
    cout << endl;
    for (Node* child : node->childs) {
        display(child);
    }
}

int size(Node* node) {
    int size_ = 0;
    for (Node* child : node->childs) {
        size_ += size(child);
    }
    return size_ + 1;
}

int height(Node* node) {
    int hei = -1;
    for (Node* child : node->childs) {
        hei = max(hei, height(child));
    }
    return hei + 1;
}

int maximum(Node* node) {
    int max_ = node->data;
    for (Node* child : node->childs) {
        max_ = max(max_, maximum(child));
    }
    return max_;
}

int minimum(Node* node) {
    int min_ = node->data;
    for (Node* child : node->childs) {
        min_ = min(min_, minimum(child));
    }
    return min_;
}

bool find(Node* node, int data) {
    bool res = false;
    if (node->data == data) return true;
    for (Node* child : node->childs) {
        res = res || find(child, data);
    }
    return res;
}

//  ========== linearize the tree ============

Node* getTail(Node* node) {
    if (node->childs.size() == 0) {
        return node;
    }
    return getTail(node->childs[0]);
}

// O(n^2)
void treeToList(Node* node) {
    for (Node* child : node->childs) {
        treeToList(child);
    }
    for (int i = node->childs.size() - 2; i >= 0; i--) {
        Node* tail = getTail(node->childs[i]);
        tail->childs.push_back(node->childs[i + 1]);
        node->childs.pop_back();
    }
}

// O(n)
Node* treeToList_btr(Node* node) {
    if (node->childs.size() == 0) {
        return node;
    }
    vector<Node*> tails(node->childs.size());
    for (int i = 0; i < node->childs.size(); i++) {
        Node* child = node->childs[i];
        tails[i] = treeToList_btr(child);
    }
    for (int i = node->childs.size() - 2; i >= 0; i--) {
        tails[i]->childs.push_back(node->childs[i + 1]);
        node->childs.pop_back();
    }
    return tails[tails.size() - 1];
}

// O(n)
Node* treeToList_best(Node* node) {
    if (node->childs.size() == 0) {
        return node;
    }
    Node* myTail = treeToList_best(node->childs.back());
    for (int i = node->childs.size() - 2; i >= 0; i--) {
        Node* tail = treeToList_best(node->childs[i]);
        tail->childs.push_back(node->childs[i + 1]);
        node->childs.pop_back();
    }
    return myTail;
}

Node* removeLeaves_mine(Node* node) {
    if (node->childs.size() == 0) {
        return nullptr;
    }
    for (int i = node->childs.size() - 1; i >= 0; i--) {
        if (node->childs[i]->childs.size() == 0) {
            node->childs.erase(node->childs.begin() + i);
            // node->childs[i] = NULL;      //  null point exception error as vector will have null elements
        } else {
            node->childs[i] = removeLeaves_mine(node->childs[i]);
        }
    }
    return node;
}

void removeLeaves_sir(Node* node) {
    vector<Node*> newChilds;
    for (Node* n : node->childs) {
        if (n->childs.size() != 0) {
            newChilds.push_back(n);
        }
    }
    node->childs = newChilds;
    for (Node* n : node->childs) {
        removeLeaves_sir(n);
    }
}

//  in one tree
bool isSymmetric_itself(Node* node1, Node* node2) {
    if (node1->childs.size() != node2->childs.size()) {
        return false;
    }
    for (int i = 0, j = node2->childs.size() - 1; i <= j; i++, j--) {
        Node* child1 = node1->childs[i];
        Node* child2 = node2->childs[j];
        if (!isSymmetric_itself(child1, child2)) {
            return false;
        }
    }
    return true;
}

//  in two tree
bool isSymmetric_other(Node* node1, Node* node2) {
    if (node1->childs.size() != node2->childs.size()) {
        return false;
    }
    for (int i = 0; i < node1->childs.size(); i++) {
        Node* child1 = node1->childs[i];
        Node* child2 = node2->childs[i];
        if (!isSymmetric_other(child1, child2)) {
            return false;
        }
    }
    return true;
}

//  in one tree
bool isMirror_itself(Node* node1, Node* node2) {
    if (node1->childs.size() != node2->childs.size() || node1->data != node2->data) {
        return false;
    }
    for (int i = 0, j = node2->childs.size() - 1; i <= j; i++, j--) {
        Node* child1 = node1->childs[i];
        Node* child2 = node2->childs[j];
        if (!isMirror_itself(child1, child2)) {
            return false;
        }
    }
    return true;
}

//  in two tree
bool isMirror_other(Node* node1, Node* node2) {
    if (node1->childs.size() != node2->childs.size() || node1->data != node2->data) {
        return false;
    }
    for (int i = 0, j = node2->childs.size() - 1; j >= 0; i++) {
        Node* child1 = node1->childs[i];
        Node* child2 = node2->childs[i];
        if (!isMirror_other(child1, child2)) {
            return false;
        }
    }
    return true;
}

vector<Node*> rootToNodePath(Node* node, int data) {
    if (node == nullptr) {
        return vector<Node*>();
    }
    if (node->data == data) {
        vector<Node*> base = {node};
        return base;
    }
    vector<Node*> myAns;
    for (Node* n : node->childs) {
        vector<Node*> recAns = rootToNodePath(n, data);
        for (Node* rn : recAns) {
            myAns.push_back(rn);
        }
    }
    if (myAns.size() != 0) {
        myAns.push_back(node);
    }
    return myAns;
}

//  lowest common ancestor
Node* LCA(Node* node, int data1, int data2) {
    vector<Node*> path1 = rootToNodePath(node, data1);
    vector<Node*> path2 = rootToNodePath(node, data2);
    int ptr1 = path1.size() - 1;
    int ptr2 = path2.size() - 1;
    Node* ans = new Node();
    while (ptr1 >= 0 && ptr2 >= 0) {
        if (path1[ptr1] != path2[ptr2]) {
            break;
        }
        ans = path1[ptr1];
        ptr1--;
        ptr2--;
    }
    return ans;
}

int distanceBetweenNodes(Node* node, int data1, int data2) {
    if (data1 == data2) {
        return 0;
    }
    vector<Node*> path1 = rootToNodePath(node, data1);
    vector<Node*> path2 = rootToNodePath(node, data2);
    int ptr1 = path1.size() - 1;
    int ptr2 = path2.size() - 1;
    int ans = 0;
    while ((ptr1 >= 0 && ptr2 >= 0)) {
        if (path1[ptr1] != path2[ptr2]) {
            ans += 2;
        }
        ptr1--;
        ptr2--;
    }
    ans += (ptr1 >= 0) ? ptr1 + 1 : 0;     //  +1 because we are counting in terms of edges
    ans += (ptr2 >= 0) ? ptr2 + 1 : 0;
    // (1 node means 2 edges, 2 nodes in distance means 3 edges)
    return ans;
}

void zigZagPrint(Node* node) {
    vector<Node*> stack1;
    vector<Node*> stack2;
    stack1.push_back(node);
    int lvl = 0;
    while (stack1.size() != 0) {
        int size = stack1.size();
        while (size --> 0) {
            Node* rn = stack1.back();
            stack1.pop_back();
            cout << rn->data << " ";
            if ((lvl & 1) == 0) {
                for (Node* n : rn->childs) {
                    stack2.push_back(n);
                }
            } else {
                for (int i = rn->childs.size() - 1; i >= 0; i--) {
                    stack2.push_back(rn->childs[i]);
                }
            }
        }
        lvl++;
        cout << endl;
        vector<Node*> temp = stack1;
        stack1 = stack2;
        stack2 = temp;
    }
}



class AllSol {
public:
    int height = -1;
    int size = 0;
    bool find = false;

    Node *pred = nullptr;
    Node *succ = nullptr;
    Node *prev = nullptr;

    int ceil = 1e8;
    int floor = -1e8;
};

void allSolution(Node *node, int data, int level, AllSol &pair) {
    if (node == nullptr) {
        return;
    }
    pair.height = max(pair.height, level);
    pair.size++;
    pair.find = pair.find || node->data == data;

    if (node->data > data) {
        pair.ceil = min(pair.ceil, node->data);
    }
    if (node->data < data) {
        pair.floor = max(pair.floor, node->data);
    }
    if (node->data == data && pair.pred == nullptr) {
        pair.pred = pair.prev;
    }
    else if (pair.prev != nullptr && pair.succ == nullptr && pair.prev->data == data) {
        pair.succ = node;
    }
    pair.prev = node;
    for (Node *child : node->childs) {
        allSolution(child, data, level + 1, pair);
    }
}

//  ---------------- main ----------------
void solve() {
    vector<int> arr = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 100, -1, 110, -1, -1, 90, -1, -1, 40, -1, -1};
    vector<int> arr1 = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 100, -1, 110, -1, -1, 90, -1, -1, 40, -1, -1};
    Node* tree = createTree(arr);
    Node* tree1 = createTree(arr1);
    display(tree);
    cout << endl;
    // treeToList(tree);
    // treeToList_btr(tree);
    // treeToList_best(tree);
    // removeLeaves_mine(tree);
    // removeLeaves_sir(tree);
    // display(tree);
    // cout << (boolalpha) << isSymmetric_itself(tree, tree) << endl;
    // cout << (boolalpha) << isMirror_itself(tree, tree) << endl;
    
    // for (Node* n : rootToNodePath(tree, 90)) {
    //     cout << n->data << " ";
    // }
    // cout << endl;
    // cout << LCA(tree, 100, 110)->data << endl;
    // cout << distanceBetweenNodes(tree, 30, 110) << endl;
    // zigZagPrint(tree);

    AllSol allAns;
    allSolution(tree, 100, 0, allAns);
    cout << allAns.ceil << "\n" << allAns.floor << "\n" << allAns.find << "\n" << allAns.height << "\n" << allAns.size << "\n" << allAns.pred->data << "\n" << allAns.succ->data << "\n" << allAns.prev->data << endl;

}

int main(int args, char**argv) {
    solve();
    return 0;
}