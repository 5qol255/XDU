#pragma GCC optimize(2)
#include <stdio.h>

int main()
{
    int n;
    int c1 = 0, c2 = 0, c3 = 0;
    scanf("%d", &n);
    int m = n * n;
    int i;
    for (i = n; i <= m; ++i)
    {
        if (i & 1)
            ++c1;
        else
            ++c2;
        if (i % 4 == 0 && i % 3 != 0)
            ++c3;
    }
    printf("%d %d %d\n", c1, c2, c3);
    if (c1 + c2 >= c2 + c3 && c1 + c2 >= c3 + c1)
        printf("%d", c1 + c2);
    else if (c2 + c3 >= c1 + c2 && c2 + c3 >= c3 + c1)
        printf("%d", c2 + c3);
    else
        printf("%d", c3 + c1);
    return 0;
}