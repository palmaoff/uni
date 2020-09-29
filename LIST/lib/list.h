#include <iostream>
using namespace std;

#ifndef LIST
#define LIST

struct Node
{
	float data;
	Node *next;
};

// base
void    list_init(Node* &head);
bool	is_empty(Node* head);

// add
void	add_start(Node* &head, float data);
void	add_end(Node* &head, float data);
void    add_after(Node* node, float data);
void	add_node(Node* &node, float data);

// del
void	node_del(Node* &node);
void	list_del(Node* &node);

// more
int		list_count(Node* head);
void	list_print(Node *a);
Node*	list_new_sort(Node* l1, Node* l2);


/*
delete_all
file input && output
*/

#endif
