#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Node {
private:
	Node* parent;
	vector<Node*> child;
	int data;
public:
	Node() {
		parent = nullptr;
		data = 0;
	}
	Node(int d) {
		parent = nullptr;
		data = d;
	}
	Node(Node* p,int d) {
		parent = p;
		data = d;
	}
	friend class Tree;
};

class Tree {
private:
	vector<Node*> treelist;
	Node* root;
public:
	Tree() {
		root = new Node(1);
		treelist.push_back(root);
	}
	Node* getroot() {
		return root;
	}
	Node* find(int x) {
		for (int i = 0; i < treelist.size(); i++) {
			if (x == treelist[i]->data) {
				return treelist[i];
			}
		}
		return nullptr;
	}
	void insert(int x, int y) {
		Node* parentNode = find(x);
		Node* newNode = new Node(parentNode, y);
		parentNode->child.push_back(newNode);
		treelist.push_back(newNode);
	}
	void preorder(Node* p) {
		if (p != root) {
			cout << p->parent->data << " ";
		}
		else {
			cout << "0 ";
		}
		for (int i = 0; i < p->child.size(); i++) {
			preorder(p->child[i]);
		}
	}
};
int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		Tree tree;
		for (int j = 0; j < n; j++) {
			int x, y;
			cin >> x >> y;
			tree.insert(x, y);
		}
		tree.preorder(tree.getroot());
		cout << endl;
	}
}