class Solution {
public:
    static const int MAX=2e4+7,MOD = 1e9+7;
    int dp[MAX][26];
    int go(int idx,char prev){
        if(idx == 1){
            
            return 1;
        }
        if(dp[idx][prev-'a']!=-1)
            return dp[idx][prev-'a'];
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
        return dp[idx][prev-'a'] = ret%MOD;
    }
    int countVowelPermutation(int n) {
        memset(dp,-1,sizeof dp);
        
        int ret=0;
        string vowel="aeiou";
        for(auto x:vowel)
        {
            
            ret=(ret%MOD + go(n,x))%MOD;
        }
        return ret;
    }
};