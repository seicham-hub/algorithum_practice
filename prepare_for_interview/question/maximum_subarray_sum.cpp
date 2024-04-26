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

int main()
{

    // vector<int> nums = {1, -2, 3, 6, -1, 2, 4, -5, 2};
    // int n = nums.size();

    // maximum_subarray_sum(nums, n);

    vector<int> nums2 = {1, -2, 3, 6, -1, 2, 4, -5, 2};
    int n2 = nums2.size();
    maximum_circular_subarray_sum(nums2, n2);

    return 0;
}