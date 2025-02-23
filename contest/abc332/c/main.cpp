// https://atcoder.jp/contests/abc332/tasks/abc332_c

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n, m;
    string s;
    cin >> n >> m >> s;

    rep(i, 1001)
    {

        int tmpM = m;
        int tmpR = i;
        bool isSuc = true;

        rep(j, n)
        {

            if (s[j] == '0')
            {
                tmpM = m;
                tmpR = i;
            }

            if (s[j] == '1')
            {
                if (tmpM > 0)
                    tmpM--;
                else if (tmpR > 0)
                    tmpR--;
                else
                {
                    isSuc = false;
                    break;
                }
            }

            if (s[j] == '2')
            {

                if (tmpR > 0)
                    tmpR--;
                else
                {
                    isSuc = false;
                    break;
                }
            }
        }

        if (isSuc)
        {
            cout << i << endl;
            return 0;
        }
    }

    return 0;
}