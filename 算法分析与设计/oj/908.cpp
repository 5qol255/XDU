#include<iostream>

using namespace std;

void jump(int x, int arr[])
{
    int i = 0;
    arr[0] = 1, arr[1] = 1;
    for (;i < x;i++)
        arr[i + 2] = arr[i + 1] + arr[i];
}

int main()
{
    int x, arr[50];
    cin >> x;
    jump(x, arr);
    cout << arr[x];
    return 0;
}