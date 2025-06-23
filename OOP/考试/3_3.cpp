#include <string>
#include <iostream>
using namespace std;

class fighter
{
protected:
    string name;

public:
    fighter(const char *s) : name(s) {}
    virtual void hello() { cout << name << " is a fighter.\n"; }
    void ourTitle() { cout << "We are fighters.\n"; }
    string getName() const { return name; }
};

class Warrior : public fighter
{
    string competitor_s_name;

public:
    Warrior(const char *s, const fighter &F)
        : fighter(s), competitor_s_name(F.getName()) {}
    void hello() { cout << name << " is a stronger warrior than "
                        << competitor_s_name << '\n'; }
};