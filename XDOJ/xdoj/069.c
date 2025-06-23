#include <stdio.h>

int main()
{
    int n, m;
    int a[114];
    int i, j;
    int s, e;
    int ps, pe;
    char flag;

    scanf("%d%d", &m, &n);
    for (i = 0; i < m; ++i)
    {
        flag = 0;
        for (j = 0; j < n; ++j)
        {
            scanf("%d", &a[j]);
            if (a[j] == 1)
                flag = 1;
        }
        if (flag == 0)
        {
            printf("-1 -1\n");
            continue;
        }
        j = 0;
        ps = -1;
        pe = -2;
        while (j < n)
        {
            while (a[j] != 1 && j < n)
                ++j;
            s = j;
            while (a[j] != 0 && j < n)
                ++j;
            e = j - 1;
            if (e - s > pe - ps)
            {
                ps = s;
                pe = e;
            }
        }
        printf("%d %d\n", ps, pe);
    }

    return 0;
}