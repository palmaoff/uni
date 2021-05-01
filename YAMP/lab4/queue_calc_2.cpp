#include "calc.h"

template <typename T>
Queue<T>::Queue()
{
	head = NULL;
	last = NULL;
}

template <typename T>
Queue<T>::~Queue()
{
	while (head != NULL)
	{
		last = head;
		head = head->next;
		delete last;
	}

	head = NULL;
	last = NULL;
}

template <typename T>
void Queue<T>::push_front(T a)
{
	Node<T> *n = new Node<T>();

	n->value = a;
	n->next = head;
	head = n;
}

template <typename T>
void Queue<T>::del()
{
	while (head != NULL)
	{
		last = head;
		head = head->next;
		delete last;
	}

	head = NULL;
	last = NULL;
}

template <typename T>
bool Queue<T>::empty()
{
	return head == NULL;
}

template <typename T>
void Queue<T>::push(T a)
{
	Node<T> *n = new Node<T>();
	Node<T> *cur = head;

	n->next = NULL;
	n->value = a;
	last = n;

	if (cur == NULL)
	{
		head = n;
		last = n;
	}
	else
	{
		while (cur->next != NULL)
			cur = cur->next;
		cur->next = n;
	}
}

template <typename T>
void Queue<T>::pop()
{
	Node<T> *tmp = head;

	if (head != NULL)
	{
		head = head->next;
		delete tmp;
	}
}

template <typename T>
T Queue<T>::find(size_t n)
{
	size_t i = 0;
	Node<T> *cur = head;

	while (i < n && cur != NULL)
	{
		cur = cur->next;
		i++;
	}
	if (cur != NULL)
		return cur->value;
	return -1;
}

template <typename T>
T Queue<T>::front()
{
	return head->value;
}

template <typename T>
T Queue<T>::back()
{
	return last->value;
}

template <typename T>
size_t Queue<T>::size()
{
	size_t i = 0;
	Node<T> *cur = head;

	if (head != NULL)
	{
		while (cur != NULL)
		{
			i++;
			cur = cur->next;
		}
	}

	return i;
}

template <typename T>
void Queue<T>::print()
{
	Node<T> *cur = head;

	if (cur == NULL)
		cout << "empty";
	while (cur != NULL)
	{
		cout << cur->value << " ";
		cur  = cur->next;
	}
	cout << endl;
}

bool do_operation(Queue<int> &digits, Queue<operation> &op)
{
	operation o;
	float a, b;

	if (!op.empty())
	{
		o = op.front();
		op.pop();
	}
	else return 1;

	if (digits.size() > 1)
	{
		b = digits.front();
		digits.pop();
		a = digits.front();
		digits.pop();
	}
	else return 1;

	if (o.operation == '+')
		digits.push_front(a + b);
	if (o.operation == '-')
		digits.push_front(a - b);
	if (o.operation == '*')
		digits.push_front(a * b);
	if (o.operation == '/' && b != 0)
		digits.push_front(a / b);
	if (o.operation == '/' && b == 0)
		return 1;
	
	return 0;
}

bool read(Queue<int> &digits, Queue<operation> &op)
{
	string c;
	size_t prior = 0;
	bool err = 0;

	cin >> c;

	if (c == "=")
		return 1;

	if (c[0] >= '1' && c[0] <= '9')
		digits.push_front(stoi(c));
	else
	{
		operation o;

		if (c == "+")
		{
			o.operation = '+';
			o.prior = 2;
			while (!op.empty() && op.front().prior >= o.prior && !err)
				err = do_operation(digits, op);
			op.push_front(o);
		}
		else if (c == "-")
		{
			o.operation = '-';
			o.prior = 2;
			while (!op.empty() && op.front().prior >= o.prior && !err)
				err = do_operation(digits, op);
			op.push_front(o);
		}
		else if (c == "*")
		{
			o.operation = '*';
			o.prior = 3;
			while (!op.empty() && op.front().prior >= o.prior && !err)
				err = do_operation(digits, op);
			op.push_front(o);
		}
		else if (c == "/")
		{
			o.operation = '/';
			o.prior = 3;
			while (!op.empty() && op.front().prior >= o.prior && !err)
				err = do_operation(digits, op);
			op.push_front(o);
		}
		else if (c == "(")
		{
			o.operation = '(';
			o.prior = 1;
			op.push_front(o);
		}
		else if (c == ")")
		{
			while (!op.empty() && op.front().operation != '(' && !err)
				err = do_operation(digits, op);
			if (op.empty())
				err = 1;
			else
				op.pop();
		}
		else
			err = 1;
	}

	return err ? 0 : read(digits, op);
}

void calc()
{
	Queue<int> digits;
	Queue<operation> op;
	bool err = 0;

	if (!read(digits, op))
		err = 1;
	else
		while (!op.empty() && !err)
			err = do_operation(digits, op);

	if (digits.size() == 1 && !err)
		cout << digits.front() << endl;
	else
		cout << "error\n";
}

int main()
{
	char c = ' ';
	int n;
	Queue<int> q;

	cout << "e(exit) c(calculate):";
	while (c != 'e')
	{
		cin >> c;
		if (c == 'c')
			calc();
		if (c == 'p')
			q.print();
		if (c == 'a')
		{
			cin >> n;
			q.push(n);
		}
		if (c == 'r')
			q.pop();
		if (c == 'd')
			q.del();
		if (c == 'n')
		{
			cin >> n;
			cout << q.find(n) << endl;
		}
		if (c == 'f')
			cout << q.front() << endl;
	}
	return 0;
}
