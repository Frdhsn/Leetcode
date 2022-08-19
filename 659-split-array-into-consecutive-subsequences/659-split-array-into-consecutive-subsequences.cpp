class Solution {
public:
    bool isPossible(vector<int>& nums) {
        if(nums.size()<3)return false;
        map<int,int> cnt, sub;
        
        for(auto x:nums)
            cnt[x]++;
        
        for(auto x:nums){
            
            if(!cnt[x])continue;
            
            cnt[x]--;
            
            if(sub[x-1] > 0){
                sub[x-1]--;
                sub[x]++;
            }
            else if(cnt[x+1]&&cnt[x+2]){
                cnt[x+1]--;
                cnt[x+2]--;
                sub[x+2]++;
            }
            else{
                return false;
            }
        }
        return true;
    }
};