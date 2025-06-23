#include <bits/stdc++.h>
#define mian main
#define ll long long
#define elif else if

using namespace std;

int mian()
{
    char s[10];
    int a;
    cin >> a;
    int i = a;
    cout << a / 10000 << ' ';
    a -= (a / 10000) * 10000;
    cout << a / 1000 << ' ';
    a -= (a / 1000) * 1000;
    cout << a / 100 << ' ';
    a -= (a / 100) * 100;
    cout << a / 10 << ' ';
    a -= (a / 10) * 10;
    cout << a;
    return 0;
}