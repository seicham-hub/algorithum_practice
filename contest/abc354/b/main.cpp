#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int n;
    cin >> n;

    vector<string> s(n);
    vector<int> c(n);

    int total = 0;

    rep(i, n)
    {
        cin >> s[i] >> c[i];
        total += c[i];
    }

    sort(s.begin(), s.end());
    int ind = total % n;

    cout << s[ind] << endl;

    return 0;
}