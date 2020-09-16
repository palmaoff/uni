#include <iostream>
using namespace std;

struct Node {
	float data;
	Node *next;
};

void    list_init(Node **head);

// add
void	add_start(Node* &head, float data);
void	add_end(Node* &head, float data);
void    add_after(Node* node, float data);

// del
void	del_head(Node* &head);
void	del_end(Node* &head);
void	del_after(Node* &node);

// more
void	list_print(Node *a);


/*
list_new		
list_init		^
list_print		^
list_add_start	^
list_add_end	^
list_del		
del_after_node	
del_head		
list_count		
list_check_nil	
list_new_sort	
*/
