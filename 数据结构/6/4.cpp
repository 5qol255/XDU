#include <bits/stdc++.h>
using namespace std;

// 合并两个子数组函数
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1; // 左子数组的大小
    int n2 = r - m;     // 右子数组的大小

    // 创建临时数组
    int L[n1], R[n2];

    // 拷贝数据到临时数组 L[] 和 R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // 合并临时数组回到 arr[l..r]
    i = 0; // 初始索引第一个子数组
    j = 0; // 初始索引第二个子数组
    k = l; // 初始索引合并的子数组
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // 拷贝 L[] 的剩余元素
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // 拷贝 R[] 的剩余元素
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// l 是数组的左边界，r 是右边界
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // 找到中间索引
        int m = l + (r - l) / 2;

        // 分别对左右两半进行排序
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // 合并已排序的两半
        merge(arr, l, m, r);
    }
}

int main()
{
    int a[10000];
    int n = 9999;
    FILE *f1, *f;
    f1 = fopen("MergeSortOutput.txt", "w");
    f = fopen("test.txt", "r");
    for (int i = 0; i < n; i++)
        fscanf(f, "%d", a + i);

    mergeSort(a, 0, n - 1);

    for (int i = 0; i < n; i++)
        fprintf(f1, "%d\n", a[i]);

    return 0;
}