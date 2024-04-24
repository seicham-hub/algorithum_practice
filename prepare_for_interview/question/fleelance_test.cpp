// 勇者が毎ターン魔王に攻撃するときに、勇者は魔王を倒すことができるか？
// 倒せる場合は"YES"かつ倒すのに必要なターン数、倒せない場合は"NO"を出力

// input: h a b
// condition: 0 < h,a,b <10^18
// 毎ターンは必ず勇者の攻撃→魔王回復の順に行われる。

#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long h, a, b;
    cin >> h >> a >> b;

    long long diff = a - b;

    // point:魔王の体力が勇者の攻撃力以下になった瞬間に魔王を倒すことができる
    h = h - a;

    // 初撃で倒せる場合
    if (h <= 0)
    {
        cout << "YES" << endl;
        cout << 1 << endl;
        return;
    }

    if (diff > 0)
    {

        long long count = h / diff + 1;
        long long remaining = h % diff;
        if (remaining > 0)
            count++;

        cout << "YES" << endl;
        cout << count << endl;
    }
    else
    {

        cout << "NO" << endl;
    }

    return 0;
}