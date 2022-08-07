class Solution {
public:
    //bool conq(int l,int r,vector<int>& nums)
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> dp(n+7);
        
        dp[0] = 1;
        
        for(int i=2;i<n+1;i++){
            if(nums[i-1]==nums[i-2] && dp[i-2])
                dp[i] = 1;
            if(i>2 && nums[i-1]==nums[i-2] && nums[i-2]==nums[i-3]&& dp[i-3])
                dp[i] = 1;
            if(i>2 && nums[i-1]==1+nums[i-2] && nums[i-2]==1+nums[i-3]&& dp[i-3])
                dp[i] = 1;
        }
        return dp[n];
    }
};