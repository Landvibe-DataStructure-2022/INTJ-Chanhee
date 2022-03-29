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
	int dequeue() {
		if (isEmpty()) {
			cout << "Empty\n";
			return 0;
		}
		node* delenode = new node();
		delenode = head;
		
		if (arrsize == 1) {
			head = tail = nullptr;
		}
		else {
			head = head->next;
		}
		return delenode->data;
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
	
	int t,n;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int q1_remain = 0;
		int q2_remain = 0;
		int q1_s=0;
		int q2_s = 0;
		Queue* q = new Queue[2];
		cin >> n;
		for (int j = 0; j < n; j++) {
			int k;
			cin >> k;
			q[0].enqueue(k);
		}
		for (int j = 0; j < n; j++) {
			int k;
			cin >> k;
			q[1].enqueue(k);
		}
		for (int j = 1; j <= n; j++) {
			int q1 = q[0].dequeue() + q1_remain;
			int q2 = q[1].dequeue() + q2_remain;
			//cout << "Round";
			cout << j;
			if (q1 > q2) {
				q1_remain = q1 - q2;
				q2_remain = 0;
				q1_s++;
				//cout << " P1 " << q1_remain << endl;
				
			}
			else if(q1 < q2) {
				q2_remain = q2 - q1;
				q1_remain = 0;
				q2_s++;
				//cout << " P2 " << q2_remain << endl;
			}
			else {
				q1_remain = 0;
				q2_remain = 0;
				//cout << " Draw " << endl;
			}

			
		}
		if (q2_s > q1_s)
			cout << q2_s << endl;
		else if (q1_s > q2_s)
			cout << q1_s << endl;
		else
			cout << q1_s << endl;
	}
}