class Solution {
public:
    static const int mod = 1e9+7;
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n = arr.size();
        
        map<int,int> mp;
        
        for(int i=0;i<arr.size();i++)
            mp[arr[i]] = i;
        
        vector<long long> dp(n,1);
        
        
        for(int i=0;i<n;i++){
            
            for(int j=0;j<i;j++){
                if(arr[i]%arr[j]==0){
                    int right = arr[i]/arr[j];
                    if(mp.find(right)!=mp.end())
                    dp[i]+=(dp[j]*dp[mp[right]])%mod;
                }
            }
        }
        long long ret=0;
        for(auto x:dp)
            ret=(ret%mod + x%mod)%mod;
        return ret;
    }
};