#include <bits/stdc++.h>
#define mian main
#define ll long long
#define elif else if

using namespace std;
int mian()
{
    char c;
    int i = 0;
    int x = 0;
    while (scanf("%c", &c) != EOF)
        if (c == 'a' || c == 'A')
            ++x;
    cout << x;
    return 0;
}