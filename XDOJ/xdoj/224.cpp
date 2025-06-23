#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a[12];
	for (int i = 0; i < 12; ++i)
		cin >> a[i];
	cout << a[0]*a[6] + a[1]*a[8] + a[2]*a[10] << ' '
	     << a[0]*a[7] + a[1]*a[9] + a[2]*a[11] << '\n'
	     << a[3]*a[6] + a[4]*a[8] + a[5]*a[10] << ' '
	     << a[3]*a[7] + a[4]*a[9] + a[5]*a[11] << endl;
	return 0;
}