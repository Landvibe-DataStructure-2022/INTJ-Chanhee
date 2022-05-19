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
		valid = NOITEM;
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
	Entry* hash_table;
	int capacity;
public:
	int hash_func(int key) {
		return key % capacity;
	}
	hashTable(int c) {
		capacity = c;
		hash_table = new Entry[capacity];
	}
	void put(int k, string s) {
		int index = hash_func(k);
		int probing = 1;
		while (hash_table[index].valid == ISITEM && probing <= capacity) {
			index = hash_func(index + 1);
			probing++;
		}
		cout << probing << endl;
		if (probing > capacity) {
			return;
		}
		hash_table[index] = Entry(k, s);
	}
	void erase(int k) {
		int index = hash_func(k);
		int probing = 1;
		while (hash_table[index].valid != NOITEM && probing <= capacity) {
			if (hash_table[index].valid == ISITEM && hash_table[index].key == k) {
				hash_table[index].erase();
				return;
			}
			index = hash_func(index + 1);
			probing++;
		}
		cout << "None\n";
	}
	string find(int k) {
		int index = hash_func(k);
		int probing = 1;
		while (hash_table[index].valid != NOITEM && probing <= capacity) {
			if (hash_table[index].valid == ISITEM && hash_table[index].key == k) {
				return hash_table[index].value;
			}
			index = hash_func(index + 1);
			probing++;
		}
		return "None";
	}
};

int main() {
	int t,n;
	cin >> t >> n;
	hashTable ht(n);
	string cmd;
	for (int i = 0; i < t; i++) {
		cin >> cmd;
		if (cmd == "put") {
			int k;
			string v;
			cin >> k >> v;
			ht.put(k, v);
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