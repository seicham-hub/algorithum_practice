
// https://atcoder.jp/contests/abc031/tasks/abc031_d
// 全く分からん、実装例が思いつかない、bit全探索（３進数）で解けるみたい
// 　今度もう一度

// 下のやつだとなぜかできない...

#include <bits/stdc++.h>
using namespace std;

int k, n;
string v[30], w[30];
string s[10];

bool dfs(int lineInd, int vInd, int wInd)
{

    // cout << v[lineInd] << vInd << " " << w[lineInd] << " " << wInd << endl;
    // for (int i = 0; i < 11; i++)
    //     cout << s[i] << " ";

    // cout << endl;
    if (lineInd == n)
    {
        return true;
    }

    if (vInd == (int)v[lineInd].size())
    {
        if (wInd == (int)w[lineInd].size())
        {
            return dfs(lineInd + 1, 0, 0);
        }
        else
        {
            return false;
        }
    }
    if (wInd >= (int)w[lineInd].size())
    {
        return false;
    }

    int nowSNumlen = s[v[lineInd][vInd] - '0'].size();

    if (nowSNumlen == 0)
    {
        s[v[lineInd][vInd] - '0'] = w[lineInd].substr(wInd, 1);

        if (dfs(lineInd, vInd + 1, wInd + 1))
        {
            return true;
        }

        // cout << "+1の作業は終わり" << endl;

        s[v[lineInd][vInd] - '0'] = w[lineInd].substr(wInd, 2);
        if (dfs(lineInd, vInd + 1, wInd + 2))
        {
            return true;
        }

        // cout << "+2の作業は終わり" << endl;

        s[v[lineInd][vInd] - '0'] = w[lineInd].substr(wInd, 3);
        if (dfs(lineInd, vInd + 1, wInd + 3))
        {
            return true;
        }
        // cout << "+3の作業は終わり" << endl;
        s[v[lineInd][vInd] - '0'] = "";
    }
    else
    {
        bool ok = true;
        // for (int i = 0; i < nowSNumlen; i++)
        // {
        //     if (s[v[lineInd][vInd] - '0'][i] != w[lineInd][wInd + i])
        //         ok = false;
        // }
        if (s[v[lineInd][vInd] - '0'] != w[lineInd].substr(wInd, nowSNumlen))
            ok = false;

        if (ok)
        {
            return dfs(lineInd, vInd + 1, wInd + nowSNumlen);
        }
        else
        {
            return false;
        }
    }
    return false;
}

int main()
{

    cin >> k >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> v[i] >> w[i];
    }

    dfs(0, 0, 0);

    for (int i = 1; i <= k; i++)
    {
        cout << s[i] << endl;
    }
    return 0;
}

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
