class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> cnt;
        for(auto x:nums)
            cnt[x]++;
        vector<int> bucket[(int)(nums.size())+1];
        
        int max_cnt=0;
        for(auto x:cnt){
            bucket[x.second].push_back(x.first);
            
            max_cnt = max(max_cnt, x.second);
        }
        vector<int>res;
        for(int i=max_cnt;i>=1&&k;i--){
            while(k&&bucket[i].size()){
                res.push_back(bucket[i].back());
                bucket[i].pop_back();
                k--;
            }
        }
        return res;
    }
};