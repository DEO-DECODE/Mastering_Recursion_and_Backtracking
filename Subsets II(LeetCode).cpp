#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void allSubsets(vector<int> &nums, int ind, vector<int> &curr, set<vector<int>> &finAns)
{
  if (ind >= nums.size())
  {
    vector<int> temp=curr;
    sort(temp.begin(), temp.end());
    finAns.insert(temp);
    return;
  }
  // pick
  curr.push_back(nums[ind]);
  allSubsets(nums, ind + 1, curr, finAns);
  curr.pop_back();
  allSubsets(nums, ind + 1, curr, finAns);
}
vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
  set<vector<int>> finAns;
  vector<int> curr;
  allSubsets(nums, 0, curr, finAns);
  vector<vector<int>> collec;
  for (auto vec : finAns)
  {
    collec.push_back(vec);
  }
  return collec;
}
};
