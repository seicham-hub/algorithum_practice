#include <iostream>
#include <vector>

using namespace std;

vector<int> a = {1, 14, 32, 51, 51, 51, 243, 419, 750, 910};

// indexが条件をみたすかどうか
bool isOK(int index, int key)
{
    if (a[index] >= key)
        return true;
    else
        return false;
}

// 汎用的な二分探索のテンプレ
int binary_search(int key)
{
    int left = -1;             // index=0 が条件を満たす事もあるため-1
    int right = (int)a.size(); // 「index = a.size()-1」が条件を満たさないこともあるので、初期値は a.size()

    /* どんな二分探索でも個々の書き方を変えずにできる */
    while (right - left > 1)
    {
        int mid = left + (right - left) / 2;

        if (isOK(mid, key))
            right = mid;
        else
            left = mid;
    }

    /* left は条件を満たさない最大の値、right は条件を満たす最小の値になっている */
    return right;
}

int main()
{
    cout << binary_search(51) << endl;
    cout << binary_search(1) << endl;
    cout << binary_search(910) << endl;

    cout << binary_search(52) << endl;  // 6
    cout << binary_search(0) << endl;   // 0
    cout << binary_search(911) << endl; // 10 (場外)
}
