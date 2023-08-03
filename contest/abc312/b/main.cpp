

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

vector<string> s;

bool check(int i, int j)
{
    // 左上の黒チェック
    rep(k, 3)
    {
        rep(l, 3)
        {
            if (s[i + k][j + l] != '#')
                return false;
        }
    }

    // 右下黒のチェック
    for (int k = 6; k < 9; k++)
    {
        for (int l = 6; l < 9; l++)
        {
            if (s[i + k][j + l] != '#')
                return false;
        }
    }

    // 左上白のチェック
    for (int k = 0; k < 4; k++)
    {
        if (s[i + k][j + 3] != '.')
            return false;
    }
    for (int k = 0; k < 4; k++)
    {
        if (s[i + 3][j + k] != '.')
            return false;
    }
    // 右下白のチェック
    for (int k = 5; k < 9; k++)
    {
        if (s[i + k][j + 5] != '.')
            return false;
    }
    for (int k = 5; k < 9; k++)
    {
        if (s[i + 5][j + k] != '.')
            return false;
    }

    return true;
}

int main()
{
    int n, m;
    cin >> n >> m;

    s.resize(n);

    rep(i, n)
    {
        cin >> s[i];
    }

    rep(i, n)
    {
        rep(j, m)
        {
            if (n - i >= 9 && m - j >= 9)
            {
                if (check(i, j))
                    cout << i + 1 << " " << j + 1 << endl;
            }
        }
    }

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// int main()
// {
//     int n, m;
//     cin >> n >> m;

//     vector<string> s(n);

//     rep(i, n)
//     {
//         cin >> s[i];
//     }

//     rep(i, n)
//     {
//         rep(j, m)
//         {
//             if (n - i >= 9 && m - j >= 9)
//             {

//                 bool bl1 = true;
//                 rep(k, 3)
//                 {
//                     rep(l, 3)
//                     {
//                         if (s[i + k][j + l] != '#')
//                             bl1 = false;
//                         if (s[i + 6 + k][j + 6 + l] != '#')
//                             bl1 = false;
//                     }
//                 }

//                 bool whi1 = true;

//                 rep(k, 4)
//                 {
//                     if (s[i + k][j + 3] != '.')
//                         whi1 = false;

//                     if (s[i + 5 + k][j + 5] != '.')
//                         whi1 = false;
//                 }
//                 rep(k, 3)
//                 {
//                     if (s[i + 3][j + k] != '.')
//                         whi1 = false;
//                     if (s[i + 5][j + 6 + k] != '.')
//                         whi1 = false;
//                 }

//                 if (bl1 && whi1)
//                 {
//                     cout << i + 1 << " " << j + 1 << endl;
//                 }
//             }
//         }
//     }

//     return 0;
// }