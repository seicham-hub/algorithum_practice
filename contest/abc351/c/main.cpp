#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{

    int n;
    cin >> n;

    vector<int> a(n), size;
    rep(i, n) cin >> a[i];

    rep(i, n)
    {
        int now = a[i];

        size.push_back(now);

        while (size.size() > 1 && size.back() == size[size.size() - 2])
        {

            int x = size.back();
            size.erase(size.end() - 1);
            size.erase(size.end() - 1);
            size.push_back(x + 1);
        }
    }

    cout << size.size() << endl;

    return 0;
}