#include <bits/stdc++.h>

using namespace std;

int cnt(char *s)
{
    int a = 0;
    for (int i = 0; s[i] != '\0'; ++i)
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
            ++a;
    return a;
}

int main()
{
    int n;
    char s[11451];
    cin >> s;
    cout << cnt(s);
    return 0;
}