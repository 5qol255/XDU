#include <bits/stdc++.h>

using namespace std;

char *f(char *s);

int main()
{
    char s[11451];
    cin >> s;
    cout << f(s);
    return 0;
}

char *f(char *s)
{
    int len = strlen(s);
    char *p = (char *)calloc(len / 2 + 2, sizeof(char));
    for (int i = 0; i < strlen(s); ++ ++i)
        p[i / 2] = s[i];
    return p;
}