//  与えられた数字が素数かどうか判定しろ
//  それぞれの関数でunittestを作成しろ

#include <bits/stdc++.h>
using namespace std;

bool is_prime(int &num)
{

    if (num <= 1)
        return false;
    if (num == 2)
        return true;
    if (num % 2 == 0)
        return false;

    for (int i = 3; i * i <= num; i += 2)
    {
        if (num % i == 0)
            return false;
    }

    return true;
}

int main()
{
    int num = 65;
    bool ans = is_prime(num);

    cout << ans << endl;

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// bool is_prime(int num)
// {
//     if (num <= 1)
//         return false;
//     if (num == 2)
//         return true;
//     if (num % 2 == 0)
//         return false;

//     int count = 0;

//     for (int i = 3; i <= num; i += 2)
//     {
//         if (num % i == 0)
//             count++;
//     }
//     return count == 1;
// }

// bool is_prime_v4(int &num)
// {
//     if (num <= 1)
//         return false;
//     if (num == 2)
//         return true;
//     if (num % 2 == 0)
//         return false;

//     for (int i = 3; i * i <= num; i += 2)
//     {
//         if (num % i == 0)
//             return false;
//     }

//     return true;
// }

// int main()
// {
//     int num = 653;

//     cout << is_prime_v4(num) << endl;

//     return 0;
// }