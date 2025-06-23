#ifndef MY_STACK_H
#define MY_STACK_H
// typedef struct Stk *Stack;
// typedef int ElementType;

namespace stk
{
    using ElementType = int;
    struct Stk
    {
        ElementType *data; // 栈的主体
        int size, amount;  // 元素数量，容量
    };
    using Stack = struct Stk *;
    Stack create(int n = 100);     // 创建一个栈(容量默认100)并返回其引用
    void clear(Stack);             // 清空栈
    bool push(Stack, ElementType); // 将一个ElementType类型变量的值压栈
    ElementType pop(Stack);        // 将栈顶部的值删除，返回删除的值
    ElementType top(const Stack);  // 返回栈顶的值
    int size(const Stack);         // 返回栈内的元素数量
    bool isEmpty(const Stack);     // 判断栈是否为空
    void destroy(Stack);           // 删除栈释放内存
};
#endif // MY_STACK_H