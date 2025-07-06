#include <iostream>
using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
typedef struct
{
    int id, password;
} stu;
typedef stu ElemType;
typedef struct Node
{
    ElemType data;
    struct Node *next;
} Node, *LinkList;

Status Insert(LinkList &L, ElemType a);
void F(LinkList &L, int m, int n);

int main()
{
    LinkList A = new Node;
    int n, m, password;
    cin >> m >> n;
    if (n == 1)
    {
        cout << "1\n";
        return 0;
    }
    if (n < 1)
    {
        cout << "error!\n";
        return 0;
    }

    cin >> password;
    stu a = {1, password};
    A->data = a;
    A->next = NULL;
    for (int i = 1; i < n; i++)
    {
        cin >> password;
        stu a = {i + 1, password};
        Insert(A, a);
    }
    Node *p = A;
    while (p->next != NULL)
        p = p->next;
    p->next = A;

    F(A, m, n);

    return 0;
}

void F(LinkList &L, int m, int n)
{
    Node *p, *q;
    while (n--)
    {
        p = L;
        for (int i = 1; i < m; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        L = q->next;
        cout << p->data.id << ' ';
        m = p->data.password;
        delete p;
    }
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