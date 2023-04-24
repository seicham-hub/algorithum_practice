// 問題の制約間違えてね？
// テストケースが本当に制約の条件を満たしているか確認

#include <iostream>
#include <cassert>
using namespace std;

int main()
{
    long long A, B;
    cin >> A >> B;

    // この 2 行を追加するだけ！
    assert(1LL <= A && A <= 5000LL); // A の値が範囲外ならエラーを発生させる
    assert(1LL <= B && B <= 5000LL); // B の値が範囲外ならエラーを発生させる

    cout << A + B << endl;
    return 0;
}