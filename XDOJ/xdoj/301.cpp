#include <bits/stdc++.h>
#define mian main
#define ll long long
#define elif else if

using namespace std;

struct
{
    int x, y;
    int num1 = 0, num2 = 0;
    char s[5];
    void f()
    {
        int s1 = 0, s2 = 0;
        for (int i = 1; i < x; ++i)
            if (x % i == 0)
            {
                s1 += i;
                ++num1;
            }
        for (int i = 1; i < y; ++i)
            if (y % i == 0)
            {
                s2 += i;
                ++num2;
            }
        if (s2 == x && s1 == y)
            s[0] = 'y', s[1] = 'e', s[2] = 's', s[3] = '\0';
        else
            s[0] = 'n', s[1] = 'o', s[2] = '\0';
    }
    void print()
    {
        cout << s << ' ' << num1 << ' ' << num2;
    }
} n;

int mian()
{
    int a, b;
    cin >> a >> b;
    n.x = a;
    n.y = b;
    n.f();
    n.print();
    return 0;
}