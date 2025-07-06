#include <bits/stdc++.h>
using namespace std;

void heapify(int *arr, int len, int i)
{
    int largest = i;       // 初始化最大值为根
    int left = 2 * i + 1;  // 左子节点
    int right = 2 * i + 2; // 右子节点

    // 如果左子节点大于根节点
    if (left < len && arr[left] > arr[largest])
        largest = left;

    // 如果右子节点大于当前最大值
    if (right < len && arr[right] > arr[largest])
        largest = right;

    // 如果最大值不是根
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        // 递归地调整被交换的子树
        heapify(arr, len, largest);
    }
}

// 主堆排序函数
void heapSort(int *arr, int len)
{
    // 构建最大堆
    for (int i = len / 2 - 1; i >= 0; i--)
        heapify(arr, len, i);

    // 一个个从堆顶取出元素
    for (int i = len - 1; i >= 0; i--)
    {
        // 将当前根移到数组末尾
        swap(arr[0], arr[i]);

        // 调整剩余元素以保持堆的性质
        heapify(arr, i, 0);
    }
}

int main()
{
    int a[10000];
    int n = 9999;
    FILE *f1, *f;
    f1 = fopen("HeapSortOutput.txt", "w");
    f = fopen("test.txt", "r");
    for (int i = 0; i < n; i++)
        fscanf(f, "%d", a + i);

    heapSort(a, n);

    for (int i = 0; i < n; i++)
        fprintf(f1, "%d\n", a[i]);

    return 0;
}