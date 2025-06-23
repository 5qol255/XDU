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
    cin >> n;
    int A, T;
    A = n - 3500;
    T = n;
    if (A <= 0)
        ;
    else if (A <= 1500)
        T -= (int)(A * 0.03);
    else if (A > 1500 && A <= 4500)
    {
        T -= (int)(1500 * 0.03);
        A -= 1500;
        T -= (int)(A * 0.10);
    }
    else if (A <= 9000)
    {
        T -= (int)(1500 * 0.03);
        A -= 1500;
        T -= (int)(3000 * 0.10);
        A -= 3000;
        T -= (int)(A * 0.20);
    }
    else if (A <= 35000)
    {
        T -= (int)(1500 * 0.03);
        A -= 1500;
        T -= (int)(3000 * 0.10);
        A -= 3000;
        T -= (int)(4500 * 0.20);
        A -= 4500;
        T -= (int)(A * 0.25);
    }
    else
    {
        T -= (int)(1500 * 0.03);
        A -= 1500;
        T -= (int)(3000 * 0.10);
        A -= 3000;
        T -= (int)(4500 * 0.20);
        A -= 4500;
        T -= (int)(26000 * 0.25);
        A -= 26000;
        T -= (int)(A * 0.30);
    }
    cout << T;
    return 0;
}