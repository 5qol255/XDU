#### 作业

&emsp;&emsp;作业老师基本每讲完一章内容就会布置一次。chap10及之前的作业题目和要求写在代码注释里面了，chap11和chap12题目有单独的文件。代码写的很烂，仅供参考。

#### 上机

&emsp;&emsp;上机题目和要求还有报告放在一个文件夹里，代码在另一个文件夹里。代码写的很烂，仅供参考。

#### 考试

&emsp;&emsp;试卷可以去这个仓库看[Happy-SE-in-XDU](https://github.com/LevickCG/Happy-SE-in-XDU)，下面附上一些我做的大题的代码，同样仅供参考。

#### 附录

对应Happy-SE-in-XDU中OOP下面的试卷

##### 1_OOP-2021下学期-面向对象A（卓越班）-褚华.pdf

###### partⅢ 2 考试/1_1.cpp

```cpp
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
```

###### partIV 1 考试/1_2.cpp

```cpp
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
```

###### partIV 2 考试/1_3.cpp

```cpp
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
```

##### OOP往年题.pdf

###### 第一套partⅢ 2 考试/2_1.cpp

```cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Book
{
    string title, ISBN;
    vector<string> author;

public:
    Book();
    Book(const string &title, const string &ISBN);
    void addAuthor(const string &author);
    void setTitle(const string &title);
    void setISBN(const string &ISBN);
    string getTitle() const;
    string getISBN() const;
};
```

###### 第一套partIV 1 考试/2_2.cpp

```cpp
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
```

###### 第一套partIV 2 考试/2_3.cpp

```cpp
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
```

###### 第二套partⅢ 2 考试/3_1.cpp

```cpp
class Point
{
    int x, y;

public:
    Point(int x = 0, int y = 0) : x(x), y(y) {}
    Point &operator+=(const Point &other)
    {
        x += other.x;
        y += other.y;
        return *this;
    }
    int getX() const { return x; }
    int getY() const { return y; }
    void setX(int x) { this->x = x; }
    void setY(int y) { this->y = y; }
};
```

###### 第二套partIV 1 考试/3_2.cpp

```cpp
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
```

###### 第二套partIV 2 考试/3_3.cpp

```cpp
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
```
