#include<iostream>
#include<string>
using namespace std;

class Queue {
private:
	int que[10000]{};
	int rearidx;
	int frontidx;
	int queuesize;

public:
	Queue() {
		rearidx = -1;
		frontidx = 0;
		queuesize = 0;
	}
	int size() {
		return queuesize;
	}
	bool isEmpty() {
		return queuesize==0;
	}
	void front() {
		if (isEmpty()) {
			cout << "Empty" << endl;
			return;
		}
		else {
			cout << que[frontidx] << endl;
			return;
		}
	}
	void rear() {
		if (isEmpty()) {
			cout << "Empty" << endl;
			return;
		}
		else {
			cout << que[rearidx] << endl;
			return;
		}
	}
	void enqueue(int value) {
		if (queuesize == 10000) {
			cout << "FULL" << endl;
			return;
		}
		else {
			que[++rearidx] = value;
		}
		queuesize++;
	}
	void dequeue() {
		if (isEmpty()) {
			cout << "Empty" << endl;
			return;
		}
		cout << que[frontidx++] << endl;
		queuesize--;
	}
};

int main() {
	Queue* q = new Queue();
	int n;
	int t;
	cin >> n >> t;
	string cmd;
	for (int i = 0; i < t; i++) {
		cin >> cmd;
		if (cmd == "enqueue") {
			int v;
			cin >> v;
			q->enqueue(v);
		}
		else if (cmd == "dequeue") {
			q->dequeue();
		}
		else if (cmd == "isEmpty") {
			if (q->isEmpty())
				cout << "True" << endl;
			else
				cout << "False" << endl;
		}
		else if (cmd == "size") {
			cout << q->size() << endl;
		}
		else if (cmd == "front") {
			q->front();
		}
		else if (cmd == "rear") {
			q->rear();
		}
	}
}