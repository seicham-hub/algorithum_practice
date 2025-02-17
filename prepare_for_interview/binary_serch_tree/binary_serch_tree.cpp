// 2024_04_11もう一度

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int value;
    Node *left;
    Node *right;

    Node(int value) : value(value){};
};

class BinarySearchTree
{
public:
    Node *root;

    BinarySearchTree() : root(nullptr){};

    void insert(int value)
    {
        function<void(int &, Node *&)> _insert = [&](int &value, Node *&node)
        {
            if (node == nullptr)
            {
                node = new Node(value);
                return;
            }

            if (value < node->value)
                _insert(value, node->left);
            else
                _insert(value, node->right);
        };

        _insert(value, root);
    }

    void inorder()
    {
        function<void(Node *)> _inorder = [&](Node *node)
        {
            if (node == nullptr)
                return;

            _inorder(node->left);
            cout << node->value << endl;
            _inorder(node->right);
        };

        _inorder(root);
    }

    bool search(int value)
    {
        function<bool(int &, Node *)> _search = [&](int &value, Node *node) -> bool
        {
            if (node == nullptr)
                return false;

            if (value == node->value)
                return true;
            else if (value < node->value)
                return _search(value, node->left);
            else
                return _search(value, node->right);
        };

        return _search(value, root);
    }

    int get_min_value(Node *node)
    {

        Node *current = node;
        while (current->left != nullptr)
        {
            current = current->left;
        }
        return current->value;
    }

    void remove(int value)
    {
        function<void(int &, Node *&)> _remove = [&](int &value, Node *&node)
        {
            if (node == nullptr)
                return;

            if (value < node->value)
                _remove(value, node->left);
            else if (value > node->value)
                _remove(value, node->right);
            else
            {
                if (node->right == nullptr)
                    node = node->left;
                else if (node->left == nullptr)
                    node = node->right;
                else
                {
                    int right_min_value = get_min_value(node->right);
                    _remove(right_min_value, node->right);
                    node->value = right_min_value;
                }
            }
        };
        _remove(value, root);
    }
};

