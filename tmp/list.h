#ifndef LIST
#define LIST

#include <iostream>
using namespace std;

struct Node
{
	int inf;
	Node* next;
	Node* prev;
};

void	print_list(Node* head);
void	list_init(Node* &head);
void	add_end(Node* &head, int inf);
void	del(Node *&head);
int		del_first(Node *&head);
int		count_k(Node *head, int k);

#endif
