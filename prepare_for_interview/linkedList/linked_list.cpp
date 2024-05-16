// 毎日課題

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int value;
    Node *next;

    Node(int value) : value(value) {}
};

class LinkedList
{
public:
    Node *head;
    LinkedList() : head(nullptr){};

    void add(int value)
    {
        Node *currentNode = head;
        Node *newNode = new Node(value);

        if (currentNode == nullptr)
        {
            head = newNode;
            return;
        }

        while (currentNode->next != nullptr)
        {
            currentNode = currentNode->next;
        }

        currentNode->next = newNode;
    }

    // 先頭に追加
    void insert(int value)
    {
        Node *newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void remove(int value)
    {
        Node *currentNode = head;
        Node *previousNode = nullptr;

        if (currentNode != nullptr && value == currentNode->value)
        {
            head = currentNode->next;
            delete currentNode;
            return;
        }

        while (currentNode != nullptr && currentNode->value != value)
        {
            previousNode = currentNode;
            currentNode = currentNode->next;
        }

        if (currentNode == nullptr)
            return;

        previousNode->next = currentNode->next;
        delete currentNode;
    }

    void reverse_iterative()
    {
        Node *currentNode = head;
        Node *previousNode = nullptr;

        while (currentNode != nullptr)
        {
            Node *nextNode = currentNode->next;
            currentNode->next = previousNode;
            previousNode = currentNode;
            currentNode = nextNode;
        }

        head = previousNode;
    }

    void reverse_recursive()
    {
        function<Node *(Node *, Node *)> _reverse_recursive = [&](Node *currentNode, Node *previousNode) -> Node *
        {
            if (currentNode == nullptr)
                return previousNode;

            Node *nextNode = currentNode->next;
            currentNode->next = previousNode;

            _reverse_recursive(nextNode, currentNode);
        };
        head = _reverse_recursive(head, nullptr);
    }

    void reverse_even()
    {
        function<Node *(Node *, Node *)> _reverse_even = [&](Node *currentNode, Node *previousNode) -> Node *
        {
            if (currentNode == nullptr)
                return nullptr;

            Node *startNode = currentNode;
            while (currentNode != nullptr && currentNode->value % 2 == 0)
            {
                Node *nextNode = currentNode->next;
                currentNode->next = previousNode;
                previousNode = currentNode;
                currentNode = nextNode;
            }

            if (startNode != currentNode)
            {
                startNode->next = _reverse_even(currentNode, nullptr);
                return previousNode;
            }
            else
            {
                currentNode->next = _reverse_even(currentNode->next, currentNode);
                return currentNode;
            }
        };
        head = _reverse_even(head, nullptr);
    }
};

int main()
{

    LinkedList list = LinkedList();

    list.add(3);
    list.add(6);
    list.add(8);
    list.add(10);
    list.add(9);
    list.add(12);
    list.add(13);
    list.add(6);
    list.add(8);
    list.add(10);
    // list.insert(3);
    // list.insert(2);
    // list.remove(2);
    // list.reverse_iterative();
    // list.reverse_recursive();
    list.reverse_even();
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// struct Node
// {
//     int value;
//     Node *next;

//     Node(int value) : value(value){};
// };

// class LinkedList
// {
// public:
//     Node *head;
//     LinkedList() : head(nullptr){};

//     // 末尾に要素追加
//     void add(int value)
//     {
//         if (head == nullptr)
//         {
//             head = new Node(value);
//             return;
//         }

//         Node *currentNode = head;
//         while (currentNode->next != nullptr)
//         {
//             currentNode = currentNode->next;
//         }
//         currentNode->next = new Node(value);
//     }

//     // 先頭に要素追加
//     void insert(int value)
//     {
//         Node *newNode = new Node(value);
//         newNode->next = head;
//         head = newNode;
//     }

//     void remove(int value)
//     {

//         Node *currentNode = head;
//         Node *previousNode = nullptr;

//         if (currentNode != nullptr && currentNode->value == value)
//         {
//             head = currentNode->next;
//             delete currentNode;
//             return;
//         }

//         while (currentNode != nullptr && value != currentNode->value)
//         {
//             previousNode = currentNode;
//             currentNode = currentNode->next;
//         }

//         if (currentNode == nullptr)
//             return;

//         previousNode->next = currentNode->next;
//         delete currentNode;
//     }

//     void reverse_iterative()
//     {
//         Node *currentNode = head;
//         Node *previousNode = nullptr;

//         while (currentNode != nullptr)
//         {
//             Node *nextNode = currentNode->next;
//             currentNode->next = previousNode;

//             previousNode = currentNode;
//             currentNode = nextNode;
//         }

//         head = previousNode;
//     }

//     void reverse_recursive()
//     {

//         function<void(Node *, Node *)> _reverse_recursive = [&](Node *currentNode, Node *previousNode)
//         {
//             if (currentNode == nullptr)
//             {
//                 head = previousNode;
//                 return;
//             }
//             Node *nextNode = currentNode->next;
//             currentNode->next = previousNode;
//             _reverse_recursive(nextNode, currentNode);
//         };

//         _reverse_recursive(head, nullptr);
//     }

//     void reverse_even()
//     {

//         function<Node *(Node *, Node *)> _reverse_even = [&](Node *currentNode, Node *previousNode) -> Node *
//         {
//             Node *startNode = currentNode;

//             if (currentNode == nullptr)
//                 return nullptr;

//             while (currentNode != nullptr && currentNode->value % 2 == 0)
//             {
//                 Node *nextNode = currentNode->next;
//                 currentNode->next = previousNode;
//                 previousNode = currentNode;
//                 currentNode = nextNode;
//             }

//             if (startNode == currentNode)
//             {
//                 currentNode->next = _reverse_even(currentNode->next, currentNode);
//                 return currentNode;
//             }
//             else
//             {
//                 startNode->next = _reverse_even(currentNode, nullptr);
//                 return previousNode;
//             }
//         };
//         head = _reverse_even(head, nullptr);
//     }
// };

// int main()
// {
//     LinkedList list = LinkedList();
//     list.add(3);
//     list.add(6);
//     list.add(8);
//     list.add(10);
//     list.add(5);
//     list.add(7);
//     list.add(12);
//     list.add(9);
//     list.add(6);
//     list.add(8);
//     list.add(10);

//     list.reverse_even();

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// class Node
// {
// public:
//     int value;
//     Node *next;

//     Node(int value) : value(value){};
// };

// class LinkedList
// {
// public:
//     Node *head;

//     LinkedList() : head(nullptr){};

//     void add(int value)
//     {

//         Node *currentNode = head;
//         Node *newNode = new Node(value);

//         if (currentNode == nullptr)
//         {
//             head = newNode;
//             return;
//         }

//         while (currentNode->next != nullptr)
//         {
//             currentNode = currentNode->next;
//         }
//         currentNode->next = newNode;
//     }

//     void insert(int value)
//     {
//         Node *newNode = new Node(value);
//         newNode->next = head;
//         head = newNode;
//     }

//     void remove(int value)
//     {

//         Node *currentNode = head;
//         Node *previousNode = nullptr;

//         if (currentNode != nullptr && currentNode->value == value)
//         {
//             head = currentNode->next;
//             delete currentNode;
//             return;
//         }

//         while (currentNode != nullptr && currentNode->value != value)
//         {
//             previousNode = currentNode;
//             currentNode = currentNode->next;
//         }

//         if (currentNode == nullptr)
//             return;

//         previousNode->next = currentNode->next;
//         delete currentNode;
//     }
//     void display()
//     {
//         Node *currentNode = head;
//         while (currentNode != nullptr)
//         {

//             cout << currentNode->value << endl;
//             currentNode = currentNode->next;
//         }
//     }

//     void reverse_iterative()
//     {
//         Node *currentNode = head;
//         Node *previousNode = nullptr;

//         while (currentNode != nullptr)
//         {
//             Node *nextNode = currentNode->next;
//             currentNode->next = previousNode;
//             previousNode = currentNode;
//             currentNode = nextNode;
//         }

//         head = previousNode;
//     }

//     void reverse_recursive()
//     {
//         head = _reverse_recursive(head, nullptr);
//     }

//     void reverse_even()
//     {
//         head = _reverse_even(head, nullptr);
//     }

// private:
//     Node *_reverse_recursive(Node *currentNode, Node *previousNode)
//     {
//         if (currentNode == nullptr)
//         {
//             return previousNode;
//         }
//         Node *nextNode = currentNode->next;
//         currentNode->next = previousNode;

//         return _reverse_recursive(nextNode, currentNode);
//     }
//     Node *_reverse_even(Node *currentNode, Node *previousNode)
//     {

//         Node *startNode = currentNode;

//         if (currentNode == nullptr)
//             return nullptr;

//         while (currentNode != nullptr && currentNode->value % 2 == 0)
//         {
//             Node *nextNode = currentNode->next;
//             currentNode->next = previousNode;
//             previousNode = currentNode;
//             currentNode = nextNode;
//         }
//         if (startNode != currentNode)
//         {
//             startNode->next = currentNode;
//             _reverse_even(currentNode, nullptr);
//             return previousNode;
//         }
//         else
//         {
//             currentNode->next = _reverse_even(currentNode->next, currentNode);
//             return currentNode;
//         }
//     }
// };

// int main()
// {
//     LinkedList list;
//     list.add(1);
//     list.add(2);
//     list.add(4);
//     list.add(6);
//     list.add(7);
//     list.add(8);
//     list.add(4);
//     list.add(2);
//     list.add(3);
//     list.insert(0);

//     list.remove(0);

//     // list.reverse_iterative();
//     // list.reverse_recursive();

//     list.reverse_even();

//     list.display();

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// class Node
// {
// public:
//     int data;
//     Node *next;

//     Node(int data) : data(data), next(nullptr) {}
// };

// class LinkedList
// {
// public:
//     Node *head;

//     LinkedList() : head(nullptr) {}

//     void add(int data)
//     {
//         Node *currentNode = head;
//         Node *newNode = new Node(data);
//         if (currentNode == nullptr)
//         {
//             head = newNode;
//             return;
//         }

//         while (currentNode->next != nullptr)
//         {
//             currentNode = currentNode->next;
//         }
//         currentNode->next = newNode;
//     }

//     void insert(int data)
//     {
//         Node *newNode = new Node(data);
//         newNode->next = head;
//         head = newNode;
//     }

//     void remove(int data)
//     {
//         Node *currentNode = head;
//         Node *previousNode = nullptr;

//         if (head != nullptr && head->data == data)
//         {
//             head = head->next;
//             return;
//         }

//         while (currentNode != nullptr && currentNode->data != data)
//         {
//             previousNode = currentNode;
//             currentNode = currentNode->next;
//         }
//         if (currentNode == nullptr)
//         {
//             return;
//         }
//         previousNode->next = currentNode->next;
//         delete currentNode;
//     }

//     void display()
//     {

//         Node *currentNode = head;

//         while (currentNode != nullptr)
//         {
//             cout << currentNode->data << endl;
//             currentNode = currentNode->next;
//         }
//     }

//     void reverse_iterative()
//     {
//         Node *currentNode = head;
//         Node *previousNode = nullptr;

//         if (currentNode == nullptr)
//             return;

//         while (currentNode != nullptr)
//         {
//             Node *nextNode = currentNode->next;
//             currentNode->next = previousNode;
//             previousNode = currentNode;
//             currentNode = nextNode;
//         }

//         head = previousNode;
//     }

//     void reverse_recursive()
//     {
//         head = _reverse_recursive(head, nullptr);
//     }

//     void reverse_even()
//     {
//         head = _reverse_even(head, nullptr);
//     }

// private:
//     Node *_reverse_recursive(Node *currentNode, Node *previousNode)
//     {

//         if (currentNode == nullptr)

//         {
//             return previousNode;
//         }
//         Node *nextNode = currentNode->next;
//         currentNode->next = previousNode;
//         return _reverse_recursive(nextNode, currentNode);
//     }

//     Node *_reverse_even(Node *currentNode, Node *previousNode)
//     {
//         if (currentNode == nullptr)
//         {
//             return nullptr;
//         }

//         Node *startNode = currentNode;

//         while (currentNode != nullptr && currentNode->data % 2 == 0)
//         {
//             Node *nextNode = currentNode->next;
//             currentNode->next = previousNode;
//             previousNode = currentNode;
//             currentNode = nextNode;
//         }

//         if (startNode != currentNode)
//         {
//             startNode->next = currentNode;
//             _reverse_even(currentNode, nullptr);
//             return previousNode;
//         }
//         else
//         {
//             startNode->next = _reverse_even(startNode->next, currentNode);
//             return startNode;
//         }
//     }
// };

// int main()
// {

//     LinkedList list;
//     list.add(3);
//     list.add(6);
//     list.add(2);
//     list.add(0);
//     list.add(3);
//     list.add(2);
//     list.add(5);

//     list.reverse_even();

//     list.display();

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// class Node
// {
// public:
//     int data;
//     Node *next;

//     Node(int data) : data(data), next(nullptr) {}
// };

// class LinkedList
// {
// public:
//     Node *head;

//     LinkedList() : head(nullptr) {}

//     void append(int data)
//     {
//         Node *newNode = new Node(data);
//         if (head == nullptr)
//         {
//             head = newNode;
//             return;
//         }

//         Node *currentNode = head;
//         while (currentNode->next != nullptr)
//         {
//             currentNode = currentNode->next;
//         }

//         currentNode->next = newNode;
//     }

//     void insert(int data)
//     {
//         Node *newNode = new Node(data);
//         newNode->next = head;
//         head = newNode;
//     }

//     void remove(int data)
//     {
//         Node *currentNode = head;
//         if (currentNode != nullptr && currentNode->data == data)
//         {
//             head = currentNode->next;
//             return;
//         }

//         Node *previousNode = nullptr;

//         while (currentNode != nullptr && currentNode->data != data)
//         {
//             previousNode = currentNode;
//             currentNode = currentNode->next;
//         }

//         if (currentNode == nullptr)
//             return;

//         previousNode->next = currentNode->next;
//         delete currentNode;
//     }

//     void reverse_iterative()
//     {
//         Node *currentNode = head;
//         Node *previousNode = nullptr;

//         while (currentNode != nullptr)
//         {

//             Node *nextNode = currentNode->next;

//             currentNode->next = previousNode;
//             previousNode = currentNode;
//             currentNode = nextNode;
//         }
//         head = previousNode;
//     }

//     void reverse_recursive()
//     {
//         head = _reverse_recursive(head, nullptr);
//     }

//     void reverse_even()
//     {
//         head = _reverse_even(head, nullptr);
//     }

//     void display()
//     {
//         Node *currentNode = head;
//         while (currentNode != nullptr)
//         {
//             cout << currentNode->data << " ";
//             currentNode = currentNode->next;
//         }
//     }

// private:
//     Node *_reverse_recursive(Node *currentNode, Node *previousNode)
//     {

//         if (currentNode == nullptr)
//         {
//             return previousNode;
//         }

//         Node *nextNode = currentNode->next;
//         currentNode->next = previousNode;

//         _reverse_recursive(nextNode, currentNode);
//     }

//     Node *_reverse_even(Node *currentNode, Node *previousNode)
//     {
//         Node *startNode = currentNode;
//         if (startNode == nullptr)
//             return nullptr;

//         while (currentNode != nullptr && currentNode->data % 2 == 0)
//         {
//             Node *nextNode = currentNode->next;
//             currentNode->next = previousNode;
//             previousNode = currentNode;
//             currentNode = nextNode;
//         }

//         if (startNode != currentNode)
//         {
//             startNode->next = currentNode;
//             _reverse_even(currentNode, nullptr);
//             return previousNode;
//         }
//         else
//         {
//             startNode->next = _reverse_even(currentNode->next, currentNode);
//             return startNode;
//         }
//     }
// };

// int main()
// {
//     LinkedList list;

//     list.append(2);
//     list.append(4);
//     list.append(6);
//     list.append(1);
//     list.append(2);
//     list.append(4);
//     list.append(6);
//     list.append(8);
//     list.append(3);
//     list.append(1);
//     list.append(2);
//     list.append(3);

//     list.reverse_even();

//     list.display();

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// class Node
// {
// public:
//     int data;
//     Node *next;

//     Node(int data) : data(data), next(nullptr) {}
// };

// class LinkedList
// {
// public:
//     Node *head;

//     LinkedList() : head(nullptr){};

//     void append(int data)
//     {

//         Node *currentNode = head;
//         Node *newNode = new Node(data);
//         if (head == nullptr)
//         {
//             head = newNode;
//         }
//         else
//         {
//             // nullptrは参照ではないので、nextがnullptrになるまで繰り返す
//             while (currentNode->next != nullptr)
//             {
//                 currentNode = currentNode->next;
//             }
//             currentNode->next = newNode;
//         }
//     }

//     void insert(int data)
//     {
//         Node *newNode = new Node(data);
//         newNode->next = head;
//         head = newNode;
//     }

//     void remove(int data)
//     {
//         Node *previousNode = nullptr;
//         Node *currentNode = head;

//         // 先頭要素をremoveするとき
//         if (currentNode != nullptr && currentNode->data == data)
//         {
//             head = currentNode->next;
//             delete currentNode;
//             return;
//         }

//         while (currentNode != nullptr)
//         {
//             if (currentNode->data == data)
//                 break;
//             previousNode = currentNode;
//             currentNode = currentNode->next;
//         }

//         // 探索した結果なかったまたは、headがnullの時
//         if (currentNode == nullptr)
//             return;

//         previousNode->next = currentNode->next;
//         delete currentNode;
//     }

//     void display()
//     {

//         Node *currentNode = head;
//         while (currentNode != nullptr)
//         {
//             cout << currentNode->data << " ";
//             currentNode = currentNode->next;
//         }
//     }

//     void reverse_iterative()
//     {
//         Node *previousNode = nullptr;
//         Node *currentNode = head;

//         while (currentNode != nullptr)
//         {
//             Node *nextNode = currentNode->next;
//             currentNode->next = previousNode;
//             previousNode = currentNode;
//             currentNode = nextNode;
//         }

//         head = previousNode;
//     }

//     void reverse_recursive()
//     {
//         head = _reverse_recursive(nullptr, head);
//     }

//     void reverse_even()
//     {
//         head = _reverse_even(nullptr, head);
//     }

// private:
//     Node *_reverse_recursive(Node *previousNode, Node *currentNode)
//     {
//         if (currentNode == nullptr)
//             return previousNode;

//         Node *nextNode = currentNode->next;
//         currentNode->next = previousNode;

//         _reverse_recursive(currentNode, nextNode);
//     }

//     Node *_reverse_even(Node *previousNode, Node *currentNode)
//     {

//         Node *startNode = currentNode;

//         if (currentNode == nullptr)
//             return nullptr;

//         while (startNode != nullptr && startNode->data % 2 == 0)
//         {
//             Node *nextNode = startNode->next;
//             startNode->next = previousNode;
//             previousNode = startNode;
//             startNode = nextNode;
//         }

//         if (startNode != currentNode)
//         {
//             // 偶数の最後を奇数の最初とつなげる　246→1
//             currentNode->next = startNode;
//             _reverse_even(nullptr, startNode);
//             return previousNode;
//         }
//         else
//         {
//             // 先頭が奇数だった時は返ってきたpreviousNodeを次のnodeにする
//             currentNode->next = _reverse_even(currentNode, currentNode->next);
//             return currentNode;
//         }
//     }
// };

// int main()
// {

//     LinkedList list;

//     list.append(6);
//     list.append(4);
//     list.append(2);
//     list.append(1);
//     list.append(6);
//     list.append(4);
//     list.append(2);

//     list.reverse_even();

//     list.display();
// }
