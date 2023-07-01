#include <bits/stdc++.h>
using namespace std;
// Fair Distribution of Cookies(LeetCode)
int ans = 1e9;
void func(vector<int> &cookies, int index, int k, vector<int> &cookiesBelongingToChild)
{
    if (index == cookies.size())
    {
        int maxUnfairness = 0;
        for (int x = 0; x < k; ++x)
        {
            maxUnfairness = max(maxUnfairness, cookiesBelongingToChild[x]);
        }
        ans = min(ans, maxUnfairness);
        return;
    }
    for (int x = 0; x < k; ++x)
    {
        cookiesBelongingToChild[x] += (cookies[index]);
        func(cookies, index + 1, k, cookiesBelongingToChild);
        cookiesBelongingToChild[x] -= (cookies[index]);
    }
}
int distributeCookies(vector<int> &cookies, int k)
{
    vector<int> cookiesBelongingToChild(k, 0);
    func(cookies, 0, k, cookiesBelongingToChild);
    return ans;
}
