/*
Implement any one of the two modules, Stack or Queue, declared in the previous exercise in this assignment.
Please test your implementation in a main() function.
【文件要求】
1. A header file, such as stack.hpp,  which declares the interface of your module.
2. A implementation file, such as stack.cpp,  in which defines all functions of your interface and all data entities on demand.
*/
/*
Suppose you need two modules,
(1) one  provides a set of operations on Stack(LIFO), and
(2) another provides a set of operations on Queue(FIFO).
Please declare a proper interface(API) that you expected for each module using the namespace mechanism, and you should define the required types(data structures).
[重要提示]
(1) Don't implement any function.
(2) Don't define any data entity in the interface.
(3) Explain the meanings of each member of the interfaces in comments.
*/
// 完成日期：2025/3/30
// 编码：utf8
// 编译器：g++
// 测试环境：Windows11 x64
#include <iostream>
#include "my_stack.h"
#include "my_queue.h"

int main()
{
    stk::Stack s = stk::create();
    stk::push(s, 10);
    stk::push(s, 20);
    stk::push(s, 30);
    stk::push(s, 40);
    stk::push(s, 50);

    while (!stk::isEmpty(s))
        std::cout << stk::pop(s) << " ";

    stk::push(s, 20);
    stk::push(s, 30);
    stk::push(s, 40);
    stk::clear(s);
    while (!stk::isEmpty(s))
        std::cout << stk::pop(s) << " ";
    std::cout << "end.\n";

    stk::destroy(s);

    return 0;
}