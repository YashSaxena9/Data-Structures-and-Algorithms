#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Node {
	public:
	int data = 0;
	int freq = 1;
	Node* left = NULL;
	Node* right = NULL;

	Node(int data) {
		this->data = data;
		this->left = nullptr;
		this->right = nullptr;
	}
	Node(int data, Node* left, Node* right) {
		this->data = data;
		this->left = left;
		this->right = right;
	}
};

void display(Node* root) {
	if (root == nullptr) {
		return;
	}
	cout << (root->left == NULL ? "\t\t . " : (" [ " + to_string(root->left->data) + " , " + to_string(root->left->freq)) + " ] ");
	cout << " -> "<<" [ " + to_string(root->data) + " , " + to_string(root->freq) + " ] "<<" <- ";
	cout << (root->right == NULL ? "\t\t . " : (" [ " + to_string(root->right->data) + " , " + to_string(root->right->freq)) + " ] ");
	cout<<endl;
	display(root->left);	
	display(root->right);
}

Node* max_(Node* node) {
	if (node-> right == nullptr) {
		return node;
	}
	return max_(node->right);
}

int maxInt(Node* node) {
	Node* curr = node;
	while (curr->right != NULL) {
		curr = curr->right;
	}
	return curr->data;
}

Node* min_(Node* node) {
	if (node-> left == nullptr) {
		return node;
	}
	return min_(node->left);
}

int minInt(Node* node) {
	Node* curr = node;
	while (curr->left != NULL) {
		curr = curr->left;
	}
	return curr->data;
}

int height_(Node* node) {
	return (node == NULL) ? 0: max(height_(node->left), height_(node->right)) + 1;
}

int size_(Node* node) {
	return (node == NULL) ? 0: size_(node->left) + size_(node->right) + 1;
}

bool find_(Node* node, int data) {
	// if (node == nullptr || node->data == data) {
	// 	if (node->data == data) {
	// 		return true;
	// 	}
	// 	return false;
	// }
	if (node == nullptr) {
		return false;
	}
	if (node->data == data) {
		return true;
	}
	bool flag = false;
	if (node->data > data) {
		flag = flag || find_(node->left, data);
	}
	else {
		flag = flag || find_(node->right, data);
		return flag;
	}
}

bool find(Node* node, int data, int level, string ans) {
	if (node == nullptr || node->data == data) {
		if (node!=nullptr && node->data == data) {
			cout<<ans;
			cout<<"height of data in tree :"<<level<<endl;
			return true;
		}
		return false;
	}
	// if (node == nullptr ) {
	
	// 	return false;
	// }
	// if (node->data == data)
	// {
	// 	cout << ans;
	// 	cout << "height of data in tree :" << level << endl;
	// 	return true;
	// }
	else if (node->data < data) {
		return find(node->right, data, level + 1, ans + to_string(node->data) + " ");
	}
	else {
		return find(node->left, data, level + 1, ans + to_string(node->data) + " ");
	}
}

Node* findNode(Node* node, int data) {
	if (node == nullptr || node->data == data) {
		if (node!=nullptr && node->data == data) {
			return node;
		}
		return NULL;
	}
	// if (node == nullptr ) {
	
	// 	return false;
	// }
	// if (node->data == data)
	// {
	// 	cout << ans;
	// 	cout << "height of data in tree :" << level << endl;
	// 	return true;
	// }
	else if (node->data < data) {
		return findNode(node->right, data);
	}
	else {
		return findNode(node->left, data);
	}
}

Node* const_InOrd(vector<int> &arr, int si, int ei) {
	if (si > ei) {
		return nullptr;
	}
	int mid = ((si + ei) >> 1);					//  (num / 2) is equal to (num >> 1)
	Node* node = new Node(arr[mid]);
	node->left = const_InOrd(arr, si, mid - 1);
	node->right = const_InOrd(arr, mid + 1, ei);
	return node;
}

//  tree from 2 traversals
Node* mkTree_Pre_In(vector<int> &preOrd, vector<int> &inOrd, int ps, int pe, int is, int ie) {
	if (ps > pe || is > ie) {
		return NULL;
	}
	Node* node = new Node(preOrd[ps]);
	int idx = is;

	while (idx <= ie) {
		if (inOrd[idx] == preOrd[ps])		break;
		idx++;
	}

	int tne = idx - is;
	
	node->left = mkTree_Pre_In(preOrd, inOrd, ps + 1, ps + tne, is, idx - 1);
	node->right = mkTree_Pre_In(preOrd, inOrd, ps + tne + 1, pe, idx + 1, ie);

	return node;
}

Node* mkTree_Post_In(vector<int> &posOrd, vector<int> &inOrd, int ps, int pe, int is, int ie) {
	if (ps > pe || is > ie) {
		return NULL;
	}
	Node* node = new Node(posOrd[pe]);
	int idx = is;

	while (idx <= ie) {
		if (inOrd[idx] == posOrd[pe])		break;
		idx++;
	}
	
	int tne = idx - is;
	
	node->left = mkTree_Post_In(posOrd, inOrd, ps, ps + tne - 1, is, idx - 1);
	node->right = mkTree_Post_In(posOrd, inOrd, ps + tne, pe - 1, idx + 1, ie);

	return node;
}

