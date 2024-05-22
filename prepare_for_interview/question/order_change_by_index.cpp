// Input: {'h','y','n','p','t','o'},{3,1,5,0,2,4}
// Output: python

// charの配列自体を並び替えて実装する場合は？

#include <bits/stdc++.h>
using namespace std;

void order_chars(vector<char> &str, vector<int> &indices)
{
    for (int i = 0; i < indices.size(); i++)
    {
        while (i != indices[i])
        {
            int correct_index = indices[i];

            swap(str[i], str[correct_index]);
            swap(indices[i], indices[correct_index]);
        }
    }
}

int main()
{

    vector<char> str = {'h', 'y', 'n', 'p', 't', 'o'};
    vector<int> indices = {3, 1, 5, 0, 2, 4};

    order_chars(str, indices);

    for (char c : str)
    {
        cout << c;
    }

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// void order_chars(vector<char> &str, vector<int> &indices)
// {

//     for (int i = 0; i < indices.size(); i++)
//     {

//         int now_index = i;
//         int correct_index = indices[i];

//         while (now_index != correct_index)
//         {
//             swap(str[now_index], str[correct_index]);
//             swap(indices[now_index], indices[correct_index]);

//             correct_index = indices[i];
//         }
//     }
// }

// int main()
// {
//     vector<char> str = {'h', 'y', 'n', 'p', 't', 'o'};
//     vector<int> indices = {3, 1, 5, 0, 2, 4};

//     order_chars(str, indices);

//     for (char c : str)
//     {
//         cout << c;
//     }
//     return 0;
// }