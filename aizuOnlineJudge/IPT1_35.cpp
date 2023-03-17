// Shuffle

#include <iostream>
#include <string>
using namespace std;

int main()
{

    string init;
    int m, h;

    while (true)
    {

        cin >> init;
        if (init == "-")
            break;
        cin >> m;

        for (int i = 0; i < m; i++)
        {
            cin >> h;
            init = init.substr(h, init.size() - h) + init.substr(0, h);
        }

        cout << init << endl;
    }

    return 0;
}
