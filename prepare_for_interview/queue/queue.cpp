#include <bits/stdc++.h>
using namespace std;

class Queue
{
public:
    vector<int> que;

    void push(int value)
    {
        que.push_back(value);
    }

    int pop()
    {

        if (que.empty())
            return -1;
        int result = que[0];

        que.erase(que.begin());

        return result;
    }
};

int main()
{

    Queue q = Queue();
    q.push(3);
    q.push(4);
    q.push(5);
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// class Queue
// {
// public:
//     vector<int> que;

//     void push(int value)
//     {
//         que.push_back(value);
//     }

//     int pop()
//     {

//         if (que.empty())
//             return -1;

//         int top = que[0];
//         que.erase(que.begin());
//         return top;
//     }
// };

// int main()
// {
//     Queue *queue = new Queue();

//     queue->push(3);
//     queue->push(4);
//     queue->push(5);
//     cout << queue->pop() << endl;
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// class Queue
// {

// public:
//     vector<int> queue;

//     void enqueue(int data)
//     {
//         queue.push_back(data);
//     }

//     int dequeue()
//     {
//         int res;
//         if (!queue.empty())
//         {
//             res = queue[0];
//             queue.erase(queue.begin());
//         }
//         return res;
//     }

//     // Queue(int size) : queue(size){};
// };

// int main()
// {
//     Queue q;
//     q.enqueue(4);
//     q.enqueue(5);
//     q.enqueue(6);
//     int t = q.dequeue();

//     return 0;
// }