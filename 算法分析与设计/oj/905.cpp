#include<iostream>
#include<cstring>

using namespace std;

void merge(int arr[], int begin, int mid, int end)
{
    int* temp = new int[end - begin + 1];
    auto a1 = begin, a2 = mid + 1, p = 0;
    while (a1 != mid + 1 && a2 != end + 1)
    {
        if (arr[a1] < arr[a2])
            temp[p++] = arr[a1++];
        else
            temp[p++] = arr[a2++];
    }
    while (a1 != mid + 1)
        temp[p++] = arr[a1++];
    while (a2 != end + 1)
        temp[p++] = arr[a2++];
    memcpy(arr + begin, temp, (end - begin + 1) * sizeof(int));
    delete[] temp;
}

void merge_sort(int arr[], int begin, int end)
{
    if (begin < end)
    {
        auto mid = begin + (end - begin) / 2;
        merge_sort(arr, begin, mid);
        merge_sort(arr, mid + 1, end);
        merge(arr, begin, mid, end);
    }
}

int main()
{
    int n;
    cin >> n;
    int a[2026];
    for (int i = 0;i < n;i++)
        cin >> a[i];
    merge_sort(a, 0, n - 1);
    for (int i = 0;i < n;i++)
        cout << a[i] << ' ';
    return 0;
}