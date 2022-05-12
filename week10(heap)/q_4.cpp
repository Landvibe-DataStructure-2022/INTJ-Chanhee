#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Heap {
private:
	
	vector<int> v;
	int rootidx;
public:
	int heapsize;
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
		int parent = idx / 2;
		if (v[parent] > v[idx]) {
			swap(parent,idx);
			upheap(parent);
		}
	}
	void insert(int x) {
		v.push_back(x);
		heapsize++;
		upheap(heapsize);
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
		else
			return;
	}
	int pop() {
		int top = v[rootidx];
		v[rootidx] = v[heapsize];
		v.pop_back();
		heapsize--;
		downheap(rootidx);
		return top;
	}
	int top() {
		return v[rootidx];
	}
	void print() {
		for (int i = 1; i <= heapsize; i++) {
			cout << v[i] << " ";
		}
		cout << endl;
	}
};
int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		int p;
		cin >> n >> p;
		Heap heap;
		for (int j = 0; j < n; j++) {
			int k;
			cin >> k;
			heap.insert(k);
		}
		while (true) {
			if (heap.top() >= p) {
				cout << "True" << endl;
				heap.print();
				break;
			}
			else if (heap.heapsize == 1) {
				cout << "False\n";
				break;
			}
			int idx1 = heap.pop();
			int idx2 = heap.pop();
			heap.insert((idx1 + idx2) / 2);
		}
	}
}