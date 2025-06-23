#include <bits/stdc++.h>

using namespace std;

char s[11451];

void f(int p)
{
    if (s[p] == '\0')
        return;
    f(p + 1);
    cout << s[p];
}

int main()
{
    cin >> s; // gets(s);
    f(0);
    return 0;
}