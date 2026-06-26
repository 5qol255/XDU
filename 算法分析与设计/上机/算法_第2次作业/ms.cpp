#include<iostream>

using namespace std;

int ms(int arr[], int n)
{
    int dp = arr[0], ans = arr[0];
    for (int i = 1;i < n;i++)
    {
        dp = max(arr[i], dp + arr[i]);
        ans = max(ans, dp);
    }
    return ans;
}

int main()
{
    int n, arr[10000];
    cin >> n;
    for (int i = 0;i < n;i++)
        cin >> arr[i];
    cout << ms(arr, n);
    return 0;
}
