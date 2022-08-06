class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        vector<vector<int>> res;
        
        vector<int> cnt(1005);
        for(auto x:items1)
            cnt[x[0]]+=x[1];
        for(auto x:items2)
            cnt[x[0]]+=x[1];
        for(int i=1;i<=1000;i++){
            if(cnt[i]==0)continue;
            
            vector<int>tmp;
            tmp.push_back(i);
            tmp.push_back(cnt[i]);
            res.push_back(tmp);
        }
        return res;
    }
};