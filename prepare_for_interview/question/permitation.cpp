// 順列をすべて表示させろ

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> all_perms(const vector<int> &elements)
{

    if (elements.size() <= 1)
    {
        return {elements};
    }

    vector<vector<int>> perms;
    for (size_t i = 0; i < elements.size(); ++i)
    {
        vector<int> rest(elements.begin(), elements.begin() + i);
        rest.insert()
    }
}

// #include <bits/stdc++.h>
// using namespace std;

// vector<int> nums = {1, 2, 3, 8, 6};

// void get_permutation(int &n, set<int> remain_nums, vector<int> tmp_nums, vector<vector<int>> &ans)
// {

//     if (remain_nums.empty())
//     {
//         ans.push_back(tmp_nums);
//         return;
//     }

//     for (int s : remain_nums)
//     {

//         set<int> new_remain_nums = remain_nums;
//         vector<int> new_tmp_nums = tmp_nums;

//         new_remain_nums.erase(s);
//         new_tmp_nums.push_back(s);
//         get_permutation(n, new_remain_nums, new_tmp_nums, ans);
//     }
// }

// int main()
// {

//     int n = nums.size();

//     vector<vector<int>> ans;
//     set<int> nums_can_use;
//     for (int i = 0; i < nums.size(); i++)
//         nums_can_use.insert(nums[i]);

//     get_permutation(n, nums_can_use, {}, ans);

//     for (auto a : ans)
//     {
//         for (int ni : a)
//             cout << ni << " ";
//         cout << endl;
//     }

//     return 0;
// }

// def all_perms(elements: List[int]) -> List[List[int]]:
//     first = elements[0:1]
//     rest = elements[1:]

//     if len(elements) <= 1
//         return [elements]

//     for perm in all_perms(elements[1:]):
//         for i in range(len(elements)):
//             print(perm[:i]+elements[0:1]+perms[i:])

// if __name__ = '__main__':
//     for p in all_perms([1,2,3]):
//         print(p)
