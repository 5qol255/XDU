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
    int n;
    char c;
    cin >> c;
    if (c >= 'A' && c <= 'Z')
        printf("%c", c + 32);
    else if (c >= 'a' && c <= 'z')
        printf("%c", c - 32);
    else
        cout << c;
    return 0;
}