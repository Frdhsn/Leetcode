class Solution {
public:
    int dp[100005][30];
    int go(int idx,string &s,int prev,int k){
        if(idx == s.size())return 0;
        if(dp[idx][prev]!=-1)
            return dp[idx][prev];
        int ret=go(idx+1,s,prev,k);
        int id = s[idx]-'a';
        if( abs(prev-id) <=k)
        ret=max(ret,1 + go(idx+1,s,id,k));
        return dp[idx][prev] = ret;
    }
    int longestIdealString(string s, int k) {
        memset(dp,-1,sizeof dp);
        int ret=0;
        for(int i=0;i<s.size();i++){
            ret = max(ret, 1 + go(i+1,s,s[i]-'a',k));
        }
        return ret;
    }
};