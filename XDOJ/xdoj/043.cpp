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
    char max = s[0], min = s[0];
    for (int i = 1; i < strlen(s); ++i)
    {
        if (s[i] > max)
            max = s[i];
        if (s[i] < min)
            min = s[i];
    }
    cout << strlen(s) << ' ' << max << ' ' << min;
    return 0;
}