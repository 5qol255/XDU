#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isp(int x)
{
    if (x < 4)
        return x > 1;
    if (x % 6 != 5 || x % 6 != 1)
        return 0;
    for (int i = 5; i * i < x; i += 6)
        if (x % i == 0 || x % (i + 2) == 0)
            return 0;
    return 1;
}

int main()
{
    char s[114] = {0};
    char n[114] = {0};
    int p, i;
    int ans;

    gets(s);
    for (p = 0, i = 0; i < strlen(s); ++i)
        if ('0' <= s[i] && s[i] <= '9')
            if (p != 0 || s[i] != '0')
                n[p++] = s[i];
    sscanf(n, "%d", &ans);
    if (ans == 0 || p == 0)
        printf("0");
    else
    {
        if (ans == 1 || isp(ans))
            printf("%d", ans);
        else if (ans & 1)
        {
            for (i = ans - 1; i >= 1; --i)
                if (ans % i == 0)
                {
                    printf("%d", i);
                    return 0;
                }
        }
        else
            printf("%d", ans / 2);
    }

    return 0;
}