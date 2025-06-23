#include <bits/stdc++.h>

using namespace std;

typedef struct
{
    int a[5], extra, sum;
    char name[24];
} Stu;

bool cmp(Stu a, Stu b)
{
    if (a.sum > b.sum)
        return true;
    if (a.sum == b.sum)
        return a.extra > b.extra;
    return false;
}

int main()
{
    int N;
    Stu stu[114];
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> stu[i].name >> stu[i].a[0] >> stu[i].a[1] >> stu[i].a[2] >> stu[i].a[3] >> stu[i].a[4] >> stu[i].extra;
        stu[i].sum = stu[i].a[0] + stu[i].a[1] + stu[i].a[2] + stu[i].a[3] + stu[i].a[4] + stu[i].extra;
    }
    sort(stu, stu + N, cmp);
    for (int i = 0; i < N; ++i)
        cout << stu[i].name << ' ' << stu[i].sum << ' ' << stu[i].extra << endl;
    return 0;
}