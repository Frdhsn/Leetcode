class Solution {
public:
    static const int MAX=2e4+7,MOD = 1e9+7;
    int dp[MAX][5];
    
    int go(int idx,char prev){
        if(idx == 1){
            
            return 1;
        }
        int id;
        if(prev=='a')id=0;
        if(prev=='e')id=1;
        if(prev=='i')id=2;
        if(prev=='o')id=3;
        if(prev=='u')id=4;
        if(dp[idx][id])
            return dp[idx][id];
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
        return dp[idx][id] = ret%MOD;
    }
    int countVowelPermutation(int n) {
        //memset(dp,-1,sizeof dp);
        
        int ret=0;
        string vowel="aeiou";
        for(auto &x:vowel)
        {
            
            ret=(ret%MOD + go(n,x))%MOD;
        }
        return ret;
    }
};