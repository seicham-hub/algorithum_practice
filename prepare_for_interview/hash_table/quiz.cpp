#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

pair<int, int> get_pair(vector<int> &nums, int target, map<int, int> num_count)
{
    int n = nums.size();
    rep(i, n)
    {
        // 選んだ数字を引く
        num_count[nums[i]]--;
        int remain = (target - nums[i]);
        if (num_count[remain])
            return {nums[i], remain};
        // 選んだ数字を戻す
        num_count[nums[i]]++;
    }

    return {0, 0};
}

int main()
{

    vector<int> nums;
    rep(i, 10) nums.push_back(rand() % 100);

    map<int, int> num_count;

    for (int num : nums)
    {
        num_count[num]++;
    }

    pair<int, int> ans = get_pair(nums, 50, num_count);

    cout << ans.first << "," << ans.second << endl;
    return 0;
}