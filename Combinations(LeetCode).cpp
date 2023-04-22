#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void allPossiblity(int val, int n, int k, int currSize, vector<int> &curr, set<vector<int>> &collec)
{
  if (currSize == k)
  {
    collec.insert(curr);
    return;
  }
  if (val > n)
    return;
  // two choices
  curr.push_back(val);
  allPossiblity(val + 1, n, k, currSize + 1, curr, collec);
  curr.pop_back();
  allPossiblity(val + 1, n, k, currSize, curr, collec);
}
vector<vector<int>> combine(int n, int k)
{
  set<vector<int>> collec;
  vector<vector<int>> ans;
  vector<int> curr;
  allPossiblity(1, n, k, 0, curr, collec);
  for (auto vec : collec)
  {
    ans.push_back(vec);
  }
  return ans;
}
};
