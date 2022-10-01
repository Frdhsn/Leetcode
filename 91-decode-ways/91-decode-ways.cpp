class Solution {
public:
    int dp[105][3];
    int go(int idx,int pr,string &s){
        if(idx == s.size())return 1;
        if(s[idx]=='0')return 0;
        if(~dp[idx][pr])return dp[idx][pr];
        int ret = go(idx+1,1,s);
        if(idx+1<s.size() && (s[idx]-'0')*10 + (s[idx+1]-'0') <=26)
        ret += go(idx+2,2,s);
        return dp[idx][pr]=ret;
    }
    int numDecodings(string s) {
        memset(dp,-1,sizeof dp);
        return go(0,0,s);
    }
};