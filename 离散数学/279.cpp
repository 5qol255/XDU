#include <bits/stdc++.h>
#define mian main
#define ll long long
#define elif else if

using namespace std;

int mian()
{
    int n;
    int R[100][100];
    bool symmetric = true, antisymmetric = true;

    cin >> n;
    for (auto i = 0; i < n; i++)
        for (auto j = 0; j < n; j++)
            cin >> R[i][j];
    for (auto i = 0; i < n; i++)
        for (auto j = 0; j < n; j++)
            if (i != j)
                if (R[i][j] == 1 && R[j][i] == 1)
                    antisymmetric = false;
                else if (R[i][j] != R[j][i])
                    symmetric = false;
    if (symmetric && !antisymmetric)
        cout << "The matrix is symmetric.";
    else if (!symmetric && antisymmetric)
        cout << "The matrix is antisymmetric.";
    else if (symmetric && antisymmetric)
        cout << "The matrix is antisymmetric and symmetric.";
    else
        cout << "The matrix is not antisymmetric or symmetric.";
    return 0;
}