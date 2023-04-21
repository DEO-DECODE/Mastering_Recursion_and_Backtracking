#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void solve(vector<int> &nums, int ind, set<vector<int>> &ans)
{
	if (ind == nums.size())
	{
		ans.insert(nums);
	}
	for (int i = ind; i < nums.size(); ++i)
	{
		swap(nums[i], nums[ind]);
		solve(nums, ind + 1, ans);
		swap(nums[i], nums[ind]);
	}
}
vector<vector<int>> permuteUnique(vector<int>& nums) {
    set<vector<int>> ans;
	vector<vector<int>> ans2;
	solve(nums, 0, ans);
	for(auto vec: ans){
		vector<int> temp;
		for(auto val: vec){
			temp.push_back(val);
		}
		ans2.push_back(temp);
	}
	return ans2;
}
};
