#include <iostream>
using namespace std;

struct Node {
	float data;
	Node *next;
};

void	list_print(Node *a);
Node	*node_add_start(float data, Node *head);

/* 
list_init
list_print ^
list_add_start
list_add_end
list_del
list_count
list_check_nil
list_new_sort
*/
