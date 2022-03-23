#include<iostream>
#include<string>
using namespace std;
int t;
class stack {
private: 
		int arr[10];
		int top = -1;
public:
	int empty(){
		if (top == -1)
			return 1;
		else
			return 0;
	}
	int topp() {
		if (this->empty())
			return -1;
		else
			return arr[top];
	}
	void push(int x) {
		if (top + 1 == t) {
			cout << "FULL" << endl;
		}
		else
			arr[++top] = x;

	}
	void pop() {
		if (top == -1)
			cout << -1;
		else
			cout << arr[top--];
	}
};

int main() {
	stack* st = new stack();
	int n;
	cin >> t >> n;
	string input;
	for (int i = 0; i < n; i++) {
		cin >> input;
		if (input == "empty") {
			cout << st->empty() << endl;
		}
		else if (input == "top") {
			cout << st->topp() << endl;
		}
		else if (input == "push") {
			int x;
			cin >> x;
			st->push(x);
		}
		else if (input == "pop")
		{
			st->pop();
		}
	}
}
