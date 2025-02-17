// 問題：[11, 2, 5, 9, 10, 3] 二つペアを選んだ時に、その二つの数字の合計と
// 残りの数字をすべて足したものが等しくなる組はあるか？

// 2024_03_25もう一度

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

struct Result
{
    pair<int, int> result;

    Result(int x, int y)
    {
        result = {x, y};
    };
};

unique_ptr<Result> get_sum_pair(vector<int> nums)
{
    unordered_map<int, bool> cache;

    int sum = 0;
    int n = nums.size();
    rep(i, n) sum += nums[i];

    if (sum % 2 != 0)
        return nullptr;

    for (int &x : nums)
    {
        if (cache[x])
        {
            return make_unique<Result>(x, sum / 2 - x);
        }
        cache[sum / 2 - x] = true;
    }

    return nullptr;
}

int main()
{
    vector<int> nums = {11, 2, 5, 9, 10, 3};
    unique_ptr<Result> ans = get_sum_pair(nums);

    if (ans)
    {
        cout << ans->result.first << "," << ans->result.second << endl;
    }

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// struct Result
// {
//     pair<int, int> value;
//     Result(int first, int second)
//     {
//         value = {first, second};
//     }
// };

// unique_ptr<Result> get_sum_pair(vector<int> &nums)
// {
//     int sum = 0;
//     int n = nums.size();
//     rep(i, n) sum += nums[i];

//     if (sum % 2 != 0)
//         return nullptr;

//     unordered_map<int, bool> cache;
//     for (int &ni : nums)
//     {
//         if (cache[ni])
//         {
//             return make_unique<Result>(ni, sum / 2 - ni);
//         }

//         cache[sum / 2 - ni] = true;
//     }

//     return nullptr;
// }

// int main()
// {

//     vector<int> nums = {11, 2, 5, 9, 10, 3};

//     auto ans = get_sum_pair(nums);

//     if (ans)
//         cout << ans->value.first << "," << ans->value.second << endl;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// pair<int, int> get_half_sum_pair(vector<int> &nums)
// {
//     int sum = 0;
//     int n = nums.size();

//     rep(i, n) sum += nums[i];

//     if (sum % 2 != 0)
//         return {0, 0};
//     unordered_map<int, int> cache;

//     rep(i, n)
//     {
//         int x = nums[i];
//         if (cache[sum / 2 - x])
//         {
//             return {sum / 2 - x, x};
//         }
//         cache[x]++;
//     }

//     return {0, 0};
// }

// int main()
// {
//     vector<int> nums = {11, 2, 5, 9, 10, 3};

//     pair<int, int> ans = get_half_sum_pair(nums);

//     cout << ans.first << "," << ans.second << endl;
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// pair<int, int> get_half_sum_pair(vector<int> &nums)
// {

//     int sum = 0;
//     int n = nums.size();
//     rep(i, n) sum += nums[i];

//     if (sum % 2 != 0)
//         return {0, 0};

//     unordered_map<int, int> cache;

//     rep(i, n)
//     {
//         int x = nums[i];
//         if (cache[sum / 2 - x])
//         {
//             return {sum / 2 - x, x};
//         }
//         cache[x]++;
//     }
// }

// int main()
// {
//     vector<int> nums = {11, 2, 5, 9, 10, 3};

//     pair<int, int> ans = get_half_sum_pair(nums);

//     cout << ans.first << "," << ans.second << endl;
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// pair<int, int> get_pair_half_sum(vector<int> &nums, int &sum)
// {

//     unordered_map<int, int> cache;
//     int n = nums.size();

//     if (sum % 2 != 0)
//         return {0, 0};

//     int half_sum = sum / 2;

//     rep(i, n)
//     {

//         int target = half_sum - nums[i];

//         if (cache[target])
//             return {target, nums[i]};
//         cache[nums[i]]++;
//     }

//     return {0, 0};
// }

// int main()
// {

//     vector<int> nums = {11, 2, 5, 9, 10, 3};

//     int sum = 0;
//     rep(i, nums.size()) sum += nums[i];

//     sort(nums.begin(), nums.end());
//     pair<int, int> ans = get_pair_half_sum(nums, sum);

//     cout << ans.first << "," << ans.second << endl;
// }

// 3/25間違い分
// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// pair<int, int> get_pair_half_sum(vector<int> &nums)
// {

//     unordered_map<int, int> cache;
//     int n = nums.size();

//     int sum = 0;
//     rep(i, n) sum += nums[i];

//     rep(i, n) cache[nums[i]]++;

//     rep(i, n)
//     {
//         int x = nums[i];
//         cache[x]--;
//         if (cache[sum / 2 - x])
//         {
//             return {x, sum / 2 - x};
//         }
//         cache[x]++;
//     }

//     return {0, 0};
// }

// int main()
// {
//     vector<int> nums = {11, 2, 5, 9, 10, 3};

//     pair<int, int> ans = get_pair_half_sum(nums);

//     cout << ans.first << "," << ans.second << endl;
//     return 0;
// }