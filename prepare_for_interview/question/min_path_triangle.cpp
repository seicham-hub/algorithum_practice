
// Input 5,20
// Output
// [[7],[6,3],[6,0,15],[4,20,1,8],[6,4,4,1,0]]

// min_path = 12
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> create_triangle(int h, int max_num)
{
    vector<vector<int>> result(h);

    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> rand(0, max_num);

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j <= i; j++)
            result[i].push_back(rand(mt));
    }

    return result;
}

int get_min_path_triangle(const vector<vector<int>> &triangle)
{
    int result = 1e9;

    function<void(int, int, int)> _get_min_path_triangle = [&](int path_sum, int now_h, int index) -> void
    {
        path_sum += triangle[now_h][index];

        if (now_h == triangle.size() - 1)
        {
            result = min(result, path_sum);
            return;
        }

        _get_min_path_triangle(path_sum, now_h + 1, index);
        _get_min_path_triangle(path_sum, now_h + 1, index + 1);
    };

    _get_min_path_triangle(0, 0, 0);

    return result;
}

int main()
{

    int h = 5, max_num = 20;
    auto triangle = create_triangle(h, max_num);
    for (int i = 0; i < 5; i++)
    {
        for (auto a : triangle[i])
        {
            cout << a << " ";
        }
        cout << endl;
    }

    int ans = get_min_path_triangle(triangle);

    cout << ans << endl;

    return 0;
}