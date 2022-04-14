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
	Node* root;
	vector<Node*> treelist;
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
	void postorder(Node* p) {
		for (int i = 0; i < p->child.size(); i++) {
			postorder(p->child[i]);
		}
		if (p == root) {
			cout << "0 ";
		}
		else {
			cout << p->parent->data << " ";
		}
	}
	void insert(int x, int y) {
		Node* parentNode = find(x);
		Node* newNode = new Node(parentNode, y);
		parentNode->child.push_back(newNode);
		treelist.push_back(newNode);
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
		tree.postorder(tree.getroot());
		cout << endl;
	}
}