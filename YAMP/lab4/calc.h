#ifndef CALC
#define CALC

#include <iostream>
#include <string>
#include <stack>

using namespace std;

struct operation
{
	char operation;
	int prior;
};


template <typename T>
struct Node
{
	T value;
	Node *next;
};

template <typename T>
class Queue
{
	Node<T> *head;
	Node<T> *last;
public:
	Queue();
	~Queue();
	void push(T a);
	void push_front(T a);
	void pop();
	void del();
	T find(size_t n);
	bool empty();
	T back();
	T front();
	size_t size();
	void print();
};

#endif