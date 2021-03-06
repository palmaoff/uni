#ifndef LIST
#define LIST

#include <iostream>
using namespace std;

struct	Node
{
	float data;
	Node *next;
};	

//		base functions
void    list_init(Node* &head);
bool	is_empty(Node* head);

//		add functions
void	add_start(Node* &head, float data);
void	add_end(Node* &head, float data);
void    add_after(Node* node, float data);
void	add_node(Node* &node, float data);

//		delete functions
void	node_del(Node* &node);
void	list_del(Node* &node);

//		additional functions
int		list_count(Node* head);
void	list_print(Node *a);
Node*	list_new_sort(Node* l1, Node* l2);

#endif
