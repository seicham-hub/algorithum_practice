#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

class Node
{
public:
    int value;
    Node *prev;
    Node *next;

    Node(int value) : value(value){};
};

class DublyLinkedList
{
public:
    Node *head;

    DublyLinkedList() : head(nullptr){};

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
        newNode->prev = currentNode;
    }
    void insert(int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }

        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void remove(int value)
    {
        Node *currentNode = head;

        if (currentNode != nullptr && currentNode->value == value)
        {
            if (currentNode->next == nullptr)
            {
                head = nullptr;
                delete currentNode;
                return;
            }
            else
            {
                Node *nextNode = currentNode->next;
                head = nextNode;
                nextNode->prev = nullptr;
                delete currentNode;
                return;
            }
        }

        while (currentNode != nullptr && currentNode->value != value)
        {
            currentNode = currentNode->next;
        }

        if (currentNode == nullptr)
            return;

        if (currentNode->next == nullptr)
        {
            Node *prevNode = currentNode->prev;
            prevNode->next = nullptr;
            delete currentNode;
        }
        else
        {
            Node *prevNode = currentNode->prev;
            Node *nextNode = currentNode->next;
            prevNode->next = nextNode;
            nextNode->prev = prevNode;
            delete currentNode;
        }
    }

    void reverse_iterative()
    {
        Node *previousNode = nullptr;
        Node *currentNode = head;

        while (currentNode != nullptr)
        {
            previousNode = currentNode->prev;
            currentNode->prev = currentNode->next;
            currentNode->next = previousNode;

            currentNode = currentNode->prev;
        }

        if (previousNode != nullptr)
            head = previousNode->prev;
    }

    void reverse_recursive()
    {
        head = _reverse_recursive(head);
    }

    void sort()
    {

        Node *currentNode = head;

        while (currentNode->next != nullptr)
        {
            Node *startNode = currentNode->next;
            while (startNode != nullptr)
            {
                if (currentNode->value > startNode->value)
                {
                    int tmp_value = currentNode->value;
                    currentNode->value = startNode->value;
                    startNode->value = tmp_value;
                }
                startNode = startNode->next;
            }
            currentNode = currentNode->next;
        }
    }

private:
    Node *_reverse_recursive(Node *currentNode)
    {
        if (currentNode == nullptr)
            return nullptr;

        Node *previousNode = currentNode->prev;
        currentNode->prev = currentNode->next;
        currentNode->next = previousNode;

        if (currentNode->prev == nullptr)
        {
            return currentNode;
        }

        return _reverse_recursive(currentNode->prev);
    }
};

int main()
{
    DublyLinkedList list;
    list.add(3);
    list.insert(2);
    list.insert(1);

    list.reverse_recursive();
    list.sort();

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; i++)

// class Node
// {
// public:
//     int value;
//     Node *next;
//     Node *prev;

//     Node(int value) : value(value){};
// };

// class DublyLinkedList
// {
// public:
//     Node *head;

//     DublyLinkedList() : head(nullptr){};

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
//         newNode->prev = currentNode;
//     }

//     void insert(int value)
//     {
//         Node *currentNode = head;
//         Node *newNode = new Node(value);

//         if (currentNode == nullptr)
//         {
//             head = newNode;
//             return;
//         }
//         newNode->next = head;
//         head->prev = newNode;
//         head = newNode;
//     }

//     void remove(int value)
//     {
//         Node *currentNode = head;

//         if (currentNode != nullptr && currentNode->value == value)
//         {
//             if (currentNode->next == nullptr)
//             {
//                 head = nullptr;
//                 delete currentNode;
//                 return;
//             }
//             else
//             {
//                 Node *nextNode = currentNode->next;
//                 nextNode->prev = nullptr;
//                 head = nextNode;
//                 delete currentNode;
//                 return;
//             }
//         }

//         while (currentNode != nullptr && currentNode->value != value)
//         {
//             currentNode = currentNode->next;
//         }

//         if (currentNode == nullptr)
//             return;

//         Node *prevNode = currentNode->prev;
//         Node *nextNode = currentNode->next;

//         if (nextNode != nullptr)
//         {
//             prevNode->next = nextNode;
//             nextNode->prev = prevNode;
//             delete currentNode;
//         }
//         else
//         {
//             prevNode->next = nullptr;
//             delete currentNode;
//         }
//     }

//     void reverse_iterative()
//     {

//         Node *previousNode = nullptr;
//         Node *currentNode = head;

//         while (currentNode != nullptr)
//         {
//             previousNode = currentNode->prev;

//             currentNode->prev = currentNode->next;
//             currentNode->next = previousNode;
//             currentNode = currentNode->prev;
//         }

//         if (previousNode != nullptr)
//             head = previousNode->prev;
//     }
//     void reverse_recursive()
//     {
//         head = _reverse_recursive(head);
//     }

