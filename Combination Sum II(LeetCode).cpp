#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void allPossible(int ind, int target, vector<int> &candidates, set<vector<int>> &ans, vector<int> &curr)
{
	if (target == 0)
	{
        // sort(curr.begin(), curr.end());
		ans.insert(curr);
		return;
	}
	if (ind == candidates.size())
	{
		return;
	}
	// Pick
	if (candidates[ind] <= target)
	{
		curr.push_back(candidates[ind]);
		allPossible(ind + 1, target - candidates[ind], candidates, ans, curr);
		curr.pop_back();
	}
	// Not Pick
	// while (ind+1 < candidates.size() && candidates[ind] == candidates[ind + 1])
	// {
	//     ind++;
	// }
	allPossible(ind + 1, target, candidates, ans, curr);
}
vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
	vector<int> curr;
	set<vector<int>> ans;
	vector<vector<int>> ans2;
	sort(candidates.begin(), candidates.end());
	allPossible(0, target, candidates, ans, curr);
	for(auto vec: ans){
		ans2.push_back(vec);
	}
	return ans2;
}
};
