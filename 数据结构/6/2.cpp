#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef int KeyType;

typedef struct
{
    KeyType key;
} ElemType;

typedef struct
{
    ElemType *r;
    int length;
} SqList;

void Create(SqList &L, int n)
{
    L.length = n;
    L.r = new ElemType[n + 1];
    FILE *f;
    f = fopen("test.txt", "r");
    for (int i = 1; i <= n; i++)
        fscanf(f, "%d", &L.r[i].key);
    fclose(f);
}

template <typename T>
void swap(T &a, T &b)
{
    auto tmp = a;
    a = b;
    b = tmp;
}

int Partition(SqList &L, int low, int high)
{
    int index = low + rand() % (high - low + 1);
    auto p = L.r[index];

    ::swap(L.r[index], L.r[high]);

    int storeIndex = low; // 存储最终枢轴的位置
    for (int j = low; j < high; j++)
    {
        // 当前元素小于枢轴，交换到左边
        if (L.r[j].key < p.key)
        {
            ::swap(L.r[storeIndex], L.r[j]);
            storeIndex++;
        }
    }
    ::swap(L.r[storeIndex], L.r[high]); // 将枢轴放到最终位置
    return storeIndex;                  // 返回枢轴的最终位置
}

void QuickSort(SqList &L, int low, int high)
{
    if (low < high)
    {
        int p = Partition(L, low, high);
        QuickSort(L, low, p - 1);
        QuickSort(L, p + 1, high);
    }
}

signed main()
{
    SqList L;
    int n = 9999;
    Create(L, n);
    QuickSort(L, 1, n);

    FILE *f1;
    f1 = fopen("QuickSortOutput.txt", "w");
    for (int i = 1; i <= n; i++)
        fprintf(f1, "%d\n", L.r[i]);
    fclose(f1);
    return 0;
}
