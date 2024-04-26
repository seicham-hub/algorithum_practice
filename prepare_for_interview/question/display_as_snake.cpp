#include <bits/stdc++.h>
using namespace std;

void print_as_snake(int h, int w, vector<char> &words)
{

    int n = words.size();

    vector<vector<char>> snake(h, vector<char>(w, ' '));

    pair<int, int> up = {-1, 1};
    pair<int, int> down = {1, 1};

    pair<int, int> start = {h / 2, 0};

    queue<pair<int, int>> q;
    q.push(start);

    int up_flg = true;
    int print_count = 0;

    while (!q.empty())
    {
        auto now_position = q.front();
        q.pop();
        int x = now_position.first;
        int y = now_position.second;

        snake[x][y] = words[print_count % n];
        print_count++;

        if (x == 0 || x == h - 1)
            up_flg = !up_flg;

        int nx, ny;
        if (up_flg)
        {
            nx = x + up.first;
            ny = y + up.second;
        }
        else
        {
            nx = x + down.first;
            ny = y + down.second;
        }

        if (0 <= nx && nx < h && 0 <= ny && ny < w)
        {
            q.push({nx, ny});
        }
    }

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cout << snake[i][j];
        }
        cout << endl;
    }
}

int main()
{

    // vector<char> words = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<char> words;

    for (char i = 'a'; i <= 'z'; i++)
    {
        words.push_back(i);
    }
    print_as_snake(11, 100, words);

    return 0;
}