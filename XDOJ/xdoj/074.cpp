#include <bits/stdc++.h>
using namespace std;

int main()
{
	stack<char> s;
	char c;
	while ((c = getchar()) != EOF)
	{
		if (c == '(' || c == '[' || c == '{')
			s.push(c);
		else if (c == ')' && s.top() == '(' || c == ']' && s.top() == '[' || c == '}' && s.top() == '{')
			s.pop();
	}
	if (s.empty())
		cout << "yes\n";
	else
		cout << "no\n";
	return 0;
}