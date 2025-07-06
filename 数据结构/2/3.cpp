#include <iostream>
using namespace std;
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
typedef struct
{
    int id, t;
} car;
typedef car ElemType;
// 定义栈的数据结构
typedef struct
{
    int top, size; // 栈中最大元素数量
    ElemType *data;
} Stack;
// 定义队列的数据结构
typedef struct QNode
{
    ElemType data;
    struct QNode *next;
} QNode;
typedef struct
{
    QNode *front, *rear;
    int size; // 队列元素个数
} Queue;

// 栈相关函数
void InitStack(Stack &S, int size);
void Pop(Stack &S);
void Push(Stack &S, ElemType a);
void Top(Stack &S, ElemType &a);
bool EmptyStack(Stack &S);
bool OverFlow(Stack &S);
// 队列相关函数
void InitQueue(Queue &Q);
void EnterQueue(Queue &Q, ElemType a);
void QuitQueue(Queue &Q, ElemType &a);
bool EmptyQueue(Queue &Q);

Stack CarPark, Temp;
Queue WaitingArea;

int main()
{
    int n;
    char sta;
    car x;
    cin >> n;
    InitStack(CarPark, n);
    InitStack(Temp, n);
    InitQueue(WaitingArea);
    while (true)
    {
        cin >> sta >> x.id >> x.t;
        if (sta == 'A')
        {
            if (OverFlow(CarPark)) // 没有位置
            {
                x.t = -1; // 进入时间设为-1以便区分没进停车场的车
                EnterQueue(WaitingArea, x);
                cout << "The car is waiting at No." << WaitingArea.size << '\n';
            }
            else
            {
                Push(CarPark, x);
                cout << "The car is parked at No." << CarPark.top + 1 << '\n';
            }
        }
        else if (sta == 'D')
        {
            ElemType c;
            for (Top(CarPark, c); c.id != x.id; Top(CarPark, c))
            {
                Pop(CarPark);
                Push(Temp, c);
            }
            cout << x.t - c.t << " min\n";
            Pop(CarPark);
            while (!EmptyStack(Temp))
            {
                ElemType tmp;
                Top(Temp, tmp);
                Push(CarPark, tmp);
                Pop(Temp);
            }
            if (!EmptyQueue(WaitingArea))
            {
                QuitQueue(WaitingArea, c);
                c.t = x.t;
                Push(CarPark, c);
            }
        }
        else
            break;
    }
    return 0;
}

void InitQueue(Queue &Q)
{
    Q.front = new QNode;
    Q.front->next = NULL;
    Q.rear = Q.front;
    Q.size = 0;
}

void EnterQueue(Queue &Q, ElemType a)
{
    QNode *s = new QNode;
    s->data = a;
    s->next = NULL;
    Q.rear->next = s;
    Q.rear = s;
    Q.size++;
}

void QuitQueue(Queue &Q, ElemType &a)
{
    if (EmptyQueue(Q))
        return;
    QNode *head = Q.front->next;
    a = head->data;
    Q.front->next = Q.front->next->next;
    if (Q.rear == head)
        Q.rear = Q.front;
    delete head;
    Q.size--;
}

bool EmptyQueue(Queue &Q)
{
    return Q.size == 0;
}

void InitStack(Stack &S, int size)
{
    S.size = size;
    S.top = -1;
    S.data = new ElemType[size];
}

void Pop(Stack &S)
{
    if (EmptyStack(S))
        return;
    S.top--;
}

void Push(Stack &S, ElemType a)
{
    S.data[++S.top] = a;
}

void Top(Stack &S, ElemType &a)
{
    if (!EmptyStack(S))
        a = S.data[S.top];
}

bool EmptyStack(Stack &S)
{
    return S.top == -1;
}

bool OverFlow(Stack &S)
{
    return S.top == S.size - 1;
}