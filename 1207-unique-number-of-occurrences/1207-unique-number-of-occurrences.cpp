class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int> count;
        
        for(auto x:arr)
            count[x]++;
        unordered_map<int,int> flag;
        for(auto x:count){
            if(flag.find(x.second)!=flag.end())return false;
            flag[x.second]=1;
        }
        return true;
    }
};