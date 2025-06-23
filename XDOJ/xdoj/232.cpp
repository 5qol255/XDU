#include <bits/stdc++.h>

using namespace std;

int main()
{
    char s[114];
    gets(s);
    int len = strlen(s);
    for (int i = 0; i < len; ++i)
        if (s[i] != s[len - 1 - i])
        {
            cout << "no\n";
            return 0;
        }
    cout << "yes\n";
    return 0;
}