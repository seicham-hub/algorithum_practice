#include <bits/stdc++.h>
using namespace std;

int main()
{
    // ooooooooはダメ
    int n, ans = -1;
    string s;
    cin >> n >> s;

    for (int i = 0; i < n;)
    {

        int tmp_max = -1;

        while (s[i] == 'o')
        {
            if (tmp_max == -1)
                tmp_max += 2;
            else
                tmp_max++;
            i++;
        }

        ans = max(ans, tmp_max);

        if (tmp_max == -1)
            i++;
    }
    if (ans == s.size())
        cout << -1 << endl;
    else
        cout << ans << endl;

    return 0;
}
