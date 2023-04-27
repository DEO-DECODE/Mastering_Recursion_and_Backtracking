#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
     void dj(vector<int> &v, int ind, int &ans, int N)
{
    if (ind == N+1)
    {
        ans++;
        return;
    }
    for (int j = ind; j <= N; ++j)
    {
        if (v[j] % (ind) == 0 || (ind) % v[j] == 0)
        {
            swap(v[ind], v[j]);
            dj(v, ind + 1, ans, N);
            swap(v[ind], v[j]);
        }
    }
}

int countArrangement(int N)
{
    vector<int> vec;
    vec.push_back(0);
    int ans = 0;
    for (int i = 1; i <= N; ++i)
        vec.push_back(i);
    dj(vec, 1, ans, N);
    return ans;
}
};
