#include <bits/stdc++.h>

using namespace std;

int main()
{
    char s[114];
    int m;
    gets(s);
    cin >> m;
    if (m > strlen(s))
    {
        cout << "error\n";
        return 0;
    }
    cout << s + m - 1;
    return 0;
}