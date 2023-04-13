#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> collect;
void allPoss(vector<int> &candidates, int target, int ind, vector<int> &curr)
{
    if (ind < 0)
        return;
    if (target == 0)
    {
        collect.push_back(curr);
        return;
    }
    // PICK 
    if (candidates[ind] <= target)
    {
        curr.push_back(candidates[ind]);
        allPoss(candidates, target - candidates[ind], ind, curr);
        curr.pop_back();
    }
    // NOT PICK
    allPoss(candidates,target, ind-1, curr);
}
vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<int> curr;
    int n=candidates.size();
    allPoss(candidates,target,n-1,curr);
    return collect;
}
};
