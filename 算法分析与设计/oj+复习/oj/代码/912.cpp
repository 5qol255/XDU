#include <iostream>
#include <vector>

using namespace std;

int min_time(int n, const vector<int>& a1, const vector<int>& a2, const vector<int>& t1, const vector<int>& t2, int e1, int e2, int x1, int x2)
{
    vector<int> f1(n, 0), f2(n, 0);
    f1[0] = e1 + a1[0];
    f2[0] = e2 + a2[0];
    for (int i = 1;i < n;i++)
    {
        f1[i] = min(f1[i - 1] + a1[i], f2[i - 1] + t2[i - 1] + a1[i]);
        f2[i] = min(f2[i - 1] + a2[i], f1[i - 1] + t1[i - 1] + a2[i]);
    }
    return min(f1[n - 1] + x1, f2[n - 1] + x2);
}

int main()
{
    int n;
    vector<int> a1, a2, t1, t2;
    int x1, x2, e1, e2;
    cin >> n;
    a1.resize(n);
    a2.resize(n);
    t1.resize(n - 1);
    t2.resize(n - 1);
    for (int i = 0; i < n; i++)
        cin >> a1[i];
    for (int i = 0; i < n; i++)
        cin >> a2[i];
    for (int i = 0; i < n - 1; i++)
        cin >> t1[i];
    for (int i = 0; i < n - 1; i++)
        cin >> t2[i];
    cin >> e1 >> e2 >> x1 >> x2;

    cout << min_time(n, a1, a2, t1, t2, e1, e2, x1, x2);
    return 0;
}