#include <string>
#include <iostream>
using namespace std;

class MyString
{
    string v;

public:
    MyString(const char *s) : v(s) {}
    MyString(int n = 0) : v(n, ' ') {}
    MyString &operator=(const MyString &S)
    {
        v = S.v;
        return *this;
    }
    MyString &operator+(int x)
    {
        v = v.substr(x);
        return *this;
    }
    MyString &operator++() { return *this + 1; }
    void display() const { cout << '[' << v << "]\n"; }
};