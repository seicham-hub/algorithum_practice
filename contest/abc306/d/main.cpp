
// 0619もプ一度

// 本番のコード

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// int main()
// {
//     int n;
//     cin >> n;

//     vector<int> x(n);
//     vector<long long> y(n);

//     rep(i, n)
//     {
//         cin >> x[i] >> y[i];
//     }

//     int status = 0;
//     bool poipu = false;
//     bool sickpu = false;
//     long long poiM = 0;
//     long long sickD = 0;
//     long long ans = 0;

//     rep(i, n)
//     {
//         if (x[i] == 0 && y[i] >= 0)
//         {
//             ans += y[i];
//             continue;
//         }
//         if (x[i] == 1 && y[i] < 0)
//         {
//             continue;
//         }

//         if (sickpu)
//         {
//             if (y[i] > sickD || i == n - 1)
//             {

//                 ans -= sickD;
//                 status = 0;
//                 sickD = 0;
//                 sickpu = false;
//             }
//         }

//         if (poipu && x[i] == 0)
//         {
//             if (poiM > abs(y[i]) || i == n)
//             {
//                 ans += poiM + y[i];
//                 status = 0;
//             }
//             else
//             {
//                 status = 1;
//             }

//             poiM = 0;
//             poipu = false;

//             continue;
//         }

//         if (status == 0)
//         {

//             if (x[i] == 1 && y[i] > 0)
//             {
//                 poipu = true;
//                 poiM = max(y[i], poiM);
//             }
//         }
//         else if (status == 1)
//         {
//             if (x[i] == 0 && y[i] < 0)
//             {
//                 sickD = abs(y[i]);
//                 sickpu = true;
//             }
//         }
//     }

//     cout << ans << endl;

//     return 0;
// }