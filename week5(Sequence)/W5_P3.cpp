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
	friend class LinkedList;
	friend class Iterator;
};
class Iterator {
private:
	Node* node;
public:
	Iterator() {
		node = nullptr;
	}
	Iterator(Node* n) {
		node = n;
	}
	void setIterator(Node* node) {
		this->node = node;
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
		head = new Node;
		tail = new Node;
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
		newNode->next = p->node;
		p->node->pre = newNode;
		size++;
	}
	void erase(Iterator* p) {
		if (size == 0) {
			cout << "Empty\n";
		}
		else {
			Node* deleNode = p->node;
			deleNode->pre->next = deleNode->next;
			deleNode->next->pre = deleNode->pre;
			p->node = begin();
			size--;
			delete deleNode;
		}
	}
	void reverseprint() {
		if (size == 0) {
			cout << "Empty" << endl;
			return;
		}
		Node* curNode = new Node;
		curNode = tail->pre;
		for (int i = 0; i < size; i++) {
			cout << curNode->data << " ";
			curNode = curNode->pre;
		}
		cout << endl;
	}
	void find(int e) {
		if (size == 0) {
			cout << "Empty\n";
			return;
		}
		Node* curNode = new Node;
		curNode = head->next;
		int idx = 0;
		for (int i = 0; i < size; i++) {
			if (curNode->data == e) {
				cout << idx << endl;
				return;
			}
			curNode = curNode->next;
			idx++;
		}
		cout << "-1\n";
	}
};

int main() {
	LinkedList* ls = new LinkedList();
	Iterator* p = new Iterator(ls->begin());
	int m;
	string str;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> str;
		if (str == "begin") {
			p->setIterator(ls->begin());
		}
		else if (str == "end") {
			p->setIterator(ls->end());
		}
		else if (str == "insert") {
			int e;
			cin >> e;
			ls->insert(p, e);
		}
		else if (str == "erase") {
			ls->erase(p);
		}
		else if (str == "++") {
			++* p;
		}
		else if (str == "--") {
			--* p;
		}
		else if (str == "reverseprint") {
			ls->reverseprint();
		}
		else if (str == "find") {
			int e;
			cin >> e;
			ls->find(e);
		}
	}
}