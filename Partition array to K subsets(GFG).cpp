//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
  bool canPartiotion(vector<int> &nums, int ind, int boucketNum, int currentSum, vector<int> &vis, int k, bool &poss, int reqSum)
{
    if (currentSum == reqSum)
    {
        return canPartiotion(nums, 0, boucketNum + 1, 0, vis, k, poss, reqSum);
    }
    if (boucketNum == k)
    {
        return true;
    }

    if (ind >= nums.size())
        return false;
    if (currentSum > reqSum)
        return false;
    if (vis[ind])
    {
        return canPartiotion(nums, ind + 1, boucketNum, currentSum, vis, k, poss, reqSum);
    }
    else
    {
        // not choose
        bool op1 = canPartiotion(nums, ind + 1, boucketNum, currentSum, vis, k, poss, reqSum);
        // choose
        currentSum += nums[ind];
        vis[ind] = 1;
        bool op2 = canPartiotion(nums, ind + 1, boucketNum, currentSum, vis, k, poss, reqSum);
        currentSum -= nums[ind];
        vis[ind] = 0;
        return op1 | op2;
    }
}
    bool isKPartitionPossible(int a[], int n, int k)
    {
         //Your code here
        vector<int> nums(n);
    for (int i = 0; i < n; ++i)
    {
        nums[i] = a[i];
    }
    vector<int> vis(nums.size(), 0);
    int summation = 0;
    for (int i = 0; i < nums.size(); ++i)
        summation += nums[i];
    if (summation % k != 0)
        return false;
    bool poss = false;
    int reqSum = summation / k;
    return canPartiotion(nums, 0, 0, 0, vis, k, poss, reqSum);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	int k;
    	cin>>k;
    	Solution obj;
    	cout<<obj.isKPartitionPossible(a, n, k)<<endl;
    }
}
// } Driver Code Ends
