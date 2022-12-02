class Solution {
public:
    bool closeStrings(string word1, string word2) {
        map<char,int> mp,mp2;
        for(auto x:word1)mp[x]++;
        for(auto x:word2)mp2[x]++;
        multiset<int> s1,s2;
        for(auto x:mp){s1.insert(x.second);}
        for(auto x:mp2){s2.insert(x.second);}

        if(s1!=s2) return false;
        // now check if contains same characters
        for(char ch='a';ch<='z';ch++){
            
            if(mp[ch] && mp2[ch])continue;
            if(mp[ch]==0 && mp2[ch]==0)continue;
            return false;
        }
        return true;
    }
};