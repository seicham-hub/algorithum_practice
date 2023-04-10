#include <iostream>
#include <string>
using namespace std;

int main()
{
    int H, W;
    string Si[100];
    cin >> H >> W;

    for (int i = 0; i < H; i++)
        cin >> Si[i];

    for (int i = 0; i < H; i++)
    {

        for (int j = 0; j < W - 1; j++)
        {
            if (Si[i][j] == 'T' && Si[i][j + 1] == 'T')
            {
                Si[i][j] = 'P';
                Si[i][j + 1] = 'C';
            }
        }
        cout << Si[i] << endl;
    }

    return 0;
}
