// https://atcoder.jp/contests/abc165/tasks/abc165_c

// 0425もう一度（時間かかりすぎ）
// 重複順列として考えると、10^10で間に合わないが、広義単調増加なので前の要素参照しなければOK
// 〇10個と|仕切り9個を並べる並べ方

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int n, m, q;
vector<int> a, b, c, d, ans;

int calc_d_sum(vector<int> &A)
{
    int result = 0;
    rep(i, q)
    {
        int ai = a[i] - 1;
        int bi = b[i] - 1;

        if (A[bi] - A[ai] == c[i])
            result += d[i];
    }

    return result;
}

void get_ans_arr(vector<int> &A)
{
    if (A.size() == n)
    {
        int candidate = calc_d_sum(A);
        ans.push_back(candidate);
        return;
    }

    for (int i = A.back(); i <= m; i++)
    {
        vector<int> A_copy = A;
        A_copy.push_back(i);
        get_ans_arr(A_copy);
    }
}

int main()
{
    cin >> n >> m >> q;

    a.resize(q);
    b.resize(q);
    c.resize(q);
    d.resize(q);

    rep(i, q) cin >> a[i] >> b[i] >> c[i] >> d[i];
    vector<int> A(1, 1);
    get_ans_arr(A);

    auto answer = max_element(ans.begin(), ans.end());
    cout << *answer << endl;

    return 0;
}
// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n, m, q, ans = 0;

//     cin >> n >> m >> q;

//     vector<int> a(q), b(q), c(q), d(q);

//     for (int i = 0; i < q; i++)
//         cin >> a[i] >> b[i] >> c[i] >> d[i];

//     vector<vector<int>> candidate;

//     function<void(vector<int>)> find_candidate = [&](vector<int> tmp)
//     {
//         if (tmp.size() == n)
//         {
//             candidate.push_back(tmp);
//             return;
//         }

//         int num = tmp.back();
//         for (int i = num; i <= m; i++)
//         {
//             vector<int> copy = tmp;
//             copy.push_back(i);
//             find_candidate(copy);
//         }
//     };

//     for (int i = 1; i <= m; i++)
//         find_candidate({i});

//     for (vector<int> nums : candidate)
//     {
//         int tmp_result = 0;
//         for (int i = 0; i < q; i++)
//         {
//             int ai = a[i];
//             int bi = b[i];
//             int ci = c[i];
//             int di = d[i];

//             if (nums[b[i] - 1] - nums[a[i] - 1] == ci)
//             {
//                 tmp_result += di;
//             }
//         }

//         ans = max(ans, tmp_result);
//     }

//     cout << ans << endl;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// int n, m, q;
// vector<int> a, b, c, d;

// int sum_di(vector<int> A)
// {
//     int result = 0;
//     rep(i, q)
//     {
//         int ai = a[i] - 1;
//         int bi = b[i] - 1;
//         if (A[bi] - A[ai] == c[i])
//         {
//             result += d[i];
//         }
//     }
//     return result;
// }

// void get_ans_arr(vector<int> A, vector<int> &ans)
// {
//     if (A.size() == n)
//     {
//         int sum = sum_di(A);
//         ans.push_back(sum);
//         return;
//     }

//     int last_num = A.empty() ? 1 : A.back();
//     for (int i = last_num; i <= m; i++)
//     {
//         vector<int> A_copy = A;
//         A_copy.push_back(i);
//         get_ans_arr(A_copy, ans);
//     }
// }

// int main()
// {

//     cin >> n >> m >> q;

//     a.resize(q);
//     b.resize(q);
//     c.resize(q);
//     d.resize(q);

//     rep(i, q)
//     {
//         cin >> a[i] >> b[i] >> c[i] >> d[i];
//     }

//     vector<int> A, ans;

//     get_ans_arr(A, ans);

//     auto answer = max_element(ans.begin(), ans.end());
//     cout << *answer << endl;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// int n, m, q, a[51], b[51], c[51], d[51], ans = 0;
// ;

// void recursion(string cur)
// {

//     if (cur.size() == n)
//     {
//         int tmp_max = 0;
//         for (int i = 1; i <= q; i++)
//         {
//             if (cur[b[i] - 1] - cur[a[i] - 1] == c[i])
//                 tmp_max += d[i];
//         }
//         ans = max(ans, tmp_max);
//         return;
//     }
//     int last = 1;
//     if (cur.size() >= 1)
//         last = cur[cur.size() - 1] - '0';

//     for (int i = last; i <= m; i++)
//     {
//         string next = cur;
//         next += '0' + i;
//         recursion(next);
//     }
// }

// int main()
// {

//     cin >> n >> m >> q;
//     for (int i = 1; i <= q; i++)
//     {
//         cin >> a[i] >> b[i] >> c[i] >> d[i];
//     }

//     string str;
//     recursion(str);

//     cout << ans << endl;

//     return 0;
// }

// #include <bits/stdc++.h>

// using namespace std;

// int n, m, q;
// int cat[11][11][11];

// int v[11];

// int mx, sum;

// void bkt(int k)
// {
//     if (k == n + 1)
//     {
//         mx = max(mx, sum);
//         return;
//         ;
//     }

//     for (int i = v[k - 1]; i <= m; i++)
//     {
//         v[k] = i;
//         int ant = sum;

//         for (int j = 1; j < k; j++)
//             sum += cat[j][k][i - v[j]];

//         bkt(k + 1);

//         sum = ant;
//     }
// }

// int main()
// {
//     cin >> n >> m >> q;

//     for (int i = 1; i <= q; i++)
//     {
//         int a, b, c, d;
//         cin >> a >> b >> c >> d;

//         cat[a][b][c] += d;
//     }

//     v[1] = 1;

//     bkt(2);

//     cout << mx << "\n";

//     return 0;
// }