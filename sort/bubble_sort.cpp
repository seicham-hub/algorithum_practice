// 毎日課題
// stable O(n^2)

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

void bubble(vector<int> &nums)
{
    int n = nums.size();
    rep(i, n)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (nums[j] > nums[j + 1])
                swap(nums[j], nums[j + 1]);
        }
    }
}

int main()
{
    vector<int> nums;
    rep(i, 10) nums.push_back(rand() % 1000);

    bubble(nums);
    rep(i, nums.size()) cout << nums[i] << " ";
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// void bubble(vector<int> &nums)
// {
//     int n = nums.size();
//     rep(i, n)
//     {
//         rep(j, n - 1 - i)
//         {
//             if (nums[j] > nums[j + 1])
//                 swap(nums[j], nums[j + 1]);
//         }
//     }
// }

// int main()
// {
//     int n = 6;
//     vector<int> nums(6);
//     nums = {2, 5, 1, 8, 7, 3};

//     bubble(nums);

//     rep(i, n) cout << nums[i] << endl;

//     return 0;
// }