#include <bits/stdc++.h>
using namespace std;

int main()
{
	char t[114], s[114];
	bool caps;
	int n;
	int len;
	cin >> s >> caps >> n;
	len = strlen(s);
	if (caps)
		for (int i = 0; i < n; ++i)
		{
			cin >> t;
			int lent = strlen(t);
			int j, k;
			bool flag;
			if (strlen(t) >= len)
				for (j = 0; j <= lent - len; ++j)
				{
					flag = true;
					for (k = 0; k < len; ++k)
						if (s[k] != t[j + k])
						{
							flag = false;
							break;
						}
					if (flag)
					{
						cout << t << endl;
						break;
					}
				}
		}
	else
	{
		for (int i = 0; i < len; ++i)
			if (s[i] >= 'A' && s[i] <= 'Z')
				s[i] += 32;
		for (int i = 0; i < n; ++i)
		{
			cin >> t;
			int lent = strlen(t);
			int j, k;
			bool flag;
			if (strlen(t) >= len)
				for (j = 0; j <= lent - len; ++j)
				{
					flag = true;
					for (k = 0; k < len; ++k)
						if (s[k] != t[j + k] && s[k] != t[k + j] + 32)
						{
							flag = false;
							break;
						}
					if (flag)
					{
						cout << t << endl;
						break;
					}
				}
		}
	}
	return 0;
}