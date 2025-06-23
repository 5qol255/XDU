/* 1. (简答题, 60分)
Write a C++ program that prints the sizes of the fundamental types, a few pointer types, and a few enumerations of your choice.
[Tips]Use the sizeof operator;
[NOTICE] Use the form "cout >> var" for output----DON'T use printf.
【提交】在解答框内先填写你的源代码，紧跟两个空行，接着将程序运行时产生的输出文本续写在解答框内（贴图者计为 0 分）。 */
// 完成日期：2025/3/14
// 编译器：g++
// 测试环境：Windows11 x64
// 编码：utf8
#include <iostream>
using namespace std;

typedef enum
{
    Overflow = -1,
    Error,
    Ok
} STATUS;

int main()
{
    char c = 'c';
    char *cp = &c;
    short b = 56343;
    short *bp = &b;
    long a = 114514;
    long *ap = &a;
    STATUS good = Overflow;
    STATUS *gp = &good;
    void *p = NULL;
    cout << "The size of a char variable is " << sizeof(c) << " Byte.\n";
    cout << "The size of a pointer to char variable are " << sizeof(cp) << " Bytes.\n";
    cout << "The size of a short variable are " << sizeof(b) << " Bytes.\n";
    cout << "The size of a pointer to short variable are " << sizeof(bp) << " Bytes.\n";
    cout << "The size of a long variable are " << sizeof(a) << " Bytes.\n";
    cout << "The size of a pointer to long variable are " << sizeof(ap) << " Bytes.\n";
    cout << "The size of a enum variable are " << sizeof(good) << " Bytes.\n";
    cout << "The size of a pointer to enum variable are " << sizeof(gp) << " Bytes.\n";
    cout << "The size of a void pointer are " << sizeof(p) << " Bytes.\n";
}
