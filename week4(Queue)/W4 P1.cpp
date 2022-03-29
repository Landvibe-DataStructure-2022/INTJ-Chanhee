#include<iostream>
#include<string>
using namespace std;
class node
{
private:
	int data;
	node* next;
public:
	node() {
		data = 0;
		next = nullptr;
	}
	friend class Queue;
};
class Queue
{
private:
	node* head;
	node* tail;
	int arrsize;
public:
	Queue() {
		head = tail = nullptr;
		arrsize = 0;
	}
	bool isEmpty() {
		if (arrsize == 0)
			return true;
		else
			return false;
	}
	void enqueue(int v) {
		node* curnode = new node();
		curnode->data = v;
		if (arrsize == 0) {
			tail = head = curnode;
		}
		else {
			tail->next = curnode;
			tail = curnode;
		}
		arrsize++;
	}
	void dequeue() {
		if (isEmpty()) {
			cout << "Empty\n";
			return;
		}
		node* delenode = new node();
		delenode = head;
		cout << head->data << endl;
		if (arrsize == 1) {
			head = tail = nullptr;
		}
		else {
			head = head->next;
		}
		delete delenode;
		arrsize--;
	}
	int size() {
		return arrsize;
	}
	void front() {
		if (this->isEmpty()) {
			cout << "Empty\n";
			return;
		}
		node* curnode = new node();
		curnode = head;
		cout << head->data << endl;
	}
	void rear() {
		if (this->isEmpty()) {
			cout << "Empty\n";
			return;
		}
		node* curnode = new node();
		curnode = this->tail;
		cout << curnode->data << endl;
	}
};

int main() {
	int t;
	cin >> t;
	Queue q;

	while (t--) {
		string cmd;
		cin >> cmd;

		if (cmd == "enqueue") {
			int value;
			cin >> value;
			q.enqueue(value);
		}
		else if (cmd == "dequeue") {
			q.dequeue();
		}
		else if (cmd == "isEmpty") {
			if (q.isEmpty()) {
				cout << "True\n";
			}
			else {
				cout << "False\n";
			}
		}
		else if (cmd == "size") {
			cout << q.size() << "\n";
		}
		else if (cmd == "front") {
			q.front();
		}
		else if (cmd == "rear") {
			q.rear();
		}
	}

	return 0;
}