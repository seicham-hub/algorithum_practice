// {1} →{2} output 2
// {1.2} → {1,3} output 13
// {9,9} → {1,0,0} output 100
// {0,0,0,9,9,9,9} → {1,0,0,0,0} output 10000

#include <bits/stdc++.h>
using namespace std;

int convert_list_to_int(vector<int> &nums)
{
    int result = 0;
    int multiplier = 1;

    for (auto it = nums.rbegin(); it != nums.rend(); it++)
    {

        result += (*it) * multiplier;
        multiplier *= 10;
    }

    return result;
}

int list_to_int_plus_one(vector<int> nums)
{
    for (auto it = nums.rbegin(); it != nums.rend(); it++)
    {
        (*it) += 1;

        if ((*it) <= 9)
            break;
        else
            (*it) = 0;

        if (it == nums.rend() - 1 && (*it) == 0)
        {
            nums.insert(nums.begin(), 1);
        }
    }

    return convert_list_to_int(nums);
}

int main()
{

    vector<int> nums = {1, 3, 5};
    int ans = list_to_int_plus_one(nums);

    cout << ans << endl;

    return 0;
}
// #include <bits/stdc++.h>
// using namespace std;

// void remove_zero(vector<int> &nums)
// {
//     while (nums.size() && nums[0] == 0)
//     {
//         nums.erase(nums.begin());
//     }
// }

// int main()
// {

//     vector<int> nums = {9, 9, 9};

//     int n = nums.size();

//     int i = 1;

//     nums[n - i]++;

//     while (n - i - 1 >= 0)
//     {

//         if (nums[n - i] < 10)
//         {
//             break;
//         }
//         else
//         {
//             nums[n - i] = 0;
//             nums[n - i - 1]++;
//         }
//         i++;
//     }

//     remove_zero(nums);

//     if (nums[0] > 9)
//     {
//         nums[0] = 0;
//         nums.insert(nums.begin(), 1);
//     }

//     string ans = "";
//     for (int i = 0; i < nums.size(); i++)
//         ans += nums[i] + '0';

//     cout << stoi(ans) << endl;
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// void remove_zero(vector<int> &nums)
// {
//     if (nums[0] == 0)
//     {
//         nums.erase(nums.begin());
//         remove_zero(nums);
//     }
//     return;
// }

// int main()
// {

//     vector<int> nums = {9, 9, 9};

//     int n = nums.size();
//     int i = n - 1;
//     nums[i]++;
//     while (i > 0)
//     {
//         if (nums[i] < 10)
//         {
//             remove_zero(nums);
//             break;
//         }
//         else
//         {
//             nums[i] = 0;
//             nums[i - 1]++;
//         }

//         i--;
//     }

//     if (nums[0] == 10)
//     {
//         nums[0] = 0;
//         nums.insert(nums.begin(), 1);
//     }

//     string ans = "";
//     for (int j = 0; j < nums.size(); j++)
//     {
//         ans += nums[j] + '0';
//     }

//     cout << stoi(ans) << endl;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {

//     vector<int> nums;
//     for (int i = 0; i < 5; i++)
//         nums.push_back(0);
//     for (int i = 0; i < 5; i++)
//         nums.push_back(9);

//     for (int i = 0; !nums.empty() && nums[i] < 1;)
//     {
//         nums.erase(nums.begin());
//     }

//     if (nums.empty())
//     {
//         cout << 1;
//         return 0;
//     }

//     int n = nums.size();

//     int last = nums.back();
//     int next = last + 1;

//     if (next < 9)
//         nums[n - 1] = next;
//     else
//     {

//         int i = 1;
//         while (next > 9 && 0 <= n - i)
//         {
//             next = next / 10 + nums[n - i];
//             nums[n - i] = next > 9 ? 0 : next;
//             ++i;
//         }

//         if (next > 9)
//             nums.insert(nums.begin(), 1);
//     }

//     for (auto i : nums)
//     {
//         cout << i;
//     }
// }