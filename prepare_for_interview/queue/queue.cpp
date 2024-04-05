#include <bits/stdc++.h>
using namespace std;

class Queue
{

public:
    vector<int> queue;

    void enqueue(int data)
    {
        queue.push_back(data);
    }

    int dequeue()
    {
        int res;
        if (!queue.empty())
        {
            res = queue[0];
            queue.erase(queue.begin());
        }
        return res;
    }

    // Queue(int size) : queue(size){};
};

int main()
{
    Queue q;
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    int t = q.dequeue();

    return 0;
}