#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Node {
private:
	Node* parent;
	vector<Node*> child;
	int data;
	int depth;
public:
	Node() {
		parent = nullptr;
		data = 0;
		depth = 0;
	}
	Node(int d,int dep) {
		parent = nullptr;
		data = d;
		depth = dep;
	}
	Node(int d, Node* parent,int dep) {
		this->parent = parent;
		data = d;
		depth = dep;
	}
	friend class Tree;
};
class Tree {
private:
	Node* root;
	vector<Node*> treelist;
public:
	Tree() {
		root = new Node(1,0);
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
			Node* newNode = new Node(y, parentNode,parentNode->depth+1);
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
		if (parentNode == nullptr || parentNode->child.size() == 0) {
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
	void ancestor(int x) {
		Node* curNode = find(x);
		while(curNode->parent != nullptr) {
			cout << curNode->parent->data << " ";
			curNode = curNode->parent;
		}
		cout << endl;
		
	}
};
int main() {
	int n, m;
	int x, y, v;
	Tree tree;
	cin >> n >> m;
	for (int i = 0; i < n - 1; i++) {
		cin >> x >> y;
		tree.insert(x, y);
	}
	for (int i = 0; i < m; i++) {
		cin >> v;
		tree.ancestor(v);
	}
}