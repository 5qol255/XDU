#include <bits/stdc++.h>
using namespace std;

int main()
{
	char s1[114], s2[114], s3[114];
	int x, y;
	char op;
	int l1, l2, l3;
	cin >> s1 >> s2 >> s3;
	l1 = strlen(s1);
	l2 = strlen(s2);
	l3 = strlen(s3);
	if (l1 == 1 && (s1[0] < '0' || s1[0] > '9'))
	{
		sscanf(s1, "%c", &op);
		sscanf(s2, "%d", &x);
		sscanf(s3, "%d", &y);
	}
	else if (l2 == 1 && (s2[0] < '0' || s2[0] > '9'))
	{
		sscanf(s2, "%c", &op);
		sscanf(s1, "%d", &x);
		sscanf(s3, "%d", &y);
	}
	else
	{
		sscanf(s3, "%c", &op);
		sscanf(s1, "%d", &x);
		sscanf(s2, "%d", &y);
	}
	switch (op)
	{
		case '+':
			cout << x + y << endl;
			break;
		case '-':
			cout << x - y << endl;
			break;
		case '*':
			cout << x *y << endl;
			break;
		case '/':
			cout << x / y << endl;
			break;
		case '%':
			cout << x % y << endl;
			break;
	}
	return 0;
}