#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

pair<int, int> get_pair_half_sum(vector<int> &nums, int &sum)
{

    map<int, int> cache;
    int n = nums.size();

    if (sum % 2 != 0)
        return {0, 0};

    int half_sum = sum / 2;

    rep(i, n)
    {
        cache[nums[i]]++;

        int target = half_sum - nums[i];

        if (cache[target])
            return {target, nums[i]};
    }

    return {0, 0};
}

int main()
{

    vector<int> nums = {11, 2, 5, 9, 10, 3};

    int sum = 0;
    rep(i, nums.size()) sum += nums[i];

    pair<int, int> ans = get_pair_half_sum(nums, sum);

    cout << ans.first << "," << ans.second << endl;
}