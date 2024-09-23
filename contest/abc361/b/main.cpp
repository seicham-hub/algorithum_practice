// https://atcoder.jp/contests/abc361/tasks/abc361_b
// 分からなかった

// 2024_09_17もう一度

#include <bits/stdc++.h>
using namespace std;

struct Point
{
    int x, y, z;
};

Point inputP()
{
    Point p;

    cin >> p.x >> p.y >> p.z;

    return p;
}

bool isDup()
{
    Point l1, r1, l2, r2;

    l1 = inputP();
    r1 = inputP();
    l2 = inputP();
    r2 = inputP();

    if (r2.x <= l1.x)
        return true;
    if (r2.y <= l1.y)
        return true;
    if (r2.z <= l1.z)
        return true;

    if (r1.x <= l2.x)
        return true;
    if (r1.y <= l2.y)
        return true;
    if (r1.z <= l2.z)
        return true;

    return false;
}

int main()
{

    if (isDup())
        cout << "No" << endl;
    else
        cout << "Yes" << endl;

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// struct Point
// {
//     int x, y, z;
// };

// Point input()
// {
//     Point p;
//     cin >> p.x >> p.y >> p.z;

//     return p;
// }

// bool isDuplicate()
// {
//     Point l1, r1, l2, r2;

//     l1 = input();
//     r1 = input();
//     l2 = input();
//     r2 = input();

//     if (r1.x <= l2.x)
//         return false;
//     if (r2.x <= l1.x)
//         return false;

//     if (r1.y <= l2.y)
//         return false;
//     if (r2.y <= l1.y)
//         return false;

//     if (r1.z <= l2.z)
//         return false;
//     if (r2.z <= l1.z)
//         return false;

//     return true;
// }

// int main()
// {

//     if (isDuplicate())
//         cout << "Yes" << endl;
//     else
//         cout << "No" << endl;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// struct Point {
//     int x, y, z;
// };

// void input(Point &p) {
//     cin >> p.x >> p.y >> p.z;
// }

// bool solve() {
//     Point l1, r1, l2, r2;

//     input(l1);
//     input(r1);
//     input(l2);
//     input(r2);

//     // それぞれのx, y, z軸で、重ならない条件をまとめる
//     if (r1.x <= l2.x || r2.x <= l1.x || r1.y <= l2.y || r2.y <= l1.y || r1.z <= l2.z || r2.z <= l1.z) {
//         return false;
//     }

//     return true;
// }

// int main() {
//     cout << (solve() ? "Yes" : "No") << endl;
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// struct Point
// {
//     int x, y, z;
// };

// void input(Point *p)
// {

//     cin >> p->x >> p->y >> p->z;
// }

// bool solve()
// {
//     auto l1 = new Point();
//     auto r1 = new Point();
//     auto l2 = new Point();
//     auto r2 = new Point();

//     input(l1);
//     input(r1);
//     input(l2);
//     input(r2);

//     if (r1->x <= l2->x)
//         return false;
//     if (r2->x <= l1->x)
//         return false;

//     if (r1->y <= l2->y)
//         return false;
//     if (r2->y <= l1->y)
//         return false;

//     if (r1->z <= l2->z)
//         return false;
//     if (r2->z <= l1->z)
//         return false;

//     return true;
// }

// int main()
// {

//     if (solve())
//         cout << "Yes" << endl;
//     else
//         cout << "No" << endl;

//     return 0;
// }