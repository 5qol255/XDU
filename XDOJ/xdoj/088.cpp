#include <bits/stdc++.h>

using namespace std;

int main()
{
    char a, b, c, d, e, f, g, h, i, j;
    int x = 1, sum = 0;
    scanf("%c-%c%c%c-%c%c%c%c%c-%c", &a, &b, &c, &d, &e, &f, &g, &h, &i, &j);
    a -= '0';
    b -= '0';
    c -= '0';
    d -= '0';
    e -= '0';
    f -= '0';
    g -= '0';
    h -= '0';
    i -= '0';
    j = (j == 'X' ? 10 : j - '0');
    sum += a * (x++);
    sum += b * (x++);
    sum += c * (x++);
    sum += d * (x++);
    sum += e * (x++);
    sum += f * (x++);
    sum += g * (x++);
    sum += h * (x++);
    sum += i * (x++);
    if (sum % 11 == j)
        cout << "Right\n";
    else
    {
        int tmp = sum % 11;
        if (tmp == 10)
            printf("%d-%d%d%d-%d%d%d%d%d-X", a, b, c, d, e, f, g, h, i);
        else
            printf("%d-%d%d%d-%d%d%d%d%d-%d", a, b, c, d, e, f, g, h, i, tmp);
    }
    return 0;
}