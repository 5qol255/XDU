#include <bits/stdc++.h>
using namespace std;

void summon(int n);
void BubbleSort(int *start, int len);
void ChooseSort(int *start, int len);
void InsertSort(int *start, int len);

int main()
{
    // summon(9999);
    int a[10000], b[10000], c[10000], n = 9999;
    FILE *f1, *f2, *f3, *f;
    f1 = fopen("BubbleSortOutput.txt", "w");
    f2 = fopen("ChooseSortOutput.txt", "w");
    f3 = fopen("InsertSortOutput.txt", "w");
    f = fopen("test.txt", "r");

    for (int i = 0; i < n; i++)
    {
        int tmp;
        fscanf(f, "%d", &tmp);
        c[i] = b[i] = a[i] = tmp;
    }

    BubbleSort(a, n);
    for (int i = 0; i < n; i++)
        fprintf(f1, "%d\n", a[i]);
    ChooseSort(b, n);
    for (int i = 0; i < n; i++)
        fprintf(f2, "%d\n", b[i]);
    InsertSort(c, n);
    for (int i = 0; i < n; i++)
        fprintf(f3, "%d\n", c[i]);

    fclose(f);
    fclose(f1);
    fclose(f2);
    fclose(f3);
    return 0;
}

void summon(int n)
{
    FILE *f;
    f = fopen("test.txt", "w");
    srand(time(0));
    for (int i = 0; i < n; i++)
        fprintf(f, "%d\n", rand());
    fclose(f);
    exit(0);
}

void BubbleSort(int *start, int len)
{
    bool flag = true;
    for (int j = 0; j < len && flag; j++)
    {
        flag = false;
        for (int i = 0; i < len - 1; i++)
            if (start[i] > start[i + 1])
            {
                flag = true;
                swap(start[i], start[i + 1]);
            }
    }
}

void ChooseSort(int *start, int len)
{
    int most, pos;
    for (int i = 0; i < len - 1; i++)
    {
        most = 2147483647;
        pos = i;
        for (int j = i + 1; j < len; j++)
        {
            if (start[j] < most)
            {
                most = start[j];
                pos = j;
            }
        }
        if (i != pos)
            swap(start[i], start[pos]);
    }
}

void InsertSort(int *start, int len)
{
    int tmp, i, j;
    for (i = 1; i < len; i++)
    {
        tmp = start[i];
        for (j = i - 1; j >= 0 && tmp < start[j]; j--)
            start[j + 1] = start[j];
        start[j + 1] = tmp;
    }
}