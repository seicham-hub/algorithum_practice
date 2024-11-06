// https://atcoder.jp/contests/abc360/tasks/abc360_c

// 2024_11_1もう一度

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n), w(n);

    vector<vector<int>> box(n);

    rep(i, n)
    {
        cin >> a[i];
        a[i]--;
    }
    rep(i, n) cin >> w[i];

    rep(i, n)
    {
        box[a[i]].push_back(w[i]);
    }

    int ans = 0;

    rep(i, n)
    {
        if (box[i].size() <= 1)
            continue;
        sort(box[i].begin(), box[i].end());
        rep(j, box[i].size() - 1)
        {
            ans += box[i][j];
        }
    }

    cout << ans << endl;

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)
// using ll = long long;

// int main()
// {
//     int n;
//     cin >> n;

//     vector<int> a(n), w(n);

//     rep(i, n)
//     {
//         cin >> a[i];
//         a[i]--;
//     }
//     rep(i, n) cin >> w[i];

//     vector<vector<int>> box(n);

//     rep(i, n) box[a[i]].push_back(w[i]);
//     int ans = 0;

//     rep(i, n)
//     {
//         if (box[i].size() == 0)
//             continue;

//         sort(box[i].begin(), box[i].end());
//         rep(j, box[i].size() - 1) ans += box[i][j];
//     }

//     cout << ans << endl;

//     return 0;
// }

// 自分で書いたコード　冗長すぎる
// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)
// using ll = long long;

// int main()
// {
//     int n;
//     cin >> n;

//     vector<int> a(n), w(n);
//     set<int> st;
//     rep(i, n) st.insert(i);

//     rep(i, n)
//     {
//         cin >> a[i];
//         a[i]--;
//         st.erase(a[i]);
//     }
//     rep(i, n) cin >> w[i];

//     map<int, vector<int>> count;

//     vector<int> candidate;

//     rep(i, n)
//     {
//         count[a[i]].push_back(w[i]);
//     }

//     for (auto &vec : count)
//     {
//         sort(vec.second.begin(), vec.second.end());
//         for (int i = 0; i < vec.second.size() - 1; i++)
//         {
//             candidate.push_back(vec.second[i]);
//         }
//     }

//     sort(candidate.begin(), candidate.end());

//     ll ans = 0;
//     int remain = st.size();
//     for (int i = 0; i < remain; i++)
//     {
//         ans += candidate[i];
//     }

//     cout << ans << endl;

//     return 0;
// }