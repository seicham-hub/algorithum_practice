#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> a(m);

    // ポイント、番号の順
    vector<pair<int, int>> ab(m);
    rep(i, m)
    {
        cin >> a[i];
        ab[i] = {a[i], i};
    }

    vector<string> s(n);

    rep(i, n)
    {
        cin >> s[i];
    }

    vector<int> points(n);
    int maxP = 0;

    rep(i, n)
    {
        int point = i + 1;
        rep(j, m)
        {
            if (s[i][j] == 'o')
                point += a[j];
        }
        points[i] = point;
        maxP = max(point, maxP);
    }

    sort(ab.begin(), ab.end());
    reverse(ab.begin(), ab.end());

    rep(i, n)
    {
        int diff = maxP - points[i];
        int problem_remain_num = 0;

        if (diff == 0)
        {

            cout << 0 << endl;
            continue;
        }

        rep(j, m)
        {
            if (diff < 0)
                break;

            int bangou = ab[j].second;

            if (s[i][bangou] == 'x')
            {
                diff -= ab[j].first;
                problem_remain_num++;
            }
        }

        cout << problem_remain_num << endl;
    }

    return 0;
}