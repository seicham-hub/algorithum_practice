//                            **1***
//                         **1*****1***
//                      **1*****2*****1***
//                   **1*****3*****3*****1***
//                **1*****4*****6*****4*****1***
//             **1*****5*****10****10****5*****1***
//          **1*****6*****15****20****15****6*****1***
//       **1*****7*****21****35****35****21****7*****1***
//    **1*****8*****28****56****70****56****28****8*****1***
// **1*****9*****36****84***126***126****84****36****9*****1***

// 上図のようなパスカルの三角形を生成しろ

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generate_pascal_triangle(int depth)
{

    vector<vector<int>> triangle(depth);

    for (int i = 0; i < depth; ++i)
    {
        triangle[i] = vector<int>(i + 1, 1);
    }

    for (int line = 2; line < depth; ++line)
    {
        for (int i = 1; i < line; ++i)
        {
            triangle[line][i] = triangle[line - 1][i] + triangle[line - 1][i - 1];
        }
    }

    return triangle;
}

void print_pascal(vector<vector<int>> &triangle)
{
    int max_digit = to_string(*max_element(triangle.back().begin(), triangle.back().end())).size();

    int width = max_digit + (max_digit % 2) + 2;

    for (int i = 0; i < triangle.size(); i++)
    {
        cout << string((width / 2) * (triangle.size() - i), ' ');

        for (int num : triangle[i])
            cout << setw(width) << setfill(' ') << num;

        cout << endl;
    }
}

int main()
{

    auto triangle = generate_pascal_triangle(10);
    print_pascal(triangle);

    for (auto line : triangle)
    {
        for (auto e : line)
        {
            cout << e << ",";
        }
        cout << endl;
    }

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// vector<vector<int>> create_triangle(int h)
// {
//     vector<vector<int>> result(h);

//     result[0] = {1};

//     for (int i = 1; i < h; i++)
//     {
//         for (int j = 0; j < i + 1; j++)
//         {
//             result[i].push_back(0);
//         }
//     }

//     for (int i = 1; i < h; i++)
//     {
//         for (int j = 0; j < i + 1; j++)
//         {
//             if (0 <= j - 1 && j < result[i - 1].size())
//                 result[i][j] = result[i - 1][j] + result[i - 1][j - 1];
//             else
//                 result[i][j] = 1;
//         }
//     }

//     return result;
// }

// // パスカルの三角形を印刷する関数
// void print_pascal(const vector<vector<int>> &data)
// {
//     int max_digit = to_string(*max_element(data.back().begin(), data.back().end())).length();
//     int width = max_digit + (max_digit % 2) + 2;

//     for (size_t index = 0; index < data.size(); ++index)
//     {
//         cout << string((width / 2) * (data.size() - index), 't');

//         for (int num : data[index])
//         {
//             cout << setw(width) << setfill('*') << num;
//         }
//         cout << endl;
//     }
// }

// int main()
// {
//     auto result = create_triangle(20);

//     print_pascal(result);

//     return 0;
// }