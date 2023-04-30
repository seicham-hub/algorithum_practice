#include <bits/stdc++.h>
using namespace std;

// 0     0     1

int main()
{
    int n, nowAns, beforeAns, cnt = 0, tyosei, beforeInd, nowInd, result;
    cin >> n;
    nowInd = n / 2;

    for (int i = 0; i < 20; i++)
    {
        cnt++;
        cout << "? " << nowInd << endl;
        cin >> nowAns;

        if (abs(nowInd - beforeInd) == 1)
        {
            if (beforeAns != nowAns)
            {
                result = nowInd < beforeInd ? nowInd + 1 : beforeInd + 1;
                break;
            }
        }
        beforeAns = nowAns;
        beforeInd = nowInd;

        if (nowAns == 0)
        {
            tyosei = (n / pow(2, cnt + 1)) < 1 ? 1 : n / pow(2, cnt + 1);
            nowInd = nowInd + tyosei;
        }
        else if (nowAns == 1)
        {
            tyosei = (n / pow(2, cnt + 1)) < 1 ? 1 : n / pow(2, cnt + 1);
            nowInd = nowInd - tyosei;
        }
    }

    cout << "! " << result << endl;

    return 0;
}

// #include<cstdio>
// #include<cstring>
// #include<algorithm>
// using namespace std;
// typedef long long LL;
// int n;
// int query(int i){
// 	printf("? %d\n",i);
// 	fflush(stdout);
// 	int x; scanf("%d",&x);
// 	return x;
// }
// int main(){
// 	fflush(stdout);
// 	scanf("%d",&n);
// 	int l=1,r=n;
// 	while(r-l>1){
// 		int mid=l+r>>1;
// 		if(query(mid)) r=mid;
// 		else l=mid;
// 	}
// 	printf("! %d\n",l);
// 	fflush(stdout);
// 	return

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;

    int fN = 1;
    int cN;
    int sN = N;
    int in;

    for (int i = 0; i < 20; i++)
    {
        int d = sN - fN;
        if (d == 1)
        {
            cout << "! " << fN << en break;
        }
        cN = (fN + sN) / 2;

        cout << "? " << cN << endl;

        cin >> in;

        if (in == 1)
        {
            sN = cN;
        }
        else
        {
            fN = cN;
        }
    }
}