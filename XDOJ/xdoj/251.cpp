#include <bits/stdc++.h>

using namespace std;

struct
{
    int y, m, d, th;
    void ask()
    {
        switch (m)
        {
        case 1:
            th = 0;
            break;
        case 2:
            th = 31;
            break;
        case 3:
            th = 59;
            break;
        case 4:
            th = 90;
            break;
        case 5:
            th = 120;
            break;
        case 6:
            th = 151;
            break;
        case 7:
            th = 181;
            break;
        case 8:
            th = 212;
            break;
        case 9:
            th = 243;
            break;
        case 10:
            th = 273;
            break;
        case 11:
            th = 304;
            break;
        case 12:
            th = 334;
            break;
        }
        if ((y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) && m >= 3)
            ++th;
        th += d;
    }
} Date;

int main()
{
    char c;
    cin >> Date.y >> c >> Date.m >> c >> Date.d;
    Date.ask();
    cout << Date.th << endl;
    return 0;
}