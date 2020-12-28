#ifndef TREE
#define TREE

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Node
{
	int data;
	Node* p;
	Node* l;
	Node* r;
};

class Tree
{
	Node* head;

	void	del_node(Node* &curr);
	void	add_node(Node* &curr, int data);
	void	show(Node* curr, int depth);
	void	show_2(Node* curr, int depth);
	void	show_3(Node* curr, int depth);
	Node*	find_node(Node* curr, int data);
	void	max_odd(Node* curr, int &max);
public:
	Tree();
	~Tree();
	void	add(int data);
	Node*	find(int data);
	bool	del(int data);
	void	del();
	void	print();
	void	print_2();
	void	print_3();
	int		max_odd();
};

#endif