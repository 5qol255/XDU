#include <iostream>
using namespace std;
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
typedef int ElemType;
typedef struct Node
{
    ElemType data;
    struct Node *next;
} Node, *Stack;

void Pop();
void Push(ElemType a);
ElemType Top();
bool Empty();

Stack A;

int main()
{
    int x;
    cin >> x;
    while (x)
    {
        Push(x % 2);
        x /= 2;
    }
    while (!Empty())
    {
        cout << Top();
        Pop();
    }
    return 0;
}

void Pop()
{
    Node *temp = A;
    if (Empty())
        return;
    A = A->next;
    delete temp;
}

void Push(ElemType a)
{
    Node *temp = new Node;
    temp->data = a;
    temp->next = A;
    A = temp;
}

ElemType Top()
{
    if (!Empty())
        return A->data;
    return 0;
}

bool Empty()
{
    return A == NULL;
}