#include <bits/stdc++.h>
#define mian main
#define ll long long
#define elif else if

using namespace std;

int mian()
{
    int a, b;
    char op;
    cin >> a >> op >> b;
    switch (op)
    {
    case '+':
        cout << a << op << b << '=' << a + b;
        break;
    case '-':
        cout << a << op << b << '=' << a - b;
        break;
    case '*':
        cout << a << op << b << '=' << a * b;
        break;
    case '/':
        cout << a << op << b << '=' << a / b;
        break;
    case '%':
        cout << a << op << b << '=' << a % b;
        break;
    default:
        break;
    }
    return 0;
}