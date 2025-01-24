// https://atcoder.jp/contests/abc352/tasks/abc352_d

// 分からなかった...
// 2025_01_15もう一度
// 2025_01_25もう一度

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> p(n);
    map<int, int> vtoind;

    rep(i, n)
    {
        cin >> p[i];
        p[i]--;
        vtoind[p[i]] = i;
    }

    set<int> st;
    int ans = n;

    rep(i, n)
    {
        st.insert(vtoind[i]);
        if (st.size() == k)
        {
            auto last = st.end();
            last--;
            auto start = st.begin();

            int now = *last - *start;
            ans = min(ans, now);

            st.erase(vtoind[i - k + 1]);
        }
    }
    cout << ans << endl;

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// int main()
// {
//     int n, k;
//     cin >> n >> k;

//     vector<int> p(n);
//     rep(i, n)
//     {
//         cin >> p[i];
//         p[i]--;
//     }

//     vector<int> q(n);
//     rep(i, n) q[p[i]] = i;

//     set<int> st;
//     int ans = n;
//     rep(i, n)
//     {
//         st.insert(q[i]);
//         if (st.size() == k)
//         {
//             int now = *st.rbegin() - *st.begin();

//             ans = min(ans, now);
//             st.erase(q[i - k + 1]);
//         }
//     }

//     cout << ans << endl;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// int main()
// {
//     int n, k;
//     cin >> n >> k;

//     vector<int> p(n);
//     rep(i, n) cin >> p[i];
//     rep(i, n) p[i]--;

//     vector<int> q(n);
//     rep(i, n) q[p[i]] = i;

//     set<int> st;

//     int ans = n;
//     rep(i, n)
//     {
//         st.insert(q[i]);
//         if (st.size() > k)
//             st.erase(q[i - k]);

//         if (st.size() == k)
//         {
//             int now = *st.rbegin() - *st.begin();
//             ans = min(ans, now);
//         }
//     }

//     cout << ans << endl;

//     return 0;
// }