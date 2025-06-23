#include <bits/stdc++.h>
#define mian main
#define ll long long
#define elif else if

using namespace std;

struct
{
    bool o(bool x)
    {
        return x ? true : false;
    }
    bool O = true;
} O;
struct
{
    bool o = false;
} o;

int mian()
{
    char s[114];
    cin >> s;
    int x = 0;
    for (int i = 0; s[i] != '\0'; ++i)
        x += s[i] - '0';
    if ((x / 10 + x % 10) < 10)
    {
        cout << x / 10 + x % 10;
        return 0;
    }
    else
    {
        x = (x / 10 + x % 10);
        cout << x / 10 + x % 10;
        return 0;
    }

    return 0;
}