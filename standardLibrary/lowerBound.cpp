// N個の整数Aから成る数列に対して、以下の条件を満たす(i, j)のペアの総数を求めよ。

// i ≠ j
// L ≤ A[i] + A[j] ≤ R

#include <bits/stdc++.h>
using namespace std;

long long N, L, R, A[1000009];

int main()
{
    scanf("%lld%lld%lld", &N, &L, &R);

    for (int i = 1; i <= N; i++)
        scanf("%lld", &A[i]);

    // 解法：まずAを小さい順にソートする
    sort(A + 1, A + N + 1);

    // 解法：iを全探索すると、jの値は一つの区間になり、これは二分探索によって決まる。

    long long ans = 0;
    for (int i = 1; i < N; i++)
    {
        int left_j = lower_bound(A + 1, A + N + 1, L - A[i]) - A;
        int right_j = lower_bound(A + 1, A + N + 1, R + 1LL - A[i]) - A;

        ans += 1LL * (right_j - left_j);
    }

    cout << ans << endl;

    return 0;
}
