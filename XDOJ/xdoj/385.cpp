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
    int a = 0, b = 0, c = 0;
    int x = 0;
    int j;
    int flag = 0;
    for (int i = 1; i < 1000; ++i)
    {
        if (i % 7 == 0)
            flag = 1;
        else
        {
            j = i;
            while (j != 0)
            {
                if (j % 10 == 7)
                {
                    flag = 1;
                    break;
                }
                j /= 10;
            }
        }
        if (!flag)
            ++x;
        if (i % 3 == 1)
            a += flag;
        else if (i % 3 == 2)
            b += flag;
        else
            c += flag;
        flag = 0;
        if (x == n)
        {
            cout << a << ' ' << b << ' ' << c;
            return 0;
        }
    }
}