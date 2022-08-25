class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res=1;
        vector<int>uni;
        int n = nums.size();
        if(n<=1)return n;
        unordered_map<int,int>cnt;
        for(int i=0;i<n;i++){
            if(cnt[nums[i]]==0){
                uni.push_back(nums[i]);
            }
            cnt[nums[i]]=1;
        }
        sort(uni.begin(),uni.end());
        int curr=1;
        for(int i=1;i<uni.size();i++){
            if(uni[i]==uni[i-1]+1){
                curr++;
            }
            else{
                curr=1;
            }
            res=max(res,curr);
        }
        return res;
    }
};