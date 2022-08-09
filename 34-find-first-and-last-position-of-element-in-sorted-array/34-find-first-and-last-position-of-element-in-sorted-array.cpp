class Solution {
public:
    int lowerbound(vector<int>& nums, int target) {
        int n = nums.size();
        int lo = 0,hi=n-1;
        while(hi-lo>5){
            int md = (lo+hi)/2;
            if(nums[md]<target)
                lo=md+1;
            else hi=md;
        }
        for(int idx=max(0,lo-10);idx<=min(n-1,hi+10);idx++){
            if(nums[idx]==target){
                return idx;
            }
        }
        return -1;
    }
    int upperbound(vector<int>& nums, int target) {
        int n = nums.size();
        int lo = 0,hi=n-1;
        while(hi-lo>5){
            int md = (lo+hi)/2;
            if(nums[md]>target)
                hi=md-1;
            else lo=md;
        }
        for(int idx=min(n-1,hi+10);idx>=max(0,lo-10);idx--){
            if(nums[idx]==target){
                return idx;
            }
        }
        return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int lo = lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        if(lo >= nums.size() or nums[lo]>target){
            vector<int> res={-1,-1};
            return res;
        }
        int hi = lower_bound(nums.begin(),nums.end(),target+1)-nums.begin();
        if(nums[hi-1]==target){
            vector<int> res={lo,hi-1};
            return res;
        }
        return {-1,-1};
    }
};