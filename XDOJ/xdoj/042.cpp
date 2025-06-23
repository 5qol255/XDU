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
} O;

int mian()
{
    int a, b;
    cin >> a >> b;
    if (!O.o(a % b))
        cout << "yes";
    else
        cout << a / b << ' ' << a % b;
    return 0;
}