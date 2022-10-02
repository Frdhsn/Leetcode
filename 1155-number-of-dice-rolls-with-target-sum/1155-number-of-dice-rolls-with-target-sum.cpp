class Solution {
public:
    const int mod = 1e9+7;
    using ll = long long int;
    ll dp[31][1001];
    ll go(int i,int k,int target){
        if(target<0)return 0;
        if(i == 0) return target==0;
        if(~dp[i][target])
            return dp[i][target];
        ll ret=0;
        for(int j=1;j<=k;j++){
            ret+=go(i-1,k,target-j)%mod;
            ret%=mod;
        }
        return dp[i][target]=ret;
    }
    int numRollsToTarget(int n, int k, int target) {
        memset(dp,-1,sizeof dp);
        return go(n,k,target);
    }
};