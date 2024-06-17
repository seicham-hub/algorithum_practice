// https://atcoder.jp/contests/s8pc-6/tasks/s8pc_6_b

// 分からなかった
// 2024_06_11もう一度

#include <bits/stdc++.h>
using namespace std;

long long calc_time(int s, int e, vector<int> &a, vector<int> &b)
{
    long long result = 0;

    for (int i = 0; i < a.size(); i++)
    {
        result += abs(a[i] - s);
        result += abs(b[i] - a[i]);
        result += abs(e - b[i]);
    }

    return result;
}

int main()
{
    int n;
    long long ans = -1;
    cin >> n;

    vector<int> a(n), b(n);

    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];

    for (int s : a)
    {
        for (int e : b)
        {
            if (ans == -1)
                ans = calc_time(s, e, a, b);
            else
                ans = min(ans, calc_time(s, e, a, b));
        }
    }

    cout << ans << endl;

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// long long calc_time(int start, int end, vector<int> &a, vector<int> &b)
// {
//     long long result = 0;
//     for (int i = 0; i < a.size(); i++)
//     {

//         result += abs(start - a[i]);
//         result += abs(b[i] - a[i]);
//         result += abs(end - b[i]);
//     }

//     return result;
// }

// int main()
// {
//     int n;
//     cin >> n;
//     vector<int> a(n), b(n);

//     long long ans = 0;

//     for (int i = 0; i < n; i++)
//         cin >> a[i] >> b[i];

//     for (int s : a)
//     {
//         for (int e : b)
//         {
//             if (!ans)

//                 ans = calc_time(s, e, a, b);
//             else
//                 ans = min(ans, calc_time(s, e, a, b));
//         }
//     }

//     cout << ans << endl;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// long long calc_moving_time(int start, int end, vector<int> &a, vector<int> &b)
// {
//     long long result = 0;
//     for (int i = 0; i < a.size(); i++)
//     {
//         result += abs(a[i] - start);
//         result += abs(b[i] - a[i]);
//         result += abs(end - b[i]);
//     }

//     return result;
// }

// int main()
// {
//     int n;
//     cin >> n;
//     long long ans = 0;

//     vector<int> a(n), b(n);
//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i] >> b[i];
//     }

//     vector<int> ab(a.begin(), a.end());
//     ab.insert(ab.end(), b.begin(), b.end());

//     for (int i = 0; i < ab.size(); i++)
//     {
//         for (int j = 0; j < ab.size(); j++)
//         {
//             int start = ab[i];
//             int end = ab[j];

//             if (!ans)
//                 ans = calc_moving_time(start, end, a, b);
//             else
//                 ans = min(ans, calc_moving_time(start, end, a, b));
//         }
//     }

//     cout << ans << endl;

//     return 0;
// }