#include <iostream>
#include <string.h>
#include <stack>
using namespace std;

int main()
{
	char c;
	stack<char> st;
	char tmp;
	bool b = 1;

	c = 0;
	while (c != '.')
	{
		cin >> c;
		if (c != '\0' && b == 1)
		{
			if (c == '(' || c == '[' || c == '{')
				st.push(c);
			if (c == ')' || c == ']' || c == '}')
			{
				if (st.empty())
					b = 0;
				else
				{
					tmp = st.top();
					switch (c)
					{
					case ')':
						if (tmp != '(')
							b = 0;
						break;
					case ']':
						if (tmp != '[')
							b = 0;
						break;
					case '}':
						if (tmp != '{')
							b = 0;
						break;
					}
					st.pop();
				}
			}
		}
	}

	if (b && st.empty())
		cout << "good" << endl;
	else
		cout << "bad" << endl;
	return 0;
}
