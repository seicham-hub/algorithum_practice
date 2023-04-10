#include <iostream>
using namespace std;

int main()
{
    long long int A, B, count = 0;
    cin >> A >> B;

    while (A != B && A > 0 && B > 0)
    {
        count++;
        if (A > B)
        {
            A = A - B;
        }
        else if (A < B)
        {
            B = B - A;
        }
        else
        {
            break;
        }
    }

    cout << count << endl;

    return 0;
}
