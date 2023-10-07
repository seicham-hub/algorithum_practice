// https://atcoder.jp/contests/abc322/tasks/abc322_d

// 方針は思いついたが、保存するデータ構造が分からなかった
// 1006もう一度

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

void Print(const string &s)
{
    cout << s << endl;
    exit(0);
}

// 右に90度回転
void Rotate(vector<string> &v)
{
    vector<string> w = v;
    rep(i, 4) rrep(j, 4) w[]
}

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// int main()
// {
//     int n, m;
//     cin >> n >> m;

//     queue<int> q;

//     rep(i, m)
//     {
//         int a;
//         cin >> a;
//         a--;
//         q.push(a);
//     }

//     vector<int> ans(n);

//     rep(i, n)
//     {
//         int d = q.front();
//         ans[i] = d - i;
//         if (d - i == 0)
//             q.pop();
//     }

//     rep(i, n)
//     {

cout << ans[i] << endl;
}

return 0;
}