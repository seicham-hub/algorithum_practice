// https://atcoder.jp/contests/abc368/submissions/me
// iteratorは要素と要素の間にあるものと理解すると良い
// 2024_09_14もう一度

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> cards(n);

    rep(i, n) cin >> cards[i];

    rotate(cards.begin(), cards.begin() + (n - k), cards.end());

    for (int a : cards)
        cout << a << " ";

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// int main()
// {
//     int n, k;
//     cin >> n >> k;

//     vector<int> cards(n);

//     rep(i, n) cin >> cards[i];

//     vector<int> move(cards.begin() + n - k, cards.end());
//     vector<int> reft(cards.begin(), cards.begin() + n - k);

//     vector<int> ans(move.begin(), move.end());

//     for (int m : move)
//         cout << m << " ";

//     for (int r : reft)
//         cout << r << " ";

//     return 0;
// }