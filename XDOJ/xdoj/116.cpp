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
    float x;
    cin >> x;
    if (x <= 110)
        printf("%.2f", x * 0.5);
    else if (x <= 210)
        printf("%.2f", 110 * 0.5 + (x - 110) * 0.55);
    else
        printf("%,2f", 110 * 0.5 + 100 + 0.55 + (x - 210) * 0.70);
    return 0;
}