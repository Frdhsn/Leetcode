class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int>cnt(26),cnt2(26);
        for(auto x:ransomNote)
            cnt[x-'a']++;
        for(auto x:magazine)
            cnt2[x-'a']++;
        for(int i=0;i<26;i++){
            if(cnt[i]>cnt2[i])
                return false;
        }
        return true;
    }
};