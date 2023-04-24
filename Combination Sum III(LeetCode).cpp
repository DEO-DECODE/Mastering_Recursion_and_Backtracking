#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    set<vector<int>> totalCollection;
void allPossiblity(int target, int k, vector<int> &curr, int val)
{
    if (target == 0)
    {
        if (k == 0){
            totalCollection.insert(curr);
        }
        return;
    }
    if (k < 0)
        return;
        // cout<<"0";
        // cout<<target<<" "<<k<<" "<<endl;
    for (int i = val; i <= 9; ++i)
    {
        if (target - i >= 0)
        {
            curr.push_back(i);
            allPossiblity(target - i, k - 1, curr, i + 1);
            curr.pop_back();
        }
        else
        {
            break;
        }
    }
}
vector<vector<int>> combinationSum3(int k, int n)
{
    vector<int> curr;
    allPossiblity(n, k, curr, 1);
    vector<vector<int>> finAns2;
    for (auto vec : totalCollection)
    {
        finAns2.push_back(vec);
        // cout << endl;
    }
    return finAns2;
}
};
