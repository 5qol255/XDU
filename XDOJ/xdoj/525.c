#include <stdio.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    int n;
    int a[10010];
    int f[10010];
    int i, j;
    int ans;
    scanf("%d", &n);
    for (i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (i = 1; i <= n; ++i)
    {
        f[i] = a[i];
        for (j = i + 1; j <= n; ++j)
        {
            f[j] = f[j - 1] + a[j];
            ans = max(max(ans, f[j]), f[j - 1]);
        }
    }
    printf("%d\n", ans);
    return 0;
}