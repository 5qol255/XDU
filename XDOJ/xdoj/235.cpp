#include <bits/stdc++.h>

using namespace std;

int main()
{
    const char *s[] = {
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December",
    };
    int x;
    cin >> x;
    if (x >= 1 && x <= 12)
        cout << s[x - 1] << endl;
    else
        cout << "wrong" << endl;
    return 0;
}