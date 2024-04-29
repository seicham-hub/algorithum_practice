// 連続する数を足し合わせたときに最大となる部分列の合計を出力
// Input: {2, -3, 4, -1, 5, -6, 7, -8, 6}
// output: {4, -1, 5, -6, 7} : 9

// 円環だった場合に連続する数を足し合わせたときの最大となる部分列と合計を出力
// Input: {2, -3, 4, -1, 5, -6, 7, -8, 6}
// output: {6, 2, -3, 4, -1, 5, -6, 7} : 14

#include <bits/stdc++.h>
using namespace std;

void maximum_subarray_sum(const vector<int> &nums, const int &n)
{
    int ans = -1e10;
    int start = -1;
    int end = -1;
    for (int len = 1; len <= n; len++)
    {
        for (int i = 0; i <= n - len; i++)
        {
            int sum = 0;
            for (int j = i; j < len + i; j++)
                sum += nums[j];
            if (sum > ans)
            {
                start = i;
                end = len + i;
                ans = sum;
            }
        }
    }

    std::cout << ans << endl;
    for (int i = start; i < end; i++)
        cout << nums[i] << " ";
}

void maximum_circular_subarray_sum(vector<int> &nums, const int &n)
{

    vector<int> circler_nums;
    int ans = -1e10;
    int start = -1;
    int end = -1;

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < nums.size(); j++)
            circler_nums.push_back(nums[j]);

    for (int len = 1; len <= n; len++)
    {
        for (int i = 0; i <= 2 * n - len; i++)
        {
            int sum = 0;
            for (int j = i; j < i + len; j++)
            {
                sum += circler_nums[j];
            }

            if (sum > ans)
            {
                ans = sum;
                start = i;
                end = i + len;
            }
        }
    }

    cout << ans << endl;
    for (int i = start; i < end; i++)
        cout << circler_nums[i] << " ";
}

auto get_max_sequence(vector<int> &nums, int n)
{
    int sequence_sum = 0;
    int result_sequence_sum = 0;
    for (int i = 0; i < n; i++)
    {

        sequence_sum = max(nums[i], sequence_sum + nums[i]);
        result_sequence_sum = max(result_sequence_sum, sequence_sum);
    }

    return result_sequence_sum;
}

int main()
{

    // vector<int> nums = {1, -2, 3, 6, -1, 2, 4, -5, 2};
    // int n = nums.size();

    // maximum_subarray_sum(nums, n);

    // vector<int> nums2 = {1, -2, 3, 6, -1, 2, 4, -5, 2};
    // int n2 = nums2.size();
    // maximum_circular_subarray_sum(nums2, n2);

    // お手本解答
    // vector<int> nums = {1, -2, 3, 6, -1, 2, 4, -5, 2};
    // int n = nums.size();
    // int sum = 0;
    // for (int i = 0; i < n; i++)
    //     sum += nums[i];

    // int result_sequence_sum = get_max_sequence(nums, n);
    // cout << result_sequence_sum << endl;

    // for (int i = 0; i < n; i++)
    //     nums[i] = nums[i] * -1;

    // int reverse_sequence_sum = get_max_sequence(nums, n) * -1;
    // int ans = max(result_sequence_sum, sum - reverse_sequence_sum);

    // cout << ans << endl;

    return 0;
}