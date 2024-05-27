// 偶数要素が先に来るように並べろ
// [0,1,3,4,2,4,5,1,6,9,8] → [0,4,2,4,6,8,1,3,5,1,9]
// 新しく配列は作成せず、既存配列をいじって実装 stableでなくてOK

#include <bits/stdc++.h>
using namespace std;

void reorder_even_odd(vector<int> &nums)
{

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] % 2 != 0)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[j] % 2 == 0)
                    swap(nums[i], nums[j]);
            }
        }
    }
}

int main()
{

    vector<int> nums = {0, 1, 3, 4, 2, 4, 5, 1, 6, 9, 8};

    reorder_even_odd(nums);

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    return 0;
}