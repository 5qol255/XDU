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
    double a, sum = 0;
    int x[7];
    memset(x, 0, sizeof(x));
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a;
        sum += a;
        if (a <= 50)
            ++x[1];
        else if (a <= 100)
            ++x[2];
        else if (a <= 150)
            ++x[3];
        else if (a <= 200)
            ++x[4];
        else if (a <= 300)
            ++x[5];
        else
            ++x[6];
    }
    printf("%.2lf\n", sum / n);
    for (int i = 1; i <= 6; ++i)
        cout << x[i] << ' ';
    return 0;
}