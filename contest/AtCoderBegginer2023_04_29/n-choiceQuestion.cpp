#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, a, b;
    cin >> n >> a >> b;

    int c[n + 1];

    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
        if (c[i] == a + b)
        {
            cout << i << endl;
            break;
        }
    }

    return 0;
}
