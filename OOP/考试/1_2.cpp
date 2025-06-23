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
    Integer &operator/(const Integer &other)
    {
        value /= other.value;
        return *this;
    }
    Integer &operator*=(const Integer &other)
    {
        value *= other.value;
        return *this;
    }
    friend ostream &operator<<(ostream &out, const Integer &I)
    {
        out << I.value;
        return out;
    }
    friend istream &operator>>(istream &in, Integer &I)
    {
        in >> I.value;
        return in;
    }
};