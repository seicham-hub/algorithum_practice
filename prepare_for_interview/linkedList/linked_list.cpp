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
            return;
        }

        // nullptrは参照ではないので、nextがnullptrになるまで繰り返す
        while (currentNode->next != nullptr)
        {
            currentNode = currentNode->next;
        }
        currentNode->next = newNode;
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

        while (currentNode != nullptr)
        {
            if (currentNode->data == data)
                break;
            previousNode = currentNode;
            currentNode = currentNode->next;
        }

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

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// class Node
// {
// public:
//     int data;
//     Node *next;

//     Node(int data) : data(data),next(nullptr) {}
// };

// class LinkedList
// {

// public:
//     Node *head;

//     LinkedList() : head(nullptr){};

//     void append(int data)
//     {
//         Node *newNode = new Node(data);
//         Node *lastNode = head;

//         if (head == nullptr)
//         {
//             head = newNode;
//             return;
//         }
//         while (lastNode->next != nullptr)
//         {
//             lastNode = lastNode->next;
//         }

//         lastNode->next = newNode;
//     }

//     // 先頭に追加
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

//         // 先頭を削除する場合
//         if (currentNode != nullptr && currentNode->data == data)
//         {
//             head = currentNode->next;
//             delete currentNode;
//             return;
//         }

//         // 2番目以降を削除する場合
//         while (currentNode != nullptr && currentNode->data != data)
//         {
//             previousNode = currentNode;
//             currentNode = currentNode->next;
//         }

//         // headがnullの場合と、削除するものが見つからなかった場合
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
//             // nextが判定しているものをpreviousに入れていく
//             previousNode = currentNode;
//             currentNode = nextNode;
//         }

//         head = previousNode;
//     }

//     void reverse_even()
//     {
//         head = _reverse_even(head, nullptr);
//     }

// private:
//     Node *_reverse_even(Node *head, Node *previousNode)
//     {
//         if (head == nullptr)
//             return nullptr;

//         Node *currentNode = head;

//         // 2,4,6
//         while (currentNode != nullptr && currentNode->data % 2 == 0)
//         {
//             Node *nextNode = currentNode->next;
//             currentNode->next = previousNode;
//             previousNode = currentNode;
//             currentNode = nextNode;
//         }

//         if (currentNode != head)
//         {
//             head->next = currentNode;
//             // 残りも同じように偶数が連続する場合を処理
//             _reverse_even(currentNode, nullptr);
//             return previousNode;
//         }
//         // 奇数で終わるとき
//         else
//         {
//             head->next = _reverse_even(head->next, head);
//             return head;
//         }
//     }
// };

// int main()
// {
//     LinkedList list;

//     list.append(5);
//     list.append(2);
//     list.append(9);
//     list.append(4);
//     list.append(6);
//     list.append(1);
//     list.append(2);
//     list.append(4);
//     list.append(6);

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
//         Node *currentNode = head;
//         newNode->next = currentNode;
//         head = newNode;
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

//     void reverse_recursive(Node *previousNode, Node *currentNode)
//     {

//         if (currentNode == nullptr)
//         {
//             head = previousNode;
//             return;
//         }

//         Node *nextNode = currentNode->next;

//         currentNode->next = previousNode;

//         reverse_recursive(currentNode, nextNode);
//     }
// };

// int main()
// {
//     LinkedList list;

//     list.append(1);
//     list.insert(0);

//     // cout << list.head->data << endl;
//     // cout << list.head->next->data << endl;
//     list.display();
//     list.reverse_iterative();
//     list.display();
//     list.reverse_recursive(nullptr, list.head);
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