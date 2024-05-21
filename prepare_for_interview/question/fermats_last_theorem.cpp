// Fermat's Last Theorem x**2 + y**2 = **2
// 3**2 + 4**2 = 5**2 OR 6**2 + 8**2 == 10**2
// Input 10, 2 => [(3,4,5),(6,8,10)]
// x,yが10以下でx^n + y^n = max_num^nを満たす誠意数の組を見つける
// (x or y <= 10)
// Input 10, 3 => []
// Input 10, 4 => []
// Input 10, 5 => []

#include <bits/stdc++.h>
using namespace std;

vector<array<int, 3>> femerts_last_theorem(int max_num, int squire_num)
{

    vector<array<int, 3>> result;
    double z_max = pow(pow(max_num - 1, 2) + pow(max_num, 2), (double)1 / (double)squire_num);

    for (int i = 1; i <= max_num; i++)
    {
        for (int j = i + 1; j <= max_num; j++)
        {

            double x_y_pow_sum = pow(i, squire_num) + pow(j, squire_num);
            double z_double = pow(x_y_pow_sum, (double)1 / (double)squire_num);
            if (z_double > (double)numeric_limits<int>::max())
            {
                cout << "exceeded maximum number of int" << endl;
                return {};
            }

            int z = (int)z_double;

            if (z > z_max)
                continue;

            if (pow(i, squire_num) + pow(j, squire_num) == pow(z, squire_num))
                result.push_back({i, j, z});
        }
    }

    return result;
}

int main()
{

    auto ans = femerts_last_theorem(14164841, 2);

    for (auto a : ans)
    {
        cout << a[0] << "," << a[1] << "," << a[2] << endl;
    }

    return 0;
}