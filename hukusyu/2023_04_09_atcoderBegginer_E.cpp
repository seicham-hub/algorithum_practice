// https://atcoder.jp/contests/abc297/tasks/abc297_e

// k番目に安い金額として、あるたこ焼きをK+1個以上買うことはないため、それぞれの買う個数を
// 0からK個で全探索するとO(K^N)で解くことができるが間に合わない。

// 1番目からｉ番目までの安い金額がわかっているとして、ｉ+１番目を考える。
// i+1番目の金額はこれらi個の方法のいずれかに1個いずれかのたこ焼きを加えたものになる。
// 始め、
// 0 だけが入っている集合を管理するデータ構造
// Q と答えを格納する長さ
// K の配列
// ans を持つ。
// i=2,3,…,K の順に以下を行う。
// Q に入っている一番小さい値
// v を取り出し、
// ans[i]=v とする。ただし、
// ans[i−1]=v の場合は次の要素を見る。
// j=1,2,…,N に対して、
// Q に
// v+A
// j
// ​
//   を加える。
// ans[i−1]=v の時に次の要素を見るのは、答えとして重複している金額は
// 1 回しかカウントしないからです。

// 計算量は、
// K×N 回
// Q にアクセスするため、
// O(KNlog(NK)) です。これは十分高速です。

// Q のサイズが
// K を超えている間
// Q の最大値を削除することで、
// O(KNlogK) でこの問題を解くこともできます。

// また、上記の探索方法はダイクストラ法に酷似しており、頂点をたこ焼きの買い方、辺をたこ焼きを
// 1 個追加する操作かつ重みはたこ焼きの金額としたグラフ上で何も買わない頂点からダイクストラ法をしているとも見ることが出来ます。ただし、同じ金額となる買い方は同じものとみることに注意してください。

#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  for (int i = 0; i < N; i++)
  {
    cin >> A[i];
  }
  priority_queue<long long, vector<long long>, greater<long long>> pq;
  pq.push(0);
  int cnt = -1;
  long long pr = -1;
  while (true)
  {
    long long x = pq.top();
    pq.pop();
    if (pr != x)
    {
      pr = x;
      cnt++;
      if (cnt == K)
      {
        cout << x << endl;
        break;
      }
      for (int i = 0; i < N; i++)
      {
        pq.push(x + A[i]);
      }
    }
  }
}
