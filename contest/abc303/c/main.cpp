
// https://atcoder.jp/contests/abc303/tasks/abc303_c
// 反省点：item[410000][410000]等は使えなかった　確保するメモリ領域がでかすぎる
// segmentation faultにならずに存在しない要素にアクセスしたときにfalseを返すのはmap
// 二つ以上の複数要素来た時はmap<tuple<int,int,string>,bool>等にしてあげればよい
// item一度使ったら無くなる仕様にしてなくてWA　めっちゃ簡単な事に気づかなかった...

// 0527もう一度 ok

/*
5/31やり直し分
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int n, m, h, k;
    map<pair<int, int>, bool> item;

    string s;

    cin >> n >> m >> h >> k >> s;

    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        item[{x, y}] = true;
    }

    pair<int, int> posi = {0, 0}, next;

    for (int i = 0; i < s.size(); i++)
    {
        h--;
        if (h < 0)
        {
            cout << "No" << endl;
            return 0;
        }

        if (s[i] == 'R')
        {
            next = {posi.first + dx[0], posi.second + dy[0]};
        }
        else if (s[i] == 'L')
        {

            next = {posi.first + dx[1], posi.second + dy[1]};
        }
        else if (s[i] == 'U')
        {

            next = {posi.first + dx[2], posi.second + dy[2]};
        }
        else if (s[i] == 'D')
        {

            next = {posi.first + dx[3], posi.second + dy[3]};
        }

        if (h < k && item[{next.first, next.second}])
        {
            item[{next.first, next.second}] = false;
            h = k;
        }
        posi = next;
    }

    cout << "Yes" << endl;

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     long long dx[4] = {0, 1, 0, -1};
//     long long dy[4] = {1, 0, -1, 0};
//     long long n, m, h, k;
//     string s;

//     cin >> n >> m >> h >> k >> s;

//     map<pair<long long, long long>, bool> item;

//     for (long long i = 0; i < m; i++)
//     {

//         long long ci, cj;
//         cin >> ci >> cj;
//         item[{ci, cj}] = true;
//     }

//     long long nox = 0;
//     long long noy = 0;

//     for (long long i = 0; i < n; i++)
//     {

//         h--;
//         if (h < 0)
//         {
//             cout << "No" << endl;
//             return 0;
//         }

//         long long nx, ny;

//         if (s[i] == 'R')
//         {
//             nx = nox + dx[1];
//             ny = noy + dy[1];
//         }
//         else if (s[i] == 'L')
//         {
//             nx = nox + dx[3];
//             ny = noy + dy[3];
//         }
//         else if (s[i] == 'U')
//         {
//             nx = nox + dx[0];
//             ny = noy + dy[0];
//         }
//         else if (s[i] == 'D')
//         {
//             nx = nox + dx[2];
//             ny = noy + dy[2];
//         }

//         if (item[{nx, ny}] && h < k)
//         {
//             h = k;
//             item[{nx, ny}] = false;
//         }
//         nox = nx;
//         noy = ny;
//     }

//     cout << "Yes" << endl;
//     return 0;
// }

// 本番のコード

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     long long dx[4] = {0, 1, 0, -1};
//     long long dy[4] = {1, 0, -1, 0};
//     long long n, m, h, k;
//     string s;

//     cin >> n >> m >> h >> k >> s;

//     map<pair<long long, long long>, bool> item;

//     for (long long i = 0; i < m; i++)
//     {

//         long long ci, cj;
//         cin >> ci >> cj;
//         item[{ci, cj}] = true;
//     }

//     long long nox = 0;
//     long long noy = 0;

//     for (long long i = 0; i < n; i++)
//     {

//         h--;
//         if (h < 0)
//         {
//             cout << "No" << endl;
//             return 0;
//         }
//         if (s[i] == 'R')
//         {

//             long long nx = nox + dx[1];
//             long long ny = noy + dy[1];

//             if (item[{nx, ny}] && h < k)
//             {
//                 h = k;
//                 item[{nx, ny}] = false;
//             }
//             nox = nx;
//             noy = ny;
//         }
//         else if (s[i] == 'L')
//         {
//             long long nx = nox + dx[3];
//             long long ny = noy + dy[3];

//             if (item[{nx, ny}] && h < k)
//             {
//                 h = k;
//                 item[{nx, ny}] = false;
//             }
//             nox = nx;
//             noy = ny;
//         }
//         else if (s[i] == 'U')
//         {
//             long long nx = nox + dx[0];
//             long long ny = noy + dy[0];

//             if (item[{nx, ny}] && h < k)
//             {
//                 h = k;
//                 item[{nx, ny}] = false;
//             }
//             nox = nx;
//             noy = ny;
//         }
//         else if (s[i] == 'D')
//         {
//             long long nx = nox + dx[2];
//             long long ny = noy + dy[2];

//             if (item[{nx, ny}] && h < k)
//             {
//                 h = k;
//                 item[{nx, ny}] = false;
//             }
//             nox = nx;
//             noy = ny;
//         }
//     }

//     cout << "Yes" << endl;
//     return 0;
// }