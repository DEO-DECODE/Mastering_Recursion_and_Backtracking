#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    
bool canPartition(vector<int> &nums, vector<int> &vis, int k, int ind, int currSum, int sumOfEachSubsets)
{
    if (k == 1)
        return true;
    if (currSum == sumOfEachSubsets)
    {
        return canPartition(nums, vis, k - 1, 0, 0, sumOfEachSubsets);
    }
    for (int i = ind; i < nums.size(); ++i)
    {
        if (vis[i] == true || currSum + nums[i] > sumOfEachSubsets)
            continue;
        vis[i] = true;
        if (canPartition(nums, vis, k, i + 1, currSum + nums[i], sumOfEachSubsets))
            return true;
        vis[i] = false;
    }
    return false;
}
bool canPartitionKSubsets(vector<int> &nums, int k)
{
    int totalSum = accumulate(nums.begin(), nums.end(), 0);
    if (totalSum % k != 0)
        return false;
    int sumOfEachSubsets = totalSum / k;
    vector<int> vis(nums.size(), false);
    return canPartition(nums, vis, k, 0, 0, sumOfEachSubsets);
}

};
