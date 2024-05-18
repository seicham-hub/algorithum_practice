// https://atcoder.jp/contests/abc145/tasks/abc145_c
// 0420もう一度
// 0421もう一度

// double型の精度は約15桁,floatは6か7桁
// 最初に要素を昇順に並べておき、do - while ループで、next_permutation() がfalse を返すまでループすると、 全順列が生成されることになる。

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }

    vector<int> indices;
    for (int i = 0; i < n; i++)
        indices.push_back(i);

    double dist_total = 0;
    double permutation_count = 0;

    do
    {

        double dist = 0;
        for (int j = 1; j < indices.size(); j++)
        {

            int before_index = indices[j - 1];
            int index = indices[j];
            int xi = x[before_index];
            int yi = y[before_index];
            int xj = x[index];
            int yj = y[index];

            dist += sqrt(pow(xi - xj, 2) + pow(yi - yj, 2));
        }
        dist_total += dist;
        permutation_count++;

    } while (next_permutation(indices.begin(), indices.end()));

    printf("%.10f\n", dist_total / permutation_count);
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n;
//     cin >> n;

//     vector<int> x(n), y(n);

//     for (int i = 0; i < n; i++)
//     {
//         cin >> x[i] >> y[i];
//     }

//     vector<int> indices(n);
//     for (int i = 0; i < n; i++)
//         indices[i] = i;

//     double dist_sum = 0;
//     double division_num = 0;

//     do
//     {
//         double dist = 0;
//         for (int j = 1; j < indices.size(); j++)
//         {
//             int index = indices[j];
//             int i = indices[j - 1];
//             int xi = x[i];
//             int yi = y[i];
//             int xj = x[index];
//             int yj = y[index];

//             dist += pow(pow(xi - xj, 2) + pow(yi - yj, 2), 0.5);
//         }
//         dist_sum += dist;
//         division_num++;

//     } while (next_permutation(indices.begin(), indices.end()));

//     printf("%.10f\n", dist_sum / division_num);

//     return 0;
// }

/*
0425解きなおし
*/

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n, x[10], y[10];
//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> x[i] >> y[i];
//     }

//     vector<int> indices(n);
//     iota(indices.begin(), indices.end(), 0);
//     double total_distance = 0, cnt = 0;

//     do
//     {
//         double tmp_distance = 0;
//         for (int i = 0; i < n - 1; i++)
//         {
//             int now = indices[i], next = indices[i + 1];
//             tmp_distance += sqrt(pow(x[next] - x[now], 2) + pow(y[next] - y[now], 2));
//         }
//         total_distance += tmp_distance;
//         cnt++;

//     } while (next_permutation(indices.begin(), indices.end()));

//     // printf("%.10f\n", total_distance / cnt);
//     cout << fixed << setprecision(10) << total_distance / cnt << endl;
//     return 0;
// }

/*
0424解きなおし
*/
// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n, x[10], y[10];

//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> x[i] >> y[i];
//     }

//     vector<int> indices(n);
//     iota(indices.begin(), indices.end(), 0);
//     double cnt = 0, total_distance = 0;
//     do
//     {
//         double tmp_distance = 0;
//         for (int i = 0; i < n - 1; i++)
//         {
//             int now = indices[i], next = indices[i + 1];

//             tmp_distance += sqrt(pow(x[next] - x[now], 2) + pow(y[next] - y[now], 2));
//         }
//         cnt++;
//         total_distance += tmp_distance;
//     } while (next_permutation(indices.begin(), indices.end()));

//     printf("%.10f\n", total_distance / cnt);

//     return 0;

//     // cout <<  fixed << setprecision(10) <<total_distance/cnt <<endl;
// }

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n, x[10], y[10];

//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> x[i] >> y[i];
//     }

//     vector<int> indices(n);
//     iota(indices.begin(), indices.end(), 0);

//     double total_distance = 0;
//     int cnt = 0;
//     do
//     {
//         double tmp_distance = 0;
//         for (int i = 0; i < n - 1; i++)
//         {
//             int now = indices[i];
//             int next = indices[i + 1];
//             tmp_distance += sqrt(pow(x[next] - x[now], 2) + pow(y[next] - y[now], 2));
//         }

//         total_distance += tmp_distance;
//         cnt++;

//     } while (next_permutation(indices.begin(), indices.end()));

//     printf("%.10f\n", total_distance / cnt);

//     // cout << fixed << setprecision(10) << total_distance / cnt << endl;

//     return 0;
// }

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
