#include <bits/stdc++.h>

using namespace std;

int cnt(char *s)
{
    int a = 0, b = 0;
    for (int i = 0; s[i] != '\0'; ++i)
        if (s[i] >= '0' && s[i] <= '9')
            ++b;
        else if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
            ++a;
    return a * 100000000 + b;
}

int main()
{
    char s[1145];
    int a, b, x;
    cin >> s; // gets(s);
    x = cnt(s);
    a = x / 100000000;
    b = x % 100000000;
    cout << a << ',' << b;
    return 0;
}