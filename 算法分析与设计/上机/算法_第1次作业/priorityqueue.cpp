#include <iostream> 
#include <vector>
#include <stdexcept>

using namespace std;

class PriorityQueue
{
private:
    vector<int> heap;

    // 上浮：新元素在堆底，逐级向上交换到正确位置
    void heapifyUp(int idx)
    {
        while (idx > 1)
        {
            int parent = idx >> 1;
            if (heap[idx] > heap[parent])
            {
                swap(heap[idx], heap[parent]);
                idx = parent;
            }
            else break;
        }
    }

    // 下沉：堆顶被替换后，逐级向下交换到正确位置
    void heapifyDown(int idx)
    {
        int n = heap.size();
        while (true)
        {
            int largest = idx;
            int left = idx << 1;        // left = idx * 2
            int right = idx << 1 | 1;   // right = idx * 2 + 1
            if (left < n && heap[left] > heap[largest])
                largest = left;
            if (right < n && heap[right] > heap[largest])
                largest = right;
            if (largest != idx)
            {
                swap(heap[idx], heap[largest]);
                idx = largest;
            }
            else break;
        }
    }

public:
    PriorityQueue()
    {
        heap.push_back(0); // dummy element at index 0
    }

    void push(int val)
    {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    int pop()
    {
        if (heap.empty())
            throw runtime_error("Priority queue is empty");

        int maxVal = heap[1];
        heap[1] = heap.back();
        heap.pop_back();
        if (!heap.empty())
            heapifyDown(1);
        return maxVal;
    }

    int top()
    {
        if (heap.empty())
            throw runtime_error("Priority queue is empty");
        return heap[1];
    }

    bool empty()
    {
        return heap.size() <= 1;
    }

    size_t size()
    {
        return heap.size() - 1;
    }
};

int main()
{
    PriorityQueue pq;
    pq.push(3);
    pq.push(1);
    pq.push(4);
    pq.push(1);
    pq.push(5);
    cout << "Top element: " << pq.top() << endl
        << pq.size() << " elements in the priority queue." << endl;
    while (!pq.empty())
    {
        cout << pq.pop() << " ";
    }
    cout << endl << pq.size() << " elements in the priority queue." << endl;
    return 0;
}