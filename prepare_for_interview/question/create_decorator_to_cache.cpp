#include <bits/stdc++.h>
using namespace std;

class cached
{

public:
    unordered_map<long long, long long> cache;

    cached() {}

    long long long_func(int value)
    {

        if (cache[value])
            return cache[value];

        long long result = (long long)value;
        for (int i = 0; i < 1e5; i++)
        {
            result += i;
        }
        cache[value] = result;

        return result;
    }
};

int main()
{

    cached long_func_wraper = cached();

    for (int i = 0; i < 10000; i++)
    {
        cout << long_func_wraper.long_func(i) << endl;
    }

    for (int i = 0; i < 10000; i++)
    {
        cout << long_func_wraper.long_func(i) << endl;
    }

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// class Wrapper
// {
// public:
//     unordered_map<long long, long long> result;

//     long long long_func(long long n)
//     {

//         long long r = 0;
//         if (result.count(n))
//             return result[n];
//         else
//         {
//             for (long long i = 0; i < 100000000; i++)
//             {
//                 r += n * i;
//             }
//             result[n] = r;
//         }

//         return r;
//     }
// };

// int main()
// {
//     Wrapper *w = new Wrapper();
//     for (long long i = 0; i < 10; i++)
//     {
//         cout << w->long_func(i) << endl;
//     }
//     for (long long i = 0; i < 10; i++)
//     {
//         cout << w->long_func(i) << endl;
//     }

//     return 0;
// }