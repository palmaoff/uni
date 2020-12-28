#ifndef LIST
#define LIST

#include <iostream>
using namespace std;

struct Node
{
	float data;
	Node *next;
};

class list
{
	Node *head;

public:
	// constructor
	list();

	// base functions
	void init();
	bool is_empty();

	// add functions
	void add_start(float data);
	void add_end(float data);
	void add_after(Node *node, float data);
	void add(Node *&node, float data);

	// delete functions
	void del();
	void del(Node *&node);

	// additional functions
	int count();
	void print();
	list new_sort(list l);
	void print_in_file();
	bool is_sort();
};

#endif
