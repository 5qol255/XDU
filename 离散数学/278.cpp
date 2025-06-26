#include <bits/stdc++.h>
#define mian main
#define ll long long
#define elif else if

using namespace std;

int mian()
{
    int n;
    int R[100][100];
    bool reflexive = true, irreflexive = true;
    cin >> n;
    for (auto i = 0; i < n; i++)
        for (auto j = 0; j < n; j++)
            cin >> R[i][j];
    for (auto i = 0; i < n; i++)
        if (R[i][i] == 1)
            irreflexive = false;
        else
            reflexive = false;
    if (reflexive)
        cout << "The matrix is reflexive.";
    else if (irreflexive)
        cout << " The matrix is irreflexive.";
    else
        cout << "The matrix is not irreflexive or reflexive.";
    return 0;
}