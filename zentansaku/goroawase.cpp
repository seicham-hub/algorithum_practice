
// https://atcoder.jp/contests/abc031/tasks/abc031_d
// 全く分からん、実装例が思いつかない、bit全探索（３進数）で解けるみたい
// 2024_06_04もう一度

// 部分点解法
// wがa,b,c飲みで構成される+k<=3なので
// sの組み合わせは最大で（3^3+3^2+3^1)^3となる。
// 先に文字列s1,...,snを決めて条件を満たすか判定すればよい

#include <bits/stdc++.h>
using namespace std;

int k, n;
vector<string> v, w;
vector<int> s_size;

bool check(vector<int> candidate)
{

    for (int i = 0; i < n; i++)
    {
        string nums = v[i];
        string word = w[i];
        int size = 0;

        for (char c : nums)
        {
            int num = c - '0';
            size += candidate[num];
        }

        if (size != word.size())
            return false;
    }

    return true;
}

void find_s_size_candidate(int now_num, vector<int> tmp_s_size)
{
    if (s_size.size())
        return;
    if (now_num > k)
    {
        if (check(tmp_s_size))
        {
            s_size = tmp_s_size;
        }
        return;
    }
    for (int i = 1; i <= 3; i++)
    {
        vector<int> copy = tmp_s_size;
        copy[now_num] = i;
        find_s_size_candidate(now_num + 1, copy);
    }
}

vector<string> find_s()
{

    find_s_size_candidate(1, vector<int>(k + 1));

    vector<int> ans_size = s_size;
    vector<string> ans(k + 1);

    for (int i = 0; i < n; i++)
    {
        string nums = v[i];
        string word = w[i];

        int ind = 0;
        for (char c : nums)
        {
            int num = c - '0';
            int size = ans_size[num];
            ans[num] = word.substr(ind, size);
            ind += size;
        }
    }

    return ans;
}

