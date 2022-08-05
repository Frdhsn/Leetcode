class Solution {
public:
    using ll = long long int;
    int dp[205][1005];
    int go(int idx,vector<int>& nums, int target){
        if(idx == nums.size())
            return 0;
        if(target == 0)
            return 1;
        if(target < 0)
            return 0;
        if(dp[idx][target]!=-1)
            return dp[idx][target];
        int ret = go(0,nums,target-nums[idx]);
        ret+=go(idx+1,nums,target);
        return dp[idx][target] = ret;
    }
    int combinationSum4(vector<int>& nums, int target) {
        memset(dp,-1,sizeof dp);
        return go(0,nums,target);
    }
};