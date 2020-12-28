#include "tree.h"

Tree::Tree()
{
	head = NULL;
}

Tree::	~Tree()
{
	del();
	head = NULL;
}

void	Tree::add(int data)
{
	add_node(head, data);	
}

void	Tree::add_node(Node* &curr, int data)
{
	if (curr == NULL)
	{
		curr = new Node();
		curr->p = NULL;
		curr->l = NULL;
		curr->r = NULL;
		curr->data = data;
	}
	else if (curr->data > data)
	{
		// left
		if (curr->l != NULL)
			add_node(curr->l, data);
		else
		{
			curr->l = new Node();
			curr->l->p = curr;
			curr->l->l = NULL;
			curr->l->r = NULL;
			curr->l->data = data;
		}
	}
	else if (curr->data < data)
	{
		// right
		if (curr->r != NULL)
			add_node(curr->r, data);
		else
		{
			curr->r = new Node();
			curr->r->p = curr;
			curr->r->l = NULL;
			curr->r->r = NULL;
			curr->r->data = data;
		}
	}
}

void	Tree::show(Node* curr, int depth)
{
	if (curr != NULL)
	{
		show(curr->r, depth + 1);
		for (int i = 0; i < depth; i++)
			cout << "\t";
		cout << curr->data << endl;
		show(curr->l, depth + 1);
	}
}

void	Tree::show_2(Node* curr, int depth)
{
	if (curr != NULL)
	{
		cout << curr->data << " ";
		show_2(curr->r, depth + 1);
		show_2(curr->l, depth + 1);
	}
}

void	Tree::show_3(Node* curr, int depth)
{
	if (curr != NULL)
	{
		show_3(curr->r, depth + 1);
		show_3(curr->l, depth + 1);
		cout << curr->data << " ";
	}
}

void	Tree::print()
{
	show(head, 0);
}

void	Tree::print_2()
{
	show_2(head, 0);
	cout << endl;
}

void	Tree::print_3()
{
	show_3(head, 0);
	cout << endl;
}

Node*	Tree::find_node(Node* curr, int data)
{
	if (curr == NULL)
		return NULL;
	else if (curr->data < data)
		return find_node(curr->r, data);
	else if (curr->data > data)
		return find_node(curr->l, data);
	return curr;
}

Node*	Tree::find(int data)
{
	return find_node(head, data);
}

void	Tree::del_node(Node* &curr)
{
	if (curr != NULL)
	{
		del_node(curr->l);
		del_node(curr->r);
		delete curr;
		curr = NULL;
	}
}

void	Tree::del()
{
	del_node(head);
}

bool	Tree::del(int data)
{
	Node* curr = find(data);
	Node* tmp;

	if (curr == NULL)
		return 0;

	// если удаляем корень
	if (curr == head)
	{
		if (curr->r != NULL)
			tmp = curr->r;
		else
			tmp = curr->l;
		while (tmp->l != NULL)
			tmp = tmp->l;
		int data = tmp->data;
		del(data);
		curr->data = data;
		return 1;
	}

	// удаляем листья
	else if (curr->l == NULL && curr->r == NULL && curr->p != NULL)
	{
		// cout << "yes\n";
		if (curr == curr->p->l)
			curr->p->l = NULL;
        else if (curr == curr->p->r)
			curr->p->r == NULL;
		delete curr;
		curr = NULL;
		return 1;
	}

	// удаление узла с левым поддеревом, но без правого
	else if (curr->l != NULL && curr->r == NULL)
	{
		curr->l->p = curr->p;
		if (curr->p->l == curr)
			curr->p->l =curr->l;
		else if (curr->p->r == curr)
			curr->p->r =curr->l;
		delete curr;
		curr = NULL;
		return 1;
	}

	// удаление узла с правым поддеревом, но без левого
	else if (curr->l == NULL && curr->r != NULL)
	{
		curr->r->p = curr->p;
		if (curr->p->l == curr)
			curr->p->l =curr->r;
		else if (curr->p->r == curr)
			curr->p->r =curr->r;
		delete curr;
		curr = NULL;
		return 1;
	}

	// удаление узла с двумя поддеревьями
	else if (curr->l != NULL && curr->r != NULL)
	{
		tmp = curr->r;

		while (tmp->l != NULL)
			tmp = tmp->l;
		
		if (tmp->p == curr)
		{
			tmp->l = curr->l;
			curr->l->p = tmp;
			tmp->p = curr->p;
			if (curr->p->l == curr)
				curr->p->l = tmp;
			else if (curr->p->r == curr)
				curr->p->r = tmp;
			delete curr;
			curr = NULL;
		}
		else
		{
			if (tmp->r != NULL)
				tmp->r->p = tmp->p;
			tmp->p->l = tmp->r;
			tmp->r = curr->r;
			tmp->l = curr->l;
			curr->l->p = tmp;
			curr->r->p = tmp;
			tmp->p = curr->p;
			if (curr == curr->p->l)
				curr->p->l = tmp;
			else if (curr == curr->p->r)
				curr->p->r = tmp;
			delete curr;
			curr = NULL;
		}
		return 1;
	}
	return 0;
}

int		Tree::max_odd()
{
	int max = 0;
	max_odd(head, max);
	return max;
}

void	Tree::max_odd(Node* curr, int &max)
{
	if (curr != NULL)
	{
		if (curr->data > max && curr->data % 2 == 1)
			max = curr->data;
		max_odd(curr->l, max);
		max_odd(curr->r, max);
	}
}
