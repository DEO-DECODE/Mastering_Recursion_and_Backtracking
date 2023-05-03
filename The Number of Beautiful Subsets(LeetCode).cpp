class Solution {
public:
     int countSubset(vector <int> &nums,int mask,int k,int index,vector <int> &dp){
         if(index >= nums.size()){
             return 1;
         }
         int ans=countSubset(nums,mask,k,index+1,dp);
         int flag=1;
         for(int i=0;i<index;i++){
            if(mask & (1<<i)){
                if(abs(nums[i]-nums[index]) == k){
                    flag=0;
                    break;
                }
            }
         }
         if(flag){
             mask|=(1<<index);
             ans += countSubset(nums,mask,k,index+1,dp);
         }
         return dp[index]=ans;
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        int n=nums.size();
        vector <int> dp(n,-1);
        return countSubset(nums,0,k,0,dp)-1;
    }
};
