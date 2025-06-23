#include <bits/stdc++.h>

using namespace std;

bool seat[100];

int main()
{
    int n, p;
    cin >> n;
    for (auto i = 0; i < n; ++i)
    {
        cin >> p;
        bool flag = false;
        switch (p)
        {
        case 1:
            for (auto j = 0; j < 100; ++j)
                if (seat[j] == false)
                {
                    seat[j] = true;
                    cout << j + 1 << '\n';
                    break;
                }
            break;
        case 2:
            for (auto j = 0; j < 100; j += 5)
                if (seat[j] == false && seat[j + 1] == false)
                {
                    flag = seat[j] = seat[j + 1] = true;
                    cout << j + 1 << ' ' << j + 2 << '\n';
                    break;
                }
                else if (seat[j + 1] == false && seat[j + 2] == false)
                {
                    flag = seat[j + 1] = seat[j + 2] = true;
                    cout << j + 2 << ' ' << j + 3 << '\n';
                    break;
                }
                else if (seat[j + 2] == false && seat[j + 3] == false)
                {
                    flag = seat[j + 2] = seat[j + 3] = true;
                    cout << j + 3 << ' ' << j + 4 << '\n';
                    break;
                }
                else if (seat[j + 3] == false && seat[j + 4] == false)
                {
                    flag = seat[j + 3] = seat[j + 4] = true;
                    cout << j + 4 << ' ' << j + 5 << '\n';
                    break;
                }
            if (flag == false)
                goto expect;
            break;
        case 3:
            for (auto j = 0; j < 100; j += 5)
                if (seat[j] == false && seat[j + 1] == false && seat[j + 2] == false)
                {
                    flag = seat[j] = seat[j + 1] = seat[j + 2] = true;
                    cout << j + 1 << ' ' << j + 2 << ' ' << j + 3 << '\n';
                    break;
                }
                else if (seat[j + 1] == false && seat[j + 2] == false && seat[j + 3] == false)
                {
                    flag = seat[j + 1] = seat[j + 2] = seat[j + 3] = true;
                    cout << j + 2 << ' ' << j + 3 << ' ' << j + 4 << '\n';
                    break;
                }
                else if (seat[j + 2] == false && seat[j + 3] == false && seat[j + 4] == false)
                {
                    flag = seat[j + 2] = seat[j + 3] = seat[j + 4] = true;
                    cout << j + 3 << ' ' << j + 4 << ' ' << j + 5 << '\n';
                    break;
                }
            if (flag == false)
                goto expect;
            break;
        case 4:
            for (auto j = 0; j < 100; j += 5)
                if (seat[j] == false && seat[j + 1] == false && seat[j + 2] == false && seat[j + 3] == false)
                {
                    flag = seat[j] = seat[j + 1] = seat[j + 2] = seat[j + 3] = true;
                    cout << j + 1 << ' ' << j + 2 << ' ' << j + 3 << ' ' << j + 4 << '\n';
                    break;
                }
                else if (seat[j + 1] == false && seat[j + 2] == false && seat[j + 3] == false && seat[j + 4] == false)
                {
                    flag = seat[j + 1] = seat[j + 2] = seat[j + 3] = seat[j + 4] = true;
                    cout << j + 2 << ' ' << j + 3 << ' ' << j + 4 << ' ' << j + 5 << '\n';
                    break;
                }
            if (flag == false)
                goto expect;
            break;
        case 5:
            for (auto j = 0; j < 100; j += 5)
                if (seat[j] == false && seat[j + 1] == false && seat[j + 2] == false && seat[j + 3] == false && seat[j + 4] == false)
                {
                    flag = seat[j] = seat[j + 1] = seat[j + 2] = seat[j + 3] = seat[j + 4] = true;
                    cout << j + 1 << ' ' << j + 2 << ' ' << j + 3 << ' ' << j + 4 << ' ' << j + 5 << '\n';
                    break;
                }
            if (flag == false)
                goto expect;
            else
                break;
        expect:
            for (auto j = 0, cnt = p; j < 100; ++j)
                if (seat[j] == false)
                {
                    seat[j] = true;
                    cout << j + 1 << ' ';
                    --cnt;
                    if (cnt == 0)
                        break;
                }
            cout << '\n';
        }
    }
    return 0;
}