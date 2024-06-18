// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n, ans = 0;
//     cin >> n;

//     vector<int> s(n);
//     for (int i = 0; i < n; i++)
//         cin >> s[i];

//     int q;
//     cin >> q;
//     vector<int> t(q);
//     for (int i = 0; i < q; i++)
//         cin >> t[i];

//     for (int ti : t)
//         if (binary_search(s.begin(), s.end(), ti))
//             ans++;

//     cout << ans << endl;
// }

#include <bits/stdc++.h>
using namespace std;

bool search(int &target, vector<int> &s)
{
    // 端っこが条件満たす場合もあるので
    int left = -1;
    int right = s.size();

    while (abs(left - right) > 1)
    {
        int mid = (left + right) / 2;
        if (s[mid] <= target)
            left = mid;
        else
            right = mid;
    }
    return s[left] == target;
}

int main()
{
    int n, ans = 0;
    cin >> n;

    vector<int> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];

    int q;
    cin >> q;
    vector<int> t(q);
    for (int i = 0; i < q; i++)
        cin >> t[i];

    for (int ti : t)
    {
        if (search(ti, s))
            ans++;
    }
    cout << ans << endl;

    return 0;
}