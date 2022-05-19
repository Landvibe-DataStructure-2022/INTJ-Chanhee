#include<iostream>
#include<string>
using namespace std;

#define NOITEM 0
#define ISITEM 1
#define AVAILABLE 2

struct Entry {
	int key;
	string value;
	int valid;
	Entry() {
		key = 0;
		value = "";
		valid = 0;
	}
	Entry(int k, string v) {
		key = k;
		value = v;
		valid = ISITEM;
	}
	void erase() {
		valid = AVAILABLE;
	}
};

class hashTable {
private:
	int capacity;
	Entry* hash_table;
	int mod;
public:
	int hash_func1(int k) {
		return k % capacity;
	}
	int hash_func2(int k) {
		return mod - k % mod;
	}
	hashTable(int c,int m) {
		capacity = c;
		hash_table = new Entry[capacity];
		mod = m;
	}
	void put(int k, string s) {
		int index = hash_func1(k);
		int probing = 1;
		while (hash_table[index].valid == ISITEM && probing <= capacity) {
			index = hash_func1(index + hash_func2(k));
			probing++;
		}
		if (probing > capacity) {
			return;
		}
		hash_table[index] = Entry(k, s);
		cout << probing << endl;
	}
	void erase(int k) {
		int index = hash_func1(k);
		int probing = 1;
		while (hash_table[index].valid != NOITEM && probing <= capacity) {
			if (hash_table[index].valid == ISITEM && hash_table[index].key == k) {
				hash_table[index].erase();
				return;
			}
			probing++;
			index = hash_func1(index + hash_func2(k));
		}
		cout << "None\n";
	}
	string find(int k) {
		int index = hash_func1(k);
		int probing = 1;
		while (hash_table[index].valid != NOITEM && probing <= capacity) {
			if (hash_table[index].valid == ISITEM && hash_table[index].key == k) {
				return hash_table[index].value;
			}
			probing++;
			index = hash_func1(index + hash_func2(k));
		}
		return "None";
	}
};

int main() {
	int t, n, m;
	cin >> t >> n >> m;
	string cmd;
	hashTable ht(n,m);
	for (int i = 0; i < t; i++) {
		cin >> cmd;
		if (cmd == "put") {
			int k;
			string s;
			cin >> k >> s;
			ht.put(k, s);
		}
		else if (cmd == "erase") {
			int k;
			cin >> k;
			ht.erase(k);
		}
		else if (cmd == "find") {
			int k;
			cin >> k;
			cout << ht.find(k) << endl;
		}
	}
}