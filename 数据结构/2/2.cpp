#include <iostream>
using namespace std;
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
typedef char ElemType;
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
    char s[110];
    cin >> s;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == '[' || s[i] == '(' || s[i] == '{')
            Push(s[i]);
        else if (s[i] == ']')
        {
            if (Top() == '[')
                Pop();
            else
            {
                cout << "no\n";
                return 0;
            }
        }
        else if (s[i] == ')')
        {
            if (Top() == '(')
                Pop();
            else
            {
                cout << "no\n";
                return 0;
            }
        }
        else if (s[i] == '}')
        {
            if (Top() == '{')
                Pop();
            else
            {
                cout << "no\n";
                return 0;
            }
        }
    }
    if (Empty())
        cout << "yes\n";
    else
        cout << "no\n";
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
    return A == NULL ? true : false;
}