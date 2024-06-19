// https://atcoder.jp/contests/joi2009ho/tasks/joi2009ho_b
// 2024_06_19もう一度

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int d, n, m, ans = 0;
    cin >> d >> n >> m;

    vector<int> s(n);
    for (int i = 1; i < n; i++)
        cin >> s[i];
    s.push_back(d);
    sort(s.begin(), s.end());

    vector<int> deli(m);
    for (int i = 0; i < m; i++)
        cin >> deli[i];

    for (int dist : deli)
    {
        int ind = lower_bound(s.begin(), s.end(), dist) - s.begin();
        int tmp = s[ind] - dist;
        if (ind > 0)
            tmp = min(tmp, dist - s[ind - 1]);
        ans += tmp;
    }

    cout << ans << endl;

    return 0;
}
// #include <bits/stdc++.h>
// using namespace std;

// int calc_time(int &target, vector<int> &s)
// {
//     int left = -1;
//     int right = s.size();

//     while (abs(left - right) > 1)
//     {
//         int mid = (left + right) / 2;
//         if (s[mid] <= target)
//             left = mid;
//         else
//             right = mid;
//     }

//     return min(target - s[left], s[left + 1] - target);
// }

// int main()
// {
//     int d, n, m, ans = 0;
//     cin >> d >> n >> m;

//     vector<int> s(n);
//     for (int i = 1; i < n; i++)
//         cin >> s[i];
//     s.push_back(d);
//     sort(s.begin(), s.end());

//     vector<int> deli(m);
//     for (int i = 0; i < m; i++)
//         cin >> deli[i];

//     for (int dist : deli)
//     {
//         ans += calc_time(dist, s);
//     }
//     cout << ans << endl;

//     return 0;
// }