int main()
{
    BinarySearchTree *tree = new BinarySearchTree();

    tree->insert(15);
    tree->insert(5);
    tree->insert(13);
    tree->insert(14);
    tree->insert(12);
    tree->insert(9);
    tree->insert(3);
    tree->insert(2);
    tree->insert(1);
    tree->insert(20);
    tree->insert(21);
    tree->inorder();

    tree->remove(20);
    cout << tree->search(1) << endl;

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// struct Node
// {
//     int value;
//     Node *left;
//     Node *right;

//     Node(int value) : value(value) {}
// };

// class BinarySearchTree
// {

// public:
//     Node *root;

//     BinarySearchTree() : root(nullptr){};

//     Node *insert(int value)
//     {

//         function<Node *(int, Node *)> _insert = [&](int value, Node *node) -> Node *
//         {
//             if (node == nullptr)
//             {
//                 return new Node(value);
//             }
//             if (value < node->value)
//                 node->left = _insert(value, node->left);
//             else
//                 node->right = _insert(value, node->right);
//             return node;
//         };

//         root = _insert(value, root);
//     }

//     void inorder()
//     {
//         function<void(Node *)> _inorder = [&](Node *node)
//         {
//             if (node == nullptr)
//                 return;

//             _inorder(node->left);
//             cout << node->value << endl;
//             _inorder(node->right);
//         };

//         _inorder(root);
//     }

//     bool search(int value)
//     {

//         function<bool(int &, Node *)> _search = [&](int &value, Node *node)
//         {
//             if (node == nullptr)
//                 return false;

//             if (value == node->value)
//                 return true;

//             if (value < node->value)
//                 return _search(value, node->left);
//             else
//                 return _search(value, node->right);
//         };

//         return _search(value, root);
//     }

//     int min_value(Node *node)
//     {
//         if (node == nullptr)
//             return 0;
//         Node *current = node;
//         while (current->left != nullptr)
//         {
//             current = current->left;
//         }

//         return current->value;
//     }

//     void test(int value)
//     {
//         function<void(int &, Node *)> _test = [&](int &value, Node *node)
//         {
//             node->value = value;
//         };

//         _test(value, root);
//     }

//     void remove_v1(int value)
//     {

//         function<void(int &, Node *&)> _remove = [&](int &value, Node *&node) -> void
//         {
//             if (node == nullptr)
//                 return;
//             if (value == node->value)
//             {
//                 if (node->right == nullptr)
//                     node = node->left;
//                 else if (node->left == nullptr)
//                     node = node->right;
//                 else
//                 {
//                     int right_min_value = min_value(node->right);
//                     _remove(right_min_value, node->right);
//                     node->value = right_min_value;
//                 }
//             }
//             else if (value < node->value)
//                 _remove(value, node->left);
//             else
//                 _remove(value, node->right);
//         };

//         _remove(value, root);
//     }
//     void remove_v2(int value)
//     {

//         function<Node *(int &, Node *)> _remove = [&](int &value, Node *node) -> Node *
//         {
//             if (node == nullptr)
//                 return nullptr;
//             if (value == node->value)
//             {
//                 if (node->right == nullptr)
//                     return node->left;
//                 else if (node->left == nullptr)
//                     return node->right;
//                 else
//                 {
//                     int right_min_value = min_value(node->right);
//                     node->right = _remove(right_min_value, node->right);
//                     node->value = right_min_value;
//                 }
//             }
//             else if (value < node->value)
//                 node->left = _remove(value, node->left);
//             else
//                 node->right = _remove(value, node->right);
//             return node;
//         };

//         _remove(value, root);
//     }
// };

// int main()
// {

//     BinarySearchTree *tree = new BinarySearchTree();

//     tree->insert(5);

//     tree->insert(3);
//     tree->insert(4);
//     tree->insert(2);
//     tree->insert(1);
//     tree->insert(6);
//     tree->insert(7);
//     tree->insert(8);
//     tree->inorder();
//     tree->remove_v2(2);

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// struct Node
// {
//     int value;
//     Node *left;
//     Node *right;

//     Node(int value) : value(value) {}
// };

// class BinaryTree
// {
// public:
//     Node *root;

//     BinaryTree() : root(nullptr){};

//     void insert(int value)
//     {

//         function<Node *(Node *, int)> _insert = [&_insert](Node *node, int value)
//         {
//             if (node == nullptr)
//             {
//                 return new Node(value);
//             }
//             if (value < node->value)
//             {
//                 node->left = _insert(node->left, value);
//             }
//             else if (value > node->value)
//             {
//                 node->right = _insert(node->right, value);
//             }

//             return node;
//         };

//         root = _insert(root, value);
//     }

//     void inorder()
//     {
//         function<void(Node *)> _inorder = [&_inorder](Node *node)
//         {
//             if (node == nullptr)
//                 return nullptr;

//             _inorder(node->left);
//             cout << node->value << endl;
//             _inorder(node->right);
//         };

//         _inorder(root);
//     }

//     bool search(int value)
//     {
//         function<bool(Node *, int)> _search = [&_search](Node *node, int value)
//         {
//             if (node == nullptr)
//                 return false;
//             if (value < node->value)
//                 return _search(node->left, value);
//             else if (value > node->value)
//                 return _search(node->right, value);
//             else
//                 return true;
//         };

//         return _search(root, value);
//     }

//     Node *min_value(Node *node)
//     {
//         Node *current = node;
//         while (current->left != nullptr)
//         {
//             current = current->left;
//         }
//         return current;
//     }

//     void remove(int value)
//     {
//         function<Node *(Node *, int)> _remove = [&](Node *node, int value)
//         {
//             if (node == nullptr)
//                 return node;
//             else if (value < node->value)
//                 node->left = _remove(node->left, value);
//             else if (value > node->value)
//                 node->right = _remove(node->right, value);
//             else
//             {
//                 if (node->left == nullptr)
//                 {
//                     Node *tmp = node->right;
//                     delete node;
//                     return tmp;
//                 }
//                 else if (node->right == nullptr)
//                 {
//                     Node *tmp = node->left;
//                     delete node;
//                     return tmp;
//                 }
//                 else
//                 {
//                     Node *min_node = min_value(node->right);
//                     node->value = min_node->value;
//                     node->right = _remove(node->right, min_node->value);
//                 }
//             }
//             return node;
//         };

//         root = _remove(root, value);
//     }
// };

// int main()
// {

//     BinaryTree *tree = new BinaryTree();

//     tree->insert(3);
//     tree->insert(4);
//     tree->insert(5);
//     tree->insert(11);
//     tree->insert(9);
//     tree->insert(8);
//     tree->insert(7);
//     tree->insert(18);
//     tree->insert(15);
//     tree->insert(13);
//     tree->insert(10);
//     tree->insert(2);
//     tree->insert(1);

//     tree->inorder();
//     cout << tree->search(4) << endl;

//     tree->remove(11);
//     tree->inorder();
// }

// #include <bits/stdc++.h>
// using namespace std;

// struct Node
// {
//     int value;
//     Node *left;
//     Node *right;

//     Node(int value) : value(value){};
// };

// class BinalySearchTree
// {
// public:
//     Node *root;

//     BinalySearchTree() : root(nullptr){};

//     void *insert(int value)
//     {

//         function<Node *(Node *, int)> _insert = [&_insert](Node *node, int value) -> Node *
//         {
//             if (node == nullptr)
//             {
//                 return new Node(value);
//             }
//             if (value < node->value)
//             {
//                 node->left = _insert(node->left, value);
//             }
//             else
//             {
//                 node->right = _insert(node->right, value);
//             }

//             return node;
//         };
//         if (root == nullptr)
//             root = new Node(value);
//         else
//             _insert(root, value);
//     }
//     void inorder()
//     {
//         function<void(Node *)> _inorder = [&_inorder](Node *node)
//         {
//             if (node == nullptr)
//                 return;
//             _inorder(node->left);
//             cout << node->value << endl;
//             _inorder(node->right);
//         };

//         _inorder(root);
//     }

//     bool search(int target)
//     {
//         function<bool(Node *, int)> _search = [&_search](Node *node, int target)
//         {
//             if (node == nullptr)
//                 return false;

//             if (target < node->value)
//                 return _search(node->left, target);
//             else if (target > node->value)
//                 return _search(node->right, target);
//             else
//                 return true;
//         };
//         return _search(root, target);
//     }

//     Node *min_value(Node *node)
//     {

//         while (node->left != nullptr)
//         {
//             node = node->left;
//         }
//         return node;
//     }

//     void *remove(int value)
//     {
//         function<Node *(Node *, int)> _remove = [&](Node *node, int value)
//         {
//             if (node == nullptr)
//                 return node;
//             else if (value < node->value)
//                 node->left = _remove(node->left, value);
//             else if (value > node->value)
//                 node->right = _remove(node->right, value);
//             else
//             {
//                 if (node->left == nullptr)
//                 {
//                     Node *tmp = node->right;
//                     delete node;
//                     return tmp;
//                 }
//                 else if (node->right == nullptr)
//                 {
//                     Node *tmp = node->left;
//                     delete node;
//                     return tmp;
//                 }
//                 else
//                 {
//                     Node *tmp = min_value(node->right);
//                     node->value = tmp->value;
//                     node->right = _remove(node->right, tmp->value);
//                 }
//             }
//             return node;
//         };
//         _remove(root, value);
//     }
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
//     if (node == nullptr)
//         return;
//     inorder(node->left);
//     cout << node->value << endl;
//     inorder(node->right);
// }

// bool search(Node *node, int target)
// {
//     if (node == nullptr)
//         return false;

//     if (target < node->value)
//         return search(node->left, target);
//     else if (target > node->value)
//         return search(node->right, target);
//     else
//         return true;
// }

// Node *min_value(Node *node)
// {

//     while (node->left != nullptr)
//     {
//         node = node->left;
//     }
//     return node;
// }

// Node *remove(Node *node, int value)
// {

//     if (node == nullptr)
//         return node;
//     else if (value < node->value)
//         node->left = remove(node->left, value);
//     else if (value > node->value)
//         node->right = remove(node->right, value);
//     else
//     {
//         if (node->left == nullptr)
//         {
//             Node *tmp = node->right;
//             delete node;
//             return tmp;
//         }
//         else if (node->right == nullptr)
//         {
//             Node *tmp = node->left;
//             delete node;
//             return tmp;
//         }
//         else
//         {
//             Node *tmp = min_value(node->right);
//             node->value = tmp->value;
//             node->right = remove(node->right, tmp->value);
//         }
//     }
//     return node;
// }

// int main()
// {
//     BinalySearchTree *tree = new BinalySearchTree();
//     tree->insert(3);
//     tree->insert(6);
//     tree->insert(5);
//     tree->insert(7);
//     tree->insert(1);
//     tree->insert(10);
//     tree->insert(2);

//     tree->remove(6);
//     tree->inorder();

//     cout << tree->search(10) << endl;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// struct Node
// {
//     int value;
//     Node *left;
//     Node *right;

//     Node(int value) : value(value){};
// };

// Node *insert(Node *node, int value)
// {

//     if (node == nullptr)
//     {
//         return new Node(value);
//     }

//     if (value < node->value)
//         node->left = insert(node->left, value);
//     else
//         node->right = insert(node->right, value);

//     return node;
// }

// void inorder(Node *node)
// {

//     if (node != nullptr)
//     {
//         inorder(node->left);
//         cout << node->value << endl;
//         inorder(node->right);
//     }
// }

// bool search(Node *node, int target)
// {
//     if (node == nullptr)
//         return false;

//     if (node->value == target)
//         return true;
//     else if (target < node->value)
//         search(node->left, target);
//     else
//         search(node->right, target);
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
//     {
//         return node;
//     }
//     if (value < node->value)
//     {
//         node->left = remove(node->left, value);
//     }
//     else if (value > node->value)
//     {
//         node->right = remove(node->right, value);
//     }
//     else
//     {
//         if (node->left == nullptr)
//         {
//             Node *temp = node->right;
//             delete node;
//             return temp;
//         }
//         else if (node->right == nullptr)
//         {
//             Node *temp = node->left;
//             delete node;
//             return temp;
//         }

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
//     root = insert(root, 4);
//     root = insert(root, 5);
//     root = insert(root, 2);

//     cout << search(root, 10) << endl;
//     root = remove(root, 4);

//     // inorder(root);

//     return 0;
// }

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