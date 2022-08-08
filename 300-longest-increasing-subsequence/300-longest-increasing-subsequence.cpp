// O(n^2)
class Solution {
public:
    int dp[2505][2505];
    int go(int idx,int prv,vector<int>& nums){
        if(idx >= nums.size())return 0;
        if(dp[idx+1][prv+1]!=-1)
            return dp[idx+1][prv+1];
        int ret = go(idx+1,prv,nums);
        if(prv==-1 or nums[idx]>nums[prv])ret=max(ret,1+go(idx+1,idx,nums));
        return dp[idx+1][prv+1] = ret;
    }
    int lengthOfLIS(vector<int>& nums) {
        memset(dp,-1,sizeof dp);
        int ret=go(0,-1,nums);
        return ret;
    }
};