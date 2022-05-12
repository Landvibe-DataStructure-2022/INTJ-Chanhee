#include<iostream>
#include<string>
using namespace std;

class Node {
private:
	int data;
	Node* parent;
	Node* left;
	Node* right;
public:
	Node(int d) {
		data = d;
		parent = nullptr;
		left = nullptr;
		right = nullptr;
	}
	void setright(Node* newNode) {
		this->right = newNode;
		if(newNode != nullptr) newNode->parent = this;
	}
	void setleft(Node* newNode) {
		this->left = newNode;
		if (newNode != nullptr) newNode->parent = this;
	}
	friend class BST;
};

class BST {
private:
	
	
public:
	Node* root;
	int cnt;
	BST() {
		root = nullptr;
		cnt = 0;
	}
	void insert(int x) {
		Node* newNode = new Node(x);
		if (root == nullptr) {
			root = newNode;
			return;
		}
		Node* curNode = root;
		Node* parentNode = nullptr;
		while (curNode != nullptr) {
			if (curNode->data < x) {
				parentNode = curNode;
				curNode = curNode->right;
			}
			else if (curNode->data > x) {
				parentNode = curNode;
				curNode = curNode->left;
			}
		}
		if (x > parentNode->data) {
			parentNode->setright(newNode);
		}
		else if (x < parentNode->data) {
			parentNode->setleft(newNode);
		}
	}
	void deleteNode(int x) {
		Node* deleNode = search(root, x);
		if (deleNode == nullptr) return;
		Node* parentNode = deleNode->parent;
		Node* childNode;
		if (deleNode->right == nullptr && deleNode->left == nullptr) {
			childNode = nullptr;
		}
		else if (deleNode->right != nullptr && deleNode->left == nullptr) {
			childNode = deleNode->right;
		}
		else if (deleNode->right == nullptr && deleNode->left != nullptr) {
			childNode = deleNode->left;
		}
		else {
			childNode = deleNode->right;
			while (childNode->left != nullptr) {
				childNode = childNode->left;
			}
			deleNode->data = childNode->data;
			deleNode = childNode;
			parentNode = deleNode->parent;
			childNode = deleNode->right;
		}
		if (parentNode == nullptr) {
			root = childNode;
			root->parent = nullptr;
		}
		else if (deleNode == parentNode->left) {
			parentNode->setleft(deleNode);
		}
		else {
			parentNode->setright(deleNode);
		}
	}
	Node* search(Node* curNode,int data) {
		while (curNode != nullptr) {
			if (data == curNode->data) {
				return curNode;
			}
			else if (data < curNode->data) {
				curNode = curNode->left;
			}
			else if (data > curNode->data) {
				curNode = curNode->right;
			}
		}
		return nullptr;
	}
	void sub(Node* node) {
		if (node == nullptr) {
			return;
		}
		sub(node->left);
		cnt++;
		sub(node->right);
	}
};
int main() {
	int n;
	cin >> n;

	BST* bst = new BST();

	while (n--) {
		string cmd;
		int data;

		cin >> cmd >> data;

		if (cmd == "insert") {
			bst->insert(data);
		}
		else if (cmd == "delete") {
			bst->deleteNode(data);
		}
		else if (cmd == "sub") {
			bst->cnt = 0;
			bst->sub(bst->search(bst->root,data));
			cout << bst->cnt << "\n";
		}
	}

	return 0;
}