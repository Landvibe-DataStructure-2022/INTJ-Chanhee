#include<iostream>
#include<string>

using namespace std;

int cnt = 0;
class Node {
private:
	int data;
	Node* parent;
	Node* left;
	Node* right;
public:
	Node() {
		data = 0;
		parent = left = right = nullptr;
	}
	Node(int d) {
		data = d;
		parent = left = right = nullptr;
	}
	void setleft(Node* node) {
		this->left = node;
		node->parent = this;
	}
	void setright(Node* node) {
		this->right = node;
		node->parent = this;
	}
	friend class BST;
};
class BST {
private:
	
public:
	Node* root;
	BST() {
		root = nullptr;
	}
	void insert(int data) {
		Node* newNode = new Node(data);
		if (root == nullptr) {
			root = newNode;
			return;
		}
		Node* parent = nullptr;
		Node* curNode = root;
		while (curNode != nullptr) {
			if (curNode->data < data) {
				parent = curNode;
				curNode = curNode->right;
			}
			else if (curNode->data > data) {
				parent = curNode;
				curNode = curNode->left;
			}
		}
		if (data > parent->data) {
			parent->setright(newNode);
		}
		else if (data < parent->data) {
			parent->setleft(newNode);
		}
	}
	void inorder(Node* r,int m) {
		
		if (r->left != nullptr) {
			inorder(r->left, m);
		}
		cnt++;
		if (cnt == m) {
			cout << r->data << endl;
			return;
		}
		if (r->right != nullptr) {
			inorder(r->right, m);
		}
	}
};
int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		BST bst;
		
		for (int j = 0; j < n; j++) {
			int k;
			cin >> k;
			bst.insert(k);
		}
		int m;
		cin >> m;
		cnt = 0;
		bst.inorder(bst.root,m);
	}
}

