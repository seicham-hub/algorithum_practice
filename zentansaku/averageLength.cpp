// https://atcoder.jp/contests/abc145/tasks/abc145_c
// 0420もう一度
// 0421もう一度

// 最初に要素を昇順に並べておき、do - while ループで、next_permutation() がfalse を返すまでループすると、 全順列が生成されることになる。

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x[10], y[10];

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }

    vector<int> indices(n);
    iota(indices.begin(), indices.end(), 0);

    double total_distance = 0;
    int cnt = 0;
    do
    {
        double tmp_distance = 0;
        for (int i = 0; i < n - 1; i++)
        {
            int now = indices[i];
            int next = indices[i + 1];
            tmp_distance += sqrt(pow(x[next] - x[now], 2) + pow(y[next] - y[now], 2));
        }

        total_distance += tmp_distance;
        cnt++;

    } while (next_permutation(indices.begin(), indices.end()));

    printf("%.10f\n", total_distance / cnt);

    // cout << fixed << setprecision(10) << total_distance / cnt << endl;

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n, cnt = 0;
//     cin >> n;
//     double totalDistance = 0;
//     vector<int> x(n), y(n), indices(n);

//     for (int i = 0; i < n; i++)
//     {
//         cin >> x[i] >> y[i];
//     }

//     iota(indices.begin(), indices.end(), 0);

//     do
//     {
//         double distance = 0;
//         for (int i = 0; i < n - 1; i++)
//         {
//             int now = indices[i], next = indices[i + 1];

//             distance += sqrt(pow(x[next] - x[now], 2) + pow(y[next] - y[now], 2));
//         }
//         totalDistance += distance;
//         cnt++;
//     } while (next_permutation(indices.begin(), indices.end()));

//     printf("%.10f\n", totalDistance / cnt);
//     return 0;
// }

/*
    chatgptの解答
*/

// #include <bits/stdc++.h>
// using namespace std;

// double distance(int x1, int y1, int x2, int y2)
// {
//     return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
// }

// int main()
// {
//     int N;
//     cin >> N;
//     vector<int> x(N), y(N);
//     for (int i = 0; i < N; i++)
//     {
//         cin >> x[i] >> y[i];
//     }

//     vector<int> indices(N);
//     iota(indices.begin(), indices.end(), 0);

//     double totalDistance = 0;
//     int cnt = 0;

//     do
//     {
//         double pathDistance = 0;
//         for (int i = 0; i < N - 1; i++)
//         {
//             int a = indices[i], b = indices[i + 1];
//             pathDistance += distance(x[a], y[a], x[b], y[b]);
//         }
//         totalDistance += pathDistance;
//         cnt++;
//     } while (next_permutation(indices.begin(), indices.end()));

//     double avgDistance = totalDistance / cnt;
//     cout << fixed << setprecision(10) << avgDistance << endl;

//     return 0;
// }

/*
4/20自分で解いたコード
さっぱりだった

*/

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n, x[10], y[10];
//     map<int, bool> m;
//     double avg;

//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> x[i] >> y[i];
//     }

//     int count = 0;

//     while (count < 8)
//     {

//         int beforeX = 0;
//         int beforeY = 0;
//         for (int i = 0; i < n;i++)
//         {

//             if (i = 0)
//             {
//                 beforeX = x[i];
//                 beforeY = y[i];
//                 m[i] = true;
//                 continue;
//             }

//             double tmpDistance = pow(pow(x[i] - beforeX, 2) + pow(y[i] - beforeY, 2), 1 / 2);

//             beforeX = x[i];
//             beforeY = y[i];
//             m[i] = true;
//         }

//         count++;
//     }

//     return 0;
// }
