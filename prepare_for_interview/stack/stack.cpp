#include <bits/stdc++.h>
using namespace std;

class Stack
{
public:
    vector<int> list;

    Stack() : list(0){};

    void psuh(int value)
    {
        list.push_back(value);
    }
    int pop()
    {
        if (list.empty())
            return -1;

        int result = list.back();
        list.pop_back();

        return result;
    }
};

int main()
{
    Stack st = Stack();

    st.psuh(5);
    st.psuh(6);
    st.psuh(7);
    st.psuh(8);
    cout << st.pop() << endl;
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// class Stack
// {

// public:
//     vector<int> stack;

//     void push(int value)
//     {
//         stack.push_back(value);
//     }
//     int pop()
//     {

//         if (stack.empty())
//             return -1;

//         int top = stack.back();
//         stack.erase(stack.end() - 1);

//         return top;
//     }
// };

// int main()
// {

//     Stack *st = new Stack();

//     st->push(3);
//     st->push(4);
//     st->push(5);

//     cout << st->pop() << endl;
// }

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