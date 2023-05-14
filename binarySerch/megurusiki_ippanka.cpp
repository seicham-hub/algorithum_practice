// 0504もう一度

// 条件を満たす最小の indexではなく、
// 条件を満たす最大のindexが知りたいとき

#include <iostream>
#include <vector>
using namespace std;

vector<int> a = {100, 98, 70, 60, 50, 41, 32, 21, 11, 1};

bool check(int ind, int key)
{
    if (a[ind] <= key)
        return true;
    else
        return false;
}

int binary_serch(int key)
{
    int left = -1;
    int right = a.size();

    while (abs(right - left) > 1)
    {
        int mid = (right + left) / 2;
        if (check(mid, key))
            right = mid;
        else
            left = mid;
    }

    return right;
}

int main()
{
    cout << binary_serch(50) << endl;
}

// #include <iostream>
// #include <vector>

// using namespace std;

// vector<int> a = {100, 98, 70, 60, 50, 41, 32, 21, 11, 1};

// bool isOK(int index, int key)
// {
//     if (a[index] >= key)
//         return true;
//     else
//         return false;
// }

// int binary_search(int key)
// {
//     int ng = -1;
//     int ok = (int)a.size();

//     /* okとngどちらが大きいか分からないことを考慮 */
//     while (abs(ok - ng) > 1)
//     {
//         int mid = (ok + ng) / 2;
//         if (isOK(mid, key))
//             ok = mid;
//         else
//             ng = mid;
//     }
//     return ok;
// }

// int main()
// {
//     cout << binary_search(30) << endl;
//     cout << binary_search(51) << endl;  // a[3] = 51 (さっきは 4 を返したが今回は「最小の index」なので 3)
//     cout << binary_search(1) << endl;   // a[0] = 1
//     cout << binary_search(910) << endl; // a[9] = 910

//     cout << binary_search(52) << endl;  // 6
//     cout << binary_search(0) << endl;   // 0
//     cout << binary_search(911) << endl; // 10 (場外)

//     return 0;
// }