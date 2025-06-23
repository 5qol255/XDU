#include <bits/stdc++.h>
using namespace std;

int main()
{
	char s[114];
	gets(s);
	int len = strlen(s);
	if (len <= 1)
	{
		cout << s << endl;
		return 0;
	}
	for (int i = 0; i < len; ++i)
	{
		if ((s[i] >= 'a' && s[i] <= 'z') || s[i] >= 'A' && s[i] <= 'Z')
		{
			if (s[i + 1] > '9' || s[i + 1] < '0')
				cout << s[i];
		}
		else
		{
			int x, cx;
			sscanf(s + i, "%d", &x);
			if (i - 1 >= 0 && ((s[i - 1] >= 'a' && s[i - 1] <= 'z') || s[i - 1] >= 'A' && s[i - 1] <= 'Z'))
			{
				if (x >= 3)
					for (int cx = x; cx; --cx)
						cout << s[i - 1];
				else
					cout << s[i - 1] << s[i];
			}
			else
				cout << s[i];
			if (x % 100 >= 10)
				++i;
		}
	}
	cout << '\n';
	return 0;
}