#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, result = 0;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int keta = 0;
        int j = i;
        while (j > 0)
        {
            keta++;
            j = j / 10;
        }

        if (keta % 2 == 1)
            result++;
    }
    cout << result << endl;

    return 0;
}
