#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data) : data(data), next(nullptr), prev(nullptr){};
};

class DublyLinkedList
{
public:
    Node *head;

    DublyLinkedList() : head(nullptr){};

    void append(int data)
    {

        Node *newNode = new Node(data);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }

        Node *currentNode = head;

        while (currentNode->next != nullptr)
        {
            currentNode = currentNode->next;
        }

        currentNode->next = newNode;
        newNode->prev = currentNode;
    }
};

int main()
{

    DublyLinkedList list;
    list.append(2);
    list.append(3);

    cout << list.head->data << endl;
    cout << list.head->next->data << endl;
    return 0;
}