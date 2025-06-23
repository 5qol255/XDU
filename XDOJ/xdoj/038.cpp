#include <bits/stdc++.h>

using namespace std;

int main()
{
    char n[114];
    int len, sum;
    ;
    cin >> n;
    len = strlen(n);
    sum = 0;

    for (int i = 0; i < len / 2; ++i)
        if (n[i] != n[len - 1 - i])
        {
            cout << "no";
            return 0;
        }
        else
            sum += n[i] + n[i] - '0' - '0';
    if (len & 1)
        sum += n[len / 2] - '0';
    cout << sum;
    return 0;
}