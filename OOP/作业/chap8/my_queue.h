#ifndef MY_QUEUE_H
#define MY_QUEUE_H
// typedef struct Que *Queue;
// typedef int ElementType;

namespace que
{
    using ElementType = int;
    using Queue = struct Que *;
    Queue create(int n = 100);      // 创建一个队列(容量默认100)并返回其引用
    void clear(Queue);              // 清空队列
    void enter(Queue, ElementType); // 将一个int类型变量的值插入到队列尾部
    ElementType quit(Queue);        // 将队列头的值删除，返回头的值
    ElementType front(const Queue); // 返回队列头的值
    ElementType rear(const Queue);  // 返回队列尾的值
    bool isEmpty(const Queue);      // 返回队列是否为空
    void destroy(Queue);            // 删除队列释放内存
};
#endif // MY_QUEUE_H