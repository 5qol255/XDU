#include<iostream>

using namespace std;

void heapify(int heap[], int size, int root)
{
    while (true)
    {
        auto left = root << 1;
        auto right = left + 1;
        auto largest_p = root;
        if (left <= size && heap[left] > heap[largest_p])
            largest_p = left;
        if (right <= size && heap[right] > heap[largest_p])
            largest_p = right;
        if (largest_p != root)
        {
            swap(heap[root], heap[largest_p]);
            root = largest_p; // 调整新的子堆，因为交换之后可能不满足堆的性质了
        }
        else
            return;
    }
}

void build_heap(int heap[], int size)
{
    for (int i = size >> 1;i > 0;i--)
        heapify(heap, size, i);
}

int main()
{
    int n;
    cin >> n;
    int a[2026];
    for (int i = 1;i <= n;i++)
        cin >> a[i];
    build_heap(a, n);
    for (int i = 1;i <= n;i++)
        cout << a[i] << ' ';
    return 0;
}