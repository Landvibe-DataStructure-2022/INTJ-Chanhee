#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Heap {
private:
	vector<int> v;
	
	int rootindex;
public:
	int heapsize;
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
		int parent = idx / 2;
		if (v[parent] > v[idx]) {
			swap(parent, idx);
			upheap(parent);
		}
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
	void insert(int i) {
		v.push_back(i);
		heapsize++;
		upheap(heapsize);
	}
	int pop() {
		if (heapsize == 0) {
			return -1;
		}
		int rv = v[rootindex];
		v[rootindex] = v[heapsize];
		heapsize--;
		v.pop_back();
		downheap(rootindex);
		return rv;
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
	int top() {
		if (heapsize == 0) {
			return -1;
		}
		return v[rootindex];
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
		int cnt = 0;
		while (true) {
			if (heap.top() >= p) {
				cout << cnt << endl;
				heap.print();
				break;
			}
			else if (heap.heapsize == 1) {
				cout << "False\n";
				break;
			}
			int fint = heap.pop();
			int sint = heap.pop();
			
			
			heap.insert((fint + sint) / 2);
			cnt++;
		}

	}
}