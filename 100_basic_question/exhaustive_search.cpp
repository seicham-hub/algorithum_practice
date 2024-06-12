// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_A&lang=ja

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];

    int q;
    cin >> q;
    vector<int> m(q);

    for (int i = 0; i < q; i++)
        cin >> m[i];

    set<int> score;

    for (int msk = 0; msk < (1 << n); msk++)
    {
        int point = 0;
        for (int i = 0; i < n; i++)
        {
            if (msk & (1 << i))
                point += A[i];
        }
        score.insert(point);
    }

    for (int mi : m)
    {

        if (score.count(mi))
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }

    return 0;
}