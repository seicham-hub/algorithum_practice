#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    // (前略)
    int ti = clock();
    while (clock() - ti < 299 * CLOCKS_PER_SEC / 100)
    {
        // 計算をここで行う
    }
    // (後略)
    return 0;
}