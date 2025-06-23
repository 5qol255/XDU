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
    int a, b, c;
    cin >> a >> b >> c;
    cout << c % 10 << ' ';
    if (b < 200)
        cout << "no";
    else if (b < 400)
        switch (a)
        {
        case 1:
            if (c % 10 == 1 || c % 10 == 6)
                cout << "yes";
            else
                cout << "no";
            break;
        case 2:
            if (c % 10 == 2 || c % 10 == 7)
                cout << "yes";
            else
                cout << "no";
            break;
        case 3:
            if (c % 10 == 3 || c % 10 == 8)
                cout << "yes";
            else
                cout << "no";
            break;
        case 4:
            if (c % 10 == 4 || c % 10 == 9)
                cout << "yes";
            else
                cout << "no";
            break;
        case 5:
            if (c % 10 == 5 || c % 10 == 0)
                cout << "yes";
            else
                cout << "no";
            break;
        case 6:
        case 7:
            cout << "no";
            break;
        }
    else
        switch (a)
        {
        case 1:
        case 3:
        case 5:
            if (c % 10 & 1)
                cout << "yes";
            else
                cout << "no";
            break;

        case 2:
        case 4:
            if (c % 10 & 1)
                cout << "no";
            else
                cout << "yes";
            break;
        }
    return 0;
}
