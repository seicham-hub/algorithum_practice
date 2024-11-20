#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int n, k;
    cin >> n >> k;
    string s;

    cin >> s;

    int cnt = 0;
    int bend = 0, abegin = 0, aend = 0;
    rep(i, s.size())
    {

        if (s[i] == '1')
            cnt++;
        if (!abegin && cnt == k)
            abegin = i;
        while (s[i] == '1')
        {
            i++;
        }
        if (!bend && cnt == k - 1)
            bend = i;
        if (!aend && cnt == k)
            aend = i;
    }

    string mae = s.substr(0, bend);
    string insert = s.substr(abegin, aend - abegin);
    string usi = s.substr(bend, abegin - bend) + s.substr(aend);

    cout << mae + insert + usi << endl;

    return 0;
}