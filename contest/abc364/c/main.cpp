#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

using P = pair<int, int>;
using ll = long long;

int main()
{
    ll n, x, y;
    cin >> n >> x >> y;

    vector<P> dish(n);

    rep(i, n)
    {
        cin >> dish[i].first;
    }
    rep(i, n)
    {
        cin >> dish[i].second;
    }

    vector<P> dish_b = dish;

    auto compare = [&](P a, P b)
    {
        return a.first > b.first;
    };
    sort(dish.begin(), dish.end(), compare);

    auto compare_b = [&](P a, P b)
    {
        return a.second > b.second;
    };
    sort(dish_b.begin(), dish_b.end(), compare_b);

    ll sweet = 0, solt = 0;
    ll ans_a = 0, ans_b = 0;
    rep(i, n)
    {
        sweet += dish[i].first;
        ans_a++;
        if (sweet > x)
            break;
    }
    rep(i, n)
    {
        solt += dish_b[i].second;
        ans_b++;
        if (solt > y)
            break;
    }

    cout << min(ans_a, ans_b) << endl;

    return 0;
}