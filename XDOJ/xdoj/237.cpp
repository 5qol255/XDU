#include <bits/stdc++.h>

using namespace std;

int main()
{
    char s[114];
    int m;
    gets(s);
    cin >> m;
    if (m > strlen(s))
        cout << "error" << endl;
    else
        cout << s + m - 1 << endl;
    return 0;
}