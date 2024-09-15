// https://atcoder.jp/contests/abc371/tasks/abc371_a
// 2024_09_16もう一度

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
    char ab, ac, bc;
    cin >> ab >> ac >> bc;

    string st;
    st += ab;
    st += ac;
    st += bc;

    if (st == "<<<")
        cout << "B" << endl;

    if (st == "<<>")
        cout << "C" << endl;

    if (st == "<>>")
        cout << "A" << endl;

    if (st == "><<")
        cout << "A" << endl;

    if (st == ">><")
        cout << "C" << endl;

    if (st == ">>>")
        cout << "B" << endl;

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// int main()
// {

//     char sab, sac, sbc;

//     int a = 0, b = 0, c = 0;

//     cin >> sab >> sac >> sbc;

//     if (sac == '<' && sbc == '>' || sac == '>' && sbc == '<')
//         cout << "C" << endl;

//     if (sab == '<' && sbc == '<' || sab == '>' && sbc == '>')
//         cout << "B" << endl;

//     if (sab == '>' && sac == '<' || sab == '<' && sac == '>')
//         cout << "A" << endl;

//     return 0;
// }