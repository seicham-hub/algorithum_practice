// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_A&lang=ja

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);

    for (int i = 0; i < n; i++)
        cin >> A[i];

    set<int> candidate;

    for (int msk = 0; msk < (1 << n); msk++)
    {
        int tmp = 0;
        for (int i = 0; i < n; i++)
            if (msk & (1 << i))
                tmp += A[i];

        candidate.insert(tmp);
    }

    int q;
    cin >> q;
    vector<int> m(q);
    for (int i = 0; i < q; i++)
        cin >> m[i];

    for (int mi : m)
    {
        if (candidate.count(mi))
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }

    return 0;
}
// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {

//     int n;
//     cin >> n;
//     vector<int> A(n);

//     for (int i = 0; i < n; i++)
//     {
//         cin >> A[i];
//     }
//     int q;
//     cin >> q;
//     vector<int> m(q);
//     for (int i = 0; i < q; i++)
//     {
//         cin >> m[i];
//     }

//     set<int> candidate;

//     for (int msk = 0; msk < (1 << n); msk++)
//     {
//         int tmp = 0;
//         for (int ind = 0; ind < n; ind++)
//         {
//             if (msk & (1 << ind))
//                 tmp += A[ind];
//         }
//         candidate.insert(tmp);
//     }

//     for (int mi : m)
//     {
//         if (candidate.count(mi))
//             cout << "yes" << endl;
//         else
//             cout << "no" << endl;
//     }

//     return 0;
// }
// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n;
//     cin >> n;
//     vector<int> A(n);
//     for (int i = 0; i < n; i++)
//         cin >> A[i];

//     int q;
//     cin >> q;
//     vector<int> m(q);

//     for (int i = 0; i < q; i++)
//         cin >> m[i];

//     set<int> score;

//     for (int msk = 0; msk < (1 << n); msk++)
//     {
//         int point = 0;
//         for (int i = 0; i < n; i++)
//         {
//             if (msk & (1 << i))
//                 point += A[i];
//         }
//         score.insert(point);
//     }

//     for (int mi : m)
//     {

//         if (score.count(mi))
//             cout << "yes" << endl;
//         else
//             cout << "no" << endl;
//     }

//     return 0;
// }