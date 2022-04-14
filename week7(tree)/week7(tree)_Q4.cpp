#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Node {
public:
	Node* parent;
	vector<Node*> child;
	int data;
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
public:
	Node* root;
	vector<Node*> treelist;
	Tree() {
		root = new Node(1);
		treelist.push_back(root);
	}
	Node* find(int x) {
		for (int i = 0; i < treelist.size(); i++) {
			if (treelist[i]->data == x)
				return treelist[i];
		}
		return nullptr;
	}
	void insert(int x, int y) {
		Node* parentNode = find(x);
		Node* newNode = new Node(parentNode, y);
		parentNode->child.push_back(newNode);
		treelist.push_back(newNode);
	}
	void reversePreOrder(Node* p) {
		cout << p->data << " ";
		for (int i = p->child.size()-1; i >=0; i--) {
			reversePreOrder(p->child[i]);
		}
	}
	void print(Node* p) {
		for (int i = 0; i < p->child.size(); i++) {
			cout << p->child[i]->data << " ";
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
		int* depth = new int[n];
		int* value = new int[n];
		for (int j = 0; j < n; j++) {
			cin >> value[j];
		}
		for (int j = 0; j < n; j++) {
			cin >> depth[j];
		}
		for (int j = n-1; j > 0; j--) {
			if (depth[j] < depth[j - 1]) {
				tree.insert(value[j], value[j - 1]);
			}
			else if (depth[j] == depth[j - 1]) {
				tree.insert(tree.find(value[j])->parent->data, value[j - 1]);
				
			}
			else {
				Node* parentNode = tree.find(value[j]);
				for (int k = 0; k < (depth[j] - depth[j - 1]) + 1 ;k++) {
					parentNode = parentNode->parent;
					
				}
				tree.insert(parentNode->data, value[j - 1]);
			}
		}
		
		tree.reversePreOrder(tree.root);
		cout << endl;
	}
}