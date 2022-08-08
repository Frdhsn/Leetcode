// O(n^2)
class Solution {
public:
    int dp[2505][2505];
    int go(int idx,int prv,vector<int>& nums){
        if(idx >= nums.size())return 0;
        if(dp[idx][prv]!=-1)
            return dp[idx][prv];
        int ret = go(idx+1,prv,nums);
        if(nums[idx]>nums[prv])ret=max(ret,1+go(idx+1,idx,nums));
        return dp[idx][prv] = ret;
    }
    int lengthOfLIS(vector<int>& nums) {
        memset(dp,-1,sizeof dp);
        int ret=0;
        for(int i=0;i<nums.size();i++){
            ret=max(ret,go(i+1,i,nums)+1);
        }
        return ret;
    }
};