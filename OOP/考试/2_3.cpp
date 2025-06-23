class Sequence
{
protected:
    int number;

public:
    Sequence(int v) : number(v) {}
    virtual void action() {}
    virtual int getNumber() { return number; }
};

class Decrement : public Sequence
{
public:
    Decrement(int n) : Sequence(n) {}
    void action() { --number; }
};

class Increment : public Sequence
{
public:
    Increment(int n) : Sequence(n) {}
    void action() { ++number; }
};

class Square : public Sequence
{
    Square(int n) : Sequence(n) {}
    void action() { number *= number; }
};