//  last common ancestor
int lowComAnce_(Node* node, int num1, int num2) {
	if (node == NULL) {
		return -1;
	}
	if (node->data < num1) {
		return lowComAnce_(node->right, num1, num2);
	}
	else if (node->data > num2) {
		return lowComAnce_(node->left, num1, num2);
	}
	else {
		return node->data;
	}
}

//  predecessor and succesor of a node in inOrder
Node* pred = NULL;
Node* succ = NULL;
Node* pre = NULL;
void predSucc_01(Node* node, int data) {
	if (node == NULL) {
		return;
	}
	predSucc_01(node->left, data);
	if (pre != NULL && pre->data == data) {
		succ = node;
	}
	if (node->data == data) {
		pred = pre;
	}
	pre = node;
	predSucc_01(node->right, data);
}

//  add node
void addNode_01(Node* node, Node* par, int data, bool isLeft) {
	if (node == NULL) {
		Node* base = new Node(data);
		// node = base;				//  this is wrong as changes won't reflect
		if (isLeft) {
			par->left = base;
		}
		else {
			par->right = base;
		}
		return;
	}
	if (node->data == data) {
		node->freq++;
	}
	else if (node->data < data) {
		addNode_01(node->right, node, data, false);
	}
	else {
		addNode_01(node->left, node, data, true);
	}
}

Node* addNode_02(Node* node, int data) {
	if (node == NULL) {
		return new Node(data);
	}
	if (node->data == data) {
		node->freq++;
		return node;
	}
	else if (node->data < data) {
		node->right = addNode_02(node->right, data);
	}
	else {
		node->left = addNode_02(node->left, data);
	}
	return node;
}

void addNode_03(Node* &node, int data) {
	if (node == NULL) {
		node = new Node(data);
		return;
	}
	if (node->data == data) {
		node->freq++;
		return;
	}
	else if (node->data < data) {
		addNode_03(node->right, data);
	}
	else {
		addNode_03(node->left, data);
	}
}

void addNode_04(Node**node, int data) {
	if ((*node) == NULL) {
		(*node) = new Node(data);
		return;
	}
	if ((*node)->data == data) {
		(*node)->freq++;
		return;
	}
	else if ((*node)->data < data) {
		addNode_04(&((*node)->right), data);
	}
	else {
		addNode_04(&((*node)->left), data);
	}
}

//  delete node
Node* delNode(Node* node, int data) {
	if (node == nullptr) {
		return node;
	}
	if (node->data < data) {
		node->right = delNode(node->right, data);
	}
	else if (node->data > data) {
		node->left = delNode(node->left, data);
	}
	else {
		if (node->freq > 1) {
			node->freq--;
		}
		else {
			if (node->left == NULL && node->right == NULL) {
				delete node;
				return nullptr;
			}
			else if (node->left == NULL || node->right == NULL) {
				Node* n = node->left != NULL ? node->left : node->right;
				delete node;
				return n;
			}
			int max_ = maxInt(node->left);
			node->data = max_;
			node->left = delNode(node->left, max_);
		}
	}
	return node;
}

void solve() {
	// vector<int> arr1 = {10,20,30,40,50,60,70,80,90,100,110,120};
	// vector<int> arr2 = {9,10,13,25,26,27,29,30,45,50,60,65,72,75,85};
	// Node* root = const_InOrd(arr2, 0, arr2.size() - 1);
	
	vector<int> inOrd = {9,10,13,25,26,27,29,30,45,50,60,65,72,75,85};
	vector<int> preOrd = {50,25,10,9,13,30,27,26,29,45,75,65,60,72,85};
	Node* root = mkTree_Pre_In(preOrd, inOrd, 0, preOrd.size() - 1, 0, inOrd.size() - 1);

	// display(root);
	// cout<<max_(root)->data<<endl;
	// cout<<maxInt(root)<<endl;
	// cout<<min_(root)->data<<endl;
	// cout<<minInt(root)<<endl;
	//cout<<lowComAnce_(root, 10, 50)<<endl;
	// cout<<(boolalpha)<<find(root, 1000000000, 1, "")<<endl;
	// cout<<(boolalpha)<<find_(root, 1000000000)<<endl;
	
	// predSucc_01(root, 70);
	// cout<<"pred : "<<pred->data<<endl;
	// cout<<"succ : "<<succ->data<<endl;

	display(root);
	cout<<endl;
	addNode_01(root, root, 63, true);
	display(root);
	cout << endl;
	addNode_02(root, 67);
	display(root);
	cout << endl;
	addNode_02(root, 65);
	display(root);
	cout<<findNode(root, 65)->freq<<endl;

	display(root);
	cout<<endl;
	delNode(root, 65);
	display(root);
	cout<<endl;
	delNode(root, 65);
	display(root);
	cout<<endl;
	delNode(root, 45);
	display(root);
	cout<<endl;
	delNode(root, 30);
	display(root);
}

int main(int args, char**argv) {
	solve();
	return 0;
}