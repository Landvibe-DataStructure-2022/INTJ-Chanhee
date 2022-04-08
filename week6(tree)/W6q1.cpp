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
	Node(int d,Node* parent) {
		this->parent = parent;
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
		if (find(x) == nullptr || find(y) != nullptr) {
			cout << "-1\n";
		}
		else {
			Node* newNode = new Node(y, parentNode);
			parentNode->child.push_back(newNode);
			treelist.push_back(newNode);
		}
	}
	void deleteNode(int x) {
		Node* parentNode = find(x);
		if (parentNode == nullptr) {
			cout << "-1\n";
		}
		else {
			for (int i = 0; i < parentNode->child.size(); i++)
			{
				parentNode->parent->child.push_back(parentNode->child[i]);
				parentNode->child[i]->parent = parentNode->parent;
			}
			for (int i = 0; i < treelist.size(); i++) {
				if (treelist[i]->data == x) {
					treelist.erase(treelist.begin() + i);
				}
			}
			for (int i = 0; i < parentNode->parent->child.size(); i++) {
				if (parentNode->parent->child[i]->data == parentNode->data) {
					parentNode->parent->child.erase(parentNode->parent->child.begin() + i);
				}
			}
			delete parentNode;
		}
	}
	void parent(int x) {
		Node* parentNode = find(x);
		if (parentNode == nullptr) {
			cout << "-1\n";
		}
		else {
			cout << parentNode->parent->data << endl;
		}
	}
	void child(int x) {
		Node* parentNode = find(x);
		if (parentNode == nullptr|| parentNode->child.size() == 0) {
			cout << "-1\n";
		}
		else {
			for (int i = 0; i < parentNode->child.size(); i++) {
				cout << parentNode->child[i]->data << " ";
			}
			cout << endl;
		}
	}
	void maxChild(int x) {
		Node* parentNode = find(x);
		if (parentNode == nullptr || parentNode->child.size() == 0) {
			cout << "-1\n";
		}
		else {
			int max = parentNode->child[0]->data;
			for (int i = 1; i < parentNode->child.size(); i++) {
				if (max < parentNode->child[i]->data) {
					max = parentNode->child[i]->data;
				}
			}
			cout << max << endl;
		}
	}
};
int main() {
	int t;
	cin >> t;
	Tree tree;
	string cmd;
	for (int i = 0; i < t; i++) {
		cin >> cmd;
		int x;
		if (cmd == "insert") {
			int y;
			cin >> x >> y;
			tree.insert(x, y);
		}
		else if (cmd == "delete") {
			cin >> x;
			tree.deleteNode(x);
		}
		else if (cmd == "parent") {
			cin >> x;
			tree.parent(x);
		}
		else if (cmd == "child") {
			cin >> x;
			tree.child(x);
		}
		else if (cmd == "maxChild") {
			cin >> x;
			tree.maxChild(x);
		}
	}
}