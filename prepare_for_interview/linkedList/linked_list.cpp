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
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            // nullptrは参照ではないので、nextがnullptrになるまで繰り返す
            while (currentNode->next != nullptr)
            {
                currentNode = currentNode->next;
            }
            currentNode->next = newNode;
        }
    }

    void insert(int data)
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    void remove(int data)
    {
        Node *previousNode = nullptr;
        Node *currentNode = head;

        // 先頭要素をremoveするとき
        if (currentNode != nullptr && currentNode->data == data)
        {
            head = currentNode->next;
            delete currentNode;
            return;
        }

        while (currentNode != nullptr)
        {
            if (currentNode->data == data)
                break;
            previousNode = currentNode;
            currentNode = currentNode->next;
        }

        // 探索した結果なかったまたは、headがnullの時
        if (currentNode == nullptr)
            return;

        previousNode->next = currentNode->next;
        delete currentNode;
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
            Node *nextNode = currentNode->next;
            currentNode->next = previousNode;
            previousNode = currentNode;
            currentNode = nextNode;
        }

        head = previousNode;
    }

    void reverse_recursive()
    {
        head = _reverse_recursive(nullptr, head);
    }

    void reverse_even()
    {
        head = _reverse_even(nullptr, head);
    }

private:
    Node *_reverse_recursive(Node *previousNode, Node *currentNode)
    {
        if (currentNode == nullptr)
            return previousNode;

        Node *nextNode = currentNode->next;
        currentNode->next = previousNode;

        _reverse_recursive(currentNode, nextNode);
    }

    Node *_reverse_even(Node *previousNode, Node *currentNode)
    {

        Node *startNode = currentNode;

        if (currentNode == nullptr)
            return nullptr;

        while (startNode != nullptr && startNode->data % 2 == 0)
        {
            Node *nextNode = startNode->next;
            startNode->next = previousNode;
            previousNode = startNode;
            startNode = nextNode;
        }

        if (startNode != currentNode)
        {
            // 偶数の最後を奇数の最初とつなげる　246→1
            currentNode->next = startNode;
            _reverse_even(nullptr, startNode);
            return previousNode;
        }
        else
        {
            // 先頭が奇数だった時は返ってきたpreviousNodeを次のnodeにする
            currentNode->next = _reverse_even(currentNode, currentNode->next);
            return currentNode;
        }
    }
};

int main()
{

    LinkedList list;

    list.append(6);
    list.append(4);
    list.append(2);
    list.append(1);
    list.append(6);
    list.append(4);
    list.append(2);

    list.reverse_even();

    list.display();
}
