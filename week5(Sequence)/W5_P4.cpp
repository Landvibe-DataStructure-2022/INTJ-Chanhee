#include<iostream>
#include<string>
using namespace std;

class Node {
private:
	Node* next;
	Node* pre;
	int data;
public:
	Node() {
		next = nullptr;
		pre = nullptr;
		data = 0;
	}
	Node(int e) {
		next = nullptr;
		pre = nullptr;
		data = e;
	}
	friend class Iterator;
	friend class LinkedList;
};

class Iterator {
private:
	Node* node;
public:
	Iterator(Node* n) {
		node = n;
	}
	Node* getNode() {
		return node;
	}
	void setIterator(Node* n) {
		node = n;
	}
	Iterator* operator++() {
		node = node->next;
		return this;
	}
	Iterator* operator--() {
		node = node->pre;
		return this;
	}
	friend class LinkedList;
};

class LinkedList {
private:
	Node* head;
	Node* tail;
	int size;
public:
	LinkedList() {
		head = new Node();
		tail = new Node();
		head->next = tail;
		tail->pre = head;
		size = 0;
	}
	Node* begin() {
		return head->next;
	}
	Node* end() {
		return tail;
	}
	void insert(Iterator* p, int e) {
		Node* newNode = new Node(e);
		p->node->pre->next = newNode;
		newNode->pre = p->node->pre;
		p->node->pre = newNode;
		newNode->next = p->node;
		size++;
	}
	void erase(Iterator* p) {
		if (size == 0)
			cout << "Empty\n";
		else {
			Node* deleNode = p->node;
			deleNode->next->pre = deleNode->pre;
			deleNode->pre->next = deleNode->next;
			size--;
			delete deleNode;
		}
	}
	void print() {
		if (size == 0) {
			cout << "Empty\n";
		}
		else {
			Node* curNode = head->next;
			for (int i = 0; i < size; i++) {
				cout << curNode->data << " ";
				curNode = curNode->next;
			}
			cout << endl;
		}
	}
	void find(int e) {
		if (size == 0)
			cout << "Empty\n";
		else {
			Node* curNode = head->next;
			int idx = 0;
			for (int i = 0; i < size; i++) {
				if (curNode->data == e) {
					cout << idx << endl;
					return;
				}
				idx++;
				curNode = curNode->next;
			}
			cout << "-1\n";
		}
	}
	void cinvolution(Iterator* p) {
		p->node = begin();
		for (int i = 0; i < size; i++) {
			cout << p->node->pre->data + (p->node->data)*3 + p->node->next->data << " ";
			++*p;
		}
		cout << endl;
	}
};

int main() {
	int t;
	string cmd;
	cin >> t;
	for (int i = 0; i < t; i++) {
		LinkedList* ls = new LinkedList();
		Iterator* p = new Iterator(ls->begin());
		int n;
		cin >> n;
		for (int j = 0; j < n; j++) {
			int pp;
			cin >> pp;
			ls->insert(p, pp);
		}
		ls->cinvolution(p);
	}
}
