#include <iostream>
using namespace std;

class Integer
{
    int value;

public:
    Integer(int v = 0) : value(v) {}
    Integer(const Integer &I) : value(I.value) {}
    Integer &operator+(const int a)
    {
        value += a;
        return *this;
    }
    Integer &operator-(const int a)
    {
        value -= a;
        return *this;
    }
    Integer &operator*=(const Integer &other)
    {
        value *= other.value;
        return *this;
    }
    void print(const string &s) { cout << s << value; }
};