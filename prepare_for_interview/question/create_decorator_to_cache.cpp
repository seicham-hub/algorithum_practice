#include <bits/stdc++.h>
using namespace std;

class Wrapper
{
public:
    unordered_map<long long, long long> result;

    long long long_func(long long n)
    {

        long long r = 0;
        if (result.count(n))
            return result[n];
        else
        {
            for (long long i = 0; i < 100000000; i++)
            {
                r += n * i;
            }
            result[n] = r;
        }

        return r;
    }
};

int main()
{
    Wrapper *w = new Wrapper();
    for (long long i = 0; i < 10; i++)
    {
        cout << w->long_func(i) << endl;
    }
    for (long long i = 0; i < 10; i++)
    {
        cout << w->long_func(i) << endl;
    }

    return 0;
}