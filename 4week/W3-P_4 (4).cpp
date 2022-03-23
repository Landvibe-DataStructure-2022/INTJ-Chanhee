#include<iostream>
#include<string>
using namespace std;
int t = 100;
class stack {
private:
	int arr[100]{};
	int top;
public:
	stack() {
		top = -1;
	}
	int empty() {
		if (top == -1)
			return 1;
		else
			return 0;
	}
	int topp() {
		if (this->empty())
			return  -1;
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
	int pop() {
		if (top == -1)
			return -1;
		else
			return arr[top--];
	}
};

int main() {

	int n;
	cin >> n;
	string str;
	for (int i = 0; i < n; i++) {
		stack* st = new stack();
		cin >> str;
		for (int i = 0; i < str.length(); i++) {
			if (str[i] - '0' >= 0 && str[i] - '0' <= 9) {
				st->push(str[i] - '0');
			}
			else {
				int num2 = st->pop();
				int num1 = st->pop();

				if (str[i] == '+') {
					st->push((num1 + num2));
				}
				else if (str[i] == '-') {
					st->push((num1 - num2));
				}
				else if (str[i] == '*') {
					st->push((num1 * num2));
				}
			}
		}
		cout << st->pop()<< endl;
	}
}