//     void sort()
//     {
//         Node *startNode = head;
//         while (startNode->next != nullptr)
//         {
//             Node *currentNode = startNode->next;
//             while (currentNode != nullptr)
//             {
//                 if (startNode->value > currentNode->value)
//                 {
//                     int bigger_value = startNode->value;
//                     startNode->value = currentNode->value;
//                     currentNode->value = bigger_value;
//                 }
//                 currentNode = currentNode->next;
//             }
//             startNode = startNode->next;
//         }
//     }

// private:
//     Node *_reverse_recursive(Node *currentNode)
//     {
//         if (currentNode == nullptr)
//             return currentNode;

//         Node *prevNode = currentNode->prev;
//         currentNode->prev = currentNode->next;
//         currentNode->next = prevNode;

//         if (currentNode->prev == nullptr)
//             return currentNode;

//         return _reverse_recursive(currentNode->prev);
//     }
// };

// int main()
// {
//     DublyLinkedList list;

//     list.add(3);
//     list.add(4);
//     list.add(5);
//     list.insert(2);

//     list.reverse_recursive();

//     list.sort();

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; i++)

// class Node
// {
// public:
//     int data;
//     Node *next;
//     Node *prev;

//     Node(int data) : data(data), next(nullptr), prev(nullptr){};
// };

// class DublyLinkedList

// {
// public:
//     Node *head;

//     DublyLinkedList() : head(nullptr){};

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
//         newNode->prev = currentNode;
//     }

//     void insert(int data)
//     {
//         Node *newNode = new Node(data);
//         if (head == nullptr)
//         {
//             head = newNode;
//             return;
//         }
//         head->prev = newNode;
//         newNode->next = head;
//         head = newNode;
//     }

//     void remove(int data)
//     {

//         Node *currentNode = head;

//         // 一番最初のノードを削除
//         if (currentNode != nullptr && currentNode->data == data)
//         {
//             if (currentNode->next == nullptr)
//             {
//                 delete currentNode;
//                 head = nullptr;
//                 return;
//             }
//             else
//             {
//                 Node *nextNode = currentNode->next;
//                 nextNode->prev = nullptr;
//                 delete currentNode;
//                 head = nextNode;
//                 return;
//             }
//         }

//         while (currentNode != nullptr && currentNode->data != data)
//         {
//             currentNode = currentNode->next;
//         }

//         if (currentNode == nullptr)
//             return;

//         if (currentNode->next == nullptr)
//         {
//             Node *prev = currentNode->prev;
//             prev->next = nullptr;
//             return;
//         }
//         else
//         {
//             Node *nextNode = currentNode->next;
//             Node *prevNode = currentNode->prev;
//             prevNode->next = nextNode;
//             nextNode->prev = prevNode;
//             delete currentNode;
//             return;
//         }
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
//             previousNode = currentNode->prev;
//             currentNode->prev = currentNode->next;
//             currentNode->next = previousNode;

//             currentNode = currentNode->prev;
//         }

//         if (previousNode != nullptr)
//             head = previousNode->prev;
//     }

//     void reverse_recursive()
//     {
//         head = _reverse_recursive(head);
//     }

//     void sort()
//     {
//         Node *currentNode = head;

//         while (currentNode != nullptr)
//         {
//             Node *nextNode = currentNode;
//             while (nextNode != nullptr)
//             {
//                 // Node *nextNode = startNode->next;
//                 if (currentNode->data > nextNode->data)
//                 {
//                     int tmpData = currentNode->data;
//                     currentNode->data = nextNode->data;
//                     nextNode->data = tmpData;
//                 }
//                 nextNode = nextNode->next;
//             }
//             currentNode = currentNode->next;
//         }
//     }

//     // void sort()
//     // {
//     //     if (head == nullptr)
//     //         return;

//     //     Node *currentNode = head;
//     //     while (currentNode->next != nullptr)
//     //     {
//     //         Node *nextNode = currentNode->next;

//     //         while (nextNode != nullptr)
//     //         {
//     //             if (currentNode->data > nextNode->data)
//     //             {
//     //                 int currentData = currentNode->data;
//     //                 currentNode->data = nextNode->data;
//     //                 nextNode->data = currentData;
//     //             }
//     //             nextNode = nextNode->next;
//     //         }
//     //         currentNode = currentNode->next;
//     //     }
//     // }

// private:
//     // もう一度
//     Node *_reverse_recursive(Node *currentNode)
//     {
//         // headがnullの時
//         if (currentNode == nullptr)
//             return currentNode;

//         Node *previousNode = currentNode->prev;
//         currentNode->prev = currentNode->next;
//         currentNode->next = previousNode;

//         if (currentNode->prev == nullptr)
//             return currentNode;

//         return _reverse_recursive(currentNode->prev);
//     }
// };

// int main()
// {

//     DublyLinkedList list;
//     list.append(13);
//     list.append(21);
//     list.append(19);
//     list.append(4);

//     list.sort();
//     // list.reverse_recursive();

//     list.display();

//     return 0;
// }