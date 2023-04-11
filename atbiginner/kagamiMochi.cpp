// 0411もう一度

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, count = 0, before = -9;

    vector<int> d;
    cin >> N;
    d.resize(N);
    for (int i = 0; i < N; i++)
        cin >> d[i];
    sort(d.begin(), d.end());

    for (int i = 0; i < N; i++)
    {
        if (before == d[i])
            continue;
        count++;
        before = d[i];
    }

    cout << count << endl;

    return 0;
}
