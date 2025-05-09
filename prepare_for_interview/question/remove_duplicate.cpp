// Input:{1, 3, 3, 5, 5, 7, 7, 7, 10, 12, 12, 15, 15};
// output:1, 3, 5, 7, 10, 12, 15
// 重複するものを削除したものを出力
// 1 3 5 7 10 12 15

#include <bits/stdc++.h>
using namespace std;

void remove_duplicate(vector<int> &nums)
{
    int i = nums.size() - 1;
    while (i >= 1)
    {
        if (nums[i - 1] == nums[i])
            nums.erase(nums.begin() + i);

        i--;
    }
}

int main()
{

    vector<int> nums = {1, 3, 3, 5, 5, 7, 7, 7, 10, 12, 12, 15, 15};
    remove_duplicate(nums);

    for (int a : nums)
    {
        cout << a << ",";
    }

    return 0;
}
// #include <bits/stdc++.h>
// using namespace std;

// void remove_duplicate(vector<int> &nums)
// {
//     int index = nums.size() - 1;
//     while (index >= 1)
//     {
//         if (nums[index] == nums[index - 1])
//         {
//             nums.erase(nums.begin() + index);
//         }

//         index--;
//     }
// }

// int main()
// {

//     vector<int> nums = {1, 3, 3, 5, 5, 7, 7, 7, 10, 12, 12, 15, 15};

//     remove_duplicate(nums);

//     for (int &n : nums)
//     {
//         cout << n << " ";
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// void remove_duplicate_with_set(vector<int> &nums, int &n)
// {
//     set<int> ans;

//     for (int i = 0; i < n; i++)
//     {
//         ans.insert(nums[i]);
//     }

//     for (int a : ans)
//     {
//         cout << a << " ";
//     }
//     cout << endl;
// }

// void remove_duplicate_v2(vector<int> &nums, int &n)
// {

//     int i = 0;
//     vector<int> ans;
//     ans.push_back(nums[0]);
//     while (i + 1 < n)
//     {

//         if (nums[i] != nums[i + 1])
//             ans.push_back(nums[i + 1]);

//         i++;
//     }

//     for (int a : ans)
//         cout << a << " ";
//     cout << endl;
// }
// void remove_duplicate_v3(vector<int> &nums, int &n)
// {

//     int i = n - 1;
//     while (i - 1 >= 0)
//     {

//         if (nums[i - 1] == nums[i])
//             nums.erase(nums.begin() + i);

//         i--;
//     }

//     for (int a : nums)
//         cout << a << " ";
//     cout << endl;
// }

// int main()
// {

//     vector<int> nums = {1, 3, 3, 5, 5, 7, 7, 7, 10, 12, 12, 15, 15};
//     int n = nums.size();
//     remove_duplicate_with_set(nums, n);
//     remove_duplicate_v2(nums, n);
//     remove_duplicate_v3(nums, n);

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// void remove_duplicate_with_set(vector<int> &nums, int &n)
// {

//     set<int> ans;

//     for (int i = 0; i < n; i++)
//         ans.insert(nums[i]);

//     for (int a : ans)
//     {
//         cout << a << " ";
//     }
//     cout << endl;
// }

// void remove_duplicate(vector<int> &nums, int &n)
// {

//     unordered_map<int, bool> mp;
//     vector<int> ans;

//     for (int i = 0; i < n; i++)
//     {

//         if (!mp[nums[i]])
//             ans.push_back(nums[i]);
//         mp[nums[i]] = true;
//     }

//     for (int a : ans)
//         cout << a << " ";
//     cout << endl;
// }

// void remove_duplicate_v2(vector<int> &nums, int &n)
// {
//     vector<int> ans;
//     ans.push_back(nums[0]);
//     for (int i = 0; i < n - 1; i++)
//     {
//         if (nums[i] != nums[i + 1])
//             ans.push_back(nums[i + 1]);
//     }

//     for (int a : ans)
//         cout << a << " ";
//     cout << endl;
// }

// void remove_duplicate_v3(vector<int> &nums, int &n)
// {
//     for (int i = 0; i < nums.size() - 1; i++)
//     {
//         while ((i + 1) < nums.size() && nums[i] == nums[i + 1])
//         {
//             nums.erase(nums.begin() + i + 1);
//         }
//     }

//     for (int a : nums)
//         cout << a << " ";
//     cout << endl;
// }

// void remove_duplicate_v4(vector<int> &nums, int &n)
// {
//     int i = n - 1;
//     while (i > 0)
//     {
//         if (nums[i] == nums[i - 1])
//         {
//             nums.erase(nums.begin() + i);
//         }
//         i--;
//     }
//     for (int a : nums)
//         cout << a << " ";
//     cout << endl;
// }

// int main()
// {

//     vector<int> nums = {1, 3, 3, 5, 5, 7, 7, 7, 10, 12, 12, 15, 15};
//     int n = nums.size();

//     remove_duplicate_with_set(nums, n);
//     remove_duplicate(nums, n);
//     remove_duplicate_v2(nums, n);
//     remove_duplicate_v3(nums, n);
//     remove_duplicate_v4(nums, n);

//     return 0;
// }