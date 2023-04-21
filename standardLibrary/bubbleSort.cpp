#include <bits/stdc++.h>
using namespace std;

int N, A[10000];

int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i];

    for (int j = 0; j < N; j++)
    {

        for (int i = 1; i <= N - 1; i++)
        {
            if (A[i] > A[i + 1])
                swap(A[i], A[i + 1]);
        }
    }

    // ソートされた配列を出力する
    for (int i = 1; i <= N; i++)
    {
        cout << A[i] << endl;
    }

    return 0;

    return 0;
}
