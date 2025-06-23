#include <bits/stdc++.h>
#define mian main
#define ll long long
#define elif else if

using namespace std;

int mian()
{
    int sum = 0, a;
    while (scanf("%d", &a) != EOF)
        sum += a;
    printf("%.2f", sum / 3.0);
    return 0;
}