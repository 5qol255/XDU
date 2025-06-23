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
    int score = 0;
    int t;
    int ex = 1;
    cin >> t;
    while (t != 0)
    {
        if (t == 1)
        {
            ++score;
            ex = 1;
        }
        else
        {
            score += ex * 2;
            ++ex;
        }
        cin >> t;
    }
    cout << score;
    return 0;
}