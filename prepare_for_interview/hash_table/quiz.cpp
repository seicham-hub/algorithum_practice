// 問題：[1,5,6,8,2,10] 足して14となるペアはあるか？

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

pair<int, int> get_pair(vector<int> &nums, int &target)
{
    // 数字：個数を記録
    unordered_map<int, int> cache;
    int n = nums.size();

    rep(i, n)
    {
        cache[nums[i]]++;
    }

    rep(i, n)
    {
        int current = nums[i];
        cache[current]--;
        int remain = target - nums[i];
        if (cache[remain])
        {
            return {current, remain};
        }
        cache[current]++;
    }

    return {0, 0};
}

int main()
{

    vector<int> nums;
    rep(i, 10) nums.push_back(rand() % 100);
    int target = 50;

    pair<int, int> ans = get_pair(nums, target);

    cout << ans.first << "," << ans.second << endl;

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// pair<int, int> get_pair(vector<int> &nums, int target)
// {
//     int n = nums.size();

//     unordered_map<int, int> cache;

//     for (int num : nums)
//     {
//         cache[num]++;
//     }

//     rep(i, n)
//     {
//         // 選んだ数字を引く
//         cache[nums[i]]--;
//         int remain = (target - nums[i]);
//         if (cache[remain])
//             return {nums[i], remain};
//         // 選んだ数字を戻す
//         cache[nums[i]]++;
//     }

//     return {0, 0};
// }

// int main()
// {

//     vector<int> nums;
//     rep(i, 10) nums.push_back(rand() % 100);

//     pair<int, int> ans = get_pair(nums, 50);

//     cout << ans.first << "," << ans.second << endl;
//     return 0;
// }