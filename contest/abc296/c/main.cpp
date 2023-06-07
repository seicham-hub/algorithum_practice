// https://atcoder.jp/contests/abc296/tasks/abc296_c
// 線形時間で無理やり終わらせよう。やはり間に合わなかった

// 0603もう一度

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    long long a[101];
    string s[11];

    int ind = 0;
    int min = 500;

    for (int i = 0; i < n; i++)
    {
        cin >> s[i] >> a[i];
        if (a[i] < min)
        {
            min = a[i];
            ind = i;
        }
    }

    for (int i = ind; i < ind + n; i++)
    {
        cout << s[ind % n] << endl;
    }

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n, x;
//     cin >> n >> x;

//     set<int> s;

//     for (int i = 0; i < n; i++)
//     {
//         int t;
//         cin >> t;
//         s.insert(t);
//     }

//     for (auto a : s)
//     {
//         if (s.find(a + x) != s.end())
//         {
//             cout << "Yes" << endl;
//             return 0;
//         }
//     }

//     cout << "No" << endl;
//     return 0;
// }

// 本番でのコード
// #include <bits/stdc++.h>
// using namespace std;

// long long int n, x;
// vector<long long> a;
// bool ans = false;

// bool check(int base)
// {

//     for (int i = base; i <= n - 1; i++)
//     {
//         if (abs(a[base] - a[i]) == x)
//         {
//             return true;
//         }
//     }

//     return false;
// }

// int main()
// {

//     cin >> n >> x;

//     if (x == 0)
//     {
//         cout << "Yes" << endl;
//         return 0;
//     }

//     a.resize(n);
//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }

//     sort(a.begin(), a.end(), greater<long long>());

//     for (int i = 0; i < n - 1; i++)
//     {
//         // cout << a[i] << endl;
//         if (x >= abs(a[i] - a[i + 1]))
//         {
//             ans = check(i) | ans;
//         }
//     }

//     if (ans)
//         cout << "Yes" << endl;
//     else
//         cout << "No" << endl;

//     return 0;
// }
