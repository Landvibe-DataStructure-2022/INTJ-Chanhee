#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Heap {
private:
	int heapsize;
	vector<int> v;
	int rootidx;
public:
	Heap() {
		heapsize = 0;
		rootidx = 1;
		v.push_back(-1);
	}
	void swap(int idx1, int idx2) {
		v[0] = v[idx1];
		v[idx1] = v[idx2];
		v[idx2] = v[0];
	}
	void upheap(int idx) {
		if (idx == rootidx) {
			return;
		}
		int parent = idx / 2;
		if (v[parent] > v[idx]) {
			swap(parent, idx);
			upheap(parent);
		}
	}
	void insert(int x) {
		v.push_back(x);
		heapsize++;
		upheap(heapsize);
	}
	int size() {
		return heapsize;
	}
	bool isEmpty() {
		return heapsize == 0;
	}
	void downheap(int idx) {
		int right = idx * 2 + 1;
		int left = idx * 2;
		if (right <= heapsize) {
			if (v[left] < v[right]) {
				if (v[left] < v[idx]) {
					swap(left, idx);
					downheap(left);
				}
				else
					return;
			}
			else {
				if (v[right] < v[idx]) {
					swap(right, idx);
					downheap(right);
				}
				else
					return;
			}
		}
		else if (left <= heapsize) {
			if (v[left] < v[idx]) {
				swap(left, idx);
				downheap(left);
			}
			else
				return;
		}
	}
	int pop() {
		if (isEmpty()) {
			return -1;
		}
		int top = v[rootidx];
		v[rootidx] = v[heapsize];
		heapsize--;
		v.pop_back();
		downheap(rootidx);
		return top;
	}
	void top() {
		if (heapsize == 0) {
			cout << "-1" << endl;
			return;
		}
		cout << v[rootidx] << endl;
	}
	void print() {
		if (heapsize == 0) {
			cout << -1 << endl;
			return;
		}
		for (int i = 1; i <= heapsize; i++) {
			cout << v[i] << " ";
		}
		cout << endl;
	}
};

int main() {
	int t;
	cin >> t;

	Heap heap;

	while (t--) {
		string cmd;
		cin >> cmd;

		if (cmd == "insert") {
			int i;
			cin >> i;
			heap.insert(i);
		}
		else if (cmd == "size") {
			cout << heap.size() << endl;
		}
		else if (cmd == "isEmpty") {
			cout << heap.isEmpty() << endl;
		}
		else if (cmd == "pop") {
			cout << heap.pop() << endl;
		}
		else if (cmd == "top") {
			heap.top();
		}
		else if (cmd == "print") {
			heap.print();
		}
	}
	return 0;
}