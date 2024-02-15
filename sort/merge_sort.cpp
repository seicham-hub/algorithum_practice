#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

vector<int> merge(const vector<int> &nums, int start, int end)
{
    if (end - start == 0)
    {
        vector<int> mini = {nums[start]};
        return mini;
    }

    int m = (start + end) / 2;

    vector<int> l = merge(nums, start, m);
    vector<int> r = merge(nums, m + 1, end);

    vector<int> res(l.size() + r.size());
    int i = 0, j = 0, k = 0;
    while (i < l.size() && j < r.size())
    {

        if (l[i] <= r[j])
        {
            res[k] = l[i];
            i++;
        }
        else
        {
            res[k] = r[j];
            j++;
        }
        k++;
    }

    while (i < l.size())
    {
        res[k] = l[i];
        i++;
        k++;
    }
    while (j < r.size())
    {
        res[k] = r[j];
        j++;
        k++;
    }

    return res;
}

int main()
{

    vector<int> nums = {5, 4, 1, 8, 7, 3, 2, 9};
    vector<int> ans = merge(nums, 0, nums.size() - 1);

    rep(i, ans.size()) cout << ans[i] << endl;

    return 0;
}