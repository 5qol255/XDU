#include <bits/stdc++.h>
#define mian main

using namespace std;

int mian()
{
    unsigned char sum = 0;
    string s;
    getline(cin, s);
    for (int i = 0; s[i] != '\0'; ++i)
        sum += s[i];
    printf("%u", sum);
    return 0;
}