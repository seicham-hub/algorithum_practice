// https://atcoder.jp/contests/abc314/tasks/abc314_d
// 毎回forで回してたら終わらない..→最後にまとめてできないか？
// 0822もう一度

/*
自分の解答
*/

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// int main()
// {
//     int n, q;
//     string s;

//     cin >> n >> s >> q;

//     map<int, char> Chapital;
//     map<int, char> mini;

//     rep(i, n)
//     {
//         if ('A' <= s[i] && s[i] <= 'Z')
//             Chapital[i] = s[i] + 'a' - 'A';
//         else
//             mini[i] = s[i];
//     }

//     rep(i, q)
//     {
//         int t, x;
//         char c;
//         cin >> t >> x >> c;

//         x--;

//         switch (t)
//         {
//         case 1:
//             if (Chapital[x])
//                 Chapital[x] = c;
//             else if (mini[x])
//                 mini[x] = c;

//             break;
//         case 2:
//             mini.insert(Chapital.begin(), Chapital.end());
//             Chapital.clear();
//             break;
//         case 3:
//             Chapital.insert(mini.begin(), mini.end());
//             mini.clear();
//         }
//     }

//     string ans = "";

//     rep(i, n)
//     {
//         if (Chapital[i])
//         {
//             ans += Chapital[i] + 'A' - 'a';
//         }
//         else if (mini[i])
//         {
//             ans += mini[i];
//         }
//     }

//     cout << ans << endl;

//     return 0;
// }