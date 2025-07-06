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
} Node, *LinkList;

void InitList(LinkList &L);
void Traverse(LinkList &L);
Status Insert(LinkList &L, ElemType a, int i);
Status Delete(LinkList &L, int i);

LinkList A;

int main()
{
    InitList(A);
    int x;
    cin >> x;
    while (x != 0)
    {
        Insert(A, x, 1);
        cin >> x;
    }
    Traverse(A);
    Delete(A, 1);
    Traverse(A);
    return 0;
}

Status Delete(LinkList &L, int i)
{
    Node *p = L, *q;
    int j = 0;
    while (p != NULL && (j < i - 1))
    {
        p = p->next;
        j++;
    }
    if (p == NULL || (j > i - 1))
        return ERROR;
    q = p->next;
    p->next = q->next;
    delete q;
    return OK;
}

void InitList(LinkList &L)
{
    L = new Node;
    L->next = NULL;
}

Status Insert(LinkList &L, ElemType a, int i)
{
    Node *p = L;
    int j = 0;
    while (p != NULL && (j < i - 1))
    {
        p = p->next;
        j++;
    }
    if (p == NULL || (j > i - 1))
        return ERROR;
    Node *s = new Node;
    s->data = a;
    s->next = p->next;
    p->next = s;
    return OK;
}

void Traverse(LinkList &L)
{
    LinkList head = L;
    if (L->next == NULL)
        cout << "empty list!";
    else
        while (head->next != NULL)
        {
            head = head->next;
            cout << head->data << ' ';
        }
    cout << '\n';
}