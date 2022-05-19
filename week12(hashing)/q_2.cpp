#include<iostream>
#include<string>
using namespace std;
#define ISHAVE 1
#define NOHAVE 0
struct Entry {
	int key;
	int valid;
	Entry() {
		key = 0;
		valid = NOHAVE;
	}
	Entry(int k) {
		key = k;
		valid = ISHAVE;
	}
};

class hashTable {
private:
	int x;
	int y;
	
	Entry* hash_table;
public:
	int xindex;
	int yindex;
	hashTable(int x_,int y_) {
		x = x_;
		y = y_;
		xindex = 0;
		yindex = 0;
		hash_table = new Entry[x];
	}
	int rotate(int key, int offset, int divisor, bool isClock) {
		int returnvalue = 0;
		if (isClock) {
			if (offset - key % divisor < 0) {
				returnvalue = divisor + offset - key % divisor;
			}
			else {
				returnvalue = offset - key % divisor;
			}
		}
		else {
			returnvalue = (offset + key % divisor) % divisor;
		}
		return returnvalue;
	}
	int hash_funcX(int key, int offset, bool isClock) {
		return rotate(key, offset, x, isClock);
	}
	int hash_funcY(int key, int offset, bool isClock) {
		return rotate(key, offset, y, isClock);
	}
	void put(int xidx, int yidx, int k) {
		xindex = hash_funcX(k, xidx, false);
		yindex = hash_funcY(k, yidx, true);
		int probing = 1;
		if (hash_table[xindex].valid == ISHAVE && probing <= x) {
			xindex = hash_funcX(yindex + 1, xindex, false);
			yindex = hash_funcY(yindex + 1, yindex, true);
			probing++;
		}
		while (hash_table[xindex].valid == ISHAVE && probing <= x) {
			xindex = hash_funcX(1, xindex, true);
			yindex = hash_funcY(1, yindex, false);
			probing++;
		}
		if (probing > x) {
			return;
		}
		hash_table[xindex] = Entry(k);
		cout << xindex+1 << " ";
	}
};
int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int x, y, n;
		cin >> x >> y >> n;
		hashTable ht(x, y);
		for (int j = 0; j < n; j++) {
			int k;
			cin >> k;
			ht.put(ht.xindex, ht.yindex, k);
			
		}
		cout << endl;
	}
}