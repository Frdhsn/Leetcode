class Solution {
public:
    using ll = long long int;
    const static int MAX = 1e5+7,MOD=1e9+7;
    ll dp[MAX][10][2];
    ll go(int idx,int previous,int seg, string &s){
        if(idx == s.size())return 1;
        if(s[idx]=='0' && seg==0)return 0;
        if(~dp[idx][previous][seg])
            return dp[idx][previous][seg];
        ll ret=0;
        // not segmented
        if(seg){
            if(s[idx]=='*'){
                for(int i=1;i<=9;i++){
                    if(previous*10 + i <= 26){
                        ret+=go(idx+1,i,0,s)%MOD;
                        ret%=MOD;
                    }
                }
            }
            else{
                
                    if(previous*10 + (s[idx]-'0') <= 26){
                        ret+=go(idx+1,(s[idx]-'0'),0,s)%MOD;
                        ret%=MOD;
                    }
            }
        }
        else{ 
        // new segment
            if(s[idx]=='*'){
                for(int i=1;i<=9;i++){
                    ret+=go(idx+1,i,0,s)%MOD;
                    ret%=MOD;
                    if(idx+1<s.size())
                    ret+=go(idx+1,i,1,s)%MOD;
                    ret%=MOD;
                }
            }
            else{
                    ret+=go(idx+1,s[idx]-'0',0,s)%MOD;
                    ret%MOD;
                    if(idx+1<s.size())
                    ret+=go(idx+1,s[idx]-'0',1,s)%MOD;
                    ret%=MOD;
                
            }
        }
        return dp[idx][previous][seg] = ret%MOD;
        
        
    }
    int numDecodings(string s) {
        memset(dp,-1,sizeof dp);
        return go(0,0,0,s);
    }
};