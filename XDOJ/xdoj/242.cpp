#include <bits/stdc++.h>

using namespace std;

typedef struct
{
    int id, a, b, c;
    char name[12];
} Student;

bool cmp(Student a, Student b)
{
    if (a.a + a.b + a.c > b.a + b.b + b.c)
        return true;
    if (a.a + a.b + a.c == b.a + b.b + b.c)
        return a.id < b.id;
    return false;
}

int main()
{
    int N;
    Student stu[114];
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> stu[i].id >> stu[i].name >> stu[i].a >> stu[i].b >> stu[i].c;
    sort(stu, stu + N, cmp);
    for (int i = 0; i < N; ++i)
        printf("%d %s %.1f\n", stu[i].id, stu[i].name, (stu[i].a + stu[i].b + stu[i].c) / 3.0);
    return 0;
}