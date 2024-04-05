// 問題：queueを逆順に並べる

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

stack<int> reverse(queue<int> q)
{

    stack<int> res;
    while (!q.empty())
    {
        int e = q.front();
        res.push(e);
        q.pop();
    }

    return res;
}

int main()
{

    queue<int> q;

    rep(i, 10) q.push(rand() % 10);

    stack<int> ans = reverse(q);

    while (!ans.empty())
    {
        cout << ans.top() << endl;
        ans.pop();
    }
    return 0;
}