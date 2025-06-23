/*
Java 语言中为所有基本类型均提供了一个包装类，如 Integer 是 int 的包装类,
Double 是 double 的包装类等等。请您为 C++ 的基本类型 int 或
double 定义一个相应的包装类，如命名为 Integer, Double等。
具体要求请参见附件中的说明。
 */
#include "interger.h"
#include <cassert>
#include <sstream>
using namespace std;

void test_all()
{
    cout << "===== start testing =====\n";
    // 构造测试
    Integer a;
    assert((int)a == 0 && "failed to default construct");
    Integer b(42);
    assert((int)b == 42 && "failed to integer construct");
    Integer c("-123");
    assert((int)c == -123 && "failed to string construct");
    Integer d = c;
    assert((int)d == -123 && "failed to copy construct");
    cout << "construct test passed\n";

    // 赋值测试
    a = 100;
    assert((int)a == 100 && "failed to assign");
    a = c;
    assert((int)a == -123 && "failed to assign from string");
    cout << "assign test passed\n";

    // 类型转换测试
    Integer conv(65);
    assert(int(conv) == 65 && "failed to convert to int");
    assert(char(conv) == 'A' && "failed to convert to char");
    assert(bool(conv) && "failed to convert to bool");
    assert(double(conv) == 65.0f && "failed to convert to double");
    assert(string(conv) == "65" && "failed to convert to string");
    cout << "type convert test passed\n";

    // 算术运算
    Integer x(10), y(3);
    assert(x + y == (Integer)13 && "failed to add");
    assert(x + (Integer)1145 == (Integer)1155 && "failed to add");
    assert((Integer)3 + y == (Integer)6 && "failed to add");
    assert(x - (Integer)122 == (Integer)-112 && "failed to subtract");
    assert((Integer)1 - x == (Integer)-9 && "failed to subtract");
    assert(x * y == (Integer)30 && "failed to multiply");
    assert(y * x == (Integer)30 && "failed to multiply");
    assert(x / y == (Integer)3 && "failed to divide");
    assert(x % y == (Integer)1 && "failed to modulus");
    assert(+x == (Integer)10 && "failed to unary plus");
    assert(-x == (Integer)-10 && "failed to unary minus");
    cout << "arithmetic test pass\n";

    // 自增/自减
    Integer n(5);
    assert(++n == (Integer)6 && "failed to prefix ++");  // n=6
    assert(n++ == (Integer)6 && "failed to postfix ++"); // n=7
    assert(--n == (Integer)6 && "failed to prefix --");  // n=6
    assert(n-- == (Integer)6 && "failed to postfix --"); // n=5
    assert(n == (Integer)5 && "failed to ++/--");
    cout << "++/-- test passed\n";

    // 流操作
    stringstream ss;
    ss << Integer(123);
    assert(ss.str() == "123" && "failed to stream output");
    Integer input;
    ss >> input;
    assert(input == (Integer)123 && "failed to stream input");
    cout << "stream test passed\n";

    // 异常测试
    bool caught = false;
    try
    {
        Integer(5) / Integer(0);
    }
    catch (runtime_error &)
    {
        caught = true;
    }
    assert(caught && "failed to catch Division by zero exception");

    cout << "exception test passed\n";

    // 关系运算
    assert(Integer(5) > (Integer)3 && "failed to compare greater than");
    assert(Integer(2) <= (Integer)2 && "failed to compare less than or equal to");
    assert(Integer(4) != (Integer)5 && "failed to compare not equal to");
    cout << "relation test passed\n";

    cout << "===== all test passed! =====\n";
}

int main()
{
    test_all();
    return 0;
}