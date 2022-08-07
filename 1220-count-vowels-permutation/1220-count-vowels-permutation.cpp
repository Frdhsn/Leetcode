class Solution {
public:
    static const int MAX=2e4+7,MOD = 1e9+7;
    int dp[MAX][5];
    unordered_map<char,int> mp;
    
    int go(int idx,char prev){
        if(idx == 1){
            
            return 1;
        }
        if(dp[idx][mp[prev]]!=-1)
            return dp[idx][mp[prev]];
        int ret=0;
        if(prev=='a'){
            ret=(ret%MOD + go(idx-1,'e'))%MOD;
        }
        if(prev=='e'){
            ret=(ret%MOD + go(idx-1,'a'))%MOD;
            ret=(ret%MOD + go(idx-1,'i'))%MOD;
        }
        if(prev=='i'){
            ret=(ret%MOD + go(idx-1,'a'))%MOD;
            ret=(ret%MOD + go(idx-1,'e'))%MOD;
            ret=(ret%MOD + go(idx-1,'o'))%MOD;
            ret=(ret%MOD + go(idx-1,'u'))%MOD;
        }
        if(prev=='o'){
            ret=(ret%MOD + go(idx-1,'i'))%MOD;
            ret=(ret%MOD + go(idx-1,'u'))%MOD;
        }
        if(prev=='u'){
            ret=(ret%MOD + go(idx-1,'a'))%MOD;
        }
        return dp[idx][mp[prev]] = ret%MOD;
    }
    int countVowelPermutation(int n) {
        memset(dp,-1,sizeof dp);
        
        int ret=0;
        string vowel="aeiou";
        mp['a']=0;
        mp['e']=1;
        mp['i']=2;
        mp['o']=3;
        mp['u']=4;
        for(auto x:vowel)
        {
            
            ret=(ret%MOD + go(n,x))%MOD;
        }
        return ret;
    }
};