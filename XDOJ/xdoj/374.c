#include <stdio.h>

int main()
{
    int m, s;
    scanf("%d%d", &m, &s);
    float t;
    t = (m * 60.0 + s) / 60.0;
    if (t <= 10)
        printf("%.1f", 100.0 - 5.0 * t);
    else if (t <= 30)
        printf("%.1f", 50.0 - (t - 10.0));
    else if (t <= 50)
        printf("%.1f", 30.0 - (t - 30.0) / 2.0);
    else if (t > 50)
        printf("20.0");
    return 0;
}