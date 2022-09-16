// recursive
class Solution {
public:
    using ll = long long int;
    ll dp[1005][1005];
    //ll dp[1005][1005][3];
    ll go(int l,int op,vector<int>&dq,vector<int>& mul){
        if(op==mul.size())return 0;
        int r=dq.size()-1-(op-l);
        if(dp[l][op]!=INT_MIN)
            return dp[l][op];
        
        ll ret=INT_MIN, sc = mul[op]*1ll*dq[l];
        
        ret = max(ret,sc+go(l+1,op+1,dq,mul));
        
        sc = mul[op]* 1ll*dq[r];
        ret = max(ret,sc+go(l,op+1,dq,mul));
        
        return dp[l][op]=ret;
    }
    int maximumScore(vector<int>& nums, vector<int>& mul) {
        //reverse(mul.begin(),mul.end());
        for(int i=0;i<=mul.size();i++)
        {
            for(int j=0;j<=mul.size();j++){
                
                dp[i][i]=INT_MIN;
                dp[i][j]=INT_MIN;
                dp[i][j]=INT_MIN;
            }
        }
        ll res=INT_MIN;
        int n = nums.size();
        res = go(0,0,nums,mul);
        return res;
    }
};