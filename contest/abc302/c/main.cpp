// 0521もう一度

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    string s[10], ans = "No";

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    vector<int> indices(n);
    iota(indices.begin(), indices.end(), 0);

    do
    {
        bool ok = true;
        for (int i = 0; i < n - 1; i++)
        {
            string now = s[indices[i]];
            string next = s[indices[i + 1]];
            int cnt = 0;

            for (int j = 0; j < m; j++)
            {
                if (now[j] != next[j])
                    cnt++;
            }

            if (cnt != 1)
                ok = false;
        }

        if (ok)
            ans = "Yes";

    } while (next_permutation(indices.begin(), indices.end()));

    cout << ans << endl;

    return 0;
}