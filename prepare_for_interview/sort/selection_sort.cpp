// 毎日課題
// stable O(n^2)

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

void selection(vector<int> &nums)
{

    int n = nums.size();

    rep(i, n)
    {
        int min_ind = i;
        for (int j = i + 1; j < n; ++j)
            if (nums[j] < nums[min_ind])
                min_ind = j;
        swap(nums[i], nums[min_ind]);
    }
}

int main()
{

    vector<int> nums;
    rep(i, 10) nums.push_back(rand() % 1000);

    selection(nums);

    rep(i, nums.size()) cout << nums[i] << endl;

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// void selection(vector<int> &nums)
// {
//     int n = nums.size();
//     rep(i, n)
//     {
//         int min_ind = i;
//         for (int j = i; j < n; j++)
//         {
//             if (nums[j] < nums[min_ind])
//                 min_ind = j;
//         }
//         swap(nums[i], nums[min_ind]);
//     }
// }

// int main()
// {

//     vector<int> nums;
//     rep(i, 10) nums.push_back(rand() % 1000);

//     selection(nums);

//     rep(i, nums.size()) cout << nums[i] << endl;

//     return 0;
// }
// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// void selection(vector<int> &nums)
// {
//     int n = nums.size();

//     rep(i, n)
//     {
//         int min_ind = i;
//         for (int j = i; j < n; j++)
//         {
//             if (nums[j] < nums[min_ind])
//                 min_ind = j;
//         }
//         swap(nums[i], nums[min_ind]);
//     }
// }

// int main()
// {

//     vector<int> nums;
//     rep(i, 10) nums.push_back(rand() % 1000);

//     selection(nums);

//     rep(i, nums.size()) cout << nums[i] << endl;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// void selection(vector<int> &nums)
// {

//     int n = nums.size();

//     rep(i, n)
//     {
//         int min_ind = i;
//         for (int j = i; j < n; j++)
//         {
//             if (nums[j] < nums[min_ind])
//                 min_ind = j;
//         }
//         swap(nums[i], nums[min_ind]);
//     }
// }

// int main()
// {
//     vector<int> nums;
//     rep(i, 10) nums.push_back(rand() % 1000);

//     selection(nums);
//     rep(i, nums.size()) cout << nums[i] << " ";
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// void selection(vector<int> &nums)
// {
//     int n = nums.size();
//     rep(i, n)
//     {
//         int min_ind = i;
//         for (int j = i; j < n; j++)
//         {
//             if (nums[j] < nums[min_ind])
//                 min_ind = j;
//         }
//         swap(nums[i], nums[min_ind]);
//     }
// }

// int main()
// {
//     vector<int> nums;

//     rep(i, 10)
//     {
//         random_device seed_gen;
//         mt19937 engine(seed_gen());
//         nums.push_back(engine() % 1000);
//     }

//     selection(nums);

//     rep(i, nums.size()) cout << nums[1] << " ";

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// void selection(vector<int> &nums)
// {

//     int n = nums.size();

//     rep(i, n)
//     {
//         int min_ind = i;
//         for (int j = i; j < n; j++)
//         {
//             if (nums[j] < nums[min_ind])
//                 min_ind = j;
//         }
//         swap(nums[i], nums[min_ind]);
//     }
// }

// int main()
// {
//     vector<int> nums;
//     rep(i, 10)
//     {
//         nums.push_back(rand() % 1000);
//     }

//     selection(nums);

//     rep(i, nums.size()) cout << nums[i] << endl;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// // 毎日課題
// void selection(vector<int> &nums)
// {

//     int n = nums.size();
//     rep(i, n)
//     {
//         int mini_ind = i;

//         for (int j = i; j < n; j++)
//         {
//             if (nums[j] < nums[mini_ind])
//             {
//                 mini_ind = j;
//             }
//         }
//         swap(nums[i], nums[mini_ind]);
//     }
// }

// int main()
// {
//     vector<int> nums(6);
//     nums = {2, 5, 1, 8, 7, 3};

//     selection(nums);

//     rep(i, nums.size()) cout << nums[i] << endl;
//     return 0;
// }