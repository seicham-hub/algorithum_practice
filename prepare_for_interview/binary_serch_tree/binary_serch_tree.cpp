#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int value;
    Node *left;
    Node *right;

    Node(int value) : value(value){};
};

Node *insert(Node *node, int value)
{

    if (node == nullptr)
    {
        return new Node(value);
    }

    if (value < node->value)
        node->left = insert(node->left, value);
    else
        node->right = insert(node->right, value);

    return node;
}

void inorder(Node *node)
{

    if (node != nullptr)
    {
        inorder(node->left);
        cout << node->value << endl;
        inorder(node->right);
    }
}

bool search(Node *node, int target)
{
    if (node == nullptr)
        return false;

    if (node->value == target)
        return true;
    else if (target < node->value)
        search(node->left, target);
    else
        search(node->right, target);
}

Node *min_value(Node *node)
{
    Node *current = node;
    while (current->left != nullptr)
    {
        current = current->left;
    }
    return current;
}

Node *remove(Node *node, int value)
{
    if (node == nullptr)
    {
        return node;
    }
    if (value < node->value)
    {
        node->left = remove(node->left, value);
    }
    else if (value > node->value)
    {
        node->right = remove(node->right, value);
    }
    else
    {
        if (node->left == nullptr)
        {
            Node *temp = node->right;
            delete node;
            return temp;
        }
        else if (node->right == nullptr)
        {
            Node *temp = node->left;
            delete node;
            return temp;
        }

        Node *temp = min_value(node->right);
        node->value = temp->value;
        node->right = remove(node->right, temp->value);
    }
    return node;
}

int main()
{

    Node *root = nullptr;

    root = insert(root, 3);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 2);

    cout << search(root, 10) << endl;
    root = remove(root, 4);

    // inorder(root);

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// struct Node
// {
//     int value;
//     Node *left;
//     Node *right;

//     Node(int value) : value(value), left(nullptr), right(nullptr) {}
// };

// Node *insert(Node *node, int value)
// {

//     if (node == nullptr)
//     {
//         return new Node(value);
//     }

//     if (value < node->value)
//     {
//         node->left = insert(node->left, value);
//     }
//     else
//     {
//         node->right = insert(node->right, value);
//     }
//     return node;
// }

// void inorder(Node *node)
// {
//     // Inorder Left, Root , Right
//     // Preorder: Root, Left, Right
//     // Postorder: Left,Right,Root
//     if (node != nullptr)
//     {
//         inorder(node->left);
//         cout << node->value << endl;
//         inorder(node->right);
//     }
// }

// bool search(Node *node, int value)
// {
//     if (node == nullptr)
//     {
//         return false;
//     }

//     if (node->value == value)
//         return true;
//     else if (value < node->value)
//         return search(node->left, value);
//     else if (node->value < value)
//         return search(node->right, value);
// }

// Node *min_value(Node *node)
// {
//     Node *current = node;

//     while (current->left != nullptr)
//     {
//         current = current->left;
//     }

//     return current;
// }

// Node *remove(Node *node, int value)
// {
//     if (node == nullptr)
//         return node;
//     else if (value < node->value)
//         node->left = remove(node->left, value);
//     else if (node->value < value)
//         node->right = remove(node->right, value);
//     else
//     {
//         if (node->left == nullptr)
//             return node->right;
//         else if (node->right == nullptr)
//             return node->left;
//         Node *temp = min_value(node->right);
//         node->value = temp->value;
//         node->right = remove(node->right, temp->value);
//     }

//     return node;
// }

// int main()
// {
//     Node *root = nullptr;

//     root = insert(root, 3);
//     root = insert(root, 6);
//     root = insert(root, 5);
//     root = insert(root, 7);
//     root = insert(root, 1);
//     root = insert(root, 2);
//     root = insert(root, 10);
//     root = remove(root, 6);

//     cout << search(root, 8) << endl;

//     return 0;
// }