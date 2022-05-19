#include<iostream>
#include<string>
using namespace std;
#define ISHAVE 1
#define NOHAVE 0
struct Entry {
	int valid;
	int key;
	Entry() {
		valid = NOHAVE;
		key = 0;
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
	int xindex;
	int yindex;
	Entry* hash_table;
public:
	hashTable(int _x, int _y) {
		x = _x;
		y = _y;
		xindex = 0;
		yindex = 0;
		hash_table = new Entry[x];
	}
	int rotate(int key, int divisor, int offset, bool isClock) {
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
		return rotate(key, x, offset, isClock);
	}
	int hash_funcY(int key, int offset, bool isClock) {
		return rotate(key, y, offset, isClock);
	}
	void put(int k) {
		xindex = hash_funcX(k, xindex, false);
		yindex = hash_funcY(k, yindex, true);
		int probing = 1;
		if (hash_table[xindex].valid == ISHAVE && probing <= x) {
			xindex = hash_funcX(yindex + 1, xindex, true);
			yindex = hash_funcY(yindex + 1, yindex, false);
			probing++;
		}
		while (hash_table[xindex].valid == ISHAVE && probing <= x) {
			xindex = hash_funcX(1, xindex, false);
			yindex = hash_funcY(1, yindex, true);
			probing++;
		}
		if (probing > x) {
			return;
		}
		hash_table[xindex] = Entry(k);
		cout << xindex + 1 << " ";
	}
};
int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int x, y, n;
		cin >> x >> y >> n;
		hashTable hs(x, y);
		for (int i = 0; i < n; i++) {
			int k;
			cin >> k;
			hs.put(k);
		}
		cout << endl;
	}
}