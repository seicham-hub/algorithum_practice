#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

long long ans = 0;

void dfs(int i, string s)
{

    if (i == s.size() - 1)
    {
    }

    if (s[i] == '?')
    {
        s[i] = ')';
        dfs(i + 1, s);
        s[i] = '(';
        dfs(i + 1, s);

        s[i] = '?';
    }
}

int main()
{

    string s;

    cin >> s;

    dfs(0, s);

    return 0;
}