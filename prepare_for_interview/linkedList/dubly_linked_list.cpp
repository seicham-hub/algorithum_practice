#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

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

        while (currentNode != nullptr)
        {
            Node *startNode = currentNode;
            while (startNode->next != nullptr)
            {
                Node *nextNode = startNode->next;
                if (startNode->data > nextNode->data)
                {
                    int tmpData = startNode->data;
                    startNode->data = nextNode->data;
                    nextNode->data = tmpData;
                }
                startNode = startNode->next;
            }
            currentNode = currentNode->next;
        }
    }

    // void sort()
    // {
    //     if (head == nullptr)
    //         return;

    //     Node *currentNode = head;
    //     while (currentNode->next != nullptr)
    //     {
    //         Node *nextNode = currentNode->next;

    //         while (nextNode != nullptr)
    //         {
    //             if (currentNode->data > nextNode->data)
    //             {
    //                 int currentData = currentNode->data;
    //                 currentNode->data = nextNode->data;
    //                 nextNode->data = currentData;
    //             }
    //             nextNode = nextNode->next;
    //         }
    //         currentNode = currentNode->next;
    //     }
    // }

private:
    // もう一度
    Node *_reverse_recursive(Node *currentNode)
    {
        // headがnullの時
        if (currentNode == nullptr)
            return currentNode;

        Node *previousNode = currentNode->prev;
        currentNode->prev = currentNode->next;
        currentNode->next = previousNode;

        if (currentNode->prev == nullptr)
            return currentNode;

        return _reverse_recursive(currentNode->prev);
    }
};

int main()
{

    DublyLinkedList list;
    list.append(2);
    list.append(1);
    list.append(0);
    list.append(3);

    list.sort();
    list.reverse_recursive();

    list.display();

    return 0;
}