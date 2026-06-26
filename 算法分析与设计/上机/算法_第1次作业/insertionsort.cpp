#include<iostream>

using namespace std;

void insertion_sort(int arr[], int begin, int end)
{
    for (int i = begin + 1;i <= end;i++)
    {
        auto key = arr[i];
        int j = i - 1;
        while (j >= begin && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    int n;
    cin >> n;
    int a[2026];
    for (int i = 0;i < n;i++)
        cin >> a[i];
    insertion_sort(a, 0, n - 1);
    for (int i = 0;i < n;i++)
        cout << a[i] << ' ';
    return 0;
}