// https://atcoder.jp/contests/abc120/tasks/abc120_b

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, k;
    cin >> a >> b >> k;

    vector<int> candidate;
    for (int i = 1; i <= max(a, b); i++)
    {
        if (a % i == 0 && b % i == 0)
        {
            candidate.push_back(i);
        }
    }

    reverse(candidate.begin(), candidate.end());
    cout << candidate[k - 1] << endl;

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int A, B, K;
//     vector<int> integers;
//     cin >> A >> B >> K;

//     for (int i = 1; i <= min(A, B); i++)
//     {
//         if (A % i == 0 && B % i == 0)
//             integers.push_back(i);
//     }

//     // 前から数えると全体-(k-1)番目、indexなのでさらに-1
//     cout << integers[integers.size() - K] << endl;

//     return 0;
// }
