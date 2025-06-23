#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s, temp;
    cin >> s;
    temp.clear();
    int len = s.length();
    for (int i = 0; i <= len; ++i)
    {
        if (i == len)
            goto last;
        if (s[i] >= '0' && s[i] <= '9')
            temp.push_back(s[i]);
        else
        {
        last:
            if (temp.empty())
            {
                temp.clear();
                continue;
            }
            else if (temp.size() == 1)
            {
                cout << temp << endl;
                temp.clear();
                continue;
            }
            int lent = temp.length();
            int a;
            bool flag = true;
            if (temp[1] - temp[0] == 1)
                a = 1;
            else if (temp[1] - temp[0] == -1)
                a = -1;
            else
            {
                temp.clear();
                continue;
            }
            for (int j = 1; j < lent; ++j)
                if (temp[j] - temp[j - 1] != a)
                {
                    flag = false;
                    break;
                }
            if (flag)
                cout << temp << endl;
            temp.clear();
        }
    }
    return 0;
}