// https://atcoder.jp/contests/abc095/tasks/arc096_a
// 0414もう一度

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    // abピザの枚数を全探索
    int max_count = x > y ? x : y;

    int ans = 1e9;

    for (int ab_count = 0; ab_count <= 2 * max_count; ab_count += 2)
    {
        int a_count = (x - ab_count / 2) >= 0 ? x - ab_count / 2 : 0;
        int b_count = (y - ab_count / 2) >= 0 ? y - ab_count / 2 : 0;

        int price = a * a_count + b * b_count + c * ab_count;

        ans = min(ans, price);
    }

    cout << ans << endl;

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {

//     int a, b, c, x, y;
//     long long int minPrice = 1100000000;

//     cin >> a >> b >> c >> x >> y;

//     for (int i = 0; i <= max(x, y) * 2; i++)
//     {
//         int aAmount = x - (i / 2) < 0 ? 0 : x - (i / 2);
//         int bAmount = y - (i / 2) < 0 ? 0 : y - (i / 2);
//         long long int tmpPrice = a * aAmount + b * bAmount + i * c;

//         minPrice = min(tmpPrice, minPrice);
//     }

//     cout << minPrice << endl;

//     return 0;
// }

// 0414解答分
// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int A, B, C, X, Y;
//     cin >> A >> B >> C >> X >> Y;

//     long long int ans = 100000000000;

//     for (int ab = 0; ab <= max(X, Y) * 2; ab += 2)
//     {

//         int x = (X - ab / 2) > 0 ? (X - ab / 2) : 0;
//         int y = (Y - ab / 2) > 0 ? (Y - ab / 2) : 0;

//         long long int curPrice = A * x + B * y + C * ab;

//         ans = min(ans, curPrice);
//     }

//     cout << ans << endl;
// }

// 自分で書いたコード（解けなかった）

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int a, b, c, x, y;
//     long long int minPrice = 100000000000;
//     cin >> a >> b >> c >> x >> y;

//     for(int i=0;i<=x;i++){
//         for(int j=0;j<=y;j++){

//         }
//     }

//     // if ((a + b) / 2 > c)
//     // {
//     //     int abMaisu = min(x, y) * 2;

//     //     if (x < y)
//     //     {
//     //         y = y - x;
//     //         x = 0;
//     //     }
//     //     else
//     //     {
//     //         x = x - y;
//     //         y = 0;
//     //     }

//     //     minPrice = c * abMaisu + a * x + b * y;
//     // }
//     // else
//     // {
//     //     minPrice = a * x + b * y;
//     // }

//     cout << minPrice << endl;

//     return 0;
// }
