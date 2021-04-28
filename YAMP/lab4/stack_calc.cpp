#include "calc.h"

void print_stacks(stack<operation> op, stack<float> digit)
{
	cout << "\noperations: ";

	while (!op.empty())
	{
		cout << op.top().operation << " ";
		op.pop();
	}

	cout << endl;
	cout << "digits: ";

	while (!digit.empty())
	{
		cout << digit.top() << " ";
		digit.pop();
	}

	cout << endl;
}

bool check_stacks(stack<operation> op, stack<float> digit)
{
	return (op.empty() && digit.size() == 1) ? 1 : 0;
}

bool do_operation(stack<operation> &op, stack<float> &digit)
{
	operation o;
	float a, b;

	if (!op.empty())
	{
		o = op.top();
		op.pop();
	}
	else return 1;

	if (digit.size() > 1)
	{
		b = digit.top();
		digit.pop();
		a = digit.top();
		digit.pop();
	}
	else return 1;

	if (o.operation == '+')
		digit.push(a + b);
	if (o.operation == '-')
		digit.push(a - b);
	if (o.operation == '*')
		digit.push(a * b);
	if (o.operation == '/' && b != 0)
		digit.push(a / b);
	if (o.operation == '/' && b == 0)
		return 1;
	
	return 0;
}

bool read(stack<operation> &op, stack<float> &digit)
{
	string c;
	bool err = 0;

	cin >> c;

	if (c == "=")
		return 0;

	if (c[0] >= '1' && c[0] <= '9')
		digit.push(stoi(c));
	else
	{
		operation o;

		if (c == "+")
		{
			o.operation = '+';
			o.prior = 2;
			while (!op.empty() && op.top().prior >= o.prior && !err)
				err = do_operation(op, digit);
			op.push(o);
		}
		else if (c == "-")
		{
			o.operation = '-';
			o.prior = 2;
			while (!op.empty() && op.top().prior >= o.prior && !err)
				err = do_operation(op, digit);
			op.push(o);
		}
		else if (c == "*")
		{
			o.operation = '*';
			o.prior = 3;
			while (!op.empty() && op.top().prior >= o.prior && !err)
				err = do_operation(op, digit);
			op.push(o);
		}
		else if (c == "/")
		{
			o.operation = '/';
			o.prior = 3;
			while (!op.empty() && op.top().prior >= o.prior && !err)
				err = do_operation(op, digit);
			op.push(o);
		}
		else if (c == "(")
		{
			o.operation = '(';
			o.prior = 1;
			op.push(o);
		}
		else if (c == ")")
		{
			while (!op.empty() && op.top().operation != '(' && !err)
				err = do_operation(op, digit);
			if (op.empty())
				err = 1;
			else
				op.pop();
		}
		else
			err = 1;
	}

	return err ? 1 : read(op, digit);
}

int main()
{
	stack<operation> op;
	stack<float> digit;
	bool err = 0;

	if (read(op, digit))
		err = 1;
	else
		while (!op.empty() && !err)
			err = do_operation(op, digit);
	
	if (check_stacks(op, digit) && !err)
		cout << digit.top() << endl;
	else
		cout << "error\n";

	return 0;
}
