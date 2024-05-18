// 以下のようにアルファベットや任意の文字列をへびのように表示させろ。
//      f                   z                   t                   n                   h
//     e g                 y a                 s u                 m o                 g i
//    d   h               x   b               r   v               l   p               f   j
//   c     i             w     c             q     w             k     q             e     k
//  b       j           v       d           p       x           j       r           d       l
// a         k         u         e         o         y         i         s         c         m
//            l       t           f       n           z       h           t       b           n       v
//             m     s             g     m             a     g             u     a             o     u
//              n   r               h   l               b   f               v   z               p   t
//               o q                 i k                 c e                 w y                 q s
//                p                   j                   d                   x                   r

#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> display_as_snake(string &text, int h, int w)
{

    vector<vector<char>> result(h, vector<char>(w, ' '));
    pair<int, int> start = {h / 2, 0};

    int dx[2] = {-1, 1};
    int dy[2] = {1, 1};

    queue<pair<int, int>> q;
    q.push(start);

    int direction_flg = 0;
    int print_count = 0;

    while (!q.empty())
    {
        auto top = q.front();
        q.pop();
        int x = top.first;
        int y = top.second;

        // charを格納
        result[x][y] = text[print_count % text.size()];
        print_count++;

        if (y >= w)
            break;

        // 上下に来たら方向を変える
        if (x == 0 || x == h - 1)
            direction_flg = !direction_flg;

        int nx = x + dx[direction_flg];
        int ny = y + dy[direction_flg];
        if (0 <= nx && nx < h && 0 <= ny && ny < w)
            q.push({nx, ny});
    }

    return result;
}

int main()
{
    string text;
    for (char i = 'a'; i <= 'z'; i++)
        text += i;

    int height = 32;
    int width = 100;
    auto ans = display_as_snake(text, height, width);

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            cout << ans[i][j];
        }
        cout << endl;
    }
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// void print_as_snake(int h, int w, vector<char> &words)
// {

//     int n = words.size();

//     vector<vector<char>> snake(h, vector<char>(w, ' '));

//     pair<int, int> up = {-1, 1};
//     pair<int, int> down = {1, 1};

//     pair<int, int> start = {h / 2, 0};

//     queue<pair<int, int>> q;
//     q.push(start);

//     int up_flg = true;
//     int print_count = 0;

//     while (!q.empty())
//     {
//         auto now_position = q.front();
//         q.pop();
//         int x = now_position.first;
//         int y = now_position.second;

//         snake[x][y] = words[print_count % n];
//         print_count++;

//         if (x == 0 || x == h - 1)
//             up_flg = !up_flg;

//         int nx, ny;
//         if (up_flg)
//         {
//             nx = x + up.first;
//             ny = y + up.second;
//         }
//         else
//         {
//             nx = x + down.first;
//             ny = y + down.second;
//         }

//         if (0 <= nx && nx < h && 0 <= ny && ny < w)
//         {
//             q.push({nx, ny});
//         }
//     }

//     for (int i = 0; i < h; i++)
//     {
//         for (int j = 0; j < w; j++)
//         {
//             cout << snake[i][j];
//         }
//         cout << endl;
//     }
// }

// int main()
// {

//     // vector<char> words = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
//     vector<char> words;

//     for (char i = 'a'; i <= 'z'; i++)
//     {
//         words.push_back(i);
//     }
//     print_as_snake(11, 100, words);

//     return 0;
// }