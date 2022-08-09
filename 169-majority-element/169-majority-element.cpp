// TC: O(n)
// MC: O(1)
class Solution {
public:
    int count(int l,int r,vector<int>&nums,int x){
        int ret=0;
        for(int i=l;i<=r;i++)
            ret+=(nums[i]==x);
        return ret;
    }
    pair<int,int> solve(int l,int r,vector<int>& nums){
        if(l==r){
            return {1,nums[l]};
        }
        int mid = (r-l)/2 + l;
        
        pair<int,int> left = solve(l,mid,nums);
        pair<int,int> right = solve(1+mid,r,nums);
        if(left.second == right.second)
            return {left.first+right.first, left.second};
        int lc = count(l,mid,nums,left.second);
        int rc = count(1+mid,r,nums,right.second);
        if(lc>rc)return {lc,left.second};
        return {rc,right.second};
    }
    int majorityElement(vector<int>& nums) {
        pair<int,int> res = solve(0,nums.size()-1,nums);
        return res.second;
    }
};