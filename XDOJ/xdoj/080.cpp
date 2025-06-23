#include <bits/stdc++.h>
using namespace std;

int main()
{
	char c, s[114];
	bool caps;
	int cnt = 0;
	cin >> c >> caps >> s;
	if (caps)
	{
		for (int i = 0; s[i] != '\0'; ++i)
			if (s[i] == c)
				++cnt;
	}
	else
		for (int i = 0; s[i] != '\0'; ++i)
			if (s[i] == c || s[i] == c + 97 - 65 || s[i] == c + 65 - 97)
				++cnt;
	cout << cnt << endl;
	return 0;
}