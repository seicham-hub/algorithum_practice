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
        int j = i - 1;
        int key = nums[i];

        while (j >= 0 && nums[j] > key)
        {
            nums[j + 1] = nums[j];
            j--;
        }

        nums[j + 1] = key;
    }
}

int main()
{

    vector<int> nums;
    rep(i, 10) nums.push_back(rand() % 100);

    selection(nums);

    for (int n : nums)
        cout << n << endl;
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// void insertion(vector<int> &nums)
// {
//     int n = nums.size();

//     rep(i, n)
//     {
//         int j = i - 1;
//         int key = nums[i];

//         while (j >= 0 && key < nums[j])
//         {
//             nums[j + 1] = nums[j];
//             j--;
//         }
//         nums[j + 1] = key;
//     }
// }

// int main()
// {

//     vector<int> nums;

//     rep(i, 10) nums.push_back(rand() % 100);

//     insertion(nums);

//     rep(i, nums.size()) cout << nums[i] << endl;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// void insertion(vector<int> &nums)
// {
//     int n = nums.size();
//     for (int i = 1; i < n; i++)
//     {
//         int key = nums[i];
//         int j = i - 1;
//         while (j >= 0 && nums[j] > key)
//         {
//             nums[j + 1] = nums[j];
//             j--;
//         }
//         nums[j + 1] = key;
//     }
// }

// int main()
// {

//     vector<int> nums;
//     rep(i, 10) nums.push_back(rand() % 1000);

//     insertion(nums);

//     rep(i, nums.size()) cout << nums[i] << endl;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// void insertion(vector<int> &nums)
// {
//     int n = nums.size();

//     for (int i = 1; i < n; i++)
//     {

//         int j = i - 1;
//         int key = nums[i];
//         while (j >= 0 && key < nums[j])
//         {
//             nums[j + 1] = nums[j];
//             j--;
//         }
//         nums[j + 1] = key;
//     }
// }

// int main()
// {

//     vector<int> nums;
//     rep(i, 10) nums.push_back(rand() % 1000);

//     insertion(nums);

//     rep(i, nums.size()) cout << nums[i] << endl;

//     return 0;
// }
// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// void insertion(vector<int> &nums)
// {
//     int n = nums.size();
//     for (int i = 1; i < n; i++)
//     {
//         int j = i - 1;
//         int key = nums[i];
//         while (j >= 0 && nums[j] > key)
//         {
//             nums[j + 1] = nums[j];
//             --j;
//         }
//         nums[j + 1] = key;
//     }
// }

// int main()
// {

//     vector<int> nums;
//     rep(i, 10) nums.push_back(rand() % 1000);

//     insertion(nums);

//     rep(i, nums.size()) cout << nums[i] << endl;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// void insertion(vector<int> &nums)
// {
//     int n = nums.size();

//     for (int i = 1; i < n; ++i)
//     {

//         int j = i - 1;
//         int key = nums[i];

//         while (j >= 0 && nums[j] > key)
//         {
//             nums[j + 1] = nums[j];
//             --j;
//         }
//         nums[j + 1] = key;
//     }
// }

// int main()
// {

//     vector<int> nums;
//     rep(i, 10) nums.push_back(rand() % 1000);

//     insertion(nums);

//     rep(i, nums.size()) cout << nums[i] << endl;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// void insertion(vector<int> &nums)
// {
//     int n = nums.size();

//     for (int i = 1; i < n; i++)
//     {
//         int j = i - 1;
//         int key = nums[i];
//         while (j >= 0 && nums[j] > key)
//         {
//             nums[j + 1] = nums[j];
//             j--;
//         }
//         nums[j + 1] = key;
//     }
// }

// int main()
// {

//     vector<int> nums;
//     rep(i, 10) nums.push_back(rand() % 1000);

//     insertion(nums);

//     rep(i, nums.size()) cout << nums[i] << endl;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// void insertion(vector<int> &nums)
// {
//     int n = nums.size();

//     for (int i = 1; i < n; i++)
//     {
//         int j = i - 1;
//         int key = nums[i];
//         while (j >= 0 && nums[j] > key)
//         {
//             nums[j + 1] = nums[j];
//             j--;
//         }

//         nums[j + 1] = key;
//     }
// }

// int main()
// {

//     vector<int> nums;
//     rep(i, 10) nums.push_back(rand() % 1000);

//     insertion(nums);

//     rep(i, nums.size()) cout << nums[i] << " ";
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// void insertion(vector<int> &nums)
// {
//     int n = nums.size();
//     for (int i = 1; i < n; i++)
//     {
//         int key = nums[i];
//         int j = i - 1;
//         while (j >= 0 && nums[j] > key)
//         {
//             nums[j + 1] = nums[j];
//             --j;
//         }
//         nums[j + 1] = key;
//     }
// }

// int main()
// {

//     vector<int> nums;
//     rep(i, 10)
//     {
//         nums.push_back(rand() % 1000);
//     }

//     insertion(nums);

//     rep(i, nums.size()) cout << nums[i] << " ";

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// void insertion(vector<int> &nums)
// {
//     int n = nums.size();
//     for (int i = 1; i < n; ++i)
//     {
//         int key = nums[i];
//         int j = i - 1;
//         while (j >= 0 && nums[j] > key)
//         {
//             nums[j + 1] = nums[j];
//             --j;
//         }
//         nums[j + 1] = key;
//     }
// }

// int main()
// {

//     vector<int> nums;

//     rep(i, 10)
//         nums.push_back(rand() % 1000); // ランダムな数値をvectorに追加

//     insertion(nums);

//     rep(i, nums.size()) cout << nums[i] << " ";
//     return 0;
// }