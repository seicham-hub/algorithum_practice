// Standard Deviation

#include <iostream>
#include <stdio.h>
#include <math.h>
#define USE_MATH_DEFINES
using namespace std;

int main()
{
    int n;
    double s[1001], sum, m, smSum;

    while (true)
    {

        sum = 0;
        smSum = 0;

        cin >> n;

        if (n == 0)
            break;

        for (int i = 1; i <= n; i++)
        {
            cin >> s[i];
            sum += s[i];
        }

        m = sum / n;

        for (int i = 1; i <= n; i++)
        {
            smSum += (s[i] - m) * (s[i] - m);
        }

        printf("%.5f\n", sqrt(smSum / n));
    }

    return 0;
}
