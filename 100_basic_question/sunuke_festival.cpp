// https://atcoder.jp/contests/abc077/tasks/arc084_a
// TLEになることはわかっていたが、どうしたらよいか分からなかった

// 2024_06_19もう一度
// 2024_06_20もう一度

#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;

    long long ans = 0;

    vector<int> a(n), b(n), c(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (int i = 0; i < n; i++)
        cin >> c[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    for (int bi : b)
    {
        long long a_ind = lower_bound(a.begin(), a.end(), bi) - a.begin();

        int c_ind = upper_bound(c.begin(), c.end(), bi) - c.begin();
        long long c_count = n - c_ind;

        ans += a_ind * c_count;
    }

    cout << ans << endl;

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n;
//     cin >> n;
//     long long ans = 0;

//     vector<int> a(n), b(n), c(n);
//     for (int i = 0; i < n; i++)
//         cin >> a[i];
//     for (int i = 0; i < n; i++)
//         cin >> b[i];
//     for (int i = 0; i < n; i++)
//         cin >> c[i];

//     sort(a.begin(), a.end());
//     sort(b.begin(), b.end());
//     sort(c.begin(), c.end());

//     for (int bi : b)
//     {
//         int a_ind = lower_bound(a.begin(), a.end(), bi) - a.begin();
//         long long a_count = a_ind;

//         int c_ind = upper_bound(c.begin(), c.end(), bi) - c.begin();
//         long long c_count = n - c_ind;

//         ans += a_count * c_count;
//     }

//     cout << ans << endl;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n;
//     cin >> n;

//     long long ans = 0;

//     vector<int> a(n), b(n), c(n);
//     for (int i = 0; i < n; i++)
//         cin >> a[i];
//     for (int i = 0; i < n; i++)
//         cin >> b[i];
//     for (int i = 0; i < n; i++)
//         cin >> c[i];

//     sort(a.begin(), a.end());
//     sort(b.begin(), b.end());
//     sort(c.begin(), c.end());

//     for (int ai : a)

//     {
//         int ind = upper_bound(b.begin(), b.end(), ai) - b.begin();
//         for (int i = ind; i < n; i++)
//         {
//             int ind = upper_bound(c.begin(), c.end(), b[i]) - c.begin();
//             int count = n - ind;
//             ans += count;
//         }
//     }

//     cout << ans << endl;

//     return 0;
// }