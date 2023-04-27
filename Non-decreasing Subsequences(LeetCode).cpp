#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    set<vector<int>> finAns;
void allPoss(vector<int> &nums, int ind, int prev_element, vector<int> &curr)
{
    // agar koi index pe jo element hai wo valid hai to uske pass do possiblity hai
    // ya to wo us list ka part bn jaye ya to naa bane
    if (ind == nums.size())
    {
        if (curr.size() >= 2)
            finAns.insert(curr);
        return;
    }
    allPoss(nums, ind + 1, prev_element, curr);
    // choose
    if (nums[ind] >= prev_element)
    {
        curr.push_back(nums[ind]);
        allPoss(nums, ind + 1, nums[ind], curr);
        curr.pop_back();
    }
}
vector<vector<int>> findSubsequences(vector<int> &nums)
{
    vector<int> curr;
    // for(int i=0; i<nums.size(); ++i){
        allPoss(nums,0,INT_MIN,curr);
    // }
    vector<vector<int>> answ;
    for(auto vec: finAns){
        answ.push_back(vec);
    }
    return answ;
}
};
