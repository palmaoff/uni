#include "hash.h"

int main() {
	HashTable table;

	table.Read("input.txt");

	string str;

	cin >> str;
	while (str != "q") {
		cout << table.Count(str) << endl;
		cin >> str;
	} 

	return 0;
}
