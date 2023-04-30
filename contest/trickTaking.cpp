#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n, ans = 0, ans2 = 0;
    long long int t, c[250000], r[250000], max2 = 0, iroAtaiMax = 0;
    cin >> n >> t;
    for (int i = 0; i < n; i++)
        cin >> c[i];
    for (int i = 0; i < n; i++)
        cin >> r[i];

    for (int i = 0; i < n; i++)
    {

        if (c[i] == t)
        {
            if (r[i] > iroAtaiMax)
            {
                iroAtaiMax = r[i];
                ans = i + 1;
            }
        }

        if (c[i] == c[0])
        {
            if (r[i] > max2)
            {
                max2 = r[i];
                ans2 = i + 1;
            }
        }
    }

    if (iroAtaiMax)
        cout << ans << endl;
    else
        cout << ans2 << endl;

    return 0;
}
