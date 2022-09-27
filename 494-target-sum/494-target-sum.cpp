class Solution {
public:
    int ways(int idx,int tot,vector<int>&nums){
        if(idx == nums.size())
            return tot==0;
        return ways(idx+1,tot-nums[idx],nums)+ways(idx+1,tot+nums[idx],nums);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return ways(0,target,nums);
    }
};