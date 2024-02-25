// 毎日課題
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

class Node
{
public:
    int data;
    Node *next;

    Node(int data) : data(data), next(nullptr) {}
};

class LinkedList
{
public:
    Node *head;

    LinkedList() : head(nullptr){};

    void append(int data)
    {
        Node *currentNode = head;
        Node *newNode = new Node(data);

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
    void insert(int data)
    {
        Node *newNode = new Node(data);
        Node *currentNode = head;
        newNode->next = currentNode;
        head = newNode;
    }

    void display()
    {
        Node *currentNode = head;
        while (currentNode != nullptr)
        {
            cout << currentNode->data << endl;
            currentNode = currentNode->next;
        }
    }

    void reverse_iterative()
    {
        Node *previousNode = nullptr;
        Node *currentNode = head;
        while (currentNode != nullptr)
        {
            Node *nextNode = currentNode->next;
            currentNode->next = previousNode;

            previousNode = currentNode;
            currentNode = nextNode;
        }
        head = previousNode;
    }

    void reverse_recursive(Node *previousNode, Node *currentNode)
    {

        if (currentNode == nullptr)
        {
            head = previousNode;
            return;
        }

        Node *nextNode = currentNode->next;

        currentNode->next = previousNode;

        reverse_recursive(currentNode, nextNode);
    }
};

int main()
{
    LinkedList list;

    list.append(1);
    list.insert(0);

    // cout << list.head->data << endl;
    // cout << list.head->next->data << endl;
    list.display();
    list.reverse_iterative();
    list.display();
    list.reverse_recursive(nullptr, list.head);
    list.display();

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// class Node
// {
// public:
//     int data;
//     Node *next;

//     // コンストラクタ
//     Node(int data) : data(data), next(nullptr) {}
// };

// class LinkedList
// {
// public:
//     Node *head;
//     LinkedList() : head(nullptr){};

//     void append(int data)
//     {
//         Node *newNode = new Node(data);
//         if (head == nullptr)
//         {
//             head = newNode;
//         }
//         else
//         {
//             Node *lastNode = head;
//             while (lastNode->next != nullptr)
//             {
//                 lastNode = lastNode->next;
//             }
//             lastNode->next = newNode;
//         }
//     }

//     void insert(int data)
//     {
//         Node *newNode = new Node(data);
//         newNode->next = head;
//         head = newNode;
//     }

//     void display()
//     {
//         Node *current = head;
//         while (current != nullptr)
//         {
//             cout << current->data << endl;
//             current = current->next;
//         }
//     }

//     void remove(int data)
//     {
//         Node *currentNode = head;
//         if (currentNode != nullptr && currentNode->data == data)
//         {
//             head = currentNode->next;
//             delete currentNode;
//             return;
//         }
//         Node *previousNode;

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
// };

// int main()
// {
//     LinkedList list;
//     list.append(1);
//     list.append(2);
//     list.append(3);
//     list.append(3);
//     list.insert(0);

//     list.display();

//     list.remove(3);

//     list.display();

//     // cout << list.head->data << endl;
//     // cout << list.head->next->data << endl;
//     // cout << list.head->next->next->data << endl;
//     // cout << list.head->next->next->next->data << endl;

//     return 0;
// }