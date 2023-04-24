#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n, fn, en, mn, reply;
    cin >> n;

    fn = 1;
    en = n;

    for (int j = 0; j < 20; j++)
    {
        if (en - fn == 1)
        {
            cout << "! " << fn << endl;
            break;
        }
        mn = (fn + en) / 2;
        cout << "? " << mn << endl;
        cin >> reply;

        if (reply == 1)
            en = mn;
        else
            fn = mn;
    }

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int N;
//     cin >> N;

//     int fN = 1;
//     int cN;
//     int sN = N;
//     int in;

//     for (int i = 0; i < 20; i++)
//     {
//         int d = sN - fN;
//         if (d == 1)
//         {
//             cout << "! " << fN << endl;
//             break;
//         }
//         cN = (fN + sN) / 2;

//         cout << "? " << cN << endl;

//         cin >> in;

//         if (in == 1)
//         {
//             sN = cN;
//         }
//         else
//         {
//             fN = cN;
//         }
//     }
// }