#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Heap {
private:
	vector<int> v;
	int heapsize;
	int rootindex;
public:
	Heap() {
		v.push_back(-1);
		heapsize = 0;
		rootindex = 1;
	}
	void swap(int idx1, int idx2) {
		v[0] = v[idx1];
		v[idx1] = v[idx2];
		v[idx2] = v[0];
	}
	void upheap(int idx) {
		if (idx == rootindex)
			return;
		int parent = idx/2;
		if (v[parent] < v[idx]) {
			swap(parent, idx);
			upheap(parent);
		}
	}
	void downheap(int idx) {
		int right = idx * 2 + 1;
		int left = idx * 2;
		if (right <= heapsize) {
			if (v[right] > v[left]) {
				if (v[right] > v[idx]) {
					swap(right, idx);
					downheap(right);
				}
				else
					return;
			}
			else {
				if (v[left] > v[idx]) {
					swap(left, idx);
					downheap(left);
				}
				else
					return;
			}
		}
		else if (left <= heapsize) {
			if (v[left] > v[idx]) {
				swap(left, idx);
				downheap(left);
			}
			else
				return;
		}
		else
			return;
	}
	void insert(int i) {
		v.push_back(i);
		heapsize++;
		upheap(heapsize);
	}
	void pop() {
		if (heapsize == 0) {
			cout << "-1" << endl;
			return;
		}
		cout << v[rootindex] << endl;
		v[rootindex] = v[heapsize];
		heapsize--;
		v.pop_back();
		downheap(rootindex);
	}
	void size() {
		cout << heapsize << endl;
	}
	void isEmpty() {
		if (heapsize == 0) {
			cout << "1" << endl;
		}
		else {
			cout << "0" << endl;
		}
	}
	void top() {
		if (heapsize == 0) {
			cout << "-1" << endl;
			return;
		}
		cout << v[rootindex] << endl;
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
			heap.size();
		}
		else if (cmd == "isEmpty") {
			heap.isEmpty();
		}
		else if (cmd == "pop") {
			 heap.pop();
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