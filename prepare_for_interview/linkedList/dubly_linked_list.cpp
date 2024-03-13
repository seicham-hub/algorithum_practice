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

    void insert(int data)
    {
        Node *newNode = new Node(data);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }

    void remove(int data)
    {

        Node *currentNode = head;

        // 一番最初のノードを削除
        if (currentNode != nullptr && currentNode->data == data)
        {
            if (currentNode->next == nullptr)
            {
                delete currentNode;
                head = nullptr;
                return;
            }
            else
            {
                Node *nextNode = currentNode->next;
                nextNode->prev = nullptr;
                delete currentNode;
                head = nextNode;
                return;
            }
        }

        while (currentNode != nullptr && currentNode->data != data)
        {
            currentNode = currentNode->next;
        }

        if (currentNode == nullptr)
            return;

        if (currentNode->next == nullptr)
        {
            Node *prev = currentNode->prev;
            prev->next = nullptr;
            return;
        }
        else
        {
            Node *nextNode = currentNode->next;
            Node *prevNode = currentNode->prev;
            prevNode->next = nextNode;
            nextNode->prev = prevNode;
            delete currentNode;
            return;
        }
    }

    void display()
    {
        Node *currentNode = head;
        while (currentNode != nullptr)
        {
            cout << currentNode->data << " ";
            currentNode = currentNode->next;
        }
    }

    void reverse_iterative()
    {

        Node *currentNode = head;
        Node *previousNode = nullptr;
        while (currentNode != nullptr)
        {
            if (previousNode != nullptr)
            {
                Node *nextNode = currentNode->next;
                currentNode->next = previousNode;
                previousNode->prev = currentNode;
                previousNode = currentNode;
                currentNode = nextNode;
            }
            else
            {
                Node *nextNode = currentNode->next;
                currentNode->next = previousNode;
                previousNode = currentNode;
                currentNode = nextNode;
            }
        }

        if (previousNode != nullptr)
        {
            previousNode->prev = nullptr;
            head = previousNode;
        }
    }
};

int main()
{

    DublyLinkedList list;
    list.append(0);
    list.append(1);
    list.append(2);
    list.append(3);

    list.reverse_iterative();

    list.display();

    return 0;
}