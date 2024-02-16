// 毎日課題

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n++ i)

int binary_search(vector<int> &nums, int target)
{
    int n = nums.size();
    int left = 0;
    int right = n - 1;
    while (abs(left - right) > 1)
    {
        int mid = (left + right) / 2;
        if (nums[mid] <= target)
            left = mid;
        else
            right = mid;
    }

    return left;
}

int main()
{

    vector<int> nums = {0, 1, 5, 7, 9, 11, 15, 20, 24};

    int ind = binary_search(nums, 15);

    cout << ind << endl;

    return 0;
}