// 最長増加部分列問題
// 2024_09_09もう一度

#include <bits/stdc++.h>
using namespace std;

int longestIncreasingSubsequence(vector<int> &nums)
{
    vector<int> dp;

    for (int x : nums)
    {
        auto it = lower_bound(dp.begin(), dp.end(), x); // x 以上の要素を探す
        if (it == dp.end())
        {
            dp.push_back(x); // 末尾に追加
        }
        else
        {
            *it = x; // 置き換え
        }
    }

    return dp.size(); // dpの長さ
}

int main()
{
    vector<int> nums = {10, 22, 9, 33, 21, 50, 41, 60, 80};
    cout << "dp Length: " << longestIncreasingSubsequence(nums) << endl;
    return 0;
}
