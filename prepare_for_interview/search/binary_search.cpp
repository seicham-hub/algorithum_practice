// 毎日課題

// 再起関数の場合

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n++ i)

int binary(vector<int> &nums, const int &target, int left, int right)
{
    if (abs(right - left) == 1)
    {
        if (nums[left] == target)
            return left;
        else
            return -1;
    }

    int mid = (left + right) / 2;
    if (nums[mid] <= target)
        left = mid;
    else
        right = mid;

    return binary(nums, target, left, right);
}

int main()
{
    vector<int> nums = {1, 2, 6, 8, 9, 11, 16, 22, 35, 38, 42, 56};
    int ans = binary(nums, 31, 0, nums.size() - 1);

    cout << ans << endl;
}

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n++ i)

// int binary(vector<int> &nums, int target)
// {
//     int n = nums.size();

//     int left = 0;
//     int right = n - 1;
//     while (abs(right - left) > 1)
//     {
//         int mid = (left + right) / 2;
//         if (nums[mid] <= target)
//             left = mid;
//         else
//             right = mid;
//     }
//     if (nums[left] == target)
//         return left;
//     else
//         -1;
// }

// int main()
// {
//     vector<int> nums = {1, 3, 4, 9, 15, 22, 36, 44, 57, 95, 102, 111};

//     int ans = binary(nums, 3);

//     cout << ans << endl;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n++ i)

// int binary_search(vector<int> &nums, int target)
// {
//     int n = nums.size();
//     int left = 0;
//     int right = n - 1;
//     while (abs(left - right) > 1)
//     {
//         int mid = (left + right) / 2;
//         if (nums[mid] <= target)
//             left = mid;
//         else
//             right = mid;
//     }

//     return left;
// }

// int main()
// {

//     vector<int> nums = {0, 1, 5, 7, 9, 11, 15, 20, 24};

//     int ind = binary_search(nums, 15);

//     cout << ind << endl;

//     return 0;
// }