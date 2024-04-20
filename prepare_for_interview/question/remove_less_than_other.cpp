// vector<int> a = {1, 2, 3, 4, 4, 5, 5, 8, 10};
// vector<int> b = {4, 5, 5, 5, 6, 7, 8, 8, 10};

// 同じ数時が含まれるとき、個数が少ない方は削除する
//

#include <bits/stdc++.h>
using namespace std;

vector<int> create_ans(unordered_map<int, int> &current, unordered_map<int, int> &other)
{
    vector<int> ans;
    for (auto n : current)
    {
        int num = n.first;
        int count = n.second;
        if (count >= other[num])
        {

            for (int i = 0; i < count; i++)
                ans.push_back(num);
        }
    }

    return ans;
}

int main()
{

    vector<int> a = {1, 2, 3, 4, 4, 5, 5, 8, 10};
    vector<int> b = {4, 5, 5, 5, 6, 7, 8, 8, 10};

    unordered_map<int, int> num_count_a, num_count_b;

    for (int k = 0; k < 2; k++)
    {
        for (int i = 0; i < a.size(); i++)
        {
            num_count_a[a[i]]++;
        }
        swap(num_count_a, num_count_b);
        swap(a, b);
    }
    swap(num_count_a, num_count_b);
    swap(a, b);

    vector<int> ans_a = create_ans(num_count_a, num_count_b);
    vector<int> ans_b = create_ans(num_count_b, num_count_a);

    return 0;
}