class Solution {
public:
    int dp[505][505];
    int go(int l, int r,string &s){
        if(l >= r)
            return 0;
        if(dp[l][r]!=-1)
            return dp[l][r];
        int ret=1e9;
        if(s[l]==s[r]){
            ret=go(l+1,r-1,s);
        }
        ret=min(ret,1+go(l,r-1,s));
        ret=min(ret,1+go(l+1,r,s));
        return dp[l][r] = ret;
    }
    int minInsertions(string s) {
        memset(dp,-1,sizeof dp);
        
        return go(0,(int)s.size(),s)-1;
    }
};