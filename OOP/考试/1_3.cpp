#include <iostream>
using namespace std;

class Sequence
{
protected:
    int number;

public:
    Sequence(int v = 0) : number(v) {}
    virtual void print() = 0;
};
class Increment : public Sequence
{
public:
    Increment(int v = 0) : Sequence(v) {}
    void print() { cout << number++ << '\t'; }
};
class Decrement : public Sequence
{
public:
    Decrement(int v = 0) : Sequence(v) {}
    void print() { cout << number-- << '\t'; }
};
class Power : public Sequence
{
public:
    Power(int v = 0) : Sequence(v) {}
    void print()
    {
        cout << number << '\t';
        number *= number;
    }
};