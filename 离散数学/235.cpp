#include <bits/stdc++.h>
using namespace std;

// struct node1
// {
//     int a, b;
//     void print()
//     {
//         cout << '<' << a << ',' << b << '>';
//     }
// };
// struct node2
// {
//     vector<node1> a;
//     void print()
//     {
//         cout << '{';
//         for (auto i : a)
//         {
//             i.print();
//             cout << ',';
//         }
//         cout << "\b}\n";
//     }
// };

// bool cmp(node1 a, node1 b);

// int main()
// {
//     int m, n;
//     vector<int> a, b;
//     vector<bool> marka(10000, false), markb(10000, false);
//     vector<node2> R;
//     cin >> m >> n;
//     for (auto i = 0; i < m; ++i)
//         cin >> a[i];
//     for (auto i = 0; i < n; ++i)
//         cin >> b[i];
//     return 0;
// }

// void f(int x, int y)
// {
//     if (x == 1)
//         ;
//     else
//     {
//         f(x - 1, y);
//     }
// }

// bool cmp(node1 a, node1 b)
// {
//     if (a.a < b.a)
//         return true;
//     if (a.a < b.a)
//         return false;
//     return a.b < b.b;
// }

void printMapping(const vector<int> &mapping, const vector<int> &A, const vector<int> &B)
{
    cout << "{";
    for (size_t i = 0; i < mapping.size(); ++i)
    {
        cout << '<' << A[i] << ',' << B[mapping[i]] << '>';
        if (i < mapping.size() - 1)
        {
            cout << ',';
        }
    }
    cout << "}\n";
}

bool isValidMapping(const vector<int> &currentMapping, int sizeB)
{
    for (int i = 0; i < sizeB; ++i)
    {
        int count = 0;
        for (int j = 0; j < currentMapping.size(); ++j)
        {
            if (currentMapping[j] == i)
            {
                ++count;
                if (count > 1)
                {
                    return false;
                }
            }
        }
    }
    return true;
}

void backtrack(const vector<int> &A, const vector<int> &B, vector<int> &currentMapping, int index)
{
    if (index == A.size())
    {
        if (isValidMapping(currentMapping, B.size()))
        {
            printMapping(currentMapping, A, B);
        }
        return;
    }
    for (int i = 0; i < B.size(); ++i)
    {
        currentMapping[index] = i;
        backtrack(A, B, currentMapping, index + 1);
    }
}

int main()
{
    int m, n;
    cin >> m >> n;
    vector<int> A(m), B(n);
    for (int i = 0; i < m; ++i)
    {
        cin >> A[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> B[i];
    }
    vector<int> currentMapping(m, -1);
    backtrack(A, B, currentMapping, 0);
    return 0;
}