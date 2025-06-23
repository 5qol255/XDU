#include <bits/stdc++.h>
#define mian main
#define ll long long
#define elif else if

using namespace std;

int mian()
{
    char a[5];
    int i = 0, j = 0;
    scanf("%c|%c|%c|%c|%c", a + i++, a + i++, a + i++, a + i++, a + i++);
    printf("%c%c%c%c%c!", (*(a + j++)) + 32, (*(a + j++)) + 32, (*(a + j++)) + 32, (*(a + j++)) + 32, (*(a + j++)) + 32);
    return 0;
}