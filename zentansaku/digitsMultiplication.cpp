// https://atcoder.jp/contests/abc057/tasks/abc057_c
// 0414もう一度
#include <bits/stdc++.h>
using namespace std;

int countKeta(long long int num)
{

    string numStr = to_string(num);
    return numStr.size();
}

int main()
{
    long long int n;
    int minKeta = 20;
    cin >> n;

    for (long long int i = 1; i * i <= n; i++)
    {
        int a = i;
        if (n % a != 0)
            continue;
        int b = n / a;
        int curKeta = max(countKeta(a), countKeta(b));

        minKeta = min(curKeta, minKeta);
    }

    cout << minKeta << endl;

    return 0;
}
