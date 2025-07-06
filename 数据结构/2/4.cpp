#include <iostream>
#include <string.h>
using namespace std;
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
typedef struct
{
    int i, j;
} ElemType;
typedef struct Node
{
    ElemType data;
    struct Node *next;
} Node, *Stack;

void Push(ElemType a);
ElemType Pop();
ElemType Top();
bool Empty();
void dfs(ElemType start, ElemType end);

Stack A;
int maze[100][100];
bool mark[100][100];
int size;
int m, n;

int main()
{
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> maze[i][j];
    ElemType start = {1, 1}, end = {m, n};
    dfs(start, end);
    return 0;
}

void dfs(ElemType start, ElemType end)
{
    int directions[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    Push(start);
    mark[start.i][start.j] = true;

    while (!Empty())
    {
        ElemType current = Top();
        // 结束
        if (current.i == end.i && current.j == end.j)
        {
            ElemType *tmp = new ElemType[size];
            int i = 0;
            while (!Empty())
                tmp[i++] = Pop();
            for (i--; i >= 0; i--)
            {
                cout << tmp[i].i << ' ' << tmp[i].j << ' ';
                if (tmp[i].i - 1 == tmp[i - 1].i && tmp[i].j == tmp[i - 1].j)
                    cout << 1 << '\n';
                else if (tmp[i].i == tmp[i - 1].i && tmp[i].j + 1 == tmp[i - 1].j)
                    cout << 2 << '\n';
                else if (tmp[i].i + 1 == tmp[i - 1].i && tmp[i].j == tmp[i - 1].j)
                    cout << 3 << '\n';
                else if (tmp[i].i == tmp[i - 1].i && tmp[i].j - 1 == tmp[i - 1].j)
                    cout << 4 << '\n';
                else
                    cout << '\n';
            }
            for (i = 0; i < size; i++)
                Push(tmp[i]);
            delete tmp;
            return;
        }
        // 访问
        bool has_unvisited = false;
        int nexti, nextj;
        for (int x = 0; x < 4; x++)
        {
            nexti = current.i + directions[x][0];
            nextj = current.j + directions[x][1];
            if (nexti >= 1 && nexti <= m && nextj >= 1 && nextj <= n &&
                !mark[nexti][nextj] && maze[nexti][nextj] == 0)
            {
                ElemType step = {nexti, nextj};
                mark[nexti][nextj] = true;
                Push(step);
                has_unvisited = true;
                break;
            }
        }
        // 回溯
        if (!has_unvisited)
        {
            ElemType tmp = Pop();
            mark[tmp.i][tmp.j] = false;
        }
    }
    cout << "No way." << endl;
}

ElemType Pop()
{
    Node *temp;
    ElemType x;
    temp = A;
    A = A->next;
    x = temp->data;
    delete temp;
    size--;
    return x;
}

ElemType Top()
{
    return A->data;
}

void Push(ElemType a)
{
    Node *temp = new Node;
    temp->data = a;
    temp->next = A;
    A = temp;
    size++;
}

bool Empty()
{
    return A == NULL ? true : false;
}

/*
8 9
0 0 1 1 1 1 1 1 1
1 0 1 1 1 1 1 1 1
1 0 0 0 0 0 0 1 1
1 1 1 0 1 1 0 1 1
0 0 0 0 0 1 0 1 1
0 0 1 1 0 0 0 0 0
1 1 0 0 1 1 0 1 0
1 1 1 0 1 1 0 0 0
 */