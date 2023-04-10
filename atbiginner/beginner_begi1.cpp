#include <iostream>
using namespace std;

int main()
{
    int N;
    long long int D, Ti[100], resultT = -1;
    cin >> N >> D;

    for (int i = 0; i < N; i++)
    {
        cin >> Ti[i];

        if (i == 0)
        {
            continue;
        }
        else if (Ti[i] - Ti[i - 1] <= D)
        {
            resultT = Ti[i];
            break;
        }
    }

    cout << resultT << endl;

    return 0;
}
