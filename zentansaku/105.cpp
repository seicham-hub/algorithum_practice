// https://atcoder.jp/contests/abc106/tasks/abc106_b
// 0414もう一度

#include <bits/stdc++.h>
using namespace std;

vector<int> get_odd_nums_divisor_count_is(int target, int &num)
{
    vector<int> results;
    for (int i = 1; i <= num; i += 2)
    {
        int divisor_count = 0;
        for (int j = 1; j <= i; j++)
        {
            if (i % j == 0)
                divisor_count++;
        }

        if (divisor_count == target)
            results.push_back(i);
    }

    return results;
}

int main()
{

    int n;
    cin >> n;

    vector<int> ans = get_odd_nums_divisor_count_is(8, n);

    cout << ans.size() << endl;

    return 0;
}
// #include <bits/stdc++.h>
// using namespace std;

// vector<int> get_division_count_is(int target_num, int num)
// {
//     vector<int> result;

//     for (int candidate = 1; candidate <= num; candidate += 2)
//     {

//         int divisionable_num_count = 0;
//         for (int i = 1; i * i <= candidate; i++)
//         {
//             if (candidate % i == 0)
//             {
//                 if (i != candidate / i)
//                     divisionable_num_count += 2;
//                 else
//                     divisionable_num_count++;
//             }
//         }

//         if (divisionable_num_count == target_num)
//             result.push_back(candidate);
//     }

//     return result;
// }

// int main()
// {
//     int n;
//     cin >> n;

//     vector<int> ans = get_division_count_is(5, n);

//     cout << ans.size() << endl;

//     return 0;
// }
// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n, result = 0;
//     cin >> n;

//     for (int i = 1; i <= n; i += 2)
//     {
//         int yakusuAmount = 0;
//         for (int j = 1; j <= i; j++)
//         {
//             if (i % j == 0)
//                 yakusuAmount++;
//         }

//         if (yakusuAmount == 8)
//             result++;
//     }
//     cout << result << endl;
//     return 0;
// }

// 自分で書いたコード

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n, result = 0;
//     cin >> n;

//     // for(int i=1;<=n;i+=2)とすれば奇数のみに絞れる
//     for (int i = 1; i <= n; i++)
//     {

//         int yakusuQuantity = 0;
//         // j<=iとすれば商が0か気にしなくてよい
//         for (int j = 1; j <= n; j++)
//         {

//             if (i / j != 0 && i % j == 0)
//             {

//                 yakusuQuantity++;
//             }
//         }

//         if (i % 2 == 1 && yakusuQuantity == 8)
//             result++;
//     }

//     cout << result << endl;
//     return 0;
// }
