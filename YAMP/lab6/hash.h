#ifndef HASH
#define HASH

#include <iostream>
#include <fstream>
#include <list>
using namespace std;

#define H_SIZE 1000

struct HashInf {
	list<string> node;
};

class HashTable {
	HashInf data[H_SIZE];

public:
	// HashTable();
	void Add(string str);
	bool Find(string str);
	size_t Count(string str);
	void Del(string str);
	void Read(string file);
};

#endif
