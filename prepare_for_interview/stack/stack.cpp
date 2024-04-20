#include <bits/stdc++.h>
using namespace std;

class Stack
{

public:
    vector<int> stack;

    void push(int value)
    {
        stack.push_back(value);
    }
    int pop()
    {

        if (stack.empty())
            return -1;

        int top = stack.back();
        stack.erase(stack.end() - 1);

        return top;
    }
};

int main()
{

    Stack *st = new Stack();

    st->push(3);
    st->push(4);
    st->push(5);

    cout << st->pop() << endl;
}

// #include <bits/stdc++.h>
// using namespace std;

// class Stack
// {

// public:
//     vector<int> stack;

//     void push(int data)
//     {
//         stack.push_back(data);
//     }

//     int pop()
//     {

//         int res = stack[stack.size() - 1];
//         // stack.pop_back();
//         stack.erase(stack.end() - 1);
//         return res;
//     }

//     Stack() : stack(){};
// };

// int main()
// {

//     Stack stack;

//     stack.push(1);
//     stack.push(2);
//     stack.push(3);
//     stack.push(4);
//     stack.pop();

//     return 0;
// }