#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Priorityque {
private:
	vector<int> v;
public:
	bool empty() {
		return v.size() == 0;
	}
	void push(int e) {
		v.push_back(e);
	}
	int pop() {
		vector<int>::iterator iter;
		vector<int>::iterator maxiter = v.begin();
		int max = v.front();
		for (iter = v.begin(); iter != v.end(); iter++) {
			if (max < *iter) {
				max = *iter;
				maxiter = iter;
			}
		}
		v.erase(maxiter);
		return max;
	}
};
int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		vector<int> v;
		Priorityque pq;
		for (int j = 0; j < n; j++) {
			int k;
			cin >> k;
			v.push_back(k);
		}
		for (int j = 0; j < n; j++) {
			pq.push(v.front());
			v.erase(v.begin());
		}
		for (int j = 0; j < n; j++) {
			v.push_back(pq.pop());
		}
		for (int j = 0; j < n; j++) {
			cout << v[j] << " ";
		}
		cout << endl;
	}
}