int main()
{

    cin >> k >> n;

    v.resize(n);
    w.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i] >> w[i];
    }

    vector<string> ans = find_s();

    for (int i = 1; i <= k; i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int k, n;
//     cin >> k >> n;

//     vector<string> v(n), w(n);

//     for (int i = 0; i < n; i++)
//         cin >> v[i] >> w[i];

//     vector<int> s_size;

//     function<bool(vector<int>)> check = [&](vector<int> candidate)
//     {
//         for (int i = 0; i < n; i++)
//         {
//             string nums = v[i];
//             int size = 0;
//             for (char c : nums)
//             {
//                 int num = c - '0';
//                 size += candidate[num];
//             }

//             if (size != w[i].size())
//                 return false;
//         }

//         return true;
//     };

//     function<void(int, vector<int>)> find_candidate = [&](int ind, vector<int> tmp_s_size)
//     {
//         if (s_size.size())
//             return;
//         if (ind > k)
//         {
//             if (check(tmp_s_size))
//             {
//                 s_size = tmp_s_size;
//             };
//             return;
//         }

//         for (int j = 1; j <= 3; j++)
//         {
//             vector<int> copy = tmp_s_size;
//             copy[ind] = j;
//             find_candidate(ind + 1, copy);
//         }
//     };

//     find_candidate(1, vector<int>(k + 1));

//     function<vector<string>(vector<int>)> create_ans = [&](vector<int> s_ans)
//     {
//         vector<string> result(k + 1);

//         for (int i = 0; i < n; i++)
//         {
//             string nums = v[i];
//             string word = w[i];
//             int ind = 0;
//             for (char c : nums)
//             {
//                 int num = c - '0';
//                 int size = s_ans[num];
//                 result[num] = word.substr(ind, size);
//                 ind += size;
//             }
//         }

//         return result;
//     };

//     vector<string> ans = create_ans(s_size);

//     for (int i = 1; i <= k; i++)
//     {
//         cout << ans[i] << endl;
//     }

//     return 0;
// }
// #include <bits/stdc++.h>
// using namespace std;

// int k, n;
// vector<string> v;
// vector<string> w;

// bool check(vector<int> s_count)
// {
//     for (int i = 0; i < n; i++)
//     {
//         int size = 0;
//         for (char c : v[i])
//         {
//             size += s_count[c - '0'];
//         }

//         if (size != w[i].size())
//         {
//             return false;
//         }
//     }

//     return true;
// }

// void dfs(int ind, vector<int> s_count, vector<int> &count_ans)
// {

//     if (count_ans.size())
//         return;
//     if (s_count.back())
//     {
//         if (check(s_count))
//             count_ans = s_count;
//         return;
//     }

//     for (int i = 1; i <= 3; i++)
//     {
//         s_count[ind] = i;
//         dfs(ind + 1, s_count, count_ans);
//     }
// }

// vector<string> create_ans(vector<int> &count_ans)
// {
//     vector<string> result(k + 1);

//     for (int i = 0; i < n; i++)
//     {
//         int ind = 0;
//         for (char c : v[i])
//         {
//             int num = c - '0';
//             int num_size = count_ans[num];

//             result[num] = w[i].substr(ind, num_size);
//             ind += num_size;
//         }
//     }

//     return result;
// }

// int main()
// {

//     cin >> k >> n;

//     v.resize(n);
//     w.resize(n);

//     for (int i = 0; i < n; i++)
//         cin >> v[i] >> w[i];

//     vector<int> s_count(k + 1, 0);
//     vector<int> count_ans;

//     dfs(0, s_count, count_ans);

//     vector<string> ans = create_ans(count_ans);

//     for (int i = 1; i <= k; i++)
//     {
//         cout << ans[i] << endl;
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// int k, n;
// string num[20];
// string v[51], w[51];

// // a:lineのインデックス,vi：v[line]のインデックス,wi：w[line]のインデックス
// bool maketable(int a, int vi, int wi)
// {
//     if (a == n)
//         return true;

//     if (vi == v[a].size())
//     {
//         if (wi == w[a].size())
//         {
//             return maketable(a + 1, 0, 0);
//         }
//         else
//             return false;
//     }

//     if (wi >= w[a].size())
//         return false;

//     if (num[v[a][vi] - '1'] == "")
//     {
//         num[v[a][vi] - '1'] = w[a].substr(wi, 1);
//         if (maketable(a, vi + 1, wi + 1))
//         {
//             return true;
//         }
//         num[v[a][vi] - '1'] = w[a].substr(wi, 2);
//         if (maketable(a, vi + 1, wi + 2))
//         {
//             return true;
//         }
//         num[v[a][vi] - '1'] = w[a].substr(wi, 3);
//         if (maketable(a, vi + 1, wi + 3))
//         {
//             return true;
//         }
//         num[v[a][vi] - '1'] = "";
//     }
//     else
//     {

//         int ok = 1;

//         for (int i = 0; i < num[v[a][vi] - '1'].size(); i++)
//         {
//             if (num[v[a][vi] - '1'][i] != w[a][wi + i])
//                 ok = 0;
//         }

//         if (ok)
//         {
//             return maketable(a, vi + 1, wi + num[v[a][vi] - '1'].size());
//         }
//         else
//             return false;
//     }

//     return false;
// }

// int main()
// {

//     cin >> k >> n;
//     for (int i = 0; i < n; i++)
//         cin >> v[i] >> w[i];
//     cout << endl;
//     maketable(0, 0, 0);
//     for (int i = 0; i < k; i++)
//         cout << num[i] << endl;

//     return 0;
// }

// 自分で解いたコード（解けなかった）
// 文字の分け方で全探索

// #include <bits/stdc++.h>
// using namespace std;

// int k, n;
// vector<int> v;
// vector<string> w;

// void dfs(int line, vector<string> s)
// {
//     string nums = to_string(v[line]);
//     string text = w[line];

//     string tmp_text;

//     for (int j = 0; j < nums.size(); j++)
//     {
//         int num = nums[j] - '0';

//         if (s[num].size() != 0)
//             tmp_text += s[num];
//         else
//         {
//             for (int l = 1; l <= 3; l++)
//             {
//                 vector<string> new_s = s;
//                 new_s[num] = string(text.begin() + tmp_text.size(), text.begin() + tmp_text.size() + l);
//             }
//         }
//     }
// }

// int main()
// {

//     cin >> k >> n;

//     v.resize(n);
//     w.resize(n);

//     vector<string> s(k + 1);

//     for (int i = 0; i < n; i++)
//         cin >> v[i] >> w[i];

//     for (int i = 0; i < n; i++)
//     {
//     }

//     return 0;
// }

// 提出 #2304491
// お手本コード

// #include <iostream>
// #include <vector>
// #include <string>

// using namespace std;

// int k, n;
// string num[20];
// string v[51], w[51];

// bool maketable(int a, int vi, int wi){
// 	if (a == n){
// 		return true;
// 	}

// //	cout << a << endl;

// 	if (vi == v[a].size()){
// 		if (wi == w[a].size()){
// 			return maketable(a + 1, 0, 0);
// 		}
// 		else
// 			return false;
// 	}

// 	if (wi >= w[a].size())
// 		return false;

// 	if (num[v[a][vi] - '1'] == ""){
// 		num[v[a][vi] - '1'] = w[a].substr(wi, 1);
// 		if(maketable(a, vi + 1, wi + 1)){
// 			return true;
// 		}
// 		num[v[a][vi] - '1'] = w[a].substr(wi, 2);
// 		if(maketable(a, vi + 1, wi + 2)){
// 			return true;
// 		}
// 		num[v[a][vi] - '1'] = w[a].substr(wi, 3);
// 		if(maketable(a, vi + 1, wi + 3)){
// 			return true;
// 		}
// 		num[v[a][vi] - '1'] = "";
// 	}
// 	else {
// 		int ok = 1;
//         // 現在の割り当てが正しいかどうかチェック
// 		for (int i = 0; i < num[v[a][vi] - '1'].size(); i++){
// 			if (num[v[a][vi] - '1'][i] != w[a][wi + i])
// 				ok = 0;
// 		}

// 		if (ok){
// 			return maketable(a, vi + 1, wi + num[v[a][vi] - '1'].size());
// 		}
// 		else
// 			return false;
// 	}

// 	return false;
// }

// int main(void){

// 	cin >> k >> n;

// 	for (int i = 0; i < n; i++){
// 		cin >> v[i] >> w[i];
// 	}

// 	maketable(0, 0, 0);

// 	for (int i = 0; i < k; i++){
// 		cout << num[i] << endl;
// 	}

// }

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int k, n;
//     cin >> k >> n;
//     string v[20], w[30];

//     for (int i = 0; i < n; i++)
//     {
//         cin >> v[i] >> w[i];
//     }

//     return 0;
// }
