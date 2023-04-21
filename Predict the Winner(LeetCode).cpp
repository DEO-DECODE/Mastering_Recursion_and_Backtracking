#include <bits/stdc++.h>
using namespace std;
// Predict the Winner(LeetCode)
class Solution
{
public:
    int func(int ind1, int ind2, vector<int> &nums, bool canChoosePlayer1, bool canChoosePlayer2, int &ans)
    {
        if (ind1 > ind2)
        {
            return 0;
        }
        // IF Player1 can choose
        // cout<<canChoosePlayer1<<" "<<ind1<<" "<<canChoosePlayer2<<" "<<ind2<<endl;
        if (canChoosePlayer1)
        {
            return max(nums[ind1] + func(ind1 + 1, ind2, nums, false, true, ans), nums[ind2] + func(ind1, ind2 - 1, nums, false, true, ans));
        }
        // IF Player2 can choose
        else
            return min(func(ind1 + 1, ind2, nums, true, false, ans), func(ind1, ind2 - 1, nums, true, false, ans));
    }
    bool PredictTheWinner(vector<int> &nums)
    {
        int n = nums.size(), score1 = 0, ans = 0;
        bool canChoosePlyer1 = true, canChoosePlyer2 = false;
        score1 = func(0, n - 1, nums, canChoosePlyer1, canChoosePlyer2, ans);
        int scorebyB = accumulate(nums.begin(), nums.end(), 0) - score1;
        return score1 >= scorebyB;
    }
};
