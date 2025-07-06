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
void Sort(LinkList &L);

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
    Sort(A);
    Traverse(A);
    Delete(A, 1);
    Traverse(A);
    return 0;
}

void Sort(LinkList &L)
{
    if (L->next == NULL)
        return;
    Node *p = L, *q = L, *mp = NULL, *mq = NULL, *NL = NULL;
    int i = 0, n = 0;
    while (p->next != NULL)
    {
        p = p->next;
        n++;
    }
    for (i = 0; i < n; i++)
    {
        mp = L->next;
        mq = L;
        p = L->next;
        q = L;
        while (p != NULL)
        {
            if (p->data > mp->data)
            {
                mq = q;
                mp = p;
            }
            q = p;
            p = p->next;
        }
        mq->next = mp->next;
        mp->next = NULL;
        if (NL == NULL)
            NL = mp;
        else
        {
            for (p = NL; p->next != NULL; p = p->next)
                ;
            p->next = mp;
        }
    }
    L->next = NL;
}

Status Delete(LinkList &L, int i)
{
    Node *p = L, *q = NULL;
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