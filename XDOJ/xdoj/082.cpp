#include <bits/stdc++.h>
using namespace std;

int main()
{
	char s[114];
	bool mark[4] = {false};
	int score;
	int len;
	gets(s);
	len = strlen(s);
	if (len == 0)
		score = 0;
	else
	{
		if (len <= 8)
			score = 1;
		else
			score = 2;
		for (int i = 0; i < len; ++i)
		{
			if (s[i] >= 'A' && s[i] <= 'Z')
				mark[0] = true;
			else if (s[i] >= 'a' && s[i] <= 'z')
				mark[1] = true;
			else if (s[i] >= '0' && s[i] <= '9')
				mark[2] = true;
			else
				mark[3] = true;
		}
	}
	if (mark[0] && mark[1] && mark[2] && mark[3])
		++++++score;
	else if ((mark[0] && mark[1] && mark[2] && !mark[3]) ||
	         (mark[0] && mark[1] && !mark[2] && mark[3]) ||
	         (mark[0] && !mark[1] && mark[2] && mark[3]) ||
	         (!mark[0] && mark[1] && mark[2] && mark[3]))
		++++score;
	else if ((!mark[0] && !mark[1] && mark[2] && mark[3]) ||
	         (!mark[0] && mark[1] && !mark[2] && mark[3]) ||
	         (!mark[0] && mark[1] && mark[2] && !mark[3]) ||
	         (mark[0] && !mark[1] && !mark[2] && mark[3]) ||
	         (mark[0] && !mark[1] && mark[2] && !mark[3]) ||
	         (mark[0] && mark[1] && !mark[2] && !mark[3]))
		++score;
	cout << score;
	return 0;
}