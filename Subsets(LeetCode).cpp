#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
void allSubsets(vector<int> &nums, int ind, vector<vector<int>> &ans, vector<int> &curr)
{
  if (ind == nums.size())
  {
    ans.push_back(curr);
    return;
  }
  // NOT PICK
  allSubsets(nums, ind + 1, ans, curr);
  // Pick
  curr.push_back(nums[ind]);
  allSubsets(nums, ind + 1, ans, curr);
  curr.pop_back();
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
  vector<vector<int>> ans;
  allSubsets(nums, 0, ans, curr);
  return ans;
    }
};
