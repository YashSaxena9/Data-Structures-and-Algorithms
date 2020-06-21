#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Node {
	public:
	int data = 0;
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
	cout << (root->left == NULL?" . " : to_string(root->left->data));
	cout << " -> "<<root->data<<" <- ";
	cout << (root->right == NULL ? " . " : to_string(root->right->data));
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

void solve() {
	// vector<int> arr1 = {10,20,30,40,50,60,70,80,90,100,110,120};
	vector<int> arr2 = {9,10,13,25,26,27,29,30,45,50,60,65,72,75,85};
	Node* root = const_InOrd(arr2, 0, arr2.size() - 1);
	display(root);
	// cout<<max_(root)->data<<endl;
	// cout<<maxInt(root)<<endl;
	// cout<<min_(root)->data<<endl;
	// cout<<minInt(root)<<endl;
	//cout<<lowComAnce_(root, 10, 50)<<endl;
	// cout<<(boolalpha)<<find(root, 1000000000, 1, "")<<endl;
	// cout<<(boolalpha)<<find_(root, 1000000000)<<endl;
	predSucc_01(root, 70);
	cout<<"pred : "<<pred->data<<endl;
	cout<<"succ : "<<succ->data<<endl;
}

int main(int args, char**argv) {
	solve();
	return 0;
}