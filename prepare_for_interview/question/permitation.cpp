// 順列をすべて表示させろ
// {1, 2, 3}

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> all_perms(vector<int> elements)
{

    if (elements.size() <= 1)
    {
        return {elements};
    }

    vector<vector<int>> result;

    int first = elements[0];
    vector<int> rest(elements.begin() + 1, elements.end());

    for (auto &perm : all_perms(rest))
    {

        for (int i = 0; i <= perm.size(); i++)
        {
            vector<int> a(perm.begin(), perm.begin() + i);
            a.push_back(first);
            a.insert(a.end(), perm.begin() + i, perm.end());

            result.push_back(a);
        }
    }

    return result;
}

int main()
{
    vector<int> elements = {1, 2, 3, 4};

    auto ans = all_perms(elements);

    for (auto a : ans)
    {
        for (int num : a)
        {
            cout << num << ",";
        }
        cout << endl;
    }

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// vector<vector<int>> all_perms(vector<int> &nums)
// {

//     if (nums.size() <= 1)
//     {
//         return {nums};
//     }
//     vector<vector<int>> result;

//     int first = nums[0];
//     vector<int> rest(nums.begin() + 1, nums.end());

//     for (auto &perm : all_perms(rest))
//     {
//         for (int i = 0; i < perm.size() + 1; i++)
//         {
//             vector<int> a(perm.begin(), perm.begin() + i);
//             a.push_back(first);
//             a.insert(a.end(), perm.begin() + i, perm.end());

//             result.push_back(a);
//         }
//     }

//     return result;
// }

// int main()
// {

//     vector<int> nums = {1, 2, 3, 4};
//     auto ans = all_perms(nums);

//     for (auto a : ans)
//     {
//         for (int num : a)
//         {
//             cout << num << ",";
//         }
//         cout << endl;
//     }
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// vector<vector<int>> all_perms(vector<int> &elements)
// {

//     if (elements.size() == 1)
//     {

//         return {elements};
//     }

//     int first = elements[0];
//     vector<int> rest(elements.begin() + 1, elements.end());

//     vector<vector<int>> result;

//     // {2,3}
//     for (const auto &perm : all_perms(rest))
//     {
//         for (int i = 0; i < perm.size() + 1; i++)
//         {
//             vector<int> a(perm.begin(), perm.begin() + i);
//             a.push_back(first);
//             a.insert(a.end(), perm.begin() + i, perm.end());

//             result.push_back(a);
//         }
//     }

//     return result;
// }

// int main()
// {
//     vector<int> elements = {1, 2, 3};

//     auto ans = all_perms(elements);

//     for (vector<int> el : ans)
//     {
//         for (int e : el)
//         {
//             cout << e << ",";
//         }
//         cout << endl;
//     }

//     return 0;
// }

// c++のお手本コード
//

// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// vector<vector<int>> all_perms(vector<int> elements)
// {
//     // ベースケース: 要素が1つ以下の場合、そのまま返す
//     if (elements.size() <= 1)
//     {
//         return {elements};
//     }

//     // すべての順列を格納するためのベクトル
//     vector<vector<int>> result;

//     // 最初の要素を取得し、残りの要素を取得
//     int first = elements[0];
//     vector<int> rest(elements.begin() + 1, elements.end());

//     // 残りの要素の順列を再帰的に取得
//     for (const auto &perm : all_perms(rest))
//     {
//         // 順列の全ての位置に最初の要素を挿入
//         for (size_t i = 0; i <= perm.size(); ++i)
//         {
//             vector<int> new_perm(perm);
//             new_perm.insert(new_perm.begin() + i, first);
//             result.push_back(new_perm);
//         }
//     }

//     return result;
// }

// int main()
// {
//     vector<int> elements = {1, 2, 3};
//     vector<vector<int>> permutations = all_perms(elements);

//     for (const auto &perm : permutations)
//     {
//         for (int num : perm)
//         {
//             cout << num << " ";
//         }
//         cout << endl;
//     }

//     return 0;
// }

// 自分で書いたコード
// 再帰的に順列を作成する。順列の候補の数字をsetに入れて管理。setが空になったらbreak

// #include <bits/stdc++.h>
// using namespace std;

// vector<vector<int>> get_all_permutation(const vector<int> &elements)
// {

//     set<int> candidate_nums;
//     for (int i = 0; i < elements.size(); i++)
//         candidate_nums.insert(i);

//     vector<vector<int>> indices_permutate;

//     function<void(int, vector<int>, set<int>)> _get_permutation_indices = [&](int now, vector<int> tmp_indices, set<int> candidate_nums)
//     {
//         tmp_indices.push_back(now);
//         candidate_nums.erase(now);

//         if (candidate_nums.empty())
//         {
//             indices_permutate.push_back(tmp_indices);
//             return;
//         }

//         for (int num : candidate_nums)
//         {
//             _get_permutation_indices(num, tmp_indices, candidate_nums);
//         }
//     };

//     for (int num : candidate_nums)
//         _get_permutation_indices(num, {}, candidate_nums);

//     vector<vector<int>> result;
//     for (vector<int> &indices : indices_permutate)
//     {

//         vector<int> tmp_result;
//         for (int &index : indices)
//         {
//             tmp_result.push_back(elements[index]);
//         }
//         result.push_back(tmp_result);
//     }

//     return result;
// }

// int main()
// {
//     vector<int> elements = {4, 9, 3};
//     auto ans = get_all_permutation(elements);

//     for (auto a : ans)
//     {
//         for (int i = 0; i < a.size(); i++)
//         {
//             cout << a[i] << ",";
//         }
//         cout << endl;
//     }

//     return 0;
// }

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
