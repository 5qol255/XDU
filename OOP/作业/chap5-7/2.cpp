/* 题目
Write declarations for the following:
(1) a function taking arguments of type pointer to character and reference to integer and returning no value;
(2) a pointer to such a function( in above);
(3) a function taking such a pointer as an argument;
(4) and a function returning such a pointer.
(5) Write the definition of a function that takes such a pointer as an argument and returns its argument as the return value.
[Hint: Use typedef]
[第1、3、4条仅需给出函数的非定义声明（原型），第2、5条必须给出定义]
（35.0分） */
// 完成日期：2025/3/23
// 编译器：g++
// 测试环境：Windows11 x64
// 编码：utf8

// 1
void strlen(char *s, int &len);
// 2
using funcp = void (*)(char *, int &);
// 3
void func1(funcp f);
// 4
funcp func2();
// 5
funcp func3(funcp f)
{
    return f;
}
int main()
{
    return 0;
}