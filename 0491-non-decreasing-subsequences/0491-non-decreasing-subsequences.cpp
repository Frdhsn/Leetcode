class Solution {
public:
    map<vector<int>,int>  mp;
    void go(vector<vector<int>>&res,int prev,int idx,vector<int>& nums,vector<int> path){
        if(idx == nums.size()){
            if(path.size()>=2 && mp[path]==0){
                mp[path] = 1;
                res.push_back(path);
            }
            return;
        }
        
        go(res,prev,idx+1,nums,path);
        if(prev==-1 or nums[prev]<=nums[idx]){
            path.push_back(nums[idx]);
            go(res,idx,idx+1,nums,path);
            path.push_back(nums[idx]);
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int>path;
        go(res,-1,0,nums,path);
        return res;
    }
};