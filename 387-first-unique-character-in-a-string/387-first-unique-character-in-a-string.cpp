class Solution {
public:
    int firstUniqChar(string s) {
        vector<int>f(26,0);
        for(auto x:s)f[x-'a']++;
        int i=0;
        for(auto x:s){
            if(f[x-'a']==1)return i;
            i++;
        }
        return -1;
        
    }
};