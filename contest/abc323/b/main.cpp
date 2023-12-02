#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

bool check(pair<int, int> a, pair<int, int> b)
{

    if (a.first == b.first)
    {
        return a.second < b.second;
    }

    return a.first > b.first;
}

int main()
{
    int n;
    cin >> n;

    vector<string> s(n);

    rep(i, n)
    {

        cin >> s[i];
    }

    // ポイント、プレイヤー番号の順
    vector<pair<int, int>> p_and_play(n);

    rep(i, n)
    {
        int p_num = i + 1;
        int point = 0;
        rep(j, n)
        {
            if (s[i][j] == 'o')
                point++;
        }

        p_and_play[i] = {point, p_num};
    }

    sort(p_and_play.begin(), p_and_play.end(), check);

    rep(i, n - 1)
    {
        cout << p_and_play[i].second << " ";
    }
    cout << p_and_play.back().second << endl;

    return 0;
}