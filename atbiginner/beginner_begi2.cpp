#include <iostream>
#include <string>
using namespace std;

int main()
{
    string S;
    int B1 = -1, B2 = -1, R1 = 0, R2 = 0, K1 = 0;

    cin >> S;

    for (int i = 0; i < 8; i++)
    {
        if (S[i] == 'B')
        {
            if (B1 == -1)
                B1 = i + 1;
            else
                B2 = i + 1;
        }
        if (S[i] == 'R')
        {
            if (R1 == 0)
                R1 = i + 1;
            else
                R2 = i + 1;
        }
        if (S[i] == 'K')
            K1 = i + 1;
    }

    if ((B1 + B2) % 2 != 0 && R1 < K1 && K1 < R2 && B1 + B2 + R1 + R2 + K1 != -2)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}
