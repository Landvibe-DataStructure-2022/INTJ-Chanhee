#include<iostream>
using namespace std;
struct node {
	int data;
	node* next;
};

class listStack {
public:
	listStack();
	bool empty();
	int size();
	int top();
	void push(int data);
	void pop();
private:
	node* topNode;
	int n;
};
listStack::listStack() {
	topNode = NULL;
	n = 0;

}

bool listStack::empty() {
	return (n == 0);
}

int listStack::size() {
	return n;
}
int listStack::top() {
	if(empty())
		return -1;
	return topNode->data;
}

void listStack::push(int data) {
	node* newNode = new node();
	newNode->data = data;
	newNode->next = topNode;
	topNode = newNode;
	n++;
}

void listStack::pop() {
	if (empty()) {
		cout << -1 << endl;
		return;
	}
	node* curNode = topNode;
	cout << curNode->data << endl;
	topNode = topNode->next;
	delete curNode;
	n--;
}

int main() {
	int n;
	cin >> n;
	string str;
	listStack* ls = new listStack();
	for (int i = 0; i < n; i++) {
		cin >> str;
		if (str == "empty") {
			cout << ls->empty() << endl;
		}
		else if (str == "top") {
			cout << ls->top() << endl;
		}
		else if (str == "push") {
			int data;
			cin >> data;
			ls->push(data);
		}
		else if (str == "pop") {
			ls->pop();
		}
	}
}
