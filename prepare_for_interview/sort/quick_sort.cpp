// 毎日課題
// unstable O(nlogn)

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

void quick(vector<int> &nums, int start, int end)
{

    if (start >= end)
        return;
    int i = start - 1;

    int pivot = nums[end];

    for (int j = start; j < end; j++)
    {
        if (nums[j] < pivot)
        {
            ++i;
            swap(nums[i], nums[j]);
        }
    }
    swap(nums[i + 1], nums[end]);

    quick(nums, start, i);
    quick(nums, i + 1, end);
}

int main()
{

    vector<int> nums;
    rep(i, 10) nums.push_back(rand() % 1000);

    quick(nums, 0, nums.size() - 1);

    rep(i, nums.size()) cout << nums[i] << " ";

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; i++)

// void quick(vector<int> &nums, int start, int end)
// {
//     if (end - start < 1)
//         return;
//     int i = start - 1;
//     int pivot = nums[end];

//     for (int j = start; j < end; j++)
//     {
//         if (nums[j] < pivot)
//         {
//             ++i;
//             swap(nums[i], nums[j]);
//         }
//     }
//     ++i;
//     swap(nums[i], nums[end]);

//     quick(nums, start, i - 1);
//     quick(nums, i, end);
// }

// int main()
// {
//     vector<int> nums;
//     rep(i, 10)
//     {
//         nums.push_back(rand() % 1000);
//     }

//     quick(nums, 0, nums.size() - 1);

//     rep(i, nums.size()) cout << nums[i] << " ";

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// void quick(vector<int> &nums, int start, int end)
// {

//     if (start >= end)
//         return;

//     int i = start - 1;
//     int j = start;

//     int pivot = nums[end];

//     for (int k = j; k < end; k++)
//     {
//         if (nums[k] < pivot)
//         {
//             ++i;
//             swap(nums[i], nums[k]);
//         }
//     }
//     swap(nums[i + 1], nums[end]);
//     quick(nums, start, i);
//     quick(nums, i + 2, end);
// }

// int main()
// {

//     vector<int> nums;
//     rep(i, 10) nums.push_back(rand() % 1000);

//     quick(nums, 0, nums.size() - 1);

//     rep(i, 10) cout << nums[i] << " ";

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// void quick(vector<int> &nums, int start, int end)
// {

//     int i = start - 1;
//     int j = start;
//     int pivot = nums[end];

//     if (start >= end)
//         return;

//     for (int j = start; j < end; j++)
//     {

//         if (nums[j] < pivot)
//         {
//             ++i;
//             swap(nums[i], nums[j]);
//         }
//     }
//     swap(nums[end], nums[i + 1]);

//     quick(nums, start, i - 1);
//     quick(nums, i + 1, end);
// }

// int main()
// {
//     vector<int> nums;
//     rep(i, 10)
//     {
//         nums.push_back(rand() % 1000);
//     }
//     int n = nums.size();
//     quick(nums, 0, n - 1);

//     rep(i, n) cout << nums[i] << endl;

//     return 0;
// }