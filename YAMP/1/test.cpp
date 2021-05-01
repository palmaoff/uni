#include <iostream>
#include <stack>
using namespace std;

struct Node
{
	int data;
	Node *left;
	Node *right;
};

class Tree
{
	Node *head;

	Node* add_node(int a)
	{
		Node *n = new Node;

		n->data = a;
		n->left = NULL;
		n->right = NULL;
		return n;		
	}
	void find(Node* h, int a)
	{
		if (h == NULL)
			head = add_node(a);
		if (h != NULL)
		{
			if (h->data > a)
				find(head->left, a);
			else if (h->data < a)
				find(head->right, a);
		}
	}
	int count(Node* h)
	{
		if (h == NULL)
			return 0;
		else
			return 1 + count(h->left) + count(h->right);
	}
	void	stack_add(stack<int> &st, Node* node)
	{
		if (node == NULL)
			return ;
		stack_add(st, node->left);
		if (node->data > 1)
			st.push(node->data);
		stack_add(st, node->right);
	}
	void print_tree(Node *t, int level)
	{
		if (t != NULL)
		{
			print_tree(t->right, level + 1);
			for (int i = 1; i <= level; i++)
				cout << ' ';
			cout << t->data << endl;
			print_tree(t->left, level + 1);
		}
	}

public:
	Tree() { head = NULL; }
	void add(int a)
	{
		find(head, a);
	}
	int count()
	{
		return count(head);
	}
	stack<int>	stack_one()
	{
		stack<int> st;
		stack_add(st, head);
		return st;
	}
	void print_tree()
	{
		print_tree(head, 0);
	}
};

int main()
{
	Tree t;
	int a;
	stack<int> st;

	for (int i = 0; i < 10; i++)
	{
		cin >> a;
		t.add(a);
	}
	// st = t.stack_one();
	// while (!st.empty())
	// {
	// 	cout << st.top();
	// 	st.pop();
	// }
	t.print_tree();
	return 0;
}
