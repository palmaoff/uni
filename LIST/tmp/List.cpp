#include "List.h"

void Init(Tlist& list) {
	list = NULL;
}
bool empty(Tlist list) {
	return list == NULL;
}
void Add_to_head(Tlist& list, int elem) {
	Tlist _new = new Node;
	_new->info = elem;
	_new->next = list;
	list = _new;
}
void Add_to_end(Tlist& list, int elem) {
	Tlist _new = new Node;
	_new->info = elem;
	_new->next = NULL;
	if (list == NULL) list = _new;
	else {
		Tlist p = list;
		while (p->next != NULL)p = p->next;
		p->next = _new;
	}
}
void Print(Tlist list) {
	Tlist p = list;
	if (p == NULL) cout << "empty" << endl;
	else {
		while (p != NULL) {
			cout << p->info << ' ';
			p = p->next;
		}
		cout << endl;
	}
}
int del_from_head(Tlist& list) {
	Tlist p = list;
	list = list->next;
	int elem = p->info;
	p->next = NULL;
	delete p;
	return elem;
}
void Clear(Tlist& list) {
	while (!empty(list))del_from_head(list);
}
int count_nodes(Tlist list) {
	int count = 0;
	if (list != NULL) {
		Tlist ptr = list;
		while (ptr != NULL) {
			count++;
			ptr = ptr->next;
		}
	}
	return count;
}
void create_as_stack(Tlist& list, ifstream& file) {
	Init(list);
	int x;
	while (!file.eof()) {
		file >> x;
		Add_to_head(list, x);
	}
}
int max_negative(Tlist list) {
	int max = 0;
	if (list != NULL) {
		Tlist ptr = list;
		bool f = 0;
		while (ptr != NULL) {
			if (f) {
				if (ptr->info < 0 && max < ptr->info)max = ptr->info;
			}
			else {
				if (ptr->info < 0) { 
					max = ptr->info; 
					f = 1;
				}
			}
			ptr = ptr->next;
		}
	}
	return max;
}