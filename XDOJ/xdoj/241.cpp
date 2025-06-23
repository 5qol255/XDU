#include <bits/stdc++.h>

using namespace std;

int f(int x)
{
    if (x == 0)
        return 1;
    return 16 * f(x - 1);
}

int main()
{
    char s[114];
    int len, x, b, a, hex = 0;
    cin >> s;
    len = strlen(s);
    b = len;
    for (int i = 0; i < len; ++i)
    {
        --b;
        switch (s[i])
        {
        case 'f':
        case 'F':
            a = 15;
            break;
        case 'e':
        case 'E':
            a = 14;
            break;
        case 'd':
        case 'D':
            a = 13;
            break;
        case 'c':
        case 'C':
            a = 12;
            break;
        case 'b':
        case 'B':
            a = 11;
            break;
        case 'a':
        case 'A':
            a = 10;
            break;
        default:
            a = s[i] - '0';
            break;
        }
        hex += a * f(b);
    }
    cout << hex;
    return 0;
}
// 另一种
/*
int main()
{
    char s[114];
    char hex[114] = "0x";
    long long n;
    cin >> s;
    strcat(hex, s);
    sscanf(hex, "%x", &n);
    printf("%lld", n);
    return 0;
}
 */