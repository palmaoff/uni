#include "hash.h"

size_t getHash(string str) {
	int count = 0;
	for (int i = 0; i < str.length(); i++)
		count += str[i] - 'a';
	return count;
}

void HashTable::Add(string str) {
	data[getHash(str)].node.push_back(str);
}

bool HashTable::Find(string str) {
	list <string> curr = data[getHash(str)].node;
	list <string> :: iterator it;

	for (it = curr.begin(); it != curr.end() && !curr.empty(); it++)
		if ((*it) == str)
			return 1;
	return 0;
}

size_t HashTable::Count(string str) {
	list <string> curr = data[getHash(str)].node;
	list <string> :: iterator it;
	size_t count = 0;

	if (curr.empty())
		return 0;
	for (it = curr.begin(); it != curr.end() && !curr.empty(); it++)
		if ((*it) == str)
			count++;
	return count;
}

void HashTable::Read(string file) {
	ifstream f;
	string str;
	size_t n;

	f.open(file);
	f >> n;
	for (int i = 0; i < n; i++) {
		f >> str;
		Add(str);
	}
	
	f.close();
}
