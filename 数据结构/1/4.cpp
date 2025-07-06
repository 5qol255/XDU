#include <iostream>
using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
typedef struct
{
    float a;
    int n;
} expr;
typedef expr ElemType;
typedef struct Node
{
    ElemType data;
    struct Node *next;
} Node, *LinkList;

void InitList(LinkList &L);
void Traverse(LinkList &L);
Status Insert(LinkList &L, ElemType a);
void Add(LinkList &A, LinkList &B, LinkList &C);
void Sub(LinkList &A, LinkList &B, LinkList &C);
void Reverse(LinkList &L);

LinkList A, B, C;

int main()
{
    InitList(A);
    InitList(B);
    InitList(C);
    int n;
    expr x;
    cin >> n;
    A->data.n = n;
    while (n--)
    {
        cin >> x.a >> x.n;
        Insert(A, x);
    }
    cin >> n;
    B->data.n = n;
    while (n--)
    {
        cin >> x.a >> x.n;
        Insert(B, x);
    }
    Sub(A, B, C);
    Traverse(C);
    return 0;
}

void Reverse(LinkList &L)
{
    Node *p, *s = NULL;
    p = L->next;
    L->next = NULL;
    while (p != NULL)
    {
        s = p;
        p = p->next;
        s->next = L->next;
        L->next = s;
    }
}

void Add(LinkList &A, LinkList &B, LinkList &C)
{
    auto pa = A->next, pb = B->next, pc = C;
    while (pa != NULL && pb != NULL)
    {
        if (pa->data.n < pb->data.n)
        {
            Insert(C, pa->data);
            pa = pa->next;
        }
        else if (pa->data.n > pb->data.n)
        {
            Insert(C, pb->data);
            pb = pb->next;
        }
        else
        {
            expr x = {pa->data.a + pb->data.a, pa->data.n};
            if (x.a != 0)
                Insert(C, x);
            pa = pa->next;
            pb = pb->next;
        }
    }
    if (pa == NULL)
        while (pb != NULL)
        {
            Insert(C, pb->data);
            pb = pb->next;
        }
    else if (pb == NULL)
        while (pa != NULL)
        {
            Insert(C, pa->data);
            pa = pa->next;
        }
    if (C->next == NULL)
    {
        Insert(C, expr{0, 0});
        C->data.n = 1;
    }
    else
    {
        int n = 0;
        pc = C;
        while (pc->next != NULL)
        {
            pc = pc->next;
            n++;
        }
        C->data.n = n;
    }
    Reverse(C);
}

void Sub(LinkList &A, LinkList &B, LinkList &C)
{
    auto pa = A->next, pb = B->next, pc = C;
    while (pa != NULL && pb != NULL)
    {
        if (pa->data.n < pb->data.n)
        {
            Insert(C, pa->data);
            pa = pa->next;
        }
        else if (pa->data.n > pb->data.n)
        {
            expr x = {-pb->data.a, pb->data.n};
            Insert(C, x);
            pb = pb->next;
        }
        else
        {
            expr x = {pa->data.a - pb->data.a, pa->data.n};
            if (x.a != 0)
                Insert(C, x);
            pa = pa->next;
            pb = pb->next;
        }
    }
    if (pa == NULL)
        while (pb != NULL)
        {
            expr x = {-pb->data.a, pb->data.n};
            Insert(C, x);
            pb = pb->next;
        }
    else if (pb == NULL)
        while (pa != NULL)
        {
            Insert(C, pa->data);
            pa = pa->next;
        }
    if (C->next == NULL)
    {
        Insert(C, expr{0, 0});
        C->data.n = 1;
    }
    else
    {
        int n = 0;
        pc = C;
        while (pc->next != NULL)
        {
            pc = pc->next;
            n++;
        }
        C->data.n = n;
    }
    Reverse(C);
}

Status Insert(LinkList &L, ElemType a)
{
    Node *p = L;
    while (p->next != NULL)
        p = p->next;
    Node *s = new Node;
    s->data = a;
    s->next = NULL;
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
            cout << head->data.a << ' ' << head->data.n << ' ';
        }
    cout << '\n';
}

void InitList(LinkList &L)
{
    L = new Node;
    L->next = NULL;
}