#include "my_stack.h"

namespace stk
{
    Stack create(int n)
    {
        auto p = new Stk;
        p->data = new ElementType[n];
        p->amount = n;
        p->size = 0;
        return p;
    }

    bool push(Stack s, ElementType v)
    {
        if (s->size < s->amount)
            s->data[s->size++] = v;
        else
            return false;
        return true;
    }

    void clear(Stack s)
    {
        s->size = 0;
    }

    void destroy(Stack s)
    {
        delete[] s->data;
        delete s;
    }

    int size(Stack s)
    {
        return s->size;
    }

    bool isEmpty(Stack s)
    {
        return s->size == 0;
    }

    ElementType top(Stack s)
    {
        if (s->size > 0)
            return s->data[s->size - 1];
        else
            return ElementType();
    }

    ElementType pop(Stack s)
    {
        if (s->size > 0)
            return s->data[--s->size];
        else
            return ElementType();
    }
}
