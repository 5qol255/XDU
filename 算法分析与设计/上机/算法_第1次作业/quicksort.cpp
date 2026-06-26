#include<iostream>
#include<cstdlib>

using namespace std;

int partition(int arr[], int begin, int end)
{
    auto pivot = arr[rand() % (end - begin + 1) + begin];
    int i = begin - 1, j = end + 1;
    while (true)
    {
        do i++;
        while (arr[i] < pivot);
        do j--;
        while (arr[j] > pivot);
        if (i >= j)
            return j;
        swap(arr[i], arr[j]);
    }
}

void quicksort(int arr[], int begin, int end)
{
    if (begin < end)
    {
        auto pivot = partition(arr, begin, end);
        quicksort(arr, begin, pivot);
        quicksort(arr, pivot + 1, end);
    }
}

int main()
{
    int n;
    cin >> n;
    int a[2026];
    for (int i = 0;i < n;i++)
        cin >> a[i];
    srand(time(nullptr));
    quicksort(a, 0, n - 1);
    for (int i = 0;i < n;i++)
        cout << a[i] << ' ';
    return 0;
}