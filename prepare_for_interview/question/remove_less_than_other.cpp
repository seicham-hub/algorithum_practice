// vector<int> a = {1, 2, 3, 4, 4, 5, 5, 8, 10};
// vector<int> b = {4, 5, 5, 5, 6, 7, 8, 8, 10};

// 同じ数字が含まれるとき、個数が少ない方は削除する
// 10 8 8 7 6 5 5 5
// 10 4 4 3 2

#include <bits/stdc++.h>
using namespace std;

void remove_duplicate_less_element(vector<int> &a, vector<int> &b)
{

    unordered_map<int, int> a_count, b_count;
    unordered_map<int, bool> a_remove, b_remove;

    for (int j = 0; j < 2; j++)
    {
        for (int i = 0; i < a.size(); i++)
            a_count[a[i]]++;

        swap(a, b);
        swap(a_count, b_count);
    }

    for (auto amp : a_count)
    {
        int duplicate_num = amp.first;

        if (b_count[duplicate_num])
        {
            if (amp.second > b_count[duplicate_num])
                b_remove[duplicate_num] = true;
            else if (amp.second < b_count[duplicate_num])
                a_remove[duplicate_num] = true;
        }
    }

    for (int i = 0; i < 2; i++)
    {
        for (auto remove : a_remove)
        {
            int i = 0;
            while (i < a.size())
                if (a[i] == remove.first)
                    a.erase(a.begin() + i);
                else
                    i++;
        }

        swap(a_remove, b_remove);
        swap(a, b);
    }
}

int main()
{
    vector<int> a = {1, 2, 3, 4, 4, 5, 5, 8, 10};
    vector<int> b = {4, 5, 5, 5, 6, 7, 8, 8, 10};

    remove_duplicate_less_element(a, b);

    for (int i = 0; i < 2; i++)
    {
        for (auto num : a)
            cout << num << " ";

        cout << endl;
        swap(a, b);
    }
}

// #include <bits/stdc++.h>
// using namespace std;

// vector<int> create_ans(unordered_map<int, int> &current, unordered_map<int, int> &other)
// {
//     vector<int> ans;
//     for (auto n : current)
//     {
//         int num = n.first;
//         int count = n.second;
//         if (count >= other[num])
//         {

//             for (int i = 0; i < count; i++)
//                 ans.push_back(num);
//         }
//     }

//     return ans;
// }

// int main()
// {

//     vector<int> a = {1, 2, 3, 4, 4, 5, 5, 8, 10};
//     vector<int> b = {4, 5, 5, 5, 6, 7, 8, 8, 10};

//     unordered_map<int, int> num_count_a, num_count_b;

//     for (int k = 0; k < 2; k++)
//     {
//         for (int i = 0; i < a.size(); i++)
//         {
//             num_count_a[a[i]]++;
//         }
//         swap(num_count_a, num_count_b);
//         swap(a, b);
//     }
//     swap(num_count_a, num_count_b);
//     swap(a, b);

//     vector<int> ans_a = create_ans(num_count_a, num_count_b);
//     vector<int> ans_b = create_ans(num_count_b, num_count_a);

//     return 0;
// }