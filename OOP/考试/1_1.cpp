#include <iostream>
#include <string>
using namespace std;

class Double
{
    double value;

public:
    Double(double v = 0) : value(v) {}
    Double(const Double &D) : value(D.value) {}
    bool operator==(const Double &other) const { return value == other.value; }
    string toString() const { return to_string(value); }
    operator int() const { return int(value); }
};