#include<iostream>
#include<string>
using namespace std;

class Array
{
private:
	int* arr;
	int arrSize;
public:
	Array(int sz)
	{
		this->arrSize = sz;
		this->arr = new int[arrSize];
		for (int i = 0; i < arrSize; i++) {
			arr[i] = 0;
		}

	}

	void add(int i, int value) {
		for (int j = arrSize-2; j >= i; j--) {
			arr[j + 1] = arr[j];
		}
		arr[i] = value;
	}
	void remove(int i) {
		for (int j = i; j < arrSize - 1; j++) {
			arr[j] = arr[j + 1];
		}
		arr[arrSize-1] = 0;
	}
	void set(int i, int value) {
		arr[i] = value;
	}
	void print() {
		for (int i = 0; i < arrSize; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	void find(int value) {
		for (int i = 0; i < arrSize; i++) {
			if (value == arr[i]) {
				cout << i << endl;
				return;
			}
		}
		cout << "-1" << endl;
	}
	void shift(int d) {
		int *ars = new int[arrSize];
		for (int i = 0; i < arrSize-d; i++) {
			ars[i + d] = arr[i];
		}
		for (int i = arrSize - d; i < arrSize; i++)
		{
			ars[i + d - arrSize] = arr[i];
		}
		arr = ars;
	}
	void swap(int t, int k) {
		int temp = 0;
		temp = arr[t];
		arr[t] = arr[k];
		arr[k] = temp;
	}
	void reverse(int a, int b)
	{
		for (int i = a; i <= (a + b) / 2; i ++) {
			swap(b-(i-a),i);
			
		}
	}

};

int main()
{
	int t;
	int m;
	string sr;
	cin >> t >> m;
	Array ar(m);
	for (int i = 0; i < m; i ++) {
		int k;
		cin >> k;
		ar.set(i, k);
	}
	for (int i = 0; i < t; i++) {
		cin >> sr;
		if (sr == "shift") {
			int d;
			cin >> d;
			ar.shift(d);
		}
		else if (sr == "print") {
			ar.print();
		}
		else if (sr == "reverse") {
			int n;
			int v;
			cin >> n >> v;
			ar.reverse(n, v);
		}
	}
}