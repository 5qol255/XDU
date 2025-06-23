/* 题目
Write declarations(and initialize each one)  for the following :
(1) a pointer to a character;
(2) an array of 3 intergers;
(3) a pointer to an array of 3 integers;
(4) a pointer to an array of character strings;
(5) a pointer to a pointer to a character;
(6) a constant integer;
(7) a pointer to a constant integer;
(8) a constant pointer to an integer.
[Warning] Don't paste picture!
[Tip] You should check your declarations according to the "GOLDEN RULE" in "How to read C declarations" .
（35.0分） */
// 完成日期：2025/3/23
// 编译器：g++
// 测试环境：Windows11 x64
// 编码：utf8
#include <string>
int main()
{
    // 1
    char c = '1';
    char *cp = &c;
    // 2
    int arr[] = {1, 2, 3};
    // 3
    int (*arrp)[3] = &arr;
    // 4
    // char *strs[] = {"123", "456.789"};
    // char *(*strsp)[2] = &strs;
    std::string strArr[] = {"123", "abc"};
    std::string(*pStrArr)[2] = &strArr;
    // 5
    char **cpp = &cp;
    // 6
    const int ci = 10;
    // 7
    const int *cip = &ci;
    // 8
    int x = 100;
    int *const xp = &x;
    return 0;
}