#include <iostream>
using namespace std;

typedef int Status;
typedef char ElemType;
typedef struct Node
{
    ElemType data;
    struct Node *Lchild, *Rchild;
} BTreeNode, *BTree;

void CreateBTree(BTree &T);
void PreOrder(BTree &T);
void InOrder(BTree &T);
void PostOrder(BTree &T);

BTree T;

int main()
{
    CreateBTree(T);
    PreOrder(T);
    cout << '\n';
    InOrder(T);
    cout << '\n';
    PostOrder(T);
    return 0;
}

void CreateBTree(BTree &T)
{
    char ch;
    cin >> ch;
    if (ch == '.')
        T = NULL;
    else
    {
        T = new BTreeNode;
        T->data = ch;
        CreateBTree(T->Lchild);
        CreateBTree(T->Rchild);
    }
}

void PreOrder(BTree &T)
{
    if (T != NULL)
    {
        cout << T->data << ' ';
        PreOrder(T->Lchild);
        PreOrder(T->Rchild);
    }
}

void InOrder(BTree &T)
{
    if (T != NULL)
    {
        InOrder(T->Lchild);
        cout << T->data << ' ';
        InOrder(T->Rchild);
    }
}

void PostOrder(BTree &T)
{
    if (T != NULL)
    {
        PostOrder(T->Lchild);
        PostOrder(T->Rchild);
        cout << T->data << ' ';
    }
}