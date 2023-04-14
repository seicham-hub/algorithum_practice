// https://atcoder.jp/contests/abc120/tasks/abc120_b

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A, B, K;
    vector<int> integers;
    cin >> A >> B >> K;

    for (int i = 1; i <= min(A, B); i++)
    {
        if (A % i == 0 && B % i == 0)
            integers.push_back(i);
    }

    // 前から数えると全体-(k-1)番目、indexなのでさらに-1
    cout << integers[integers.size() - K] << endl;

    return 0;
}
